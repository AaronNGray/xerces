/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2001 The Apache Software Foundation.  All rights
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
 * originally based on software copyright (c) 2001, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Id$
 */

// ---------------------------------------------------------------------------
//  This program tests the XMLPlatformUtils::Initialize/Terminate() pair
//  by calling the pair a number of times.
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/sax/SAXException.hpp>
#include <xercesc/sax/SAXParseException.hpp>

#include <xercesc/parsers/DOMParser.hpp>
#include <xercesc/parsers/IDOMParser.hpp>
#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>

#include <xercesc/dom/DOM_DOMException.hpp>
#include <xercesc/idom/IDOM_DOMException.hpp>
#include "InitTermTest.hpp"

#include <string.h>
#include <stdlib.h>
#include <fstream.h>
#include <limits.h>


// ---------------------------------------------------------------------------
//  Local Enum to switch theState
// ---------------------------------------------------------------------------
enum Teststate {
    Once,
    Multiple,
    UnEven,
    Limit,
    ExceedLimit
};

// ---------------------------------------------------------------------------
//  Declare functions
// ---------------------------------------------------------------------------
int TestInit4DOM(const char* xmlFile, bool gDoNamespaces, bool gDoSchema, bool gSchemaFullChecking, Teststate theState);
int TestInit4DOM(const char* xmlFile, bool gDoNamespaces, bool gDoSchema, bool gSchemaFullChecking, Teststate theState);
int TestInit4SAX(const char* xmlFile, bool gDoNamespaces, bool gDoSchema, bool gSchemaFullChecking, Teststate theState);
int TestInit4SAX2(const char* xmlFile, bool gDoNamespaces, bool gDoSchema, bool gSchemaFullChecking, Teststate theState);

// ---------------------------------------------------------------------------
//  Define macro
// ---------------------------------------------------------------------------
#define TESTINITPRE                                               \
    long times = 1;                                               \
    switch (theState) {                                           \
        case Multiple:                                            \
        case UnEven:                                              \
            times = 100;                                           \
            break;                                                \
        case Limit:                                               \
        case ExceedLimit:                                         \
            times = LONG_MAX;                                     \
            break;                                                \
        case Once:                                                \
        default:                                                  \
            times = 1;                                            \
    }                                                             \
    long i = 0;                                                   \
    for (i = 0; i < times; i++) {                                 \
        try                                                       \
        {                                                         \
            XMLPlatformUtils::Initialize();                       \
        }                                                         \
                                                                  \
        catch (const XMLException& toCatch)                       \
        {                                                         \
             cerr << "Error during initialization! :\n"           \
                  << StrX(toCatch.getMessage()) << endl;          \
             return 1;                                            \
        }                                                         \
    }                                                             \
                                                                  \
    if (theState == ExceedLimit) {                                \
        try                                                       \
        {                                                         \
            XMLPlatformUtils::Initialize();                       \
        }                                                         \
                                                                  \
        catch (const XMLException& toCatch)                       \
        {                                                         \
             cerr << "Error during initialization! :\n"           \
                  << StrX(toCatch.getMessage()) << endl;          \
             return 1;                                            \
        }                                                         \
    }


#define TESTINITPOST                                              \
    InitTermTestErrorHandler errorHandler;                        \
    parser->setErrorHandler(&errorHandler);                       \
    bool   errorOccurred = false;                                 \
                                                                  \
    errorHandler.resetErrors();                                   \
                                                                  \
    try                                                           \
    {                                                             \
        parser->parse(xmlFile);                                   \
    }                                                             \
                                                                  \
    catch (const XMLException& toCatch)                           \
    {                                                             \
        cerr << "\nError during parsing: '" << xmlFile << "'\n"   \
             << "Exception message is:  \n"                       \
             << StrX(toCatch.getMessage()) << "\n" << endl;       \
        errorOccurred = true;                                     \
    }                                                             \
    catch (const DOM_DOMException& toCatch)                       \
    {                                                             \
        cerr << "\nDOM Error during parsing: '" << xmlFile        \
             << "\nDOMException code is:  \n"                     \
             << toCatch.code << "\n" << endl;                     \
        errorOccurred = true;                                     \
    }                                                             \
    catch (...)                                                   \
    {                                                             \
        cerr << "\nUnexpected exception during parsing: '"        \
        << xmlFile << "'\n";                                      \
        errorOccurred = true;                                     \
    }                                                             \
                                                                  \
    if (errorHandler.getSawErrors())                              \
    {                                                             \
        cout << "\nErrors occurred, no output available\n" << endl;\
        errorOccurred = true;                                     \
    }                                                             \
                                                                  \
    delete parser;                                                \
                                                                  \
    for (i = 0; i < times; i++) {                                 \
        XMLPlatformUtils::Terminate();                            \
    }                                                             \
                                                                  \
    if (theState == ExceedLimit || theState == UnEven) {          \
        XMLPlatformUtils::Terminate();                            \
    }                                                             \
                                                                  \
    if (errorOccurred)                                            \
        return 4;                                                 \
    else                                                          \
        return 0;

