# Microsoft Developer Studio Generated NMAKE File, Based on XercesLib.dsp
!IF "$(CFG)" == ""
CFG=XercesLib - Win32 Debug
!MESSAGE No configuration specified. Defaulting to XercesLib - Win32 Debug.
!ENDIF

!IF "$(CFG)" != "XercesLib - Win32 Release" && "$(CFG)" != "XercesLib - Win32 Debug" && "$(CFG)" != "XercesLib - Win64 Debug" && "$(CFG)" != "XercesLib - Win64 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "XercesLib.mak" CFG="XercesLib - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "XercesLib - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "XercesLib - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "XercesLib - Win64 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "XercesLib - Win64 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE
!ERROR An invalid configuration is specified.
!ENDIF

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF

!IF  "$(CFG)" == "XercesLib - Win32 Release"

OUTDIR=.\..\..\..\..\..\Build\Win32\VC6\Release
INTDIR=.\..\..\..\..\..\Build\Win32\VC6\Release\obj
# Begin Custom Macros
OutDir=.\..\..\..\..\..\Build\Win32\VC6\Release
# End Custom Macros

ALL : "$(OUTDIR)\xerces-c_2_1_0.dll"


CLEAN :
	-@erase "$(INTDIR)\AbstractDOMParser.obj"
	-@erase "$(INTDIR)\AbstractNumericFacetValidator.obj"
	-@erase "$(INTDIR)\AbstractNumericValidator.obj"
	-@erase "$(INTDIR)\AbstractStringValidator.obj"
	-@erase "$(INTDIR)\AllContentModel.obj"
	-@erase "$(INTDIR)\AnySimpleTypeDatatypeValidator.obj"
	-@erase "$(INTDIR)\AnyURIDatatypeValidator.obj"
	-@erase "$(INTDIR)\ASCIIRangeFactory.obj"
	-@erase "$(INTDIR)\AttrImpl.obj"
	-@erase "$(INTDIR)\AttrMapImpl.obj"
	-@erase "$(INTDIR)\AttrNSImpl.obj"
	-@erase "$(INTDIR)\Base64.obj"
	-@erase "$(INTDIR)\Base64BinaryDatatypeValidator.obj"
	-@erase "$(INTDIR)\BinFileInputStream.obj"
	-@erase "$(INTDIR)\BinHTTPURLInputStream.obj"
	-@erase "$(INTDIR)\BinInputStream.obj"
	-@erase "$(INTDIR)\BinMemInputStream.obj"
	-@erase "$(INTDIR)\BitSet.obj"
	-@erase "$(INTDIR)\BlockRangeFactory.obj"
	-@erase "$(INTDIR)\BMPattern.obj"
	-@erase "$(INTDIR)\BooleanDatatypeValidator.obj"
	-@erase "$(INTDIR)\CDATASectionImpl.obj"
	-@erase "$(INTDIR)\CharacterDataImpl.obj"
	-@erase "$(INTDIR)\CharToken.obj"
	-@erase "$(INTDIR)\ChildNode.obj"
	-@erase "$(INTDIR)\ClosureToken.obj"
	-@erase "$(INTDIR)\CMAny.obj"
	-@erase "$(INTDIR)\CMBinaryOp.obj"
	-@erase "$(INTDIR)\CMUnaryOp.obj"
	-@erase "$(INTDIR)\CommentImpl.obj"
	-@erase "$(INTDIR)\ComplexTypeInfo.obj"
	-@erase "$(INTDIR)\ConcatToken.obj"
	-@erase "$(INTDIR)\ConditionToken.obj"
	-@erase "$(INTDIR)\ContentLeafNameTypeVector.obj"
	-@erase "$(INTDIR)\ContentSpecNode.obj"
	-@erase "$(INTDIR)\DatatypeValidator.obj"
	-@erase "$(INTDIR)\DatatypeValidatorFactory.obj"
	-@erase "$(INTDIR)\DateDatatypeValidator.obj"
	-@erase "$(INTDIR)\DateTimeDatatypeValidator.obj"
	-@erase "$(INTDIR)\DateTimeValidator.obj"
	-@erase "$(INTDIR)\DayDatatypeValidator.obj"
	-@erase "$(INTDIR)\DecimalDatatypeValidator.obj"
	-@erase "$(INTDIR)\DeepNodeListImpl.obj"
	-@erase "$(INTDIR)\DFAContentModel.obj"
	-@erase "$(INTDIR)\DocumentFragmentImpl.obj"
	-@erase "$(INTDIR)\DocumentImpl.obj"
	-@erase "$(INTDIR)\DocumentTypeImpl.obj"
	-@erase "$(INTDIR)\DOM_Attr.obj"
	-@erase "$(INTDIR)\DOM_CDATASection.obj"
	-@erase "$(INTDIR)\DOM_CharacterData.obj"
	-@erase "$(INTDIR)\DOM_Comment.obj"
	-@erase "$(INTDIR)\DOM_Document.obj"
	-@erase "$(INTDIR)\DOM_DocumentFragment.obj"
	-@erase "$(INTDIR)\DOM_DocumentType.obj"
	-@erase "$(INTDIR)\DOM_DOMException.obj"
	-@erase "$(INTDIR)\DOM_DOMImplementation.obj"
	-@erase "$(INTDIR)\DOM_Element.obj"
	-@erase "$(INTDIR)\DOM_Entity.obj"
	-@erase "$(INTDIR)\DOM_EntityReference.obj"
	-@erase "$(INTDIR)\DOM_NamedNodeMap.obj"
	-@erase "$(INTDIR)\DOM_Node.obj"
	-@erase "$(INTDIR)\DOM_NodeFilter.obj"
	-@erase "$(INTDIR)\DOM_NodeIterator.obj"
	-@erase "$(INTDIR)\DOM_NodeList.obj"
	-@erase "$(INTDIR)\DOM_Notation.obj"
	-@erase "$(INTDIR)\DOM_ProcessingInstruction.obj"
	-@erase "$(INTDIR)\DOM_Range.obj"
	-@erase "$(INTDIR)\DOM_RangeException.obj"
	-@erase "$(INTDIR)\DOM_Text.obj"
	-@erase "$(INTDIR)\DOM_TreeWalker.obj"
	-@erase "$(INTDIR)\DOM_XMLDecl.obj"
	-@erase "$(INTDIR)\DOMAttrImpl.obj"
	-@erase "$(INTDIR)\DOMAttrMapImpl.obj"
	-@erase "$(INTDIR)\DOMAttrNSImpl.obj"
	-@erase "$(INTDIR)\DOMBuilderImpl.obj"
	-@erase "$(INTDIR)\DOMCDATASectionImpl.obj"
	-@erase "$(INTDIR)\DOMCharacterDataImpl.obj"
	-@erase "$(INTDIR)\DOMChildNode.obj"
	-@erase "$(INTDIR)\DOMCommentImpl.obj"
	-@erase "$(INTDIR)\DOMDeepNodeListImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentFragmentImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentTypeImpl.obj"
	-@erase "$(INTDIR)\DOMElementImpl.obj"
	-@erase "$(INTDIR)\DOMElementNSImpl.obj"
	-@erase "$(INTDIR)\DOMEntityImpl.obj"
	-@erase "$(INTDIR)\DOMEntityReferenceImpl.obj"
	-@erase "$(INTDIR)\DOMErrorImpl.obj"
	-@erase "$(INTDIR)\DOMException.obj"
	-@erase "$(INTDIR)\DOMImplementationImpl.obj"
	-@erase "$(INTDIR)\DOMImplementationRegistry.obj"
	-@erase "$(INTDIR)\DOMLocatorImpl.obj"
	-@erase "$(INTDIR)\DomMemDebug.obj"
	-@erase "$(INTDIR)\DOMNamedNodeMapImpl.obj"
	-@erase "$(INTDIR)\DOMNodeIDMap.obj"
	-@erase "$(INTDIR)\DOMNodeImpl.obj"
	-@erase "$(INTDIR)\DOMNodeIteratorImpl.obj"
	-@erase "$(INTDIR)\DOMNodeListImpl.obj"
	-@erase "$(INTDIR)\DOMNodeVector.obj"
	-@erase "$(INTDIR)\DOMNotationImpl.obj"
	-@erase "$(INTDIR)\DOMParentNode.obj"
	-@erase "$(INTDIR)\DOMParser.obj"
	-@erase "$(INTDIR)\DOMProcessingInstructionImpl.obj"
	-@erase "$(INTDIR)\DOMRangeException.obj"
	-@erase "$(INTDIR)\DOMRangeImpl.obj"
	-@erase "$(INTDIR)\DOMString.obj"
	-@erase "$(INTDIR)\DOMStringPool.obj"
	-@erase "$(INTDIR)\DOMTextImpl.obj"
	-@erase "$(INTDIR)\DOMTreeWalkerImpl.obj"
	-@erase "$(INTDIR)\DOMWriterImpl.obj"
	-@erase "$(INTDIR)\DoubleDatatypeValidator.obj"
	-@erase "$(INTDIR)\DStringPool.obj"
	-@erase "$(INTDIR)\DTDAttDef.obj"
	-@erase "$(INTDIR)\DTDAttDefList.obj"
	-@erase "$(INTDIR)\DTDElementDecl.obj"
	-@erase "$(INTDIR)\DTDGrammar.obj"
	-@erase "$(INTDIR)\DTDScanner.obj"
	-@erase "$(INTDIR)\DTDValidator.obj"
	-@erase "$(INTDIR)\Dummy.obj"
	-@erase "$(INTDIR)\DurationDatatypeValidator.obj"
	-@erase "$(INTDIR)\ElementDefinitionImpl.obj"
	-@erase "$(INTDIR)\ElementImpl.obj"
	-@erase "$(INTDIR)\ElementNSImpl.obj"
	-@erase "$(INTDIR)\ElemStack.obj"
	-@erase "$(INTDIR)\EncodingValidator.obj"
	-@erase "$(INTDIR)\ENTITYDatatypeValidator.obj"
	-@erase "$(INTDIR)\EntityImpl.obj"
	-@erase "$(INTDIR)\EntityReferenceImpl.obj"
	-@erase "$(INTDIR)\FieldActivator.obj"
	-@erase "$(INTDIR)\FieldValueMap.obj"
	-@erase "$(INTDIR)\FloatDatatypeValidator.obj"
	-@erase "$(INTDIR)\GeneralAttributeCheck.obj"
	-@erase "$(INTDIR)\GrammarResolver.obj"
	-@erase "$(INTDIR)\HashPtr.obj"
	-@erase "$(INTDIR)\HashXMLCh.obj"
	-@erase "$(INTDIR)\HeaderDummy.obj"
	-@erase "$(INTDIR)\HexBin.obj"
	-@erase "$(INTDIR)\HexBinaryDatatypeValidator.obj"
	-@erase "$(INTDIR)\IC_Field.obj"
	-@erase "$(INTDIR)\IC_Key.obj"
	-@erase "$(INTDIR)\IC_KeyRef.obj"
	-@erase "$(INTDIR)\IC_Selector.obj"
	-@erase "$(INTDIR)\IC_Unique.obj"
	-@erase "$(INTDIR)\IDDatatypeValidator.obj"
	-@erase "$(INTDIR)\IdentityConstraint.obj"
	-@erase "$(INTDIR)\IDREFDatatypeValidator.obj"
	-@erase "$(INTDIR)\InputSource.obj"
	-@erase "$(INTDIR)\KVStringPair.obj"
	-@erase "$(INTDIR)\ListDatatypeValidator.obj"
	-@erase "$(INTDIR)\LocalFileFormatTarget.obj"
	-@erase "$(INTDIR)\LocalFileInputSource.obj"
	-@erase "$(INTDIR)\Match.obj"
	-@erase "$(INTDIR)\MemBufFormatTarget.obj"
	-@erase "$(INTDIR)\MemBufInputSource.obj"
	-@erase "$(INTDIR)\MixedContentModel.obj"
	-@erase "$(INTDIR)\ModifierToken.obj"
	-@erase "$(INTDIR)\MonthDatatypeValidator.obj"
	-@erase "$(INTDIR)\MonthDayDatatypeValidator.obj"
	-@erase "$(INTDIR)\Mutexes.obj"
	-@erase "$(INTDIR)\NameDatatypeValidator.obj"
	-@erase "$(INTDIR)\NamedNodeMapImpl.obj"
	-@erase "$(INTDIR)\NamespaceScope.obj"
	-@erase "$(INTDIR)\NCNameDatatypeValidator.obj"
	-@erase "$(INTDIR)\NodeIDMap.obj"
	-@erase "$(INTDIR)\NodeImpl.obj"
	-@erase "$(INTDIR)\NodeIteratorImpl.obj"
	-@erase "$(INTDIR)\NodeListImpl.obj"
	-@erase "$(INTDIR)\NodeVector.obj"
	-@erase "$(INTDIR)\NOTATIONDatatypeValidator.obj"
	-@erase "$(INTDIR)\NotationImpl.obj"
	-@erase "$(INTDIR)\Op.obj"
	-@erase "$(INTDIR)\OpFactory.obj"
	-@erase "$(INTDIR)\ParentNode.obj"
	-@erase "$(INTDIR)\ParenToken.obj"
	-@erase "$(INTDIR)\ParserForXMLSchema.obj"
	-@erase "$(INTDIR)\PlatformUtils.obj"
	-@erase "$(INTDIR)\ProcessingInstructionImpl.obj"
	-@erase "$(INTDIR)\QName.obj"
	-@erase "$(INTDIR)\QNameDatatypeValidator.obj"
	-@erase "$(INTDIR)\RangeFactory.obj"
	-@erase "$(INTDIR)\RangeImpl.obj"
	-@erase "$(INTDIR)\RangeToken.obj"
	-@erase "$(INTDIR)\RangeTokenMap.obj"
	-@erase "$(INTDIR)\ReaderMgr.obj"
	-@erase "$(INTDIR)\RefCountedImpl.obj"
	-@erase "$(INTDIR)\RegularExpression.obj"
	-@erase "$(INTDIR)\RegxParser.obj"
	-@erase "$(INTDIR)\RegxUtil.obj"
	-@erase "$(INTDIR)\sax2Dummy.obj"
	-@erase "$(INTDIR)\SAX2XMLReaderImpl.obj"
	-@erase "$(INTDIR)\SAXException.obj"
	-@erase "$(INTDIR)\SAXParseException.obj"
	-@erase "$(INTDIR)\SAXParser.obj"
	-@erase "$(INTDIR)\SchemaAttDef.obj"
	-@erase "$(INTDIR)\SchemaAttDefList.obj"
	-@erase "$(INTDIR)\SchemaElementDecl.obj"
	-@erase "$(INTDIR)\SchemaGrammar.obj"
	-@erase "$(INTDIR)\SchemaInfo.obj"
	-@erase "$(INTDIR)\SchemaSymbols.obj"
	-@erase "$(INTDIR)\SchemaValidator.obj"
	-@erase "$(INTDIR)\SimpleContentModel.obj"
	-@erase "$(INTDIR)\StdInInputSource.obj"
	-@erase "$(INTDIR)\StdOutFormatTarget.obj"
	-@erase "$(INTDIR)\StringDatatypeValidator.obj"
	-@erase "$(INTDIR)\StringPool.obj"
	-@erase "$(INTDIR)\StringToken.obj"
	-@erase "$(INTDIR)\SubstitutionGroupComparator.obj"
	-@erase "$(INTDIR)\TextImpl.obj"
	-@erase "$(INTDIR)\TimeDatatypeValidator.obj"
	-@erase "$(INTDIR)\Token.obj"
	-@erase "$(INTDIR)\TokenFactory.obj"
	-@erase "$(INTDIR)\TransService.obj"
	-@erase "$(INTDIR)\TraverseSchema.obj"
	-@erase "$(INTDIR)\TreeWalkerImpl.obj"
	-@erase "$(INTDIR)\UnicodeRangeFactory.obj"
	-@erase "$(INTDIR)\UnionDatatypeValidator.obj"
	-@erase "$(INTDIR)\UnionToken.obj"
	-@erase "$(INTDIR)\URLInputSource.obj"
	-@erase "$(INTDIR)\ValueStore.obj"
	-@erase "$(INTDIR)\ValueStoreCache.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\VecAttributesImpl.obj"
	-@erase "$(INTDIR)\VecAttrListImpl.obj"
	-@erase "$(INTDIR)\Version.res"
	-@erase "$(INTDIR)\Win32MsgLoader.obj"
	-@erase "$(INTDIR)\Win32PlatformUtils.obj"
	-@erase "$(INTDIR)\Win32TransService.obj"
	-@erase "$(INTDIR)\WinSockNetAccessor.obj"
	-@erase "$(INTDIR)\Wrapper4DOMInputSource.obj"
	-@erase "$(INTDIR)\Wrapper4InputSource.obj"
	-@erase "$(INTDIR)\XercesAttGroupInfo.obj"
	-@erase "$(INTDIR)\XercesDOMParser.obj"
	-@erase "$(INTDIR)\XercesElementWildcard.obj"
	-@erase "$(INTDIR)\XercesGroupInfo.obj"
	-@erase "$(INTDIR)\XercesXPath.obj"
	-@erase "$(INTDIR)\XML256TableTranscoder.obj"
	-@erase "$(INTDIR)\XML88591Transcoder.obj"
	-@erase "$(INTDIR)\XMLAbstractDoubleFloat.obj"
	-@erase "$(INTDIR)\XMLASCIITranscoder.obj"
	-@erase "$(INTDIR)\XMLAttDef.obj"
	-@erase "$(INTDIR)\XMLAttr.obj"
	-@erase "$(INTDIR)\XMLBigDecimal.obj"
	-@erase "$(INTDIR)\XMLBigInteger.obj"
	-@erase "$(INTDIR)\XMLBuffer.obj"
	-@erase "$(INTDIR)\XMLBufferMgr.obj"
	-@erase "$(INTDIR)\XMLChTranscoder.obj"
	-@erase "$(INTDIR)\XMLContentModel.obj"
	-@erase "$(INTDIR)\XMLDateTime.obj"
	-@erase "$(INTDIR)\XMLDeclImpl.obj"
	-@erase "$(INTDIR)\XMLDouble.obj"
	-@erase "$(INTDIR)\XMLEBCDICTranscoder.obj"
	-@erase "$(INTDIR)\XMLElementDecl.obj"
	-@erase "$(INTDIR)\XMLEntityDecl.obj"
	-@erase "$(INTDIR)\XMLException.obj"
	-@erase "$(INTDIR)\XMLFloat.obj"
	-@erase "$(INTDIR)\XMLFormatter.obj"
	-@erase "$(INTDIR)\XMLIBM1140Transcoder.obj"
	-@erase "$(INTDIR)\XMLNotationDecl.obj"
	-@erase "$(INTDIR)\XMLMsgLoader.obj"
	-@erase "$(INTDIR)\XMLNumber.obj"
	-@erase "$(INTDIR)\XMLRangeFactory.obj"
	-@erase "$(INTDIR)\XMLReader.obj"
	-@erase "$(INTDIR)\XMLRecognizer.obj"
	-@erase "$(INTDIR)\XMLScanner.obj"
	-@erase "$(INTDIR)\XMLScanner2.obj"
	-@erase "$(INTDIR)\XMLString.obj"
	-@erase "$(INTDIR)\XMLStringTokenizer.obj"
	-@erase "$(INTDIR)\XMLUCSTranscoder.obj"
	-@erase "$(INTDIR)\XMLUni.obj"
	-@erase "$(INTDIR)\XMLUniCharacter.obj"
	-@erase "$(INTDIR)\XMLUri.obj"
	-@erase "$(INTDIR)\XMLURL.obj"
	-@erase "$(INTDIR)\XMLUTF16Transcoder.obj"
	-@erase "$(INTDIR)\XMLUTF8Transcoder.obj"
	-@erase "$(INTDIR)\XMLValidator.obj"
	-@erase "$(INTDIR)\XMLWin1252Transcoder.obj"
	-@erase "$(INTDIR)\XPathMatcher.obj"
	-@erase "$(INTDIR)\XPathMatcherStack.obj"
	-@erase "$(INTDIR)\XPathSymbols.obj"
	-@erase "$(INTDIR)\XSDDOMParser.obj"
	-@erase "$(INTDIR)\XSDElementNSImpl.obj"
	-@erase "$(INTDIR)\XSDErrorReporter.obj"
	-@erase "$(INTDIR)\XSDLocator.obj"
	-@erase "$(INTDIR)\XUtil.obj"
	-@erase "$(INTDIR)\YearDatatypeValidator.obj"
	-@erase "$(INTDIR)\YearMonthDatatypeValidator.obj"
	-@erase "$(OUTDIR)\obj\xerces-c_2_1_0.map"
	-@erase "$(OUTDIR)\xerces-c_2.exp"
	-@erase "$(OUTDIR)\xerces-c_2.lib"
	-@erase "$(OUTDIR)\xerces-c_2_1_0.dll"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=$(CPP)
