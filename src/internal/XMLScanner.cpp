/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 1999-2000 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache\@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Id$
 */


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <util/Janitor.hpp>
#include <util/Mutexes.hpp>
#include <util/PlatformUtils.hpp>
#include <util/RefVectorOf.hpp>
#include <util/RuntimeException.hpp>
#include <util/UnexpectedEOFException.hpp>
#include <util/XMLDeleterFor.hpp>
#include <util/XMLMsgLoader.hpp>
#include <util/XMLUniDefs.hpp>
#include <util/XMLUni.hpp>
#include <util/XMLURL.hpp>
#include <sax/InputSource.hpp>
#include <sax/SAXException.hpp>
#include <framework/LocalFileInputSource.hpp>
#include <framework/URLInputSource.hpp>
#include <framework/XMLDocumentHandler.hpp>
#include <framework/XMLErrorReporter.hpp>
#include <framework/XMLEntityHandler.hpp>
#include <framework/XMLPScanToken.hpp>
#include <framework/XMLValidator.hpp>
#include <framework/XMLValidityCodes.hpp>
#include <internal/XMLScanner.hpp>
#include <internal/EndOfEntityException.hpp>
#include <validators/DTD/DTDScanner.hpp>



// ---------------------------------------------------------------------------
//  Local static data
// ---------------------------------------------------------------------------
static XMLUInt32       gScannerId;
static XMLMsgLoader*   gMsgLoader;

// ---------------------------------------------------------------------------
//  Local const data
//
//  These are the text for the require char refs that must always be present.
//  We init these into the entity pool upon construction.
// ---------------------------------------------------------------------------
static const XMLCh gAmp[] = { chLatin_a, chLatin_m, chLatin_p, chNull };
static const XMLCh gLT[] = { chLatin_l, chLatin_t, chNull };
static const XMLCh gGT[] = { chLatin_g, chLatin_t, chNull };
static const XMLCh gQuot[] = { chLatin_q, chLatin_u, chLatin_o, chLatin_t, chNull };
static const XMLCh gApos[] = { chLatin_a, chLatin_p, chLatin_o, chLatin_s, chNull };


// ---------------------------------------------------------------------------
//  Local, static functions
// ---------------------------------------------------------------------------

//
//  We need to fault in this mutex. But, since its used for synchronization
//  itself, we have to do this the low level way using a compare and swap.
//
static XMLMutex& gScannerMutex()
{
    static bool      registered = false;
    static XMLMutex* scannerMutex = 0;
    if (!scannerMutex)
    {
        XMLMutex* tmpMutex = new XMLMutex;
        if (XMLPlatformUtils::compareAndSwap((void**)&scannerMutex, tmpMutex, 0))
        {
            // Someone beat us to it, so let's clean up ours
            delete tmpMutex;
        }

        // Now lock it and try to register it
        XMLMutexLock lock(scannerMutex);

        // If we got here first, then register it and set the registered flag
        if (!registered)
        {
            XMLPlatformUtils::registerLazyData
            (
                new XMLDeleterFor<XMLMutex>(scannerMutex)
            );
            registered = true;
        }
    }
    return *scannerMutex;
}


// ---------------------------------------------------------------------------
//  XMLScanner: Constructors and Destructor
// ---------------------------------------------------------------------------
XMLScanner::XMLScanner(XMLValidator* const valToAdopt) :

    fAttrList(0)
    , fDocHandler(0)
    , fDocTypeHandler(0)
    , fDoNamespaces(false)
    , fEntityHandler(0)
    , fErrorReporter(0)
    , fExitOnFirstFatal(true)
    , fIDRefList(0)
    , fInException(false)
    , fRawAttrList(0)
    , fReuseGrammar(false)
    , fScannerId(0)
    , fSequenceId(0)
    , fStandalone(false)
    , fValidate(false)
    , fValidator(valToAdopt)
    , fValidatorFromUser(false)
    , fValScheme(Val_Never)
    , fSchemaValidation(false)
    , fEmptyNamespaceId(0)
    , fGlobalNamespaceId(0)
    , fUnknownNamespaceId(0)
    , fXMLNamespaceId(0)
    , fXMLNSNamespaceId(0)
    , fGrammarResolver(0)
    , fGrammar(0)
    , fEntityDeclPool(0)
    , fURIStringPool(0)
{
   commonInit();

   if (fValidator) {
       fValidatorFromUser = true;
       initValidator();
   }
}

XMLScanner::XMLScanner( XMLDocumentHandler* const  docHandler
                        , DocTypeHandler* const    docTypeHandler
                        , XMLEntityHandler* const  entityHandler
                        , XMLErrorReporter* const  errHandler
                        , XMLValidator* const      valToAdopt) :

    fAttrList(0)
    , fDocHandler(docHandler)
    , fDocTypeHandler(docTypeHandler)
    , fDoNamespaces(false)
    , fEntityHandler(entityHandler)
    , fErrorReporter(errHandler)
    , fExitOnFirstFatal(true)
    , fIDRefList(0)
    , fInException(false)
    , fRawAttrList(0)
    , fReuseGrammar(false)
    , fScannerId(0)
    , fSequenceId(0)
    , fStandalone(false)
    , fValidate(false)
    , fValidator(valToAdopt)
    , fValidatorFromUser(false)
    , fValScheme(Val_Never)
    , fSchemaValidation(false)
    , fEmptyNamespaceId(0)
    , fGlobalNamespaceId(0)
    , fUnknownNamespaceId(0)
    , fXMLNamespaceId(0)
    , fXMLNSNamespaceId(0)
    , fGrammarResolver(0)
    , fGrammar(0)
    , fEntityDeclPool(0)
    , fURIStringPool(0)
{
   commonInit();

   if (fValidator){
      fValidatorFromUser = true;
       initValidator();
   }
}

XMLScanner::~XMLScanner()
{
    delete fAttrList;
    delete fIDRefList;
    delete fRawAttrList;
    delete fValidator;
    delete fEntityDeclPool;

    //fGrammarResolver will delete the fGrammar as well
    delete fGrammarResolver;

    delete fURIStringPool;
}


// ---------------------------------------------------------------------------
//  XMLScanner: Main entry point to scan a document
// ---------------------------------------------------------------------------
void XMLScanner::scanDocument(  const   XMLCh* const    systemId
                                , const bool            reuseGrammar)
{
    //
    //  First we try to parse it as a URL. If that fails, we assume its
    //  a file and try it that way.
    //
    InputSource* srcToUse = 0;
    try
    {
        //
        //  Create a temporary URL. Since this is the primary document,
        //  it has to be fully qualified. If not, then assume we are just
        //  mistaking a file for a URL.
        //

        XMLURL tmpURL(systemId);
        if (tmpURL.isRelative()) {
            srcToUse = new LocalFileInputSource(systemId);
        }
        else
        {
            srcToUse = new URLInputSource(tmpURL);
        }

    }

    catch(const MalformedURLException&)
    {
        srcToUse = new LocalFileInputSource(systemId);
    }

    catch(...)
    {
        // Just rethrow this, since its not our problem
        throw;
    }

    Janitor<InputSource> janSrc(srcToUse);
    scanDocument(*srcToUse, reuseGrammar);
}

void XMLScanner::scanDocument(  const   char* const systemId
                                , const bool        reuseGrammar)
{
    // We just delegate this to the XMLCh version after transcoding
    XMLCh* tmpBuf = XMLString::transcode(systemId);
    ArrayJanitor<XMLCh> janBuf(tmpBuf);
    scanDocument(tmpBuf, reuseGrammar);
}


void XMLScanner::scanDocument(const InputSource& src, const bool reuseGrammar)
{
    //
    //  Bump up the sequence id for this parser instance. This will invalidate
    //  any previous progressive scan tokens.
    //
    fSequenceId++;

    // Store the reuse validator flag
    fReuseGrammar = reuseGrammar;

    try
    {
        //
        //  Reset the scanner and its plugged in stuff for a new run. This
        //  resets all the data structures, creates the initial reader and
        //  pushes it on the stack, and sets up the base document path.
        //
        scanReset(src);

        // If we have a document handler, then call the start document
        if (fDocHandler)
            fDocHandler->startDocument();

        //
        //  Scan the prolog part, which is everything before the root element
        //  including the DTD subsets.
        //
        scanProlog();

        //
        //  If we got to the end of input, then its not a valid XML file.
        //  Else, go on to scan the content.
        //
        if (fReaderMgr.atEOF())
        {
            emitError(XMLErrs::EmptyMainEntity);
        }
         else
        {
            // Scan content, and tell it its not an external entity
            if (scanContent(false))
            {
                // Do post-parse validation if required
                if (fValidate)
                {
                    //
                    //  We handle ID reference semantics at this level since
                    //  its required by XML 1.0.
                    //
                    checkIDRefs();

                    // Then allow the validator to do any extra stuff it wants
                    fValidator->postParseValidation();
                }

                // That went ok, so scan for any miscellaneous stuff
                if (!fReaderMgr.atEOF())
                    scanMiscellaneous();
            }
        }

        // If we have a document handler, then call the end document
        if (fDocHandler)
            fDocHandler->endDocument();

        // Reset the reader manager to close all files, sockets, etc...
        fReaderMgr.reset();
    }

    //
    //  NOTE:
    //
    //  In all of the error processing below, the emitError() call MUST come
    //  before the flush of the reader mgr, or it will fail because it tries
    //  to find out the position in the XML source of the error.
    //
    catch(const XMLErrs::Codes)
    {
        // This is a 'first fatal error' type exit, so reset and fall through
        fReaderMgr.reset();
    }

    catch(const XMLValid::Codes)
    {
        // This is a 'first fatal error' type exit, so reset and fall through
        fReaderMgr.reset();
    }

    catch(const SAXException&)
    {
        //
        //  We have to propogate SAX exceptions.
        //
        //  Make sure that the reader manager gets reset, then rethrow this
        //  exception since it means nothing much to us.
        //
        fReaderMgr.reset();
        throw;
    }

    catch(const XMLException& excToCatch)
    {
        //
        //  Emit the error and catch any user exception thrown from here. Make
        //  sure in all cases we flush the reader manager.
        //
        fInException = true;
        try
        {
            emitError
            (
                XMLErrs::XMLException
                , excToCatch.getType()
                , excToCatch.getMessage()
            );
        }

        catch(...)
        {
            // Flush the reader manager and rethrow user's error
            fReaderMgr.reset();
            throw;
        }

        // If it returned, then reset the reader manager and fall through
        fReaderMgr.reset();
    }

    catch(...)
    {
        // Reset and rethrow
        fReaderMgr.reset();
        throw;
    }
}


