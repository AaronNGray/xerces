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
 * Revision 1.6  2002/03/25 20:25:32  knoaman
 * Move particle derivation checking from TraverseSchema to SchemaValidator.
 *
 * Revision 1.5  2002/02/26 14:26:10  tng
 * [Bug 6672] SAXValidator results in an access violation when validating against schema with empty element that has default value.
 *
 * Revision 1.4  2002/02/25 21:24:31  tng
 * Schema Fix: Ensure no invalid uri index for UPA checking.
 *
 * Revision 1.3  2002/02/25 21:18:18  tng
 * Schema Fix: Ensure no invalid uri index for UPA checking.
 *
 * Revision 1.2  2002/02/07 16:41:29  knoaman
 * Fix for xsi:type.
 *
 * Revision 1.1.1.1  2002/02/01 22:22:47  peiyongz
 * sane_include
 *
 * Revision 1.26  2001/11/21 18:05:09  tng
 * Schema Fix: Check both XMLAttDef::Fixed and XMLAttDef::Required_And_Fixed for default values.
 *
 * Revision 1.25  2001/11/21 14:30:13  knoaman
 * Fix for UPA checking.
 *
 * Revision 1.24  2001/11/20 20:32:52  knoaman
 * Bypass validating element's simple content if it's empty and element is nillable.
 *
 * Revision 1.23  2001/11/13 13:25:08  tng
 * Deprecate function XMLValidator::checkRootElement.
 *
 * Revision 1.22  2001/11/09 18:10:58  tng
 * Schema Fix: should concatenate all characters for validation.
 *
 * Revision 1.21  2001/10/23 13:35:36  tng
 * Schema fix: Resolve notation prefix to an URI.
 *
 * Revision 1.20  2001/10/12 20:44:01  tng
 * Schema Fix: Notation Uri Binding.
 *
 * Revision 1.19  2001/10/04 15:08:56  knoaman
 * Add support for circular import.
 *
 * Revision 1.18  2001/09/10 14:06:22  tng
 * Schema: AnyAttribute support in Scanner and Validator.
 *
 * Revision 1.17  2001/09/05 20:49:11  knoaman
 * Fix for complexTypes with mixed content model.
 *
 * Revision 1.16  2001/08/30 15:47:46  tng
 * Schema: xsi:type fixes
 *
 * Revision 1.15  2001/08/29 20:52:35  tng
 * Schema: xsi:type support
 *
 * Revision 1.14  2001/08/28 19:20:54  tng
 * Schema: xsi:type support
 *
 * Revision 1.13  2001/08/21 16:06:11  tng
 * Schema: Unique Particle Attribution Constraint Checking.
 *
 * Revision 1.12  2001/08/09 15:23:16  knoaman
 * add support for <anyAttribute> declaration.
 *
 * Revision 1.11  2001/07/26 17:04:11  tng
 * Schema: Process should stop after fatal error, and user throws need to be rethrown.
 *
 * Revision 1.10  2001/07/24 21:23:40  tng
 * Schema: Use DatatypeValidator for ID/IDREF/ENTITY/ENTITIES/NOTATION.
 *
 * Revision 1.9  2001/07/11 21:39:58  peiyongz
 * fix to normalizeWhiteSpace: synchronize fDatatypeBuffer with toFill.
 *
 * Revision 1.8  2001/05/17 18:14:32  tng
 * Schema Fix: if nillable, it's an error to have default value
 *
 * Revision 1.7  2001/05/11 15:17:46  tng
 * Schema: Nillable fixes.
 *
 * Revision 1.6  2001/05/11 13:27:37  tng
 * Copyright update.
 *
 * Revision 1.5  2001/05/10 17:49:42  tng
 * Schema: SchemaValidator fixes
 *
 * Revision 1.4  2001/05/03 20:34:44  tng
 * Schema: SchemaValidator update
 *
 * Revision 1.3  2001/04/19 18:17:39  tng
 * Schema: SchemaValidator update, and use QName in Content Model
 *
 * Revision 1.2  2001/03/30 16:35:19  tng
 * Schema: Whitespace normalization.
 *
 * Revision 1.1  2001/03/21 21:56:33  tng
 * Schema: Add Schema Grammar, Schema Validator, and split the DTDValidator into DTDValidator, DTDScanner, and DTDGrammar.
 *
 */

// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include <xercesc/util/Janitor.hpp>
#include <xercesc/util/KVStringPair.hpp>
#include <xercesc/framework/XMLDocumentHandler.hpp>
#include <xercesc/internal/XMLReader.hpp>
#include <xercesc/internal/XMLScanner.hpp>
#include <xercesc/validators/datatype/DatatypeValidatorFactory.hpp>
#include <xercesc/validators/datatype/InvalidDatatypeValueException.hpp>
#include <xercesc/validators/datatype/InvalidDatatypeFacetException.hpp>
#include <xercesc/validators/datatype/ListDatatypeValidator.hpp>
#include <xercesc/validators/datatype/UnionDatatypeValidator.hpp>
#include <xercesc/validators/datatype/ENTITYDatatypeValidator.hpp>
#include <xercesc/validators/datatype/IDDatatypeValidator.hpp>
#include <xercesc/validators/datatype/IDREFDatatypeValidator.hpp>
#include <xercesc/validators/schema/SchemaSymbols.hpp>
#include <xercesc/validators/schema/SchemaValidator.hpp>
#include <xercesc/validators/schema/SubstitutionGroupComparator.hpp>
#include <xercesc/validators/schema/XercesGroupInfo.hpp>
#include <xercesc/validators/schema/XSDLocator.hpp>

// ---------------------------------------------------------------------------
//  SchemaValidator: Constructors and Destructor
// ---------------------------------------------------------------------------
SchemaValidator::SchemaValidator(XMLErrorReporter* const errReporter) :

    XMLValidator(errReporter)
    , fGrammarResolver(0)
    , fSchemaGrammar(0)
    , fTrailing(false)
    , fXsiType(0)
    , fXsiTypeValidator(0)
    , fNil(false)
{
}

SchemaValidator::~SchemaValidator()
{
    delete fXsiType;
}

