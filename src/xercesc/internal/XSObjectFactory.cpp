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
 * originally based on software copyright (c) 2001, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/*
 * $Log$
 * Revision 1.17  2004/01/06 03:55:26  knoaman
 * Various PSVI fixes.
 *
 * Revision 1.16  2003/12/30 19:46:15  neilg
 * use a null-terminated string when tokenizing pattern facets
 *
 * Revision 1.15  2003/12/29 16:45:06  knoaman
 * PSVI: add whitespace facet if missing
 *
 * Revision 1.14  2003/12/29 16:15:41  knoaman
 * More PSVI updates
 *
 * Revision 1.13  2003/12/24 17:42:02  knoaman
 * Misc. PSVI updates
 *
 * Revision 1.12  2003/12/17 20:50:35  knoaman
 * PSVI: fix for annotation of attributes in attributeGroup/derived types
 *
 * Revision 1.11  2003/12/17 19:58:25  knoaman
 * Check for NULL when building XSParticle
 *
 * Revision 1.10  2003/12/17 00:18:34  cargilld
 * Update to memory management so that the static memory manager (one used to call Initialize) is only for static data.
 *
 * Revision 1.9  2003/12/10 05:14:00  neilg
 * fix seg fault caused when a complex type had simple content; we were not processing the complex type itself, only its base
 *
 * Revision 1.8  2003/12/01 20:41:25  neilg
 * fix for infinite loop between XSComplexTypeDefinitions and XSElementDeclarations; from David Cargill
 *
 * Revision 1.7  2003/11/27 16:42:00  neilg
 * fixes for segfaults and infinite loops in schema component model implementation; thanks to David Cargill
 *
 * Revision 1.6  2003/11/25 17:50:15  knoaman
 * Fix AIX linking error
 *
 * Revision 1.5  2003/11/24 15:45:36  knoaman
 * PSVI: finish construction of XSSimpleTypeDefinition
 *
 * Revision 1.4  2003/11/23 16:49:26  knoaman
 * PSVI: create local elements of groups
 *
 * Revision 1.3  2003/11/23 16:21:40  knoaman
 * PSVI: create local elements of complex types
 *
 * Revision 1.2  2003/11/21 22:34:46  neilg
 * More schema component model implementation, thanks to David Cargill.
 * In particular, this cleans up and completes the XSModel, XSNamespaceItem,
 * XSAttributeDeclaration and XSAttributeGroup implementations.
 *
 * Revision 1.1  2003/11/21 17:11:24  knoaman
 * Initial revision
 *
 */


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/internal/XSObjectFactory.hpp>
#include <xercesc/framework/psvi/XSModel.hpp>
#include <xercesc/framework/psvi/XSParticle.hpp>
#include <xercesc/framework/psvi/XSModelGroup.hpp>
#include <xercesc/framework/psvi/XSElementDeclaration.hpp>
#include <xercesc/framework/psvi/XSComplexTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSSimpleTypeDefinition.hpp>
#include <xercesc/framework/psvi/XSModelGroupDefinition.hpp>
#include <xercesc/framework/psvi/XSAttributeGroupDefinition.hpp>
#include <xercesc/framework/psvi/XSWildcard.hpp>
#include <xercesc/framework/psvi/XSNamespaceItem.hpp>
#include <xercesc/framework/psvi/XSIDCDefinition.hpp>
#include <xercesc/framework/psvi/XSAttributeUse.hpp>
#include <xercesc/framework/psvi/XSAttributeDeclaration.hpp>
#include <xercesc/framework/psvi/XSNotationDeclaration.hpp>
#include <xercesc/framework/psvi/XSFacet.hpp>
#include <xercesc/framework/psvi/XSMultiValueFacet.hpp>
#include <xercesc/validators/common/ContentSpecNode.hpp>
#include <xercesc/validators/datatype/DatatypeValidator.hpp>
#include <xercesc/validators/schema/SchemaAttDefList.hpp>
#include <xercesc/validators/schema/SchemaGrammar.hpp>
#include <xercesc/validators/schema/XercesGroupInfo.hpp>
#include <xercesc/validators/schema/XercesAttGroupInfo.hpp>
#include <xercesc/validators/schema/identity/IdentityConstraint.hpp>
#include <xercesc/validators/schema/identity/IC_KeyRef.hpp>
#include <xercesc/validators/schema/identity/XercesXPath.hpp>
#include <xercesc/util/HashPtr.hpp>
#include <xercesc/util/XMLStringTokenizer.hpp>

XERCES_CPP_NAMESPACE_BEGIN

static XMLCh regexSeparator[] = {chPipe, chNull};

// ---------------------------------------------------------------------------
//  XSObjectFactory: Constructors and Destructor
// ---------------------------------------------------------------------------
XSObjectFactory::XSObjectFactory(MemoryManager* const manager)
    : fMemoryManager(manager)
    , fXercesToXSMap(0)
    , fDeleteVector(0)
{
    fDeleteVector = new (manager) RefVectorOf<XSObject>(20, true, manager);
    fXercesToXSMap = new (manager) RefHashTableOf<XSObject> (
        109, false, new (manager) HashPtr(), manager);
}