CPP_PROJ=/G6 /MD /Za /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=/D "NDEBUG" /mktyplib203 /o "NUL" /win32
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Version.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/o"$(OUTDIR)\XercesLib.bsc"
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib advapi32.lib ws2_32.lib /base:"0x12000000" /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\xerces-c_2_1_0.pdb" /map:"$(INTDIR)\xerces-c_2_1_0.map" /machine:I386 /out:"$(OUTDIR)\xerces-c_2_1_0.dll" /implib:"$(OUTDIR)\xerces-c_2.lib" /version:2.0.0
LINK32_OBJS= \
	"$(INTDIR)\Win32PlatformUtils.obj" \
	"$(INTDIR)\Win32MsgLoader.obj" \
	"$(INTDIR)\Win32TransService.obj" \
	"$(INTDIR)\BinHTTPURLInputStream.obj" \
	"$(INTDIR)\WinSockNetAccessor.obj" \
	"$(INTDIR)\ASCIIRangeFactory.obj" \
	"$(INTDIR)\BlockRangeFactory.obj" \
	"$(INTDIR)\BMPattern.obj" \
	"$(INTDIR)\CharToken.obj" \
	"$(INTDIR)\ClosureToken.obj" \
	"$(INTDIR)\ConcatToken.obj" \
	"$(INTDIR)\ConditionToken.obj" \
	"$(INTDIR)\Match.obj" \
	"$(INTDIR)\ModifierToken.obj" \
	"$(INTDIR)\Op.obj" \
	"$(INTDIR)\OpFactory.obj" \
	"$(INTDIR)\ParenToken.obj" \
	"$(INTDIR)\ParserForXMLSchema.obj" \
	"$(INTDIR)\RangeFactory.obj" \
	"$(INTDIR)\RangeToken.obj" \
	"$(INTDIR)\RangeTokenMap.obj" \
	"$(INTDIR)\RegularExpression.obj" \
	"$(INTDIR)\RegxParser.obj" \
	"$(INTDIR)\RegxUtil.obj" \
	"$(INTDIR)\StringToken.obj" \
	"$(INTDIR)\Token.obj" \
	"$(INTDIR)\TokenFactory.obj" \
	"$(INTDIR)\UnicodeRangeFactory.obj" \
	"$(INTDIR)\UnionToken.obj" \
	"$(INTDIR)\XMLRangeFactory.obj" \
	"$(INTDIR)\XMLUniCharacter.obj" \
	"$(INTDIR)\Base64.obj" \
	"$(INTDIR)\BinFileInputStream.obj" \
	"$(INTDIR)\BinInputStream.obj" \
	"$(INTDIR)\BinMemInputStream.obj" \
	"$(INTDIR)\BitSet.obj" \
	"$(INTDIR)\EncodingValidator.obj" \
	"$(INTDIR)\HashPtr.obj" \
	"$(INTDIR)\HashXMLCh.obj" \
	"$(INTDIR)\HeaderDummy.obj" \
	"$(INTDIR)\HexBin.obj" \
	"$(INTDIR)\KVStringPair.obj" \
	"$(INTDIR)\Mutexes.obj" \
	"$(INTDIR)\PlatformUtils.obj" \
	"$(INTDIR)\QName.obj" \
	"$(INTDIR)\StringPool.obj" \
	"$(INTDIR)\TransService.obj" \
	"$(INTDIR)\XML256TableTranscoder.obj" \
	"$(INTDIR)\XML88591Transcoder.obj" \
	"$(INTDIR)\XMLAbstractDoubleFloat.obj" \
	"$(INTDIR)\XMLASCIITranscoder.obj" \
	"$(INTDIR)\XMLBigDecimal.obj" \
	"$(INTDIR)\XMLBigInteger.obj" \
	"$(INTDIR)\XMLChTranscoder.obj" \
	"$(INTDIR)\XMLDateTime.obj" \
	"$(INTDIR)\XMLDouble.obj" \
	"$(INTDIR)\XMLEBCDICTranscoder.obj" \
	"$(INTDIR)\XMLException.obj" \
	"$(INTDIR)\XMLFloat.obj" \
	"$(INTDIR)\XMLIBM1140Transcoder.obj" \
	"$(INTDIR)\XMLMsgLoader.obj" \
	"$(INTDIR)\XMLNumber.obj" \
	"$(INTDIR)\XMLString.obj" \
	"$(INTDIR)\XMLStringTokenizer.obj" \
	"$(INTDIR)\XMLUCSTranscoder.obj" \
	"$(INTDIR)\XMLUni.obj" \
	"$(INTDIR)\XMLUri.obj" \
	"$(INTDIR)\XMLURL.obj" \
	"$(INTDIR)\XMLUTF16Transcoder.obj" \
	"$(INTDIR)\XMLUTF8Transcoder.obj" \
	"$(INTDIR)\XMLWin1252Transcoder.obj" \
	"$(INTDIR)\LocalFileFormatTarget.obj" \
	"$(INTDIR)\LocalFileInputSource.obj" \
	"$(INTDIR)\MemBufFormatTarget.obj" \
	"$(INTDIR)\MemBufInputSource.obj" \
	"$(INTDIR)\StdInInputSource.obj" \
	"$(INTDIR)\StdOutFormatTarget.obj" \
	"$(INTDIR)\URLInputSource.obj" \
	"$(INTDIR)\Wrapper4DOMInputSource.obj" \
	"$(INTDIR)\Wrapper4InputSource.obj" \
	"$(INTDIR)\XMLAttDef.obj" \
	"$(INTDIR)\XMLAttr.obj" \
	"$(INTDIR)\XMLBuffer.obj" \
	"$(INTDIR)\XMLBufferMgr.obj" \
	"$(INTDIR)\XMLContentModel.obj" \
	"$(INTDIR)\XMLElementDecl.obj" \
	"$(INTDIR)\XMLEntityDecl.obj" \
	"$(INTDIR)\XMLFormatter.obj" \
	"$(INTDIR)\XMLNotationDecl.obj" \
	"$(INTDIR)\XMLRecognizer.obj" \
	"$(INTDIR)\XMLValidator.obj" \
	"$(INTDIR)\ElemStack.obj" \
	"$(INTDIR)\ReaderMgr.obj" \
	"$(INTDIR)\VecAttributesImpl.obj" \
	"$(INTDIR)\VecAttrListImpl.obj" \
	"$(INTDIR)\XMLReader.obj" \
	"$(INTDIR)\XMLScanner.obj" \
	"$(INTDIR)\XMLScanner2.obj" \
	"$(INTDIR)\Dummy.obj" \
	"$(INTDIR)\InputSource.obj" \
	"$(INTDIR)\SAXException.obj" \
	"$(INTDIR)\SAXParseException.obj" \
	"$(INTDIR)\AbstractDOMParser.obj" \
	"$(INTDIR)\DOMBuilderImpl.obj" \
	"$(INTDIR)\SAX2XMLReaderImpl.obj" \
	"$(INTDIR)\SAXParser.obj" \
	"$(INTDIR)\XercesDOMParser.obj" \
	"$(INTDIR)\AllContentModel.obj" \
	"$(INTDIR)\CMAny.obj" \
	"$(INTDIR)\CMBinaryOp.obj" \
	"$(INTDIR)\CMUnaryOp.obj" \
	"$(INTDIR)\ContentLeafNameTypeVector.obj" \
	"$(INTDIR)\ContentSpecNode.obj" \
	"$(INTDIR)\DFAContentModel.obj" \
	"$(INTDIR)\GrammarResolver.obj" \
	"$(INTDIR)\MixedContentModel.obj" \
	"$(INTDIR)\SimpleContentModel.obj" \
	"$(INTDIR)\AbstractNumericFacetValidator.obj" \
	"$(INTDIR)\AbstractNumericValidator.obj" \
	"$(INTDIR)\AbstractStringValidator.obj" \
	"$(INTDIR)\AnySimpleTypeDatatypeValidator.obj" \
	"$(INTDIR)\AnyURIDatatypeValidator.obj" \
	"$(INTDIR)\Base64BinaryDatatypeValidator.obj" \
	"$(INTDIR)\BooleanDatatypeValidator.obj" \
	"$(INTDIR)\DatatypeValidator.obj" \
	"$(INTDIR)\DatatypeValidatorFactory.obj" \
	"$(INTDIR)\DateDatatypeValidator.obj" \
	"$(INTDIR)\DateTimeDatatypeValidator.obj" \
	"$(INTDIR)\DateTimeValidator.obj" \
	"$(INTDIR)\DayDatatypeValidator.obj" \
	"$(INTDIR)\DecimalDatatypeValidator.obj" \
	"$(INTDIR)\DoubleDatatypeValidator.obj" \
	"$(INTDIR)\DurationDatatypeValidator.obj" \
	"$(INTDIR)\ENTITYDatatypeValidator.obj" \
	"$(INTDIR)\FloatDatatypeValidator.obj" \
	"$(INTDIR)\HexBinaryDatatypeValidator.obj" \
	"$(INTDIR)\IDDatatypeValidator.obj" \
	"$(INTDIR)\IDREFDatatypeValidator.obj" \
	"$(INTDIR)\ListDatatypeValidator.obj" \
	"$(INTDIR)\MonthDatatypeValidator.obj" \
	"$(INTDIR)\MonthDayDatatypeValidator.obj" \
	"$(INTDIR)\NameDatatypeValidator.obj" \
	"$(INTDIR)\NCNameDatatypeValidator.obj" \
	"$(INTDIR)\NOTATIONDatatypeValidator.obj" \
	"$(INTDIR)\QNameDatatypeValidator.obj" \
	"$(INTDIR)\StringDatatypeValidator.obj" \
	"$(INTDIR)\TimeDatatypeValidator.obj" \
	"$(INTDIR)\UnionDatatypeValidator.obj" \
	"$(INTDIR)\YearDatatypeValidator.obj" \
	"$(INTDIR)\YearMonthDatatypeValidator.obj" \
	"$(INTDIR)\DTDAttDef.obj" \
	"$(INTDIR)\DTDAttDefList.obj" \
	"$(INTDIR)\DTDElementDecl.obj" \
	"$(INTDIR)\DTDGrammar.obj" \
	"$(INTDIR)\DTDScanner.obj" \
	"$(INTDIR)\DTDValidator.obj" \
	"$(INTDIR)\FieldActivator.obj" \
	"$(INTDIR)\FieldValueMap.obj" \
	"$(INTDIR)\IC_Field.obj" \
	"$(INTDIR)\IC_Key.obj" \
	"$(INTDIR)\IC_KeyRef.obj" \
	"$(INTDIR)\IC_Selector.obj" \
	"$(INTDIR)\IC_Unique.obj" \
	"$(INTDIR)\IdentityConstraint.obj" \
	"$(INTDIR)\ValueStore.obj" \
	"$(INTDIR)\ValueStoreCache.obj" \
	"$(INTDIR)\XercesXPath.obj" \
	"$(INTDIR)\XPathMatcher.obj" \
	"$(INTDIR)\XPathMatcherStack.obj" \
	"$(INTDIR)\XPathSymbols.obj" \
	"$(INTDIR)\ComplexTypeInfo.obj" \
	"$(INTDIR)\GeneralAttributeCheck.obj" \
	"$(INTDIR)\NamespaceScope.obj" \
	"$(INTDIR)\SchemaAttDef.obj" \
	"$(INTDIR)\SchemaAttDefList.obj" \
	"$(INTDIR)\SchemaElementDecl.obj" \
	"$(INTDIR)\SchemaGrammar.obj" \
	"$(INTDIR)\SchemaInfo.obj" \
	"$(INTDIR)\SchemaSymbols.obj" \
	"$(INTDIR)\SchemaValidator.obj" \
	"$(INTDIR)\SubstitutionGroupComparator.obj" \
	"$(INTDIR)\TraverseSchema.obj" \
	"$(INTDIR)\XercesAttGroupInfo.obj" \
	"$(INTDIR)\XercesElementWildcard.obj" \
	"$(INTDIR)\XercesGroupInfo.obj" \
	"$(INTDIR)\XSDDOMParser.obj" \
	"$(INTDIR)\XSDErrorReporter.obj" \
	"$(INTDIR)\XSDLocator.obj" \
	"$(INTDIR)\XUtil.obj" \
	"$(INTDIR)\sax2Dummy.obj" \
	"$(INTDIR)\DOMAttrImpl.obj" \
	"$(INTDIR)\DOMAttrMapImpl.obj" \
	"$(INTDIR)\DOMAttrNSImpl.obj" \
	"$(INTDIR)\DOMCDATASectionImpl.obj" \
	"$(INTDIR)\DOMCharacterDataImpl.obj" \
	"$(INTDIR)\DOMChildNode.obj" \
	"$(INTDIR)\DOMCommentImpl.obj" \
	"$(INTDIR)\DOMDeepNodeListImpl.obj" \
	"$(INTDIR)\DOMDocumentFragmentImpl.obj" \
	"$(INTDIR)\DOMDocumentImpl.obj" \
	"$(INTDIR)\DOMDocumentTypeImpl.obj" \
	"$(INTDIR)\DOMElementImpl.obj" \
	"$(INTDIR)\DOMElementNSImpl.obj" \
	"$(INTDIR)\DOMEntityImpl.obj" \
	"$(INTDIR)\DOMEntityReferenceImpl.obj" \
	"$(INTDIR)\DOMErrorImpl.obj" \
	"$(INTDIR)\DOMImplementationImpl.obj" \
	"$(INTDIR)\DOMImplementationRegistry.obj" \
	"$(INTDIR)\DOMLocatorImpl.obj" \
	"$(INTDIR)\DOMNamedNodeMapImpl.obj" \
	"$(INTDIR)\DOMNodeIDMap.obj" \
	"$(INTDIR)\DOMNodeImpl.obj" \
	"$(INTDIR)\DOMNodeIteratorImpl.obj" \
	"$(INTDIR)\DOMNodeListImpl.obj" \
	"$(INTDIR)\DOMNodeVector.obj" \
	"$(INTDIR)\DOMNotationImpl.obj" \
	"$(INTDIR)\DOMParentNode.obj" \
	"$(INTDIR)\DOMProcessingInstructionImpl.obj" \
	"$(INTDIR)\DOMRangeImpl.obj" \
	"$(INTDIR)\DOMStringPool.obj" \
	"$(INTDIR)\DOMTextImpl.obj" \
	"$(INTDIR)\DOMTreeWalkerImpl.obj" \
	"$(INTDIR)\DOMWriterImpl.obj" \
	"$(INTDIR)\XSDElementNSImpl.obj" \
	"$(INTDIR)\AttrImpl.obj" \
	"$(INTDIR)\AttrMapImpl.obj" \
	"$(INTDIR)\AttrNSImpl.obj" \
	"$(INTDIR)\CDATASectionImpl.obj" \
	"$(INTDIR)\CharacterDataImpl.obj" \
	"$(INTDIR)\ChildNode.obj" \
	"$(INTDIR)\CommentImpl.obj" \
	"$(INTDIR)\DeepNodeListImpl.obj" \
	"$(INTDIR)\DocumentFragmentImpl.obj" \
	"$(INTDIR)\DocumentImpl.obj" \
	"$(INTDIR)\DocumentTypeImpl.obj" \
	"$(INTDIR)\DOM_Attr.obj" \
	"$(INTDIR)\DOM_CDATASection.obj" \
	"$(INTDIR)\DOM_CharacterData.obj" \
	"$(INTDIR)\DOM_Comment.obj" \
	"$(INTDIR)\DOM_Document.obj" \
	"$(INTDIR)\DOM_DocumentFragment.obj" \
	"$(INTDIR)\DOM_DocumentType.obj" \
	"$(INTDIR)\DOM_DOMException.obj" \
	"$(INTDIR)\DOM_DOMImplementation.obj" \
	"$(INTDIR)\DOM_Element.obj" \
	"$(INTDIR)\DOM_Entity.obj" \
	"$(INTDIR)\DOM_EntityReference.obj" \
	"$(INTDIR)\DOM_NamedNodeMap.obj" \
	"$(INTDIR)\DOM_Node.obj" \
	"$(INTDIR)\DOM_NodeFilter.obj" \
	"$(INTDIR)\DOM_NodeIterator.obj" \
	"$(INTDIR)\DOM_NodeList.obj" \
	"$(INTDIR)\DOM_Notation.obj" \
	"$(INTDIR)\DOM_ProcessingInstruction.obj" \
	"$(INTDIR)\DOM_Range.obj" \
	"$(INTDIR)\DOM_RangeException.obj" \
	"$(INTDIR)\DOM_Text.obj" \
	"$(INTDIR)\DOM_TreeWalker.obj" \
	"$(INTDIR)\DOM_XMLDecl.obj" \
	"$(INTDIR)\DomMemDebug.obj" \
	"$(INTDIR)\DOMParser.obj" \
	"$(INTDIR)\DOMString.obj" \
	"$(INTDIR)\DStringPool.obj" \
	"$(INTDIR)\ElementDefinitionImpl.obj" \
	"$(INTDIR)\ElementImpl.obj" \
	"$(INTDIR)\ElementNSImpl.obj" \
	"$(INTDIR)\EntityImpl.obj" \
	"$(INTDIR)\EntityReferenceImpl.obj" \
	"$(INTDIR)\NamedNodeMapImpl.obj" \
	"$(INTDIR)\NodeIDMap.obj" \
	"$(INTDIR)\NodeImpl.obj" \
	"$(INTDIR)\NodeIteratorImpl.obj" \
	"$(INTDIR)\NodeListImpl.obj" \
	"$(INTDIR)\NodeVector.obj" \
	"$(INTDIR)\NotationImpl.obj" \
	"$(INTDIR)\ParentNode.obj" \
	"$(INTDIR)\ProcessingInstructionImpl.obj" \
	"$(INTDIR)\RangeImpl.obj" \
	"$(INTDIR)\RefCountedImpl.obj" \
	"$(INTDIR)\TextImpl.obj" \
	"$(INTDIR)\TreeWalkerImpl.obj" \
	"$(INTDIR)\XMLDeclImpl.obj" \
	"$(INTDIR)\DOMException.obj" \
	"$(INTDIR)\DOMRangeException.obj" \
	"$(INTDIR)\Version.res"

"$(OUTDIR)\xerces-c_2_1_0.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "XercesLib - Win32 Debug"

OUTDIR=.\..\..\..\..\..\Build\Win32\VC6\Debug
INTDIR=.\..\..\..\..\..\Build\Win32\VC6\Debug\obj
# Begin Custom Macros
OutDir=.\..\..\..\..\..\Build\Win32\VC6\Debug
# End Custom Macros

ALL : "$(OUTDIR)\xerces-c_2_1_0D.dll"