// ---------------------------------------------------------------------------
//  DOM Parser
// ---------------------------------------------------------------------------
int TestInit4DOM(const char* xmlFile, bool gDoNamespaces, bool gDoSchema, bool gSchemaFullChecking, Teststate theState)
{
    TESTINITPRE;
    DOMParser* parser = new DOMParser;
    parser->setDoNamespaces(gDoNamespaces);
    parser->setDoSchema(gDoSchema);
    parser->setValidationSchemaFullChecking(gSchemaFullChecking);
    TESTINITPOST;
}

// ---------------------------------------------------------------------------
//  IDOM Parser
// ---------------------------------------------------------------------------
int TestInit4IDOM(const char* xmlFile, bool gDoNamespaces, bool gDoSchema, bool gSchemaFullChecking, Teststate theState)
{
    TESTINITPRE;
    IDOMParser* parser = new IDOMParser;
    parser->setDoNamespaces(gDoNamespaces);
    parser->setDoSchema(gDoSchema);
    parser->setValidationSchemaFullChecking(gSchemaFullChecking);
    TESTINITPOST;
}

// ---------------------------------------------------------------------------
//  SAX Parser
// ---------------------------------------------------------------------------
int TestInit4SAX(const char* xmlFile, bool gDoNamespaces, bool gDoSchema, bool gSchemaFullChecking, Teststate theState)
{
    TESTINITPRE;
    SAXParser* parser = new SAXParser;
    parser->setDoNamespaces(gDoNamespaces);
    parser->setDoSchema(gDoSchema);
    parser->setValidationSchemaFullChecking(gSchemaFullChecking);
    TESTINITPOST;
}

// ---------------------------------------------------------------------------
//  SAX2 XML Reader
// ---------------------------------------------------------------------------
int TestInit4SAX2(const char* xmlFile, bool gDoNamespaces, bool gDoSchema, bool gSchemaFullChecking, Teststate theState)
{
    TESTINITPRE;
    SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();

    XMLCh* doNamespaceFeature = XMLString::transcode("http://xml.org/sax/features/namespaces");
    parser->setFeature(doNamespaceFeature, gDoNamespaces);

    XMLCh* doSchemaFeature = XMLString::transcode("http://apache.org/xml/features/validation/schema");
    parser->setFeature(doSchemaFeature, gDoSchema);

    XMLCh* fullSchemaCheckFeature = XMLString::transcode("http://apache.org/xml/features/validation/schema-full-checking");
    parser->setFeature(fullSchemaCheckFeature, gSchemaFullChecking);

    delete [] doNamespaceFeature;
    delete [] doSchemaFeature;
    delete [] fullSchemaCheckFeature;

    TESTINITPOST;
}

// ---------------------------------------------------------------------------
//
//  Usage()
//
// ---------------------------------------------------------------------------
void usage()
{
    cout << "\nUsage:\n"
            "    InitTermTest [options] <XML file>\n\n"
            "This program tests the XMLPlatformUtils::Initialize()/Terminate()\n"
            "pair by calling it a number of times.  All four parsers\n"
            "(DOMParser, IDOMParser, SAXParser and SAX2XMLReader) are invoked\n"
            "to parse the specified XML file.\n\n"
            "Options:\n"
            "    -n          Enable namespace processing. Default is off.\n"
            "    -s          Enable schema processing. Default is off.\n"
            "    -f          Enable full schema constraint checking. Defaults to off.\n"
		      "    -?          Show this help.\n"
          <<  endl;
}