XSObjectFactory::~XSObjectFactory()
{
    delete fXercesToXSMap;
    delete fDeleteVector;
}

// ---------------------------------------------------------------------------
//  XSObjectFactory: factory methods
// ---------------------------------------------------------------------------
XSParticle*
XSObjectFactory::createModelGroupParticle(const ContentSpecNode* const rootNode,
                                          XSModel* const xsModel)
{
    if (rootNode == 0)
        return 0;

    ContentSpecNode::NodeTypes nodeType = rootNode->getType();
    if (nodeType == ContentSpecNode::All
        || nodeType == ContentSpecNode::ModelGroupChoice
        || nodeType == ContentSpecNode::ModelGroupSequence)
    {
        XSParticleList* particleList = new (fMemoryManager) RefVectorOf<XSParticle> (4, true, fMemoryManager);
        XSAnnotation* annot = getAnnotationFromModel(xsModel, rootNode);
        XSModelGroup* modelGroup = 0;

        if (nodeType == ContentSpecNode::All)
        {
            modelGroup = new (fMemoryManager) XSModelGroup(XSModelGroup::COMPOSITOR_ALL, particleList, annot, xsModel, fMemoryManager);
            buildAllParticles(rootNode, particleList, xsModel);
        }
        else
        {
            if (nodeType == ContentSpecNode::ModelGroupChoice)
                modelGroup = new (fMemoryManager) XSModelGroup(XSModelGroup::COMPOSITOR_CHOICE, particleList, annot, xsModel, fMemoryManager);
            else
                modelGroup = new (fMemoryManager) XSModelGroup(XSModelGroup::COMPOSITOR_SEQUENCE, particleList, annot, xsModel, fMemoryManager);

            buildChoiceSequenceParticles(rootNode->getFirst(), particleList, xsModel);
            buildChoiceSequenceParticles(rootNode->getSecond(), particleList, xsModel);
        }

        XSParticle* groupParticle = new (fMemoryManager) XSParticle
        (
            XSParticle::TERM_MODELGROUP
            , xsModel
            , modelGroup
            , rootNode->getMinOccurs()
            , rootNode->getMaxOccurs()
            , fMemoryManager
        );
    
        return groupParticle;
    }
    else
        return 0;
}

void XSObjectFactory::buildAllParticles(const ContentSpecNode* const rootNode,
                                 XSParticleList* const particleList,
                                 XSModel* const xsModel)
{
    // Get the type of spec node our current node is
    const ContentSpecNode::NodeTypes nodeType = rootNode->getType();

    if (nodeType == ContentSpecNode::All)
    {
        const ContentSpecNode* rightNode = rootNode->getSecond();

        buildAllParticles(rootNode->getFirst(), particleList, xsModel);
        if (rightNode)
            buildAllParticles(rightNode, particleList, xsModel);
    }
    else if (nodeType == ContentSpecNode::Leaf)
    {
        XSParticle* elemParticle = createElementParticle(rootNode, xsModel);
        if (elemParticle)
            particleList->addElement(elemParticle);
    }
}

void XSObjectFactory::buildChoiceSequenceParticles(const ContentSpecNode* const rootNode,
                                            XSParticleList* const particleList,
                                            XSModel* const xsModel)
{
    if (rootNode)
    {
        const ContentSpecNode::NodeTypes nodeType = rootNode->getType();

        if (nodeType == ContentSpecNode::Sequence)
        {
            buildChoiceSequenceParticles(rootNode->getFirst(), particleList, xsModel);
            buildChoiceSequenceParticles(rootNode->getSecond(), particleList, xsModel);
        }
        else if (nodeType == ContentSpecNode::Choice)
        {
            buildChoiceSequenceParticles(rootNode->getFirst(), particleList, xsModel);
            buildChoiceSequenceParticles(rootNode->getSecond(), particleList, xsModel);
        }
        else if ((nodeType & 0x0f) == ContentSpecNode::Any
                 || (nodeType & 0x0f) == ContentSpecNode::Any_Other
                 || (nodeType & 0x0f) == ContentSpecNode::Any_NS
                 || nodeType == ContentSpecNode::Any_NS_Choice)
        {
            XSParticle* wildcardParticle = createWildcardParticle(rootNode, xsModel);
            if (wildcardParticle)
                particleList->addElement(wildcardParticle);
        }
        else if (nodeType == ContentSpecNode::Leaf)
        {
            XSParticle* elemParticle = createElementParticle(rootNode, xsModel);
            if (elemParticle)
                particleList->addElement(elemParticle);
        }
        // must be a model group
        else
        {
            XSParticle* xsParticle = createModelGroupParticle(rootNode, xsModel);
            if (xsParticle)
                particleList->addElement(xsParticle);
        }
    }
}

