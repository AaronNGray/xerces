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



/**
 * $Id$
 */


/** This IRangeTest tests all of the cases delineated as examples
 *  in the DOM Level 2 Range specification, and a few others.
 *  <p>These do not by any means completely test the API and
 *  corner cases.
 */

#include <stdio.h>
#include <idom/IDOM.hpp>
#include <util/PlatformUtils.hpp>
#include <util/XMLException.hpp>
#include <util/XMLString.hpp>
#include <util/XMLUni.hpp>
#include <util/XMLUniDefs.hpp>
#include <idom/IDOM_range.hpp>
#include <idom/IDOM_XMLDecl.hpp>


#define TASSERT(c) tassert((c), __FILE__, __LINE__)

void tassert(bool c, char *file, int line)
{
    if (!c)
        printf("Failure.  Line %d,   file %s\n", line, file);
};


#define EXCEPTION_TEST(operation, expected_exception)               \
{                                                                   \
    try {                                                           \
    operation;                                                      \
    printf(" Error: no exception thrown at line %d\n", __LINE__);   \
}                                                                   \
    catch (IDOM_DOMException &e) {                                       \
    if (e.code != expected_exception)                       \
    printf(" Wrong exception code: %d at line %d\n", e.code, __LINE__); \
}                                                                 \
    catch (...)   {                                                 \
    printf(" Wrong exception thrown at line %d\n", __LINE__);       \
}                                                                   \
}
//Define a bunch of XMLCh* string for comparison
XMLCh xa[] = {chLatin_a, chNull};
XMLCh xab[] = {chLatin_a, chLatin_b, chNull};
XMLCh xabHello[] = {chLatin_a, chLatin_b, chLatin_H, chLatin_e, chLatin_l, chLatin_l, chLatin_o, chNull};
XMLCh xabHellocd[] = {chLatin_a, chLatin_b, chLatin_H, chLatin_e, chLatin_l, chLatin_l, chLatin_o, chSpace, chLatin_c, chLatin_d, chNull};
XMLCh xAnotherText[] = {chLatin_A, chLatin_n, chLatin_o, chLatin_t, chLatin_h, chLatin_e, chLatin_r,
     chLatin_T, chLatin_e, chLatin_x, chLatin_t, chNull};
XMLCh xb[] = {chLatin_b, chNull};
XMLCh xBlahxyz[] = {chLatin_B, chLatin_l, chLatin_a, chLatin_h, chSpace,
     chLatin_x, chLatin_y, chLatin_z, chNull};
XMLCh xBody[] = {chLatin_B, chLatin_o, chLatin_d, chLatin_y, chNull};
XMLCh xbody2[] = {chLatin_b, chLatin_o, chLatin_d, chLatin_y, chDigit_2, chNull};
XMLCh xc[] = {chLatin_c, chNull};
XMLCh xcool[] = {chLatin_c, chLatin_o, chLatin_o, chLatin_l, chNull};
XMLCh xef[] = {chLatin_e, chLatin_f, chNull};
XMLCh xElement1[] = {chLatin_E, chLatin_l, chLatin_e, chLatin_m, chLatin_e, chLatin_n, chLatin_t, chDigit_1, chNull};
XMLCh xElement2[] = {chLatin_E, chLatin_l, chLatin_e, chLatin_m, chLatin_e, chLatin_n, chLatin_t, chDigit_2, chNull};
XMLCh xElement3[] = {chLatin_E, chLatin_l, chLatin_e, chLatin_m, chLatin_e, chLatin_n, chLatin_t, chDigit_3, chNull};
XMLCh xell[] = {chLatin_e, chLatin_l, chLatin_l, chNull};
XMLCh xellocd[] = {chLatin_e, chLatin_l, chLatin_l, chLatin_o, chSpace, chLatin_c, chLatin_d, chNull};
XMLCh xellocdef[] = {chLatin_e, chLatin_l, chLatin_l, chLatin_o, chSpace, chLatin_c, chLatin_d, chLatin_e, chLatin_f, chNull};
XMLCh xeplacedTextInsertedTexttle[] = {chLatin_e, chLatin_p, chLatin_l, chLatin_a, chLatin_c, chLatin_e, chLatin_d,
     chLatin_T, chLatin_e, chLatin_x, chLatin_t, chLatin_I, chLatin_n, chLatin_s, chLatin_e, chLatin_r, chLatin_t, chLatin_e, chLatin_d,
     chLatin_T, chLatin_e, chLatin_x, chLatin_t, chLatin_t, chLatin_l, chLatin_e, chNull};
XMLCh xex[] = {chLatin_e, chLatin_x, chNull};
XMLCh xext1[] = {chLatin_e, chLatin_x, chLatin_t, chDigit_1, chNull};
XMLCh xext3[] = {chLatin_e, chLatin_x, chLatin_t, chDigit_3, chNull};
XMLCh xfoo[] = {chLatin_f, chLatin_o, chLatin_o, chNull};
XMLCh xH1[] = {chLatin_H, chDigit_1, chNull};
XMLCh xh2[] = {chLatin_h, chDigit_2, chNull};
XMLCh xh3[] = {chLatin_h, chDigit_3, chNull};
XMLCh xh4[] = {chLatin_h, chDigit_4, chNull};
XMLCh xHellocd[] = {chLatin_H, chLatin_e, chLatin_l, chLatin_l, chLatin_o, chSpace, chLatin_c, chLatin_d, chNull};
XMLCh xhead[] = {chLatin_h, chLatin_e, chLatin_a, chLatin_d, chNull};
XMLCh xhead2[] = {chLatin_h, chLatin_e, chLatin_a, chLatin_d, chDigit_2, chNull};
XMLCh xInsertedText[] = {chLatin_I, chLatin_n, chLatin_s, chLatin_e, chLatin_r, chLatin_t, chLatin_e, chLatin_d,
     chLatin_T, chLatin_e, chLatin_x, chLatin_t, chNull};
