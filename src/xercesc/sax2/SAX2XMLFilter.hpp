/*
 * Copyright 1999-2001,2004 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
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
 * $Log$
 * Revision 1.1  2004/12/24 19:21:46  amassari
 * Add support for SAX2 filters (jira# 1133)
 *
 */

#ifndef SAX2XMLFilter_HPP
#define SAX2XMLFilter_HPP

#include <xercesc/sax2/SAX2XMLReader.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class SAX2_EXPORT SAX2XMLFilter : public SAX2XMLReader
{
public:
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    /** @name Constructors and Destructor */
    //@{
    /** The default constructor */
    SAX2XMLFilter()
    {
    }
    /** The destructor */
    virtual ~SAX2XMLFilter()
    {
    }
    //@}

    //-----------------------------------------------------------------------
    // The XMLFilter interface
    //-----------------------------------------------------------------------
    /** @name Implementation of SAX 2.0 XMLFilter interface's. */
    //@{

    /**
      * This method returns the parent XMLReader object.
      *
      * @return A pointer to the parent XMLReader object.
      */
    virtual SAX2XMLReader* getParent() const = 0 ;

    /**
      * Sets the parent XMLReader object; parse requests will be forwarded to this
      * object, and callback notifications coming from it will be postprocessed
      *
      * @param parent The new XMLReader parent.
      * @see SAX2XMLReader#SAX2XMLReader
      */
    virtual void setParent(SAX2XMLReader* parent) = 0;

    //@}

private :
    /* The copy constructor, you cannot call this directly */
    SAX2XMLFilter(const SAX2XMLFilter&);

    /* The assignment operator, you cannot call this directly */
    SAX2XMLFilter& operator=(const SAX2XMLFilter&);

};

XERCES_CPP_NAMESPACE_END

#endif