XSParticle*
XSObjectFactory::createElementParticle(const ContentSpecNode* const rootNode,
                                       XSModel* const xsModel)
{
    if (rootNode->getElementDecl())
    {
        XSElementDeclaration* xsElemDecl = addOrFind(
            (SchemaElementDecl*) rootNode->getElementDecl(), xsModel);

        if (xsElemDecl)
        {
            XSParticle* particle = new (fMemoryManager) XSParticle
            (
                XSParticle::TERM_ELEMENT
                , xsModel
                , xsElemDecl
                , rootNode->getMinOccurs()
                , rootNode->getMaxOccurs()
                , fMemoryManager
            );

            return particle;
        }
    }

    return 0;
}

XSParticle*
XSObjectFactory::createWildcardParticle(const ContentSpecNode* const rootNode,
                                        XSModel* const xsModel)
{
    XSWildcard* xsWildcard = createXSWildcard(rootNode, xsModel);
    if (xsWildcard)
    {
        XSParticle* particle = new (fMemoryManager) XSParticle
        (
            XSParticle::TERM_WILDCARD
            , xsModel
            , xsWildcard
            , rootNode->getMinOccurs()
            , rootNode->getMaxOccurs()
            , fMemoryManager
        );

        return particle;
    }

    return 0;
}

XSAttributeDeclaration*
XSObjectFactory::addOrFind(SchemaAttDef* const attDef,
                           XSModel* const xsModel,
                           XSComplexTypeDefinition* const enclosingTypeDef)
{
    XSAttributeDeclaration* xsObj = (XSAttributeDeclaration*) xsModel->getXSObject(attDef);
    if (xsObj)
    {
        if (xsObj->getScope() == XSConstants::SCOPE_LOCAL
            && xsObj->getEnclosingCTDefinition() == 0
            && enclosingTypeDef)
            xsObj->setEnclosingCTDefinition(enclosingTypeDef);
    }
    else
    {
        XSSimpleTypeDefinition* xsType = 0;
        if (attDef->getDatatypeValidator())
            xsType = addOrFind(attDef->getDatatypeValidator(), xsModel);

        XSConstants::SCOPE scope = XSConstants::SCOPE_ABSENT;
        XSComplexTypeDefinition* enclosingCTDefinition = 0;

        if (attDef->getPSVIScope() == PSVIDefs::SCP_GLOBAL)
            scope = XSConstants::SCOPE_GLOBAL;
        else if (attDef->getPSVIScope() == PSVIDefs::SCP_LOCAL)
        {
            scope = XSConstants::SCOPE_LOCAL;
            enclosingCTDefinition = enclosingTypeDef;
        }

        xsObj = new (fMemoryManager) XSAttributeDeclaration
        (
            attDef
            , xsType
            , getAnnotationFromModel(xsModel, attDef)
            , xsModel
            , scope
            , enclosingCTDefinition
            , fMemoryManager
        );
        putObjectInMap(attDef, xsObj);
    }

    return xsObj;
}

XSSimpleTypeDefinition*
XSObjectFactory::addOrFind(DatatypeValidator* const validator,
                           XSModel* const xsModel,
                           bool isAnySimpleType)
{
    XSSimpleTypeDefinition* xsObj = (XSSimpleTypeDefinition*) xsModel->getXSObject(validator);
    if (!xsObj)
    {
        XSSimpleTypeDefinition* baseType = 0;
        XSSimpleTypeDefinitionList* memberTypes = 0;
        XSSimpleTypeDefinition* primitiveOrItemType = 0;
        XSSimpleTypeDefinition::VARIETY typeVariety = XSSimpleTypeDefinition::VARIETY_ATOMIC;
        bool primitiveTypeSelf = false;

        //REVISIT: the getFixed method is protected so added friend XSObjectFactory
        //         to DatatypeValidator class... 
        DatatypeValidator::ValidatorType dvType = validator->getType();
        DatatypeValidator* baseDV = validator->getBaseValidator();

        if (dvType == DatatypeValidator::Union)
        {
            typeVariety = XSSimpleTypeDefinition::VARIETY_UNION;
            RefVectorOf<DatatypeValidator>* membersDV = ((UnionDatatypeValidator*)validator)->getMemberTypeValidators();
            unsigned int size = membersDV->size();
            if (size)
            {
                memberTypes = new (fMemoryManager) RefVectorOf<XSSimpleTypeDefinition>(size, false, fMemoryManager);
                for (unsigned int i=0; i<size; i++)
                    memberTypes->addElement(addOrFind(membersDV->elementAt(i), xsModel));
            }
            
            if (baseDV)
            {
                baseType = addOrFind(baseDV, xsModel);
            }
            else
            {
                baseType = (XSSimpleTypeDefinition*) xsModel->getTypeDefinition
                (
                    SchemaSymbols::fgDT_ANYSIMPLETYPE
                    , SchemaSymbols::fgURI_SCHEMAFORSCHEMA
                );
            }
        } 
        else if (dvType == DatatypeValidator::List)
        {
            typeVariety = XSSimpleTypeDefinition::VARIETY_LIST;
            if (baseDV->getType() == DatatypeValidator::List)
            {
                baseType = addOrFind(baseDV, xsModel);
                primitiveOrItemType = baseType->getItemType();
            }
            else
            {
                baseType = (XSSimpleTypeDefinition*) xsModel->getTypeDefinition
                (
                    SchemaSymbols::fgDT_ANYSIMPLETYPE
                    , SchemaSymbols::fgURI_SCHEMAFORSCHEMA
                );
                primitiveOrItemType = addOrFind(baseDV, xsModel);
            }
        }
        else if (!isAnySimpleType)
        {
            if (baseDV)
            {
                baseType = addOrFind(baseDV, xsModel);
                primitiveOrItemType = baseType->getPrimitiveType();
            }
            else // built-in
            {
                baseType = (XSSimpleTypeDefinition*) xsModel->getTypeDefinition
                (
                    SchemaSymbols::fgDT_ANYSIMPLETYPE
                    , SchemaSymbols::fgURI_SCHEMAFORSCHEMA
                );
                primitiveTypeSelf = true;
            }
        }

        xsObj = new (fMemoryManager) XSSimpleTypeDefinition
        (
            validator
            , typeVariety
            , baseType
            , primitiveOrItemType
            , memberTypes
            , getAnnotationFromModel(xsModel, validator)
            , xsModel
            , fMemoryManager
        );
        putObjectInMap(validator, xsObj);

        if (primitiveTypeSelf)
            xsObj->setPrimitiveType(xsObj);

        // process facets
        if (validator->getFacetsDefined())
            processFacets(validator, xsModel, xsObj);
    }

    return xsObj;
}