// ---------------------------------------------------------------------------
//  SchemaValidator: Implementation of the XMLValidator interface
// ---------------------------------------------------------------------------
int SchemaValidator::checkContent (XMLElementDecl* const elemDecl
                                 , QName** const         children
                                 , const unsigned int    childCount)
{
    //
    //  Look up the element id in our element decl pool. This will get us
    //  the element decl in our own way of looking at them.
    //
    if (!elemDecl)
        ThrowXML(RuntimeException, XMLExcepts::Val_InvalidElemId);

    //
    //  Get the content spec type of this element. This will tell us what
    //  to do to validate it.
    //
    const SchemaElementDecl::ModelTypes modelType = ((SchemaElementDecl*) elemDecl)->getModelType();

    if (modelType == SchemaElementDecl::Empty)
    {
        //
        //  We can do this one here. It cannot have any children. If it does
        //  we return 0 as the index of the first bad child.
        //
        if (childCount)
            return 0;
    }
    else if (modelType == SchemaElementDecl::Any)
    {
        // We pass no judgement on this one, anything goes
    }
    else if ((modelType == SchemaElementDecl::Mixed_Simple)
         ||  (modelType == SchemaElementDecl::Mixed_Complex)
         ||  (modelType == SchemaElementDecl::Children))
    {
        // if nillable, it's an error to have value
        // XML Schema REC: Validation Rule: Element Locally Valid (Element)
        // 3.2.1 The element information item must have no
        // character or element information item [children].
        //
        if (fNil) {
            if (childCount > 0 || XMLString::compareString(fDatatypeBuffer.getRawBuffer(), XMLUni::fgZeroLenString))
                emitError(XMLValid::NilAttrNotEmpty, elemDecl->getFullName());

        }
        else {
            // Get the element's content model or fault it in
            XMLContentModel* elemCM = elemDecl->getContentModel();

            // Ask it to validate and return its return
            unsigned int emptyNS = getScanner()->getEmptyNamespaceId();
            int result = elemCM->validateContent(children, childCount, emptyNS);
            if (result != -1) {
                result = elemCM->validateContentSpecial(children
                                                      , childCount
                                                      , emptyNS
                                                      , fGrammarResolver
                                                      , getScanner()->getURIStringPool());
            }
            return result;
        }
    }
    else if (modelType == SchemaElementDecl::Simple)
    {
        if (childCount > 0) {
            emitError(XMLValid::SimpleTypeHasChild, elemDecl->getFullName());
        } else {
            try {
                DatatypeValidator* fCurrentDV = ((SchemaElementDecl*)elemDecl)->getDatatypeValidator();
                // If there is xsi:type validator, substitute it.
                if (fXsiTypeValidator) {
                    fCurrentDV = fXsiTypeValidator;
                    fXsiTypeValidator = 0;
                }
                if (!fCurrentDV) {
                    emitError(XMLValid::NoDatatypeValidatorForSimpleType, elemDecl->getFullName());
                } else {
                    XMLCh* value = fDatatypeBuffer.getRawBuffer();
                    XMLCh* elemDefaultValue = ((SchemaElementDecl*) elemDecl)->getDefaultValue();

                    if (elemDefaultValue) {
                        // a default value was specified

                        // if nillable, it's an error to have default value
                        if (fNil)
                            emitError(XMLValid::NilAttrNotEmpty, elemDecl->getFullName());

                        if (!XMLString::compareString(value, XMLUni::fgZeroLenString)) {
                            // if this element didn't specified any value
                            // use default value
                            if (getScanner()->getDocHandler())
                                getScanner()->getDocHandler()->docCharacters(elemDefaultValue, XMLString::stringLen(elemDefaultValue), false);
                        }
                        else {
                            // this element has specified some value
                            // if the flag is FIXED, then this value must be same as default value
                            if ((((SchemaElementDecl*)elemDecl)->getMiscFlags() == SchemaSymbols::FIXED) != 0) {
                                if (fCurrentDV->compare(value, elemDefaultValue) != 0 )
                                    emitError(XMLValid::FixedDifferentFromActual, elemDecl->getFullName());
                            }

                            // if nillable, it's an error to have value
                            if (fNil)
                                emitError(XMLValid::NilAttrNotEmpty, elemDecl->getFullName());
                            else
                               fCurrentDV->validate(value);
                        }
                    }
                    else {
                        // no default value, then check nillable
                        if (!XMLString::compareString(value, XMLUni::fgZeroLenString)) {
                            if ((((SchemaElementDecl*)elemDecl)->getMiscFlags() & SchemaSymbols::NILLABLE) == 0)
                                fCurrentDV->validate(value);
                        }
                        else if (fNil) {
                            emitError(XMLValid::NilAttrNotEmpty, elemDecl->getFullName());
                        }
                        else
                            fCurrentDV->validate(value);
                    }
                }
            } catch (InvalidDatatypeValueException idve) {
                emitError (XMLValid::DatatypeError, idve.getType(), idve.getMessage());
            }
            catch (InvalidDatatypeFacetException idve) {
                emitError (XMLValid::DatatypeError, idve.getType(), idve.getMessage());
            }
            catch (...) {
                emitError(XMLValid::GenericError);
                throw;
            }
        }
    }
     else
    {
        ThrowXML(RuntimeException, XMLExcepts::CM_UnknownCMType);
    }

    fDatatypeBuffer.reset();
    fNil = false;
    fTrailing=false;

    // Went ok, so return success
    return -1;
}

void SchemaValidator::faultInAttr (XMLAttr&    toFill, const XMLAttDef&  attDef)   const
{
    //
    //  At this level, we cannot set the URI id. So we just set it to zero
    //  and leave it at that. The scanner, who called us, will look at the
    //  prefix we stored (if any), resolve it, and store the URL id if any.
    //
    SchemaAttDef* schemaAttDef = (SchemaAttDef*) &attDef;
    QName* attName = schemaAttDef->getAttName();

    toFill.set
    (
          attName->getURI()
        , attName->getLocalPart()
        , attName->getPrefix()
        , schemaAttDef->getValue()
        , schemaAttDef->getType()
    );
}

void SchemaValidator::reset()
{
    fTrailing = false;
    delete fXsiType;
    fXsiType = 0;
    fXsiTypeValidator = 0;
    fNil = false;
    fDatatypeBuffer.reset();
}

bool SchemaValidator::requiresNamespaces() const
{
    return true;
}

void SchemaValidator::validateAttrValue (const   XMLAttDef* attDef
                                       , const XMLCh* const attrValue)
{
    //
    //  Get quick refs to lot of the stuff in the passed objects in
    //  order to simplify the code below, which will reference them very
    //  often.
    //
    XMLAttDef::AttTypes            type      = attDef->getType();
    const XMLAttDef::DefAttTypes   defType   = attDef->getDefaultType();
    const XMLCh* const             fullName  = attDef->getFullName();

    //
    //  If the default type is fixed, then make sure the passed value maps
    //  to the fixed value.
    //
    if (defType == XMLAttDef::Fixed || defType == XMLAttDef::Required_And_Fixed)
    {
        const XMLCh* const valueText = attDef->getValue();
        if (XMLString::compareString(attrValue, valueText))
            emitError(XMLValid::NotSameAsFixedValue, fullName, attrValue, valueText);
    }

    // An empty string cannot be valid for non_CDATA any of the other types
    if (!attrValue[0] && type != XMLAttDef::Simple)
    {
        emitError(XMLValid::InvalidEmptyAttValue, fullName);
        return;
    }

    DatatypeValidator* attDefDV = ((SchemaAttDef*) attDef)->getDatatypeValidator();
    if (!attDefDV) {
        emitError(XMLValid::NoDatatypeValidatorForAttribute, fullName);
    }
    else {
        try {
            DatatypeValidator::ValidatorType attDefDVType = attDefDV->getType();

            // set up the entitydeclpool in ENTITYDatatypeValidator
            // and the idreflist in ID/IDREFDatatypeValidator

            if (attDefDVType == DatatypeValidator::List) {
                DatatypeValidator* itemDTV = ((ListDatatypeValidator*)attDefDV)->getItemTypeDTV();
                DatatypeValidator::ValidatorType itemDTVType = itemDTV->getType();
                if (itemDTVType == DatatypeValidator::ENTITY)
                    ((ENTITYDatatypeValidator*)itemDTV)->setEntityDeclPool(getScanner()->getEntityDeclPool());
                else if (itemDTVType == DatatypeValidator::ID)
                    ((IDDatatypeValidator*)itemDTV)->setIDRefList(getScanner()->getIDRefList());
                else if (itemDTVType == DatatypeValidator::IDREF)
                    ((IDREFDatatypeValidator*)itemDTV)->setIDRefList(getScanner()->getIDRefList());
            }
            else if (attDefDVType == DatatypeValidator::Union) {
                RefVectorOf<DatatypeValidator>* memberDTV = ((UnionDatatypeValidator*)attDefDV)->getMemberTypeValidators();
                unsigned int memberTypeNumber = memberDTV->size();
                for ( unsigned int memberIndex = 0; memberIndex < memberTypeNumber; ++memberIndex)
                {
                    DatatypeValidator::ValidatorType memberDTVType = memberDTV->elementAt(memberIndex)->getType();
                    if (memberDTVType == DatatypeValidator::ENTITY)
                        ((ENTITYDatatypeValidator*)memberDTV->elementAt(memberIndex))->setEntityDeclPool(getScanner()->getEntityDeclPool());
                    else if (memberDTVType == DatatypeValidator::ID)
                        ((IDDatatypeValidator*)memberDTV->elementAt(memberIndex))->setIDRefList(getScanner()->getIDRefList());
                    else if (memberDTVType == DatatypeValidator::IDREF)
                        ((IDREFDatatypeValidator*)memberDTV->elementAt(memberIndex))->setIDRefList(getScanner()->getIDRefList());
                }
            }
            else if (attDefDVType == DatatypeValidator::ENTITY)
                ((ENTITYDatatypeValidator*)attDefDV)->setEntityDeclPool(getScanner()->getEntityDeclPool());
            else if (attDefDVType == DatatypeValidator::ID)
                ((IDDatatypeValidator*)attDefDV)->setIDRefList(getScanner()->getIDRefList());
            else if (attDefDVType == DatatypeValidator::IDREF)
                ((IDREFDatatypeValidator*)attDefDV)->setIDRefList(getScanner()->getIDRefList());

            // now validate the attribute value
            // if notation, need to bind URI to notation first
            if (attDefDVType == DatatypeValidator::NOTATION)
            {
                //
                //  Make sure that this value maps to one of the
                //  notation values in the enumList parameter. We don't have to
                //  look it up in the notation pool (if a notation) because we
                //  will look up the enumerated values themselves. If they are in
                //  the notation pool (after the Grammar is parsed), then obviously
                //  this value will be legal since it matches one of them.
                //
                XMLBuffer nameBuf(XMLString::stringLen(attrValue)+1);
                XMLBuffer prefixBuf(XMLString::stringLen(attrValue)+1);
                XMLBuffer notationBuf;
                unsigned int uriId = getScanner()->resolveQName(attrValue, nameBuf, prefixBuf, ElemStack::Mode_Element);
                notationBuf.set(getScanner()->getURIText(uriId));
                notationBuf.append(chColon);
                notationBuf.append(nameBuf.getRawBuffer());

                attDefDV->validate(notationBuf.getRawBuffer());
            }
            else
                attDefDV->validate(attrValue);
        } catch (InvalidDatatypeValueException idve) {
            emitError (XMLValid::DatatypeError, idve.getType(), idve.getMessage());
        }
        catch (InvalidDatatypeFacetException idve) {
            emitError (XMLValid::DatatypeError, idve.getType(), idve.getMessage());
        }
        catch (...) {
            emitError(XMLValid::GenericError);
            throw;
        }
    }
    fDatatypeBuffer.reset();
    fTrailing = false;
}