//
//  This method begins a progressive parse. It scans through the prolog and
//  returns a token to be used on subsequent scanNext() calls. If the return
//  value is true, then the token is legal and ready for further use. If it
//  returns false, then the scan of the prolog failed and the token is not
//  going to work on subsequent scanNext() calls.
//
bool XMLScanner::scanFirst( const   XMLCh* const    systemId
                            ,       XMLPScanToken&  toFill
                            , const bool            reuseGrammar)
{
    //
    //  First we try to parse it as a URL. If that fails, we assume its
    //  a file and try it that way.
    //
    InputSource* srcToUse = 0;
    try
    {
        //
        //  Create a temporary URL. Since this is the primary document,
        //  it has to be fully qualified. If not, then assume we are just
        //  mistaking a file for a URL.
        //
        XMLURL tmpURL(systemId);
        if (tmpURL.isRelative())
            ThrowXML(MalformedURLException, XMLExcepts::URL_NoProtocolPresent);
        srcToUse = new URLInputSource(tmpURL);
    }

    catch(const MalformedURLException&)
    {
        srcToUse = new LocalFileInputSource(systemId);
    }

    catch(...)
    {
        // Just rethrow this, since its not our problem
        throw;
    }

    Janitor<InputSource> janSrc(srcToUse);
    return scanFirst(*srcToUse, toFill, reuseGrammar);
}

bool XMLScanner::scanFirst( const   char* const     systemId
                            ,       XMLPScanToken&  toFill
                            , const bool            reuseGrammar)
{
    // We just delegate this to the XMLCh version after transcoding
    XMLCh* tmpBuf = XMLString::transcode(systemId);
    ArrayJanitor<XMLCh> janBuf(tmpBuf);
    return scanFirst(tmpBuf, toFill, reuseGrammar);
}

bool XMLScanner::scanFirst( const   InputSource&    src
                            ,       XMLPScanToken&  toFill
                            , const bool            reuseGrammar)
{
    // Store the reuse validator flag
    fReuseGrammar = reuseGrammar;

    //
    //  Bump up the sequence id for this new scan cycle. This will invalidate
    //  any previous tokens we've returned.
    //
    fSequenceId++;

	//
    // Reset the scanner and its plugged in stuff for a new run.  This
	// resets all the data structures, creates the initial reader and
	// pushes it on the stack, and sets up the base document path
	//
    scanReset(src);

	// If we have a document handler, then call the start document
	if (fDocHandler)
		fDocHandler->startDocument();

    try
    {
        //
        //  Scan the prolog part, which is everything before the root element
        //  including the DTD subsets. This is all that is done on the scan
        //  first.
        //
        scanProlog();
    }

    //
    //  NOTE:
    //
    //  In all of the error processing below, the emitError() call MUST come
    //  before the flush of the reader mgr, or it will fail because it tries
    //  to find out the position in the XML source of the error.
    //
    catch(const XMLErrs::Codes)
    {
        // This is a 'first failure' exception so reset and return a failure
        fReaderMgr.reset();
        return false;
    }

    catch(const XMLValid::Codes)
    {
        // This is a 'first fatal error' type exit, so reset and reuturn failure
        fReaderMgr.reset();
        return false;
    }

    // We have to propogate SAX exceptions
    catch(const SAXException&)
    {
        fReaderMgr.reset();
        throw;
    }

    catch(const XMLException& excToCatch)
    {
        //
        //  Emit the error and catch any user exception thrown from here. Make
        //  sure in all cases we flush the reader manager.
        //
        fInException = true;
        try
        {
            emitError
            (
                XMLErrs::XMLException
                , excToCatch.getType()
                , excToCatch.getMessage()
            );
        }

        catch(...)
        {
            // Reset and rethrow the user error
            fReaderMgr.reset();
            throw;
        }

        // Reset and return a failure
        fReaderMgr.reset();
        return false;
    }

    catch(...)
    {
        // Reset and rethrow original error
        fReaderMgr.reset();
        throw;
    }

    // Fill in the caller's token to make it legal and return success
    toFill.set(fScannerId, fSequenceId);
    return true;
}


bool XMLScanner::scanNext(XMLPScanToken& token)
{
    // Make sure this token is still legal
    if (!isLegalToken(token))
        ThrowXML(RuntimeException, XMLExcepts::Scan_BadPScanToken);

    // Find the next token and remember the reader id
    unsigned int orgReader;
    XMLTokens curToken;

    //
    //  We have to handle any end of entity exceptions that happen here.
    //  We could be at the end of X nested entities, each of which will
    //  generate an end of entity exception as we try to move forward.
    //

    while (true)
    {
        try
        {
            curToken = senseNextToken(orgReader);
            break;
        }

        catch(const EndOfEntityException& toCatch)
        {
            // Send an end of entity reference event
            if (fDocHandler)
                fDocHandler->endEntityReference(toCatch.getEntity());
        }
    }

    bool retVal = true;
    try
    {
        if (curToken == Token_CharData)
        {
            scanCharData(fCDataBuf);
        }
         else if (curToken == Token_EOF)
        {
            if (!fElemStack.isEmpty())
            {
                const ElemStack::StackElem* topElem = fElemStack.popTop();
                emitError
                (
                    XMLErrs::EndedWithTagsOnStack
                    , topElem->fThisElement->getFullName()
                );
            }

            retVal = false;
        }
         else
        {
            // Its some sort of markup
            bool gotData = true;
            switch(curToken)
            {
                case Token_CData :
                    // Make sure we are within content
                    if (fElemStack.isEmpty())
                        emitError(XMLErrs::CDATAOutsideOfContent);
                    scanCDSection();
                    break;

                case Token_Comment :
                    scanComment();
                    break;

                case Token_EndTag :
                    scanEndTag(gotData);
                    break;

                case Token_PI :
                    scanPI();
                    break;

                case Token_StartTag :
                    if (fDoNamespaces)
                        scanStartTagNS(gotData);
                    else
                        scanStartTag(gotData);
                    break;

                default :
                    fReaderMgr.skipToChar(chOpenAngle);
                    break;
            }

            if (orgReader != fReaderMgr.getCurrentReaderNum())
                emitError(XMLErrs::PartialMarkupInEntity);

            // If we hit the end, then do the miscellaneous part
            if (!gotData)
			{
                scanMiscellaneous();
				if (fDocHandler)
					fDocHandler->endDocument();
			}
        }
    }

    //
    //  NOTE:
    //
    //  In all of the error processing below, the emitError() call MUST come
    //  before the flush of the reader mgr, or it will fail because it tries
    //  to find out the position in the XML source of the error.
    //
    catch(const XMLErrs::Codes)
    {
        // This is a 'first failure' exception, so reset and return failure
        fReaderMgr.reset();
        return false;
    }

    catch(const XMLValid::Codes)
    {
        // This is a 'first fatal error' type exit, so reset and reuturn failure
        fReaderMgr.reset();
        return false;
    }

    // We have to propogate SAX exceptions
    catch(const SAXException&)
    {
        // Just reset our reader manager and rethrow SAX exception
        fReaderMgr.reset();
        throw;
    }

    catch(const XMLException& excToCatch)
    {
        //
        //  Emit the error and catch any user exception thrown from here. Make
        //  sure in all cases we flush the reader manager.
        //
        fInException = true;
        try
        {
            emitError
            (
                XMLErrs::XMLException
                , excToCatch.getType()
                , excToCatch.getMessage()
            );
        }

        catch(...)
        {
            // Reset and rethrow user error
            fReaderMgr.reset();
            throw;
        }

        // Reset and return failure
        fReaderMgr.reset();
        return false;
    }

    catch(...)
    {
        // Reset and rethrow original error
        fReaderMgr.reset();
        throw;
    }

    // If we hit the end, then flush the reader manager
    if (!retVal)
        fReaderMgr.reset();

    return retVal;
}


void XMLScanner::scanReset(XMLPScanToken& token)
{
    // Make sure this token is still legal
    if (!isLegalToken(token))
        ThrowXML(RuntimeException, XMLExcepts::Scan_BadPScanToken);

    // Reset the reader manager
    fReaderMgr.reset();

    // And invalidate any tokens by bumping our sequence number
    fSequenceId++;
}



// ---------------------------------------------------------------------------
//  XMLScanner: Private helper methods. Most of these are implemented in
//  XMLScanner2.Cpp.
// ---------------------------------------------------------------------------

//
//  This method handles the common initialization, to avoid having to do
//  it redundantly in multiple constructors.
//
void XMLScanner::commonInit()
{
    //
    //  We have to do a little init that involves statics, so we have to
    //  use the mutex to protect it.
    //
    {
        XMLMutexLock lockInit(&gScannerMutex());

        // If we haven't loaded our message yet, then do that
        if (!gMsgLoader)
        {
            gMsgLoader = XMLPlatformUtils::loadMsgSet(XMLUni::fgXMLErrDomain);
            if (!gMsgLoader)
                XMLPlatformUtils::panic(XMLPlatformUtils::Panic_CantLoadMsgDomain);

            // Register this object to be cleaned up at termination
            XMLPlatformUtils::registerLazyData
            (
                new XMLDeleterFor<XMLMsgLoader>(gMsgLoader)
            );
        }

        // And assign ourselves the next available scanner id
        fScannerId = ++gScannerId;
    }

    //
    //  Create the attribute list, which is used to store attribute values
    //  during start tag processing. Give it a reasonable initial size that
    //  will serve for most folks, though it will grow as required.
    //
    fAttrList = new RefVectorOf<XMLAttr>(32);

    //
    //  And we need one for the raw attribute scan. This just stores key/
    //  value string pairs (prior to any processing.)
    //
    fRawAttrList = new RefVectorOf<KVStringPair>(32);

    //
    //  Create the id ref list. This is used to enforce XML 1.0 ID ref
    //  semantics, i.e. all id refs must refer to elements that exist
    //
    fIDRefList = new RefHashTableOf<XMLRefInfo>(109);

    //  Create the EntityDeclPool
    fEntityDeclPool = new NameIdPool<DTDEntityDecl>(109);

    //  Create the GrammarResolver
    fGrammarResolver = new GrammarResolver();

    resetEntityDeclPool();
}



void XMLScanner::initValidator() {
    //
    //  Tell the validator about the stuff it needs to know in order to
    //  do its work.
    //
    fValidator->setScannerInfo(this, &fReaderMgr, &fBufMgr);
    fValidator->setErrorReporter(fErrorReporter);

    //  So lets ask the validator whether it requires namespaces or not. If it
    //  does, we have to override the namespace enablement flag.
    if (fValidator->requiresNamespaces() && !fDoNamespaces)
        setDoNamespaces(true);

    if (fValidator->handlesSchema())
        ((SchemaValidator*) fValidator)->setGrammarResolver(fGrammarResolver);
}