XSElementDeclaration*
XSObjectFactory::addOrFind(SchemaElementDecl* const elemDecl,
                           XSModel* const xsModel,
                           XSComplexTypeDefinition* const enclosingTypeDef)
{
    XSElementDeclaration* xsObj = (XSElementDeclaration*) xsModel->getXSObject(elemDecl);
    if (xsObj)
    {
        if (!xsObj->getEnclosingCTDefinition() && enclosingTypeDef)
            xsObj->setEnclosingCTDefinition(enclosingTypeDef);
    }
    else
    {
        XSElementDeclaration*        xsSubElem = 0;
        XSTypeDefinition*            xsType = 0;
        XSNamedMap<XSIDCDefinition>* icMap = 0;

        if (elemDecl->getSubstitutionGroupElem())
            xsSubElem = addOrFind(elemDecl->getSubstitutionGroupElem(), xsModel);

        // defer checking for complexTypeInfo until later as it could
        // eventually need this elemement
        // but don't check simple type unless no complexTypeInfo present
        if (!elemDecl->getComplexTypeInfo() && elemDecl->getDatatypeValidator())
            xsType = addOrFind(elemDecl->getDatatypeValidator(), xsModel);

        unsigned int count = elemDecl->getIdentityConstraintCount();
        if (count)
        {
            //REVISIT: size of hash table....   
            icMap = new (fMemoryManager) XSNamedMap<XSIDCDefinition>
            (
                count
                , 29
                , xsModel->getURIStringPool()
                , false
                , fMemoryManager
            );

            for (unsigned int i = 0; i < count; i++) 
            {
                XSIDCDefinition* icDef = addOrFind
                (
                    elemDecl->getIdentityConstraintAt(i)
                    , xsModel
                );
                if (icDef)
                {
                    icMap->addElement
                    (
                        icDef
                        , icDef->getName()
                        , icDef->getNamespace()
                    );
                }
            }
        }

        XSConstants::SCOPE elemScope = XSConstants::SCOPE_ABSENT;
        if (elemDecl->getPSVIScope() == PSVIDefs::SCP_LOCAL)
            elemScope = XSConstants::SCOPE_LOCAL;
        else if (elemDecl->getPSVIScope() == PSVIDefs::SCP_GLOBAL)
            elemScope = XSConstants::SCOPE_GLOBAL;

        xsObj = new (fMemoryManager) XSElementDeclaration
        (
            elemDecl
            , xsType
            , xsSubElem
            , getAnnotationFromModel(xsModel, elemDecl)
            , icMap
            , xsModel
            , elemScope
            , enclosingTypeDef
            , fMemoryManager
        );
        putObjectInMap(elemDecl, xsObj);

        if (elemDecl->getComplexTypeInfo())
        {
            xsType = addOrFind(elemDecl->getComplexTypeInfo(), xsModel);
            xsObj->setTypeDefinition(xsType);
        }
        else if (!xsType)
        {
            xsType = xsModel->getTypeDefinition
            (
                SchemaSymbols::fgATTVAL_ANYTYPE
                , SchemaSymbols::fgURI_SCHEMAFORSCHEMA
            );
            xsObj->setTypeDefinition(xsType);
        }
    }

    return xsObj;
}

