/*
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2003 The Apache Software Foundation.  All rights
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
 * Revision 1.4  2003/11/14 22:33:30  neilg
 * ./src/xercesc/framework/psvi/XSAnnotation.cpp
 * ./src/xercesc/framework/psvi/XSAnnotation.hpp
 * ./src/xercesc/framework/psvi/XSAttributeDeclaration.cpp
 * ./src/xercesc/framework/psvi/XSAttributeDeclaration.hpp
 * ./src/xercesc/framework/psvi/XSAttributeGroupDefinition.cpp
 * ./src/xercesc/framework/psvi/XSAttributeGroupDefinition.hpp
 * ./src/xercesc/framework/psvi/XSAttributeUse.cpp
 * ./src/xercesc/framework/psvi/XSAttributeUse.hpp
 * ./src/xercesc/framework/psvi/XSComplexTypeDefinition.cpp
 * ./src/xercesc/framework/psvi/XSComplexTypeDefinition.hpp
 * ./src/xercesc/framework/psvi/XSElementDeclaration.cpp
 * ./src/xercesc/framework/psvi/XSElementDeclaration.hpp
 * ./src/xercesc/framework/psvi/XSFacet.cpp
 * ./src/xercesc/framework/psvi/XSFacet.hpp
 * ./src/xercesc/framework/psvi/XSIDCDefinition.cpp
 * ./src/xercesc/framework/psvi/XSIDCDefinition.hpp
 * ./src/xercesc/framework/psvi/XSModel.cpp
 * ./src/xercesc/framework/psvi/XSModel.hpp
 * ./src/xercesc/framework/psvi/XSModelGroup.cpp
 * ./src/xercesc/framework/psvi/XSModelGroup.hpp
 * ./src/xercesc/framework/psvi/XSModelGroupDefinition.cpp
 * ./src/xercesc/framework/psvi/XSModelGroupDefinition.hpp
 * ./src/xercesc/framework/psvi/XSMultiValueFacet.cpp
 * ./src/xercesc/framework/psvi/XSMultiValueFacet.hpp
 * ./src/xercesc/framework/psvi/XSNamespaceItem.cpp
 * ./src/xercesc/framework/psvi/XSNamespaceItem.hpp
 * ./src/xercesc/framework/psvi/XSNotationDeclaration.cpp
 * ./src/xercesc/framework/psvi/XSNotationDeclaration.hpp
 * ./src/xercesc/framework/psvi/XSObject.cpp
 * ./src/xercesc/framework/psvi/XSObject.hpp
 * ./src/xercesc/framework/psvi/XSParticle.cpp
 * ./src/xercesc/framework/psvi/XSParticle.hpp
 * ./src/xercesc/framework/psvi/XSSimpleTypeDefinition.cpp
 * ./src/xercesc/framework/psvi/XSSimpleTypeDefinition.hpp
 * ./src/xercesc/framework/psvi/XSTypeDefinition.cpp
 * ./src/xercesc/framework/psvi/XSTypeDefinition.hpp
 * ./src/xercesc/framework/psvi/XSWildcard.cpp
 * ./src/xercesc/framework/psvi/XSWildcard.hpp
 * ./src/xercesc/internal/XMLGrammarPoolImpl.cpp
 * ./src/xercesc/internal/XMLGrammarPoolImpl.hpp
 * ./src/xercesc/validators/schema/identity/IdentityConstraint.cpp
 * ./src/xercesc/validators/schema/identity/IdentityConstraint.hpp
 * ./src/xercesc/validators/schema/SchemaGrammar.hpp
 * ./src/xercesc/validators/schema/TraverseSchema.cpp
 *
 * Revision 1.3  2003/11/06 15:30:04  neilg
 * first part of PSVI/schema component model implementation, thanks to David Cargill.  This covers setting the PSVIHandler on parser objects, as well as implementing XSNotation, XSSimpleTypeDefinition, XSIDCDefinition, and most of XSWildcard, XSComplexTypeDefinition, XSElementDeclaration, XSAttributeDeclaration and XSAttributeUse.
 *
 * Revision 1.2  2003/09/17 17:45:37  neilg
 * remove spurious inlines; hopefully this will make Solaris/AIX compilers happy.
 *
 * Revision 1.1  2003/09/16 14:33:36  neilg
 * PSVI/schema component model classes, with Makefile/configuration changes necessary to build them
 *
 */