void XMLScanner::resetEntityDeclPool() {

    fEntityDeclPool->removeAll();
    //
    //  Add the default entity entries for the character refs that must always
    //  be present. We indicate that they are from the internal subset. They
    //  aren't really, but they have to look that way so that they are still
    //  valid for use within a standalone document.
    //
    //  We also mark them as special char entities, which allows them to be
    //  used in places whether other non-numeric general entities cannot.
    //
    fEntityDeclPool->put(new DTDEntityDecl(gAmp, chAmpersand, true, true));
    fEntityDeclPool->put(new DTDEntityDecl(gLT, chOpenAngle, true, true));
    fEntityDeclPool->put(new DTDEntityDecl(gGT, chCloseAngle, true, true));
    fEntityDeclPool->put(new DTDEntityDecl(gQuot, chDoubleQuote, true, true));
    fEntityDeclPool->put(new DTDEntityDecl(gApos, chSingleQuote, true, true));
}

void XMLScanner::resetURIPool() {
    fURIStringPool->flushAll();

    fEmptyNamespaceId   = fURIStringPool->addOrFind(XMLUni::fgZeroLenString);
    fGlobalNamespaceId  = fURIStringPool->addOrFind(XMLUni::fgGlobalNSURIName);
    fUnknownNamespaceId = fURIStringPool->addOrFind(XMLUni::fgUnknownURIName);
    fXMLNamespaceId     = fURIStringPool->addOrFind(XMLUni::fgXMLURIName);
    fXMLNSNamespaceId   = fURIStringPool->addOrFind(XMLUni::fgXMLNSURIName);
}

// ---------------------------------------------------------------------------
//  XMLScanner: Error emitting methods
// ---------------------------------------------------------------------------

//
//  These methods are called whenever the scanner wants to emit an error.
//  It handles getting the message loaded, doing token replacement, etc...
//  and then calling the error handler, if its installed.
//
void XMLScanner::emitError(const XMLErrs::Codes toEmit)
{
    if (fErrorReporter)
    {
        // Load the message into a local for display
        const unsigned int msgSize = 1023;
        XMLCh errText[msgSize + 1];

        // Lock the mutex and load the text
        {
            XMLMutexLock lockInit(&gScannerMutex());
            if (!gMsgLoader->loadMsg(toEmit, errText, msgSize))
            {
                // <TBD> Probably should load a default msg here
            }
        }

        //
        //  Create a LastExtEntityInfo structure and get the reader manager
        //  to fill it in for us. This will give us the information about
        //  the last reader on the stack that was an external entity of some
        //  sort (i.e. it will ignore internal entities.
        //
        ReaderMgr::LastExtEntityInfo lastInfo;
        fReaderMgr.getLastExtEntityInfo(lastInfo);

        fErrorReporter->error
        (
            toEmit
            , XMLUni::fgXMLErrDomain
            , XMLErrs::errorType(toEmit)
            , errText
            , lastInfo.systemId
            , lastInfo.publicId
            , lastInfo.lineNumber
            , lastInfo.colNumber
        );
    }

    // Bail out if its fatal an we are to give up on the first fatal error
    if (XMLErrs::isFatal(toEmit) && fExitOnFirstFatal && !fInException)
        throw toEmit;
}

void XMLScanner::emitError( const   XMLErrs::Codes    toEmit
                            , const XMLCh* const        text1
                            , const XMLCh* const        text2
                            , const XMLCh* const        text3
                            , const XMLCh* const        text4)
{
    if (fErrorReporter)
    {
        //
        //  Load the message into alocal and replace any tokens found in
        //  the text.
        //
        const unsigned int maxChars = 2047;
        XMLCh errText[maxChars + 1];

        // Lock the mutex and load the text
        {
            XMLMutexLock lockInit(&gScannerMutex());
            if (!gMsgLoader->loadMsg(toEmit, errText, maxChars, text1, text2, text3, text4))
            {
                // <TBD> Should probably load a default message here
            }
        }

        //
        //  Create a LastExtEntityInfo structure and get the reader manager
        //  to fill it in for us. This will give us the information about
        //  the last reader on the stack that was an external entity of some
        //  sort (i.e. it will ignore internal entities.
        //
        ReaderMgr::LastExtEntityInfo lastInfo;
        fReaderMgr.getLastExtEntityInfo(lastInfo);

        fErrorReporter->error
        (
            toEmit
            , XMLUni::fgXMLErrDomain
            , XMLErrs::errorType(toEmit)
            , errText
            , lastInfo.systemId
            , lastInfo.publicId
            , lastInfo.lineNumber
            , lastInfo.colNumber
        );
    }

    // Bail out if its fatal an we are to give up on the first fatal error
    if (XMLErrs::isFatal(toEmit) && fExitOnFirstFatal && !fInException)
        throw toEmit;
}

void XMLScanner::emitError( const   XMLErrs::Codes    toEmit
                            , const char* const         text1
                            , const char* const         text2
                            , const char* const         text3
                            , const char* const         text4)
{
    if (fErrorReporter)
    {
        //
        //  Load the message into alocal and replace any tokens found in
        //  the text.
        //
        const unsigned int maxChars = 2047;
        XMLCh errText[maxChars + 1];

        // Lock the mutex and load the text
        {
            XMLMutexLock lockInit(&gScannerMutex());
            if (!gMsgLoader->loadMsg(toEmit, errText, maxChars, text1, text2, text3, text4))
            {
                // <TBD> Should probably load a default message here
            }
        }

        //
        //  Create a LastExtEntityInfo structure and get the reader manager
        //  to fill it in for us. This will give us the information about
        //  the last reader on the stack that was an external entity of some
        //  sort (i.e. it will ignore internal entities.
        //
        ReaderMgr::LastExtEntityInfo lastInfo;
        fReaderMgr.getLastExtEntityInfo(lastInfo);

        fErrorReporter->error
        (
            toEmit
            , XMLUni::fgXMLErrDomain
            , XMLErrs::errorType(toEmit)
            , errText
            , lastInfo.systemId
            , lastInfo.publicId
            , lastInfo.lineNumber
            , lastInfo.colNumber
        );
    }

    // Bail out if its fatal an we are to give up on the first fatal error
    if (XMLErrs::isFatal(toEmit) && fExitOnFirstFatal && !fInException)
        throw toEmit;
}


// ---------------------------------------------------------------------------
//  XMLScanner: Getter methods
// ---------------------------------------------------------------------------

//
//  This method allows the caller to query the current location of the scanner.
//  It will return the sys/public ids of the current entity, and the line/col
//  position within it.
//
//  NOTE: This API returns the location with the last external file. So if its
//  currently scanning an entity, the position returned will be the end of
//  the entity reference in the file that had the reference.
//
bool
XMLScanner::getLastExtLocation(         XMLCh* const    sysIdToFill
                                , const unsigned int    maxSysIdChars
                                ,       XMLCh* const    pubIdToFill
                                , const unsigned int    maxPubIdChars
                                ,       unsigned int&   lineToFill
                                ,       unsigned int&   colToFill)
{
    // Create a local info object and get it filled in by the reader manager
    ReaderMgr::LastExtEntityInfo lastInfo;
    fReaderMgr.getLastExtEntityInfo(lastInfo);

    // Fill in the line and column number
    lineToFill = lastInfo.lineNumber;
    colToFill = lastInfo.colNumber;

    // And copy over as much of the ids as will fit
    sysIdToFill[0] = 0;
    if (lastInfo.systemId)
    {
        if (XMLString::stringLen(lastInfo.systemId) > maxSysIdChars)
            return false;
        XMLString::copyString(sysIdToFill, lastInfo.systemId);
    }

    pubIdToFill[0] = 0;
    if (lastInfo.publicId)
    {
        if (XMLString::stringLen(lastInfo.publicId) > maxPubIdChars)
            return false;
        XMLString::copyString(pubIdToFill, lastInfo.publicId);
    }
    return true;
}


// ---------------------------------------------------------------------------
//  XMLScanner: Private scanning methods
// ---------------------------------------------------------------------------