XSComplexTypeDefinition*
XSObjectFactory::addOrFind(ComplexTypeInfo* const typeInfo,
                           XSModel* const xsModel)
{
    XSComplexTypeDefinition* xsObj = (XSComplexTypeDefinition*) xsModel->getXSObject(typeInfo);
    if (!xsObj)
    {
        XSWildcard*             xsWildcard = 0;
        XSSimpleTypeDefinition* xsSimpleType = 0;
        XSAttributeUseList*     xsAttList = 0;
        XSTypeDefinition*       xsBaseType = 0;
        XSParticle*             xsParticle = 0;

        if (typeInfo->getAttWildCard())
            xsWildcard = createXSWildcard(typeInfo->getAttWildCard(), xsModel);

        if ((typeInfo->getContentType() == SchemaElementDecl::Simple) &&
            (typeInfo->getDatatypeValidator()))
            xsSimpleType = addOrFind(typeInfo->getDatatypeValidator(), xsModel);
        
        unsigned int attCount;
        if (typeInfo->hasAttDefs())
        {
            SchemaAttDefList& attDefList = (SchemaAttDefList&) typeInfo->getAttDefList();
            attCount = attDefList.getAttDefCount();
            xsAttList = new (fMemoryManager) RefVectorOf<XSAttributeUse>(attCount, false, fMemoryManager);            
            // create list now put fill it in after we put complextype into map
            // otherwise we may encounter an infinite loop: complextype needs to
            // addorfind attdef, which does an addorfind on the enclosingCTdefintion.
        }

        // compute fBase
        bool isAnyType = false;
        if (typeInfo->getBaseComplexTypeInfo() == typeInfo) // case of anyType
            isAnyType = true;
        else if (typeInfo->getBaseComplexTypeInfo())
            xsBaseType = addOrFind(typeInfo->getBaseComplexTypeInfo(), xsModel);
        else if (typeInfo->getBaseDatatypeValidator())
            xsBaseType = addOrFind(typeInfo->getBaseDatatypeValidator(), xsModel);
        else // base is anyType
            xsBaseType = xsModel->getTypeDefinition(SchemaSymbols::fgATTVAL_ANYTYPE, SchemaSymbols::fgURI_SCHEMAFORSCHEMA);

        // compute particle
        ContentSpecNode* contentSpec = typeInfo->getContentSpec();
        if (contentSpec)
            xsParticle = createModelGroupParticle(contentSpec, xsModel);

        xsObj = new (fMemoryManager) XSComplexTypeDefinition
        (
            typeInfo
            , xsWildcard
            , xsSimpleType
            , xsAttList
            , xsBaseType
            , xsParticle
            , getAnnotationFromModel(xsModel, typeInfo)
            , xsModel
            , fMemoryManager
        );
        putObjectInMap(typeInfo, xsObj);

        if (isAnyType)
            xsObj->setBaseType(xsObj);
       
        if (typeInfo->hasAttDefs())
        {
            // now create the xsattributedeclarations...
            SchemaAttDefList& attDefList = (SchemaAttDefList&) typeInfo->getAttDefList();
            for(unsigned int i=0; i<attCount; i++)
            {
                XSAttributeDeclaration* xsAttDecl = 0;
                SchemaAttDef& attDef = (SchemaAttDef&) attDefList.getAttDef(i);

                if (attDef.getBaseAttDecl())
                    xsAttDecl = addOrFind(attDef.getBaseAttDecl(), xsModel);
                else
                    xsAttDecl = addOrFind(&attDef, xsModel, xsObj);

                XSAttributeUse* attUse = createXSAttributeUse(xsAttDecl, xsModel);
                xsAttList->addElement(attUse);
                processAttUse(&attDef, attUse);
            }
        }

        // process local elements
        unsigned int elemCount = typeInfo->elementCount();
        for (unsigned int j=0; j<elemCount; j++)
        {
            SchemaElementDecl* elemDecl = typeInfo->elementAt(j);

            if (elemDecl->getEnclosingScope() == typeInfo->getScopeDefined()
                && elemDecl->getPSVIScope() == PSVIDefs::SCP_LOCAL)
                addOrFind(elemDecl, xsModel, xsObj);
        }
    }

    return xsObj;
}

XSIDCDefinition* XSObjectFactory::addOrFind(IdentityConstraint* const ic,
                                            XSModel* const xsModel)
{
    XSIDCDefinition* xsObj = (XSIDCDefinition*) xsModel->getXSObject(ic);
    if (!xsObj)
    {
        XSIDCDefinition* keyIC = 0;
        StringList*      stringList = 0;
        unsigned int     fieldCount = ic->getFieldCount();

        if (fieldCount) 
        {
            stringList = new (fMemoryManager) RefArrayVectorOf<XMLCh>(
                fieldCount, true, fMemoryManager);

            for(unsigned int i=0; i<fieldCount; i++)
            {
                XMLCh* expr = XMLString::replicate
                (
                    ic->getFieldAt(i)->getXPath()->getExpression()
                    , fMemoryManager
                );
                stringList->addElement(expr);
            }
        }

        if (ic->getType() == IdentityConstraint::KEYREF)
            keyIC = addOrFind(((IC_KeyRef*) ic)->getKey(), xsModel);

        xsObj= new (fMemoryManager) XSIDCDefinition
        (
            ic
            , keyIC
            , getAnnotationFromModel(xsModel, ic)
            , stringList
            , xsModel
            , fMemoryManager
        );
        putObjectInMap(ic, xsObj);
    }

    return xsObj;
}

