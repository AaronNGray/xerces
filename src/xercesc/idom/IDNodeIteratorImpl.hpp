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
 * Revision 1.1  2002/02/01 22:21:55  peiyongz
 * Initial revision
 *
 * Revision 1.3  2001/06/04 20:11:52  tng
 * IDOM: Complete IDNodeIterator, IDTreeWalker, IDNodeFilter.
 *
 * Revision 1.2  2001/05/11 13:25:45  tng
 * Copyright update.
 *
 * Revision 1.1.1.1  2001/04/03 00:14:25  andyh
 * IDOM
 *
 */

#ifndef IDNodeIteratorImpl_HEADER_GUARD_
#define IDNodeIteratorImpl_HEADER_GUARD_


// IDNodeIteratorImpl.hpp: interface for the IDNodeIteratorImpl class.
//
//////////////////////////////////////////////////////////////////////

#include "IDOM_Node.hpp"
#include "IDOM_NodeIterator.hpp"


class CDOM_EXPORT IDNodeIteratorImpl : public IDOM_NodeIterator {
    private:
        //
        // Data
        //
        // The root.
        IDOM_Node* fRoot;

        // The whatToShow mask.
        unsigned long fWhatToShow;

        // The NodeFilter reference.
        IDOM_NodeFilter* fNodeFilter;


        // The expandEntity reference flag.
        bool  fExpandEntityReferences;
        bool fDetached;


        //
        // Iterator state - current node and direction.
        //
        // Note: The current node and direction are sufficient to implement
        // the desired behaviour of the current pointer being _between_
        // two nodes. The fCurrentNode is actually the last node returned,
        // and the
        // direction is whether the pointer is in front or behind this node.
        // (usually akin to whether the node was returned via nextNode())
        // (eg fForward = true) or previousNode() (eg fForward = false).
        // The last Node returned.
        IDOM_Node* fCurrentNode;

        // The direction of the iterator on the fCurrentNode.
        //  <pre>
        //  nextNode()  ==      fForward = true;
        //  previousNode() ==   fForward = false;
        //  </pre>
        bool fForward;

    protected:
        IDNodeIteratorImpl ();

    public:
        virtual ~IDNodeIteratorImpl ();
        IDNodeIteratorImpl (
            IDOM_Node* root,
            unsigned long whatToShow,
            IDOM_NodeFilter* nodeFilter,
            bool expandEntityRef);

        IDNodeIteratorImpl ( const IDNodeIteratorImpl& toCopy);
        IDNodeIteratorImpl& operator= (const IDNodeIteratorImpl& other);
        	
        virtual unsigned long getWhatToShow ();
        virtual IDOM_NodeFilter* getFilter ();
        // Get the expandEntity reference flag.
        virtual bool getExpandEntityReferences();

        virtual IDOM_Node* nextNode ();
        virtual IDOM_Node* previousNode ();
        virtual void detach ();

    private:
        IDOM_Node* matchNodeOrParent (IDOM_Node* node);
        IDOM_Node* nextNode (IDOM_Node* node, bool visitChildren);
        IDOM_Node* previousNode (IDOM_Node* node);
        void removeNode (IDOM_Node* node);
        bool acceptNode (IDOM_Node* node);

};

#endif