//
//  This method is called from scanStartTag() to handle the very raw initial
//  scan of the attributes. It just fills in the passed collection with
//  key/value pairs for each attribute. No processing is done on them at all.
//
unsigned int
XMLScanner::rawAttrScan(const   XMLCh* const                elemName
                        ,       RefVectorOf<KVStringPair>&  toFill
                        ,       bool&                       isEmpty)
{
    //
    //  Keep up with how many attributes we've seen so far, and how many
    //  elements are available in the vector. This way we can reuse old
    //  elements until we run out and then expand it.
    //
    unsigned int attCount = 0;
    unsigned int curVecSize = toFill.size();

    // Assume it is not empty
    isEmpty = false;

    //
    //  We loop until we either see a /> or >, handling key/value pairs util
    //  we get there. We place them in the passed vector, which we will expand
    //  as required to hold them.
    //
    while (true)
    {
        // Get the next character, which should be non-space
        XMLCh nextCh = fReaderMgr.peekNextChar();

        //
        //  If the next character is not a slash or closed angle bracket,
        //  then it must be whitespace, since whitespace is required
        //  between the end of the last attribute and the name of the next
        //  one.
        //
        if (attCount)
        {
            if ((nextCh != chForwardSlash) && (nextCh != chCloseAngle))
            {
                if (XMLReader::isWhitespace(nextCh))
                {
                    // Ok, skip by them and get another char
                    fReaderMgr.getNextChar();
                    fReaderMgr.skipPastSpaces();
                    nextCh = fReaderMgr.peekNextChar();
                }
                 else
                {
                    // Emit the error but keep on going
                    emitError(XMLErrs::ExpectedWhitespace);
                }
            }
        }

        //
        //  Ok, here we first check for any of the special case characters.
        //  If its not one, then we do the normal case processing, which
        //  assumes that we've hit an attribute value, Otherwise, we do all
        //  the special case checks.
        //
        if (!XMLReader::isSpecialStartTagChar(nextCh))
        {
            //
            //  Assume its going to be an attribute, so get a name from
            //  the input.
            //
            if (!fReaderMgr.getName(fAttNameBuf))
            {
                emitError(XMLErrs::ExpectedAttrName);
                fReaderMgr.skipPastChar(chCloseAngle);
                return attCount;
            }

            // And next must be an equal sign
            if (!scanEq())
            {
                static const XMLCh tmpList[] =
                {
                    chSingleQuote, chDoubleQuote, chCloseAngle
                    , chOpenAngle, chForwardSlash, chNull
                };

                emitError(XMLErrs::ExpectedEqSign);

                //
                //  Try to sync back up by skipping forward until we either
                //  hit something meaningful.
                //
                const XMLCh chFound = fReaderMgr.skipUntilInOrWS(tmpList);

                if ((chFound == chCloseAngle) || (chFound == chForwardSlash))
                {
                    // Jump back to top for normal processing of these
                    continue;
                }
                 else if ((chFound == chSingleQuote)
                      ||  (chFound == chDoubleQuote)
                      ||  XMLReader::isWhitespace(chFound))
                {
                    // Just fall through assuming that the value is to follow
                }
                 else if (chFound == chOpenAngle)
                {
                    // Assume a malformed tag and that new one is starting
                    emitError(XMLErrs::UnterminatedStartTag, elemName);
                    return attCount;
                }
                 else
                {
                    // Something went really wrong
                    return attCount;
                }
            }

            //
            //  Next should be the quoted attribute value. We just do a simple
            //  and stupid scan of this value. The only thing we do here
            //  is to expand entity references.
            //
            if (!basicAttrValueScan(fAttNameBuf.getRawBuffer(), fAttValueBuf))
            {
                static const XMLCh tmpList[] =
                {
                    chCloseAngle, chOpenAngle, chForwardSlash, chNull
                };

                emitError(XMLErrs::ExpectedAttrValue);

                //
                //  It failed, so lets try to get synced back up. We skip
                //  forward until we find some whitespace or one of the
                //  chars in our list.
                //
                const XMLCh chFound = fReaderMgr.skipUntilInOrWS(tmpList);

                if ((chFound == chCloseAngle)
                ||  (chFound == chForwardSlash)
                ||  XMLReader::isWhitespace(chFound))
                {
                    //
                    //  Just fall through and process this attribute, though
                    //  the value will be "".
                    //
                }
                 else if (chFound == chOpenAngle)
                {
                    // Assume a malformed tag and that new one is starting
                    emitError(XMLErrs::UnterminatedStartTag, elemName);
                    return attCount;
                }
                 else
                {
                    // Something went really wrong
                    return attCount;
                }
            }

            //
            //  Make sure that the name is basically well formed for namespace
            //  enabled rules. It either has no colons, or it has one which
            //  is neither the first or last char.
            //
            const int colonFirst = XMLString::indexOf(fAttNameBuf.getRawBuffer(), chColon);
            if (colonFirst != -1)
            {
                const int colonLast = XMLString::lastIndexOf(fAttNameBuf.getRawBuffer(), chColon);

                if (colonFirst != colonLast)
                {
                    emitError(XMLErrs::TooManyColonsInName);
                    continue;
                }
                 else if ((colonFirst == 0)
                      ||  (colonLast == (int)fAttNameBuf.getLen() - 1))
                {
                    emitError(XMLErrs::InvalidColonPos);
                    continue;
                }
            }


            //
            //  And now lets add it to the passed collection. If we have not
            //  filled it up yet, then we use the next element. Else we add
            //  a new one.
            //
            KVStringPair* curPair = 0;
            if (attCount >= curVecSize)
            {
                curPair = new KVStringPair
                (
                    fAttNameBuf.getRawBuffer()
                    , fAttValueBuf.getRawBuffer()
                );
                toFill.addElement(curPair);
            }
             else
            {
                curPair = toFill.elementAt(attCount);
                curPair->set(fAttNameBuf.getRawBuffer(), fAttValueBuf.getRawBuffer());
            }

            // And bump the count of attributes we've gotten
            attCount++;

            // And go to the top again for another attribute
            continue;
        }

        //
        //  It was some special case character so do all of the checks and
        //  deal with it.
        //
        if (!nextCh)
            ThrowXML(UnexpectedEOFException, XMLExcepts::Gen_UnexpectedEOF);

        if (nextCh == chForwardSlash)
        {
            fReaderMgr.getNextChar();
            isEmpty = true;
            if (!fReaderMgr.skippedChar(chCloseAngle))
                emitError(XMLErrs::UnterminatedStartTag, elemName);
            break;
        }
         else if (nextCh == chCloseAngle)
        {
            fReaderMgr.getNextChar();
            break;
        }
         else if (nextCh == chOpenAngle)
        {
            //
            //  Check for this one specially, since its going to be common
            //  and it is kind of auto-recovering since we've already hit the
            //  next open bracket, which is what we would have seeked to (and
            //  skipped this whole tag.)
            //
            emitError(XMLErrs::UnterminatedStartTag, elemName);
            break;
        }
         else if ((nextCh == chSingleQuote) || (nextCh == chDoubleQuote))
        {
            //
            //  Check for this one specially, which is probably a missing
            //  attribute name, e.g. ="value". Just issue expected name
            //  error and eat the quoted string, then jump back to the
            //  top again.
            //
            emitError(XMLErrs::ExpectedAttrName);
            fReaderMgr.getNextChar();
            fReaderMgr.skipQuotedString(nextCh);
            fReaderMgr.skipPastSpaces();
            continue;
        }
    }

    return attCount;
}


//
//  This method will kick off the scanning of the primary content of the
//  document, i.e. the elements.
//
bool XMLScanner::scanContent(const bool extEntity)
{
    //
    //  Go into a loop until we hit the end of the root element, or we fall
    //  out because there is no root element.
    //
    //  We have to do kind of a deeply nested double loop here in order to
    //  avoid doing the setup/teardown of the exception handler on each
    //  round. Doing it this way we only do it when an exception actually
    //  occurs.
    //
    bool gotData = true;
    bool inMarkup = false;
    while (gotData)
    {
        try
        {
            while (gotData)
            {
                //  Sense what the next top level token is. According to what
                //  this tells us, we will call something to handle that kind
                //  of thing.
                //
                unsigned int orgReader;
                const XMLTokens curToken = senseNextToken(orgReader);

                //
                //  Handle character data and end of file specially. Char data
                //  is not markup so we don't want to handle it in the loop
                //  below.
                //
                if (curToken == Token_CharData)
                {
                    //
                    //  Scan the character data and call appropriate events. Let
                    //  him use our local character data buffer for efficiency.
                    //
                    scanCharData(fCDataBuf);
                    continue;
                }
                 else if (curToken == Token_EOF)
                {
                    //
                    //  The element stack better be empty at this point or we
                    //  ended prematurely before all elements were closed.
                    //
                    if (!fElemStack.isEmpty())
                    {
                        const ElemStack::StackElem* topElem = fElemStack.popTop();
                        emitError
                        (
                            XMLErrs::EndedWithTagsOnStack
                            , topElem->fThisElement->getFullName()
                        );
                    }

                    // Its the end of file, so clear the got data flag
                    gotData = false;
                    continue;
                }

                // We are in some sort of markup now
                inMarkup = true;

                //
                //  According to the token we got, call the appropriate
                //  scanning method.
                //
                switch(curToken)
                {
                    case Token_CData :
                        // Make sure we are within content
                        if (fElemStack.isEmpty())
                            emitError(XMLErrs::CDATAOutsideOfContent);
                        scanCDSection();
                        break;

                    case Token_Comment :
                        scanComment();
                        break;

                    case Token_EndTag :
                        scanEndTag(gotData);
                        break;

                    case Token_PI :
                        scanPI();
                        break;

                    case Token_StartTag :
                        if (fDoNamespaces)
                            scanStartTagNS(gotData);
                        else
                            scanStartTag(gotData);
                        break;

                    default :
                        fReaderMgr.skipToChar(chOpenAngle);
                        break;
                }

                if (orgReader != fReaderMgr.getCurrentReaderNum())
                    emitError(XMLErrs::PartialMarkupInEntity);

                // And we are back out of markup again
                inMarkup = false;
            }
        }

        catch(const EndOfEntityException& toCatch)
        {
            //
            //  If we were in some markup when this happened, then its a
            //  partial markup error.
            //
            if (inMarkup)
                emitError(XMLErrs::PartialMarkupInEntity);

            // Send an end of entity reference event
            if (fDocHandler)
                fDocHandler->endEntityReference(toCatch.getEntity());

            inMarkup = false;
        }
    }

    // It went ok, so return success
    return true;
}