CLEAN :
	-@erase "$(INTDIR)\AbstractDOMParser.obj"
	-@erase "$(INTDIR)\AbstractNumericFacetValidator.obj"
	-@erase "$(INTDIR)\AbstractNumericValidator.obj"
	-@erase "$(INTDIR)\AbstractStringValidator.obj"
	-@erase "$(INTDIR)\AllContentModel.obj"
	-@erase "$(INTDIR)\AnySimpleTypeDatatypeValidator.obj"
	-@erase "$(INTDIR)\AnyURIDatatypeValidator.obj"
	-@erase "$(INTDIR)\ASCIIRangeFactory.obj"
	-@erase "$(INTDIR)\AttrImpl.obj"
	-@erase "$(INTDIR)\AttrMapImpl.obj"
	-@erase "$(INTDIR)\AttrNSImpl.obj"
	-@erase "$(INTDIR)\Base64.obj"
	-@erase "$(INTDIR)\Base64BinaryDatatypeValidator.obj"
	-@erase "$(INTDIR)\BinFileInputStream.obj"
	-@erase "$(INTDIR)\BinHTTPURLInputStream.obj"
	-@erase "$(INTDIR)\BinInputStream.obj"
	-@erase "$(INTDIR)\BinMemInputStream.obj"
	-@erase "$(INTDIR)\BitSet.obj"
	-@erase "$(INTDIR)\BlockRangeFactory.obj"
	-@erase "$(INTDIR)\BMPattern.obj"
	-@erase "$(INTDIR)\BooleanDatatypeValidator.obj"
	-@erase "$(INTDIR)\CDATASectionImpl.obj"
	-@erase "$(INTDIR)\CharacterDataImpl.obj"
	-@erase "$(INTDIR)\CharToken.obj"
	-@erase "$(INTDIR)\ChildNode.obj"
	-@erase "$(INTDIR)\ClosureToken.obj"
	-@erase "$(INTDIR)\CMAny.obj"
	-@erase "$(INTDIR)\CMBinaryOp.obj"
	-@erase "$(INTDIR)\CMUnaryOp.obj"
	-@erase "$(INTDIR)\CommentImpl.obj"
	-@erase "$(INTDIR)\ComplexTypeInfo.obj"
	-@erase "$(INTDIR)\ConcatToken.obj"
	-@erase "$(INTDIR)\ConditionToken.obj"
	-@erase "$(INTDIR)\ContentLeafNameTypeVector.obj"
	-@erase "$(INTDIR)\ContentSpecNode.obj"
	-@erase "$(INTDIR)\DatatypeValidator.obj"
	-@erase "$(INTDIR)\DatatypeValidatorFactory.obj"
	-@erase "$(INTDIR)\DateDatatypeValidator.obj"
	-@erase "$(INTDIR)\DateTimeDatatypeValidator.obj"
	-@erase "$(INTDIR)\DateTimeValidator.obj"
	-@erase "$(INTDIR)\DayDatatypeValidator.obj"
	-@erase "$(INTDIR)\DecimalDatatypeValidator.obj"
	-@erase "$(INTDIR)\DeepNodeListImpl.obj"
	-@erase "$(INTDIR)\DFAContentModel.obj"
	-@erase "$(INTDIR)\DocumentFragmentImpl.obj"
	-@erase "$(INTDIR)\DocumentImpl.obj"
	-@erase "$(INTDIR)\DocumentTypeImpl.obj"
	-@erase "$(INTDIR)\DOM_Attr.obj"
	-@erase "$(INTDIR)\DOM_CDATASection.obj"
	-@erase "$(INTDIR)\DOM_CharacterData.obj"
	-@erase "$(INTDIR)\DOM_Comment.obj"
	-@erase "$(INTDIR)\DOM_Document.obj"
	-@erase "$(INTDIR)\DOM_DocumentFragment.obj"
	-@erase "$(INTDIR)\DOM_DocumentType.obj"
	-@erase "$(INTDIR)\DOM_DOMException.obj"
	-@erase "$(INTDIR)\DOM_DOMImplementation.obj"
	-@erase "$(INTDIR)\DOM_Element.obj"
	-@erase "$(INTDIR)\DOM_Entity.obj"
	-@erase "$(INTDIR)\DOM_EntityReference.obj"
	-@erase "$(INTDIR)\DOM_NamedNodeMap.obj"
	-@erase "$(INTDIR)\DOM_Node.obj"
	-@erase "$(INTDIR)\DOM_NodeFilter.obj"
	-@erase "$(INTDIR)\DOM_NodeIterator.obj"
	-@erase "$(INTDIR)\DOM_NodeList.obj"
	-@erase "$(INTDIR)\DOM_Notation.obj"
	-@erase "$(INTDIR)\DOM_ProcessingInstruction.obj"
	-@erase "$(INTDIR)\DOM_Range.obj"
	-@erase "$(INTDIR)\DOM_RangeException.obj"
	-@erase "$(INTDIR)\DOM_Text.obj"
	-@erase "$(INTDIR)\DOM_TreeWalker.obj"
	-@erase "$(INTDIR)\DOM_XMLDecl.obj"
	-@erase "$(INTDIR)\DOMAttrImpl.obj"
	-@erase "$(INTDIR)\DOMAttrMapImpl.obj"
	-@erase "$(INTDIR)\DOMAttrNSImpl.obj"
	-@erase "$(INTDIR)\DOMBuilderImpl.obj"
	-@erase "$(INTDIR)\DOMCDATASectionImpl.obj"
	-@erase "$(INTDIR)\DOMCharacterDataImpl.obj"
	-@erase "$(INTDIR)\DOMChildNode.obj"
	-@erase "$(INTDIR)\DOMCommentImpl.obj"
	-@erase "$(INTDIR)\DOMDeepNodeListImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentFragmentImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentTypeImpl.obj"
	-@erase "$(INTDIR)\DOMElementImpl.obj"
	-@erase "$(INTDIR)\DOMElementNSImpl.obj"
	-@erase "$(INTDIR)\DOMEntityImpl.obj"
	-@erase "$(INTDIR)\DOMEntityReferenceImpl.obj"
	-@erase "$(INTDIR)\DOMErrorImpl.obj"
	-@erase "$(INTDIR)\DOMException.obj"
	-@erase "$(INTDIR)\DOMImplementationImpl.obj"
	-@erase "$(INTDIR)\DOMImplementationRegistry.obj"
	-@erase "$(INTDIR)\DOMLocatorImpl.obj"
	-@erase "$(INTDIR)\DomMemDebug.obj"
	-@erase "$(INTDIR)\DOMNamedNodeMapImpl.obj"
	-@erase "$(INTDIR)\DOMNodeIDMap.obj"
	-@erase "$(INTDIR)\DOMNodeImpl.obj"
	-@erase "$(INTDIR)\DOMNodeIteratorImpl.obj"
	-@erase "$(INTDIR)\DOMNodeListImpl.obj"
	-@erase "$(INTDIR)\DOMNodeVector.obj"
	-@erase "$(INTDIR)\DOMNotationImpl.obj"
	-@erase "$(INTDIR)\DOMParentNode.obj"
	-@erase "$(INTDIR)\DOMParser.obj"
	-@erase "$(INTDIR)\DOMProcessingInstructionImpl.obj"
	-@erase "$(INTDIR)\DOMRangeException.obj"
	-@erase "$(INTDIR)\DOMRangeImpl.obj"
	-@erase "$(INTDIR)\DOMString.obj"
	-@erase "$(INTDIR)\DOMStringPool.obj"
	-@erase "$(INTDIR)\DOMTextImpl.obj"
	-@erase "$(INTDIR)\DOMTreeWalkerImpl.obj"
	-@erase "$(INTDIR)\DOMWriterImpl.obj"
	-@erase "$(INTDIR)\DoubleDatatypeValidator.obj"
	-@erase "$(INTDIR)\DStringPool.obj"
	-@erase "$(INTDIR)\DTDAttDef.obj"
	-@erase "$(INTDIR)\DTDAttDefList.obj"
	-@erase "$(INTDIR)\DTDElementDecl.obj"
	-@erase "$(INTDIR)\DTDGrammar.obj"
	-@erase "$(INTDIR)\DTDScanner.obj"
	-@erase "$(INTDIR)\DTDValidator.obj"
	-@erase "$(INTDIR)\Dummy.obj"
	-@erase "$(INTDIR)\DurationDatatypeValidator.obj"
	-@erase "$(INTDIR)\ElementDefinitionImpl.obj"
	-@erase "$(INTDIR)\ElementImpl.obj"
	-@erase "$(INTDIR)\ElementNSImpl.obj"
	-@erase "$(INTDIR)\ElemStack.obj"
	-@erase "$(INTDIR)\EncodingValidator.obj"
	-@erase "$(INTDIR)\ENTITYDatatypeValidator.obj"
	-@erase "$(INTDIR)\EntityImpl.obj"
	-@erase "$(INTDIR)\EntityReferenceImpl.obj"
	-@erase "$(INTDIR)\FieldActivator.obj"
	-@erase "$(INTDIR)\FieldValueMap.obj"
	-@erase "$(INTDIR)\FloatDatatypeValidator.obj"
	-@erase "$(INTDIR)\GeneralAttributeCheck.obj"
	-@erase "$(INTDIR)\GrammarResolver.obj"
	-@erase "$(INTDIR)\HashPtr.obj"
	-@erase "$(INTDIR)\HashXMLCh.obj"
	-@erase "$(INTDIR)\HeaderDummy.obj"
	-@erase "$(INTDIR)\HexBin.obj"
	-@erase "$(INTDIR)\HexBinaryDatatypeValidator.obj"
	-@erase "$(INTDIR)\IC_Field.obj"
	-@erase "$(INTDIR)\IC_Key.obj"
	-@erase "$(INTDIR)\IC_KeyRef.obj"
	-@erase "$(INTDIR)\IC_Selector.obj"
	-@erase "$(INTDIR)\IC_Unique.obj"
	-@erase "$(INTDIR)\IDDatatypeValidator.obj"
	-@erase "$(INTDIR)\IdentityConstraint.obj"
	-@erase "$(INTDIR)\IDREFDatatypeValidator.obj"
	-@erase "$(INTDIR)\InputSource.obj"
	-@erase "$(INTDIR)\KVStringPair.obj"
	-@erase "$(INTDIR)\ListDatatypeValidator.obj"
	-@erase "$(INTDIR)\LocalFileFormatTarget.obj"
	-@erase "$(INTDIR)\LocalFileInputSource.obj"
	-@erase "$(INTDIR)\Match.obj"
	-@erase "$(INTDIR)\MemBufFormatTarget.obj"
	-@erase "$(INTDIR)\MemBufInputSource.obj"
	-@erase "$(INTDIR)\MixedContentModel.obj"
	-@erase "$(INTDIR)\ModifierToken.obj"
	-@erase "$(INTDIR)\MonthDatatypeValidator.obj"
	-@erase "$(INTDIR)\MonthDayDatatypeValidator.obj"
	-@erase "$(INTDIR)\Mutexes.obj"
	-@erase "$(INTDIR)\NameDatatypeValidator.obj"
	-@erase "$(INTDIR)\NamedNodeMapImpl.obj"
	-@erase "$(INTDIR)\NamespaceScope.obj"
	-@erase "$(INTDIR)\NCNameDatatypeValidator.obj"
	-@erase "$(INTDIR)\NodeIDMap.obj"
	-@erase "$(INTDIR)\NodeImpl.obj"
	-@erase "$(INTDIR)\NodeIteratorImpl.obj"
	-@erase "$(INTDIR)\NodeListImpl.obj"
	-@erase "$(INTDIR)\NodeVector.obj"
	-@erase "$(INTDIR)\NOTATIONDatatypeValidator.obj"
	-@erase "$(INTDIR)\NotationImpl.obj"
	-@erase "$(INTDIR)\Op.obj"
	-@erase "$(INTDIR)\OpFactory.obj"
	-@erase "$(INTDIR)\ParentNode.obj"
	-@erase "$(INTDIR)\ParenToken.obj"
	-@erase "$(INTDIR)\ParserForXMLSchema.obj"
	-@erase "$(INTDIR)\PlatformUtils.obj"
	-@erase "$(INTDIR)\ProcessingInstructionImpl.obj"
	-@erase "$(INTDIR)\QName.obj"
	-@erase "$(INTDIR)\QNameDatatypeValidator.obj"
	-@erase "$(INTDIR)\RangeFactory.obj"
	-@erase "$(INTDIR)\RangeImpl.obj"
	-@erase "$(INTDIR)\RangeToken.obj"
	-@erase "$(INTDIR)\RangeTokenMap.obj"
	-@erase "$(INTDIR)\ReaderMgr.obj"
	-@erase "$(INTDIR)\RefCountedImpl.obj"
	-@erase "$(INTDIR)\RegularExpression.obj"
	-@erase "$(INTDIR)\RegxParser.obj"
	-@erase "$(INTDIR)\RegxUtil.obj"
	-@erase "$(INTDIR)\sax2Dummy.obj"
	-@erase "$(INTDIR)\SAX2XMLReaderImpl.obj"
	-@erase "$(INTDIR)\SAXException.obj"
	-@erase "$(INTDIR)\SAXParseException.obj"
	-@erase "$(INTDIR)\SAXParser.obj"
	-@erase "$(INTDIR)\SchemaAttDef.obj"
	-@erase "$(INTDIR)\SchemaAttDefList.obj"
	-@erase "$(INTDIR)\SchemaElementDecl.obj"
	-@erase "$(INTDIR)\SchemaGrammar.obj"
	-@erase "$(INTDIR)\SchemaInfo.obj"
	-@erase "$(INTDIR)\SchemaSymbols.obj"
	-@erase "$(INTDIR)\SchemaValidator.obj"
	-@erase "$(INTDIR)\SimpleContentModel.obj"
	-@erase "$(INTDIR)\StdInInputSource.obj"
	-@erase "$(INTDIR)\StdOutFormatTarget.obj"
	-@erase "$(INTDIR)\StringDatatypeValidator.obj"
	-@erase "$(INTDIR)\StringPool.obj"
	-@erase "$(INTDIR)\StringToken.obj"
	-@erase "$(INTDIR)\SubstitutionGroupComparator.obj"
	-@erase "$(INTDIR)\TextImpl.obj"
	-@erase "$(INTDIR)\TimeDatatypeValidator.obj"
	-@erase "$(INTDIR)\Token.obj"
	-@erase "$(INTDIR)\TokenFactory.obj"
	-@erase "$(INTDIR)\TransService.obj"
	-@erase "$(INTDIR)\TraverseSchema.obj"
	-@erase "$(INTDIR)\TreeWalkerImpl.obj"
	-@erase "$(INTDIR)\UnicodeRangeFactory.obj"
	-@erase "$(INTDIR)\UnionDatatypeValidator.obj"
	-@erase "$(INTDIR)\UnionToken.obj"
	-@erase "$(INTDIR)\URLInputSource.obj"
	-@erase "$(INTDIR)\ValueStore.obj"
	-@erase "$(INTDIR)\ValueStoreCache.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\VecAttributesImpl.obj"
	-@erase "$(INTDIR)\VecAttrListImpl.obj"
	-@erase "$(INTDIR)\Version.res"
	-@erase "$(INTDIR)\Win32MsgLoader.obj"
	-@erase "$(INTDIR)\Win32PlatformUtils.obj"
	-@erase "$(INTDIR)\Win32TransService.obj"
	-@erase "$(INTDIR)\WinSockNetAccessor.obj"
	-@erase "$(INTDIR)\Wrapper4DOMInputSource.obj"
	-@erase "$(INTDIR)\Wrapper4InputSource.obj"
	-@erase "$(INTDIR)\XercesAttGroupInfo.obj"
	-@erase "$(INTDIR)\XercesDOMParser.obj"
	-@erase "$(INTDIR)\XercesElementWildcard.obj"
	-@erase "$(INTDIR)\XercesGroupInfo.obj"
	-@erase "$(INTDIR)\XercesXPath.obj"
	-@erase "$(INTDIR)\XML256TableTranscoder.obj"
	-@erase "$(INTDIR)\XML88591Transcoder.obj"
	-@erase "$(INTDIR)\XMLAbstractDoubleFloat.obj"
	-@erase "$(INTDIR)\XMLASCIITranscoder.obj"
	-@erase "$(INTDIR)\XMLAttDef.obj"
	-@erase "$(INTDIR)\XMLAttr.obj"
	-@erase "$(INTDIR)\XMLBigDecimal.obj"
	-@erase "$(INTDIR)\XMLBigInteger.obj"
	-@erase "$(INTDIR)\XMLBuffer.obj"
	-@erase "$(INTDIR)\XMLBufferMgr.obj"
	-@erase "$(INTDIR)\XMLChTranscoder.obj"
	-@erase "$(INTDIR)\XMLContentModel.obj"
	-@erase "$(INTDIR)\XMLDateTime.obj"
	-@erase "$(INTDIR)\XMLDeclImpl.obj"
	-@erase "$(INTDIR)\XMLDouble.obj"
	-@erase "$(INTDIR)\XMLEBCDICTranscoder.obj"
	-@erase "$(INTDIR)\XMLElementDecl.obj"
	-@erase "$(INTDIR)\XMLEntityDecl.obj"
	-@erase "$(INTDIR)\XMLException.obj"
	-@erase "$(INTDIR)\XMLFloat.obj"
	-@erase "$(INTDIR)\XMLFormatter.obj"
	-@erase "$(INTDIR)\XMLIBM1140Transcoder.obj"
	-@erase "$(INTDIR)\XMLNotationDecl.obj"
	-@erase "$(INTDIR)\XMLMsgLoader.obj"
	-@erase "$(INTDIR)\XMLNumber.obj"	
	-@erase "$(INTDIR)\XMLRangeFactory.obj"
	-@erase "$(INTDIR)\XMLReader.obj"
	-@erase "$(INTDIR)\XMLRecognizer.obj"
	-@erase "$(INTDIR)\XMLScanner.obj"
	-@erase "$(INTDIR)\XMLScanner2.obj"
	-@erase "$(INTDIR)\XMLString.obj"
	-@erase "$(INTDIR)\XMLStringTokenizer.obj"
	-@erase "$(INTDIR)\XMLUCSTranscoder.obj"
	-@erase "$(INTDIR)\XMLUni.obj"
	-@erase "$(INTDIR)\XMLUniCharacter.obj"
	-@erase "$(INTDIR)\XMLUri.obj"
	-@erase "$(INTDIR)\XMLURL.obj"
	-@erase "$(INTDIR)\XMLUTF16Transcoder.obj"
	-@erase "$(INTDIR)\XMLUTF8Transcoder.obj"
	-@erase "$(INTDIR)\XMLValidator.obj"
	-@erase "$(INTDIR)\XMLWin1252Transcoder.obj"
	-@erase "$(INTDIR)\XPathMatcher.obj"
	-@erase "$(INTDIR)\XPathMatcherStack.obj"
	-@erase "$(INTDIR)\XPathSymbols.obj"
	-@erase "$(INTDIR)\XSDDOMParser.obj"
	-@erase "$(INTDIR)\XSDElementNSImpl.obj"
	-@erase "$(INTDIR)\XSDErrorReporter.obj"
	-@erase "$(INTDIR)\XSDLocator.obj"
	-@erase "$(INTDIR)\XUtil.obj"
	-@erase "$(INTDIR)\YearDatatypeValidator.obj"
	-@erase "$(INTDIR)\YearMonthDatatypeValidator.obj"
	-@erase "$(OUTDIR)\xerces-c_2_1_0D.dll"
	-@erase "$(OUTDIR)\xerces-c_2_1_0D.ilk"
	-@erase "$(OUTDIR)\xerces-c_2_1_0D.pdb"
	-@erase "$(OUTDIR)\xerces-c_2D.exp"
	-@erase "$(OUTDIR)\xerces-c_2D.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=$(CPP)
