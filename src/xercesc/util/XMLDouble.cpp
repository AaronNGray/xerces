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
 * $Log$
 * Revision 1.6  2003/01/30 19:14:43  tng
 * On some platforms like Solaris strtod will return -0.0.   So need to consider this scenario as well.
 *
 * Revision 1.5  2002/12/11 00:20:02  peiyongz
 * Doing businesss in value space. Converting out-of-bound value into special values.
 *
 * Revision 1.4  2002/11/04 15:22:05  tng
 * C++ Namespace Support.
 *
 * Revision 1.3  2002/09/24 19:51:24  tng
 * Performance: use XMLString::equals instead of XMLString::compareString
 *
 * Revision 1.2  2002/05/03 16:05:45  peiyongz
 * Bug 7341: Missing newline at end of util and DOM source files,
 * patch from Martin Kalen.
 *
 * Revision 1.1.1.1  2002/02/01 22:22:15  peiyongz
 * sane_include
 *
 * Revision 1.16  2001/11/19 21:33:42  peiyongz
 * Reorganization: Double/Float
 *
 * Revision 1.15  2001/11/19 17:27:55  peiyongz
 * Boundary Values updated
 *
 * Revision 1.14  2001/10/26 16:37:46  peiyongz
 * Add thread safe code
 *
 * Revision 1.12  2001/09/20 13:11:41  knoaman
 * Regx  + misc. fixes
 *
 * Revision 1.11  2001/09/14 13:57:59  peiyongz
 * exponent is a must if 'E' or 'e' is present.
 *
 * Revision 1.10  2001/08/23 11:54:26  tng
 * Add newline at the end and various typo fixes.
 *
 * Revision 1.9  2001/08/21 15:10:15  peiyongz
 * Bugzilla# 3017: MSVC5.0: C2202: 'compareSpecial' : not all
 * control paths return a value
 *
 * Revision 1.8  2001/08/14 22:10:20  peiyongz
 * new exception message added
 *
 * Revision 1.7  2001/07/31 17:38:16  peiyongz
 * Fix: memory leak by static (boundry) objects
 *
 * Revision 1.6  2001/07/31 13:48:29  peiyongz
 * fValue removed
 *
 * Revision 1.5  2001/07/27 20:43:53  peiyongz
 * copy ctor: to check for special types.
 *
 * Revision 1.4  2001/07/26 18:21:15  peiyongz
 * Boundary Checking
 *
 * Revision 1.3  2001/07/25 19:06:56  peiyongz
 * Fix to Linux compilation error: XMLDouble::LiteralType' is not an aggregate type
 *
 * Revision 1.2  2001/07/24 21:52:27  peiyongz
 * XMLDouble: move fg...String to XMLUni
 *
 * Revision 1.1  2001/07/24 13:58:11  peiyongz
 * XMLDouble and related supporting methods from XMLBigInteger/XMLBigDecimal
 *
 */

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/util/XMLDouble.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/NumberFormatException.hpp>
#include <xercesc/util/Janitor.hpp>

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>

XERCES_CPP_NAMESPACE_BEGIN

// ---------------------------------------------------------------------------
//  ctor/dtor
// ---------------------------------------------------------------------------
XMLDouble::XMLDouble(const XMLCh* const strValue)
:XMLAbstractDoubleFloat()
{
    init(strValue);
}

XMLDouble::~XMLDouble()
{
}

void XMLDouble::checkBoundary(const XMLCh* const strValue)
{
    char *nptr = XMLString::transcode(strValue);
    ArrayJanitor<char> jan1(nptr);
    int   strLen = strlen(nptr);
    char *endptr = 0;
    errno = 0;
    fValue = strtod(nptr, &endptr);

    // check if all chars are valid char
    if ( (endptr - nptr) != strLen)
    {
        ThrowXML(NumberFormatException, XMLExcepts::XMLNUM_Inv_chars);
    }

    // check if overflow/underflow occurs
    if (errno == ERANGE)
    {
        if ( fValue < 0 )
        {
            if (fValue > (-1)*DBL_MIN)
            {
                fType = NegZero;
                fValue = 0;
            }
            else
            {
                fType = NegINF;
            }
        }
        else if ( fValue > 0)
        {
            if (fValue < DBL_MIN )
            {
                fType = PosZero;
                fValue = 0;
            }
            else
            {
                fType = PosINF;
            }
        }
        else
        {
            fType = (getSign() == 1) ? PosZero : NegZero;
        }

    }

}

XERCES_CPP_NAMESPACE_END
