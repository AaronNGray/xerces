/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 1999-2001 The Apache Software Foundation.  All rights
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
#include <xercesc/util/Janitor.hpp>
#include <xercesc/util/RefHashTableOf.hpp>
#include <xercesc/util/XML88591Transcoder.hpp>
#include <xercesc/util/XMLASCIITranscoder.hpp>
#include <xercesc/util/XMLChTranscoder.hpp>
#include <xercesc/util/XMLEBCDICTranscoder.hpp>
#include <xercesc/util/XMLIBM1140Transcoder.hpp>
#include <xercesc/util/XMLUCS4Transcoder.hpp>
#include <xercesc/util/XMLUTF8Transcoder.hpp>
#include <xercesc/util/XMLUTF16Transcoder.hpp>
#include <xercesc/util/XMLWin1252Transcoder.hpp>
#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/util/XMLUni.hpp>
#include <xercesc/util/TransENameMap.hpp>



// ---------------------------------------------------------------------------
//  Local, static data
//
//  gMappings
//      This is a hash table of ENameMap objects. It is created and filled
//      in when the platform init calls our initTransService() method.
//
//  gDisallow1
//  gDisallowX
//      These area small set of encoding names that, for temporary reasons,
//      we disallow at this time.
//
//  gDisallowList
//  gDisallowListSize
//      An array of the disallow strings, for easier searching below.
//
//  gDisallowPre
//      All of the disallowed encodings start with 'IBM', so we have a prefix
//      we can check for and quickly decide if we need to search the list.
// ---------------------------------------------------------------------------
static RefHashTableOf<ENameMap>*    gMappings = 0;
static XMLCh                        gDisallow1[] =
{
        chLatin_I, chLatin_B, chLatin_M, chDash, chDigit_0, chDigit_3
      , chDigit_7, chNull
};
static XMLCh                        gDisallow2[] =
{
        chLatin_I, chLatin_B, chLatin_M, chDash, chDigit_3, chDigit_7, chNull
};
static XMLCh                        gDisallow3[] =
{
        chLatin_I, chLatin_B, chLatin_M, chDash, chDigit_0, chDigit_3
    ,   chDigit_7, chDash, chLatin_S, chDigit_3, chDigit_9, chDigit_0, chNull
};
static XMLCh                        gDisallow4[] =
{
        chLatin_I, chLatin_B, chLatin_M, chDash, chDigit_3, chDigit_7, chDash
    ,   chLatin_S, chDigit_3, chDigit_9, chDigit_0, chNull
};
static XMLCh                        gDisallow5[] =
{
        chLatin_I, chLatin_B, chLatin_M, chDash, chDigit_1, chDigit_1
      , chDigit_4, chDigit_0, chNull
};
static XMLCh                        gDisallow6[] =
{
        chLatin_I, chLatin_B, chLatin_M, chDash, chDigit_1, chDigit_1
      , chDigit_4, chDigit_0, chDash, chLatin_S, chDigit_3
      , chDigit_9, chDigit_0, chNull
};
static const unsigned int           gDisallowListSize = 6;
static XMLCh*                       gDisallowList[gDisallowListSize] =
{
    gDisallow1, gDisallow2, gDisallow3, gDisallow4, gDisallow5, gDisallow6
};
static XMLCh                        gDisallowPre[] =
{
        chLatin_I, chLatin_B, chLatin_M, chNull
};



// ---------------------------------------------------------------------------
//  XLMTransService: Constructors and destructor
// ---------------------------------------------------------------------------
XMLTransService::XMLTransService()
{
}

XMLTransService::~XMLTransService()
{
    delete gMappings;    // The contents of the gMappings hash table are owned by
    gMappings = 0;       //   the it, and so will be deleted by gMapping's destructor.
}

// ---------------------------------------------------------------------------
//	Allow user specific encodings to be added to the mappings table.
//	Should be called after platform init
// ---------------------------------------------------------------------------
void XMLTransService::addEncoding(const XMLCh* const encoding,
								  ENameMap* const ownMapping) {

	if (gMappings) {

		gMappings->put((void *) encoding, ownMapping);
	}
}