CPP_PROJ=/G6 /MDd /Za /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=/D "_DEBUG" /mktyplib203 /o "NUL" /win32
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Version.res" /d "_DEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/o"$(OUTDIR)\XercesLib.bsc"
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib advapi32.lib ws2_32.lib /base:"0x12000000" /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\xerces-c_2_1_0D.pdb" /debug /machine:I386 /out:"$(OUTDIR)\xerces-c_2_1_0D.dll" /implib:"$(OUTDIR)\xerces-c_2D.lib" /pdbtype:sept /version:2.0.0
LINK32_OBJS= \
	"$(INTDIR)\Win32PlatformUtils.obj" \
	"$(INTDIR)\Win32MsgLoader.obj" \
	"$(INTDIR)\Win32TransService.obj" \
	"$(INTDIR)\BinHTTPURLInputStream.obj" \
	"$(INTDIR)\WinSockNetAccessor.obj" \
	"$(INTDIR)\ASCIIRangeFactory.obj" \
	"$(INTDIR)\BlockRangeFactory.obj" \
	"$(INTDIR)\BMPattern.obj" \
	"$(INTDIR)\CharToken.obj" \
	"$(INTDIR)\ClosureToken.obj" \
	"$(INTDIR)\ConcatToken.obj" \
	"$(INTDIR)\ConditionToken.obj" \
	"$(INTDIR)\Match.obj" \
	"$(INTDIR)\ModifierToken.obj" \
	"$(INTDIR)\Op.obj" \
	"$(INTDIR)\OpFactory.obj" \
	"$(INTDIR)\ParenToken.obj" \
	"$(INTDIR)\ParserForXMLSchema.obj" \
	"$(INTDIR)\RangeFactory.obj" \
	"$(INTDIR)\RangeToken.obj" \
	"$(INTDIR)\RangeTokenMap.obj" \
	"$(INTDIR)\RegularExpression.obj" \
	"$(INTDIR)\RegxParser.obj" \
	"$(INTDIR)\RegxUtil.obj" \
	"$(INTDIR)\StringToken.obj" \
	"$(INTDIR)\Token.obj" \
	"$(INTDIR)\TokenFactory.obj" \
	"$(INTDIR)\UnicodeRangeFactory.obj" \
	"$(INTDIR)\UnionToken.obj" \
	"$(INTDIR)\XMLRangeFactory.obj" \
	"$(INTDIR)\XMLUniCharacter.obj" \
	"$(INTDIR)\Base64.obj" \
	"$(INTDIR)\BinFileInputStream.obj" \
	"$(INTDIR)\BinInputStream.obj" \
	"$(INTDIR)\BinMemInputStream.obj" \
	"$(INTDIR)\BitSet.obj" \
	"$(INTDIR)\EncodingValidator.obj" \
	"$(INTDIR)\HashPtr.obj" \
	"$(INTDIR)\HashXMLCh.obj" \
	"$(INTDIR)\HeaderDummy.obj" \
	"$(INTDIR)\HexBin.obj" \
	"$(INTDIR)\KVStringPair.obj" \
	"$(INTDIR)\Mutexes.obj" \
	"$(INTDIR)\PlatformUtils.obj" \
	"$(INTDIR)\QName.obj" \
	"$(INTDIR)\StringPool.obj" \
	"$(INTDIR)\TransService.obj" \
	"$(INTDIR)\XML256TableTranscoder.obj" \
	"$(INTDIR)\XML88591Transcoder.obj" \
	"$(INTDIR)\XMLAbstractDoubleFloat.obj" \
	"$(INTDIR)\XMLASCIITranscoder.obj" \
	"$(INTDIR)\XMLBigDecimal.obj" \
	"$(INTDIR)\XMLBigInteger.obj" \
	"$(INTDIR)\XMLChTranscoder.obj" \
	"$(INTDIR)\XMLDateTime.obj" \
	"$(INTDIR)\XMLDouble.obj" \
	"$(INTDIR)\XMLEBCDICTranscoder.obj" \
	"$(INTDIR)\XMLException.obj" \
	"$(INTDIR)\XMLFloat.obj" \
	"$(INTDIR)\XMLIBM1140Transcoder.obj" \
	"$(INTDIR)\XMLMsgLoader.obj" \
	"$(INTDIR)\XMLNumber.obj" \
	"$(INTDIR)\XMLString.obj" \
	"$(INTDIR)\XMLStringTokenizer.obj" \
	"$(INTDIR)\XMLUCSTranscoder.obj" \
	"$(INTDIR)\XMLUni.obj" \
	"$(INTDIR)\XMLUri.obj" \
	"$(INTDIR)\XMLURL.obj" \
	"$(INTDIR)\XMLUTF16Transcoder.obj" \
	"$(INTDIR)\XMLUTF8Transcoder.obj" \
	"$(INTDIR)\XMLWin1252Transcoder.obj" \
	"$(INTDIR)\LocalFileFormatTarget.obj" \
	"$(INTDIR)\LocalFileInputSource.obj" \
	"$(INTDIR)\MemBufFormatTarget.obj" \
	"$(INTDIR)\MemBufInputSource.obj" \
	"$(INTDIR)\StdInInputSource.obj" \
	"$(INTDIR)\StdOutFormatTarget.obj" \
	"$(INTDIR)\URLInputSource.obj" \
	"$(INTDIR)\Wrapper4DOMInputSource.obj" \
	"$(INTDIR)\Wrapper4InputSource.obj" \
	"$(INTDIR)\XMLAttDef.obj" \
	"$(INTDIR)\XMLAttr.obj" \
	"$(INTDIR)\XMLBuffer.obj" \
	"$(INTDIR)\XMLBufferMgr.obj" \
	"$(INTDIR)\XMLContentModel.obj" \
	"$(INTDIR)\XMLElementDecl.obj" \
	"$(INTDIR)\XMLEntityDecl.obj" \
	"$(INTDIR)\XMLFormatter.obj" \
	"$(INTDIR)\XMLNotationDecl.obj" \
	"$(INTDIR)\XMLRecognizer.obj" \
	"$(INTDIR)\XMLValidator.obj" \
	"$(INTDIR)\ElemStack.obj" \
	"$(INTDIR)\ReaderMgr.obj" \
	"$(INTDIR)\VecAttributesImpl.obj" \
	"$(INTDIR)\VecAttrListImpl.obj" \
	"$(INTDIR)\XMLReader.obj" \
	"$(INTDIR)\XMLScanner.obj" \
	"$(INTDIR)\XMLScanner2.obj" \
	"$(INTDIR)\Dummy.obj" \
	"$(INTDIR)\InputSource.obj" \
	"$(INTDIR)\SAXException.obj" \
	"$(INTDIR)\SAXParseException.obj" \
	"$(INTDIR)\AbstractDOMParser.obj" \
	"$(INTDIR)\DOMBuilderImpl.obj" \
	"$(INTDIR)\SAX2XMLReaderImpl.obj" \
	"$(INTDIR)\SAXParser.obj" \
	"$(INTDIR)\XercesDOMParser.obj" \
	"$(INTDIR)\AllContentModel.obj" \
	"$(INTDIR)\CMAny.obj" \
	"$(INTDIR)\CMBinaryOp.obj" \
	"$(INTDIR)\CMUnaryOp.obj" \
	"$(INTDIR)\ContentLeafNameTypeVector.obj" \
	"$(INTDIR)\ContentSpecNode.obj" \
	"$(INTDIR)\DFAContentModel.obj" \
	"$(INTDIR)\GrammarResolver.obj" \
	"$(INTDIR)\MixedContentModel.obj" \
	"$(INTDIR)\SimpleContentModel.obj" \
	"$(INTDIR)\AbstractNumericFacetValidator.obj" \
	"$(INTDIR)\AbstractNumericValidator.obj" \
	"$(INTDIR)\AbstractStringValidator.obj" \
	"$(INTDIR)\AnySimpleTypeDatatypeValidator.obj" \
	"$(INTDIR)\AnyURIDatatypeValidator.obj" \
	"$(INTDIR)\Base64BinaryDatatypeValidator.obj" \
	"$(INTDIR)\BooleanDatatypeValidator.obj" \
	"$(INTDIR)\DatatypeValidator.obj" \
	"$(INTDIR)\DatatypeValidatorFactory.obj" \
	"$(INTDIR)\DateDatatypeValidator.obj" \
	"$(INTDIR)\DateTimeDatatypeValidator.obj" \
	"$(INTDIR)\DateTimeValidator.obj" \
	"$(INTDIR)\DayDatatypeValidator.obj" \
	"$(INTDIR)\DecimalDatatypeValidator.obj" \
	"$(INTDIR)\DoubleDatatypeValidator.obj" \
	"$(INTDIR)\DurationDatatypeValidator.obj" \
	"$(INTDIR)\ENTITYDatatypeValidator.obj" \
	"$(INTDIR)\FloatDatatypeValidator.obj" \
	"$(INTDIR)\HexBinaryDatatypeValidator.obj" \
	"$(INTDIR)\IDDatatypeValidator.obj" \
	"$(INTDIR)\IDREFDatatypeValidator.obj" \
	"$(INTDIR)\ListDatatypeValidator.obj" \
	"$(INTDIR)\MonthDatatypeValidator.obj" \
	"$(INTDIR)\MonthDayDatatypeValidator.obj" \
	"$(INTDIR)\NameDatatypeValidator.obj" \
	"$(INTDIR)\NCNameDatatypeValidator.obj" \
	"$(INTDIR)\NOTATIONDatatypeValidator.obj" \
	"$(INTDIR)\QNameDatatypeValidator.obj" \
	"$(INTDIR)\StringDatatypeValidator.obj" \
	"$(INTDIR)\TimeDatatypeValidator.obj" \
	"$(INTDIR)\UnionDatatypeValidator.obj" \
	"$(INTDIR)\YearDatatypeValidator.obj" \
	"$(INTDIR)\YearMonthDatatypeValidator.obj" \
	"$(INTDIR)\DTDAttDef.obj" \
	"$(INTDIR)\DTDAttDefList.obj" \
	"$(INTDIR)\DTDElementDecl.obj" \
	"$(INTDIR)\DTDGrammar.obj" \
	"$(INTDIR)\DTDScanner.obj" \
	"$(INTDIR)\DTDValidator.obj" \
	"$(INTDIR)\FieldActivator.obj" \
	"$(INTDIR)\FieldValueMap.obj" \
	"$(INTDIR)\IC_Field.obj" \
	"$(INTDIR)\IC_Key.obj" \
	"$(INTDIR)\IC_KeyRef.obj" \
	"$(INTDIR)\IC_Selector.obj" \
	"$(INTDIR)\IC_Unique.obj" \
	"$(INTDIR)\IdentityConstraint.obj" \
	"$(INTDIR)\ValueStore.obj" \
	"$(INTDIR)\ValueStoreCache.obj" \
	"$(INTDIR)\XercesXPath.obj" \
	"$(INTDIR)\XPathMatcher.obj" \
	"$(INTDIR)\XPathMatcherStack.obj" \
	"$(INTDIR)\XPathSymbols.obj" \
	"$(INTDIR)\ComplexTypeInfo.obj" \
	"$(INTDIR)\GeneralAttributeCheck.obj" \
	"$(INTDIR)\NamespaceScope.obj" \
	"$(INTDIR)\SchemaAttDef.obj" \
	"$(INTDIR)\SchemaAttDefList.obj" \
	"$(INTDIR)\SchemaElementDecl.obj" \
	"$(INTDIR)\SchemaGrammar.obj" \
	"$(INTDIR)\SchemaInfo.obj" \
	"$(INTDIR)\SchemaSymbols.obj" \
	"$(INTDIR)\SchemaValidator.obj" \
	"$(INTDIR)\SubstitutionGroupComparator.obj" \
	"$(INTDIR)\TraverseSchema.obj" \
	"$(INTDIR)\XercesAttGroupInfo.obj" \
	"$(INTDIR)\XercesElementWildcard.obj" \
	"$(INTDIR)\XercesGroupInfo.obj" \
	"$(INTDIR)\XSDDOMParser.obj" \
	"$(INTDIR)\XSDErrorReporter.obj" \
	"$(INTDIR)\XSDLocator.obj" \
	"$(INTDIR)\XUtil.obj" \
	"$(INTDIR)\sax2Dummy.obj" \
	"$(INTDIR)\DOMAttrImpl.obj" \
	"$(INTDIR)\DOMAttrMapImpl.obj" \
	"$(INTDIR)\DOMAttrNSImpl.obj" \
	"$(INTDIR)\DOMCDATASectionImpl.obj" \
	"$(INTDIR)\DOMCharacterDataImpl.obj" \
	"$(INTDIR)\DOMChildNode.obj" \
	"$(INTDIR)\DOMCommentImpl.obj" \
	"$(INTDIR)\DOMDeepNodeListImpl.obj" \
	"$(INTDIR)\DOMDocumentFragmentImpl.obj" \
	"$(INTDIR)\DOMDocumentImpl.obj" \
	"$(INTDIR)\DOMDocumentTypeImpl.obj" \
	"$(INTDIR)\DOMElementImpl.obj" \
	"$(INTDIR)\DOMElementNSImpl.obj" \
	"$(INTDIR)\DOMEntityImpl.obj" \
	"$(INTDIR)\DOMEntityReferenceImpl.obj" \
	"$(INTDIR)\DOMErrorImpl.obj" \
	"$(INTDIR)\DOMImplementationImpl.obj" \
	"$(INTDIR)\DOMImplementationRegistry.obj" \
	"$(INTDIR)\DOMLocatorImpl.obj" \
	"$(INTDIR)\DOMNamedNodeMapImpl.obj" \
	"$(INTDIR)\DOMNodeIDMap.obj" \
	"$(INTDIR)\DOMNodeImpl.obj" \
	"$(INTDIR)\DOMNodeIteratorImpl.obj" \
	"$(INTDIR)\DOMNodeListImpl.obj" \
	"$(INTDIR)\DOMNodeVector.obj" \
	"$(INTDIR)\DOMNotationImpl.obj" \
	"$(INTDIR)\DOMParentNode.obj" \
	"$(INTDIR)\DOMProcessingInstructionImpl.obj" \
	"$(INTDIR)\DOMRangeImpl.obj" \
	"$(INTDIR)\DOMStringPool.obj" \
	"$(INTDIR)\DOMTextImpl.obj" \
	"$(INTDIR)\DOMTreeWalkerImpl.obj" \
	"$(INTDIR)\DOMWriterImpl.obj" \
	"$(INTDIR)\XSDElementNSImpl.obj" \
	"$(INTDIR)\AttrImpl.obj" \
	"$(INTDIR)\AttrMapImpl.obj" \
	"$(INTDIR)\AttrNSImpl.obj" \
	"$(INTDIR)\CDATASectionImpl.obj" \
	"$(INTDIR)\CharacterDataImpl.obj" \
	"$(INTDIR)\ChildNode.obj" \
	"$(INTDIR)\CommentImpl.obj" \
	"$(INTDIR)\DeepNodeListImpl.obj" \
	"$(INTDIR)\DocumentFragmentImpl.obj" \
	"$(INTDIR)\DocumentImpl.obj" \
	"$(INTDIR)\DocumentTypeImpl.obj" \
	"$(INTDIR)\DOM_Attr.obj" \
	"$(INTDIR)\DOM_CDATASection.obj" \
	"$(INTDIR)\DOM_CharacterData.obj" \
	"$(INTDIR)\DOM_Comment.obj" \
	"$(INTDIR)\DOM_Document.obj" \
	"$(INTDIR)\DOM_DocumentFragment.obj" \
	"$(INTDIR)\DOM_DocumentType.obj" \
	"$(INTDIR)\DOM_DOMException.obj" \
	"$(INTDIR)\DOM_DOMImplementation.obj" \
	"$(INTDIR)\DOM_Element.obj" \
	"$(INTDIR)\DOM_Entity.obj" \
	"$(INTDIR)\DOM_EntityReference.obj" \
	"$(INTDIR)\DOM_NamedNodeMap.obj" \
	"$(INTDIR)\DOM_Node.obj" \
	"$(INTDIR)\DOM_NodeFilter.obj" \
	"$(INTDIR)\DOM_NodeIterator.obj" \
	"$(INTDIR)\DOM_NodeList.obj" \
	"$(INTDIR)\DOM_Notation.obj" \
	"$(INTDIR)\DOM_ProcessingInstruction.obj" \
	"$(INTDIR)\DOM_Range.obj" \
	"$(INTDIR)\DOM_RangeException.obj" \
	"$(INTDIR)\DOM_Text.obj" \
	"$(INTDIR)\DOM_TreeWalker.obj" \
	"$(INTDIR)\DOM_XMLDecl.obj" \
	"$(INTDIR)\DomMemDebug.obj" \
	"$(INTDIR)\DOMParser.obj" \
	"$(INTDIR)\DOMString.obj" \
	"$(INTDIR)\DStringPool.obj" \
	"$(INTDIR)\ElementDefinitionImpl.obj" \
	"$(INTDIR)\ElementImpl.obj" \
	"$(INTDIR)\ElementNSImpl.obj" \
	"$(INTDIR)\EntityImpl.obj" \
	"$(INTDIR)\EntityReferenceImpl.obj" \
	"$(INTDIR)\NamedNodeMapImpl.obj" \
	"$(INTDIR)\NodeIDMap.obj" \
	"$(INTDIR)\NodeImpl.obj" \
	"$(INTDIR)\NodeIteratorImpl.obj" \
	"$(INTDIR)\NodeListImpl.obj" \
	"$(INTDIR)\NodeVector.obj" \
	"$(INTDIR)\NotationImpl.obj" \
	"$(INTDIR)\ParentNode.obj" \
	"$(INTDIR)\ProcessingInstructionImpl.obj" \
	"$(INTDIR)\RangeImpl.obj" \
	"$(INTDIR)\RefCountedImpl.obj" \
	"$(INTDIR)\TextImpl.obj" \
	"$(INTDIR)\TreeWalkerImpl.obj" \
	"$(INTDIR)\XMLDeclImpl.obj" \
	"$(INTDIR)\DOMException.obj" \
	"$(INTDIR)\DOMRangeException.obj" \
	"$(INTDIR)\Version.res"

"$(OUTDIR)\xerces-c_2_1_0D.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "XercesLib - Win64 Debug"

OUTDIR=.\..\..\..\..\..\Build\Win64\VC6\Debug
INTDIR=.\..\..\..\..\..\Build\Win64\VC6\Debug\obj
# Begin Custom Macros
OutDir=.\..\..\..\..\..\Build\Win64\VC6\Debug
# End Custom Macros

ALL : "$(OUTDIR)\xerces-c_2_1_0D.dll"


CLEAN :
	-@erase "$(INTDIR)\AbstractDOMParser.obj"
	-@erase "$(INTDIR)\AbstractNumericFacetValidator.obj"
	-@erase "$(INTDIR)\AbstractNumericValidator.obj"
	-@erase "$(INTDIR)\AbstractStringValidator.obj"
	-@erase "$(INTDIR)\AllContentModel.obj"
	-@erase "$(INTDIR)\AnySimpleTypeDatatypeValidator.obj"
	-@erase "$(INTDIR)\AnyURIDatatypeValidator.obj"
	-@erase "$(INTDIR)\ASCIIRangeFactory.obj"
	-@erase "$(INTDIR)\AttrImpl.obj"
	-@erase "$(INTDIR)\AttrMapImpl.obj"
	-@erase "$(INTDIR)\AttrNSImpl.obj"
	-@erase "$(INTDIR)\Base64.obj"
	-@erase "$(INTDIR)\Base64BinaryDatatypeValidator.obj"
	-@erase "$(INTDIR)\BinFileInputStream.obj"
	-@erase "$(INTDIR)\BinHTTPURLInputStream.obj"
	-@erase "$(INTDIR)\BinInputStream.obj"
	-@erase "$(INTDIR)\BinMemInputStream.obj"
	-@erase "$(INTDIR)\BitSet.obj"
	-@erase "$(INTDIR)\BlockRangeFactory.obj"
	-@erase "$(INTDIR)\BMPattern.obj"
	-@erase "$(INTDIR)\BooleanDatatypeValidator.obj"
	-@erase "$(INTDIR)\CDATASectionImpl.obj"
	-@erase "$(INTDIR)\CharacterDataImpl.obj"
	-@erase "$(INTDIR)\CharToken.obj"
	-@erase "$(INTDIR)\ChildNode.obj"
	-@erase "$(INTDIR)\ClosureToken.obj"
	-@erase "$(INTDIR)\CMAny.obj"
	-@erase "$(INTDIR)\CMBinaryOp.obj"
	-@erase "$(INTDIR)\CMUnaryOp.obj"
	-@erase "$(INTDIR)\CommentImpl.obj"
	-@erase "$(INTDIR)\ComplexTypeInfo.obj"
	-@erase "$(INTDIR)\ConcatToken.obj"
	-@erase "$(INTDIR)\ConditionToken.obj"
	-@erase "$(INTDIR)\ContentLeafNameTypeVector.obj"
	-@erase "$(INTDIR)\ContentSpecNode.obj"
	-@erase "$(INTDIR)\DatatypeValidator.obj"
	-@erase "$(INTDIR)\DatatypeValidatorFactory.obj"
	-@erase "$(INTDIR)\DateDatatypeValidator.obj"
	-@erase "$(INTDIR)\DateTimeDatatypeValidator.obj"
	-@erase "$(INTDIR)\DateTimeValidator.obj"
	-@erase "$(INTDIR)\DayDatatypeValidator.obj"
	-@erase "$(INTDIR)\DecimalDatatypeValidator.obj"
	-@erase "$(INTDIR)\DeepNodeListImpl.obj"
	-@erase "$(INTDIR)\DFAContentModel.obj"
	-@erase "$(INTDIR)\DocumentFragmentImpl.obj"
	-@erase "$(INTDIR)\DocumentImpl.obj"
	-@erase "$(INTDIR)\DocumentTypeImpl.obj"
	-@erase "$(INTDIR)\DOM_Attr.obj"
	-@erase "$(INTDIR)\DOM_CDATASection.obj"
	-@erase "$(INTDIR)\DOM_CharacterData.obj"
	-@erase "$(INTDIR)\DOM_Comment.obj"
	-@erase "$(INTDIR)\DOM_Document.obj"
	-@erase "$(INTDIR)\DOM_DocumentFragment.obj"
	-@erase "$(INTDIR)\DOM_DocumentType.obj"
	-@erase "$(INTDIR)\DOM_DOMException.obj"
	-@erase "$(INTDIR)\DOM_DOMImplementation.obj"
	-@erase "$(INTDIR)\DOM_Element.obj"
	-@erase "$(INTDIR)\DOM_Entity.obj"
	-@erase "$(INTDIR)\DOM_EntityReference.obj"
	-@erase "$(INTDIR)\DOM_NamedNodeMap.obj"
	-@erase "$(INTDIR)\DOM_Node.obj"
	-@erase "$(INTDIR)\DOM_NodeFilter.obj"
	-@erase "$(INTDIR)\DOM_NodeIterator.obj"
	-@erase "$(INTDIR)\DOM_NodeList.obj"
	-@erase "$(INTDIR)\DOM_Notation.obj"
	-@erase "$(INTDIR)\DOM_ProcessingInstruction.obj"
	-@erase "$(INTDIR)\DOM_Range.obj"
	-@erase "$(INTDIR)\DOM_RangeException.obj"
	-@erase "$(INTDIR)\DOM_Text.obj"
	-@erase "$(INTDIR)\DOM_TreeWalker.obj"
	-@erase "$(INTDIR)\DOM_XMLDecl.obj"
	-@erase "$(INTDIR)\DOMAttrImpl.obj"
	-@erase "$(INTDIR)\DOMAttrMapImpl.obj"
	-@erase "$(INTDIR)\DOMAttrNSImpl.obj"
	-@erase "$(INTDIR)\DOMBuilderImpl.obj"
	-@erase "$(INTDIR)\DOMCDATASectionImpl.obj"
	-@erase "$(INTDIR)\DOMCharacterDataImpl.obj"
	-@erase "$(INTDIR)\DOMChildNode.obj"
	-@erase "$(INTDIR)\DOMCommentImpl.obj"
	-@erase "$(INTDIR)\DOMDeepNodeListImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentFragmentImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentTypeImpl.obj"
	-@erase "$(INTDIR)\DOMElementImpl.obj"
	-@erase "$(INTDIR)\DOMElementNSImpl.obj"
	-@erase "$(INTDIR)\DOMEntityImpl.obj"
	-@erase "$(INTDIR)\DOMEntityReferenceImpl.obj"
	-@erase "$(INTDIR)\DOMErrorImpl.obj"
	-@erase "$(INTDIR)\DOMException.obj"
	-@erase "$(INTDIR)\DOMImplementationImpl.obj"
	-@erase "$(INTDIR)\DOMImplementationRegistry.obj"
	-@erase "$(INTDIR)\DOMLocatorImpl.obj"
	-@erase "$(INTDIR)\DomMemDebug.obj"
	-@erase "$(INTDIR)\DOMNamedNodeMapImpl.obj"
	-@erase "$(INTDIR)\DOMNodeIDMap.obj"
	-@erase "$(INTDIR)\DOMNodeImpl.obj"
	-@erase "$(INTDIR)\DOMNodeIteratorImpl.obj"
	-@erase "$(INTDIR)\DOMNodeListImpl.obj"
	-@erase "$(INTDIR)\DOMNodeVector.obj"
	-@erase "$(INTDIR)\DOMNotationImpl.obj"
	-@erase "$(INTDIR)\DOMParentNode.obj"
	-@erase "$(INTDIR)\DOMParser.obj"
	-@erase "$(INTDIR)\DOMProcessingInstructionImpl.obj"
	-@erase "$(INTDIR)\DOMRangeException.obj"
	-@erase "$(INTDIR)\DOMRangeImpl.obj"
	-@erase "$(INTDIR)\DOMString.obj"
	-@erase "$(INTDIR)\DOMStringPool.obj"
	-@erase "$(INTDIR)\DOMTextImpl.obj"
	-@erase "$(INTDIR)\DOMTreeWalkerImpl.obj"
	-@erase "$(INTDIR)\DOMWriterImpl.obj"
	-@erase "$(INTDIR)\DoubleDatatypeValidator.obj"
	-@erase "$(INTDIR)\DStringPool.obj"
	-@erase "$(INTDIR)\DTDAttDef.obj"
	-@erase "$(INTDIR)\DTDAttDefList.obj"
	-@erase "$(INTDIR)\DTDElementDecl.obj"
	-@erase "$(INTDIR)\DTDGrammar.obj"
	-@erase "$(INTDIR)\DTDScanner.obj"
	-@erase "$(INTDIR)\DTDValidator.obj"
	-@erase "$(INTDIR)\Dummy.obj"
	-@erase "$(INTDIR)\DurationDatatypeValidator.obj"
	-@erase "$(INTDIR)\ElementDefinitionImpl.obj"
	-@erase "$(INTDIR)\ElementImpl.obj"
	-@erase "$(INTDIR)\ElementNSImpl.obj"
	-@erase "$(INTDIR)\ElemStack.obj"
	-@erase "$(INTDIR)\EncodingValidator.obj"
	-@erase "$(INTDIR)\ENTITYDatatypeValidator.obj"
	-@erase "$(INTDIR)\EntityImpl.obj"
	-@erase "$(INTDIR)\EntityReferenceImpl.obj"
	-@erase "$(INTDIR)\FieldActivator.obj"
	-@erase "$(INTDIR)\FieldValueMap.obj"
	-@erase "$(INTDIR)\FloatDatatypeValidator.obj"
	-@erase "$(INTDIR)\GeneralAttributeCheck.obj"
	-@erase "$(INTDIR)\GrammarResolver.obj"
	-@erase "$(INTDIR)\HashPtr.obj"
	-@erase "$(INTDIR)\HashXMLCh.obj"
	-@erase "$(INTDIR)\HeaderDummy.obj"
	-@erase "$(INTDIR)\HexBin.obj"
	-@erase "$(INTDIR)\HexBinaryDatatypeValidator.obj"
	-@erase "$(INTDIR)\IC_Field.obj"
	-@erase "$(INTDIR)\IC_Key.obj"
	-@erase "$(INTDIR)\IC_KeyRef.obj"
	-@erase "$(INTDIR)\IC_Selector.obj"
	-@erase "$(INTDIR)\IC_Unique.obj"
	-@erase "$(INTDIR)\IDDatatypeValidator.obj"
	-@erase "$(INTDIR)\IdentityConstraint.obj"
	-@erase "$(INTDIR)\IDREFDatatypeValidator.obj"
	-@erase "$(INTDIR)\InputSource.obj"
	-@erase "$(INTDIR)\KVStringPair.obj"
	-@erase "$(INTDIR)\ListDatatypeValidator.obj"
	-@erase "$(INTDIR)\LocalFileFormatTarget.obj"
	-@erase "$(INTDIR)\LocalFileInputSource.obj"
	-@erase "$(INTDIR)\Match.obj"
	-@erase "$(INTDIR)\MemBufFormatTarget.obj"
	-@erase "$(INTDIR)\MemBufInputSource.obj"
	-@erase "$(INTDIR)\MixedContentModel.obj"
	-@erase "$(INTDIR)\ModifierToken.obj"
	-@erase "$(INTDIR)\MonthDatatypeValidator.obj"
	-@erase "$(INTDIR)\MonthDayDatatypeValidator.obj"
	-@erase "$(INTDIR)\Mutexes.obj"
	-@erase "$(INTDIR)\NameDatatypeValidator.obj"
	-@erase "$(INTDIR)\NamedNodeMapImpl.obj"
	-@erase "$(INTDIR)\NamespaceScope.obj"
	-@erase "$(INTDIR)\NCNameDatatypeValidator.obj"
	-@erase "$(INTDIR)\NodeIDMap.obj"
	-@erase "$(INTDIR)\NodeImpl.obj"
	-@erase "$(INTDIR)\NodeIteratorImpl.obj"
	-@erase "$(INTDIR)\NodeListImpl.obj"
	-@erase "$(INTDIR)\NodeVector.obj"
	-@erase "$(INTDIR)\NOTATIONDatatypeValidator.obj"
	-@erase "$(INTDIR)\NotationImpl.obj"
	-@erase "$(INTDIR)\Op.obj"
	-@erase "$(INTDIR)\OpFactory.obj"
	-@erase "$(INTDIR)\ParentNode.obj"
	-@erase "$(INTDIR)\ParenToken.obj"
	-@erase "$(INTDIR)\ParserForXMLSchema.obj"
	-@erase "$(INTDIR)\PlatformUtils.obj"
	-@erase "$(INTDIR)\ProcessingInstructionImpl.obj"
	-@erase "$(INTDIR)\QName.obj"
	-@erase "$(INTDIR)\QNameDatatypeValidator.obj"
	-@erase "$(INTDIR)\RangeFactory.obj"
	-@erase "$(INTDIR)\RangeImpl.obj"
	-@erase "$(INTDIR)\RangeToken.obj"
	-@erase "$(INTDIR)\RangeTokenMap.obj"
	-@erase "$(INTDIR)\ReaderMgr.obj"
	-@erase "$(INTDIR)\RefCountedImpl.obj"
	-@erase "$(INTDIR)\RegularExpression.obj"
	-@erase "$(INTDIR)\RegxParser.obj"
	-@erase "$(INTDIR)\RegxUtil.obj"
	-@erase "$(INTDIR)\sax2Dummy.obj"
	-@erase "$(INTDIR)\SAX2XMLReaderImpl.obj"
	-@erase "$(INTDIR)\SAXException.obj"
	-@erase "$(INTDIR)\SAXParseException.obj"
	-@erase "$(INTDIR)\SAXParser.obj"
	-@erase "$(INTDIR)\SchemaAttDef.obj"
	-@erase "$(INTDIR)\SchemaAttDefList.obj"
	-@erase "$(INTDIR)\SchemaElementDecl.obj"
	-@erase "$(INTDIR)\SchemaGrammar.obj"
	-@erase "$(INTDIR)\SchemaInfo.obj"
	-@erase "$(INTDIR)\SchemaSymbols.obj"
	-@erase "$(INTDIR)\SchemaValidator.obj"
	-@erase "$(INTDIR)\SimpleContentModel.obj"
	-@erase "$(INTDIR)\StdInInputSource.obj"
	-@erase "$(INTDIR)\StdOutFormatTarget.obj"
	-@erase "$(INTDIR)\StringDatatypeValidator.obj"
	-@erase "$(INTDIR)\StringPool.obj"
	-@erase "$(INTDIR)\StringToken.obj"
	-@erase "$(INTDIR)\SubstitutionGroupComparator.obj"
	-@erase "$(INTDIR)\TextImpl.obj"
	-@erase "$(INTDIR)\TimeDatatypeValidator.obj"
	-@erase "$(INTDIR)\Token.obj"
	-@erase "$(INTDIR)\TokenFactory.obj"
	-@erase "$(INTDIR)\TransService.obj"
	-@erase "$(INTDIR)\TraverseSchema.obj"
	-@erase "$(INTDIR)\TreeWalkerImpl.obj"
	-@erase "$(INTDIR)\UnicodeRangeFactory.obj"
	-@erase "$(INTDIR)\UnionDatatypeValidator.obj"
	-@erase "$(INTDIR)\UnionToken.obj"
	-@erase "$(INTDIR)\URLInputSource.obj"
	-@erase "$(INTDIR)\ValueStore.obj"
	-@erase "$(INTDIR)\ValueStoreCache.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\VecAttributesImpl.obj"
	-@erase "$(INTDIR)\VecAttrListImpl.obj"
	-@erase "$(INTDIR)\Version.res"
	-@erase "$(INTDIR)\Win32MsgLoader.obj"
	-@erase "$(INTDIR)\Win32PlatformUtils.obj"
	-@erase "$(INTDIR)\Win32TransService.obj"
	-@erase "$(INTDIR)\WinSockNetAccessor.obj"
	-@erase "$(INTDIR)\Wrapper4DOMInputSource.obj"
	-@erase "$(INTDIR)\Wrapper4InputSource.obj"
	-@erase "$(INTDIR)\XercesAttGroupInfo.obj"
	-@erase "$(INTDIR)\XercesDOMParser.obj"
	-@erase "$(INTDIR)\XercesElementWildcard.obj"
	-@erase "$(INTDIR)\XercesGroupInfo.obj"
	-@erase "$(INTDIR)\XercesXPath.obj"
	-@erase "$(INTDIR)\XML256TableTranscoder.obj"
	-@erase "$(INTDIR)\XML88591Transcoder.obj"
	-@erase "$(INTDIR)\XMLAbstractDoubleFloat.obj"
	-@erase "$(INTDIR)\XMLASCIITranscoder.obj"
	-@erase "$(INTDIR)\XMLAttDef.obj"
	-@erase "$(INTDIR)\XMLAttr.obj"
	-@erase "$(INTDIR)\XMLBigDecimal.obj"
	-@erase "$(INTDIR)\XMLBigInteger.obj"
	-@erase "$(INTDIR)\XMLBuffer.obj"
	-@erase "$(INTDIR)\XMLBufferMgr.obj"
	-@erase "$(INTDIR)\XMLChTranscoder.obj"
	-@erase "$(INTDIR)\XMLContentModel.obj"
	-@erase "$(INTDIR)\XMLDateTime.obj"
	-@erase "$(INTDIR)\XMLDeclImpl.obj"
	-@erase "$(INTDIR)\XMLDouble.obj"
	-@erase "$(INTDIR)\XMLEBCDICTranscoder.obj"
	-@erase "$(INTDIR)\XMLElementDecl.obj"
	-@erase "$(INTDIR)\XMLEntityDecl.obj"
	-@erase "$(INTDIR)\XMLException.obj"
	-@erase "$(INTDIR)\XMLFloat.obj"
	-@erase "$(INTDIR)\XMLFormatter.obj"
	-@erase "$(INTDIR)\XMLIBM1140Transcoder.obj"
	-@erase "$(INTDIR)\XMLNotationDecl.obj"
	-@erase "$(INTDIR)\XMLMsgLoader.obj"
	-@erase "$(INTDIR)\XMLNumber.obj"
	-@erase "$(INTDIR)\XMLRangeFactory.obj"
	-@erase "$(INTDIR)\XMLReader.obj"
	-@erase "$(INTDIR)\XMLRecognizer.obj"
	-@erase "$(INTDIR)\XMLScanner.obj"
	-@erase "$(INTDIR)\XMLScanner2.obj"
	-@erase "$(INTDIR)\XMLString.obj"
	-@erase "$(INTDIR)\XMLStringTokenizer.obj"
	-@erase "$(INTDIR)\XMLUCSTranscoder.obj"
	-@erase "$(INTDIR)\XMLUni.obj"
	-@erase "$(INTDIR)\XMLUniCharacter.obj"
	-@erase "$(INTDIR)\XMLUri.obj"
	-@erase "$(INTDIR)\XMLURL.obj"
	-@erase "$(INTDIR)\XMLUTF16Transcoder.obj"
	-@erase "$(INTDIR)\XMLUTF8Transcoder.obj"
	-@erase "$(INTDIR)\XMLValidator.obj"
	-@erase "$(INTDIR)\XMLWin1252Transcoder.obj"
	-@erase "$(INTDIR)\XPathMatcher.obj"
	-@erase "$(INTDIR)\XPathMatcherStack.obj"
	-@erase "$(INTDIR)\XPathSymbols.obj"
	-@erase "$(INTDIR)\XSDDOMParser.obj"
	-@erase "$(INTDIR)\XSDElementNSImpl.obj"
	-@erase "$(INTDIR)\XSDErrorReporter.obj"
	-@erase "$(INTDIR)\XSDLocator.obj"
	-@erase "$(INTDIR)\XUtil.obj"
	-@erase "$(INTDIR)\YearDatatypeValidator.obj"
	-@erase "$(INTDIR)\YearMonthDatatypeValidator.obj"
	-@erase "$(OUTDIR)\xerces-c_2_1_0D.dll"
	-@erase "$(OUTDIR)\xerces-c_2_1_0D.ilk"
	-@erase "$(OUTDIR)\xerces-c_2_1_0D.pdb"
	-@erase "$(OUTDIR)\xerces-c_2D.exp"
	-@erase "$(OUTDIR)\xerces-c_2D.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=$(CPP)