XMLCh xInsertedTexttle[] = {chLatin_I, chLatin_n, chLatin_s, chLatin_e, chLatin_r, chLatin_t, chLatin_e, chLatin_d,
     chLatin_T, chLatin_e, chLatin_x, chLatin_t, chLatin_t, chLatin_l, chLatin_e, chNull};
XMLCh xmoo[] = {chLatin_m, chLatin_o, chLatin_o, chNull};
XMLCh xroot[] = {chLatin_r, chLatin_o, chLatin_o, chLatin_t, chNull};
XMLCh xroot2[] = {chLatin_r, chLatin_o, chLatin_o, chLatin_t, chDigit_2, chNull};
XMLCh xP[] = {chLatin_P, chNull};
XMLCh xp1[] = {chLatin_p, chDigit_1, chNull};
XMLCh xp2[] = {chLatin_p, chDigit_2, chNull};
XMLCh xptext2[] = {chLatin_p, chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_2, chNull};
XMLCh xReplacedText[] = {chLatin_R, chLatin_e, chLatin_p, chLatin_l, chLatin_a, chLatin_c, chLatin_e, chLatin_d,
     chLatin_T, chLatin_e, chLatin_x, chLatin_t, chNull};
XMLCh xSurroundNode1[] = {chLatin_S, chLatin_u, chLatin_r, chLatin_r, chLatin_o, chLatin_u, chLatin_n, chLatin_d,
      chLatin_N, chLatin_o, chLatin_d, chLatin_e, chDigit_1, chNull};
XMLCh xt[] = {chLatin_t, chNull};
XMLCh xtl[] = {chLatin_t, chLatin_l, chNull};
XMLCh xtext1[] = {chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_1, chNull};
XMLCh xtext2[] = {chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_2, chNull};
XMLCh xtext2ex[] = {chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_2, chLatin_e, chLatin_x, chNull};
XMLCh xtext3[] = {chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_3, chNull};
XMLCh xtext4[] = {chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_4, chNull};
XMLCh xtext4ext3[] = {chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_4, chLatin_e, chLatin_x, chLatin_t, chDigit_3, chNull};
XMLCh xttext4ext3[] = {chLatin_t, chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_4, chLatin_e, chLatin_x, chLatin_t, chDigit_3, chNull};
XMLCh xtext5[] = {chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_5, chNull};
XMLCh xtext6[] = {chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_6, chNull};
XMLCh xTi[] = {chLatin_T, chLatin_i, chNull};
XMLCh xTitle[] = {chLatin_T, chLatin_i, chLatin_t, chLatin_l, chLatin_e, chNull};
XMLCh xtle[] = {chLatin_t, chLatin_l, chLatin_e, chNull};
XMLCh xu[] = {chLatin_u, chNull};
XMLCh xupbody[] = {chLatin_u, chLatin_p, chLatin_b, chLatin_o, chLatin_d, chLatin_y, chNull};
XMLCh xupbody2[] = {chLatin_u, chLatin_p, chLatin_b, chLatin_o, chLatin_d, chLatin_y, chDigit_2, chNull};
XMLCh xupp1[] = {chLatin_u, chLatin_p, chLatin_p, chDigit_1, chNull};
XMLCh xuptext1[] = {chLatin_u, chLatin_p, chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_1, chNull};
XMLCh xuptext2[] = {chLatin_u, chLatin_p, chLatin_t, chLatin_e, chLatin_x, chLatin_t, chDigit_2, chNull};


