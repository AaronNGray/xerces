/*
 * The Apache Software License, Version 1.1
 * 
 * Copyright (c) 2002 The Apache Software Foundation.  All rights
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
 * $Log$
 * Revision 1.1  2002/05/23 15:47:24  knoaman
 * DOM L3 core - support for DOMError, DOMErrorHandler and DOMLocator
 *
 */


#ifndef DOMERRORHANDLER_HPP
#define DOMERRORHANDLER_HPP

#include <xercesc/util/XercesDefs.hpp>

class DOMError;


/**
  * Basic interface for DOM error handlers.
  *
  * <p>DOMErrorHandler is a callback interface that the DOM implementation
  * can call when reporting errors that happens while processing XML data, or
  * when doing some other processing (e.g. validating a document).</p>
  *
  * <p>The application that is using the DOM implementation is expected to
  * implement this interface.</p>
  *
  * @see DOMBuilder#setErrorHandler
  */

class CDOM_EXPORT DOMErrorHandler
{
protected:
    /** @name Constructors */
    //@{

    /** Default constructor */
    DOMErrorHandler() {};

    //@}

public:
    /** @name Destructor */
    //@{

    /** Desctructor */
    virtual ~DOMErrorHandler()
    {
    }

    //@}

    /** @name The error handler interface */
    //@{
   /**
    * This method is called on the error handler when an error occures.
    *
    * @param domError The error object that describes the error, this object
    *                 may be reused by the DOM implementation across multiple
    *                 calls to the handleEvent method.
    * @return If the handleError method returns <code>true</code> the DOM
    *         implementation should continue as if the error didn't happen
    *         when possible, if the method returns <code>false</code> then the
    *         DOM implementation should stop the current processing when
    *         possible.
    */
    virtual bool handleError(const DOMError& domError) = 0;

   /**
    * Reset the Error handler object on its reuse
    *
    * <p>This method helps in reseting the Error handler object
    * implementational defaults each time the Error handler is begun.</p>
    *
    */
    virtual void resetErrors() = 0;

    //@}

private :
    /* Unimplemented constructors and operators */
    
    /* Copy constructor */
    DOMErrorHandler(const DOMErrorHandler&);

    /* Assignment operator */
    void operator=(const DOMErrorHandler&);
    
};

#endif