CPP_PROJ=/MDd /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "WIN64" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=/D "_DEBUG" /mktyplib203 /o "NUL" /win32
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Version.res" /d "_DEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/o"$(OUTDIR)\XercesLib.bsc"
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib advapi32.lib ws2_32.lib /base:"0x12000000" /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\xerces-c_2_1_0D.pdb" /debug /machine:IX86 /out:"$(OUTDIR)\xerces-c_2_1_0D.dll" /implib:"$(OUTDIR)\xerces-c_2D.lib" /pdbtype:sept /version:2.0.0 /machine:IA64
LINK32_OBJS= \
	"$(INTDIR)\Win32PlatformUtils.obj" \
	"$(INTDIR)\Win32MsgLoader.obj" \
	"$(INTDIR)\Win32TransService.obj" \
	"$(INTDIR)\BinHTTPURLInputStream.obj" \
	"$(INTDIR)\WinSockNetAccessor.obj" \
	"$(INTDIR)\ASCIIRangeFactory.obj" \
	"$(INTDIR)\BlockRangeFactory.obj" \
	"$(INTDIR)\BMPattern.obj" \
	"$(INTDIR)\CharToken.obj" \
	"$(INTDIR)\ClosureToken.obj" \
	"$(INTDIR)\ConcatToken.obj" \
	"$(INTDIR)\ConditionToken.obj" \
	"$(INTDIR)\Match.obj" \
	"$(INTDIR)\ModifierToken.obj" \
	"$(INTDIR)\Op.obj" \
	"$(INTDIR)\OpFactory.obj" \
	"$(INTDIR)\ParenToken.obj" \
	"$(INTDIR)\ParserForXMLSchema.obj" \
	"$(INTDIR)\RangeFactory.obj" \
	"$(INTDIR)\RangeToken.obj" \
	"$(INTDIR)\RangeTokenMap.obj" \
	"$(INTDIR)\RegularExpression.obj" \
	"$(INTDIR)\RegxParser.obj" \
	"$(INTDIR)\RegxUtil.obj" \
	"$(INTDIR)\StringToken.obj" \
	"$(INTDIR)\Token.obj" \
	"$(INTDIR)\TokenFactory.obj" \
	"$(INTDIR)\UnicodeRangeFactory.obj" \
	"$(INTDIR)\UnionToken.obj" \
	"$(INTDIR)\XMLRangeFactory.obj" \
	"$(INTDIR)\XMLUniCharacter.obj" \
	"$(INTDIR)\Base64.obj" \
	"$(INTDIR)\BinFileInputStream.obj" \
	"$(INTDIR)\BinInputStream.obj" \
	"$(INTDIR)\BinMemInputStream.obj" \
	"$(INTDIR)\BitSet.obj" \
	"$(INTDIR)\EncodingValidator.obj" \
	"$(INTDIR)\HashPtr.obj" \
	"$(INTDIR)\HashXMLCh.obj" \
	"$(INTDIR)\HeaderDummy.obj" \
	"$(INTDIR)\HexBin.obj" \
	"$(INTDIR)\KVStringPair.obj" \
	"$(INTDIR)\Mutexes.obj" \
	"$(INTDIR)\PlatformUtils.obj" \
	"$(INTDIR)\QName.obj" \
	"$(INTDIR)\StringPool.obj" \
	"$(INTDIR)\TransService.obj" \
	"$(INTDIR)\XML256TableTranscoder.obj" \
	"$(INTDIR)\XML88591Transcoder.obj" \
	"$(INTDIR)\XMLAbstractDoubleFloat.obj" \
	"$(INTDIR)\XMLASCIITranscoder.obj" \
	"$(INTDIR)\XMLBigDecimal.obj" \
	"$(INTDIR)\XMLBigInteger.obj" \
	"$(INTDIR)\XMLChTranscoder.obj" \
	"$(INTDIR)\XMLDateTime.obj" \
	"$(INTDIR)\XMLDouble.obj" \
	"$(INTDIR)\XMLEBCDICTranscoder.obj" \
	"$(INTDIR)\XMLException.obj" \
	"$(INTDIR)\XMLFloat.obj" \
	"$(INTDIR)\XMLIBM1140Transcoder.obj" \
	"$(INTDIR)\XMLMsgLoader.obj" \
	"$(INTDIR)\XMLNumber.obj" \	
	"$(INTDIR)\XMLString.obj" \
	"$(INTDIR)\XMLStringTokenizer.obj" \
	"$(INTDIR)\XMLUCSTranscoder.obj" \
	"$(INTDIR)\XMLUni.obj" \
	"$(INTDIR)\XMLUri.obj" \
	"$(INTDIR)\XMLURL.obj" \
	"$(INTDIR)\XMLUTF16Transcoder.obj" \
	"$(INTDIR)\XMLUTF8Transcoder.obj" \
	"$(INTDIR)\XMLWin1252Transcoder.obj" \
	"$(INTDIR)\LocalFileFormatTarget.obj" \
	"$(INTDIR)\LocalFileInputSource.obj" \
	"$(INTDIR)\MemBufFormatTarget.obj" \
	"$(INTDIR)\MemBufInputSource.obj" \
	"$(INTDIR)\StdInInputSource.obj" \
	"$(INTDIR)\StdOutFormatTarget.obj" \
	"$(INTDIR)\URLInputSource.obj" \
	"$(INTDIR)\Wrapper4DOMInputSource.obj" \
	"$(INTDIR)\Wrapper4InputSource.obj" \
	"$(INTDIR)\XMLAttDef.obj" \
	"$(INTDIR)\XMLAttr.obj" \
	"$(INTDIR)\XMLBuffer.obj" \
	"$(INTDIR)\XMLBufferMgr.obj" \
	"$(INTDIR)\XMLContentModel.obj" \
	"$(INTDIR)\XMLElementDecl.obj" \
	"$(INTDIR)\XMLEntityDecl.obj" \
	"$(INTDIR)\XMLFormatter.obj" \
	"$(INTDIR)\XMLNotationDecl.obj" \
	"$(INTDIR)\XMLRecognizer.obj" \
	"$(INTDIR)\XMLValidator.obj" \
	"$(INTDIR)\ElemStack.obj" \
	"$(INTDIR)\ReaderMgr.obj" \
	"$(INTDIR)\VecAttributesImpl.obj" \
	"$(INTDIR)\VecAttrListImpl.obj" \
	"$(INTDIR)\XMLReader.obj" \
	"$(INTDIR)\XMLScanner.obj" \
	"$(INTDIR)\XMLScanner2.obj" \
	"$(INTDIR)\Dummy.obj" \
	"$(INTDIR)\InputSource.obj" \
	"$(INTDIR)\SAXException.obj" \
	"$(INTDIR)\SAXParseException.obj" \
	"$(INTDIR)\AbstractDOMParser.obj" \
	"$(INTDIR)\DOMBuilderImpl.obj" \
	"$(INTDIR)\SAX2XMLReaderImpl.obj" \
	"$(INTDIR)\SAXParser.obj" \
	"$(INTDIR)\XercesDOMParser.obj" \
	"$(INTDIR)\AllContentModel.obj" \
	"$(INTDIR)\CMAny.obj" \
	"$(INTDIR)\CMBinaryOp.obj" \
	"$(INTDIR)\CMUnaryOp.obj" \
	"$(INTDIR)\ContentLeafNameTypeVector.obj" \
	"$(INTDIR)\ContentSpecNode.obj" \
	"$(INTDIR)\DFAContentModel.obj" \
	"$(INTDIR)\GrammarResolver.obj" \
	"$(INTDIR)\MixedContentModel.obj" \
	"$(INTDIR)\SimpleContentModel.obj" \
	"$(INTDIR)\AbstractNumericFacetValidator.obj" \
	"$(INTDIR)\AbstractNumericValidator.obj" \
	"$(INTDIR)\AbstractStringValidator.obj" \
	"$(INTDIR)\AnySimpleTypeDatatypeValidator.obj" \
	"$(INTDIR)\AnyURIDatatypeValidator.obj" \
	"$(INTDIR)\Base64BinaryDatatypeValidator.obj" \
	"$(INTDIR)\BooleanDatatypeValidator.obj" \
	"$(INTDIR)\DatatypeValidator.obj" \
	"$(INTDIR)\DatatypeValidatorFactory.obj" \
	"$(INTDIR)\DateDatatypeValidator.obj" \
	"$(INTDIR)\DateTimeDatatypeValidator.obj" \
	"$(INTDIR)\DateTimeValidator.obj" \
	"$(INTDIR)\DayDatatypeValidator.obj" \
	"$(INTDIR)\DecimalDatatypeValidator.obj" \
	"$(INTDIR)\DoubleDatatypeValidator.obj" \
	"$(INTDIR)\DurationDatatypeValidator.obj" \
	"$(INTDIR)\ENTITYDatatypeValidator.obj" \
	"$(INTDIR)\FloatDatatypeValidator.obj" \
	"$(INTDIR)\HexBinaryDatatypeValidator.obj" \
	"$(INTDIR)\IDDatatypeValidator.obj" \
	"$(INTDIR)\IDREFDatatypeValidator.obj" \
	"$(INTDIR)\ListDatatypeValidator.obj" \
	"$(INTDIR)\MonthDatatypeValidator.obj" \
	"$(INTDIR)\MonthDayDatatypeValidator.obj" \
	"$(INTDIR)\NameDatatypeValidator.obj" \
	"$(INTDIR)\NCNameDatatypeValidator.obj" \
	"$(INTDIR)\NOTATIONDatatypeValidator.obj" \
	"$(INTDIR)\QNameDatatypeValidator.obj" \
	"$(INTDIR)\StringDatatypeValidator.obj" \
	"$(INTDIR)\TimeDatatypeValidator.obj" \
	"$(INTDIR)\UnionDatatypeValidator.obj" \
	"$(INTDIR)\YearDatatypeValidator.obj" \
	"$(INTDIR)\YearMonthDatatypeValidator.obj" \
	"$(INTDIR)\DTDAttDef.obj" \
	"$(INTDIR)\DTDAttDefList.obj" \
	"$(INTDIR)\DTDElementDecl.obj" \
	"$(INTDIR)\DTDGrammar.obj" \
	"$(INTDIR)\DTDScanner.obj" \
	"$(INTDIR)\DTDValidator.obj" \
	"$(INTDIR)\FieldActivator.obj" \
	"$(INTDIR)\FieldValueMap.obj" \
	"$(INTDIR)\IC_Field.obj" \
	"$(INTDIR)\IC_Key.obj" \
	"$(INTDIR)\IC_KeyRef.obj" \
	"$(INTDIR)\IC_Selector.obj" \
	"$(INTDIR)\IC_Unique.obj" \
	"$(INTDIR)\IdentityConstraint.obj" \
	"$(INTDIR)\ValueStore.obj" \
	"$(INTDIR)\ValueStoreCache.obj" \
	"$(INTDIR)\XercesXPath.obj" \
	"$(INTDIR)\XPathMatcher.obj" \
	"$(INTDIR)\XPathMatcherStack.obj" \
	"$(INTDIR)\XPathSymbols.obj" \
	"$(INTDIR)\ComplexTypeInfo.obj" \
	"$(INTDIR)\GeneralAttributeCheck.obj" \
	"$(INTDIR)\NamespaceScope.obj" \
	"$(INTDIR)\SchemaAttDef.obj" \
	"$(INTDIR)\SchemaAttDefList.obj" \
	"$(INTDIR)\SchemaElementDecl.obj" \
	"$(INTDIR)\SchemaGrammar.obj" \
	"$(INTDIR)\SchemaInfo.obj" \
	"$(INTDIR)\SchemaSymbols.obj" \
	"$(INTDIR)\SchemaValidator.obj" \
	"$(INTDIR)\SubstitutionGroupComparator.obj" \
	"$(INTDIR)\TraverseSchema.obj" \
	"$(INTDIR)\XercesAttGroupInfo.obj" \
	"$(INTDIR)\XercesElementWildcard.obj" \
	"$(INTDIR)\XercesGroupInfo.obj" \
	"$(INTDIR)\XSDDOMParser.obj" \
	"$(INTDIR)\XSDErrorReporter.obj" \
	"$(INTDIR)\XSDLocator.obj" \
	"$(INTDIR)\XUtil.obj" \
	"$(INTDIR)\sax2Dummy.obj" \
	"$(INTDIR)\DOMAttrImpl.obj" \
	"$(INTDIR)\DOMAttrMapImpl.obj" \
	"$(INTDIR)\DOMAttrNSImpl.obj" \
	"$(INTDIR)\DOMCDATASectionImpl.obj" \
	"$(INTDIR)\DOMCharacterDataImpl.obj" \
	"$(INTDIR)\DOMChildNode.obj" \
	"$(INTDIR)\DOMCommentImpl.obj" \
	"$(INTDIR)\DOMDeepNodeListImpl.obj" \
	"$(INTDIR)\DOMDocumentFragmentImpl.obj" \
	"$(INTDIR)\DOMDocumentImpl.obj" \
	"$(INTDIR)\DOMDocumentTypeImpl.obj" \
	"$(INTDIR)\DOMElementImpl.obj" \
	"$(INTDIR)\DOMElementNSImpl.obj" \
	"$(INTDIR)\DOMEntityImpl.obj" \
	"$(INTDIR)\DOMEntityReferenceImpl.obj" \
	"$(INTDIR)\DOMErrorImpl.obj" \
	"$(INTDIR)\DOMImplementationImpl.obj" \
	"$(INTDIR)\DOMImplementationRegistry.obj" \
	"$(INTDIR)\DOMLocatorImpl.obj" \
	"$(INTDIR)\DOMNamedNodeMapImpl.obj" \
	"$(INTDIR)\DOMNodeIDMap.obj" \
	"$(INTDIR)\DOMNodeImpl.obj" \
	"$(INTDIR)\DOMNodeIteratorImpl.obj" \
	"$(INTDIR)\DOMNodeListImpl.obj" \
	"$(INTDIR)\DOMNodeVector.obj" \
	"$(INTDIR)\DOMNotationImpl.obj" \
	"$(INTDIR)\DOMParentNode.obj" \
	"$(INTDIR)\DOMProcessingInstructionImpl.obj" \
	"$(INTDIR)\DOMRangeImpl.obj" \
	"$(INTDIR)\DOMStringPool.obj" \
	"$(INTDIR)\DOMTextImpl.obj" \
	"$(INTDIR)\DOMTreeWalkerImpl.obj" \
	"$(INTDIR)\DOMWriterImpl.obj" \
	"$(INTDIR)\XSDElementNSImpl.obj" \
	"$(INTDIR)\AttrImpl.obj" \
	"$(INTDIR)\AttrMapImpl.obj" \
	"$(INTDIR)\AttrNSImpl.obj" \
	"$(INTDIR)\CDATASectionImpl.obj" \
	"$(INTDIR)\CharacterDataImpl.obj" \
	"$(INTDIR)\ChildNode.obj" \
	"$(INTDIR)\CommentImpl.obj" \
	"$(INTDIR)\DeepNodeListImpl.obj" \
	"$(INTDIR)\DocumentFragmentImpl.obj" \
	"$(INTDIR)\DocumentImpl.obj" \
	"$(INTDIR)\DocumentTypeImpl.obj" \
	"$(INTDIR)\DOM_Attr.obj" \
	"$(INTDIR)\DOM_CDATASection.obj" \
	"$(INTDIR)\DOM_CharacterData.obj" \
	"$(INTDIR)\DOM_Comment.obj" \
	"$(INTDIR)\DOM_Document.obj" \
	"$(INTDIR)\DOM_DocumentFragment.obj" \
	"$(INTDIR)\DOM_DocumentType.obj" \
	"$(INTDIR)\DOM_DOMException.obj" \
	"$(INTDIR)\DOM_DOMImplementation.obj" \
	"$(INTDIR)\DOM_Element.obj" \
	"$(INTDIR)\DOM_Entity.obj" \
	"$(INTDIR)\DOM_EntityReference.obj" \
	"$(INTDIR)\DOM_NamedNodeMap.obj" \
	"$(INTDIR)\DOM_Node.obj" \
	"$(INTDIR)\DOM_NodeFilter.obj" \
	"$(INTDIR)\DOM_NodeIterator.obj" \
	"$(INTDIR)\DOM_NodeList.obj" \
	"$(INTDIR)\DOM_Notation.obj" \
	"$(INTDIR)\DOM_ProcessingInstruction.obj" \
	"$(INTDIR)\DOM_Range.obj" \
	"$(INTDIR)\DOM_RangeException.obj" \
	"$(INTDIR)\DOM_Text.obj" \
	"$(INTDIR)\DOM_TreeWalker.obj" \
	"$(INTDIR)\DOM_XMLDecl.obj" \
	"$(INTDIR)\DomMemDebug.obj" \
	"$(INTDIR)\DOMParser.obj" \
	"$(INTDIR)\DOMString.obj" \
	"$(INTDIR)\DStringPool.obj" \
	"$(INTDIR)\ElementDefinitionImpl.obj" \
	"$(INTDIR)\ElementImpl.obj" \
	"$(INTDIR)\ElementNSImpl.obj" \
	"$(INTDIR)\EntityImpl.obj" \
	"$(INTDIR)\EntityReferenceImpl.obj" \
	"$(INTDIR)\NamedNodeMapImpl.obj" \
	"$(INTDIR)\NodeIDMap.obj" \
	"$(INTDIR)\NodeImpl.obj" \
	"$(INTDIR)\NodeIteratorImpl.obj" \
	"$(INTDIR)\NodeListImpl.obj" \
	"$(INTDIR)\NodeVector.obj" \
	"$(INTDIR)\NotationImpl.obj" \
	"$(INTDIR)\ParentNode.obj" \
	"$(INTDIR)\ProcessingInstructionImpl.obj" \
	"$(INTDIR)\RangeImpl.obj" \
	"$(INTDIR)\RefCountedImpl.obj" \
	"$(INTDIR)\TextImpl.obj" \
	"$(INTDIR)\TreeWalkerImpl.obj" \
	"$(INTDIR)\XMLDeclImpl.obj" \
	"$(INTDIR)\DOMException.obj" \
	"$(INTDIR)\DOMRangeException.obj" \
	"$(INTDIR)\Version.res"