void SchemaValidator::validateElement(const   XMLElementDecl*  elemDef)
{
    if (fXsiType) {
        // handle "xsi:type" right here
        unsigned int uri = fXsiType->getURI();
        const XMLCh* localPart = fXsiType->getLocalPart();

        if (uri != XMLElementDecl::fgInvalidElemId &&
            uri != XMLElementDecl::fgPCDataElemId &&
            uri != XMLContentModel::gEpsilonFakeId &&
            uri != XMLContentModel::gEOCFakeId) {
            // retrieve Grammar for the uri
            const XMLCh* uriStr = getScanner()->getURIText(uri);
            SchemaGrammar* sGrammar = (SchemaGrammar*) fGrammarResolver->getGrammar(uriStr);

            if (!sGrammar) {

                // Check built-in simple types
                if (!XMLString::compareString(uriStr, SchemaSymbols::fgURI_SCHEMAFORSCHEMA)) {

                    fXsiTypeValidator = fGrammarResolver->getDatatypeRegistry()->getDatatypeValidator(localPart);

                    if (!fXsiTypeValidator)
                        emitError(XMLValid::BadXsiType, fXsiType->getRawName());
                    else {
                        DatatypeValidator* ancestorValidator = ((SchemaElementDecl*)elemDef)->getDatatypeValidator();
                        if (ancestorValidator && !ancestorValidator->isSubstitutableBy(fXsiTypeValidator)) {
                            // the type is not derived from ancestor
                            emitError(XMLValid::NonDerivedXsiType, fXsiType->getRawName(), elemDef->getFullName());
                        }
                        else {
                            // the type is derived from ancestor
                            if (((SchemaElementDecl*)elemDef)->getBlockSet() == SchemaSymbols::RESTRICTION)
                                emitError(XMLValid::NoSubforBlock, fXsiType->getRawName(), elemDef->getFullName());
                            if (elemDef->hasAttDefs()) {
                                // if we have an attribute but xsi:type's type is simple, we have a problem...
                                emitError(XMLValid::NonDerivedXsiType, fXsiType->getRawName(), elemDef->getFullName());
                            }
                        }
                    }
                }
                else {
                    // Grammar not found
                    emitError(XMLValid::GrammarNotFound, uriStr);
                }
            }
            else if (sGrammar->getGrammarType() != Grammar::SchemaGrammarType) {
                emitError(XMLValid::GrammarNotFound, uriStr);
            }
            else {
                // retrieve complexType registry and DatatypeValidator registry
                RefHashTableOf<ComplexTypeInfo>* complexTypeRegistry = sGrammar->getComplexTypeRegistry();
                DatatypeValidatorFactory* dataTypeReg = fGrammarResolver->getDatatypeRegistry();

                if (!complexTypeRegistry || !dataTypeReg)
                    emitError(XMLValid::BadXsiType, fXsiType->getRawName());
                else {
                    // retrieve the typeInfo specified in xsi:type
                    XMLBuffer aBuffer;
                    aBuffer.set(uriStr);
                    aBuffer.append(chComma);
                    aBuffer.append(localPart);
                    ComplexTypeInfo* typeInfo = complexTypeRegistry->get(aBuffer.getRawBuffer());

                    if (typeInfo) {
                        // typeInfo is found
                        bool error = false;

                        if (typeInfo->getAbstract()) {
                            emitError(XMLValid::NoAbstractInXsiType, aBuffer.getRawBuffer());
                            error = true;
                        }

                        ComplexTypeInfo* destType = ((SchemaElementDecl*)elemDef)->getComplexTypeInfo();
                        ComplexTypeInfo* tempType = typeInfo;
                        if (destType) {
                            while (tempType) {
                                if (!XMLString::compareString(tempType->getTypeName(), destType->getTypeName()))
                                    break;
                                tempType = tempType->getBaseComplexTypeInfo();
                            }
                            if (!tempType) {
                                emitError(XMLValid::NonDerivedXsiType, fXsiType->getRawName(), elemDef->getFullName());
                                error = true;
                            }
                            else {
                                int derivationMethod = typeInfo->getDerivedBy();
                                if ((((SchemaElementDecl*)elemDef)->getBlockSet() & derivationMethod) != 0) {
                                    emitError(XMLValid::NoSubforBlock, fXsiType->getRawName(), elemDef->getFullName());
                                    error = true;
                                }
                            }
                        }
                        else {
                            // if the original type is a simple type, check derivation ok.
                            DatatypeValidator* ancestorValidator = ((SchemaElementDecl*)elemDef)->getDatatypeValidator();
                            if (ancestorValidator && !ancestorValidator->isSubstitutableBy(fXsiTypeValidator)) {
                                // the type is not derived from ancestor
                                emitError(XMLValid::NonDerivedXsiType, fXsiType->getRawName(), elemDef->getFullName());
                                error = true;
                            }
                        }

                        if (!error)
                            ((SchemaElementDecl*)elemDef)->setXsiComplexTypeInfo(typeInfo);
                    }
                    else {
                        // typeInfo not found
                        if (!XMLString::compareString(uriStr, SchemaSymbols::fgURI_SCHEMAFORSCHEMA))
                            fXsiTypeValidator = dataTypeReg->getDatatypeValidator(localPart);
                        else
                            fXsiTypeValidator = dataTypeReg->getDatatypeValidator(aBuffer.getRawBuffer());

                        if (!fXsiTypeValidator)
                            emitError(XMLValid::BadXsiType, fXsiType->getRawName());
                        else {
                            DatatypeValidator* ancestorValidator = ((SchemaElementDecl*)elemDef)->getDatatypeValidator();
                            if (ancestorValidator && !ancestorValidator->isSubstitutableBy(fXsiTypeValidator)) {
                                // the type is not derived from ancestor
                                emitError(XMLValid::NonDerivedXsiType, fXsiType->getRawName(), elemDef->getFullName());
                            }
                            else {
                                // the type is derived from ancestor
                                if (((SchemaElementDecl*)elemDef)->getBlockSet() == SchemaSymbols::RESTRICTION)
                                    emitError(XMLValid::NoSubforBlock, fXsiType->getRawName(), elemDef->getFullName());
                                if (elemDef->hasAttDefs()) {
                                    // if we have an attribute but xsi:type's type is simple, we have a problem...
                                    emitError(XMLValid::NonDerivedXsiType, fXsiType->getRawName(), elemDef->getFullName());
                                }
                            }

                        }
                    }
                }
            }
        }
        delete fXsiType;
        fXsiType = 0;
    }
    else {
        //
        // xsi:type was not specified...
        // If the corresponding type is abstract, detect an error
        //
        ComplexTypeInfo* typeInfo = ((SchemaElementDecl*)elemDef)->getComplexTypeInfo();

        if (typeInfo) {
            if (typeInfo->getAbstract()) {
                emitError(XMLValid::NoUseAbstractType, elemDef->getFullName());
            }
        }
    }

    //
    // Check whether this element is abstract.  If so, an error
    //
    int miscFlags = ((SchemaElementDecl*)elemDef)->getMiscFlags();
    if ((miscFlags & SchemaSymbols::ABSTRACT) != 0) {
        emitError(XMLValid::NoDirectUseAbstractElement, elemDef->getFullName());
    }

    //
    // Check whether this element allows Nillable
    //
    if (fNil && (miscFlags & SchemaSymbols::NILLABLE) == 0 ) {
        fNil = false;
        emitError(XMLValid::NillNotAllowed, elemDef->getFullName());
    }

    fDatatypeBuffer.reset();
    fTrailing = false;
}

