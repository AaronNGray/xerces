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
 * $Log$
 * Revision 1.2  2001/05/11 13:25:50  tng
 * Copyright update.
 *
 * Revision 1.1.1.1  2001/04/03 00:14:29  andyh
 * IDOM
 *
 */

#ifndef IDOMException_HEADER_GUARD_
#define IDOMException_HEADER_GUARD_

#include <util/XercesDefs.hpp>

/**
  * Encapsulate a general DOM error or warning.
  *
  * <p> The DOM will create and throw an instance of DOMException
  * when an error condition is detected.  Exceptions can occur
  * when an application directly manipulates the DOM document
  * tree that is produced by the parser, or when a document tree
  * is created from scratch using the DOM API.  DOM exceptions will
  * not be generated by the parser while constructing a document
  * tree from an XML source document.
  *
  * <p>Unlike the other classes in the C++ DOM API, DOM_DOMException
  * is NOT a reference to an underlying implementation class, and
  * does not provide automatic memory management.  Code that catches
  * a DOM exception is responsible for deleting it, or otherwise
  * arranging for its disposal.
  *
  */
class CDOM_EXPORT IDOM_DOMException  {
public:
    /** @name Enumerators for DOM Exceptions */
    //@{
        enum ExceptionCode {
                INDEX_SIZE_ERR       = 1,
                DOMSTRING_SIZE_ERR   = 2,
                HIERARCHY_REQUEST_ERR = 3,
                WRONG_DOCUMENT_ERR   = 4,
                INVALID_CHARACTER_ERR = 5,
                NO_DATA_ALLOWED_ERR  = 6,
                NO_MODIFICATION_ALLOWED_ERR = 7,
                NOT_FOUND_ERR        = 8,
                NOT_SUPPORTED_ERR    = 9,
                INUSE_ATTRIBUTE_ERR  = 10,
                INVALID_STATE_ERR    = 11,
	       	SYNTAX_ERR	     = 12,
        	INVALID_MODIFICATION_ERR    = 13,
        	NAMESPACE_ERR	     = 14,
        	INVALID_ACCESS_ERR   = 15
        };
    //@}
public:
    /** @name Constructors and assignment operator */
    //@{
    /**
      * Default constructor for IDOM_DOMException.
      *
      */
    IDOM_DOMException();

    /**
      * Constructor which takes an error code and a message.
      *
      * @param code The error code which indicates the exception
      * @param message The string containing the error message
      */
    IDOM_DOMException(short code, const XMLCh *message);

    /**
      * Copy constructor.
      *
      * @param other The object to be copied.
      */
    IDOM_DOMException(const IDOM_DOMException &other);

    //@}
    /** @name Destructor. */
    //@{
	 /**
	  * Destructor for IDOM_DOMException.  Applications are responsible
      * for deleting DOM_Exception objects that they catch after they
      * have completed their exception processing.
	  *
	  */
    virtual ~IDOM_DOMException();
    //@}

    /** @name Public variables. */
     //@{
	 /**
	  * A code value, from the set defined by the ExceptionCode enum,
      * indicating the type of error that occured.
	  */
   ExceptionCode   code;

	 /**
	  * A string value.  Applications may use this field to hold an error
      *  message.  The field value is not set by the DOM implementation,
      *  meaning that the string will be empty when an exception is first
      *  thrown.
	  */
    const XMLCh *msg;
    //@}

};

#endif