"$(OUTDIR)\xerces-c_2_1_0D.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "XercesLib - Win64 Release"

OUTDIR=.\..\..\..\..\..\Build\Win64\VC6\Release
INTDIR=.\..\..\..\..\..\Build\Win64\VC6\Release\obj
# Begin Custom Macros
OutDir=.\..\..\..\..\..\Build\Win64\VC6\Release
# End Custom Macros

ALL : "$(OUTDIR)\xerces-c_2_1_0.dll"


CLEAN :
	-@erase "$(INTDIR)\AbstractDOMParser.obj"
	-@erase "$(INTDIR)\AbstractNumericFacetValidator.obj"
	-@erase "$(INTDIR)\AbstractNumericValidator.obj"
	-@erase "$(INTDIR)\AbstractStringValidator.obj"
	-@erase "$(INTDIR)\AllContentModel.obj"
	-@erase "$(INTDIR)\AnySimpleTypeDatatypeValidator.obj"
	-@erase "$(INTDIR)\AnyURIDatatypeValidator.obj"
	-@erase "$(INTDIR)\ASCIIRangeFactory.obj"
	-@erase "$(INTDIR)\AttrImpl.obj"
	-@erase "$(INTDIR)\AttrMapImpl.obj"
	-@erase "$(INTDIR)\AttrNSImpl.obj"
	-@erase "$(INTDIR)\Base64.obj"
	-@erase "$(INTDIR)\Base64BinaryDatatypeValidator.obj"
	-@erase "$(INTDIR)\BinFileInputStream.obj"
	-@erase "$(INTDIR)\BinHTTPURLInputStream.obj"
	-@erase "$(INTDIR)\BinInputStream.obj"
	-@erase "$(INTDIR)\BinMemInputStream.obj"
	-@erase "$(INTDIR)\BitSet.obj"
	-@erase "$(INTDIR)\BlockRangeFactory.obj"
	-@erase "$(INTDIR)\BMPattern.obj"
	-@erase "$(INTDIR)\BooleanDatatypeValidator.obj"
	-@erase "$(INTDIR)\CDATASectionImpl.obj"
	-@erase "$(INTDIR)\CharacterDataImpl.obj"
	-@erase "$(INTDIR)\CharToken.obj"
	-@erase "$(INTDIR)\ChildNode.obj"
	-@erase "$(INTDIR)\ClosureToken.obj"
	-@erase "$(INTDIR)\CMAny.obj"
	-@erase "$(INTDIR)\CMBinaryOp.obj"
	-@erase "$(INTDIR)\CMUnaryOp.obj"
	-@erase "$(INTDIR)\CommentImpl.obj"
	-@erase "$(INTDIR)\ComplexTypeInfo.obj"
	-@erase "$(INTDIR)\ConcatToken.obj"
	-@erase "$(INTDIR)\ConditionToken.obj"
	-@erase "$(INTDIR)\ContentLeafNameTypeVector.obj"
	-@erase "$(INTDIR)\ContentSpecNode.obj"
	-@erase "$(INTDIR)\DatatypeValidator.obj"
	-@erase "$(INTDIR)\DatatypeValidatorFactory.obj"
	-@erase "$(INTDIR)\DateDatatypeValidator.obj"
	-@erase "$(INTDIR)\DateTimeDatatypeValidator.obj"
	-@erase "$(INTDIR)\DateTimeValidator.obj"
	-@erase "$(INTDIR)\DayDatatypeValidator.obj"
	-@erase "$(INTDIR)\DecimalDatatypeValidator.obj"
	-@erase "$(INTDIR)\DeepNodeListImpl.obj"
	-@erase "$(INTDIR)\DFAContentModel.obj"
	-@erase "$(INTDIR)\DocumentFragmentImpl.obj"
	-@erase "$(INTDIR)\DocumentImpl.obj"
	-@erase "$(INTDIR)\DocumentTypeImpl.obj"
	-@erase "$(INTDIR)\DOM_Attr.obj"
	-@erase "$(INTDIR)\DOM_CDATASection.obj"
	-@erase "$(INTDIR)\DOM_CharacterData.obj"
	-@erase "$(INTDIR)\DOM_Comment.obj"
	-@erase "$(INTDIR)\DOM_Document.obj"
	-@erase "$(INTDIR)\DOM_DocumentFragment.obj"
	-@erase "$(INTDIR)\DOM_DocumentType.obj"
	-@erase "$(INTDIR)\DOM_DOMException.obj"
	-@erase "$(INTDIR)\DOM_DOMImplementation.obj"
	-@erase "$(INTDIR)\DOM_Element.obj"
	-@erase "$(INTDIR)\DOM_Entity.obj"
	-@erase "$(INTDIR)\DOM_EntityReference.obj"
	-@erase "$(INTDIR)\DOM_NamedNodeMap.obj"
	-@erase "$(INTDIR)\DOM_Node.obj"
	-@erase "$(INTDIR)\DOM_NodeFilter.obj"
	-@erase "$(INTDIR)\DOM_NodeIterator.obj"
	-@erase "$(INTDIR)\DOM_NodeList.obj"
	-@erase "$(INTDIR)\DOM_Notation.obj"
	-@erase "$(INTDIR)\DOM_ProcessingInstruction.obj"
	-@erase "$(INTDIR)\DOM_Range.obj"
	-@erase "$(INTDIR)\DOM_RangeException.obj"
	-@erase "$(INTDIR)\DOM_Text.obj"
	-@erase "$(INTDIR)\DOM_TreeWalker.obj"
	-@erase "$(INTDIR)\DOM_XMLDecl.obj"
	-@erase "$(INTDIR)\DOMAttrImpl.obj"
	-@erase "$(INTDIR)\DOMAttrMapImpl.obj"
	-@erase "$(INTDIR)\DOMAttrNSImpl.obj"
	-@erase "$(INTDIR)\DOMBuilderImpl.obj"
	-@erase "$(INTDIR)\DOMCDATASectionImpl.obj"
	-@erase "$(INTDIR)\DOMCharacterDataImpl.obj"
	-@erase "$(INTDIR)\DOMChildNode.obj"
	-@erase "$(INTDIR)\DOMCommentImpl.obj"
	-@erase "$(INTDIR)\DOMDeepNodeListImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentFragmentImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentImpl.obj"
	-@erase "$(INTDIR)\DOMDocumentTypeImpl.obj"
	-@erase "$(INTDIR)\DOMElementImpl.obj"
	-@erase "$(INTDIR)\DOMElementNSImpl.obj"
	-@erase "$(INTDIR)\DOMEntityImpl.obj"
	-@erase "$(INTDIR)\DOMEntityReferenceImpl.obj"
	-@erase "$(INTDIR)\DOMErrorImpl.obj"
	-@erase "$(INTDIR)\DOMException.obj"
	-@erase "$(INTDIR)\DOMImplementationImpl.obj"
	-@erase "$(INTDIR)\DOMImplementationRegistry.obj"
	-@erase "$(INTDIR)\DOMLocatorImpl.obj"
	-@erase "$(INTDIR)\DomMemDebug.obj"
	-@erase "$(INTDIR)\DOMNamedNodeMapImpl.obj"
	-@erase "$(INTDIR)\DOMNodeIDMap.obj"
	-@erase "$(INTDIR)\DOMNodeImpl.obj"
	-@erase "$(INTDIR)\DOMNodeIteratorImpl.obj"
	-@erase "$(INTDIR)\DOMNodeListImpl.obj"
	-@erase "$(INTDIR)\DOMNodeVector.obj"
	-@erase "$(INTDIR)\DOMNotationImpl.obj"
	-@erase "$(INTDIR)\DOMParentNode.obj"
	-@erase "$(INTDIR)\DOMParser.obj"
	-@erase "$(INTDIR)\DOMProcessingInstructionImpl.obj"
	-@erase "$(INTDIR)\DOMRangeException.obj"
	-@erase "$(INTDIR)\DOMRangeImpl.obj"
	-@erase "$(INTDIR)\DOMString.obj"
	-@erase "$(INTDIR)\DOMStringPool.obj"
	-@erase "$(INTDIR)\DOMTextImpl.obj"
	-@erase "$(INTDIR)\DOMTreeWalkerImpl.obj"
	-@erase "$(INTDIR)\DOMWriterImpl.obj"
	-@erase "$(INTDIR)\DoubleDatatypeValidator.obj"
	-@erase "$(INTDIR)\DStringPool.obj"
	-@erase "$(INTDIR)\DTDAttDef.obj"
	-@erase "$(INTDIR)\DTDAttDefList.obj"
	-@erase "$(INTDIR)\DTDElementDecl.obj"
	-@erase "$(INTDIR)\DTDGrammar.obj"
	-@erase "$(INTDIR)\DTDScanner.obj"
	-@erase "$(INTDIR)\DTDValidator.obj"
	-@erase "$(INTDIR)\Dummy.obj"
	-@erase "$(INTDIR)\DurationDatatypeValidator.obj"
	-@erase "$(INTDIR)\ElementDefinitionImpl.obj"
	-@erase "$(INTDIR)\ElementImpl.obj"
	-@erase "$(INTDIR)\ElementNSImpl.obj"
	-@erase "$(INTDIR)\ElemStack.obj"
	-@erase "$(INTDIR)\EncodingValidator.obj"
	-@erase "$(INTDIR)\ENTITYDatatypeValidator.obj"
	-@erase "$(INTDIR)\EntityImpl.obj"
	-@erase "$(INTDIR)\EntityReferenceImpl.obj"
	-@erase "$(INTDIR)\FieldActivator.obj"
	-@erase "$(INTDIR)\FieldValueMap.obj"
	-@erase "$(INTDIR)\FloatDatatypeValidator.obj"
	-@erase "$(INTDIR)\GeneralAttributeCheck.obj"
	-@erase "$(INTDIR)\GrammarResolver.obj"
	-@erase "$(INTDIR)\HashPtr.obj"
	-@erase "$(INTDIR)\HashXMLCh.obj"
	-@erase "$(INTDIR)\HeaderDummy.obj"
	-@erase "$(INTDIR)\HexBin.obj"
	-@erase "$(INTDIR)\HexBinaryDatatypeValidator.obj"
	-@erase "$(INTDIR)\IC_Field.obj"
	-@erase "$(INTDIR)\IC_Key.obj"
	-@erase "$(INTDIR)\IC_KeyRef.obj"
	-@erase "$(INTDIR)\IC_Selector.obj"
	-@erase "$(INTDIR)\IC_Unique.obj"
	-@erase "$(INTDIR)\IDDatatypeValidator.obj"
	-@erase "$(INTDIR)\IdentityConstraint.obj"
	-@erase "$(INTDIR)\IDREFDatatypeValidator.obj"
	-@erase "$(INTDIR)\InputSource.obj"
	-@erase "$(INTDIR)\KVStringPair.obj"
	-@erase "$(INTDIR)\ListDatatypeValidator.obj"
	-@erase "$(INTDIR)\LocalFileFormatTarget.obj"
	-@erase "$(INTDIR)\LocalFileInputSource.obj"
	-@erase "$(INTDIR)\Match.obj"
	-@erase "$(INTDIR)\MemBufFormatTarget.obj"
	-@erase "$(INTDIR)\MemBufInputSource.obj"
	-@erase "$(INTDIR)\MixedContentModel.obj"
	-@erase "$(INTDIR)\ModifierToken.obj"
	-@erase "$(INTDIR)\MonthDatatypeValidator.obj"
	-@erase "$(INTDIR)\MonthDayDatatypeValidator.obj"
	-@erase "$(INTDIR)\Mutexes.obj"
	-@erase "$(INTDIR)\NameDatatypeValidator.obj"
	-@erase "$(INTDIR)\NamedNodeMapImpl.obj"
	-@erase "$(INTDIR)\NamespaceScope.obj"
	-@erase "$(INTDIR)\NCNameDatatypeValidator.obj"
	-@erase "$(INTDIR)\NodeIDMap.obj"
	-@erase "$(INTDIR)\NodeImpl.obj"
	-@erase "$(INTDIR)\NodeIteratorImpl.obj"
	-@erase "$(INTDIR)\NodeListImpl.obj"
	-@erase "$(INTDIR)\NodeVector.obj"
	-@erase "$(INTDIR)\NOTATIONDatatypeValidator.obj"
	-@erase "$(INTDIR)\NotationImpl.obj"
	-@erase "$(INTDIR)\Op.obj"
	-@erase "$(INTDIR)\OpFactory.obj"
	-@erase "$(INTDIR)\ParentNode.obj"
	-@erase "$(INTDIR)\ParenToken.obj"
	-@erase "$(INTDIR)\ParserForXMLSchema.obj"
	-@erase "$(INTDIR)\PlatformUtils.obj"
	-@erase "$(INTDIR)\ProcessingInstructionImpl.obj"
	-@erase "$(INTDIR)\QName.obj"
	-@erase "$(INTDIR)\QNameDatatypeValidator.obj"
	-@erase "$(INTDIR)\RangeFactory.obj"
	-@erase "$(INTDIR)\RangeImpl.obj"
	-@erase "$(INTDIR)\RangeToken.obj"
	-@erase "$(INTDIR)\RangeTokenMap.obj"
	-@erase "$(INTDIR)\ReaderMgr.obj"
	-@erase "$(INTDIR)\RefCountedImpl.obj"
	-@erase "$(INTDIR)\RegularExpression.obj"
	-@erase "$(INTDIR)\RegxParser.obj"
	-@erase "$(INTDIR)\RegxUtil.obj"
	-@erase "$(INTDIR)\sax2Dummy.obj"
	-@erase "$(INTDIR)\SAX2XMLReaderImpl.obj"
	-@erase "$(INTDIR)\SAXException.obj"
	-@erase "$(INTDIR)\SAXParseException.obj"
	-@erase "$(INTDIR)\SAXParser.obj"
	-@erase "$(INTDIR)\SchemaAttDef.obj"
	-@erase "$(INTDIR)\SchemaAttDefList.obj"
	-@erase "$(INTDIR)\SchemaElementDecl.obj"
	-@erase "$(INTDIR)\SchemaGrammar.obj"
	-@erase "$(INTDIR)\SchemaInfo.obj"
	-@erase "$(INTDIR)\SchemaSymbols.obj"
	-@erase "$(INTDIR)\SchemaValidator.obj"
	-@erase "$(INTDIR)\SimpleContentModel.obj"
	-@erase "$(INTDIR)\StdInInputSource.obj"
	-@erase "$(INTDIR)\StdOutFormatTarget.obj"
	-@erase "$(INTDIR)\StringDatatypeValidator.obj"
	-@erase "$(INTDIR)\StringPool.obj"
	-@erase "$(INTDIR)\StringToken.obj"
	-@erase "$(INTDIR)\SubstitutionGroupComparator.obj"
	-@erase "$(INTDIR)\TextImpl.obj"
	-@erase "$(INTDIR)\TimeDatatypeValidator.obj"
	-@erase "$(INTDIR)\Token.obj"
	-@erase "$(INTDIR)\TokenFactory.obj"
	-@erase "$(INTDIR)\TransService.obj"
	-@erase "$(INTDIR)\TraverseSchema.obj"
	-@erase "$(INTDIR)\TreeWalkerImpl.obj"
	-@erase "$(INTDIR)\UnicodeRangeFactory.obj"
	-@erase "$(INTDIR)\UnionDatatypeValidator.obj"
	-@erase "$(INTDIR)\UnionToken.obj"
	-@erase "$(INTDIR)\URLInputSource.obj"
	-@erase "$(INTDIR)\ValueStore.obj"
	-@erase "$(INTDIR)\ValueStoreCache.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\VecAttributesImpl.obj"
	-@erase "$(INTDIR)\VecAttrListImpl.obj"
	-@erase "$(INTDIR)\Version.res"
	-@erase "$(INTDIR)\Win32MsgLoader.obj"
	-@erase "$(INTDIR)\Win32PlatformUtils.obj"
	-@erase "$(INTDIR)\Win32TransService.obj"
	-@erase "$(INTDIR)\WinSockNetAccessor.obj"
	-@erase "$(INTDIR)\Wrapper4DOMInputSource.obj"
	-@erase "$(INTDIR)\Wrapper4InputSource.obj"
	-@erase "$(INTDIR)\XercesAttGroupInfo.obj"
	-@erase "$(INTDIR)\XercesDOMParser.obj"
	-@erase "$(INTDIR)\XercesElementWildcard.obj"
	-@erase "$(INTDIR)\XercesGroupInfo.obj"
	-@erase "$(INTDIR)\XercesXPath.obj"
	-@erase "$(INTDIR)\XML256TableTranscoder.obj"
	-@erase "$(INTDIR)\XML88591Transcoder.obj"
	-@erase "$(INTDIR)\XMLAbstractDoubleFloat.obj"
	-@erase "$(INTDIR)\XMLASCIITranscoder.obj"
	-@erase "$(INTDIR)\XMLAttDef.obj"
	-@erase "$(INTDIR)\XMLAttr.obj"
	-@erase "$(INTDIR)\XMLBigDecimal.obj"
	-@erase "$(INTDIR)\XMLBigInteger.obj"
	-@erase "$(INTDIR)\XMLBuffer.obj"
	-@erase "$(INTDIR)\XMLBufferMgr.obj"
	-@erase "$(INTDIR)\XMLChTranscoder.obj"
	-@erase "$(INTDIR)\XMLContentModel.obj"
	-@erase "$(INTDIR)\XMLDateTime.obj"
	-@erase "$(INTDIR)\XMLDeclImpl.obj"
	-@erase "$(INTDIR)\XMLDouble.obj"
	-@erase "$(INTDIR)\XMLEBCDICTranscoder.obj"
	-@erase "$(INTDIR)\XMLElementDecl.obj"
	-@erase "$(INTDIR)\XMLEntityDecl.obj"
	-@erase "$(INTDIR)\XMLException.obj"
	-@erase "$(INTDIR)\XMLFloat.obj"
	-@erase "$(INTDIR)\XMLFormatter.obj"
	-@erase "$(INTDIR)\XMLIBM1140Transcoder.obj"
	-@erase "$(INTDIR)\XMLNotationDecl.obj"
	-@erase "$(INTDIR)\XMLMsgLoader.obj"
	-@erase "$(INTDIR)\XMLNumber.obj"	
	-@erase "$(INTDIR)\XMLRangeFactory.obj"
	-@erase "$(INTDIR)\XMLReader.obj"
	-@erase "$(INTDIR)\XMLRecognizer.obj"
	-@erase "$(INTDIR)\XMLScanner.obj"
	-@erase "$(INTDIR)\XMLScanner2.obj"
	-@erase "$(INTDIR)\XMLString.obj"
	-@erase "$(INTDIR)\XMLStringTokenizer.obj"
	-@erase "$(INTDIR)\XMLUCSTranscoder.obj"
	-@erase "$(INTDIR)\XMLUni.obj"
	-@erase "$(INTDIR)\XMLUniCharacter.obj"
	-@erase "$(INTDIR)\XMLUri.obj"
	-@erase "$(INTDIR)\XMLURL.obj"
	-@erase "$(INTDIR)\XMLUTF16Transcoder.obj"
	-@erase "$(INTDIR)\XMLUTF8Transcoder.obj"
	-@erase "$(INTDIR)\XMLValidator.obj"
	-@erase "$(INTDIR)\XMLWin1252Transcoder.obj"
	-@erase "$(INTDIR)\XPathMatcher.obj"
	-@erase "$(INTDIR)\XPathMatcherStack.obj"
	-@erase "$(INTDIR)\XPathSymbols.obj"
	-@erase "$(INTDIR)\XSDDOMParser.obj"
	-@erase "$(INTDIR)\XSDElementNSImpl.obj"
	-@erase "$(INTDIR)\XSDErrorReporter.obj"
	-@erase "$(INTDIR)\XSDLocator.obj"
	-@erase "$(INTDIR)\XUtil.obj"
	-@erase "$(INTDIR)\YearDatatypeValidator.obj"
	-@erase "$(INTDIR)\YearMonthDatatypeValidator.obj"
	-@erase "$(OUTDIR)\obj\xerces-c_2_1_0.map"
	-@erase "$(OUTDIR)\xerces-c_2.exp"
	-@erase "$(OUTDIR)\xerces-c_2.lib"
	-@erase "$(OUTDIR)\xerces-c_2_1_0.dll"
	-@erase "$(OUTDIR)\xerces-c_2_1_0.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=$(CPP)
CPP_PROJ=/MD /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "WIN64" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $<
<<