void XMLScanner::scanEndTag(bool& gotData)
{
    //
    //  Assume we will still have data until proven otherwise. It will only
    //  ever be false if this is the end of the root element.
    //
    gotData = true;

    //
    //  Check if the element stack is empty. If so, then this is an unbalanced
    //  element (i.e. more ends than starts, perhaps because of bad text
    //  causing one to be skipped.)
    //
    if (fElemStack.isEmpty())
    {
        emitError(XMLErrs::MoreEndThanStartTags);
        fReaderMgr.skipPastChar(chCloseAngle);
        ThrowXML(RuntimeException, XMLExcepts::Scan_UnbalancedStartEnd);
    }

    // After the </ is the element QName, so get a name from the input
    XMLBufBid bbQName(&fBufMgr);
    XMLBuffer& qnameBuf = bbQName.getBuffer();
    if (!fReaderMgr.getName(qnameBuf))
    {
        // It failed so we can't really do anything with it
        emitError(XMLErrs::ExpectedElementName);
        fReaderMgr.skipPastChar(chCloseAngle);
        return;
    }

    unsigned int elemId;
    unsigned int uriId = 0;
    if (fDoNamespaces)
    {
        XMLBufBid bbName(&fBufMgr);
        XMLBufBid bbPrefix(&fBufMgr);
        uriId = resolveQName
        (
            qnameBuf.getRawBuffer()
            , bbName.getBuffer()
            , bbPrefix.getBuffer()
            , ElemStack::Mode_Element
        );

        //
        //  Ask the validator for the element id for the {uri}name we got. He owns
        //  the element decl pool.
        //
        elemId = fGrammar->getElemId
        (
            uriId
            , bbName.getBuffer().getRawBuffer()
            , qnameBuf.getRawBuffer()
            , 0
        );
    }
     else
    {
        elemId = fGrammar->getElemId(0, 0, qnameBuf.getRawBuffer(), 0);
    }

    //
    //  Pop the stack of the element we are supposed to be ending. Remember
    //  that we don't own this. The stack just keeps them and reuses them.
    //
    //  NOTE: We CANNOT do this until we've resolved the element name because
    //  the element stack top contains the prefix to URI mappings for this
    //  element.
    //
    const ElemStack::StackElem* topElem = fElemStack.popTop();

    // Make sure that its the end of the element that we expect
    if (topElem->fThisElement->getId() != elemId)
    {
        emitError
        (
            XMLErrs::ExpectedEndOfTagX
            , topElem->fThisElement->getFullName()
        );
    }

    // Make sure we are back on the same reader as where we started
    if (topElem->fReaderNum != fReaderMgr.getCurrentReaderNum())
        emitError(XMLErrs::PartialTagMarkupError);

    // See if it was the root element, to avoid multiple calls below
    const bool isRoot = fElemStack.isEmpty();

    // Skip optional whitespace
    fReaderMgr.skipPastSpaces();

    // Make sure we find the closing bracket
    if (!fReaderMgr.skippedChar(chCloseAngle))
    {
        emitError
        (
            XMLErrs::UnterminatedEndTag
            , topElem->fThisElement->getFullName()
        );
    }

    // If we have a doc handler, tell it about the end tag
    if (fDocHandler)
    {
        fDocHandler->endElement
        (
            *topElem->fThisElement
            , uriId
            , isRoot
        );
    }

    //
    //  If validation is enabled, then lets pass him the list of children and
    //  this element and let him validate it.
    //
    if (fValidate)
    {
        int res = fValidator->checkContent
        (
            topElem->fThisElement->getId()
            , topElem->fChildIds
            , topElem->fChildCount
        );

        if (res >= 0)
        {
            //
            //  One of the elements is not valid for the content. NOTE that
            //  if no children were provided but the content model requires
            //  them, it comes back with a zero value. But we cannot use that
            //  to index the child array in this case, and have to put out a
            //  special message.
            //
            if (!topElem->fChildCount)
            {
                fValidator->emitError
                (
                    XMLValid::EmptyNotValidForContent
                    , topElem->fThisElement->getFormattedContentModel(*fGrammar)
                );
            }
             else if ((unsigned int)res >= topElem->fChildCount)
            {
                fValidator->emitError
                (
                    XMLValid::NotEnoughElemsForCM
                    , topElem->fThisElement->getFormattedContentModel(*fGrammar)
                );
            }
             else
            {
                // Find the element decl for the evil spawn
                XMLElementDecl* decl = fGrammar->getElemDecl
                (
                    topElem->fChildIds[res]
                );

                fValidator->emitError
                (
                    XMLValid::ElementNotValidForContent
                    , decl->getFullName()
                    , topElem->fThisElement->getFormattedContentModel(*fGrammar)
                );
            }
        }
    }

    // If this was the root, then done with content
    gotData = !isRoot;
}


//
//  This method is called after the end of the root element, to handle
//  any miscellaneous stuff hanging around.
//
void XMLScanner::scanMiscellaneous()
{
    // Get a buffer for this work
    XMLBufBid bbCData(&fBufMgr);

    while (true)
    {
        try
        {
            const XMLCh nextCh = fReaderMgr.peekNextChar();

            // Watch for end of file and break out
            if (!nextCh)
                break;

            if (nextCh == chOpenAngle)
            {
                if (fReaderMgr.skippedString(XMLUni::fgXMLStringSpace))
                {
                    // Can't have an XML decl here
                    emitError(XMLErrs::NotValidAfterContent);
                    fReaderMgr.skipPastChar(chCloseAngle);
                }
                 else if (fReaderMgr.skippedString(XMLUni::fgPIString))
                {
                    scanPI();
                }
                 else if (fReaderMgr.skippedString(XMLUni::fgCommentString))
                {
                    scanComment();
                }
                 else
                {
                    // This can't be possible, so just give up
                    emitError(XMLErrs::ExpectedCommentOrPI);
                    fReaderMgr.skipPastChar(chCloseAngle);
                }
            }
             else if (XMLReader::isWhitespace(nextCh))
            {
                //
                //  If we have a doc handler, then gather up the spaces and
                //  call back. Otherwise, just skip over whitespace.
                //
                if (fDocHandler)
                {
                    fReaderMgr.getSpaces(bbCData.getBuffer());
                    fDocHandler->ignorableWhitespace
                    (
                        bbCData.getRawBuffer()
                        , bbCData.getLen()
                        , false
                    );
                }
                 else
                {
                    fReaderMgr.skipPastSpaces();
                }
            }
             else
            {
                emitError(XMLErrs::ExpectedCommentOrPI);
                fReaderMgr.skipPastChar(chCloseAngle);
            }
        }

        catch(const EndOfEntityException&)
        {
            //
            //  Some entity leaked out of the content part of the document. Issue
            //  a warning and keep going.
            //
            emitError(XMLErrs::EntityPropogated);
        }
    }
}


//
//  Scans a PI and calls the appropriate callbacks. At entry we have just
//  scanned the <? part, and need to now start on the PI target name.
//
void XMLScanner::scanPI()
{
    const XMLCh* namePtr = 0;
    const XMLCh* targetPtr = 0;

    //
    //  If there are any spaces here, then warn about it. If we aren't in
    //  'first error' mode, then we'll come back and can easily pick up
    //  again by just skipping them.
    //
    if (fReaderMgr.lookingAtSpace())
    {
        emitError(XMLErrs::PINameExpected);
        fReaderMgr.skipPastSpaces();
    }

    // Get a buffer for the PI name and scan it in
    XMLBufBid bbName(&fBufMgr);
    if (!fReaderMgr.getNameToken(bbName.getBuffer()))
    {
        emitError(XMLErrs::PINameExpected);
        fReaderMgr.skipPastChar(chCloseAngle);
        return;
    }

    // Point the name pointer at the raw data
    namePtr = bbName.getRawBuffer();

    // See if it is some form of 'xml' and emit a warning
    if (!XMLString::compareIString(namePtr, XMLUni::fgXMLString))
        emitError(XMLErrs::NoPIStartsWithXML);

    // If namespaces are enabled, then no colons allowed
    if (fDoNamespaces)
    {
        if (XMLString::indexOf(namePtr, chColon) != -1)
            emitError(XMLErrs::ColonNotLegalWithNS);
    }

    //
    //  If we don't hit a space next, then the PI has no target. If we do
    //  then get out the target. Get a buffer for it as well
    //
    XMLBufBid bbTarget(&fBufMgr);
    if (fReaderMgr.skippedSpace())
    {
        // Skip any leading spaces
        fReaderMgr.skipPastSpaces();

        // It does have a target, so lets move on to deal with that.
        while (1)
        {
            const XMLCh nextCh = fReaderMgr.getNextChar();

            // Watch for an end of file, which is always bad here
            if (!nextCh)
            {
                emitError(XMLErrs::UnterminatedPI);
                ThrowXML(UnexpectedEOFException, XMLExcepts::Gen_UnexpectedEOF);
            }

            // Watch for potential terminating character
            if (nextCh == chQuestion)
            {
                // It must be followed by '>' to be a termination of the target
                if (fReaderMgr.skippedChar(chCloseAngle))
                    break;
            }

            // Watch for invalid chars but try to keep going
            if (!XMLReader::isXMLChar(nextCh))
            {
                XMLCh tmpBuf[9];
                XMLString::binToText
                (
                    nextCh
                    , tmpBuf
                    , 8
                    , 16
                );
                emitError(XMLErrs::InvalidCharacter, tmpBuf);
            }

            bbTarget.append(nextCh);
        }
    }
     else
    {
        // No target, but make sure its terminated ok
        if (!fReaderMgr.skippedChar(chQuestion))
        {
            emitError(XMLErrs::UnterminatedPI);
            fReaderMgr.skipPastChar(chCloseAngle);
            return;
        }

        if (!fReaderMgr.skippedChar(chCloseAngle))
        {
            emitError(XMLErrs::UnterminatedPI);
            fReaderMgr.skipPastChar(chCloseAngle);
            return;
        }
    }

    // Point the target pointer at the raw data
    targetPtr = bbTarget.getRawBuffer();

    // If we have a handler, then call it
    if (fDocHandler)
    {
        fDocHandler->docPI
        (
            namePtr
            , targetPtr
       );
    }
}


//
//  Scans all the input from the start of the file to the root element.
//  There does not have to be anything in the prolog necessarily, but usually
//  there is at least an XMLDecl.
//
//  On exit from here we are either at the end of the file or about to read
//  the opening < of the root element.
//
void XMLScanner::scanProlog()
{
    // Get a buffer for whitespace processing
    XMLBufBid bbCData(&fBufMgr);

    //
    //  Loop through the prolog. If there is no content, this could go all
    //  the way to the end of the file.
    //
    //  Note that we use a double loop here to avoid the overhead of the
    //  setup/teardown of the exception handler on each loop.
    //
    bool  acceptXMLDecl = true;
    while (true)
    {
    try
    {
        while (true)
        {
            const XMLCh nextCh = fReaderMgr.peekNextChar();

            // An end of file is legal here between markup
            if (!nextCh)
                return;

            if (nextCh == chOpenAngle)
            {
                //
                //  Ok, it could be the xml decl, a comment, the doc type line,
                //  or the start of the root element.
                //
                if (fReaderMgr.skippedString(XMLUni::fgXMLDeclStringSpace))
                {
                    //
                    //  If we are not at line 1, col 7, then the decl was not
                    //  the first text, so its invalid.
                    //
                    const XMLReader* curReader = fReaderMgr.getCurrentReader();
                    if ((curReader->getLineNumber() != 1)
                    ||  (curReader->getColumnNumber() != 7))
                    {
                        emitError(XMLErrs::XMLDeclMustBeFirst);
                    }
                    scanXMLDecl(Decl_XML);
                }
                 else if (fReaderMgr.skippedString(XMLUni::fgPIString))
                {
                    scanPI();
                }
                 else if (fReaderMgr.skippedString(XMLUni::fgCommentString))
                {
                    scanComment();
                }
                 else if (fReaderMgr.skippedString(XMLUni::fgDocTypeString))
                {

                    //
                    //  We have a doc type. So, create a DTDScanner and
                    //  store the Grammar in DTDGrammar.
                    //

                    DTDScanner dtdScanner((DTDGrammar*)fGrammar, fDocTypeHandler);
                    dtdScanner.setScannerInfo(this, &fReaderMgr, &fBufMgr);
                    dtdScanner.scanDocTypeDecl(fReuseGrammar);

                    //
                    //  Since we have seen a grammar, set our validation flag
                    //  at this point if the validation scheme is auto
                    //
                    if (fValScheme == Val_Auto)
                        fValidate = true;

                    //  if validating, then set up the validator
                    if (fValidate) {
                        if (fValidator) {
                            if (!fValidator->handlesDTD())
                                ThrowXML(RuntimeException, XMLExcepts::Gen_NoDTDValidator);
                        }
                        else {
                            fValidator = new DTDValidator();
                            initValidator();
                        }

                        ((DTDValidator*) fValidator)->setDTDGrammar((DTDGrammar*)fGrammar);
                        //
                        //  At this point, we know which type of validation we are going to
                        //  use (if the plugged in validator handles either DTD or Schemas)
                        //  since we will have seen the DOCTYPE or PI that set it up. So lets
                        //  ask the validator whether it requires namespaces or not. If it
                        //  does, we have to override the namespace enablement flag.
                        //
                        if (fValidator->requiresNamespaces() && !fDoNamespaces)
                            fDoNamespaces = true;

                        //  if validating, then validate the DTD scan so far
                        fValidator->preContentValidation(fReuseGrammar);
                    }

                }
                 else
                {
                    // Assume its the start of the root element
                    return;
                }
            }
             else if (XMLReader::isWhitespace(nextCh))
            {
                //
                //  If we have a document handler then gather up the
                //  whitespace and call back. Otherwise just skip over spaces.
                //
                if (fDocHandler)
                {
                    fReaderMgr.getSpaces(bbCData.getBuffer());
                    fDocHandler->ignorableWhitespace
                    (
                        bbCData.getRawBuffer()
                        , bbCData.getLen()
                        , false
                    );
                }
                 else
                {
                    fReaderMgr.skipPastSpaces();
                }
            }
             else
            {
                emitError(XMLErrs::InvalidDocumentStructure);
                fReaderMgr.skipPastChar(chCloseAngle);
            }

            //
            //  Once we make it around once, then we cannot accept the XML
            //  decl now, since it must be first if present.
            //
            acceptXMLDecl = false;
        }
    }

    catch(const EndOfEntityException&)
    {
        //
        //  We should never get an end of entity here. They should only
        //  occur within the doc type scanning method, and not leak out to
        //  here.
        //
        emitError
        (
            XMLErrs::UnexpectedEOE
            , "in prolog"
        );
    }
    }
}


