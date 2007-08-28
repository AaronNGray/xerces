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

#if !defined(XERCESC_INCLUDE_GUARD_CYGWINTRANSSERVICE_HPP)
#define XERCESC_INCLUDE_GUARD_CYGWINTRANSSERVICE_HPP

#include <xercesc/util/TransService.hpp>
#include <xercesc/util/RefHashTableOf.hpp>
#include <windows.h>

XERCES_CPP_NAMESPACE_BEGIN

class CPMapEntry;



//---------------------------------------------------------------------------
//
//  class CygwinTransService
//
//---------------------------------------------------------------------------
class XMLUTIL_EXPORT CygwinTransService : public XMLTransService
{
public :
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    CygwinTransService();
    virtual ~CygwinTransService();


    // -----------------------------------------------------------------------
    //  Implementation of the virtual transcoding service API
    // -----------------------------------------------------------------------
    virtual int compareIString
    (
        const   XMLCh* const    comp1
        , const XMLCh* const    comp2
    );

    virtual int compareNIString
    (
        const   XMLCh* const    comp1
        , const XMLCh* const    comp2
        , const XMLSize_t       maxChars
    );

    virtual const XMLCh* getId() const;

    virtual XMLLCPTranscoder* makeNewLCPTranscoder();

    virtual bool supportsSrcOfs() const;

    virtual void upperCase(XMLCh* const toUpperCase) const;
    virtual void lowerCase(XMLCh* const toLowerCase) const;


protected :
    // -----------------------------------------------------------------------
    //  Protected virtual methods, implemented in CygwinTransService.cpp
    // -----------------------------------------------------------------------
    virtual XMLTranscoder* makeNewXMLTranscoder
    (
        const   XMLCh* const            encodingName
        ,       XMLTransService::Codes& resValue
        , const XMLSize_t               blockSize
        ,       MemoryManager* const    manager
    );

private :
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    CygwinTransService(const CygwinTransService&);
    CygwinTransService& operator=(const CygwinTransService&);

    int auxCompareString
    (
        const   XMLCh* const  comp1
        , const XMLCh* const  comp2
        , signed long         maxChars
        , const  bool         ignoreCase
    );

    static bool isAlias(const HKEY          encodingKey
                    ,       char* const     aliasBuf = 0
                    , const unsigned int    nameBufSz = 0);


    //      This is a hash table of entries which map encoding names to their
    //      Windows specific code pages. The code page allows us to create
    //      transcoders for those encodings. The encoding names come from XML
    //      files.
    //
    //      This map is shared unsynchronized among all threads of the process,
    //      which is cool since it will be read only once its initialized.

    RefHashTableOf<CPMapEntry>    *fCPMap;
};







//---------------------------------------------------------------------------
//
//  class CygwinTranscoder
//
//---------------------------------------------------------------------------

class XMLUTIL_EXPORT CygwinTranscoder : public XMLTranscoder
{
public :
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    CygwinTranscoder
    (
        const   XMLCh* const    encodingName
        , const unsigned int    winCP
        , const unsigned int    ieCP
        , const XMLSize_t       blockSize
        , MemoryManager* const  manager = XMLPlatformUtils::fgMemoryManager);
    ~CygwinTranscoder();


    // -----------------------------------------------------------------------
    //  Implementation of the virtual transcoder interface
    // -----------------------------------------------------------------------
    virtual XMLSize_t transcodeFrom
    (
        const   XMLByte* const          srcData
        , const XMLSize_t               srcCount
        ,       XMLCh* const            toFill
        , const XMLSize_t               maxChars
        ,       XMLSize_t&              bytesEaten
        ,       unsigned char* const    charSizes
    );

    virtual XMLSize_t transcodeTo
    (
        const   XMLCh* const    srcData
        , const XMLSize_t       srcCount
        ,       XMLByte* const  toFill
        , const XMLSize_t       maxBytes
        ,       XMLSize_t&      charsEaten
        , const UnRepOpts       options
    );

    virtual bool canTranscodeTo
    (
        const   unsigned int    toCheck
    )   const;


private :
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    CygwinTranscoder(const CygwinTranscoder&);
    CygwinTranscoder& operator=(const CygwinTranscoder&);


    // -----------------------------------------------------------------------
    //  Private data members
    //
    //  fIECP
    //      This is the internet explorer code page for this encoding.
    //
    //  fWinCP
    //      This is the windows code page for this encoding.
    // -----------------------------------------------------------------------
    unsigned int    fIECP;
    unsigned int    fWinCP;
};





//---------------------------------------------------------------------------
//
//  class CygwinLCPTranscoder
//
//---------------------------------------------------------------------------
class XMLUTIL_EXPORT CygwinLCPTranscoder : public XMLLCPTranscoder
{
public :
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    CygwinLCPTranscoder();
    ~CygwinLCPTranscoder();


    // -----------------------------------------------------------------------
    //  Implementation of the virtual transcoder interface
    // -----------------------------------------------------------------------
    virtual char* transcode(const XMLCh* const toTranscode,
                            MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager);

    virtual XMLCh* transcode(const char* const toTranscode,
                             MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager);


    // -----------------------------------------------------------------------
    //  DEPRECATED old transcode interface
    // -----------------------------------------------------------------------
    virtual XMLSize_t calcRequiredSize(const char* const srcText
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager);

    virtual XMLSize_t calcRequiredSize(const XMLCh* const srcText
        , MemoryManager* const manager = XMLPlatformUtils::fgMemoryManager);

    virtual bool transcode
    (
        const   char* const     toTranscode
        ,       XMLCh* const    toFill
        , const XMLSize_t       maxChars
        , MemoryManager* const  manager = XMLPlatformUtils::fgMemoryManager
    );

    virtual bool transcode
    (
        const   XMLCh* const    toTranscode
        ,       char* const     toFill
        , const XMLSize_t       maxChars
        , MemoryManager* const  manager = XMLPlatformUtils::fgMemoryManager
    );


private :
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    CygwinLCPTranscoder(const CygwinLCPTranscoder&);
    CygwinLCPTranscoder& operator=(const CygwinLCPTranscoder&);
};

XERCES_CPP_NAMESPACE_END

#endif