MTL=midl.exe
MTL_PROJ=/D "NDEBUG" /mktyplib203 /o "NUL" /win32
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Version.res" /d "NDEBUG"
BSC32=bscmake.exe
BSC32_FLAGS=/o"$(OUTDIR)\XercesLib.bsc"
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib advapi32.lib ws2_32.lib /base:"0x12000000" /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\xerces-c_2_1_0.pdb" /map:"$(INTDIR)\xerces-c_2_1_0.map" /machine:IX86 /out:"$(OUTDIR)\xerces-c_2_1_0.dll" /implib:"$(OUTDIR)\xerces-c_2.lib" /version:2.0.0 /machine:IA64
LINK32_OBJS= \
	"$(INTDIR)\Win32PlatformUtils.obj" \
	"$(INTDIR)\Win32MsgLoader.obj" \
	"$(INTDIR)\Win32TransService.obj" \
	"$(INTDIR)\BinHTTPURLInputStream.obj" \
	"$(INTDIR)\WinSockNetAccessor.obj" \
	"$(INTDIR)\ASCIIRangeFactory.obj" \
	"$(INTDIR)\BlockRangeFactory.obj" \
	"$(INTDIR)\BMPattern.obj" \
	"$(INTDIR)\CharToken.obj" \
	"$(INTDIR)\ClosureToken.obj" \
	"$(INTDIR)\ConcatToken.obj" \
	"$(INTDIR)\ConditionToken.obj" \
	"$(INTDIR)\Match.obj" \
	"$(INTDIR)\ModifierToken.obj" \
	"$(INTDIR)\Op.obj" \
	"$(INTDIR)\OpFactory.obj" \
	"$(INTDIR)\ParenToken.obj" \
	"$(INTDIR)\ParserForXMLSchema.obj" \
	"$(INTDIR)\RangeFactory.obj" \
	"$(INTDIR)\RangeToken.obj" \
	"$(INTDIR)\RangeTokenMap.obj" \
	"$(INTDIR)\RegularExpression.obj" \
	"$(INTDIR)\RegxParser.obj" \
	"$(INTDIR)\RegxUtil.obj" \
	"$(INTDIR)\StringToken.obj" \
	"$(INTDIR)\Token.obj" \
	"$(INTDIR)\TokenFactory.obj" \
	"$(INTDIR)\UnicodeRangeFactory.obj" \
	"$(INTDIR)\UnionToken.obj" \
	"$(INTDIR)\XMLRangeFactory.obj" \
	"$(INTDIR)\XMLUniCharacter.obj" \
	"$(INTDIR)\Base64.obj" \
	"$(INTDIR)\BinFileInputStream.obj" \
	"$(INTDIR)\BinInputStream.obj" \
	"$(INTDIR)\BinMemInputStream.obj" \
	"$(INTDIR)\BitSet.obj" \
	"$(INTDIR)\EncodingValidator.obj" \
	"$(INTDIR)\HashPtr.obj" \
	"$(INTDIR)\HashXMLCh.obj" \
	"$(INTDIR)\HeaderDummy.obj" \
	"$(INTDIR)\HexBin.obj" \
	"$(INTDIR)\KVStringPair.obj" \
	"$(INTDIR)\Mutexes.obj" \
	"$(INTDIR)\PlatformUtils.obj" \
	"$(INTDIR)\QName.obj" \
	"$(INTDIR)\StringPool.obj" \
	"$(INTDIR)\TransService.obj" \
	"$(INTDIR)\XML256TableTranscoder.obj" \
	"$(INTDIR)\XML88591Transcoder.obj" \
	"$(INTDIR)\XMLAbstractDoubleFloat.obj" \
	"$(INTDIR)\XMLASCIITranscoder.obj" \
	"$(INTDIR)\XMLBigDecimal.obj" \
	"$(INTDIR)\XMLBigInteger.obj" \
	"$(INTDIR)\XMLChTranscoder.obj" \
	"$(INTDIR)\XMLDateTime.obj" \
	"$(INTDIR)\XMLDouble.obj" \
	"$(INTDIR)\XMLEBCDICTranscoder.obj" \
	"$(INTDIR)\XMLException.obj" \
	"$(INTDIR)\XMLFloat.obj" \
	"$(INTDIR)\XMLIBM1140Transcoder.obj" \
	"$(INTDIR)\XMLMsgLoader.obj" \
	"$(INTDIR)\XMLNumber.obj" \
	"$(INTDIR)\XMLString.obj" \
	"$(INTDIR)\XMLStringTokenizer.obj" \
	"$(INTDIR)\XMLUCSTranscoder.obj" \
	"$(INTDIR)\XMLUni.obj" \
	"$(INTDIR)\XMLUri.obj" \
	"$(INTDIR)\XMLURL.obj" \
	"$(INTDIR)\XMLUTF16Transcoder.obj" \
	"$(INTDIR)\XMLUTF8Transcoder.obj" \
	"$(INTDIR)\XMLWin1252Transcoder.obj" \
	"$(INTDIR)\LocalFileFormatTarget.obj" \
	"$(INTDIR)\LocalFileInputSource.obj" \
	"$(INTDIR)\MemBufFormatTarget.obj" \
	"$(INTDIR)\MemBufInputSource.obj" \
	"$(INTDIR)\StdInInputSource.obj" \
	"$(INTDIR)\StdOutFormatTarget.obj" \
	"$(INTDIR)\URLInputSource.obj" \
	"$(INTDIR)\Wrapper4DOMInputSource.obj" \
	"$(INTDIR)\Wrapper4InputSource.obj" \
	"$(INTDIR)\XMLAttDef.obj" \
	"$(INTDIR)\XMLAttr.obj" \
	"$(INTDIR)\XMLBuffer.obj" \
	"$(INTDIR)\XMLBufferMgr.obj" \
	"$(INTDIR)\XMLContentModel.obj" \
	"$(INTDIR)\XMLElementDecl.obj" \
	"$(INTDIR)\XMLEntityDecl.obj" \
	"$(INTDIR)\XMLFormatter.obj" \
	"$(INTDIR)\XMLNotationDecl.obj" \
	"$(INTDIR)\XMLRecognizer.obj" \
	"$(INTDIR)\XMLValidator.obj" \
	"$(INTDIR)\ElemStack.obj" \
	"$(INTDIR)\ReaderMgr.obj" \
	"$(INTDIR)\VecAttributesImpl.obj" \
	"$(INTDIR)\VecAttrListImpl.obj" \
	"$(INTDIR)\XMLReader.obj" \
	"$(INTDIR)\XMLScanner.obj" \
	"$(INTDIR)\XMLScanner2.obj" \
	"$(INTDIR)\Dummy.obj" \
	"$(INTDIR)\InputSource.obj" \
	"$(INTDIR)\SAXException.obj" \
	"$(INTDIR)\SAXParseException.obj" \
	"$(INTDIR)\AbstractDOMParser.obj" \
	"$(INTDIR)\DOMBuilderImpl.obj" \
	"$(INTDIR)\SAX2XMLReaderImpl.obj" \
	"$(INTDIR)\SAXParser.obj" \
	"$(INTDIR)\XercesDOMParser.obj" \
	"$(INTDIR)\AllContentModel.obj" \
	"$(INTDIR)\CMAny.obj" \
	"$(INTDIR)\CMBinaryOp.obj" \
	"$(INTDIR)\CMUnaryOp.obj" \
	"$(INTDIR)\ContentLeafNameTypeVector.obj" \
	"$(INTDIR)\ContentSpecNode.obj" \
	"$(INTDIR)\DFAContentModel.obj" \
	"$(INTDIR)\GrammarResolver.obj" \
	"$(INTDIR)\MixedContentModel.obj" \
	"$(INTDIR)\SimpleContentModel.obj" \
	"$(INTDIR)\AbstractNumericFacetValidator.obj" \
	"$(INTDIR)\AbstractNumericValidator.obj" \
	"$(INTDIR)\AbstractStringValidator.obj" \
	"$(INTDIR)\AnySimpleTypeDatatypeValidator.obj" \
	"$(INTDIR)\AnyURIDatatypeValidator.obj" \
	"$(INTDIR)\Base64BinaryDatatypeValidator.obj" \
	"$(INTDIR)\BooleanDatatypeValidator.obj" \
	"$(INTDIR)\DatatypeValidator.obj" \
	"$(INTDIR)\DatatypeValidatorFactory.obj" \
	"$(INTDIR)\DateDatatypeValidator.obj" \
	"$(INTDIR)\DateTimeDatatypeValidator.obj" \
	"$(INTDIR)\DateTimeValidator.obj" \
	"$(INTDIR)\DayDatatypeValidator.obj" \
	"$(INTDIR)\DecimalDatatypeValidator.obj" \
	"$(INTDIR)\DoubleDatatypeValidator.obj" \
	"$(INTDIR)\DurationDatatypeValidator.obj" \
	"$(INTDIR)\ENTITYDatatypeValidator.obj" \
	"$(INTDIR)\FloatDatatypeValidator.obj" \
	"$(INTDIR)\HexBinaryDatatypeValidator.obj" \
	"$(INTDIR)\IDDatatypeValidator.obj" \
	"$(INTDIR)\IDREFDatatypeValidator.obj" \
	"$(INTDIR)\ListDatatypeValidator.obj" \
	"$(INTDIR)\MonthDatatypeValidator.obj" \
	"$(INTDIR)\MonthDayDatatypeValidator.obj" \
	"$(INTDIR)\NameDatatypeValidator.obj" \
	"$(INTDIR)\NCNameDatatypeValidator.obj" \
	"$(INTDIR)\NOTATIONDatatypeValidator.obj" \
	"$(INTDIR)\QNameDatatypeValidator.obj" \
	"$(INTDIR)\StringDatatypeValidator.obj" \
	"$(INTDIR)\TimeDatatypeValidator.obj" \
	"$(INTDIR)\UnionDatatypeValidator.obj" \
	"$(INTDIR)\YearDatatypeValidator.obj" \
	"$(INTDIR)\YearMonthDatatypeValidator.obj" \
	"$(INTDIR)\DTDAttDef.obj" \
	"$(INTDIR)\DTDAttDefList.obj" \
	"$(INTDIR)\DTDElementDecl.obj" \
	"$(INTDIR)\DTDGrammar.obj" \
	"$(INTDIR)\DTDScanner.obj" \
	"$(INTDIR)\DTDValidator.obj" \
	"$(INTDIR)\FieldActivator.obj" \
	"$(INTDIR)\FieldValueMap.obj" \
	"$(INTDIR)\IC_Field.obj" \
	"$(INTDIR)\IC_Key.obj" \
	"$(INTDIR)\IC_KeyRef.obj" \
	"$(INTDIR)\IC_Selector.obj" \
	"$(INTDIR)\IC_Unique.obj" \
	"$(INTDIR)\IdentityConstraint.obj" \
	"$(INTDIR)\ValueStore.obj" \
	"$(INTDIR)\ValueStoreCache.obj" \
	"$(INTDIR)\XercesXPath.obj" \
	"$(INTDIR)\XPathMatcher.obj" \
	"$(INTDIR)\XPathMatcherStack.obj" \
	"$(INTDIR)\XPathSymbols.obj" \
	"$(INTDIR)\ComplexTypeInfo.obj" \
	"$(INTDIR)\GeneralAttributeCheck.obj" \
	"$(INTDIR)\NamespaceScope.obj" \
	"$(INTDIR)\SchemaAttDef.obj" \
	"$(INTDIR)\SchemaAttDefList.obj" \
	"$(INTDIR)\SchemaElementDecl.obj" \
	"$(INTDIR)\SchemaGrammar.obj" \
	"$(INTDIR)\SchemaInfo.obj" \
	"$(INTDIR)\SchemaSymbols.obj" \
	"$(INTDIR)\SchemaValidator.obj" \
	"$(INTDIR)\SubstitutionGroupComparator.obj" \
	"$(INTDIR)\TraverseSchema.obj" \
	"$(INTDIR)\XercesAttGroupInfo.obj" \
	"$(INTDIR)\XercesElementWildcard.obj" \
	"$(INTDIR)\XercesGroupInfo.obj" \
	"$(INTDIR)\XSDDOMParser.obj" \
	"$(INTDIR)\XSDErrorReporter.obj" \
	"$(INTDIR)\XSDLocator.obj" \
	"$(INTDIR)\XUtil.obj" \
	"$(INTDIR)\sax2Dummy.obj" \
	"$(INTDIR)\DOMAttrImpl.obj" \
	"$(INTDIR)\DOMAttrMapImpl.obj" \
	"$(INTDIR)\DOMAttrNSImpl.obj" \
	"$(INTDIR)\DOMCDATASectionImpl.obj" \
	"$(INTDIR)\DOMCharacterDataImpl.obj" \
	"$(INTDIR)\DOMChildNode.obj" \
	"$(INTDIR)\DOMCommentImpl.obj" \
	"$(INTDIR)\DOMDeepNodeListImpl.obj" \
	"$(INTDIR)\DOMDocumentFragmentImpl.obj" \
	"$(INTDIR)\DOMDocumentImpl.obj" \
	"$(INTDIR)\DOMDocumentTypeImpl.obj" \
	"$(INTDIR)\DOMElementImpl.obj" \
	"$(INTDIR)\DOMElementNSImpl.obj" \
	"$(INTDIR)\DOMEntityImpl.obj" \
	"$(INTDIR)\DOMEntityReferenceImpl.obj" \
	"$(INTDIR)\DOMErrorImpl.obj" \
	"$(INTDIR)\DOMImplementationImpl.obj" \
	"$(INTDIR)\DOMImplementationRegistry.obj" \
	"$(INTDIR)\DOMLocatorImpl.obj" \
	"$(INTDIR)\DOMNamedNodeMapImpl.obj" \
	"$(INTDIR)\DOMNodeIDMap.obj" \
	"$(INTDIR)\DOMNodeImpl.obj" \
	"$(INTDIR)\DOMNodeIteratorImpl.obj" \
	"$(INTDIR)\DOMNodeListImpl.obj" \
	"$(INTDIR)\DOMNodeVector.obj" \
	"$(INTDIR)\DOMNotationImpl.obj" \
	"$(INTDIR)\DOMParentNode.obj" \
	"$(INTDIR)\DOMProcessingInstructionImpl.obj" \
	"$(INTDIR)\DOMRangeImpl.obj" \
	"$(INTDIR)\DOMStringPool.obj" \
	"$(INTDIR)\DOMTextImpl.obj" \
	"$(INTDIR)\DOMTreeWalkerImpl.obj" \
	"$(INTDIR)\DOMWriterImpl.obj" \
	"$(INTDIR)\XSDElementNSImpl.obj" \
	"$(INTDIR)\AttrImpl.obj" \
	"$(INTDIR)\AttrMapImpl.obj" \
	"$(INTDIR)\AttrNSImpl.obj" \
	"$(INTDIR)\CDATASectionImpl.obj" \
	"$(INTDIR)\CharacterDataImpl.obj" \
	"$(INTDIR)\ChildNode.obj" \
	"$(INTDIR)\CommentImpl.obj" \
	"$(INTDIR)\DeepNodeListImpl.obj" \
	"$(INTDIR)\DocumentFragmentImpl.obj" \
	"$(INTDIR)\DocumentImpl.obj" \
	"$(INTDIR)\DocumentTypeImpl.obj" \
	"$(INTDIR)\DOM_Attr.obj" \
	"$(INTDIR)\DOM_CDATASection.obj" \
	"$(INTDIR)\DOM_CharacterData.obj" \
	"$(INTDIR)\DOM_Comment.obj" \
	"$(INTDIR)\DOM_Document.obj" \
	"$(INTDIR)\DOM_DocumentFragment.obj" \
	"$(INTDIR)\DOM_DocumentType.obj" \
	"$(INTDIR)\DOM_DOMException.obj" \
	"$(INTDIR)\DOM_DOMImplementation.obj" \
	"$(INTDIR)\DOM_Element.obj" \
	"$(INTDIR)\DOM_Entity.obj" \
	"$(INTDIR)\DOM_EntityReference.obj" \
	"$(INTDIR)\DOM_NamedNodeMap.obj" \
	"$(INTDIR)\DOM_Node.obj" \
	"$(INTDIR)\DOM_NodeFilter.obj" \
	"$(INTDIR)\DOM_NodeIterator.obj" \
	"$(INTDIR)\DOM_NodeList.obj" \
	"$(INTDIR)\DOM_Notation.obj" \
	"$(INTDIR)\DOM_ProcessingInstruction.obj" \
	"$(INTDIR)\DOM_Range.obj" \
	"$(INTDIR)\DOM_RangeException.obj" \
	"$(INTDIR)\DOM_Text.obj" \
	"$(INTDIR)\DOM_TreeWalker.obj" \
	"$(INTDIR)\DOM_XMLDecl.obj" \
	"$(INTDIR)\DomMemDebug.obj" \
	"$(INTDIR)\DOMParser.obj" \
	"$(INTDIR)\DOMString.obj" \
	"$(INTDIR)\DStringPool.obj" \
	"$(INTDIR)\ElementDefinitionImpl.obj" \
	"$(INTDIR)\ElementImpl.obj" \
	"$(INTDIR)\ElementNSImpl.obj" \
	"$(INTDIR)\EntityImpl.obj" \
	"$(INTDIR)\EntityReferenceImpl.obj" \
	"$(INTDIR)\NamedNodeMapImpl.obj" \
	"$(INTDIR)\NodeIDMap.obj" \
	"$(INTDIR)\NodeImpl.obj" \
	"$(INTDIR)\NodeIteratorImpl.obj" \
	"$(INTDIR)\NodeListImpl.obj" \
	"$(INTDIR)\NodeVector.obj" \
	"$(INTDIR)\NotationImpl.obj" \
	"$(INTDIR)\ParentNode.obj" \
	"$(INTDIR)\ProcessingInstructionImpl.obj" \
	"$(INTDIR)\RangeImpl.obj" \
	"$(INTDIR)\RefCountedImpl.obj" \
	"$(INTDIR)\TextImpl.obj" \
	"$(INTDIR)\TreeWalkerImpl.obj" \
	"$(INTDIR)\XMLDeclImpl.obj" \
	"$(INTDIR)\DOMException.obj" \
	"$(INTDIR)\DOMRangeException.obj" \
	"$(INTDIR)\Version.res"

"$(OUTDIR)\xerces-c_2_1_0.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("XercesLib.dep")
!INCLUDE "XercesLib.dep"
!ELSE
!MESSAGE Warning: cannot find "XercesLib.dep"
!ENDIF
!ENDIF


!IF "$(CFG)" == "XercesLib - Win32 Release" || "$(CFG)" == "XercesLib - Win32 Debug" || "$(CFG)" == "XercesLib - Win64 Debug" || "$(CFG)" == "XercesLib - Win64 Release"
SOURCE=..\..\..\..\..\src\xercesc\util\Platforms\Win32\Win32PlatformUtils.cpp

!IF  "$(CFG)" == "XercesLib - Win32 Release"

CPP_SWITCHES=/G6 /MD /Ze /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32PlatformUtils.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win32 Debug"

CPP_SWITCHES=/G6 /MDd /Ze /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32PlatformUtils.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Debug"

CPP_SWITCHES=/MDd /Ze /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "WIN64" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32PlatformUtils.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Release"

CPP_SWITCHES=/MD /Ze /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "WIN64" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32PlatformUtils.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF

SOURCE=..\..\..\..\..\src\xercesc\util\MsgLoaders\Win32\Win32MsgLoader.cpp

!IF  "$(CFG)" == "XercesLib - Win32 Release"

CPP_SWITCHES=/G6 /MD /Ze /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32MsgLoader.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win32 Debug"

CPP_SWITCHES=/G6 /MDd /Ze /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32MsgLoader.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Debug"

CPP_SWITCHES=/MDd /Ze /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "WIN64" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32MsgLoader.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Release"

CPP_SWITCHES=/MD /Ze /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "WIN64" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32MsgLoader.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF

SOURCE=..\..\..\..\..\src\xercesc\util\Transcoders\Win32\Win32TransService.cpp

!IF  "$(CFG)" == "XercesLib - Win32 Release"

CPP_SWITCHES=/G6 /MD /Ze /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32TransService.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win32 Debug"

CPP_SWITCHES=/G6 /MDd /Ze /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32TransService.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Debug"

CPP_SWITCHES=/MDd /Ze /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "WIN64" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32TransService.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Release"

CPP_SWITCHES=/MD /Ze /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "WIN64" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\Win32TransService.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF

SOURCE=..\..\..\..\..\src\xercesc\util\NetAccessors\WinSock\BinHTTPURLInputStream.cpp

!IF  "$(CFG)" == "XercesLib - Win32 Release"

CPP_SWITCHES=/G6 /MD /Ze /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\BinHTTPURLInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win32 Debug"

CPP_SWITCHES=/G6 /MDd /Ze /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\BinHTTPURLInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Debug"

CPP_SWITCHES=/MDd /Ze /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "WIN64" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\BinHTTPURLInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Release"

CPP_SWITCHES=/MD /Ze /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "WIN64" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\BinHTTPURLInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF

SOURCE=..\..\..\..\..\src\xercesc\util\NetAccessors\WinSock\WinSockNetAccessor.cpp

!IF  "$(CFG)" == "XercesLib - Win32 Release"

CPP_SWITCHES=/G6 /MD /Ze /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\WinSockNetAccessor.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win32 Debug"

CPP_SWITCHES=/G6 /MDd /Ze /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\WinSockNetAccessor.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Debug"

CPP_SWITCHES=/MDd /Ze /W3 /Gm /GX /Zi /Od /I "..\..\..\..\..\src" /D "WIN64" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_SAX2" /D "_DEBUG" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\WinSockNetAccessor.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Release"

CPP_SWITCHES=/MD /Ze /W3 /GX /O2 /Ob2 /I "..\..\..\..\..\src" /D "WIN64" /D "NDEBUG" /D "PLATFORM_WIN32" /D "_CRTDBG_MAP_ALLOC" /D "PROJ_XMLPARSER" /D "PROJ_XMLUTIL" /D "PROJ_PARSERS" /D "PROJ_SAX4C" /D "PROJ_SAX2" /D "PROJ_DOM" /D "PROJ_VALIDATORS" /D "XML_SINGLEDLL" /D "WIN32" /D "_WINDOWS" /D "XML_USE_WIN32_TRANSCODER" /D "XML_USE_WIN32_MSGLOADER" /D "XML_USE_NETACCESSOR_WINSOCK" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c

"$(INTDIR)\WinSockNetAccessor.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF

SOURCE=..\..\..\..\..\src\xercesc\util\regx\ASCIIRangeFactory.cpp

"$(INTDIR)\ASCIIRangeFactory.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\BlockRangeFactory.cpp

"$(INTDIR)\BlockRangeFactory.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\BMPattern.cpp

"$(INTDIR)\BMPattern.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\CharToken.cpp

"$(INTDIR)\CharToken.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\ClosureToken.cpp

"$(INTDIR)\ClosureToken.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\ConcatToken.cpp

"$(INTDIR)\ConcatToken.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\ConditionToken.cpp