bool XMLScanner::scanStartTag(bool& gotData)
{
    //
    //  Assume we will still have data until proven otherwise. It will only
    //  ever be false if this is the root and its empty.
    //
    gotData = true;

    //
    //  Get the QName. In this case, we are not doing namespaces, so we just
    //  use it as is and don't have to break it into parts.
    //
    if (!fReaderMgr.getName(fQNameBuf))
    {
        emitError(XMLErrs::ExpectedElementName);
        fReaderMgr.skipToChar(chOpenAngle);
        return false;
    }

    // Assume it won't be an empty tag
    bool isEmpty = false;

    //
    //  Lets try to look up the element in the validator's element decl pool
    //  We can pass bogus values for the URI id and the base name. We know that
    //  this can only be called if we are doing a DTD style validator and that
    //  he will only look at the QName.
    //
    //  We tell him to fault in a decl if he does not find one.
    //
    bool wasAdded;
    XMLElementDecl* elemDecl = fGrammar->findOrAddElemDecl
    (
        0
        , 0
        , 0
        , fQNameBuf.getRawBuffer()
        , 0
        , wasAdded
    );

    //
    //  We do something different here according to whether we found the
    //  element or not.
    //
    if (wasAdded)
    {
        // If validating then emit an error
        if (fValidate)
        {
            // This is to tell the reuse Validator that this element was
            // faulted-in, was not an element in the validator pool originally
            elemDecl->setCreateReason(XMLElementDecl::JustFaultIn);

            fValidator->emitError
            (
                XMLValid::ElementNotDefined
                , elemDecl->getFullName()
            );
        }

        //
        //  If we are not validating, then mark it as declared since it makes
        //  things simpler and we aren't going to do do the validation checks
        //  that need to know if it was really declared or not anyway.
        //
        if (!fValidate)
            elemDecl->setCreateReason(XMLElementDecl::Declared);
    }
     else
    {
        // If its not marked declared and validating, then emit an error
        if (!elemDecl->isDeclared() && fValidate)
        {
            fValidator->emitError
            (
                XMLValid::ElementNotDefined
                , elemDecl->getFullName()
            );
        }
    }

    // See if its the root element
    const bool isRoot = fElemStack.isEmpty();

    // Expand the element stack and add the new element
    fElemStack.addLevel(elemDecl, fReaderMgr.getCurrentReaderNum());

    //
    //  If this is the first element and we are validating, check the root
    //  element. This may or may not have any meaning for the installed
    //  validator, in which case it may just always return success. Some
    //  validators will treat any element as the root.
    //
    if (isRoot)
    {
        if (fValidate)
        {
            if (!fValidator->checkRootElement(elemDecl->getId()))
                fValidator->emitError(XMLValid::RootElemNotLikeDocType);
        }
    }
     else
    {
        //
        //  If the element stack is not empty, then add this element as a
        //  child of the previous top element. If its empty, this is the root
        //  elem and is not the child of anything.
        //
        fElemStack.addChild(elemDecl->getId(), true);
    }

    //
    //  Ask the element decl to clear out the 'provided' flag on all of its
    //  att defs.
    //
    elemDecl->resetDefs();

    // Skip any whitespace after the name
    fReaderMgr.skipPastSpaces();

    //
    //  We loop until we either see a /> or >, handling attribute/value
    //  pairs until we get there.
    //
    unsigned int    attCount = 0;
    unsigned int    curAttListSize = fAttrList->size();
    while (true)
    {
        // And get the next non-space character
        XMLCh nextCh = fReaderMgr.peekNextChar();

        //
        //  If the next character is not a slash or closed angle bracket,
        //  then it must be whitespace, since whitespace is required
        //  between the end of the last attribute and the name of the next
        //  one.
        //
        if (attCount)
        {
            if ((nextCh != chForwardSlash) && (nextCh != chCloseAngle))
            {
                if (XMLReader::isWhitespace(nextCh))
                {
                    // Ok, skip by them and peek another char
                    fReaderMgr.skipPastSpaces();
                    nextCh = fReaderMgr.peekNextChar();
                }
                 else
                {
                    // Emit the error but keep on going
                    emitError(XMLErrs::ExpectedWhitespace);
                }
            }
        }

        //
        //  Ok, here we first check for any of the special case characters.
        //  If its not one, then we do the normal case processing, which
        //  assumes that we've hit an attribute value, Otherwise, we do all
        //  the special case checks.
        //
        if (!XMLReader::isSpecialStartTagChar(nextCh))
        {
            //
            //  Assume its going to be an attribute, so get a name from
            //  the input.
            //
            if (!fReaderMgr.getName(fAttNameBuf))
            {
                emitError(XMLErrs::ExpectedAttrName);
                fReaderMgr.skipPastChar(chCloseAngle);
                return false;
            }

            // And next must be an equal sign
            if (!scanEq())
            {
                static const XMLCh tmpList[] =
                {
                    chSingleQuote, chDoubleQuote, chCloseAngle
                    , chOpenAngle, chForwardSlash, chNull
                };

                emitError(XMLErrs::ExpectedEqSign);

                //
                //  Try to sync back up by skipping forward until we either
                //  hit something meaningful.
                //
                const XMLCh chFound = fReaderMgr.skipUntilInOrWS(tmpList);

                if ((chFound == chCloseAngle) || (chFound == chForwardSlash))
                {
                    // Jump back to top for normal processing of these
                    continue;
                }
                 else if ((chFound == chSingleQuote)
                      ||  (chFound == chDoubleQuote)
                      ||  XMLReader::isWhitespace(chFound))
                {
                    // Just fall through assuming that the value is to follow
                }
                 else if (chFound == chOpenAngle)
                {
                    // Assume a malformed tag and that new one is starting
                    emitError(XMLErrs::UnterminatedStartTag, elemDecl->getFullName());
                    return false;
                }
                 else
                {
                    // Something went really wrong
                    return false;
                }
            }

            //
            //  See if this attribute is declared for this element. If we are
            //  not validating of course it will not be at first, but we will
            //  fault it into the pool (to avoid lots of redundant errors.)
            //
            XMLAttDef* attDef = elemDecl->findAttr
            (
                fAttNameBuf.getRawBuffer()
                , 0
                , 0
                , 0
                , XMLElementDecl::AddIfNotFound
                , wasAdded
            );

            if (wasAdded)
            {
                //
                //  If there is a validation handler, then we are validating
                //  so emit an error.
                //
                if (fValidate)
                {
                   // This is to tell the reuse Validator that this attribute was
                   // faulted-in, was not an attribute in the attdef originally
                    if(!fReuseGrammar)
                       attDef->setCreateReason(XMLAttDef::JustFaultIn);

                    fValidator->emitError
                    (
                        XMLValid::AttNotDefinedForElement
                        , fAttNameBuf.getRawBuffer()
                        , elemDecl->getFullName()
                    );
                }
            }
            else
            {
               // If we are reusing validator and this attribute was faulted-in,
               // then emit an error
               if (fValidate)
               {
                  if (fReuseGrammar && attDef->getCreateReason()==XMLAttDef::JustFaultIn)
                  {
                      //reset the CreateReason to avoid redundant error
                      attDef->setCreateReason(XMLAttDef::NoReason);

                      fValidator->emitError
                      (
                          XMLValid::AttNotDefinedForElement
                          , fAttNameBuf.getRawBuffer()
                          , elemDecl->getFullName()
                      );
                   }
                }
            }

            //
            //  If its already provided, then there are more than one of
            //  this attribute in this start tag, so emit an error.
            //
            if (attDef->getProvided())
            {
                emitError
                (
                    XMLErrs::AttrAlreadyUsedInSTag
                    , attDef->getFullName()
                    , elemDecl->getFullName()
                );
            }
             else
            {
                // Mark this one as already seen
                attDef->setProvided(true);
            }

            //
            //  Skip any whitespace before the value and then scan the att
            //  value. This will come back normalized with entity refs and
            //  char refs expanded.
            //
            fReaderMgr.skipPastSpaces();
            if (!scanAttValue(attDef->getFullName(), fAttValueBuf, attDef->getType()))
            {
                static const XMLCh tmpList[] =
                {
                    chCloseAngle, chOpenAngle, chForwardSlash, chNull
                };

                emitError(XMLErrs::ExpectedAttrValue);

                //
                //  It failed, so lets try to get synced back up. We skip
                //  forward until we find some whitespace or one of the
                //  chars in our list.
                //
                const XMLCh chFound = fReaderMgr.skipUntilInOrWS(tmpList);

                if ((chFound == chCloseAngle)
                ||  (chFound == chForwardSlash)
                ||  XMLReader::isWhitespace(chFound))
                {
                    //
                    //  Just fall through and process this attribute, though
                    //  the value will be "".
                    //
                }
                 else if (chFound == chOpenAngle)
                {
                    // Assume a malformed tag and that new one is starting
                    emitError(XMLErrs::UnterminatedStartTag, elemDecl->getFullName());
                    return false;
                }
                 else
                {
                    // Something went really wrong
                    return false;
                }
            }

            //
            //  Now that its all stretched out, lets look at its type and
            //  determine if it has a valid value. It will output any needed
            //  errors, but we just keep going. We only need to do this if
            //  we are validating.
            //
            if (!wasAdded)
            {
                // Let the validator pass judgement on the attribute value
                if (fValidate)
                {
                    fValidator->validateAttrValue
                    (
                        *attDef
                        , fAttValueBuf.getRawBuffer()
                    );
                }
            }

            //
            //  Add this attribute to the attribute list that we use to
            //  pass them to the handler. We reuse its existing elements
            //  but expand it as required.
            //
            XMLAttr* curAtt;
            if (attCount >= curAttListSize)
            {
                curAtt = new XMLAttr
                (
                    -1
                    , fAttNameBuf.getRawBuffer()
                    , XMLUni::fgZeroLenString
                    , fAttValueBuf.getRawBuffer()
                    , attDef->getType()
                    , true
                );
                fAttrList->addElement(curAtt);
            }
             else
            {
                curAtt = fAttrList->elementAt(attCount);
                curAtt->set
                (
                    -1
                    , fAttNameBuf.getRawBuffer()
                    , XMLUni::fgZeroLenString
                    , fAttValueBuf.getRawBuffer()
                    , attDef->getType()
                );
                curAtt->setSpecified(true);
            }
            attCount++;

            // And jump back to the top of the loop
            continue;
        }

        //
        //  It was some special case character so do all of the checks and
        //  deal with it.
        //
        if (!nextCh)
            ThrowXML(UnexpectedEOFException, XMLExcepts::Gen_UnexpectedEOF);

        if (nextCh == chForwardSlash)
        {
            fReaderMgr.getNextChar();
            isEmpty = true;
            if (!fReaderMgr.skippedChar(chCloseAngle))
                emitError(XMLErrs::UnterminatedStartTag, elemDecl->getFullName());
            break;
        }
         else if (nextCh == chCloseAngle)
        {
            fReaderMgr.getNextChar();
            break;
        }
         else if (nextCh == chOpenAngle)
        {
            //
            //  Check for this one specially, since its going to be common
            //  and it is kind of auto-recovering since we've already hit the
            //  next open bracket, which is what we would have seeked to (and
            //  skipped this whole tag.)
            //
            emitError(XMLErrs::UnterminatedStartTag, elemDecl->getFullName());
            break;
        }
         else if ((nextCh == chSingleQuote) || (nextCh == chDoubleQuote))
        {
            //
            //  Check for this one specially, which is probably a missing
            //  attribute name, e.g. ="value". Just issue expected name
            //  error and eat the quoted string, then jump back to the
            //  top again.
            //
            emitError(XMLErrs::ExpectedAttrName);
            scanAttValue(XMLUni::fgZeroLenString, fAttValueBuf, XMLAttDef::CData);
            fReaderMgr.skipPastSpaces();
            continue;
        }
    }

    //
    //  Ok, so lets get an enumerator for the attributes of this element
    //  and run through them for well formedness and validity checks. But
    //  make sure that we had any attributes before we do it, since the list
    //  would have have gotten faulted in anyway.
    //
    if (elemDecl->hasAttDefs())
    {
        XMLAttDefList& attDefList = elemDecl->getAttDefList();
        while (attDefList.hasMoreElements())
        {
            // Get the current att def, for convenience and its def type
            const XMLAttDef& curDef = attDefList.nextElement();
            const XMLAttDef::DefAttTypes defType = curDef.getDefaultType();

            if (!curDef.getProvided())
            {
                if (fValidate)
                {
                    // If we are validating and its required, then an error
                    if (defType == XMLAttDef::Required)
                    {
                        fValidator->emitError
                        (
                            XMLValid::RequiredAttrNotProvided
                            , curDef.getFullName()
                            , elemDecl->getFullName()
                        );
                    }
		            else if ((defType == XMLAttDef::Default) ||
		                     (defType == XMLAttDef::Fixed)  )
					{
		                if (fStandalone)
		                {
			                //
			                // XML 1.0 Section 2.9
			                // Document is standalone, so attributes must not be defaulted.
			                //
			                emitError(XMLErrs::BadStandalone, elemDecl->getFullName());

		                 }
		             }
                }

                // Fault in the value if needed, and bump the att count
                if ((defType == XMLAttDef::Default)
                ||  (defType == XMLAttDef::Fixed))
                {
                    XMLAttr* curAtt;
                    if (attCount >= curAttListSize)
                    {
                        curAtt = new XMLAttr
                        (
                            -1
                            , curDef.getFullName()
                            , XMLUni::fgZeroLenString
                            , curDef.getValue()
                            , curDef.getType()
                            , false
                        );
                        fAttrList->addElement(curAtt);
                        curAttListSize++;
                    }
                     else
                    {
                        curAtt = fAttrList->elementAt(attCount);
                        curAtt->set
                        (
                            -1
                            , curDef.getFullName()
                            , XMLUni::fgZeroLenString
                            , curDef.getValue()
                            , curDef.getType()
                        );
                        curAtt->setSpecified(false);
                    }
                    attCount++;
                }
            }
        }
    }

    //
    //  If empty, validate content right now if we are validating and then
    //  pop the element stack top. Else, we have to update the current stack
    //  top's namespace mapping elements.
    //
    if (isEmpty)
    {
        // If validating, then insure that its legal to have no content
        if (fValidate)
        {
            const int res = fValidator->checkContent(elemDecl->getId(), 0, 0);
            if (res >= 0)
            {
                fValidator->emitError
                (
                    XMLValid::ElementNotValidForContent
                    , elemDecl->getFullName()
                    , elemDecl->getFormattedContentModel(*fGrammar)
                );
            }
        }

        // Pop the element stack back off since it'll never be used now
        fElemStack.popTop();

        // If the elem stack is empty, then it was an empty root
        if (isRoot)
            gotData = false;
    }

    //
    //  If we have a document handler, then tell it about this start tag. We
    //  don't have any URI id to send along, so send zero. We also do not send
    //  any prefix since its just one big name if we are not doing namespaces.
    //
    if (fDocHandler)
    {
        fDocHandler->startElement
        (
            *elemDecl
            , 0
            , 0
            , *fAttrList
            , attCount
            , isEmpty
            , isRoot
        );
    }

    return true;
}