void SchemaValidator::preContentValidation(bool reuseGrammar)
{
    //  Lets go through all the grammar in the GrammarResolver
    //    and validate those that has not been validated yet
    //
    //  Lets enumerate all of the elements in the element decl pool
    //    and put out an error for any that did not get declared.
    //    We also check all of the attributes as well.
    //
    //  And enumerate all the complextype info in the grammar
    //    and do Unique Particle Attribution Checking

    RefHashTableOfEnumerator<Grammar> grammarEnum = fGrammarResolver->getGrammarEnumerator();
    while (grammarEnum.hasMoreElements())
    {
        SchemaGrammar& sGrammar = (SchemaGrammar&) grammarEnum.nextElement();
        if (sGrammar.getGrammarType() != Grammar::SchemaGrammarType || sGrammar.getUPAChecked())
             continue;

        sGrammar.setUPAChecked(true);

        RefHash3KeysIdPoolEnumerator<SchemaElementDecl> elemEnum = sGrammar.getElemEnumerator();

        while (elemEnum.hasMoreElements())
        {
            SchemaElementDecl& curElem = elemEnum.nextElement();

            //  First check if declared or not
            //
            //  See if this element decl was ever marked as declared. If
            //  not, then put out an error. In some cases its just
            //  a warning, such as being referenced in a content model.
            //
            const SchemaElementDecl::CreateReasons reason = curElem.getCreateReason();

            if (reason != XMLElementDecl::Declared)
            {
                if (reason == XMLElementDecl::AttList)
                {
                    getScanner()->emitError
                    (
                        XMLErrs::UndeclaredElemInAttList
                        , curElem.getFullName()
                    );
                }
                 else if (reason == XMLElementDecl::AsRootElem)
                {
                    emitError
                    (
                        XMLValid::UndeclaredElemInDocType
                        , curElem.getFullName()
                    );
                }
                 else if (reason == XMLElementDecl::InContentModel)
                {
                    getScanner()->emitError
                    (
                        XMLErrs::UndeclaredElemInCM
                        , curElem.getFullName()
                    );
                }
                else
                {
                }
            }

            //
            //  Then check all of the attributes of the current element.
            //  We check for:
            //
            //  1) Multiple ID attributes
            //  2) That all of the default values of attributes are
            //      valid for their type.
            //  3) That for any notation types, that their lists
            //      of possible values refer to declared notations.
            //
            if (curElem.hasAttDefs()) {
                XMLAttDefList& attDefList = curElem.getAttDefList();
                bool seenId = false;
                while (attDefList.hasMoreElements())
                {
                    const XMLAttDef& curAttDef = attDefList.nextElement();

                    if (curAttDef.getType() == XMLAttDef::ID)
                    {
                        if (seenId)
                        {
                            emitError
                            (
                                XMLValid::MultipleIdAttrs
                                , curElem.getFullName()
                            );
                            break;
                        }

                        seenId = true;
                    }
                     else if (curAttDef.getType() == XMLAttDef::Notation)
                    {
                        //
                        //  We need to verify that all of its possible values
                        //  (in the enum list) refer to valid notations.
                        //
                        XMLCh* list = XMLString::replicate(curAttDef.getEnumeration());
                        ArrayJanitor<XMLCh> janList(list);

                        //
                        //  Search forward for a space or a null. If a null,
                        //  we are done. If a space, cap it and look it up.
                        //
                        bool    breakFlag = false;
                        XMLCh*  listPtr = list;
                        XMLCh*  lastPtr = listPtr;
                        while (true)
                        {
                            while (*listPtr && (*listPtr != chSpace))
                                listPtr++;

                            //
                            //  If at the end, indicate we need to break after
                            //  this one. Else, cap it off here.
                            //
                            if (!*listPtr)
                                breakFlag = true;
                            else
                                *listPtr = chNull;

                            if (!sGrammar.getNotationDecl(lastPtr))
                            {
                                emitError
                                (
                                    XMLValid::UnknownNotRefAttr
                                    , curAttDef.getFullName()
                                    , lastPtr
                                );
                            }

                            // Break out if we hit the end last time
                            if (breakFlag)
                                break;

                            // Else move upwards and try again
                            listPtr++;
                            lastPtr = listPtr;
                        }
                    }

                    // If it has a default/fixed value, then validate it
                    if (curAttDef.getValue())
                    {
                        validateAttrValue
                        (
                            &curAttDef
                            , curAttDef.getValue()
                        );
                    }
                }
            }
        }

        //  For each complex type info, check the Unique Particle Attribution
        if (getScanner()->getValidationSchemaFullChecking()) {
            RefHashTableOf<ComplexTypeInfo>* complexTypeRegistry = sGrammar.getComplexTypeRegistry();

            RefHashTableOfEnumerator<ComplexTypeInfo> complexTypeEnum(complexTypeRegistry);
            while (complexTypeEnum.hasMoreElements())
            {
                ComplexTypeInfo& curTypeInfo = complexTypeEnum.nextElement();
                curTypeInfo.checkUniqueParticleAttribution(&sGrammar, fGrammarResolver, getScanner()->getURIStringPool(), this);
                checkParticleDerivation(&sGrammar, &curTypeInfo);
            }

            RefHashTableOf<XercesGroupInfo>* groupInfoRegistry = sGrammar.getGroupInfoRegistry();
            RefHashTableOfEnumerator<XercesGroupInfo> groupEnum(groupInfoRegistry);

            while (groupEnum.hasMoreElements()) {

                XercesGroupInfo& curGroup = groupEnum.nextElement();
                XercesGroupInfo* baseGroup = curGroup.getBaseGroup();

                if (baseGroup) {
                    try {
                        checkParticleDerivationOk(&sGrammar, curGroup.getContentSpec(), curGroup.getScope(),
                                                  baseGroup->getContentSpec(), baseGroup->getScope());
                    }
                    catch (const XMLException& excep) {
                        fSchemaErrorReporter.emitError(XMLErrs::DisplayErrorMessage, XMLUni::fgXMLErrDomain, curGroup.getLocator(), excep.getMessage());
					}
                }
            }
        }
    }
}

void SchemaValidator::postParseValidation()
{
    //
    //  At this time, there is nothing to do here. The scanner itself handles
    //  ID/IDREF validation, since that is the same no matter what kind of
    //  validator.
    //
}