// ---------------------------------------------------------------------------
//  XLMTranscoder: Non-virtual API
// ---------------------------------------------------------------------------
XMLTranscoder*
XMLTransService::makeNewTranscoderFor(  const   char* const             encodingName
                                        ,       XMLTransService::Codes& resValue
                                        , const unsigned int            blockSize)
{
    XMLCh* tmpName = XMLString::transcode(encodingName);
    ArrayJanitor<XMLCh> janName(tmpName);

    return makeNewTranscoderFor(tmpName, resValue, blockSize);
}

XMLTranscoder*
XMLTransService::makeNewTranscoderFor(  const   XMLCh* const            encodingName
                                        ,       XMLTransService::Codes& resValue
                                        , const unsigned int            blockSize)
{
    //
    //  First try to find it in our list of mappings to intrinsically
    //  supported encodings. We have to upper case the passed encoding
    //  name because we use a hash table and we stored all our mappings
    //  in all uppercase.
    //
    const unsigned int bufSize = 2048;
    XMLCh upBuf[bufSize + 1];
    if (!XMLString::copyNString(upBuf, encodingName, bufSize))
        return 0;
    XMLString::upperCase(upBuf);
    ENameMap* ourMapping = gMappings->get(upBuf);

    // If we found it, then call the factory method for it
    if (ourMapping)
        return ourMapping->makeNew(blockSize);

    //
    //  For now, we have a little list of encodings that we disallow
    //  explicitly. So lets check for them up front. They all start with
    //  IBM, so we can do a quick check to see if we should even do
    //  anything at all.
    //
    if (XMLString::startsWith(upBuf, gDisallowPre))
    {
        for (unsigned int index = 0; index < gDisallowListSize; index++)
        {
            // If its one of our guys, then pretend we don't understand it
            if (!XMLString::compareString(upBuf, gDisallowList[index]))
                return 0;
        }
    }

    //
    //  It wasn't an intrinsic and it wasn't disallowed, so pass it on
    //  to the trans service to see if he can make anything of it.
    //
    return makeNewXMLTranscoder(encodingName, resValue, blockSize);
}


// ---------------------------------------------------------------------------
//  XLMTranscoder: Public Destructor
// ---------------------------------------------------------------------------
XMLTranscoder::~XMLTranscoder()
{
    delete [] fEncodingName;
}


// ---------------------------------------------------------------------------
//  XLMTranscoder: Hidden Constructors
// ---------------------------------------------------------------------------
XMLTranscoder::XMLTranscoder(const  XMLCh* const    encodingName
                            , const unsigned int    blockSize) :
    fEncodingName(0)
    , fBlockSize(blockSize)
{
    fEncodingName = XMLString::replicate(encodingName);
}


// ---------------------------------------------------------------------------
//  XLMTranscoder: Protected helpers
// ---------------------------------------------------------------------------
void XMLTranscoder::checkBlockSize(const unsigned int toCheck)
{
//    if (toCheck > fBlockSize)
//        ThrowXML(TranscodingException, XMLExcepts::Trans_BadBlockSize);
}


// ---------------------------------------------------------------------------
//  XLMLCPTranscoder: Public Destructor
// ---------------------------------------------------------------------------
XMLLCPTranscoder::XMLLCPTranscoder()
{
}


// ---------------------------------------------------------------------------
//  XLMTranscoder: Hidden Constructors
// ---------------------------------------------------------------------------
XMLLCPTranscoder::~XMLLCPTranscoder()
{
}