// ---------------------------------------------------------------------------
//  Main
// ---------------------------------------------------------------------------
int main(int argC, char* argV[]) {

    // ---------------------------------------------------------------------------
    //  Local data
    //
    //  gDoNamespaces
    //      Indicates whether namespace processing should be done.
    //
    //  gDoSchema
    //      Indicates whether schema processing should be done.
    //
    //  gSchemaFullChecking
    //      Indicates whether full schema constraint checking should be done.
    //
    // ---------------------------------------------------------------------------
    bool gDoNamespaces          = false;
    bool gDoSchema              = false;
    bool gSchemaFullChecking    = false;

    // Check command line and extract arguments.
    if (argC < 2)
    {
        usage();
        return 1;
    }

    // See if non validating dom parser configuration is requested.
    int parmInd;
    for (parmInd = 1; parmInd < argC; parmInd++)
    {
        // Break out on first parm not starting with a dash
        if (argV[parmInd][0] != '-')
            break;

        // Watch for special case help request
        if (!strcmp(argV[parmInd], "-?"))
        {
            usage();
            return 2;
        }
         else if (!strcmp(argV[parmInd], "-n")
              ||  !strcmp(argV[parmInd], "-N"))
        {
            gDoNamespaces = true;
        }
         else if (!strcmp(argV[parmInd], "-s")
              ||  !strcmp(argV[parmInd], "-S"))
        {
            gDoSchema = true;
        }
         else if (!strcmp(argV[parmInd], "-f")
              ||  !strcmp(argV[parmInd], "-F"))
        {
            gSchemaFullChecking = true;
        }
         else
        {
            cerr << "Unknown option '" << argV[parmInd]
                 << "', ignoring it.\n" << endl;
        }
    }

    //
    //  And now we have to have only one parameter left and it must be
    //  the file name.
    //
    if (parmInd + 1 != argC)
    {
        usage();
        return 1;
    }

    char* xmlFile = argV[parmInd];
    bool error = false;

    //
    // Calling Init/Term pair a number of times
    //
    unsigned int i = 0;
    for (i=0; i < 100; i++) {
        if (error) {
            cout << "Test Failed" << endl;
            return 4;
        }

        if (TestInit4DOM(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Once))
            error = true;
        if (TestInit4IDOM(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Once))
            error = true;
        if (TestInit4SAX(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Once))
            error = true;
        if (TestInit4SAX2(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Once))
            error = true;
    }

    if (error || TestInit4DOM(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Multiple))
        error = true;
    if (error || TestInit4IDOM(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Multiple))
        error = true;
    if (error || TestInit4SAX(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Multiple))
        error = true;
    if (error || TestInit4SAX2(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Multiple))
        error = true;
/*
 * The following Limit test is a stress test that can run a long time
 * Commented out for regular sanity test
 */
/*
    if (error || TestInit4DOM(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Limit))
        error = true;
    if (error || TestInit4IDOM(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Limit))
        error = true;
    if (error || TestInit4SAX(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Limit))
        error = true;
    if (error || TestInit4SAX2(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, Limit))
        error = true;

    if (error || TestInit4DOM(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, ExceedLimit))
        error = true;
    if (error || TestInit4IDOM(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, ExceedLimit))
        error = true;
    if (error || TestInit4SAX(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, ExceedLimit))
        error = true;
    if (error || TestInit4SAX2(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, ExceedLimit))
        error = true;
*/

    if (error || TestInit4DOM(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, UnEven))
        error = true;
    if (error || TestInit4IDOM(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, UnEven))
        error = true;
    if (error || TestInit4SAX(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, UnEven))
        error = true;
    if (error || TestInit4SAX2(xmlFile, gDoNamespaces, gDoSchema, gSchemaFullChecking, UnEven))
        error = true;

    if (error) {
        cout << "Test Failed" << endl;
        return 4;
    }

    cout << "Test Run Successfully" << endl;
    return 0;
}

// ---------------------------------------------------------------------------
//  InitTermTestErrorHandler
// ---------------------------------------------------------------------------
InitTermTestErrorHandler::InitTermTestErrorHandler() :

    fSawErrors(false)
{
}

InitTermTestErrorHandler::~InitTermTestErrorHandler()
{
}

void InitTermTestErrorHandler::error(const SAXParseException& e)
{
    fSawErrors = true;
    cerr << "\nError at file " << StrX(e.getSystemId())
         << ", line " << e.getLineNumber()
         << ", char " << e.getColumnNumber()
         << "\n  Message: " << StrX(e.getMessage()) << endl;
}

void InitTermTestErrorHandler::fatalError(const SAXParseException& e)
{
    fSawErrors = true;
    cerr << "\nFatal Error at file " << StrX(e.getSystemId())
         << ", line " << e.getLineNumber()
         << ", char " << e.getColumnNumber()
         << "\n  Message: " << StrX(e.getMessage()) << endl;
}

void InitTermTestErrorHandler::warning(const SAXParseException& e)
{
    cerr << "\nWarning at file " << StrX(e.getSystemId())
         << ", line " << e.getLineNumber()
         << ", char " << e.getColumnNumber()
         << "\n  Message: " << StrX(e.getMessage()) << endl;
}

void InitTermTestErrorHandler::resetErrors()
{
    fSawErrors = false;
}