// ---------------------------------------------------------------------------
//  SchemaValidator: Validator method
// ---------------------------------------------------------------------------
// Do Schema Normalization depends on the WhiteSpace Facet
// preserve : No normalization is done
// replace  : All occurrences of #x9 (tab), #xA (linefeed) and #xD (carriage return)
//            are replaced with #x20 (space).
// collapse : Subsequent to the replacements specified above under replace,
//            contiguous sequences of #x20s are collapsed to a single #x20,
//            and initial and/or final #x20s are deleted.
//
void SchemaValidator::normalizeWhiteSpace(DatatypeValidator* dV, const XMLCh* const value, XMLBuffer& toFill)
{
    short fWhiteSpace = DatatypeValidator::PRESERVE;
    if (dV)
        fWhiteSpace = dV->getWSFacet();

    enum States
    {
        InWhitespace
        , InContent
    };

    States curState = InContent;
    toFill.reset();

    //
    //  Loop through the chars of the source value and normalize it according
    //  to the whitespace facet
    //
    bool firstNonWS = false;
    XMLCh nextCh;
    const XMLCh* srcPtr = value;

    if ((fWhiteSpace==DatatypeValidator::COLLAPSE) && fTrailing)
        toFill.append(chSpace);

    while (*srcPtr)
    {
        nextCh = *srcPtr;

        if (fWhiteSpace == DatatypeValidator::PRESERVE)
        {
            // do nothing
        }
        else if (fWhiteSpace == DatatypeValidator::REPLACE)
        {
            if (XMLReader::isWhitespace(nextCh))
                nextCh = chSpace;
        }
        else // COLLAPSE case
        {
            if (curState == InWhitespace)
            {
                if (!XMLReader::isWhitespace(nextCh))
                {
                    if (firstNonWS)
                        toFill.append(chSpace);
                    curState = InContent;
                    firstNonWS = true;
                }
                 else
                {
                    srcPtr++;
                    continue;
                }
            }
             else if (curState == InContent)
            {
                if (XMLReader::isWhitespace(nextCh))
                {
                    curState = InWhitespace;
                    srcPtr++;
                    continue;
                }
                firstNonWS = true;
            }
        }
        // Add this char to the target buffer
        toFill.append(nextCh);

        // stored the content for validation later
        //fDatatypeBuffer.append(nextCh);

        // And move up to the next character in the source
        srcPtr++;
    }
    srcPtr--;
    nextCh = *srcPtr;
    if (XMLReader::isWhitespace(nextCh))
        fTrailing = true;

    fDatatypeBuffer.append(toFill.getRawBuffer());
}


// ---------------------------------------------------------------------------
//  SchemaValidator: Particle Derivation Checking
// ---------------------------------------------------------------------------
void SchemaValidator::checkParticleDerivation(SchemaGrammar* const currentGrammar,
                                              const ComplexTypeInfo* const curTypeInfo) {

    ComplexTypeInfo* baseTypeInfo = 0;
    ContentSpecNode* curSpecNode = 0;

    if (curTypeInfo->getDerivedBy() == SchemaSymbols::RESTRICTION
        && ((baseTypeInfo = curTypeInfo->getBaseComplexTypeInfo()) != 0)
        && ((curSpecNode = curTypeInfo->getContentSpec()) != 0)) {

        try {
            checkParticleDerivationOk(currentGrammar, curSpecNode,
                                      curTypeInfo->getScopeDefined(),
                                      baseTypeInfo->getContentSpec(),
                                      baseTypeInfo->getScopeDefined(), baseTypeInfo);
        }
        catch (const XMLException& excep) {
            fSchemaErrorReporter.emitError(XMLErrs::DisplayErrorMessage, XMLUni::fgXMLErrDomain, curTypeInfo->getLocator(), excep.getMessage());
        }
    }
}

void SchemaValidator::checkParticleDerivationOk(SchemaGrammar* const aGrammar,
                                                ContentSpecNode* const curNode,
                                                const int derivedScope,
                                                ContentSpecNode* const baseNode,
                                                const int baseScope,
                                                const ComplexTypeInfo* const baseInfo) {

    // Check for pointless occurrences of all, choice, sequence.  The result is
    // the contentspec which is not pointless. If the result is a non-pointless
    // group, Vector is filled  in with the children of interest
    if (!curNode || !baseNode)
        return;

    ContentSpecNode* curSpecNode = curNode;
    ContentSpecNode* baseSpecNode = baseNode;
    ValueVectorOf<ContentSpecNode*> curVector(8);
    ValueVectorOf<ContentSpecNode*> baseVector(8);
    ContentSpecNode::NodeTypes curNodeType = curSpecNode->getType();
    ContentSpecNode::NodeTypes baseNodeType = baseSpecNode->getType();

    if (curNodeType == ContentSpecNode::Sequence ||
        curNodeType == ContentSpecNode::Choice ||
        curNodeType == ContentSpecNode::All) {
        curSpecNode = checkForPointlessOccurrences(curSpecNode, curNodeType, &curVector);
    }

    if (baseNodeType == ContentSpecNode::Sequence ||
        baseNodeType == ContentSpecNode::Choice ||
        baseNodeType == ContentSpecNode::All) {
        baseSpecNode = checkForPointlessOccurrences(baseSpecNode, baseNodeType, &baseVector);
    }

    curNodeType = curSpecNode->getType();
    baseNodeType = baseSpecNode->getType();

    switch (curNodeType & 0x0f) {
    case ContentSpecNode::Leaf:
        {
            switch (baseNodeType & 0x0f) {
            case ContentSpecNode::Leaf:
                {
                    checkNameAndTypeOK(aGrammar, curSpecNode, derivedScope, baseSpecNode, baseScope, baseInfo);
                    return;
                }
            case ContentSpecNode::Any:
            case ContentSpecNode::Any_Other:
            case ContentSpecNode::Any_NS:
                {
                    checkNSCompat(curSpecNode, baseSpecNode);
                    return;
                }
            case ContentSpecNode::Choice:
            case ContentSpecNode::Sequence:
            case ContentSpecNode::All:
                {
                    checkRecurseAsIfGroup(aGrammar, curSpecNode, derivedScope,
                                          baseSpecNode, baseScope, &baseVector, baseInfo);
                    return;
                }
            default:
                {
                    ThrowXML(RuntimeException, XMLExcepts::PD_InvalidContentType);
                }
            }		
        }
    case ContentSpecNode::Any:
    case ContentSpecNode::Any_Other:
    case ContentSpecNode::Any_NS:
        {
            switch (baseNodeType & 0x0f) {
            case ContentSpecNode::Any:
            case ContentSpecNode::Any_Other:
            case ContentSpecNode::Any_NS:
                {
                     checkNSSubset(curSpecNode, baseSpecNode);
                     return;
                }
            case ContentSpecNode::Choice:
            case ContentSpecNode::Sequence:
            case ContentSpecNode::All:
            case ContentSpecNode::Leaf:
                {
                    ThrowXML(RuntimeException, XMLExcepts::PD_ForbiddenRes1);
                }
            default:
                {
                    ThrowXML(RuntimeException, XMLExcepts::PD_InvalidContentType);
                }
            }
        }
    case ContentSpecNode::All:
        {
            switch (baseNodeType & 0x0f) {
            case ContentSpecNode::Any:
            case ContentSpecNode::Any_Other:
            case ContentSpecNode::Any_NS:
                {
                    checkNSRecurseCheckCardinality(aGrammar, curSpecNode, &curVector, derivedScope, baseSpecNode);
                    return;
                }
            case ContentSpecNode::All:
                {
                    checkRecurse(aGrammar, curSpecNode, derivedScope, &curVector,
                                 baseSpecNode, baseScope, &baseVector, baseInfo);
                    return;
                }
            case ContentSpecNode::Choice:
            case ContentSpecNode::Sequence:
            case ContentSpecNode::Leaf:
                {
                    ThrowXML(RuntimeException, XMLExcepts::PD_ForbiddenRes2);
                }
            default:
                {
                    ThrowXML(RuntimeException, XMLExcepts::PD_InvalidContentType);
                }
            }
        }
    case ContentSpecNode::Choice:
        {
            switch (baseNodeType & 0x0f) {
            case ContentSpecNode::Any:
            case ContentSpecNode::Any_Other:
            case ContentSpecNode::Any_NS:
                {
                    checkNSRecurseCheckCardinality(aGrammar, curSpecNode, &curVector, derivedScope, baseSpecNode);
                    return;
                }
            case ContentSpecNode::Choice:
                {
                    checkRecurse(aGrammar, curSpecNode, derivedScope, &curVector,
                                 baseSpecNode, baseScope, &baseVector, baseInfo, true);
                    return;
                }
            case ContentSpecNode::All:
            case ContentSpecNode::Sequence:
            case ContentSpecNode::Leaf:
                {
                    ThrowXML(RuntimeException, XMLExcepts::PD_ForbiddenRes3);
                }
            default:
                {
                    ThrowXML(RuntimeException, XMLExcepts::PD_InvalidContentType);
                }
            }
        }
    case ContentSpecNode::Sequence:
        {
            switch (baseNodeType & 0x0f) {
            case ContentSpecNode::Any:
            case ContentSpecNode::Any_Other:
            case ContentSpecNode::Any_NS:
                {
                    checkNSRecurseCheckCardinality(aGrammar, curSpecNode, &curVector, derivedScope, baseSpecNode);
                    return;
                }
            case ContentSpecNode::All:
                {
                    checkRecurseUnordered(aGrammar, curSpecNode, &curVector, derivedScope,
                                          baseSpecNode, &baseVector, baseScope, baseInfo);
                    return;
                }
            case ContentSpecNode::Sequence:
                {
                    checkRecurse(aGrammar, curSpecNode, derivedScope, &curVector,
                                 baseSpecNode, baseScope, &baseVector, baseInfo);
                    return;
                }
            case ContentSpecNode::Choice:
                {
                    checkMapAndSum(aGrammar, curSpecNode, &curVector, derivedScope,
                                   baseSpecNode, &baseVector, baseScope, baseInfo);
                    return;
                }
            case ContentSpecNode::Leaf:
                {
                    ThrowXML(RuntimeException, XMLExcepts::PD_ForbiddenRes4);
                }
            default:
                {
                    ThrowXML(RuntimeException, XMLExcepts::PD_InvalidContentType);
                }
            }
        }
    }
}