//
//
//  This method is called to scan a start tag when we are processing
//  namespaces. There are two different versions of this method, one for
//  namespace aware processing an done for non-namespace aware processing.
//
//  This method is called after we've scanned the < of a start tag. So we
//  have to get the element name, then scan the attributes, after which
//  we are either going to see >, />, or attributes followed by one of those
//  sequences.
//
bool XMLScanner::scanStartTagNS(bool& gotData)
{
    //
    //  Assume we will still have data until proven otherwise. It will only
    //  ever be false if this is the root and its empty.
    //
    gotData = true;

    //
    //  The current position is after the open bracket, so we need to read in
    //  in the element name.
    //
    if (!fReaderMgr.getName(fQNameBuf))
    {
        emitError(XMLErrs::ExpectedElementName);
        fReaderMgr.skipToChar(chOpenAngle);
        return false;
    }

    //
    //  Do a little sanity check here. One common problem is that
    //  badly encoded files cause getName() to exit above on a
    //  non-name char (an invalid XML char), then the scan start
    //  tag below fails. This is misleading, so check here that
    //  we are looking at a valid XML char.
    //
    if (!XMLReader::isXMLChar(fReaderMgr.peekNextChar()))
    {
        XMLCh tmpBuf[9];
        XMLString::binToText
        (
            fReaderMgr.getNextChar()
            , tmpBuf
            , 8
            , 16
        );
        emitError(XMLErrs::InvalidCharacter, tmpBuf);
    }

    // See if its the root element
    const bool isRoot = fElemStack.isEmpty();

    // Skip any whitespace after the name
    fReaderMgr.skipPastSpaces();

    //
    //  First we have to do the rawest attribute scan. We don't do any
    //  normalization of them at all, since we don't know yet what type they
    //  might be (since we need the element decl in order to do that.)
    //
    bool isEmpty;
    unsigned int attCount = rawAttrScan
    (
        fQNameBuf.getRawBuffer()
        , *fRawAttrList
        , isEmpty
    );
    const bool gotAttrs = (attCount != 0);

    //
    //  Now, since we might have to update the namespace map for this element,
    //  but we don't have the element decl yet, we just tell the element stack
    //  to expand up to get ready.
    //
    fElemStack.addLevel();

    //
    //  Make an initial pass through the list and find any xmlns attributes or
    //  schema attributes.
    //
    if (attCount)
      scanRawAttrListforNameSpaces(fRawAttrList, attCount);

    //
    //  Resolve the qualified name to a URI and name so that we can look up
    //  the element decl for this element. We have now update the prefix to
    //  namespace map so we should get the correct element now.
    //
    //  <TBD>
    //  <NOTE> There is an issue here in that (when Schema comes along) if
    //  there were defauled/fixed xmlns attributes defined for this element,
    //  it is too late for them to affect the prefix of this element (though
    //  technically they should.) There is no way out of this unfortunately.
    //
    const unsigned int uriId = resolveQName
    (
        fQNameBuf.getRawBuffer()
        , fNameBuf
        , fPrefixBuf
        , ElemStack::Mode_Element
    );

    //
    //  Look up the element now in the validator. This will get us back a
    //  generic element decl object. We tell him to fault one in if he does
    //  not find it.
    //
    bool wasAdded;
    XMLElementDecl* elemDecl = fGrammar->findOrAddElemDecl
    (
        uriId
        , fNameBuf.getRawBuffer()
        , fPrefixBuf.getRawBuffer()
        , fQNameBuf.getRawBuffer()
        , 0
        , wasAdded
    );

    //
    //  We do something different here according to whether we found the
    //  element or not.
    //
    if (wasAdded)
    {
        // If validating then emit an error
        if (fValidate)
        {
            // This is to tell the reuse Validator that this element was
            // faulted-in, was not an element in the validator pool originally
            elemDecl->setCreateReason(XMLElementDecl::JustFaultIn);

            fValidator->emitError
            (
                XMLValid::ElementNotDefined
                , elemDecl->getFullName()
            );
        }

        //
        //  If we are not validating, then mark it as declared since it makes
        //  things simpler and we aren't going to do do the validation checks
        //  that need to know if it was really declared or not anyway.
        //
        if (!fValidate)
            elemDecl->setCreateReason(XMLElementDecl::Declared);
    }
     else
    {
        // If its not marked declared and validating, then emit an error
        if (!elemDecl->isDeclared() && fValidate)
        {
            fValidator->emitError
            (
                XMLValid::ElementNotDefined
                , elemDecl->getFullName()
            );
        }
    }

    //
    //  Now we can update the element stack to set the current element
    //  decl. We expanded the stack above, but couldn't store the element
    //  decl because we didn't know it yet.
    //
    fElemStack.setElement(elemDecl, fReaderMgr.getCurrentReaderNum());

    //
    //  If this is the first element and we are validating, check the root
    //  element. This may or may not have any meaning for the installed
    //  validator, in which case it may just always return success. Some
    //  validators will treat any element as the root.
    //
    if (isRoot)
    {
        if (fValidate)
        {
            if (!fValidator->checkRootElement(elemDecl->getId()))
                fValidator->emitError(XMLValid::RootElemNotLikeDocType);
        }
    }
     else
    {
        //
        //  If the element stack is not empty, then add this element as a
        //  child of the previous top element. If its empty, this is the root
        //  elem and is not the child of anything.
        //
        fElemStack.addChild(elemDecl->getId(), true);
    }

    //
    //  Now lets get the fAttrList filled in. This involves faulting in any
    //  defaulted and fixed attributes and normalizing the values of any that
    //  we got explicitly.
    //
    //  We update the attCount value with the total number of attributes, but
    //  it goes in with the number of values we got during the raw scan of
    //  explictly provided attrs above.
    //
    attCount = buildAttList(*fRawAttrList, attCount, *elemDecl, *fAttrList);

    //
    //  If empty, validate content right now if we are validating and then
    //  pop the element stack top. Else, we have to update the current stack
    //  top's namespace mapping elements.
    //
    if (isEmpty)
    {
        // Pop the element stack back off since it'll never be used now
        fElemStack.popTop();

        // If validating, then insure that its legal to have no content
        if (fValidate)
        {
            const int res = fValidator->checkContent(elemDecl->getId(), 0, 0);
            if (res >= 0)
            {
                fValidator->emitError
                (
                    XMLValid::ElementNotValidForContent
                    , elemDecl->getFullName()
                    , elemDecl->getFormattedContentModel(*fGrammar)
                );
            }
        }

        // If the elem stack is empty, then it was an empty root
        if (isRoot)
            gotData = false;
    }

    // If we have a document handler, then tell it about this start tag
    if (fDocHandler)
    {
        fDocHandler->startElement
        (
            *elemDecl
            , uriId
            , fPrefixBuf.getRawBuffer()
            , *fAttrList
            , attCount
            , isEmpty
            , isRoot
        );
    }

    return true;
}