XSNotationDeclaration* XSObjectFactory::addOrFind(XMLNotationDecl* const notDecl,
                                                  XSModel* const xsModel)
{
    XSNotationDeclaration* xsObj = (XSNotationDeclaration*) xsModel->getXSObject(notDecl);
    if (!xsObj)
    {
        xsObj = new (fMemoryManager) XSNotationDeclaration
        (
            notDecl
            , getAnnotationFromModel(xsModel, notDecl)
            , xsModel
            , fMemoryManager
        );
        putObjectInMap(notDecl, xsObj);
    }

    return xsObj;
}

XSAttributeUse*
XSObjectFactory::createXSAttributeUse(XSAttributeDeclaration* const xsAttDecl,
                               XSModel* const xsModel)
{
    XSAttributeUse* attrUse = new (fMemoryManager) XSAttributeUse(xsAttDecl, xsModel, fMemoryManager);
    fDeleteVector->addElement(attrUse);

    return attrUse;
}

XSWildcard*
XSObjectFactory::createXSWildcard(SchemaAttDef* const attDef,
                                  XSModel* const xsModel)
{
    XSAnnotation* annot = (attDef->getBaseAttDecl())
        ? getAnnotationFromModel(xsModel, attDef->getBaseAttDecl())
        : getAnnotationFromModel(xsModel, attDef);

    XSWildcard* xsWildcard = new (fMemoryManager) XSWildcard
    (
        attDef
        , annot
        , xsModel
        , fMemoryManager
    );
    fDeleteVector->addElement(xsWildcard);

    return xsWildcard;
}

XSWildcard*
XSObjectFactory::createXSWildcard(const ContentSpecNode* const rootNode,
                                  XSModel* const xsModel)
{
    XSWildcard* xsWildcard = new (fMemoryManager) XSWildcard
    (
        rootNode
        , getAnnotationFromModel(xsModel, rootNode)
        , xsModel
        , fMemoryManager
    );
    fDeleteVector->addElement(xsWildcard);

    return xsWildcard;
}

XSModelGroupDefinition*
XSObjectFactory::createXSModelGroupDefinition(XercesGroupInfo* const groupInfo,
                                              XSModel* const xsModel)
{
    XSParticle* particle = createModelGroupParticle(
            groupInfo->getContentSpec(), xsModel);

    XSModelGroupDefinition* xsObj = new (fMemoryManager) XSModelGroupDefinition
    (
        groupInfo
        , particle
        , getAnnotationFromModel(xsModel, groupInfo)
        , xsModel
        , fMemoryManager
    );
    fDeleteVector->addElement(xsObj);

    // process local elements
    unsigned int elemCount = groupInfo->elementCount();
    for (unsigned int j=0; j<elemCount; j++)
    {
        SchemaElementDecl* elemDecl = groupInfo->elementAt(j);

        if (elemDecl->getEnclosingScope() == groupInfo->getScope())
            addOrFind(elemDecl, xsModel);
    }

    return xsObj;
}


XSAttributeGroupDefinition*
XSObjectFactory::createXSAttGroupDefinition(XercesAttGroupInfo* const attGroupInfo,
                                            XSModel* const xsModel)
{
    XSAttributeUseList* xsAttList = 0;
    XSWildcard*         xsWildcard = 0;
    unsigned int        attCount = attGroupInfo->attributeCount();

    if (attCount)
    {
        xsAttList = new (fMemoryManager) RefVectorOf<XSAttributeUse>(attCount, false, fMemoryManager);
        for (unsigned int i=0; i < attCount; i++) 
        {
            SchemaAttDef* attDef = attGroupInfo->attributeAt(i);
            XSAttributeDeclaration* xsAttDecl = 0;

            if (attDef->getBaseAttDecl())
                xsAttDecl = addOrFind(attDef->getBaseAttDecl(), xsModel);
            else
                xsAttDecl = addOrFind(attDef, xsModel);

            if (xsAttDecl) // just for sanity
            {
                XSAttributeUse* attUse = createXSAttributeUse(xsAttDecl, xsModel);
                xsAttList->addElement(attUse);
                processAttUse(attDef, attUse);
            }
        }
    }
    
    if (attGroupInfo->getCompleteWildCard())
        xsWildcard = createXSWildcard(attGroupInfo->getCompleteWildCard(), xsModel);

    XSAttributeGroupDefinition* xsObj = new (fMemoryManager) XSAttributeGroupDefinition
    (
        attGroupInfo
        , xsAttList
        , xsWildcard
        , getAnnotationFromModel(xsModel, attGroupInfo)
        , xsModel
        , fMemoryManager
    );
    fDeleteVector->addElement(xsObj);

    return xsObj;
}