ContentSpecNode*
SchemaValidator::checkForPointlessOccurrences(ContentSpecNode* const specNode,
                                              const ContentSpecNode::NodeTypes nodeType,
                                              ValueVectorOf<ContentSpecNode*>* const nodes) {

    ContentSpecNode* rightNode = specNode->getSecond();
    int min = specNode->getMinOccurs();
    int max = specNode->getMaxOccurs();

    if (!rightNode) {

         gatherChildren(nodeType, specNode->getFirst(), nodes);

         if (nodes->size() == 1 && min == 1 && max == 1) {
            return nodes->elementAt(0);
        }

        return specNode;
    }

    gatherChildren(nodeType, specNode->getFirst(), nodes);
    gatherChildren(nodeType, rightNode, nodes);

    return specNode;
}

void SchemaValidator::gatherChildren(const ContentSpecNode::NodeTypes parentNodeType,
                                    ContentSpecNode* const specNode,
                                    ValueVectorOf<ContentSpecNode*>* const nodes) {

    if (!specNode) {
        return;
    }

    int min = specNode->getMinOccurs();
    int max = specNode->getMaxOccurs();
    ContentSpecNode::NodeTypes nodeType = specNode->getType();
    ContentSpecNode* rightNode = specNode->getSecond();

    if (nodeType == ContentSpecNode::Leaf ||
        (nodeType & 0x0f) == ContentSpecNode::Any ||
        (nodeType & 0x0f) == ContentSpecNode::Any_NS ||
        (nodeType & 0x0f) == ContentSpecNode::Any_Other) {
        nodes->addElement(specNode);
    }
    else if (min !=1 || max != 1) {
        nodes->addElement(specNode);
    }
    else if (!rightNode) {
        gatherChildren(nodeType, specNode->getFirst(), nodes);
    }
    else if (parentNodeType == nodeType) {

        gatherChildren(nodeType, specNode->getFirst(), nodes);
        gatherChildren(nodeType, rightNode, nodes);
    }
    else {
        nodes->addElement(specNode);
    }
}

void
SchemaValidator::checkNSCompat(const ContentSpecNode* const derivedSpecNode,
                               const ContentSpecNode* const baseSpecNode) {

    // check Occurrence ranges
    if (!isOccurrenceRangeOK(derivedSpecNode->getMinOccurs(), derivedSpecNode->getMaxOccurs(),
                             baseSpecNode->getMinOccurs(), baseSpecNode->getMaxOccurs())) {
        ThrowXML1(RuntimeException, XMLExcepts::PD_OccurRangeE,
                  derivedSpecNode->getElement()->getLocalPart());
    }

    // check wildcard subset
    if (!wildcardEltAllowsNamespace(baseSpecNode, derivedSpecNode->getElement()->getURI())) {
        ThrowXML1(RuntimeException, XMLExcepts::PD_NSCompat1,
                  derivedSpecNode->getElement()->getLocalPart());
    }
}

bool
SchemaValidator::wildcardEltAllowsNamespace(const ContentSpecNode* const baseSpecNode,
                                            const unsigned int derivedURI) {

    ContentSpecNode::NodeTypes nodeType = baseSpecNode->getType();

    if ((nodeType & 0x0f) == ContentSpecNode::Any) {
        return true;
    }

    unsigned int baseURI = baseSpecNode->getElement()->getURI();

    if ((nodeType & 0x0f) == ContentSpecNode::Any_NS) {
        if (derivedURI == baseURI) {
           return true;
        }
    }
    else { // must be ANY_OTHER
        if (derivedURI != baseURI && derivedURI != getScanner()->getEmptyNamespaceId()) {
            return true;
        }
    }

    return false;
}

void
SchemaValidator::checkNameAndTypeOK(SchemaGrammar* const currentGrammar,
                                    const ContentSpecNode* const derivedSpecNode,
                                    const int derivedScope,
                                    const ContentSpecNode* const baseSpecNode,
                                    const int baseScope,
                                    const ComplexTypeInfo* const baseInfo) {

    unsigned int derivedURI = derivedSpecNode->getElement()->getURI();
    unsigned int baseURI = baseSpecNode->getElement()->getURI();
    const XMLCh* derivedName = derivedSpecNode->getElement()->getLocalPart();
    const XMLCh* baseName = baseSpecNode->getElement()->getLocalPart();

    if (XMLString::compareString(derivedName, baseName) || derivedURI != baseURI) {
        ThrowXML(RuntimeException, XMLExcepts::PD_NameTypeOK1);
    }

	// case of mixed complex types with attributes only
    if (derivedURI == XMLElementDecl::fgPCDataElemId) {
        return;
    }

    if (!isOccurrenceRangeOK(derivedSpecNode->getMinOccurs(), derivedSpecNode->getMaxOccurs(),
                             baseSpecNode->getMinOccurs(), baseSpecNode->getMaxOccurs())) {
        ThrowXML1(RuntimeException, XMLExcepts::PD_OccurRangeE, derivedName);
    }

    SchemaGrammar* aGrammar = currentGrammar;
    const XMLCh* schemaURI = getScanner()->getURIStringPool()->getValueForId(derivedURI);

    if (derivedURI != getScanner()->getEmptyNamespaceId()) {
        aGrammar= (SchemaGrammar*) fGrammarResolver->getGrammar(schemaURI);
    }

    if (!aGrammar) { //something is wrong
        return;
    }

    SchemaElementDecl* derivedElemDecl = findElement(derivedScope, derivedURI, derivedName, aGrammar);

    if (!derivedElemDecl) {
        return;
    }

    SchemaElementDecl* baseElemDecl =
        findElement(baseScope, baseURI, baseName, aGrammar, baseInfo);

    if (!baseElemDecl) {
        return;
    }

    int derivedFlags = derivedElemDecl->getMiscFlags();
    int baseFlags = baseElemDecl->getMiscFlags();

    if (((baseFlags & SchemaSymbols::NILLABLE) == 0) &&
		((derivedFlags & SchemaSymbols::NILLABLE) != 0)) {
        ThrowXML1(RuntimeException, XMLExcepts::PD_NameTypeOK2, derivedName);
    }

    const XMLCh* derivedDefVal = derivedElemDecl->getDefaultValue();
    const XMLCh* baseDefVal = baseElemDecl->getDefaultValue();

    if (baseDefVal && (baseFlags & SchemaSymbols::FIXED) != 0 &&
        ((derivedFlags & SchemaSymbols::FIXED) == 0 ||
         XMLString::compareString(derivedDefVal, baseDefVal))) {
        ThrowXML1(RuntimeException, XMLExcepts::PD_NameTypeOK3, derivedName);
    }

    int derivedBlockSet = derivedElemDecl->getBlockSet();
    int baseBlockSet = baseElemDecl->getBlockSet();

    if ((derivedBlockSet & baseBlockSet) != baseBlockSet) {
        ThrowXML1(RuntimeException, XMLExcepts::PD_NameTypeOK4, derivedName);
    }

    // check identity constraints
    checkICRestriction(derivedElemDecl, baseElemDecl, derivedName, baseName);

    // check that the derived element's type is derived from the base's.
    checkTypesOK(derivedElemDecl, baseElemDecl, derivedName);
}