//
//  Scans the <?xml .... ?> line. This stuff is all sequential so we don't
//  do any state machine loop here. We just bull straight through it. It ends
//  past the closing bracket. If there is a document handler, then its called
//  on the XMLDecl callback.
//
//  On entry, the <?xml has been scanned, and we pick it up from there.
//
//  NOTE: In order to provide good recovery from bad XML here, we try to be
//  very flexible. No matter what order the stuff is in, we'll keep going
//  though we'll issue errors.
//
//  The parameter tells us which type of decl we should expect, Text or XML.
//
void XMLScanner::scanXMLDecl(const DeclTypes type)
{
    // Get us some buffers to use
    XMLBufBid bbVersion(&fBufMgr);
    XMLBufBid bbEncoding(&fBufMgr);
    XMLBufBid bbStand(&fBufMgr);
    XMLBufBid bbDummy(&fBufMgr);
    XMLBufBid bbName(&fBufMgr);

    //
    //  We use this little enum and array to keep up with what we found
    //  and what order we found them in. This lets us get them free form
    //  without too much overhead, but still know that they were in the
    //  wrong order.
    //
    enum Strings
    {
        VersionString
        , EncodingString
        , StandaloneString
        , UnknownString

        , StringCount
    };
    int flags[StringCount] = { -1, -1, -1, -1 };

    //
    //  Also set up a list of buffers in the right order so that we know
    //  where to put stuff.
    //
    XMLBuffer* buffers[StringCount] ;
    buffers[0] = &bbVersion.getBuffer();
    buffers[1] = &bbEncoding.getBuffer();
    buffers[2] = &bbStand.getBuffer();
    buffers[3] = &bbDummy.getBuffer();

    int curCount = 0;
    Strings curString;
    XMLBuffer& nameBuf = bbName.getBuffer();
    while (true)
    {
        // Skip any spaces
        const unsigned int spaceCount = fReaderMgr.skipPastSpaces();

        // If we are looking at a question mark, then break out
        if (fReaderMgr.lookingAtChar(chQuestion))
            break;

        // If this is not the first string, then we require the spaces
        if (!spaceCount && curCount)
            emitError(XMLErrs::ExpectedWhitespace);

        //
        //  Get characters up to the next whitespace or equal's sign.
        //
        if (!scanUpToWSOr(nameBuf, chEqual))
            emitError(XMLErrs::ExpectedDeclString);

        // See if it matches any of our expected strings
        if (!XMLString::compareString(nameBuf.getRawBuffer(), XMLUni::fgVersionString))
            curString = VersionString;
        else if (!XMLString::compareString(nameBuf.getRawBuffer(), XMLUni::fgEncodingString))
            curString = EncodingString;
        else if (!XMLString::compareString(nameBuf.getRawBuffer(), XMLUni::fgStandaloneString))
            curString = StandaloneString;
        else
            curString = UnknownString;

        //
        //  If its an unknown string, then give that error. Else check to
        //  see if this one has been done already and give that error.
        //
        if (curString == UnknownString)
            emitError(XMLErrs::ExpectedDeclString, nameBuf.getRawBuffer());
        else if (flags[curString] != -1)
            emitError(XMLErrs::DeclStringRep, nameBuf.getRawBuffer());
        else if (flags[curString] == -1)
            flags[curString] = ++curCount;

        //
        //  Scan for an equal's sign. If we don't find it, issue an error
        //  but keep trying to go on.
        //
        if (!scanEq())
            emitError(XMLErrs::ExpectedEqSign);

        //
        //  Get a quote string into the buffer for the string that we are
        //  currently working on.
        //
        if (!getQuotedString(*buffers[curString]))
        {
            emitError(XMLErrs::ExpectedQuotedString);
            fReaderMgr.skipPastChar(chCloseAngle);
            return;
        }

        // And validate the value according which one it was
        const XMLCh* rawValue = buffers[curString]->getRawBuffer();
        if (curString == VersionString)
        {
            if (XMLString::compareString(rawValue, XMLUni::fgSupportedVersion))
                emitError(XMLErrs::UnsupportedXMLVersion, rawValue);
        }
         else if (curString == EncodingString)
        {
            if (!XMLString::stringLen(rawValue))
                emitError(XMLErrs::BadXMLEncoding, rawValue);
        }
         else if (curString == StandaloneString)
        {
            if (!XMLString::compareString(rawValue, XMLUni::fgYesString))
                fStandalone = true;
            else if (!XMLString::compareString(rawValue, XMLUni::fgNoString))
                fStandalone = false;
            else
            {
                emitError(XMLErrs::BadStandalone);
                if (!XMLString::compareIString(rawValue, XMLUni::fgYesString))
                    fStandalone = true;
                else if (!XMLString::compareIString(rawValue, XMLUni::fgNoString))
                    fStandalone = false;
            }
        }
    }

    //
    //  Make sure that the strings present are in order. We don't care about
    //  which ones are present at this point, just that any there are in the
    //  right order.
    //
    int curTop = 0;
    for (int index = VersionString; index < StandaloneString; index++)
    {
        if (flags[index] != -1)
        {
            if (flags[index] !=  curTop + 1)
            {
                emitError(XMLErrs::DeclStringsInWrongOrder);
                break;
            }
            curTop = flags[index];
        }
    }

    //
    //  If its an XML decl, the version must be present. If its a Text decl
    //  then standalone must not be present.
    //
    if ((type == Decl_XML) && (flags[VersionString] == -1))
        emitError(XMLErrs::XMLVersionRequired);
    else if ((type == Decl_Text) && (flags[StandaloneString] != -1))
        emitError(XMLErrs::StandaloneNotLegal);

    if (!fReaderMgr.skippedChar(chQuestion))
    {
        emitError(XMLErrs::UnterminatedXMLDecl);
        fReaderMgr.skipPastChar(chCloseAngle);
    }
     else if (!fReaderMgr.skippedChar(chCloseAngle))
    {
        emitError(XMLErrs::UnterminatedXMLDecl);
        fReaderMgr.skipPastChar(chCloseAngle);
    }

    //
    //  If we have a document handler then call the XML Decl callback.
    //
    //  !NOTE! Do this before we possibly update the reader with the
    //  actual encoding string. Otherwise, we will pass the wrong thing
    //  for the last parameter!
    //
    if (fDocHandler)
    {
        fDocHandler->XMLDecl
        (
            bbVersion.getRawBuffer()
            , bbEncoding.getRawBuffer()
            , bbStand.getRawBuffer()
            , fReaderMgr.getCurrentEncodingStr()
        );
    }

    //
    //  Ok, we've now seen the real encoding string, if there was one, so
    //  lets call back on the current reader and tell it what the real
    //  encoding string was. If it fails, that's because it represents some
    //  sort of contradiction with the autosensed format, and it keeps the
    //  original encoding.
    //
    //  NOTE: This can fail for a number of reasons, such as a bogus encoding
    //  name or because its in flagrant contradiction of the auto-sensed
    //  format.
    //
    if (flags[EncodingString] != -1)
    {
        if (!fReaderMgr.getCurrentReader()->setEncoding(bbEncoding.getRawBuffer()))
            emitError(XMLErrs::ContradictoryEncoding, bbEncoding.getRawBuffer());
    }
}

const XMLCh* XMLScanner::getURIText(const   unsigned int    uriId) const
{
    // Look up the URI in the string pool and return its id
    const XMLCh* value = fURIStringPool->getValueForId(uriId);
    if (!value)
        return XMLUni::fgZeroLenString;

	return value;
}

bool XMLScanner::getURIText(  const   unsigned int    uriId
                      ,       XMLBuffer&      uriBufToFill) const
{
    // Look up the URI in the string pool and return its id
    const XMLCh* value = fURIStringPool->getValueForId(uriId);
    if (!value)
        return false;

    uriBufToFill.set(value);
    return true;
}