#include <xercesc/framework/psvi/XSAttributeDeclaration.hpp>
#include <xercesc/validators/schema/SchemaAttDef.hpp>
#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>
#include <xercesc/util/QName.hpp>
#include <xercesc/util/StringPool.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/validators/schema/SchemaGrammar.hpp>

XERCES_CPP_NAMESPACE_BEGIN

XSAttributeDeclaration::XSAttributeDeclaration(SchemaAttDef*            attDef,
                                               XSModel*                 xsModel,
                                               MemoryManager * const    manager):
    fAttDef(attDef),
    fTypeDefinition(0),
    XSObject(XSConstants::ATTRIBUTE_DECLARATION, xsModel, manager)
{
    if (fAttDef->getDatatypeValidator())
    {
        fTypeDefinition = (XSSimpleTypeDefinition*) getObjectFromMap((void *)fAttDef->getDatatypeValidator());
        if (!fTypeDefinition)
        {
            fTypeDefinition = new (manager) XSSimpleTypeDefinition(fAttDef->getDatatypeValidator(), fXSModel, manager);
            putObjectInMap((void *)fAttDef->getDatatypeValidator(), fTypeDefinition);
        }
    }
}

XSAttributeDeclaration::~XSAttributeDeclaration() 
{
    // don't delete fTypeDefinition - deleted by XSModel
}
// XSObject methods
const XMLCh *XSAttributeDeclaration::getName() 
{
    return fAttDef->getAttName()->getLocalPart();
}

const XMLCh *XSAttributeDeclaration::getNamespace() 
{
    return fXSModel->getURIStringPool()->getValueForId(fAttDef->getAttName()->getURI());
}

XSNamespaceItem *XSAttributeDeclaration::getNamespaceItem() 
{
    return getNamespaceItemFromHash(getNamespace());
}

// XSAttributeDeclaration methods

/**
 * [type definition]: A simple type definition 
 */
XSSimpleTypeDefinition *XSAttributeDeclaration::getTypeDefinition()
{
    return fTypeDefinition;
}

/**
 * Optional. One of <code>SCOPE_GLOBAL</code>, <code>SCOPE_LOCAL</code>, 
 * or <code>SCOPE_ABSENT</code>. If the scope is local, then the 
 * <code>enclosingCTDefinition</code> is present. 
 */
XSConstants::SCOPE XSAttributeDeclaration::getScope() const
{   
    // REVISIT: review... what about SCOPE_ABSENT?
    // Using just:
    // if (getNamespaceItem()->getSchemaGrammar()->getAttributeDeclRegistry()->get(fAttDef))
    // give class conversion error...
    if (((XSAttributeDeclaration*) this)->getNamespaceItem()->getSchemaGrammar()->getAttributeDeclRegistry()->get(fAttDef))
        return XSConstants::SCOPE_GLOBAL;
    return XSConstants::SCOPE_LOCAL;

}

/**
 * The complex type definition for locally scoped declarations (see 
 * <code>scope</code>). 
 */
XSComplexTypeDefinition *XSAttributeDeclaration::getEnclosingCTDefinition()
{
    // REVISIT
    return 0;
}

/**
 * Value constraint: one of <code>VC_NONE, VC_DEFAULT, VC_FIXED</code>. 
 */
XSConstants::VALUE_CONSTRAINT XSAttributeDeclaration::getConstraintType() const
{
    if (fAttDef->getDefaultType() & XMLAttDef::Default)
    {
        return XSConstants::VC_DEFAULT;
    }
    if (fAttDef->getDefaultType() & XMLAttDef::Fixed ||
        fAttDef->getDefaultType() & XMLAttDef::Required_And_Fixed)
    {
        return XSConstants::VC_FIXED;
    }
    return XSConstants::VC_NONE;
}

/**
 * Value constraint: The actual value with respect to the [type definition
 * ]. 
 */
const XMLCh *XSAttributeDeclaration::getConstraintValue()
{
    return fAttDef->getValue();
}

/**
 * Optional. Annotation. 
 */
XSAnnotation *XSAttributeDeclaration::getAnnotation()
{
    return getAnnotationFromModel(fAttDef);
}

/**
 * Process Id
 */ 
void XSAttributeDeclaration::setId(unsigned int id)
{
    fId = id;
}

unsigned int XSAttributeDeclaration::getId() const
{
    return fId;
}

XERCES_CPP_NAMESPACE_END