SchemaElementDecl*
SchemaValidator::findElement(const int scope, const unsigned int uriIndex,
                             const XMLCh* const name,
                             SchemaGrammar* const grammar,
                             const ComplexTypeInfo* const typeInfo) {

    // check for element at given scope first
    SchemaElementDecl* elemDecl = (SchemaElementDecl*) grammar->getElemDecl(uriIndex, name, 0, scope);

    // if not found, check at global scope
    if (!elemDecl) {

        elemDecl = (SchemaElementDecl*)
            grammar->getElemDecl(uriIndex, name, 0, Grammar::TOP_LEVEL_SCOPE);

        // if still not found, and base is specified, look it up there
        if (!elemDecl && typeInfo) {

            const ComplexTypeInfo* baseInfo = typeInfo;

            while (baseInfo) {

                elemDecl = (SchemaElementDecl*)
                    grammar->getElemDecl(uriIndex, name, 0, baseInfo->getScopeDefined());

                if (elemDecl) {
                   break;
                }

                baseInfo = baseInfo->getBaseComplexTypeInfo();
            }
        }
    }

    return elemDecl;
}

void
SchemaValidator::checkICRestriction(const SchemaElementDecl* const derivedElemDecl,
                                   const SchemaElementDecl* const baseElemDecl,
                                   const XMLCh* const derivedElemName,
                                   const XMLCh* const baseElemName) {

    // REVIST - need to get more clarification
    unsigned int derivedICCount = derivedElemDecl->getIdentityConstraintCount();
    unsigned int baseICCount = baseElemDecl->getIdentityConstraintCount();

    if (derivedICCount > baseICCount) {
        ThrowXML2(RuntimeException, XMLExcepts::PD_NameTypeOK6, derivedElemName, baseElemName);
    }

    for (unsigned int i=0; i < derivedICCount; i++) {

        bool found = false;
        IdentityConstraint* ic= derivedElemDecl->getIdentityConstraintAt(i);

        for (unsigned int j=0; j < baseICCount; j++) {
            if (*ic == *(baseElemDecl->getIdentityConstraintAt(j))) {

                found = true;
                break;
            }
        }

        if (!found) {
            ThrowXML2(RuntimeException, XMLExcepts::PD_NameTypeOK7, derivedElemName, baseElemName);
        }
    }
}

void
SchemaValidator::checkTypesOK(const SchemaElementDecl* const derivedElemDecl,
                              const SchemaElementDecl* const baseElemDecl,
                              const XMLCh* const derivedElemName) {

    SchemaElementDecl::ModelTypes baseType = baseElemDecl->getModelType();

    if (baseType == SchemaElementDecl::Any) {
        return;
    }

    ComplexTypeInfo* rInfo = derivedElemDecl->getComplexTypeInfo();
    ComplexTypeInfo* bInfo = baseElemDecl->getComplexTypeInfo();

    if (derivedElemDecl->getModelType() == SchemaElementDecl::Simple) {

        if (baseType != SchemaElementDecl::Simple) {
            ThrowXML1(RuntimeException, XMLExcepts::PD_NameTypeOK5, derivedElemName);
        }

        if (!rInfo) {

            DatatypeValidator* bDV = baseElemDecl->getDatatypeValidator();

            if (bInfo || bDV == 0 ||
				!bDV->isSubstitutableBy(derivedElemDecl->getDatatypeValidator())) {
                ThrowXML1(RuntimeException, XMLExcepts::PD_NameTypeOK5, derivedElemName);
            }

            return;
        }
    }

    if (rInfo == bInfo)
        return;

    for (; rInfo && rInfo != bInfo; rInfo = rInfo->getBaseComplexTypeInfo()) {
        if (rInfo->getDerivedBy() != SchemaSymbols::RESTRICTION) {

            rInfo = 0;
            break;
        }
    }

    if (!rInfo) {
        ThrowXML1(RuntimeException, XMLExcepts::PD_NameTypeOK5, derivedElemName);
    }
}

void
SchemaValidator::checkRecurseAsIfGroup(SchemaGrammar* const currentGrammar,
                                       ContentSpecNode* const derivedSpecNode,
                                       const int derivedScope,
                                       const ContentSpecNode* const baseSpecNode,
                                       const int baseScope,
                                       ValueVectorOf<ContentSpecNode*>* const baseNodes,
                                       const ComplexTypeInfo* const baseInfo) {

    ContentSpecNode::NodeTypes baseType = baseSpecNode->getType();
    ValueVectorOf<ContentSpecNode*> derivedNodes(1);
    bool toLax = false;

    //Treat the element as if it were in a group of the same variety as base
    ContentSpecNode derivedGroupNode(baseType, derivedSpecNode, 0, false);

    derivedNodes.addElement(derivedSpecNode);

    if (baseSpecNode->getType() == ContentSpecNode::Choice) {
        toLax = true;
    }

    checkRecurse(currentGrammar, &derivedGroupNode, derivedScope, &derivedNodes,
                 baseSpecNode, baseScope, baseNodes, baseInfo, toLax);
}

void
SchemaValidator::checkRecurse(SchemaGrammar* const currentGrammar,
                              const ContentSpecNode* const derivedSpecNode,
                              const int derivedScope,
                              ValueVectorOf<ContentSpecNode*>* const derivedNodes,
                              const ContentSpecNode* const baseSpecNode,
                              const int baseScope,
                              ValueVectorOf<ContentSpecNode*>* const baseNodes,
                              const ComplexTypeInfo* const baseInfo,
                              const bool toLax) {

    if (!isOccurrenceRangeOK(derivedSpecNode->getMinOccurs(), derivedSpecNode->getMaxOccurs(),
                             baseSpecNode->getMinOccurs(), baseSpecNode->getMaxOccurs())) {
        ThrowXML(RuntimeException, XMLExcepts::PD_Recurse1);
    }

    // check for mapping of children
    XMLExcepts::Codes codeToThrow = XMLExcepts::NoError;
    unsigned int count1= derivedNodes->size();
    unsigned int count2= baseNodes->size();
    unsigned int current = 0;

    for (unsigned int i=0; i<count1; i++) {

        bool matched = false;

        for (unsigned int j = current; j < count2; j++) {

            ContentSpecNode* baseNode = baseNodes->elementAt(j);
            current++;

            try {

                checkParticleDerivationOk(currentGrammar, derivedNodes->elementAt(i),
                                          derivedScope, baseNode, baseScope, baseInfo);
                matched = true;
                break;
            }
            catch(const XMLException&) {
                if (!toLax && baseNode->getMinTotalRange()) {
                    break;
                }
            }
        }

        // did not find a match
        if (!matched) {

            codeToThrow = XMLExcepts::PD_Recurse2;
            break;
        }
    }

    // Now, see if there are some elements in the base we didn't match up
    // in case of Sequence or All
    if (!toLax && codeToThrow == XMLExcepts::NoError) {
        for (unsigned int j = current; j < count2; j++) {
            if (baseNodes->elementAt(j)->getMinTotalRange()) { //!emptiable

                codeToThrow =  XMLExcepts::PD_Recurse2;
                break;
            }
        }
    }

    if (codeToThrow != XMLExcepts::NoError) {
        ThrowXML(RuntimeException, codeToThrow);
    }
}

