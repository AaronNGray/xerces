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

// xml4com.cpp : Implementation of DLL Exports.
// Note: Proxy/Stub Information
//      To merge the proxy/stub code into the object DLL, add the file
//      dlldatax.c to the project.  Make sure precompiled headers
//      are turned off for this file, and add _MERGE_PROXYSTUB to the
//      defines for the project.
//
//      If you are not running WinNT4.0 or Win95 with DCOM, then you
//      need to remove the following define from dlldatax.c
//      #define _WIN32_WINNT 0x0400
//
//      Further, if you are running MIDL without /Oicf switch, you also
//      need to remove the following define from dlldatax.c.
//      #define USE_STUBLESS_PROXY
//
//      Modify the custom build rule for xml4com.idl by adding the following
//      files to the Outputs.
//          xml4com_p.c
//          dlldata.c
//      To build a separate proxy/stub DLL,
//      run nmake -f xml4comps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>

#include <xercesc/util/PlatformUtils.hpp>
#include "xml4com.h"
#include <xercesc/dom/DOMException.hpp>

//
//
//    These were extracted from an identifier definition file
//       generated by compiling MSXML.IDL using the MIDL compiler
//        (and removing CLSID_DOMDocument, CLSID_XMLHttpRequest, et al)
//
const IID IID_IXMLDOMImplementation = {0x2933BF8F,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMNode = {0x2933BF80,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMDocumentFragment = {0x3efaa413,0x272f,0x11d2,{0x83,0x6f,0x00,0x00,0xf8,0x7a,0x77,0x82}};


const IID IID_IXMLDOMDocument = {0x2933BF81,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMNodeList = {0x2933BF82,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMNamedNodeMap = {0x2933BF83,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMCharacterData = {0x2933BF84,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMAttribute = {0x2933BF85,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMElement = {0x2933BF86,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMText = {0x2933BF87,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMComment = {0x2933BF88,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMProcessingInstruction = {0x2933BF89,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMCDATASection = {0x2933BF8A,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMDocumentType = {0x2933BF8B,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMNotation = {0x2933BF8C,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMEntity = {0x2933BF8D,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMEntityReference = {0x2933BF8E,0x7B36,0x11d2,{0xB2,0x0E,0x00,0xC0,0x4F,0x98,0x3E,0x60}};


const IID IID_IXMLDOMParseError = {0x3efaa426,0x272f,0x11d2,{0x83,0x6f,0x00,0x00,0xf8,0x7a,0x77,0x82}};


const IID IID_IXTLRuntime = {0x3efaa425,0x272f,0x11d2,{0x83,0x6f,0x00,0x00,0xf8,0x7a,0x77,0x82}};


const IID DIID_XMLDOMDocumentEvents = {0x3efaa427,0x272f,0x11d2,{0x83,0x6f,0x00,0x00,0xf8,0x7a,0x77,0x82}};



const IID IID_IXMLHttpRequest = {0xED8C108D,0x4349,0x11D2,{0x91,0xA4,0x00,0xC0,0x4F,0x79,0x69,0xE8}};


const IID IID_IXMLDSOControl = {0x310afa62,0x0575,0x11d2,{0x9c,0xa9,0x00,0x60,0xb0,0xec,0x3d,0x39}};


const IID IID_IXMLElementCollection = {0x65725580,0x9B5D,0x11d0,{0x9B,0xFE,0x00,0xC0,0x4F,0xC9,0x9C,0x8E}};


const IID IID_IXMLDocument = {0xF52E2B61,0x18A1,0x11d1,{0xB1,0x05,0x00,0x80,0x5F,0x49,0x91,0x6B}};


const IID IID_IXMLDocument2 = {0x2B8DE2FE,0x8D2D,0x11d1,{0xB2,0xFC,0x00,0xC0,0x4F,0xD9,0x15,0xA9}};


const IID IID_IXMLElement = {0x3F7F31AC,0xE15F,0x11d0,{0x9C,0x25,0x00,0xC0,0x4F,0xC9,0x9C,0x8E}};


const IID IID_IXMLElement2 = {0x2B8DE2FF,0x8D2D,0x11d1,{0xB2,0xFC,0x00,0xC0,0x4F,0xD9,0x15,0xA9}};


const IID IID_IXMLAttribute = {0xD4D4A0FC,0x3B73,0x11d1,{0xB2,0xB4,0x00,0xC0,0x4F,0xB9,0x25,0x96}};


const IID IID_IXMLError = {0x948C5AD3,0xC58D,0x11d0,{0x9C,0x0B,0x00,0xC0,0x4F,0xC9,0x9C,0x8E}};



//
//   This file is generated from the type library compilation
//       of xml4com.idl
//
#include "xml4com_i.c"
#include "XMLDOMDocument.h"
#include "XMLHTTPRequest.h"

#ifdef _MERGE_PROXYSTUB
extern "C" HINSTANCE hProxyDll;
#endif

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_DOMDocument, CXMLDOMDocument)
OBJECT_ENTRY(CLSID_XMLHTTPRequest, CXMLHttpRequest)
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    lpReserved;
#ifdef _MERGE_PROXYSTUB
    if (!PrxDllMain(hInstance, dwReason, lpReserved))
        return FALSE;
#endif
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_Xerces);
        DisableThreadLibraryCalls(hInstance);
		XMLPlatformUtils::Initialize();
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
        XMLPlatformUtils::Terminate();
        _Module.Term();
    }
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllCanUnloadNow() != S_OK)
        return S_FALSE;
#endif
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
        return S_OK;
#endif
    return _Module.GetClassObject(rclsid, riid, ppv);
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
    HRESULT hRes = PrxDllRegisterServer();
    if (FAILED(hRes))
        return hRes;
#endif
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
#ifdef _MERGE_PROXYSTUB
    PrxDllUnregisterServer();
#endif
    return _Module.UnregisterServer(TRUE);
}


static LPOLESTR Msgs[] =
{
	OLESTR("UNDEFINED DOM ERROR"),
	OLESTR("INDEX_SIZE_ERR"),   // INDEX_SIZE_ERR =  1
	OLESTR("DOMSTRING_SIZE_ERR"),  // DOMSTRING_SIZE_ERR =  2
	OLESTR("HIERARCHY_REQUEST_ERR"),   // HIERARCHY_REQUEST_ERR =  3
	OLESTR("WRONG_DOCUMENT_ERR"),   // WRONG_DOCUMENT_ERR =  4
	OLESTR("INVALID_CHARACTER_ERR"),   // INVALID_CHARACTER_ERR =  5
	OLESTR("NO_DATA_ALLOWED_ERR"),   // NO_DATA_ALLOWED_ERR =  6
	OLESTR("NO_MODIFICATION_ALLOWED_ERR"),   // NO_MODIFICATION_ALLOWED_ERR =  7
	OLESTR("NOT_FOUND_ERR"),   // NOT_FOUND_ERR =  8
	OLESTR("NOT_SUPPORTED_ERR"),   // NOT_SUPPORTED_ERR =  9
	OLESTR("INUSE_ATTRIBUTE_ERR"),   // INUSE_ATTRIBUTE_ERR =  10
	OLESTR("INVALID_STATE_ERR"),   // INVALID_STATE_ERR =  11
	OLESTR("SYNTAX_ERR	"),   // 	SYNTAX_ERR	 =  12
	OLESTR("INVALID_MODIFICATION_ERR"),   // 	INVALID_MODIFICATION_ERR =  13
	OLESTR("NAMESPACE_ERR"),   // 	NAMESPACE_ERR	 =  14
	OLESTR("INVALID_ACCESS_ERR") // INVALID_ACCESS_ERR   = 15
    OLESTR("VALIDATION_ERR") // VALIDATION_ERR = 16
};

//
//
//   makes an HRESULT with a code based on the DOM error code
//
HRESULT MakeHRESULT(DOMException& ex)
{
	ICreateErrorInfo* pCErr = NULL;
	HRESULT sc = CreateErrorInfo(&pCErr);
	if(SUCCEEDED(sc)) {
		const XMLCh* msg = ex.msg;
		if(msg == NULL)
		{
			if(ex.code >= DOMException::INDEX_SIZE_ERR &&
				ex.code <= DOMException::VALIDATION_ERR)
			{
				sc = pCErr->SetDescription(Msgs[ex.code]);
			}
			else
			{
				sc = pCErr->SetDescription(Msgs[0]);
			}
		}
		else
		{
			sc = pCErr->SetDescription(SysAllocString(ex.msg));
		}

		IErrorInfo* pErr = NULL;
		sc = pCErr->QueryInterface(IID_IErrorInfo,(void**) &pErr);
		if(SUCCEEDED(sc))
		{
			sc = SetErrorInfo(0,pErr);
			pErr->Release();
		}
		pCErr->Release();
	}
	return 0x80040600 + ex.code;
}