"$(INTDIR)\ConditionToken.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\Match.cpp

"$(INTDIR)\Match.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\ModifierToken.cpp

"$(INTDIR)\ModifierToken.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\Op.cpp

"$(INTDIR)\Op.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\OpFactory.cpp

"$(INTDIR)\OpFactory.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\ParenToken.cpp

"$(INTDIR)\ParenToken.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\ParserForXMLSchema.cpp

"$(INTDIR)\ParserForXMLSchema.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\RangeFactory.cpp

"$(INTDIR)\RangeFactory.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\RangeToken.cpp

"$(INTDIR)\RangeToken.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\RangeTokenMap.cpp

"$(INTDIR)\RangeTokenMap.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\RegularExpression.cpp

"$(INTDIR)\RegularExpression.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\RegxParser.cpp

"$(INTDIR)\RegxParser.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\RegxUtil.cpp

"$(INTDIR)\RegxUtil.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\StringToken.cpp

"$(INTDIR)\StringToken.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\Token.cpp

"$(INTDIR)\Token.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\TokenFactory.cpp

"$(INTDIR)\TokenFactory.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\UnicodeRangeFactory.cpp

"$(INTDIR)\UnicodeRangeFactory.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\UnionToken.cpp

"$(INTDIR)\UnionToken.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\XMLRangeFactory.cpp

"$(INTDIR)\XMLRangeFactory.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\regx\XMLUniCharacter.cpp

"$(INTDIR)\XMLUniCharacter.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\Base64.cpp

"$(INTDIR)\Base64.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\BinFileInputStream.cpp

"$(INTDIR)\BinFileInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\BinInputStream.cpp

"$(INTDIR)\BinInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\BinMemInputStream.cpp

"$(INTDIR)\BinMemInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\BitSet.cpp

"$(INTDIR)\BitSet.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\EncodingValidator.cpp

"$(INTDIR)\EncodingValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\HashPtr.cpp

"$(INTDIR)\HashPtr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\HashXMLCh.cpp

"$(INTDIR)\HashXMLCh.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\HeaderDummy.cpp

"$(INTDIR)\HeaderDummy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\HexBin.cpp

"$(INTDIR)\HexBin.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\KVStringPair.cpp

"$(INTDIR)\KVStringPair.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\Mutexes.cpp

"$(INTDIR)\Mutexes.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\PlatformUtils.cpp

"$(INTDIR)\PlatformUtils.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\QName.cpp

"$(INTDIR)\QName.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\StringPool.cpp

"$(INTDIR)\StringPool.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\TransService.cpp

"$(INTDIR)\TransService.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XML256TableTranscoder.cpp

"$(INTDIR)\XML256TableTranscoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XML88591Transcoder.cpp

"$(INTDIR)\XML88591Transcoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLAbstractDoubleFloat.cpp

"$(INTDIR)\XMLAbstractDoubleFloat.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLASCIITranscoder.cpp

"$(INTDIR)\XMLASCIITranscoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLBigDecimal.cpp

"$(INTDIR)\XMLBigDecimal.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLBigInteger.cpp

"$(INTDIR)\XMLBigInteger.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLChTranscoder.cpp

"$(INTDIR)\XMLChTranscoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLDateTime.cpp

"$(INTDIR)\XMLDateTime.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLDouble.cpp

"$(INTDIR)\XMLDouble.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLEBCDICTranscoder.cpp

"$(INTDIR)\XMLEBCDICTranscoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLException.cpp

"$(INTDIR)\XMLException.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLFloat.cpp

"$(INTDIR)\XMLFloat.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLIBM1140Transcoder.cpp

"$(INTDIR)\XMLIBM1140Transcoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLMsgLoader.cpp

"$(INTDIR)\XMLMsgLoader.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)
	
	
SOURCE=..\..\..\..\..\src\xercesc\util\XMLNumber.cpp

"$(INTDIR)\XMLNumber.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLString.cpp

"$(INTDIR)\XMLString.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLStringTokenizer.cpp

"$(INTDIR)\XMLStringTokenizer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLUCSTranscoder.cpp

"$(INTDIR)\XMLUCSTranscoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLUni.cpp

"$(INTDIR)\XMLUni.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLUri.cpp

"$(INTDIR)\XMLUri.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLURL.cpp

"$(INTDIR)\XMLURL.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLUTF16Transcoder.cpp

"$(INTDIR)\XMLUTF16Transcoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLUTF8Transcoder.cpp

"$(INTDIR)\XMLUTF8Transcoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\XMLWin1252Transcoder.cpp

"$(INTDIR)\XMLWin1252Transcoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\LocalFileFormatTarget.cpp

"$(INTDIR)\LocalFileFormatTarget.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\LocalFileInputSource.cpp

"$(INTDIR)\LocalFileInputSource.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\MemBufFormatTarget.cpp

"$(INTDIR)\MemBufFormatTarget.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\MemBufInputSource.cpp

"$(INTDIR)\MemBufInputSource.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\StdInInputSource.cpp

"$(INTDIR)\StdInInputSource.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\StdOutFormatTarget.cpp

"$(INTDIR)\StdOutFormatTarget.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\URLInputSource.cpp

"$(INTDIR)\URLInputSource.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\Wrapper4DOMInputSource.cpp

"$(INTDIR)\Wrapper4DOMInputSource.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\Wrapper4InputSource.cpp

"$(INTDIR)\Wrapper4InputSource.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\XMLAttDef.cpp

"$(INTDIR)\XMLAttDef.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\XMLAttr.cpp

"$(INTDIR)\XMLAttr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\XMLBuffer.cpp

"$(INTDIR)\XMLBuffer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\XMLBufferMgr.cpp

"$(INTDIR)\XMLBufferMgr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\XMLContentModel.cpp

"$(INTDIR)\XMLContentModel.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\XMLElementDecl.cpp

"$(INTDIR)\XMLElementDecl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\XMLEntityDecl.cpp

"$(INTDIR)\XMLEntityDecl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\XMLFormatter.cpp

"$(INTDIR)\XMLFormatter.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\XMLNotationDecl.cpp

"$(INTDIR)\XMLNotationDecl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\XMLRecognizer.cpp

"$(INTDIR)\XMLRecognizer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\framework\XMLValidator.cpp

"$(INTDIR)\XMLValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\internal\ElemStack.cpp

"$(INTDIR)\ElemStack.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\internal\ReaderMgr.cpp

"$(INTDIR)\ReaderMgr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\internal\VecAttributesImpl.cpp

"$(INTDIR)\VecAttributesImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\internal\VecAttrListImpl.cpp

"$(INTDIR)\VecAttrListImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\internal\XMLReader.cpp

"$(INTDIR)\XMLReader.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\internal\XMLScanner.cpp

"$(INTDIR)\XMLScanner.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\internal\XMLScanner2.cpp

"$(INTDIR)\XMLScanner2.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\sax\Dummy.cpp

"$(INTDIR)\Dummy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\sax\InputSource.cpp

"$(INTDIR)\InputSource.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\sax\SAXException.cpp

"$(INTDIR)\SAXException.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\sax\SAXParseException.cpp

"$(INTDIR)\SAXParseException.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\parsers\AbstractDOMParser.cpp

"$(INTDIR)\AbstractDOMParser.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\parsers\DOMBuilderImpl.cpp

"$(INTDIR)\DOMBuilderImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\parsers\SAX2XMLReaderImpl.cpp

"$(INTDIR)\SAX2XMLReaderImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\parsers\SAXParser.cpp

"$(INTDIR)\SAXParser.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\parsers\XercesDOMParser.cpp

"$(INTDIR)\XercesDOMParser.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\common\AllContentModel.cpp

"$(INTDIR)\AllContentModel.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\common\CMAny.cpp

"$(INTDIR)\CMAny.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\common\CMBinaryOp.cpp

"$(INTDIR)\CMBinaryOp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\common\CMUnaryOp.cpp

"$(INTDIR)\CMUnaryOp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\common\ContentLeafNameTypeVector.cpp

"$(INTDIR)\ContentLeafNameTypeVector.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\common\ContentSpecNode.cpp

"$(INTDIR)\ContentSpecNode.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\common\DFAContentModel.cpp

"$(INTDIR)\DFAContentModel.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\common\GrammarResolver.cpp

"$(INTDIR)\GrammarResolver.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\common\MixedContentModel.cpp

"$(INTDIR)\MixedContentModel.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\common\SimpleContentModel.cpp

"$(INTDIR)\SimpleContentModel.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\AbstractNumericFacetValidator.cpp

"$(INTDIR)\AbstractNumericFacetValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\AbstractNumericValidator.cpp

"$(INTDIR)\AbstractNumericValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\AbstractStringValidator.cpp

"$(INTDIR)\AbstractStringValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\AnySimpleTypeDatatypeValidator.cpp

"$(INTDIR)\AnySimpleTypeDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\AnyURIDatatypeValidator.cpp

"$(INTDIR)\AnyURIDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\Base64BinaryDatatypeValidator.cpp

"$(INTDIR)\Base64BinaryDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\BooleanDatatypeValidator.cpp

"$(INTDIR)\BooleanDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\DatatypeValidator.cpp

"$(INTDIR)\DatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\DatatypeValidatorFactory.cpp

"$(INTDIR)\DatatypeValidatorFactory.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\DateDatatypeValidator.cpp

"$(INTDIR)\DateDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\DateTimeDatatypeValidator.cpp

"$(INTDIR)\DateTimeDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\DateTimeValidator.cpp

"$(INTDIR)\DateTimeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\DayDatatypeValidator.cpp

"$(INTDIR)\DayDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\DecimalDatatypeValidator.cpp

"$(INTDIR)\DecimalDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\DoubleDatatypeValidator.cpp

"$(INTDIR)\DoubleDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\DurationDatatypeValidator.cpp

"$(INTDIR)\DurationDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\ENTITYDatatypeValidator.cpp

"$(INTDIR)\ENTITYDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\FloatDatatypeValidator.cpp

"$(INTDIR)\FloatDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\HexBinaryDatatypeValidator.cpp

"$(INTDIR)\HexBinaryDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\IDDatatypeValidator.cpp

"$(INTDIR)\IDDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\IDREFDatatypeValidator.cpp

"$(INTDIR)\IDREFDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\ListDatatypeValidator.cpp

"$(INTDIR)\ListDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\MonthDatatypeValidator.cpp

"$(INTDIR)\MonthDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\MonthDayDatatypeValidator.cpp

"$(INTDIR)\MonthDayDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\NameDatatypeValidator.cpp

"$(INTDIR)\NameDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\NCNameDatatypeValidator.cpp

"$(INTDIR)\NCNameDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\NOTATIONDatatypeValidator.cpp

"$(INTDIR)\NOTATIONDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\QNameDatatypeValidator.cpp

"$(INTDIR)\QNameDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\StringDatatypeValidator.cpp

"$(INTDIR)\StringDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\TimeDatatypeValidator.cpp

"$(INTDIR)\TimeDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\UnionDatatypeValidator.cpp

"$(INTDIR)\UnionDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\YearDatatypeValidator.cpp

"$(INTDIR)\YearDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\datatype\YearMonthDatatypeValidator.cpp

"$(INTDIR)\YearMonthDatatypeValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\DTD\DTDAttDef.cpp

"$(INTDIR)\DTDAttDef.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\DTD\DTDAttDefList.cpp

"$(INTDIR)\DTDAttDefList.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\DTD\DTDElementDecl.cpp

"$(INTDIR)\DTDElementDecl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\DTD\DTDGrammar.cpp

"$(INTDIR)\DTDGrammar.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\DTD\DTDScanner.cpp

"$(INTDIR)\DTDScanner.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\DTD\DTDValidator.cpp

"$(INTDIR)\DTDValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\FieldActivator.cpp

"$(INTDIR)\FieldActivator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\FieldValueMap.cpp

"$(INTDIR)\FieldValueMap.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\IC_Field.cpp

"$(INTDIR)\IC_Field.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\IC_Key.cpp

"$(INTDIR)\IC_Key.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\IC_KeyRef.cpp

"$(INTDIR)\IC_KeyRef.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\IC_Selector.cpp

"$(INTDIR)\IC_Selector.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\IC_Unique.cpp

"$(INTDIR)\IC_Unique.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\IdentityConstraint.cpp

"$(INTDIR)\IdentityConstraint.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\ValueStore.cpp

"$(INTDIR)\ValueStore.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\ValueStoreCache.cpp

"$(INTDIR)\ValueStoreCache.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\XercesXPath.cpp

"$(INTDIR)\XercesXPath.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\XPathMatcher.cpp

"$(INTDIR)\XPathMatcher.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\XPathMatcherStack.cpp

"$(INTDIR)\XPathMatcherStack.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\identity\XPathSymbols.cpp

"$(INTDIR)\XPathSymbols.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\ComplexTypeInfo.cpp

"$(INTDIR)\ComplexTypeInfo.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\GeneralAttributeCheck.cpp

"$(INTDIR)\GeneralAttributeCheck.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\NamespaceScope.cpp

"$(INTDIR)\NamespaceScope.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\SchemaAttDef.cpp

"$(INTDIR)\SchemaAttDef.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\SchemaAttDefList.cpp

"$(INTDIR)\SchemaAttDefList.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\SchemaElementDecl.cpp

"$(INTDIR)\SchemaElementDecl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\SchemaGrammar.cpp

"$(INTDIR)\SchemaGrammar.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\SchemaInfo.cpp

"$(INTDIR)\SchemaInfo.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\SchemaSymbols.cpp

"$(INTDIR)\SchemaSymbols.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\SchemaValidator.cpp

"$(INTDIR)\SchemaValidator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\SubstitutionGroupComparator.cpp

"$(INTDIR)\SubstitutionGroupComparator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\TraverseSchema.cpp

"$(INTDIR)\TraverseSchema.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\XercesAttGroupInfo.cpp

"$(INTDIR)\XercesAttGroupInfo.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\XercesElementWildcard.cpp

"$(INTDIR)\XercesElementWildcard.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\XercesGroupInfo.cpp

"$(INTDIR)\XercesGroupInfo.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\XSDDOMParser.cpp

"$(INTDIR)\XSDDOMParser.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\XSDErrorReporter.cpp

"$(INTDIR)\XSDErrorReporter.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\XSDLocator.cpp

"$(INTDIR)\XSDLocator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\validators\schema\XUtil.cpp

"$(INTDIR)\XUtil.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\sax2\sax2Dummy.cpp

"$(INTDIR)\sax2Dummy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMAttrImpl.cpp

"$(INTDIR)\DOMAttrImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMAttrMapImpl.cpp

"$(INTDIR)\DOMAttrMapImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMAttrNSImpl.cpp

"$(INTDIR)\DOMAttrNSImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMCDATASectionImpl.cpp

"$(INTDIR)\DOMCDATASectionImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMCharacterDataImpl.cpp

"$(INTDIR)\DOMCharacterDataImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMChildNode.cpp

"$(INTDIR)\DOMChildNode.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMCommentImpl.cpp

"$(INTDIR)\DOMCommentImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMDeepNodeListImpl.cpp

"$(INTDIR)\DOMDeepNodeListImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMDocumentFragmentImpl.cpp

"$(INTDIR)\DOMDocumentFragmentImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMDocumentImpl.cpp

"$(INTDIR)\DOMDocumentImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMDocumentTypeImpl.cpp

"$(INTDIR)\DOMDocumentTypeImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMElementImpl.cpp

"$(INTDIR)\DOMElementImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMElementNSImpl.cpp

"$(INTDIR)\DOMElementNSImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMEntityImpl.cpp

"$(INTDIR)\DOMEntityImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMEntityReferenceImpl.cpp

"$(INTDIR)\DOMEntityReferenceImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMErrorImpl.cpp

"$(INTDIR)\DOMErrorImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMImplementationImpl.cpp

"$(INTDIR)\DOMImplementationImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMImplementationRegistry.cpp

"$(INTDIR)\DOMImplementationRegistry.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMLocatorImpl.cpp

"$(INTDIR)\DOMLocatorImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMNamedNodeMapImpl.cpp

"$(INTDIR)\DOMNamedNodeMapImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMNodeIDMap.cpp

"$(INTDIR)\DOMNodeIDMap.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMNodeImpl.cpp

"$(INTDIR)\DOMNodeImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMNodeIteratorImpl.cpp

"$(INTDIR)\DOMNodeIteratorImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMNodeListImpl.cpp

"$(INTDIR)\DOMNodeListImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMNodeVector.cpp

"$(INTDIR)\DOMNodeVector.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMNotationImpl.cpp

"$(INTDIR)\DOMNotationImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMParentNode.cpp

"$(INTDIR)\DOMParentNode.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMProcessingInstructionImpl.cpp

"$(INTDIR)\DOMProcessingInstructionImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMRangeImpl.cpp

"$(INTDIR)\DOMRangeImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMStringPool.cpp

"$(INTDIR)\DOMStringPool.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMTextImpl.cpp

"$(INTDIR)\DOMTextImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMTreeWalkerImpl.cpp

"$(INTDIR)\DOMTreeWalkerImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\DOMWriterImpl.cpp

"$(INTDIR)\DOMWriterImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\impl\XSDElementNSImpl.cpp

"$(INTDIR)\XSDElementNSImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\AttrImpl.cpp

"$(INTDIR)\AttrImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\AttrMapImpl.cpp

"$(INTDIR)\AttrMapImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\AttrNSImpl.cpp

"$(INTDIR)\AttrNSImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\CDATASectionImpl.cpp

"$(INTDIR)\CDATASectionImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\CharacterDataImpl.cpp

"$(INTDIR)\CharacterDataImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\ChildNode.cpp

"$(INTDIR)\ChildNode.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\CommentImpl.cpp

"$(INTDIR)\CommentImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DeepNodeListImpl.cpp

"$(INTDIR)\DeepNodeListImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DocumentFragmentImpl.cpp

"$(INTDIR)\DocumentFragmentImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DocumentImpl.cpp

"$(INTDIR)\DocumentImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DocumentTypeImpl.cpp

"$(INTDIR)\DocumentTypeImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_Attr.cpp

"$(INTDIR)\DOM_Attr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_CDATASection.cpp

"$(INTDIR)\DOM_CDATASection.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_CharacterData.cpp

"$(INTDIR)\DOM_CharacterData.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_Comment.cpp

"$(INTDIR)\DOM_Comment.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_Document.cpp

"$(INTDIR)\DOM_Document.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_DocumentFragment.cpp

"$(INTDIR)\DOM_DocumentFragment.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_DocumentType.cpp

"$(INTDIR)\DOM_DocumentType.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_DOMException.cpp

"$(INTDIR)\DOM_DOMException.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_DOMImplementation.cpp

"$(INTDIR)\DOM_DOMImplementation.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_Element.cpp

"$(INTDIR)\DOM_Element.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_Entity.cpp

"$(INTDIR)\DOM_Entity.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_EntityReference.cpp

"$(INTDIR)\DOM_EntityReference.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_NamedNodeMap.cpp

"$(INTDIR)\DOM_NamedNodeMap.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_Node.cpp

"$(INTDIR)\DOM_Node.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_NodeFilter.cpp

"$(INTDIR)\DOM_NodeFilter.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_NodeIterator.cpp

"$(INTDIR)\DOM_NodeIterator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_NodeList.cpp

"$(INTDIR)\DOM_NodeList.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_Notation.cpp

"$(INTDIR)\DOM_Notation.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_ProcessingInstruction.cpp

"$(INTDIR)\DOM_ProcessingInstruction.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_Range.cpp

"$(INTDIR)\DOM_Range.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_RangeException.cpp

"$(INTDIR)\DOM_RangeException.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_Text.cpp

"$(INTDIR)\DOM_Text.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_TreeWalker.cpp

"$(INTDIR)\DOM_TreeWalker.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOM_XMLDecl.cpp

"$(INTDIR)\DOM_XMLDecl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DomMemDebug.cpp

"$(INTDIR)\DomMemDebug.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOMParser.cpp

"$(INTDIR)\DOMParser.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DOMString.cpp

"$(INTDIR)\DOMString.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\DStringPool.cpp

"$(INTDIR)\DStringPool.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\ElementDefinitionImpl.cpp

"$(INTDIR)\ElementDefinitionImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\ElementImpl.cpp

"$(INTDIR)\ElementImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\ElementNSImpl.cpp

"$(INTDIR)\ElementNSImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\EntityImpl.cpp

"$(INTDIR)\EntityImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\EntityReferenceImpl.cpp

"$(INTDIR)\EntityReferenceImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\NamedNodeMapImpl.cpp

"$(INTDIR)\NamedNodeMapImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\NodeIDMap.cpp

"$(INTDIR)\NodeIDMap.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\NodeImpl.cpp

"$(INTDIR)\NodeImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\NodeIteratorImpl.cpp

"$(INTDIR)\NodeIteratorImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\NodeListImpl.cpp

"$(INTDIR)\NodeListImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\NodeVector.cpp

"$(INTDIR)\NodeVector.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\NotationImpl.cpp

"$(INTDIR)\NotationImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\ParentNode.cpp

"$(INTDIR)\ParentNode.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\ProcessingInstructionImpl.cpp

"$(INTDIR)\ProcessingInstructionImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\RangeImpl.cpp

"$(INTDIR)\RangeImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\RefCountedImpl.cpp

"$(INTDIR)\RefCountedImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\TextImpl.cpp

"$(INTDIR)\TextImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\TreeWalkerImpl.cpp

"$(INTDIR)\TreeWalkerImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\deprecated\XMLDeclImpl.cpp

"$(INTDIR)\XMLDeclImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\DOMException.cpp

"$(INTDIR)\DOMException.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\dom\DOMRangeException.cpp

"$(INTDIR)\DOMRangeException.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\..\..\..\..\src\xercesc\util\Platforms\Win32\Version.rc

!IF  "$(CFG)" == "XercesLib - Win32 Release"


"$(INTDIR)\Version.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\Version.res" /i "\Xerces-Testing\src\xercesc\util\Platforms\Win32" /d "NDEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "XercesLib - Win32 Debug"


"$(INTDIR)\Version.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\Version.res" /i "\Xerces-Testing\src\xercesc\util\Platforms\Win32" /d "_DEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Debug"


"$(INTDIR)\Version.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\Version.res" /i "\Xerces-Testing\src\xercesc\util\Platforms\Win32" /d "_DEBUG" $(SOURCE)


!ELSEIF  "$(CFG)" == "XercesLib - Win64 Release"


"$(INTDIR)\Version.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) /l 0x409 /fo"$(INTDIR)\Version.res" /i "\Xerces-Testing\src\xercesc\util\Platforms\Win32" /d "NDEBUG" $(SOURCE)


!ENDIF


!ENDIF