XSAnnotation* XSObjectFactory::getAnnotationFromModel(XSModel* const xsModel,
                                               const void* const key)
{
    XSNamespaceItemList* namespaceItemList = xsModel->getNamespaceItems();

    XSAnnotation* annot = 0;
    for (unsigned int i=0; i<namespaceItemList->size(); i++)
    {
        XSNamespaceItem* nsItem = namespaceItemList->elementAt(i);
        if (nsItem->fGrammar)
        {
            annot = nsItem->fGrammar->getAnnotation(key);
            if (annot)
                return annot;
        }
    }

    if (xsModel->fParent)
        return getAnnotationFromModel(xsModel->fParent, key);
    return 0;
}


void XSObjectFactory::putObjectInMap(void* key, XSObject* const object)
{
     fXercesToXSMap->put(key, object);
     fDeleteVector->addElement(object);
}


void XSObjectFactory::processFacets(DatatypeValidator* const dv,
                                    XSModel* const xsModel,
                                    XSSimpleTypeDefinition* const xsST)
{
    // NOTE: XSMultiValueFacetList is not owned by XSModel!
    // NOTE: XSFacetList is not owned by XSModel!
    int definedFacets = 0;
    int fixedFacets = 0;
    XSFacetList* xsFacetList = new (fMemoryManager) RefVectorOf<XSFacet>(4, true, fMemoryManager);
    XSMultiValueFacetList* xsMultiFacetList = 0;
    StringList* patternList = 0;
    bool isFixed = false;
    int dvFacetsDefined = dv->getFacetsDefined();
    int dvFixedFacets = dv->getFixed();

    if ((dvFacetsDefined & DatatypeValidator::FACET_PATTERN)
        || (dvFacetsDefined & DatatypeValidator::FACET_ENUMERATION))
        xsMultiFacetList = new (fMemoryManager) RefVectorOf<XSMultiValueFacet>(2, true, fMemoryManager);

    if (dvFacetsDefined & DatatypeValidator::FACET_ENUMERATION)
    {
        RefArrayVectorOf<XMLCh>* enumList = (RefArrayVectorOf<XMLCh>*) dv->getEnumString();
        isFixed = ((dvFixedFacets & DatatypeValidator::FACET_ENUMERATION) != 0);

        // NOTE: Don't need to add multivaluefacet to "ObjectMap -> getObjectFromMap/putObjectInMap);
        xsMultiFacetList->addElement(
            new (fMemoryManager) XSMultiValueFacet(
                XSSimpleTypeDefinition::FACET_ENUMERATION , enumList, isFixed
                , getAnnotationFromModel(xsModel, enumList)
                , xsModel, fMemoryManager)
        );
        definedFacets |= XSSimpleTypeDefinition::FACET_ENUMERATION;
        if (isFixed)
            fixedFacets |= XSSimpleTypeDefinition::FACET_ENUMERATION;
    }

    RefHashTableOf<KVStringPair>* facets = dv->getFacets();
    if (facets)
    {
        // NOTE: Don't need to add facet to "ObjectMap -> getObjectFromMap/putObjectInMap);
        RefHashTableOfEnumerator<KVStringPair> e(facets, false, fMemoryManager);
        while (e.hasMoreElements())
        {
            KVStringPair& pair = e.nextElement();
            XMLCh* key = pair.getKey();
            XSSimpleTypeDefinition::FACET facetType = XSSimpleTypeDefinition::FACET_NONE;
            XSAnnotation* annot = getAnnotationFromModel(xsModel, &pair);

            if (XMLString::equals(key, SchemaSymbols::fgELT_MAXINCLUSIVE))
            {
                facetType = XSSimpleTypeDefinition::FACET_MAXINCLUSIVE;
                isFixed = ((dvFixedFacets & DatatypeValidator::FACET_MAXINCLUSIVE) != 0);
            }
            else if (XMLString::equals(key, SchemaSymbols::fgELT_MAXEXCLUSIVE))
            {
                facetType = XSSimpleTypeDefinition::FACET_MAXEXCLUSIVE;
                isFixed = ((dvFixedFacets & DatatypeValidator::FACET_MAXEXCLUSIVE) !=0);
            }
            else if (XMLString::equals(key, SchemaSymbols::fgELT_MININCLUSIVE))
            {
                facetType = XSSimpleTypeDefinition::FACET_MININCLUSIVE;
                isFixed = ((dvFixedFacets & DatatypeValidator::FACET_MININCLUSIVE) !=0);
            }
            else if (XMLString::equals(key, SchemaSymbols::fgELT_MINEXCLUSIVE))
            {
                facetType = XSSimpleTypeDefinition::FACET_MINEXCLUSIVE;
                isFixed = ((dvFixedFacets & DatatypeValidator::FACET_MINEXCLUSIVE) != 0);
            }
            else if (XMLString::equals(key, SchemaSymbols::fgELT_LENGTH))
            {
                facetType = XSSimpleTypeDefinition::FACET_LENGTH;
                isFixed = ((dvFixedFacets & DatatypeValidator::FACET_LENGTH) != 0);
            }
            else if (XMLString::equals(key, SchemaSymbols::fgELT_MINLENGTH))
            {
                facetType = XSSimpleTypeDefinition::FACET_MINLENGTH;
                isFixed = ((dvFixedFacets & DatatypeValidator::FACET_MINLENGTH) != 0);
            }
            else if (XMLString::equals(key, SchemaSymbols::fgELT_MAXLENGTH))
            {
                facetType = XSSimpleTypeDefinition::FACET_MAXLENGTH;
                isFixed = ((dvFixedFacets & DatatypeValidator::FACET_MAXLENGTH) != 0);
            }
            else if (XMLString::equals(key, SchemaSymbols::fgELT_TOTALDIGITS))
            {
                facetType = XSSimpleTypeDefinition::FACET_TOTALDIGITS;
                isFixed = ((dvFixedFacets & DatatypeValidator::FACET_TOTALDIGITS) != 0);
            }
            else if (XMLString::equals(key, SchemaSymbols::fgELT_FRACTIONDIGITS))
            {
                facetType = XSSimpleTypeDefinition::FACET_FRACTIONDIGITS;
                isFixed = ((dvFixedFacets & DatatypeValidator::FACET_FRACTIONDIGITS) != 0);
            }
            else if (XMLString::equals(key, SchemaSymbols::fgELT_WHITESPACE))
            {
                facetType = XSSimpleTypeDefinition::FACET_WHITESPACE;
                isFixed = ((dvFixedFacets & DatatypeValidator::FACET_WHITESPACE) != 0);
            }
            else if (XMLString::equals(key, SchemaSymbols::fgELT_PATTERN))
            {
                XMLStringTokenizer tokenizer(dv->getPattern(), regexSeparator, fMemoryManager);
                patternList = new (fMemoryManager) RefArrayVectorOf<XMLCh>(tokenizer.countTokens(), true, fMemoryManager);
                
                while (tokenizer.hasMoreTokens())
                    patternList->addElement(XMLString::replicate(tokenizer.nextToken(), fMemoryManager));

                isFixed = ((dvFixedFacets & DatatypeValidator::FACET_PATTERN) != 0);
                // NOTE: Don't need to add multivaluefacet to "ObjectMap -> getObjectFromMap/putObjectInMap);
                xsMultiFacetList->addElement(
                    new (fMemoryManager) XSMultiValueFacet(
                        XSSimpleTypeDefinition::FACET_PATTERN, patternList
                        , isFixed, annot, xsModel, fMemoryManager)
	            );
                definedFacets |= XSSimpleTypeDefinition::FACET_PATTERN;
                if (isFixed) 
                    fixedFacets |= XSSimpleTypeDefinition::FACET_PATTERN;
                continue;
            }
            else
            {
                // REVISIT: hmm... what about XSSimpleTypeDefinition::FACET_NONE
                // don't think I need to create an empty Facet?
                continue;
            }

            xsFacetList->addElement(
                new (fMemoryManager) XSFacet(
                    facetType, pair.getValue(), isFixed, annot, xsModel, fMemoryManager)
            );

            definedFacets |= facetType;
            if (isFixed) 
                fixedFacets |= facetType;
        }
    }

    // add whistespace facet if missing
    if (!(definedFacets & XSSimpleTypeDefinition::FACET_WHITESPACE))
    {
        xsFacetList->addElement
        (
            new (fMemoryManager) XSFacet
            (
                XSSimpleTypeDefinition::FACET_WHITESPACE
                , dv->getWSstring(dv->getWSFacet())
                , false, 0, xsModel, fMemoryManager
            )
        );
        definedFacets |= XSSimpleTypeDefinition::FACET_WHITESPACE;
    }

    xsST->setFacetInfo(definedFacets, fixedFacets, xsFacetList, xsMultiFacetList, patternList);
}

void XSObjectFactory::processAttUse(SchemaAttDef* const attDef,
                                    XSAttributeUse* const xsAttUse)
{
    bool isRequired = false;
    XSConstants::VALUE_CONSTRAINT constraintType = XSConstants::VC_NONE;
    
    if (attDef->getDefaultType() == XMLAttDef::Default)
    {
        constraintType = XSConstants::VC_DEFAULT;
    }
    else if ((attDef->getDefaultType() == XMLAttDef::Fixed) ||
             (attDef->getDefaultType() == XMLAttDef::Required_And_Fixed))
    {
        constraintType = XSConstants::VC_FIXED;
    }

    if (attDef->getDefaultType() == XMLAttDef::Required ||
        attDef->getDefaultType() == XMLAttDef::Required_And_Fixed)
        isRequired = true;

    xsAttUse->set(isRequired, constraintType, attDef->getValue());
}

XERCES_CPP_NAMESPACE_END
