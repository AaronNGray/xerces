/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Id$
 */

#if !defined(XSERIALIZER_HANDLER_HPP)
#define XSERIALIZER_HANDLER_HPP

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>

XERCES_CPP_NAMESPACE_USE

class XSerializerHandlers : public DefaultHandler
{
public:
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    XSerializerHandlers();
    ~XSerializerHandlers();


    // -----------------------------------------------------------------------
    //  Getter methods
    // -----------------------------------------------------------------------
    unsigned int getElementCount() const
    {
        return fElementCount;
    }

    unsigned int getAttrCount() const
    {
        return fAttrCount;
    }

    XMLSize_t getCharacterCount() const
    {
        return fCharacterCount;
    }

    bool getSawErrors() const
    {
        return fSawErrors;
    }

    XMLSize_t getSpaceCount() const
    {
        return fSpaceCount;
    }


    // -----------------------------------------------------------------------
    //  Handlers for the SAX ContentHandler interface
    // -----------------------------------------------------------------------
    void startElement(const XMLCh* const uri, const XMLCh* const localname, const XMLCh* const qname, const Attributes& attrs);
    void characters(const XMLCh* const chars, const XMLSize_t length);
    void ignorableWhitespace(const XMLCh* const chars, const XMLSize_t length);
    void resetDocument();


    // -----------------------------------------------------------------------
    //  Handlers for the SAX ErrorHandler interface
    // -----------------------------------------------------------------------
	void warning(const SAXParseException& exc);
    void error(const SAXParseException& exc);
    void fatalError(const SAXParseException& exc);
    void resetErrors();


private:
    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fAttrCount
    //  fCharacterCount
    //  fElementCount
    //  fSpaceCount
    //      These are just counters that are run upwards based on the input
    //      from the document handlers.
    //
    //  fSawErrors
    //      This is set by the error handlers, and is queryable later to
    //      see if any errors occured.
    // -----------------------------------------------------------------------
    unsigned int    fAttrCount;
    XMLSize_t       fCharacterCount;
    unsigned int    fElementCount;
    XMLSize_t       fSpaceCount;
    bool            fSawErrors;
};

#endif