// ---------------------------------------------------------------------------
//  XLMTranscoder: Hidden Init Method
//
//  This is called by platform utils during startup.
// ---------------------------------------------------------------------------
void XMLTransService::initTransService()
{

    //
    //  Create our hash table that we will fill with mappings. The default
    //  is to adopt the elements, which is fine with us.
    //
    gMappings = new RefHashTableOf<ENameMap>(103);

    //
    //  Add in the magical mapping for the native XMLCh transcoder. This
    //  is used for internal entities.
    //
    gMappings->put((void*)XMLUni::fgXMLChEncodingString, new ENameMapFor<XMLChTranscoder>(XMLUni::fgXMLChEncodingString));

    //
    //  Add in our mappings for ASCII.
    //
    gMappings->put((void*)XMLUni::fgUSASCIIEncodingString, new ENameMapFor<XMLASCIITranscoder>(XMLUni::fgUSASCIIEncodingString));
    gMappings->put((void*)XMLUni::fgUSASCIIEncodingString2, new ENameMapFor<XMLASCIITranscoder>(XMLUni::fgUSASCIIEncodingString2));
    gMappings->put((void*)XMLUni::fgUSASCIIEncodingString3, new ENameMapFor<XMLASCIITranscoder>(XMLUni::fgUSASCIIEncodingString3));
    gMappings->put((void*)XMLUni::fgUSASCIIEncodingString4, new ENameMapFor<XMLASCIITranscoder>(XMLUni::fgUSASCIIEncodingString4));


    //
    //  Add in our mappings for UTF-8
    //
    gMappings->put((void*)XMLUni::fgUTF8EncodingString, new ENameMapFor<XMLUTF8Transcoder>(XMLUni::fgUTF8EncodingString));
    gMappings->put((void*)XMLUni::fgUTF8EncodingString2, new ENameMapFor<XMLUTF8Transcoder>(XMLUni::fgUTF8EncodingString2));

    //
    //  Add in our mappings for Latin1
    //
    gMappings->put((void*)XMLUni::fgISO88591EncodingString, new ENameMapFor<XML88591Transcoder>(XMLUni::fgISO88591EncodingString));
    gMappings->put((void*)XMLUni::fgISO88591EncodingString2, new ENameMapFor<XML88591Transcoder>(XMLUni::fgISO88591EncodingString2));
    gMappings->put((void*)XMLUni::fgISO88591EncodingString3, new ENameMapFor<XML88591Transcoder>(XMLUni::fgISO88591EncodingString3));
    gMappings->put((void*)XMLUni::fgISO88591EncodingString4, new ENameMapFor<XML88591Transcoder>(XMLUni::fgISO88591EncodingString4));
    gMappings->put((void*)XMLUni::fgISO88591EncodingString5, new ENameMapFor<XML88591Transcoder>(XMLUni::fgISO88591EncodingString5));
    gMappings->put((void*)XMLUni::fgISO88591EncodingString6, new ENameMapFor<XML88591Transcoder>(XMLUni::fgISO88591EncodingString6));
    gMappings->put((void*)XMLUni::fgISO88591EncodingString7, new ENameMapFor<XML88591Transcoder>(XMLUni::fgISO88591EncodingString7));
    gMappings->put((void*)XMLUni::fgISO88591EncodingString8, new ENameMapFor<XML88591Transcoder>(XMLUni::fgISO88591EncodingString8));

    //
    //  Add in our mappings for UTF-16 and UCS-4, little endian
    //
    bool swapped = false;

    #if defined(ENDIANMODE_BIG)
    swapped = true;
    #endif
    gMappings->put
    (
		(void*)XMLUni::fgUTF16LEncodingString,
        new EEndianNameMapFor<XMLUTF16Transcoder>
        (
            XMLUni::fgUTF16LEncodingString
            , swapped
        )
    );

    gMappings->put
    (
		(void*)XMLUni::fgUTF16LEncodingString2,
        new EEndianNameMapFor<XMLUTF16Transcoder>
        (
            XMLUni::fgUTF16LEncodingString2
            , swapped
        )
    );

    gMappings->put
    (
		(void*)XMLUni::fgUCS4LEncodingString,
        new EEndianNameMapFor<XMLUCS4Transcoder>
        (
            XMLUni::fgUCS4LEncodingString
            , swapped
        )
    );

    gMappings->put
    (
		(void*)XMLUni::fgUCS4LEncodingString2,
        new EEndianNameMapFor<XMLUCS4Transcoder>
        (
            XMLUni::fgUCS4LEncodingString2
            , swapped
        )
    );

    //
    //  Add in our mappings for UTF-16 and UCS-4, big endian
    //
    swapped = false;
    #if defined(ENDIANMODE_LITTLE)
    swapped = true;
    #endif
    gMappings->put
    (
		(void*)XMLUni::fgUTF16BEncodingString,
        new EEndianNameMapFor<XMLUTF16Transcoder>
        (
            XMLUni::fgUTF16BEncodingString
            , swapped
        )
    );

    gMappings->put
    (
		(void*)XMLUni::fgUTF16BEncodingString2,
        new EEndianNameMapFor<XMLUTF16Transcoder>
        (
            XMLUni::fgUTF16BEncodingString2
            , swapped
        )
    );

    gMappings->put
    (
		(void*)XMLUni::fgUCS4BEncodingString,
        new EEndianNameMapFor<XMLUCS4Transcoder>
        (
            XMLUni::fgUCS4BEncodingString
            , swapped
        )
    );

    gMappings->put
    (
		(void*)XMLUni::fgUCS4BEncodingString2,
        new EEndianNameMapFor<XMLUCS4Transcoder>
        (
            XMLUni::fgUCS4BEncodingString2
            , swapped
        )
    );

    //
    //  Add in our mappings for UTF-16 and UCS-4 which does not indicate endian
    //  assumes the same endian encoding as the OS
    //

    gMappings->put
    (
		(void*)XMLUni::fgUTF16EncodingString,
        new EEndianNameMapFor<XMLUTF16Transcoder>
        (
            XMLUni::fgUTF16EncodingString
            , false
        )
    );
    gMappings->put
    (
		(void*)XMLUni::fgUTF16EncodingString2,
        new EEndianNameMapFor<XMLUTF16Transcoder>
        (
            XMLUni::fgUTF16EncodingString2
            , false
        )
    );
    gMappings->put
    (
		(void*)XMLUni::fgUTF16EncodingString3,
        new EEndianNameMapFor<XMLUTF16Transcoder>
        (
            XMLUni::fgUTF16EncodingString3
            , false
        )
    );
    gMappings->put
    (
		(void*)XMLUni::fgUTF16EncodingString4,
        new EEndianNameMapFor<XMLUTF16Transcoder>
        (
            XMLUni::fgUTF16EncodingString4
            , false
        )
    );
    gMappings->put
    (
		(void*)XMLUni::fgUCS4EncodingString,
        new EEndianNameMapFor<XMLUCS4Transcoder>
        (
            XMLUni::fgUCS4EncodingString
            , false
        )
    );
    gMappings->put
    (
		(void*)XMLUni::fgUCS4EncodingString2,
        new EEndianNameMapFor<XMLUCS4Transcoder>
        (
            XMLUni::fgUCS4EncodingString2
            , false
        )
    );
    gMappings->put
    (
		(void*)XMLUni::fgUCS4EncodingString3,
        new EEndianNameMapFor<XMLUCS4Transcoder>
        (
            XMLUni::fgUCS4EncodingString3
            , false
        )
    );

    //
    //  Add in our mappings for IBM037, and the one alias we support for
    //  it, which is EBCDIC-CP-US.
    //
    gMappings->put((void*)XMLUni::fgIBM037EncodingString, new ENameMapFor<XMLEBCDICTranscoder>(XMLUni::fgIBM037EncodingString));
    gMappings->put((void*)XMLUni::fgIBM037EncodingString2, new ENameMapFor<XMLEBCDICTranscoder>(XMLUni::fgIBM037EncodingString2));

    //
    //  Add in our mappings for IBM037 with Euro update, i.e. IBM1140. It
    //  has no aliases
    //
    gMappings->put((void*)XMLUni::fgIBM1140EncodingString, new ENameMapFor<XMLIBM1140Transcoder>(XMLUni::fgIBM1140EncodingString));

    //
    //  Add in our mappings for Windows-1252. We don't have any aliases for
    //  this one, so there is just one mapping.
    //
    gMappings->put((void*)XMLUni::fgWin1252EncodingString, new ENameMapFor<XMLWin1252Transcoder>(XMLUni::fgWin1252EncodingString));

}