void SchemaValidator::checkNSSubset(const ContentSpecNode* const derivedSpecNode,
                                    const ContentSpecNode* const baseSpecNode) {

    // check Occurrence ranges
    if (!isOccurrenceRangeOK(derivedSpecNode->getMinOccurs(), derivedSpecNode->getMaxOccurs(),
                             baseSpecNode->getMinOccurs(), baseSpecNode->getMaxOccurs())) {
        ThrowXML(RuntimeException, XMLExcepts::PD_NSSubset1);
    }

    if (!isWildCardEltSubset(derivedSpecNode, baseSpecNode)) {
        ThrowXML(RuntimeException, XMLExcepts::PD_NSSubset2);
    }
}

bool
SchemaValidator::isWildCardEltSubset(const ContentSpecNode* const derivedSpecNode,
                                     const ContentSpecNode* const baseSpecNode) {

    ContentSpecNode::NodeTypes baseType = baseSpecNode->getType();

    if ((baseType & 0x0f) == ContentSpecNode::Any) {
        return true;
    }

    ContentSpecNode::NodeTypes derivedType = derivedSpecNode->getType();
    unsigned int baseURI = baseSpecNode->getElement()->getURI();
    unsigned int derivedURI = derivedSpecNode->getElement()->getURI();

    if (((derivedType & 0x0f) == ContentSpecNode::Any_Other) &&
        ((baseType & 0x0f) == ContentSpecNode::Any_Other) &&
        baseURI == derivedURI) {
        return true;
    }

    if ((derivedType & 0x0f) == ContentSpecNode::Any_NS) {

        if (((baseType & 0x0f) == ContentSpecNode::Any_NS) &&
            baseURI == derivedURI) {
            return true;
        }

        if (((baseType & 0x0f) == ContentSpecNode::Any_Other) &&
            baseURI != derivedURI) {
            return true;
        }
    }

    return false;
}

void
SchemaValidator::checkNSRecurseCheckCardinality(SchemaGrammar* const currentGrammar,
                                                const ContentSpecNode* const derivedSpecNode,
                                                ValueVectorOf<ContentSpecNode*>* const derivedNodes,
                                                const int derivedScope,
                                                ContentSpecNode* const baseSpecNode) {

    // Implement total range check
    int derivedMin = derivedSpecNode->getMinTotalRange();
    int derivedMax = derivedSpecNode->getMaxTotalRange();

    // check Occurrence ranges
    if (!isOccurrenceRangeOK(derivedMin, derivedMax, baseSpecNode->getMinOccurs(),
                              baseSpecNode->getMaxOccurs())) {
        ThrowXML(RuntimeException, XMLExcepts::PD_NSRecurseCheckCardinality1);
    }

    // Check that each member of the group is a valid restriction of the wildcard
    unsigned int nodesCount = derivedNodes->size();

    for (unsigned int i = 0; i < nodesCount; i++) {
        checkParticleDerivationOk(currentGrammar, derivedNodes->elementAt(i), derivedScope, baseSpecNode, -1);
    }
}

void
SchemaValidator::checkRecurseUnordered(SchemaGrammar* const currentGrammar,
                                       const ContentSpecNode* const derivedSpecNode,
                                       ValueVectorOf<ContentSpecNode*>* const derivedNodes,
                                       const int derivedScope,
                                       ContentSpecNode* const baseSpecNode,
                                       ValueVectorOf<ContentSpecNode*>* const baseNodes,
                                       const int baseScope,
                                       const ComplexTypeInfo* const baseInfo) {

    // check Occurrence ranges
    if (!isOccurrenceRangeOK(derivedSpecNode->getMinOccurs(), derivedSpecNode->getMaxOccurs(),
                             baseSpecNode->getMinOccurs(), baseSpecNode->getMaxOccurs())) {
        ThrowXML(RuntimeException, XMLExcepts::PD_Recurse1);
    }

    XMLExcepts::Codes  codeToThrow = XMLExcepts::NoError;
    unsigned int       derivedCount= derivedNodes->size();
    unsigned int       baseCount = baseNodes->size();
    bool*              foundIt = new bool[baseCount];
    ArrayJanitor<bool> janFoundIt(foundIt);

    for (unsigned k=0; k < baseCount; k++) {
        foundIt[k] = false;
    }

    // check for mapping of children
    for (unsigned int i = 0; i < derivedCount; i++) {

        ContentSpecNode* derivedNode = derivedNodes->elementAt(i);
        bool matched = false;

        for (unsigned int j = 0; j < baseCount; j++) {

            try {

                checkParticleDerivationOk(currentGrammar, derivedNode, derivedScope,
                                          baseNodes->elementAt(j), baseScope, baseInfo);

                if (foundIt[j]) {
                    break;
                }

                foundIt[j] = true;
                matched = true;
                break;
            }
            catch (const XMLException&) {
            }
        }

        // didn't find a match.
        if (!matched) {

	        codeToThrow = XMLExcepts::PD_RecurseUnordered;
            break;
        }
    }

    // For all unmapped particles in base, check to see it it's emptiable or not
    if (codeToThrow == XMLExcepts::NoError) {
        for (unsigned int j=0; j < baseCount; j++) {
            if (!foundIt[j] && baseNodes->elementAt(j)->getMinTotalRange()) {

	            codeToThrow = XMLExcepts::PD_RecurseUnordered;
                break;
            }
        }
    }

    if (codeToThrow != XMLExcepts::NoError) {
        ThrowXML(RuntimeException, codeToThrow);
    }
}

void
SchemaValidator::checkMapAndSum(SchemaGrammar* const currentGrammar,
                                const ContentSpecNode* const derivedSpecNode,
                                ValueVectorOf<ContentSpecNode*>* const derivedNodes,
                                const int derivedScope,
                                ContentSpecNode* const baseSpecNode,
                                ValueVectorOf<ContentSpecNode*>* const baseNodes,
                                const int baseScope,
                                const ComplexTypeInfo* const baseInfo) {

    // check Occurrence ranges
    int derivedCount = derivedNodes->size();
    int baseCount = baseNodes->size();
    int derivedMin = derivedSpecNode->getMinOccurs() * derivedCount;
    int derivedMax = derivedSpecNode->getMaxOccurs();

    if (derivedMax != SchemaSymbols::UNBOUNDED) {
        derivedMax *= derivedCount;
    }

    if (!isOccurrenceRangeOK(derivedMin, derivedMax, baseSpecNode->getMinOccurs(),
                             baseSpecNode->getMaxOccurs())) {
        ThrowXML(RuntimeException, XMLExcepts::PD_Recurse1);
    }

    // check for mapping of children
    for (int i = 0; i < derivedCount; i++) {

        ContentSpecNode* derivedNode = derivedNodes->elementAt(i);
        bool matched = false;

        for (int j = 0; j < baseCount && !matched; j++) {

            try {

                checkParticleDerivationOk(currentGrammar, derivedNode, derivedScope,
                                          baseNodes->elementAt(j), baseScope, baseInfo);
                matched = true;
            }
            catch (const XMLException&) {
            }
        }

        // didn't find a match.
        if (!matched) {
	        ThrowXML(RuntimeException, XMLExcepts::PD_MapAndSum);
        }
    }

}

