// This file is generated, don't edit it!!

#if !defined(ERRHEADER_XMLExcepts)
#define ERRHEADER_XMLExcepts

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/dom/DOMError.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XMLExcepts
{
public :
    enum Codes
    {
        NoError                            = 0
      , W_LowBounds                        = 1
      , Scan_CouldNotOpenSource_Warning    = 2
      , GC_ExistingGrammar                 = 3
      , W_HighBounds                       = 4
      , F_LowBounds                        = 5
      , Array_BadIndex                     = 6
      , Array_BadNewSize                   = 7
      , AttrList_BadIndex                  = 8
      , AttDef_BadAttType                  = 9
      , AttDef_BadDefAttType               = 10
      , Bitset_BadIndex                    = 11
      , Bitset_NotEqualSize                = 12
      , BufMgr_NoMoreBuffers               = 13
      , BufMgr_BufferNotInPool             = 14
      , CPtr_PointerIsZero                 = 15
      , CM_BinOpHadUnaryType               = 16
      , CM_MustBeMixedOrChildren           = 17
      , CM_NoPCDATAHere                    = 18
      , CM_NotValidForSpecType             = 19
      , CM_UnaryOpHadBinType               = 20
      , CM_UnknownCMType                   = 21
      , CM_UnknownCMSpecType               = 22
      , CM_NoParentCSN                     = 23
      , CM_NotValidSpecTypeForNode         = 24
      , DTD_UnknownCreateReason            = 25
      , ElemStack_EmptyStack               = 26
      , ElemStack_BadIndex                 = 27
      , ElemStack_StackUnderflow           = 28
      , ElemStack_NoParentPushed           = 29
      , Enum_NoMoreElements                = 30
      , File_CouldNotOpenFile              = 31
      , File_CouldNotGetCurPos             = 32
      , File_CouldNotCloseFile             = 33
      , File_CouldNotSeekToEnd             = 34
      , File_CouldNotSeekToPos             = 35
      , File_CouldNotDupHandle             = 36
      , File_CouldNotReadFromFile          = 37
      , File_CouldNotWriteToFile           = 38
      , File_CouldNotResetFile             = 39
      , File_CouldNotGetSize               = 40
      , File_CouldNotGetBasePathName       = 41
      , File_BasePathUnderflow             = 42
      , Gen_ParseInProgress                = 43
      , Gen_NoDTDValidator                 = 44
      , Gen_CouldNotOpenDTD                = 45
      , Gen_CouldNotOpenExtEntity          = 46
      , Gen_UnexpectedEOF                  = 47
      , HshTbl_ZeroModulus                 = 48
      , HshTbl_BadHashFromKey              = 49
      , HshTbl_NoSuchKeyExists             = 50
      , Mutex_CouldNotCreate               = 51
      , Mutex_CouldNotClose                = 52
      , Mutex_CouldNotLock                 = 53
      , Mutex_CouldNotUnlock               = 54
      , Mutex_CouldNotDestroy              = 55
      , NetAcc_InternalError               = 56
      , NetAcc_LengthError                 = 57
      , NetAcc_InitFailed                  = 58
      , NetAcc_TargetResolution            = 59
      , NetAcc_CreateSocket                = 60
      , NetAcc_ConnSocket                  = 61
      , NetAcc_WriteSocket                 = 62
      , NetAcc_ReadSocket                  = 63
      , NetAcc_UnsupportedMethod           = 64
      , Pool_ElemAlreadyExists             = 65
      , Pool_BadHashFromKey                = 66
      , Pool_InvalidId                     = 67
      , Pool_ZeroModulus                   = 68
      , RdrMgr_ReaderIdNotFound            = 69
      , Reader_BadAutoEncoding             = 70
      , Reader_CouldNotDecodeFirstLine     = 71
      , Reader_EOIInMultiSeq               = 72
      , Reader_SrcOfsNotSupported          = 73
      , Reader_EncodingStrRequired         = 74
      , Scan_CouldNotOpenSource            = 75
      , Scan_UnbalancedStartEnd            = 76
      , Scan_BadPScanToken                 = 77
      , Stack_BadIndex                     = 78
      , Stack_EmptyStack                   = 79
      , Str_ZeroSizedTargetBuf             = 80
      , Str_UnknownRadix                   = 81
      , Str_TargetBufTooSmall              = 82
      , Str_StartIndexPastEnd              = 83
      , Str_ConvertOverflow                = 84
      , Strm_StdErrWriteFailure            = 85
      , Strm_StdOutWriteFailure            = 86
      , Strm_ConWriteFailure               = 87
      , StrPool_IllegalId                  = 88
      , Trans_CouldNotCreateDefCvtr        = 89
      , Trans_InvalidSizeReq               = 90
      , Trans_Unrepresentable              = 91
      , Trans_NotValidForEncoding          = 92
      , Trans_BadBlockSize                 = 93
      , Trans_BadSrcSeq                    = 94
      , Trans_BadSrcCP                     = 95
      , Trans_BadTrailingSurrogate         = 96
      , Trans_CantCreateCvtrFor            = 97
      , URL_MalformedURL                   = 98
      , URL_UnsupportedProto               = 99
      , URL_UnsupportedProto1              = 100
      , URL_OnlyLocalHost                  = 101
      , URL_NoProtocolPresent              = 102
      , URL_ExpectingTwoSlashes            = 103
      , URL_IncorrectEscapedCharRef        = 104
      , URL_UnterminatedHostComponent      = 105
      , URL_RelativeBaseURL                = 106
      , URL_BaseUnderflow                  = 107
      , URL_BadPortField                   = 108
      , UTF8_FormatError                   = 109
      , Vector_BadIndex                    = 110
      , Val_InvalidElemId                  = 111
      , Val_CantHaveIntSS                  = 112
      , XMLRec_UnknownEncoding             = 113
      , Parser_Parse1                      = 114
      , Parser_Parse2                      = 115
      , Parser_Next1                       = 116
      , Parser_Next2                       = 117
      , Parser_Next3                       = 118
      , Parser_Next4                       = 119
      , Parser_Factor1                     = 120
      , Parser_Factor2                     = 121
      , Parser_Factor3                     = 122
      , Parser_Factor4                     = 123
      , Parser_Factor5                     = 124
      , Parser_Factor6                     = 125
      , Parser_Atom1                       = 126
      , Parser_Atom2                       = 127
      , Parser_Atom3                       = 128
      , Parser_Atom4                       = 129
      , Parser_Atom5                       = 130
      , Parser_CC1                         = 131
      , Parser_CC2                         = 132
      , Parser_CC3                         = 133
      , Parser_CC4                         = 134
      , Parser_CC5                         = 135
      , Parser_CC6                         = 136
      , Parser_Ope1                        = 137
      , Parser_Ope2                        = 138
      , Parser_Ope3                        = 139
      , Parser_Descape1                    = 140
      , Parser_Descape2                    = 141
      , Parser_Descape3                    = 142
      , Parser_Descape4                    = 143
      , Parser_Descape5                    = 144
      , Parser_Process1                    = 145
      , Parser_Process2                    = 146
      , Parser_Quantifier1                 = 147
      , Parser_Quantifier2                 = 148
      , Parser_Quantifier3                 = 149
      , Parser_Quantifier4                 = 150
      , Parser_Quantifier5                 = 151
      , Gen_NoSchemaValidator              = 152
      , XUTIL_UnCopyableNodeType           = 153
      , SubGrpComparator_NGR               = 154
      , FACET_Invalid_Len                  = 155
      , FACET_Invalid_maxLen               = 156
      , FACET_Invalid_minLen               = 157
      , FACET_NonNeg_Len                   = 158
      , FACET_NonNeg_maxLen                = 159
      , FACET_NonNeg_minLen                = 160
      , FACET_Len_maxLen                   = 161
      , FACET_Len_minLen                   = 162
      , FACET_maxLen_minLen                = 163
      , FACET_bool_Pattern                 = 164
      , FACET_Invalid_Tag                  = 165
      , FACET_Len_baseLen                  = 166
      , FACET_minLen_baseminLen            = 167
      , FACET_minLen_basemaxLen            = 168
      , FACET_maxLen_basemaxLen            = 169
      , FACET_maxLen_baseminLen            = 170
      , FACET_Len_baseMinLen               = 171
      , FACET_Len_baseMaxLen               = 172
      , FACET_minLen_baseLen               = 173
      , FACET_maxLen_baseLen               = 174
      , FACET_enum_base                    = 175
      , FACET_Invalid_WS                   = 176
      , FACET_WS_collapse                  = 177
      , FACET_WS_replace                   = 178
      , FACET_Invalid_MaxIncl              = 179
      , FACET_Invalid_MaxExcl              = 180
      , FACET_Invalid_MinIncl              = 181
      , FACET_Invalid_MinExcl              = 182
      , FACET_Invalid_TotalDigit           = 183
      , FACET_Invalid_FractDigit           = 184
      , FACET_PosInt_TotalDigit            = 185
      , FACET_NonNeg_FractDigit            = 186
      , FACET_max_Incl_Excl                = 187
      , FACET_min_Incl_Excl                = 188
      , FACET_maxExcl_minExcl              = 189
      , FACET_maxExcl_minIncl              = 190
      , FACET_maxIncl_minExcl              = 191
      , FACET_maxIncl_minIncl              = 192
      , FACET_TotDigit_FractDigit          = 193
      , FACET_maxIncl_base_maxExcl         = 194
      , FACET_maxIncl_base_maxIncl         = 195
      , FACET_maxIncl_base_minIncl         = 196
      , FACET_maxIncl_base_minExcl         = 197
      , FACET_maxExcl_base_maxExcl         = 198
      , FACET_maxExcl_base_maxIncl         = 199
      , FACET_maxExcl_base_minIncl         = 200
      , FACET_maxExcl_base_minExcl         = 201
      , FACET_minExcl_base_maxExcl         = 202
      , FACET_minExcl_base_maxIncl         = 203
      , FACET_minExcl_base_minIncl         = 204
      , FACET_minExcl_base_minExcl         = 205
      , FACET_minIncl_base_maxExcl         = 206
      , FACET_minIncl_base_maxIncl         = 207
      , FACET_minIncl_base_minIncl         = 208
      , FACET_minIncl_base_minExcl         = 209
      , FACET_maxIncl_notFromBase          = 210
      , FACET_maxExcl_notFromBase          = 211
      , FACET_minIncl_notFromBase          = 212
      , FACET_minExcl_notFromBase          = 213
      , FACET_totalDigit_base_totalDigit   = 214
      , FACET_fractDigit_base_totalDigit   = 215
      , FACET_fractDigit_base_fractDigit   = 216
      , FACET_maxIncl_base_fixed           = 217
      , FACET_maxExcl_base_fixed           = 218
      , FACET_minIncl_base_fixed           = 219
      , FACET_minExcl_base_fixed           = 220
      , FACET_totalDigit_base_fixed        = 221
      , FACET_fractDigit_base_fixed        = 222
      , FACET_maxLen_base_fixed            = 223
      , FACET_minLen_base_fixed            = 224
      , FACET_len_base_fixed               = 225
      , FACET_whitespace_base_fixed        = 226
      , FACET_internalError_fixed          = 227
      , FACET_List_Null_baseValidator      = 228
      , FACET_Union_Null_memberTypeValidators   = 229
      , FACET_Union_Null_baseValidator     = 230
      , FACET_Union_invalid_baseValidatorType   = 231
      , VALUE_NotMatch_Pattern             = 232
      , VALUE_Not_Base64                   = 233
      , VALUE_Not_HexBin                   = 234
      , VALUE_GT_maxLen                    = 235
      , VALUE_LT_minLen                    = 236
      , VALUE_NE_Len                       = 237
      , VALUE_NotIn_Enumeration            = 238
      , VALUE_exceed_totalDigit            = 239
      , VALUE_exceed_fractDigit            = 240
      , VALUE_exceed_maxIncl               = 241
      , VALUE_exceed_maxExcl               = 242
      , VALUE_exceed_minIncl               = 243
      , VALUE_exceed_minExcl               = 244
      , VALUE_WS_replaced                  = 245
      , VALUE_WS_collapsed                 = 246
      , VALUE_Invalid_NCName               = 247
      , VALUE_Invalid_Name                 = 248
      , VALUE_ID_Not_Unique                = 249
      , VALUE_ENTITY_Invalid               = 250
      , VALUE_QName_Invalid                = 251
      , VALUE_NOTATION_Invalid             = 252
      , VALUE_no_match_memberType          = 253
      , VALUE_URI_Malformed                = 254
      , XMLNUM_emptyString                 = 255
      , XMLNUM_WSString                    = 256
      , XMLNUM_2ManyDecPoint               = 257
      , XMLNUM_Inv_chars                   = 258
      , XMLNUM_null_ptr                    = 259
      , XMLNUM_URI_Component_Empty         = 260
      , XMLNUM_URI_Component_for_GenURI_Only   = 261
      , XMLNUM_URI_Component_Invalid_EscapeSequence   = 262
      , XMLNUM_URI_Component_Invalid_Char   = 263
      , XMLNUM_URI_Component_Set_Null      = 264
      , XMLNUM_URI_Component_Not_Conformant   = 265
      , XMLNUM_URI_No_Scheme               = 266
      , XMLNUM_URI_NullHost                = 267
      , XMLNUM_URI_NullPath                = 268
      , XMLNUM_URI_Component_inPath        = 269
      , XMLNUM_URI_PortNo_Invalid          = 270
      , XMLNUM_DBL_FLT_maxNeg              = 271
      , XMLNUM_DBL_FLT_maxPos              = 272
      , XMLNUM_DBL_FLT_minNegPos           = 273
      , XMLNUM_DBL_FLT_InvalidType         = 274
      , XMLNUM_DBL_FLT_No_Exponent         = 275
      , Regex_Result_Not_Set               = 276
      , Regex_CompactRangesError           = 277
      , Regex_MergeRangesTypeMismatch      = 278
      , Regex_SubtractRangesError          = 279
      , Regex_IntersectRangesError         = 280
      , Regex_ComplementRangesInvalidArg   = 281
      , Regex_InvalidCategoryName          = 282
      , Regex_KeywordNotFound              = 283
      , Regex_BadRefNo                     = 284
      , Regex_UnknownOption                = 285
      , Regex_UnknownTokenType             = 286
      , Regex_RangeTokenGetError           = 287
      , Regex_NotSupported                 = 288
      , Regex_InvalidChildIndex            = 289
      , Regex_RepPatMatchesZeroString      = 290
      , Regex_InvalidRepPattern            = 291
      , NEL_RepeatedCalls                  = 292
      , RethrowError                       = 293
      , Out_Of_Memory                      = 294
      , DV_InvalidOperation                = 295
      , XPath_NoAttrSelector               = 296
      , XPath_NoUnionAtStart               = 297
      , XPath_NoMultipleUnion              = 298
      , XPath_MissingAttr                  = 299
      , XPath_ExpectedToken1               = 300
      , XPath_PrefixNoURI                  = 301
      , XPath_NoDoubleColon                = 302
      , XPath_ExpectedStep1                = 303
      , XPath_ExpectedStep2                = 304
      , XPath_ExpectedStep3                = 305
      , XPath_NoForwardSlash               = 306
      , XPath_NoDoubleForwardSlash         = 307
      , XPath_NoForwardSlashAtStart        = 308
      , XPath_NoSelectionOfRoot            = 309
      , XPath_EmptyExpr                    = 310
      , XPath_NoUnionAtEnd                 = 311
      , XPath_InvalidChar                  = 312
      , XPath_TokenNotSupported            = 313
      , XPath_FindSolution                 = 314
      , DateTime_Assert_Buffer_Fail        = 315
      , DateTime_dt_missingT               = 316
      , DateTime_gDay_invalid              = 317
      , DateTime_gMth_invalid              = 318
      , DateTime_gMthDay_invalid           = 319
      , DateTime_dur_Start_dashP           = 320
      , DateTime_dur_noP                   = 321
      , DateTime_dur_DashNotFirst          = 322
      , DateTime_dur_inv_b4T               = 323
      , DateTime_dur_NoTimeAfterT          = 324
      , DateTime_dur_NoElementAtAll        = 325
      , DateTime_dur_inv_seconds           = 326
      , DateTime_date_incomplete           = 327
      , DateTime_date_invalid              = 328
      , DateTime_time_incomplete           = 329
      , DateTime_time_invalid              = 330
      , DateTime_ms_noDigit                = 331
      , DateTime_ym_incomplete             = 332
      , DateTime_ym_invalid                = 333
      , DateTime_year_tooShort             = 334
      , DateTime_year_leadingZero          = 335
      , DateTime_ym_noMonth                = 336
      , DateTime_tz_noUTCsign              = 337
      , DateTime_tz_stuffAfterZ            = 338
      , DateTime_tz_invalid                = 339
      , DateTime_year_zero                 = 340
      , DateTime_mth_invalid               = 341
      , DateTime_day_invalid               = 342
      , DateTime_hour_invalid              = 343
      , DateTime_min_invalid               = 344
      , DateTime_second_invalid            = 345
      , DateTime_tz_hh_invalid             = 346
      , PD_EmptyBase                       = 347
      , PD_NSCompat1                       = 348
      , PD_OccurRangeE                     = 349
      , PD_NameTypeOK1                     = 350
      , PD_NameTypeOK2                     = 351
      , PD_NameTypeOK3                     = 352
      , PD_NameTypeOK4                     = 353
      , PD_NameTypeOK5                     = 354
      , PD_NameTypeOK6                     = 355
      , PD_NameTypeOK7                     = 356
      , PD_RecurseAsIfGroup                = 357
      , PD_Recurse1                        = 358
      , PD_Recurse2                        = 359
      , PD_ForbiddenRes1                   = 360
      , PD_ForbiddenRes2                   = 361
      , PD_ForbiddenRes3                   = 362
      , PD_ForbiddenRes4                   = 363
      , PD_NSSubset1                       = 364
      , PD_NSSubset2                       = 365
      , PD_NSRecurseCheckCardinality1      = 366
      , PD_RecurseUnordered                = 367
      , PD_MapAndSum                       = 368
      , PD_InvalidContentType              = 369
      , NodeIDMap_GrowErr                  = 370
      , XSer_ProtoType_Null_ClassName      = 371
      , XSer_ProtoType_NameLen_Dif         = 372
      , XSer_ProtoType_Name_Dif            = 373
      , XSer_InStream_Read_LT_Req          = 374
      , XSer_InStream_Read_OverFlow        = 375
      , XSer_Storing_Violation             = 376
      , XSer_StoreBuffer_Violation         = 377
      , XSer_LoadPool_UppBnd_Exceed        = 378
      , XSer_LoadPool_NoTally_ObjCnt       = 379
      , XSer_Loading_Violation             = 380
      , XSer_LoadBuffer_Violation          = 381
      , XSer_Inv_ClassIndex                = 382
      , XSer_Inv_FillBuffer_Size           = 383
      , XSer_Inv_checkFillBuffer_Size      = 384
      , XSer_Inv_checkFlushBuffer_Size     = 385
      , XSer_Inv_Null_Pointer              = 386
      , XSer_Inv_Buffer_Len                = 387
      , XSer_CreateObject_Fail             = 388
      , XSer_ObjCount_UppBnd_Exceed        = 389
      , XSer_GrammarPool_Locked            = 390
      , XSer_GrammarPool_Empty             = 391
      , XSer_GrammarPool_NotEmpty          = 392
      , XSer_StringPool_NotEmpty           = 393
      , XSer_BinaryData_Version_NotSupported   = 394
      , F_HighBounds                       = 395
      , E_LowBounds                        = 396
      , E_HighBounds                       = 397
    };


private:
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XMLExcepts();
};

XERCES_CPP_NAMESPACE_END

#endif