int  main()
{
	try {
		XMLPlatformUtils::Initialize();
	}
	catch (const XMLException& toCatch) {
        char *pMessage = XMLString::transcode(toCatch.getMessage());
        fprintf(stderr, "Error during XMLPlatformUtils::Initialize(). \n"
                        "  Message is: %s\n", pMessage);
        delete [] pMessage;
        return -1;
    }

    /*
    Range tests include testing of

    createRange

    setStart, setStartBefore. setStartAfter,
    setEnd, setEndBefore. setEndAfter
    getStartContainer, getStartOffset
    getEndContainer, getEndOffset
    getCommonAncestorContainer
    selectNode
    selectNodeContents
    insertNode
    deleteContents
    collapse
    getCollapsed
    surroundContents
    compareBoundaryPoints
    cloneRange
    cloneContents
    extractContents
    toString
    detach
    removeChild
    */
    {

        {
            IDOM_DOMImplementation* impl = IDOM_DOMImplementation::getImplementation();
            IDOM_Document* doc = impl->createDocument();

            //Creating a root element
            IDOM_Element*     root = doc->createElement(xBody);
            doc->appendChild(root);

            //Creating the siblings of root
            IDOM_Element*     E11 = doc->createElement(xH1);
            root->appendChild(E11);

            IDOM_Element*     E12 = doc->createElement(xP);
            root->appendChild(E12);

            //Attaching texts to siblings
            IDOM_Text*        textNode1 = doc->createTextNode(xTitle);
            E11->appendChild(textNode1);

            IDOM_Text*        textNode11 = doc->createTextNode(xAnotherText);
            E11->appendChild(textNode11);

            IDOM_Text*        textNode2 = doc->createTextNode(xBlahxyz);
            E12->appendChild(textNode2);

            IDOM_Text*     E210 = doc->createTextNode(xInsertedText);

            delete doc;


        }


        {
            //DOM Tree and some usable node creation
            IDOM_DOMImplementation* impl = IDOM_DOMImplementation::getImplementation();
            IDOM_Document* doc = impl->createDocument();

            //Creating a root element
            IDOM_Element*     root = doc->createElement(xBody);
            doc->appendChild(root);

            //Creating the siblings of root
            IDOM_Element*     E11 = doc->createElement(xH1);
            root->appendChild(E11);

            IDOM_Element*     E12 = doc->createElement(xP);
            root->appendChild(E12);

            //Attaching texts to siblings
            IDOM_Text*        textNode1 = doc->createTextNode(xTitle);
            E11->appendChild(textNode1);

            IDOM_Text*        textNode11 = doc->createTextNode(xAnotherText);
            E11->appendChild(textNode11);

            IDOM_Text*        textNode2 = doc->createTextNode(xBlahxyz);
            E12->appendChild(textNode2);

            //experimental nodes
            IDOM_Element*     E120 = doc->createElement(xElement1);
            IDOM_Element*     E121 = doc->createElement(xElement2);
            IDOM_Element*     E122 = doc->createElement(xElement3);
            IDOM_Element*     E311 = doc->createElement(xSurroundNode1);

            IDOM_Text*     E210 = doc->createTextNode(xInsertedText);

            IDOM_Node* rt = doc->getDocumentElement();
            IDOM_Range* range = doc->createRange();



            //Tests start here
            // Initial dom tree looks like :
            // <Body><H1>TitleAnother Text</H1><P>Blah xyz</P></Body>
            //i.e.,            Body(rt)
            //     _____________|________________
            //     |                           |
            //  ___H1(E11)___                    P(E12)
            //  |           |                    |
            //  "Title"  "Another Text"        "Blah xyz"


            //test for start and end settings of a range
            range->setStart(rt->getFirstChild(), 0);
            TASSERT(range->getStartContainer() == rt->getFirstChild() );
            TASSERT(range->getStartOffset() == 0);

            range->setEnd(rt->getFirstChild(), 1);
            TASSERT(range->getEndContainer() == rt->getFirstChild() );
            TASSERT(range->getEndOffset() == 1);


            //IDOM_Node* node = range->getCommonAncestorContainer();
            TASSERT(range->getCommonAncestorContainer() == rt->getFirstChild());

            //selection related test
            range->selectNode(rt->getLastChild());
            TASSERT(range->getStartContainer() == rt);
            TASSERT(range->getStartOffset() == 1);
            TASSERT(range->getEndContainer() == rt);
            TASSERT(range->getEndOffset() == 2);

            //insertion related tests
            range->insertNode(E120);

            //only end offset moves and new node gets into range as being inserted at boundary point
            TASSERT(range->getStartContainer() == rt);
            TASSERT(range->getStartOffset() == 1);
            TASSERT(range->getEndContainer() == rt);
            TASSERT(range->getEndOffset() == 3);

            range->insertNode(E121);
            //only end offset moves and new node gets into range as being inserted at boundary point
            TASSERT(range->getStartContainer() == rt);
            TASSERT(range->getStartOffset() == 1);
            TASSERT(range->getEndContainer() == rt);
            TASSERT(range->getEndOffset() == 4);

            rt->insertBefore(E122, rt->getFirstChild());
            //both offsets move as new node is not part of the range
            TASSERT(range->getStartContainer() == rt);
            TASSERT(range->getStartOffset() == 2);
            TASSERT(range->getEndContainer() == rt);
            TASSERT(range->getEndOffset() == 5);

            //After above operations, now the tree looks like:
            // <Body><Element3/><H1>TitleAnother Text</H1><Element2/><Element1/><P>Blah xyz</P></Body>
            //i.e.,            Body(rt)
            //     _____________|_______________________________________________________________
            //     |                |                  |                |                      |
            //  Element3(E122)  ___H1(E11)___        Element2(E121)    Element1(E120)          P(E12)
            //                  |           |                                                  |
            //               "Title"  "Another Text"                                        "Blah xyz"
            //
            // range has rt as start and end container, and 2 as start offset, 5 as end offset

            //changing selection
            range->selectNode(rt->getLastChild()->getPreviousSibling());
            TASSERT(range->getStartContainer() == rt);
            TASSERT(range->getStartOffset() == 3);
            TASSERT(range->getEndContainer() == rt);
            TASSERT(range->getEndOffset() == 4);

            //deleting related tests
            range->deleteContents();
            TASSERT(rt->getLastChild()->getPreviousSibling() == E121);

            range->setStart(rt->getFirstChild()->getNextSibling()->getFirstChild(), 2);
            TASSERT(range->getStartContainer() == rt->getFirstChild()->getNextSibling()->getFirstChild());
            TASSERT(!XMLString::compareString(range->getStartContainer()->getNodeValue(),xTitle));
            TASSERT(range->getStartOffset() == 2);

            range->setEnd(rt->getFirstChild()->getNextSibling()->getFirstChild(), 4);
            TASSERT(range->getEndContainer() == rt->getFirstChild()->getNextSibling()->getFirstChild());
            TASSERT(!XMLString::compareString(range->getEndContainer()->getNodeValue(),xTitle));
            TASSERT(range->getEndOffset() == 4);
            TASSERT(!XMLString::compareString(range->toString(),xtl));

            //inserting text between a text node
            range->insertNode(E210);

            //only end offset moves and new node gets into range as being inserted at boundary point
            TASSERT(range->getStartContainer() == rt->getFirstChild()->getNextSibling()->getFirstChild());
            TASSERT(range->getStartOffset() == 2);
            TASSERT(range->getEndContainer() == rt->getFirstChild()->getNextSibling()->getLastChild()->getPreviousSibling());
            TASSERT(range->getEndOffset() == 2);

            //inserting element node before the selected text node
            range->insertNode(E120);
            //only end offset moves and new node gets into range as being inserted at boundary point
            TASSERT(range->getStartContainer() == rt->getFirstChild()->getNextSibling()->getFirstChild());
            TASSERT(!XMLString::compareString(range->getStartContainer()->getNodeValue(),xTi));
            TASSERT(range->getStartOffset() == 2);
            TASSERT(range->getEndContainer() == rt->getFirstChild()->getNextSibling()->getLastChild()->getPreviousSibling());
            TASSERT(!XMLString::compareString(range->getEndContainer()->getNodeValue(),xtle));
            TASSERT(range->getEndOffset() == 2);
            TASSERT(E11->getChildNodes()->getLength()==6);

           //checking the text replacment
            range->getStartContainer()->setNodeValue(xReplacedText);
            //only the start offset is impact
            TASSERT(range->getStartContainer() == rt->getFirstChild()->getNextSibling()->getFirstChild());
            TASSERT(!XMLString::compareString(range->getStartContainer()->getNodeValue(),xReplacedText));
            TASSERT(range->getStartOffset() == 0);
            TASSERT(range->getEndContainer() == rt->getFirstChild()->getNextSibling()->getLastChild()->getPreviousSibling());
            TASSERT(!XMLString::compareString(range->getEndContainer()->getNodeValue(),xtle));
            TASSERT(range->getEndOffset() == 2);

            //After above operations, now the tree looks like:
            // <Body><Element3/><H1>ReplacedText<Element1/>InsertedTexttleAnother Text</H1><Element2/><P>Blah xyz</P></Body>
            //i.e.,            Body(rt)
            //     _____________|_______________________________________________________________________________________________
            //     |                |                                                                          |                |
            //  Element3(E122)  ___H1(E11)___________________________________________________________        Element2(E121)    P(E12)
            //                  |              |     |                |                      |      |                             |
            //               "ReplacedText"   ""   Element1(E120)   "InsertedText"(E210)   "tle"  "Another Text"              "Blah xyz"
            //
            // range has "ReplacedText" as start container and "tle" as end container
            //   and 0 as start offset, 2 as end offset

            //changing the selection. Preparing for 'surround'
            range->setStart(range->getStartContainer()->getParentNode(), 2);
            range->setEnd(range->getStartContainer(), 5);
            TASSERT(!XMLString::compareString(range->getStartContainer()->getNodeName(),xH1));
            TASSERT(!XMLString::compareString(range->getEndContainer()->getNodeName(),xH1));
            TASSERT(!XMLString::compareString(range->toString(),xInsertedTexttle));

            range->surroundContents(E311);
            TASSERT(!XMLString::compareString(range->getStartContainer()->getNodeName(),xH1));
            TASSERT(range->getStartOffset() == 2);
            TASSERT(!XMLString::compareString(range->getEndContainer()->getNodeName(),xH1));
            TASSERT(range->getEndOffset() == 3);
            TASSERT(E11->getChildNodes()->getLength()==4);
            TASSERT(E311->getChildNodes()->getLength()==3);
            TASSERT(!XMLString::compareString(range->toString(),xInsertedTexttle));

            //After above operations, now the tree looks like:
            // <Body><Element3/><H1>ReplacedText<SurroundNode1><Element1/>InsertedTexttle</SurroundNode1>Another Text</H1><Element2/><P>Blah xyz</P></Body>
            //i.e.,            Body(rt)
            //     _____________|_________________________________________________________________________
            //     |                |                                                    |                |
            //  Element3(E122)  ___H1(E11)___________________________________        Element2(E121)    P(E12)
            //                  |              |     |                      |                            |
            //               "ReplacedText"   ""   SurroundNode1(E311)  "Another Text"              "Blah xyz"
            //                          ____________ |_____________________________
            //                          |                    |                    |
            //                          Element1(E120)   "InsertedText"(E210)   "tle"
            //
            // range has H1 as start and end container and 2 as start offset, 3 as end offset

            //testing cloning
            IDOM_Range* aRange = range->cloneRange();

            TASSERT(aRange->getStartContainer() == range->getStartContainer());
            TASSERT(aRange->getEndContainer() == range->getEndContainer());
            TASSERT(aRange->getStartOffset() == 2);
            TASSERT(aRange->getEndOffset() == 3);
            //changing the new ranges start
            aRange->setStart(aRange->getStartContainer()->getFirstChild(), 1);

            //comparing the ranges
            short compVal = range->compareBoundaryPoints(IDOM_Range::END_TO_END, aRange);
            TASSERT(compVal == 0);
            compVal = range->compareBoundaryPoints(IDOM_Range::START_TO_START, aRange);
            TASSERT(compVal == 1);
            compVal = range->compareBoundaryPoints(IDOM_Range::START_TO_END, aRange);
            TASSERT(compVal == 1);
            compVal = range->compareBoundaryPoints(IDOM_Range::END_TO_START, aRange);
            TASSERT(compVal == -1);

            //testing collapse
            //not collapsed
            TASSERT(range->getCollapsed() == false);
            TASSERT(range->getStartOffset() == 2);
            TASSERT(range->getEndOffset() == 3);

            //selectNodeContents
            range->selectNodeContents(rt->getLastChild()->getFirstChild());
            TASSERT(range->getStartContainer() == rt->getLastChild()->getFirstChild());
            TASSERT(range->getEndContainer() == rt->getLastChild()->getFirstChild());
            TASSERT(range->getStartOffset() == 0);
            TASSERT(range->getEndOffset() == 8);
            TASSERT(!XMLString::compareString(range->toString(),xBlahxyz));

            //testing collapse
            range->collapse(true); //collapse to start
            TASSERT(range->getCollapsed() == true);
            TASSERT(range->getStartOffset() == 0);
            TASSERT(range->getEndOffset() == 0);
            TASSERT(!XMLString::compareString(range->toString(),XMLUni::fgZeroLenString));
            TASSERT(aRange->getEndOffset() == 3); //other range is unaffected
            TASSERT(!XMLString::compareString(aRange->toString(),xeplacedTextInsertedTexttle));

            //After above operations, now the tree looks like:
            // <Body><Element3/><H1>ReplacedText<SurroundNode1><Element1/>InsertedTexttle</SurroundNode1>Another Text</H1><Element2/><P>Blah xyz</P></Body>
            //i.e.,            Body(rt)
            //     _____________|_________________________________________________________________________
            //     |                |                                                    |                |
            //  Element3(E122)  ___H1(E11)___________________________________        Element2(E121)    P(E12)
            //                  |              |     |                      |                            |
            //               "ReplacedText"   ""   SurroundNode1(E311)  "Another Text"              "Blah xyz"
            //                          ____________ |_____________________________
            //                          |                    |                    |
            //                          Element1(E120)   "InsertedText"(E210)   "tle"
            //
            // range has "Blah xyz" as start and end container and 0 as start and end offset (collapsed)
            // aRange has "ReplacedText" as start container and H1 as end container
            //    and 1 as start offset and 3 as end offset

            IDOM_DocumentFragment* docFrag = aRange->cloneContents();
            TASSERT( docFrag != 0);
            range->selectNode(rt->getFirstChild());
            TASSERT(range->getStartContainer() == rt);
            TASSERT(range->getEndContainer() == rt);
            TASSERT(range->getStartOffset() == 0);
            TASSERT(range->getEndOffset() == 1);

            //Testing toString()
            const XMLCh* str = aRange->toString();
            TASSERT(!XMLString::compareString(str, xeplacedTextInsertedTexttle));

            //start and end before and after tests
            range->setStartBefore(rt->getFirstChild());
            TASSERT(range->getStartOffset() == 0);
            range->setEndBefore(rt->getFirstChild());
            TASSERT(range->getEndOffset() == 0);
            range->setStartAfter(rt->getLastChild());
            TASSERT(range->getStartOffset() == 4);

            range->setStartAfter(rt->getFirstChild());
            TASSERT(range->getStartOffset() == 1);

            range->setEndBefore(rt->getLastChild());
            TASSERT(range->getEndOffset() == 3);

            range->setEndAfter(rt->getLastChild());
            TASSERT(range->getEndOffset() == 4);

            //testing extract()
            IDOM_DocumentFragment* frag2 = range->extractContents();
            TASSERT( frag2 != 0);

            //After above operations, now the tree looks like:
            // <Body><Element3/></Body>
            //i.e.,            Body(rt)
            //                  |
            //               Element3(E122)
            //
            // aRange has rt as start and end container, and 1 as start and end offset (collapsed)
            // range has rt as start and end container, and 1 as start and end offset (collapsed)
            //
            //and frag2 looks:
            // <Body>ReplacedText<SurroundNode1><Element1/>InsertedTexttle</SurroundNode1>Another Text</H1><Element2/><P>Blah xyz</P></Body>
            //i.e.,             Body(rt)
            //      ______________|________________________________________________________
            //      |                                                    |                |
            //   ___H1(E11)___________________________________        Element2(E121)    P(E12)
            //   |              |     |                      |                            |
            //"ReplacedText"   ""   SurroundNode1(E311)  "Another Text"              "Blah xyz"
            //           ____________ |_____________________________
            //           |                    |                    |
            //        Element1(E120)   "InsertedText"(E210)   "tle"
            //

            //the tree do not have those node anymore after extract
            //only Element3 left
            TASSERT(rt->getChildNodes()->getLength()==1);

            //aRange is collapsed
            TASSERT(aRange->getCollapsed() == true);
            TASSERT(aRange->getStartContainer() == rt);
            TASSERT(aRange->getStartOffset() == 1);
            TASSERT(aRange->getEndContainer() == rt);
            TASSERT(aRange->getEndOffset() == 1);

            //range is collapsed as well
            TASSERT(range->getCollapsed() == true);
            TASSERT(range->getStartContainer() == rt);
            TASSERT(range->getStartOffset() == 1);
            TASSERT(range->getEndContainer() == rt);
            TASSERT(range->getEndOffset() == 1);

            //test the document fragment frag2
            TASSERT(frag2->getChildNodes()->getLength()==3);

            //detaching the other range
            aRange->detach();
            range->detach();

            //***************************************************************
            //another set of test
            //TEST createRange, setStart and setEnd, insertnode
            //***************************************************************
            IDOM_DOMImplementation* impl2 = IDOM_DOMImplementation::getImplementation();
            IDOM_Document* doc2 = impl2->createDocument();

            IDOM_Element* root2 = doc2->createElement(xroot2);
            doc2->appendChild(root2);
            //case 1: simple text node, start==end
            // <body>text1</body>
            IDOM_Element* body = doc2->createElement(xBody);
            IDOM_Text* text1 = doc2->createTextNode(xtext1);
            body->appendChild(text1);
            root2->appendChild(body);

            //set range
            IDOM_Range* range1 = doc2->createRange();
            range1->setStart(text1,1);
            range1->setEnd(text1,3);

            TASSERT(!XMLString::compareString(range1->toString(),xex));
            TASSERT(range1->getStartOffset()==1);
            TASSERT(!XMLString::compareString(range1->getStartContainer()->getNodeValue(),xtext1));
            TASSERT(range1->getEndOffset()==3);
            TASSERT(!XMLString::compareString(range1->getEndContainer()->getNodeValue(),xtext1));

            //now insert a text node
            //<body>ttext2ext1</body>
            IDOM_Text* text2 = doc2->createTextNode(xtext2);
            range1->insertNode(text2);

            TASSERT(!XMLString::compareString(range1->toString(),xtext2ex));
            TASSERT(range1->getStartOffset()==1);
            TASSERT(!XMLString::compareString(range1->getStartContainer()->getNodeValue(),xt));
            TASSERT(range1->getEndOffset()==2);
            TASSERT(!XMLString::compareString(range1->getEndContainer()->getNodeValue(),xext1));

            //now insert a non-text node
            //<body>t<p1/>text2ext1</body>
            IDOM_Element* p1 = doc2->createElement(xp1);
            range1->insertNode(p1);

            TASSERT(!XMLString::compareString(range1->toString(),xtext2ex));
            TASSERT(range1->getStartOffset()==1);
            TASSERT(!XMLString::compareString(range1->getStartContainer()->getNodeValue(),xt));
            TASSERT(range1->getEndOffset()==2);
            TASSERT(!XMLString::compareString(range1->getEndContainer()->getNodeValue(),xext1));

            //case 2: non-text node, start==end
            // <head><h1/></head>
            IDOM_Element* head = doc2->createElement(xhead);
            IDOM_Element* h1 = doc2->createElement(xH1);
            head->appendChild(h1);
            root2->appendChild(head);

            //set range
            IDOM_Range* range2 = doc2->createRange();
            range2->setStart(head,0);
            range2->setEnd(head,1);

            TASSERT(!XMLString::compareString(range2->toString(),XMLUni::fgZeroLenString));
            TASSERT(range2->getStartOffset()==0);
            TASSERT(!XMLString::compareString(range2->getStartContainer()->getNodeName(),xhead));
            TASSERT(range2->getEndOffset()==1);
            TASSERT(!XMLString::compareString(range2->getEndContainer()->getNodeName(),xhead));

            //now insert a non-text node
            //<head><h2/><h1/></head>
            IDOM_Element* h2 = doc2->createElement(xh2);
            range2->insertNode(h2);

            TASSERT(!XMLString::compareString(range2->toString(),XMLUni::fgZeroLenString));
            TASSERT(range2->getStartOffset()==0);
            TASSERT(!XMLString::compareString(range2->getStartContainer()->getNodeName(),xhead));
            TASSERT(range2->getEndOffset()==2);
            TASSERT(!XMLString::compareString(range2->getEndContainer()->getNodeName(),xhead));

            //now insert a text node
            //<head>text5<h2/><h1/></head>
            IDOM_Text* text5 = doc2->createTextNode(xtext5);
            range2->insertNode(text5);

            TASSERT(!XMLString::compareString(range2->toString(),xtext5));
            TASSERT(range2->getStartOffset()==0);
            TASSERT(!XMLString::compareString(range2->getStartContainer()->getNodeName(),xhead));
            TASSERT(range2->getEndOffset()==3);
            TASSERT(!XMLString::compareString(range2->getEndContainer()->getNodeName(),xhead));

            //case 3: simple text node, start!=end
            // <body2>text3</body2>
            IDOM_Element* body2 = doc2->createElement(xbody2);
            IDOM_Text* text3 = doc2->createTextNode(xtext3);
            body2->appendChild(text3);
            root2->appendChild(body2);

            //set range
            IDOM_Range* range3 = doc2->createRange();
            range3->setStart(text3,1);
            range3->setEnd(body2,1);

            TASSERT(!XMLString::compareString(range3->toString(),xext3));
            TASSERT(range3->getStartOffset()==1);
            TASSERT(!XMLString::compareString(range3->getStartContainer()->getNodeValue(),xtext3));
            TASSERT(range3->getEndOffset()==1);
            TASSERT(!XMLString::compareString(range3->getEndContainer()->getNodeName(),xbody2));

            //now insert a textnode
            //<body2>ttext4ext3</body2>
            IDOM_Text* text4 = doc2->createTextNode(xtext4);
            range3->insertNode(text4);

            TASSERT(!XMLString::compareString(range3->toString(),XMLUni::fgZeroLenString));
            TASSERT(range3->getStartOffset()==1);
            TASSERT(!XMLString::compareString(range3->getStartContainer()->getNodeValue(),xt));
            TASSERT(range3->getEndOffset()==1);
            TASSERT(!XMLString::compareString(range3->getEndContainer()->getNodeName(),xbody2));

            //now insert a non-text node
            //<body2>t<p2/>text4ext3</body2>
            IDOM_Element* p2 = doc2->createElement(xp2);
            range3->insertNode(p2);

            //extra empty node caused by splitting 't'
            TASSERT(!XMLString::compareString(range3->toString(),XMLUni::fgZeroLenString));
            TASSERT(range3->getStartOffset()==1);
            TASSERT(!XMLString::compareString(range3->getStartContainer()->getNodeValue(),xt));
            TASSERT(range3->getEndOffset()==1);
            TASSERT(!XMLString::compareString(range3->getEndContainer()->getNodeName(),xbody2));

            //test toString a bit
            range3->setStart(body2,1);
            range3->setEnd(body2,5);

            TASSERT(!XMLString::compareString(range3->toString(),xtext4ext3));

            range3->setStart(body2,0);
            range3->setEnd(body2,5);

            TASSERT(!XMLString::compareString(range3->toString(),xttext4ext3));

            //case 4: non-text node, start!=end
            // <head2><h3/></head2>
            IDOM_Element* head2 = doc2->createElement(xhead2);
            IDOM_Element* h3 = doc2->createElement(xh3);
            head2->appendChild(h3);
            root2->appendChild(head2);

            //set range
            IDOM_Range* range4 = doc2->createRange();
            range4->setStart(head2,0);
            range4->setEnd(h3,0);

            TASSERT(!XMLString::compareString(range4->toString(),XMLUni::fgZeroLenString));
            TASSERT(range4->getStartOffset()==0);
            TASSERT(!XMLString::compareString(range4->getStartContainer()->getNodeName(),xhead2));
            TASSERT(range4->getEndOffset()==0);
            TASSERT(!XMLString::compareString(range4->getEndContainer()->getNodeName(),xh3));

            //now insert a non-text node
            //<head2><h4/><h3/></head2>
            IDOM_Element* h4 = doc2->createElement(xh4);
            range4->insertNode(h4);

            TASSERT(!XMLString::compareString(range4->toString(),XMLUni::fgZeroLenString));
            TASSERT(range4->getStartOffset()==0);
            TASSERT(!XMLString::compareString(range4->getStartContainer()->getNodeName(),xhead2));
            TASSERT(range4->getEndOffset()==0);
            TASSERT(!XMLString::compareString(range4->getEndContainer()->getNodeName(),xh3));

            //now insert a text node
            //<head2>text6<h4/><h3/></head2>
            IDOM_Text* text6 = doc2->createTextNode(xtext6);
            range4->insertNode(text6);

            TASSERT(!XMLString::compareString(range4->toString(),xtext6));
            TASSERT(range4->getStartOffset()==0);
            TASSERT(!XMLString::compareString(range4->getStartContainer()->getNodeName(),xhead2));
            TASSERT(range4->getEndOffset()==0);
            TASSERT(!XMLString::compareString(range4->getEndContainer()->getNodeName(),xh3));

            //***************************************************************
            // quick test of updating
            //***************************************************************
            // <upbody>text1</upbody>
            IDOM_Element* upbody = doc2->createElement(xupbody);
            IDOM_Text* uptext1 = doc2->createTextNode(xuptext1);
            upbody->appendChild(uptext1);
            root2->appendChild(upbody);

            IDOM_Range* uprange = doc2->createRange();
            uprange->setStart(upbody,0);
            uprange->setEnd(upbody,1);

            TASSERT(!XMLString::compareString(uprange->toString(),xuptext1));
            TASSERT(uprange->getStartOffset()==0);
            TASSERT(!XMLString::compareString(uprange->getStartContainer()->getNodeName(),xupbody));
            TASSERT(uprange->getEndOffset()==1);
            TASSERT(!XMLString::compareString(uprange->getEndContainer()->getNodeName(),xupbody));

            // split text
            uptext1->splitText(1);

            TASSERT(!XMLString::compareString(uprange->toString(),xu));
            TASSERT(uprange->getStartOffset()==0);
            TASSERT(!XMLString::compareString(uprange->getStartContainer()->getNodeName(),xupbody));
            TASSERT(uprange->getEndOffset()==1);
            TASSERT(!XMLString::compareString(uprange->getEndContainer()->getNodeName(),xupbody));

            //insert node
            IDOM_Element* upbody2 = doc2->createElement(xupbody2);
            IDOM_Text* uptext2 = doc2->createTextNode(xuptext2);
            upbody2->appendChild(uptext2);
            root2->appendChild(upbody2);

            IDOM_Range* uprange2 = doc2->createRange();
            uprange2->setStart(uptext2,1);
            uprange2->setEnd(upbody2,1);

            IDOM_Range* uprange3 = doc2->createRange();
            uprange3->setStart(uptext2,1);
            uprange3->setEnd(upbody2,1);

            TASSERT(!XMLString::compareString(uprange2->toString(),xptext2));
            TASSERT(uprange2->getStartOffset()==1);
            TASSERT(!XMLString::compareString(uprange2->getStartContainer()->getNodeValue(),xuptext2));
            TASSERT(uprange2->getEndOffset()==1);
            TASSERT(!XMLString::compareString(uprange2->getEndContainer()->getNodeName(),xupbody2));

            TASSERT(!XMLString::compareString(uprange3->toString(),xptext2));
            TASSERT(uprange3->getStartOffset()==1);
            TASSERT(!XMLString::compareString(uprange3->getStartContainer()->getNodeValue(),xuptext2));
            TASSERT(uprange3->getEndOffset()==1);
            TASSERT(!XMLString::compareString(uprange3->getEndContainer()->getNodeName(),xupbody2));

            IDOM_Element* upp1 = doc2->createElement(xupp1);
            uprange2->insertNode(upp1);

            TASSERT(!XMLString::compareString(uprange2->toString(),XMLUni::fgZeroLenString));
            TASSERT(uprange2->getStartOffset()==1);
            TASSERT(!XMLString::compareString(uprange2->getStartContainer()->getNodeValue(),xu));
            TASSERT(uprange2->getEndOffset()==1);
            TASSERT(!XMLString::compareString(uprange2->getEndContainer()->getNodeName(),xupbody2));

            TASSERT(!XMLString::compareString(uprange3->toString(),XMLUni::fgZeroLenString));
            TASSERT(uprange3->getStartOffset()==1);
            TASSERT(!XMLString::compareString(uprange3->getStartContainer()->getNodeValue(),xu));
            TASSERT(uprange3->getEndOffset()==1);
            TASSERT(!XMLString::compareString(uprange3->getEndContainer()->getNodeName(),xupbody2));

            //***************************************************************
            //another set of test
            //<foo><c/><moo><b/></moo>ab<a>Hello cd</a><cool>ef</cool></foo>
            //
            //  ______________________foo_____________________
            //  |          |           |          |           |
            //  c         moo        "ab"         a          cool
            //             |                      |           |
            //             b                    "Hello cd"   "ef"
            //
            IDOM_DOMImplementation* impl3 = IDOM_DOMImplementation::getImplementation();
            IDOM_Document* doc3 = impl3->createDocument();

            IDOM_Element* root3 = doc3->createElement(xroot);
            doc3->appendChild(root3);

            IDOM_Element* foo = doc3->createElement(xfoo);
            IDOM_Element* moo = doc3->createElement(xmoo);
            IDOM_Element* cool = doc3->createElement(xcool);
            IDOM_Text* ab = doc3->createTextNode(xab);
            IDOM_Text* cd = doc3->createTextNode(xHellocd);
            IDOM_Text* ef = doc3->createTextNode(xef);

            IDOM_Element* a = doc3->createElement(xa);
            IDOM_Element* b = doc3->createElement(xb);
            IDOM_Element* c = doc3->createElement(xc);

            root3->appendChild(foo);
            foo->appendChild(c);
            foo->appendChild(moo);
            foo->appendChild(ab);
            foo->appendChild(a);
            foo->appendChild(cool);
            moo->appendChild(b);
            a->appendChild(cd);
            cool->appendChild(ef);

            //***************************************************************
            //TEST toString
            //***************************************************************
            IDOM_Range* newtestrange = doc3->createRange();
            //case 1:
            //start container is text node
            //   i) end container is also text node
            //    a) start==end
            //    b) start!=end
            //  ii) end container is not text node
            //    a) start==end => impossible
            //    b) start!=end
            //
            //case 2:
            //start container is not text node
            //   i) end container is text node
            //    a) start==end => impossible
            //    b) start!=end
            //  ii) end container is not text node
            //    a) start==end
            //    b) start!=end

            //case 1, i, a
            newtestrange->setStart( cd, 1 );
            newtestrange->setEnd( cd, 4 );

            TASSERT(!XMLString::compareString(newtestrange->toString(),xell));

            //case 1, i, b
            newtestrange->setStart( cd, 1 );
            newtestrange->setEnd( ef, 2 );

            TASSERT(!XMLString::compareString(newtestrange->toString(),xellocdef));

            //case 1, ii, b
            newtestrange->setStart( cd, 1 );
            newtestrange->setEnd( foo, 4 );

            TASSERT(!XMLString::compareString(newtestrange->toString(),xellocd));

            //case 2, i, b
            newtestrange->setStart( foo, 1 );
            newtestrange->setEnd( cd, 5 );

            TASSERT(!XMLString::compareString(newtestrange->toString(),xabHello));

            //case 2, ii, a
            newtestrange->setStart( foo, 1 );
            newtestrange->setEnd( foo, 4 );

            TASSERT(!XMLString::compareString(newtestrange->toString(),xabHellocd));

            //case 2, ii, b
            newtestrange->setStart( moo, 1 );
            newtestrange->setEnd( foo, 4 );

            TASSERT(!XMLString::compareString(newtestrange->toString(),xabHellocd));

            //***************************************************************
            //test removeChild
            //***************************************************************
            IDOM_Range* newrange = doc3->createRange();
            newrange->setStart( moo, 0 );
            newrange->setEnd( foo, 4 );

            TASSERT(newrange->getStartOffset()==0);
            TASSERT(!XMLString::compareString(newrange->getStartContainer()->getNodeName(),xmoo));
            TASSERT(newrange->getEndOffset()==4);
            TASSERT(!XMLString::compareString(newrange->getEndContainer()->getNodeName(),xfoo));
            TASSERT(!XMLString::compareString(newrange->toString(),xabHellocd));

            IDOM_Node* n = newrange->cloneContents();
            IDOM_NodeList* nol = foo->getChildNodes();

            //removing moo
            foo->removeChild(nol->item(1));
            TASSERT(newrange->getStartOffset()==1);
            TASSERT(!XMLString::compareString(newrange->getStartContainer()->getNodeName(),xfoo));
            TASSERT(newrange->getEndOffset()==3);
            TASSERT(!XMLString::compareString(newrange->getEndContainer()->getNodeName(),xfoo));
            TASSERT(!XMLString::compareString(newrange->toString(),xabHellocd));

            TASSERT(newtestrange->getStartOffset()==1);
            TASSERT(!XMLString::compareString(newtestrange->getStartContainer()->getNodeName(),xfoo));
            TASSERT(newtestrange->getEndOffset()==3);
            TASSERT(!XMLString::compareString(newtestrange->getEndContainer()->getNodeName(),xfoo));
            TASSERT(!XMLString::compareString(newtestrange->toString(),xabHellocd));

            delete doc;
            delete doc2;
            delete doc3;
        }
    } //creating the dom tree and tests

    // And call the termination method
    XMLPlatformUtils::Terminate();

    return 0;
};



