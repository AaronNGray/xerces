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

#if !defined(XERCESC_INCLUDE_GUARD_CMREPEATINGLEAF_HPP)
#define XERCESC_INCLUDE_GUARD_CMREPEATINGLEAF_HPP

#include <xercesc/validators/common/CMLeaf.hpp>


XERCES_CPP_NAMESPACE_BEGIN

//
//  A compound content model leaf node which carries occurence information.
//
class CMRepeatingLeaf : public CMLeaf
{
public :
    // -----------------------------------------------------------------------
    //  Constructors
    // -----------------------------------------------------------------------
    CMRepeatingLeaf
    (
          QName* const         element
        , int                  minOccurs
        , int                  maxOccurs
        , const unsigned int   position
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );
    CMRepeatingLeaf
    (
          QName* const         element
        , int                  minOccurs
        , int                  maxOccurs
        , const unsigned int   position
        , const bool           adopt
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager
    );


    // -----------------------------------------------------------------------
    //  Getter methods
    // -----------------------------------------------------------------------
    int getMinOccurs() const;
    int getMaxOccurs() const;

    virtual bool isRepeatableLeaf() const;

private :
    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fMinOccurs
    //  fMaxOccurs
    //      The cardinality of the repeating leaf
    //
    // -----------------------------------------------------------------------
    int             fMinOccurs;
    int             fMaxOccurs;

    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    CMRepeatingLeaf(const CMRepeatingLeaf&);
    CMRepeatingLeaf& operator=(const CMRepeatingLeaf&);
};


// -----------------------------------------------------------------------
//  Constructors
// -----------------------------------------------------------------------
inline CMRepeatingLeaf::CMRepeatingLeaf(   QName* const               element
                                         , int                        minOccurs
                                         , int                        maxOccurs
                                         , const unsigned int         position
                                         ,       MemoryManager* const manager) :
    CMLeaf(element, position, manager)
    , fMinOccurs(minOccurs)
    , fMaxOccurs(maxOccurs)
{
}

inline CMRepeatingLeaf::CMRepeatingLeaf(   QName* const               element
                                         , int                        minOccurs
                                         , int                        maxOccurs
                                         , const unsigned int         position
                                         , const bool                 adopt
                                         ,       MemoryManager* const manager) :
    CMLeaf(element, position, adopt, manager)
    , fMinOccurs(minOccurs)
    , fMaxOccurs(maxOccurs)
{
}

// ---------------------------------------------------------------------------
//  Getter methods
// ---------------------------------------------------------------------------
inline int CMRepeatingLeaf::getMinOccurs() const
{
    return fMinOccurs;
}

inline int CMRepeatingLeaf::getMaxOccurs() const
{
    return fMaxOccurs;
}

inline bool CMRepeatingLeaf::isRepeatableLeaf() const
{
    return true;
}

XERCES_CPP_NAMESPACE_END

#endif
