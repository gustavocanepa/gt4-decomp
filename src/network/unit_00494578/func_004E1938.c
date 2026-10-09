/* expat 1.95.7: big2_checkPiTarget from xmltok.c, placed at 0x004e1938 by
 * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin. */
#define XMLCALL 
#define BYTEORDER 1234
#define HAVE_MEMMOVE
#define XML_NS
#define XML_DTD
#define XML_CONTEXT_BYTES 1024
#define KW_ANY D_006BAC50
#define KW_ATTLIST D_006BAC58
#define KW_CDATA D_006BAC60
#define KW_DOCTYPE D_006BAC68
#define KW_ELEMENT D_006BAC70
#define KW_EMPTY D_006BAC78
#define KW_ENTITIES D_006BAC80
#define KW_ENTITY D_006BAC90
#define KW_FIXED D_006BAC98
#define KW_ID D_006BACA0
#define KW_IDREF D_006BACA8
#define KW_IDREFS D_006BACB0
#define KW_IGNORE D_006BACB8
#define KW_IMPLIED D_006BACC0
#define KW_INCLUDE D_006BACC8
#define KW_ISO_8859_1 D_006BFEC0
#define KW_NDATA D_006BACD0
#define KW_NMTOKEN D_006BACD8
#define KW_NMTOKENS D_006BACE0
#define KW_NOTATION D_006BACF0
#define KW_PCDATA D_006BAD00
#define KW_PUBLIC D_006BAD08
#define KW_REQUIRED D_006BAD10
#define KW_SYSTEM D_006BAD20
#define KW_US_ASCII D_006BFED0
#define KW_UTF_16 D_006BFEE8
#define KW_UTF_16BE D_006BFEF0
#define KW_UTF_16LE D_006BFF00
#define KW_UTF_8 D_006BFEE0
#define KW_encoding D_006BFE90
#define KW_no D_006BFEB8
#define KW_standalone D_006BFEA0
#define KW_version D_006BFE88
#define KW_yes D_006BFEB0
#define XML_DefaultCurrent func_004CFAB0
#define XML_ErrorString func_004CFB08
#define XML_ExpatVersion func_004CFB38
#define XML_ExpatVersionInfo func_004CFB48
#define XML_ExternalEntityParserCreate func_004CEE28
#define XML_FreeContentModel func_004CFA28
#define XML_GetBase func_004CF3D8
#define XML_GetBuffer func_004CF740
#define XML_GetCurrentByteCount func_004CF908
#define XML_GetCurrentByteIndex func_004CF8E0
#define XML_GetCurrentColumnNumber func_004CF9D0
#define XML_GetCurrentLineNumber func_004CF970
#define XML_GetErrorCode func_004CF8D8
#define XML_GetFeatureList func_004CFB88
#define XML_GetIdAttributeIndex func_004CF3E8
#define XML_GetInputContext func_004CF930
#define XML_GetSpecifiedAttributeCount func_004CF3E0
#define XML_MemFree func_004CFA90
#define XML_MemMalloc func_004CFA48
#define XML_MemRealloc func_004CFA68
#define XML_Parse func_004CF580
#define XML_ParseBuffer func_004CF678
#define XML_ParserCreate func_004CE828
#define XML_ParserCreateNS func_004CE848
#define XML_ParserCreate_MM func_004CE870
#define XML_ParserFree func_004CF150
#define XML_ParserReset func_004CECA0
#define XML_SetAttlistDeclHandler func_004CF4F8
#define XML_SetBase func_004CF388
#define XML_SetCdataSectionHandler func_004CF428
#define XML_SetCharacterDataHandler func_004CF410
#define XML_SetCommentHandler func_004CF420
#define XML_SetDefaultHandler func_004CF448
#define XML_SetDefaultHandlerExpand func_004CF458
#define XML_SetDoctypeDeclHandler func_004CF468
#define XML_SetElementDeclHandler func_004CF4F0
#define XML_SetElementHandler func_004CF3F0
#define XML_SetEncoding func_004CED80
#define XML_SetEndCdataSectionHandler func_004CF440
#define XML_SetEndDoctypeDeclHandler func_004CF480
#define XML_SetEndElementHandler func_004CF408
#define XML_SetEndNamespaceDeclHandler func_004CF4B0
#define XML_SetEntityDeclHandler func_004CF500
#define XML_SetExternalEntityRefHandler func_004CF4C0
#define XML_SetExternalEntityRefHandlerArg func_004CF4C8
#define XML_SetNamespaceDeclHandler func_004CF498
#define XML_SetNotStandaloneHandler func_004CF4B8
#define XML_SetNotationDeclHandler func_004CF490
#define XML_SetParamEntityParsing func_004CF510
#define XML_SetProcessingInstructionHandler func_004CF418
#define XML_SetReturnNSTriplet func_004CF318
#define XML_SetSkippedEntityHandler func_004CF4D8
#define XML_SetStartCdataSectionHandler func_004CF438
#define XML_SetStartDoctypeDeclHandler func_004CF478
#define XML_SetStartElementHandler func_004CF400
#define XML_SetStartNamespaceDeclHandler func_004CF4A8
#define XML_SetUnknownEncodingHandler func_004CF4E0
#define XML_SetUnparsedEntityDeclHandler func_004CF488
#define XML_SetUserData func_004CF370
#define XML_SetXmlDeclHandler func_004CF508
#define XML_UseForeignDTD func_004CF2A0
#define XML_UseParserAsHandlerArg func_004CF298
#define XmlGetUtf16InternalEncoding func_004E6778
#define XmlGetUtf16InternalEncodingNS func_004E6998
#define XmlGetUtf8InternalEncoding func_004E6768
#define XmlGetUtf8InternalEncodingNS func_004E6988
#define XmlInitEncoding func_004E67F8
#define XmlInitEncodingNS func_004E6A18
#define XmlInitUnknownEncoding func_004E6138
#define XmlInitUnknownEncodingNS func_004E6BA8
#define XmlParseXmlDecl func_004E6920
#define XmlParseXmlDeclNS func_004E6B40
#define XmlPrologStateInit func_004D91D8
#define XmlPrologStateInitExternalEntity func_004D91F8
#define XmlSizeOfUnknownEncoding func_004E5DE0
#define XmlUtf16Encode func_004E5D78
#define XmlUtf8Encode func_004E5C88
#define addBinding func_004D1788
#define appendAttributeValue func_004D40C8
#define ascii_encoding D_006BD1F8
#define ascii_encoding_ns D_006BD088
#define ascii_toUtf8 func_004DD0B8
#define attlist0 func_004D8250
#define attlist1 func_004D82C8
#define attlist2 func_004D8368
#define attlist3 func_004D84C8
#define attlist4 func_004D8548
#define attlist5 func_004D85D8
#define attlist6 func_004D8630
#define attlist7 func_004D8688
#define attlist8 func_004D8718
#define attlist9 func_004D8880
#define big2_attributeValueTok func_004E4398
#define big2_cdataSectionTok func_004E1E08
#define big2_charRefNumber func_004E4D40
#define big2_checkPiTarget func_004E1938
#define big2_contentTok func_004E3258
#define big2_encoding D_006BFD18
#define big2_encoding_ns D_006BFBA8
#define big2_getAtts func_004E4A28
#define big2_ignoreSectionTok func_004E4708
#define big2_isPublicId func_004E48E8
#define big2_nameLength func_004E52D8
#define big2_nameMatchesAscii func_004E5278
#define big2_predefinedEntityName func_004E4EF8
#define big2_prologTok func_004E3BD0
#define big2_sameName func_004E50F8
#define big2_scanAtts func_004E2840
#define big2_scanCdataSection func_004E1DA0
#define big2_scanCharRef func_004E2488
#define big2_scanComment func_004E15D0
#define big2_scanDecl func_004E1748
#define big2_scanEndTag func_004E20A0
#define big2_scanHexCharRef func_004E2390
#define big2_scanLit func_004E3A58
#define big2_scanLt func_004E2D50
#define big2_scanPercent func_004E35A8
#define big2_scanPi func_004E1A10
#define big2_scanPoundName func_004E3808
#define big2_scanRef func_004E25C0
#define big2_skipS func_004E5380
#define big2_toUtf16 func_004DD5B8
#define big2_toUtf8 func_004DD3E0
#define big2_updatePosition func_004E5410
#define build_model func_004D6F18
#define build_node func_004D6D78
#define cdataSectionProcessor func_004D1978
#define checkCharRefNumber func_004E5C00
#define common func_004D91A8
#define condSect0 func_004D8F90
#define condSect1 func_004D9080
#define condSect2 func_004D90E0
#define contentProcessor func_004CFCB8
#define copyEntityTable func_004D5EB0
#define declClose func_004D9138
#define defineAttribute func_004D4C28
#define destroyBindings func_004CF0E8
#define doCdataSection func_004D1A20
#define doContent func_004D0000
#define doIgnoreSection func_004D1D08
#define doParseXmlDecl func_004E58D0
#define doProlog func_004D2780
#define doctype0 func_004D72E8
#define doctype1 func_004D7360
#define doctype2 func_004D74C0
#define doctype3 func_004D7518
#define doctype4 func_004D7570
#define doctype5 func_004D7600
#define dtdCopy func_004D5B00
#define dtdCreate func_004D5848
#define dtdDestroy func_004D5A18
#define dtdReset func_004D5918
#define element0 func_004D88D8
#define element1 func_004D8950
#define element2 func_004D8AA8
#define element3 func_004D8BC8
#define element4 func_004D8C88
#define element5 func_004D8D00
#define element6 func_004D8D98
#define element7 func_004D8E50
#define encodings D_006453D8
#define encodingsNS D_006453F8
#define entity0 func_004D7918
#define entity1 func_004D79A8
#define entity10 func_004D7F40
#define entity2 func_004D7A00
#define entity3 func_004D7B48
#define entity4 func_004D7BA0
#define entity5 func_004D7BF8
#define entity6 func_004D7CE8
#define entity7 func_004D7D48
#define entity8 func_004D7E90
#define entity9 func_004D7EE8
#define entityValueInitProcessor func_004D23C0
#define entityValueProcessor func_004D2620
#define epilogProcessor func_004D3DD8
#define error func_004D91A0
#define errorProcessor func_004D4020
#define externalEntityContentProcessor func_004CFFB0
#define externalEntityInitProcessor func_004CFD08
#define externalEntityInitProcessor2 func_004CFD90
#define externalEntityInitProcessor3 func_004CFE98
#define externalParEntInitProcessor func_004D22F0
#define externalParEntProcessor func_004D2520
#define externalSubset0 func_004D7830
#define externalSubset1 func_004D7870
#define findEncoding func_004E6870
#define findEncodingNS func_004E6A90
#define free D_00575DA0
#define getAttributeId func_004D4EE8
#define getContext func_004D5180
#define getElementType func_004D6FB0
#define getEncodingIndex func_004E6458
#define handleUnknownEncoding func_004D2148
#define hash func_004D6080
#define hashTableClear func_004D64E0
#define hashTableDestroy func_004D6560
#define hashTableInit func_004D65D8
#define hashTableIterInit func_004D65F0
#define hashTableIterNext func_004D6610
#define ignoreSectionProcessor func_004D1C90
#define implicitContext D_006BA330
#define initScan func_004E64D0
#define initScanContent func_004E67C0
#define initScanContentNS func_004E69E0
#define initScanProlog func_004E6788
#define initScanPrologNS func_004E69A8
#define initUpdatePosition func_004E55B8
#define initializeEncoding func_004D1E50
#define internalSubset func_004D7658
#define internal_little2_encoding D_006BE948
#define internal_little2_encoding_ns D_006BE7D8
#define internal_utf8_encoding D_006BCC38
#define internal_utf8_encoding_ns D_006BCAC8
#define isNever func_004D9210
#define isSpace func_004E5620
#define keyeq func_004D6048
#define latin1_encoding D_006BCF18
#define latin1_encoding_ns D_006BCDA8
#define latin1_toUtf16 func_004DD060
#define latin1_toUtf8 func_004DCFA8
#define little2_attributeValueTok func_004E0410
#define little2_cdataSectionTok func_004DDE80
#define little2_charRefNumber func_004E0DB8
#define little2_checkPiTarget func_004DD9B0
#define little2_contentTok func_004DF2D8
#define little2_encoding D_006BE668
#define little2_encoding_ns D_006BE4F8
#define little2_entityValueTok func_004E05C8
#define little2_getAtts func_004E0AA0
#define little2_ignoreSectionTok func_004E0780
#define little2_isPublicId func_004E0960
#define little2_nameLength func_004E1350
#define little2_nameMatchesAscii func_004E12F0
#define little2_predefinedEntityName func_004E0F70
#define little2_prologTok func_004DFC48
#define little2_sameName func_004E1170
#define little2_scanAtts func_004DE8B8
#define little2_scanCdataSection func_004DDE18
#define little2_scanCharRef func_004DE500
#define little2_scanComment func_004DD648
#define little2_scanDecl func_004DD7C0
#define little2_scanEndTag func_004DE118
#define little2_scanHexCharRef func_004DE408
#define little2_scanLit func_004DFAD0
#define little2_scanLt func_004DEDC8
#define little2_scanPercent func_004DF620
#define little2_scanPi func_004DDA88
#define little2_scanPoundName func_004DF880
#define little2_scanRef func_004DE638
#define little2_skipS func_004E13F8
#define little2_toUtf16 func_004DD350
#define little2_toUtf8 func_004DD178
#define little2_updatePosition func_004E1488
#define lookup func_004D60D8
#define malloc D_00575DC8
#define memcmp D_0057F188
#define memcpy D_005A4724
#define memmove D_005A47D4
#define func_005A48D8 D_005A48D8
#define moveToFreeBindingList func_004CEC70
#define namePages D_006BB600
#define namingBitmap D_006BB000
#define nextScaffoldPart func_004D6C18
#define nmstrtPages D_006BB500
#define normal_attributeValueTok func_004DC058
#define normal_cdataSectionTok func_004D9CF0
#define normal_charRefNumber func_004DC800
#define normal_checkPiTarget func_004D9868
#define normal_contentTok func_004DB050
#define normal_entityValueTok func_004DC190
#define normal_getAtts func_004DC560
#define normal_ignoreSectionTok func_004DC2C0
#define normal_isPublicId func_004DC4A0
#define normal_nameLength func_004DCC00
#define normal_nameMatchesAscii func_004DCBB0
#define normal_predefinedEntityName func_004DC948
#define normal_prologTok func_004DB988
#define normal_sameName func_004DCAA0
#define normal_scanAtts func_004DA5E8
#define normal_scanCdataSection func_004D9C90
#define normal_scanCharRef func_004DA2C0
#define normal_scanComment func_004D9580
#define normal_scanDecl func_004D9718
#define normal_scanEndTag func_004D9F90
#define normal_scanHexCharRef func_004DA220
#define normal_scanLit func_004DB7F0
#define normal_scanLt func_004DAB68
#define normal_scanPercent func_004DB388
#define normal_scanPi func_004D9910
#define normal_scanPoundName func_004DB5C8
#define normal_scanRef func_004DA388
#define normal_skipS func_004DCC68
#define normal_updatePosition func_004DCCB0
#define normalizeLines func_004D48B0
#define normalizePublicId func_004D57A8
#define notation0 func_004D7FB0
#define notation1 func_004D8008
#define notation2 func_004D80F8
#define notation3 func_004D8150
#define notation4 func_004D81B0
#define parsePseudoAttribute func_004E5670
#define parserCreate func_004CE8D8
#define parserInit func_004CEB08
#define poolAppend func_004D6758
#define poolAppendString func_004D6930
#define poolClear func_004D6678
#define poolCopyString func_004D67F8
#define poolCopyStringN func_004D6880
#define poolDestroy func_004D66D8
#define poolGrow func_004D6A20
#define poolInit func_004D6658
#define poolStoreString func_004D69C0
#define processInternalParamEntity func_004D3F70
#define processXmlDecl func_004D1EC8
#define prolog0 func_004D7050
#define prolog1 func_004D7170
#define prolog2 func_004D7258
#define prologInitProcessor func_004D2268
#define prologProcessor func_004D2708
#define realloc D_00575E30
#define reportComment func_004D4A80
#define reportDefault func_004D4B38
#define reportProcessingInstruction func_004D4958
#define setContext func_004D54F8
#define setElementTypePrefix func_004D4DA8
#define storeAttributeValue func_004D4028
#define storeAtts func_004D0BA0
#define storeEntityValue func_004D4528
#define storeRawNames func_004CFBA8
#define streqci func_004E5558
#define toAscii func_004E55D8
#define unicode_byte_type func_004DD110
#define unknown_isInvalid func_004E5ED8
#define unknown_isName func_004E5DE8
#define unknown_isNmstrt func_004E5E60
#define unknown_toUtf16 func_004E6048
#define unknown_toUtf8 func_004E5F30
#define utf8_encoding D_006BC958
#define utf8_encoding_ns D_006BC7E8
#define utf8_isInvalid2 func_004D93B8
#define utf8_isInvalid3 func_004D93F8
#define utf8_isInvalid4 func_004D94C8
#define utf8_isName2 func_004D9218
#define utf8_isName3 func_004D9278
#define utf8_isNmstrt2 func_004D92E8
#define utf8_isNmstrt3 func_004D9348
#define utf8_toUtf16 func_004DCE30
#define utf8_toUtf8 func_004DCD90
/* Copyright (c) 1998, 1999 Thai Open Source Software Center Ltd
   See the file COPYING for copying permission.
*/

#ifdef COMPILED_FROM_DSP
/*================================================================
** Copyright 2000, Clark Cooper
** All rights reserved.
**
** This is free software. You are permitted to copy, distribute, or modify
** it under the terms of the MIT/X license (contained in the COPYING file
** with this distribution.)
*/

#ifndef WINCONFIG_H
#define WINCONFIG_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

#include <memory.h>

#ifndef _STRING_H
#define _STRING_H

#ifndef _STDDEF_H
#define _STDDEF_H
#ifndef SHIM_SIZE_T
#define SHIM_SIZE_T unsigned int
#endif
typedef SHIM_SIZE_T size_t;
#ifndef SHIM_PTRDIFF_T
#define SHIM_PTRDIFF_T int
#endif
typedef SHIM_PTRDIFF_T ptrdiff_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *func_005A48D8(void *, int, size_t);
int memcmp(const void *, const void *, size_t);
size_t strlen(const char *);
char *strcpy(char *, const char *);
char *strncpy(char *, const char *, size_t);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, size_t);
char *strchr(const char *, int);
char *strrchr(const char *, int);
char *strcat(char *, const char *);
#endif

#define XML_NS 1
#define XML_DTD 1
#define XML_CONTEXT_BYTES 1024

#define BYTEORDER 1234

#define HAVE_MEMMOVE

#endif 

#elif defined(MACOS_CLASSIC)
/*================================================================
** Copyright 2000, Clark Cooper
** All rights reserved.
**
** This is free software. You are permitted to copy, distribute, or modify
** it under the terms of the MIT/X license (contained in the COPYING file
** with this distribution.)
**
*/

#ifndef MACCONFIG_H
#define MACCONFIG_H

#define BYTEORDER  4321

#undef HAVE_BCOPY

#undef HAVE_DLFCN_H

#undef HAVE_FCNTL_H

#undef HAVE_GETPAGESIZE

#undef HAVE_INTTYPES_H

#define HAVE_MEMMOVE

#undef HAVE_MEMORY_H

#undef HAVE_MMAP

#undef HAVE_STDINT_H

#define HAVE_STDLIB_H

#undef HAVE_STRINGS_H

#define HAVE_STRING_H

#undef HAVE_SYS_STAT_H

#undef HAVE_SYS_TYPES_H

#undef HAVE_UNISTD_H

#undef PACKAGE_BUGREPORT

#undef PACKAGE_NAME

#undef PACKAGE_STRING

#undef PACKAGE_TARNAME

#undef PACKAGE_VERSION

#define STDC_HEADERS

#define WORDS_BIGENDIAN

#undef XML_CONTEXT_BYTES

#define XML_DTD

#define XML_NS

#undef const

#define off_t  long

#undef size_t

#endif 

#else
#ifdef HAVE_EXPAT_CONFIG_H
#include <expat_config.h>
#endif
#endif 

/* internal.h

   Internal definitions used by Expat.  This is not needed to compile
   client code.

   The following calling convention macros are defined for frequently
   called functions:

   FASTCALL    - Used for those internal functions that have a simple
                 body and a low number of arguments and local variables.

   PTRCALL     - Used for functions called though function pointers.

   PTRFASTCALL - Like PTRCALL, but for low number of arguments.

   inline      - Used for selected internal functions for which inlining
                 may improve performance on some platforms.

   Note: Use of these macros is based on judgement, not hard rules,
         and therefore subject to change.
*/

#if defined(__GNUC__) && defined(__i386__)

#define FASTCALL __attribute__((regparm(3)))
#define PTRFASTCALL __attribute__((regparm(3)))
#endif

#ifndef FASTCALL
#define FASTCALL
#endif

#ifndef PTRCALL
#define PTRCALL
#endif

#ifndef PTRFASTCALL
#define PTRFASTCALL
#endif

#ifndef XML_MIN_SIZE
#if !defined(__cplusplus) && !defined(inline)
#ifdef __GNUC__
#define inline __inline
#endif 
#endif
#endif 

#ifdef __cplusplus
#define inline inline
#else
#ifndef inline
#define inline
#endif
#endif

/* Copyright (c) 1998, 1999 Thai Open Source Software Center Ltd
   See the file COPYING for copying permission.
*/

#ifndef XmlTok_INCLUDED
#define XmlTok_INCLUDED 1

#ifdef __cplusplus
extern "C" {
#endif

#define XML_TOK_TRAILING_RSQB -5 

#define XML_TOK_NONE -4          
#define XML_TOK_TRAILING_CR -3   

#define XML_TOK_PARTIAL_CHAR -2  
#define XML_TOK_PARTIAL -1       
#define XML_TOK_INVALID 0

#define XML_TOK_START_TAG_WITH_ATTS 1
#define XML_TOK_START_TAG_NO_ATTS 2
#define XML_TOK_EMPTY_ELEMENT_WITH_ATTS 3 
#define XML_TOK_EMPTY_ELEMENT_NO_ATTS 4
#define XML_TOK_END_TAG 5
#define XML_TOK_DATA_CHARS 6
#define XML_TOK_DATA_NEWLINE 7
#define XML_TOK_CDATA_SECT_OPEN 8
#define XML_TOK_ENTITY_REF 9
#define XML_TOK_CHAR_REF 10               

#define XML_TOK_PI 11                     
#define XML_TOK_XML_DECL 12               
#define XML_TOK_COMMENT 13
#define XML_TOK_BOM 14                    

#define XML_TOK_PROLOG_S 15
#define XML_TOK_DECL_OPEN 16              
#define XML_TOK_DECL_CLOSE 17             
#define XML_TOK_NAME 18
#define XML_TOK_NMTOKEN 19
#define XML_TOK_POUND_NAME 20             
#define XML_TOK_OR 21                     
#define XML_TOK_PERCENT 22
#define XML_TOK_OPEN_PAREN 23
#define XML_TOK_CLOSE_PAREN 24
#define XML_TOK_OPEN_BRACKET 25
#define XML_TOK_CLOSE_BRACKET 26
#define XML_TOK_LITERAL 27
#define XML_TOK_PARAM_ENTITY_REF 28
#define XML_TOK_INSTANCE_START 29

#define XML_TOK_NAME_QUESTION 30          
#define XML_TOK_NAME_ASTERISK 31          
#define XML_TOK_NAME_PLUS 32              
#define XML_TOK_COND_SECT_OPEN 33         
#define XML_TOK_COND_SECT_CLOSE 34        
#define XML_TOK_CLOSE_PAREN_QUESTION 35   
#define XML_TOK_CLOSE_PAREN_ASTERISK 36   
#define XML_TOK_CLOSE_PAREN_PLUS 37       
#define XML_TOK_COMMA 38

#define XML_TOK_ATTRIBUTE_VALUE_S 39

#define XML_TOK_CDATA_SECT_CLOSE 40

#define XML_TOK_PREFIXED_NAME 41

#ifdef XML_DTD
#define XML_TOK_IGNORE_SECT 42
#endif 

#ifdef XML_DTD
#define XML_N_STATES 4
#else 
#define XML_N_STATES 3
#endif 

#define XML_PROLOG_STATE 0
#define XML_CONTENT_STATE 1
#define XML_CDATA_SECTION_STATE 2
#ifdef XML_DTD
#define XML_IGNORE_SECTION_STATE 3
#endif 

#define XML_N_LITERAL_TYPES 2
#define XML_ATTRIBUTE_VALUE_LITERAL 0
#define XML_ENTITY_VALUE_LITERAL 1

#define XML_UTF8_ENCODE_MAX 4

#define XML_UTF16_ENCODE_MAX 2

typedef struct position {
  
  unsigned long lineNumber;
  unsigned long columnNumber;
} POSITION;

typedef struct {
  const char *name;
  const char *valuePtr;
  const char *valueEnd;
  char normalized;
} ATTRIBUTE;

struct encoding;
typedef struct encoding ENCODING;

typedef int (PTRCALL *SCANNER)(const ENCODING *,
                               const char *,
                               const char *,
                               const char **);

struct encoding {
  SCANNER scanners[XML_N_STATES];
  SCANNER literalScanners[XML_N_LITERAL_TYPES];
  int (PTRCALL *sameName)(const ENCODING *,
                          const char *,
                          const char *);
  int (PTRCALL *nameMatchesAscii)(const ENCODING *,
                                  const char *,
                                  const char *,
                                  const char *);
  int (PTRFASTCALL *nameLength)(const ENCODING *, const char *);
  const char *(PTRFASTCALL *skipS)(const ENCODING *, const char *);
  int (PTRCALL *getAtts)(const ENCODING *enc,
                         const char *ptr,
                         int attsMax,
                         ATTRIBUTE *atts);
  int (PTRFASTCALL *charRefNumber)(const ENCODING *enc, const char *ptr);
  int (PTRCALL *predefinedEntityName)(const ENCODING *,
                                      const char *,
                                      const char *);
  void (PTRCALL *updatePosition)(const ENCODING *,
                                 const char *ptr,
                                 const char *end,
                                 POSITION *);
  int (PTRCALL *isPublicId)(const ENCODING *enc,
                            const char *ptr,
                            const char *end,
                            const char **badPtr);
  void (PTRCALL *utf8Convert)(const ENCODING *enc,
                              const char **fromP,
                              const char *fromLim,
                              char **toP,
                              const char *toLim);
  void (PTRCALL *utf16Convert)(const ENCODING *enc,
                               const char **fromP,
                               const char *fromLim,
                               unsigned short **toP,
                               const unsigned short *toLim);
  int minBytesPerChar;
  char isUtf8;
  char isUtf16;
};

#define XmlTok(enc, state, ptr, end, nextTokPtr) \
  (((enc)->scanners[state])(enc, ptr, end, nextTokPtr))

#define XmlPrologTok(enc, ptr, end, nextTokPtr) \
   XmlTok(enc, XML_PROLOG_STATE, ptr, end, nextTokPtr)

#define XmlContentTok(enc, ptr, end, nextTokPtr) \
   XmlTok(enc, XML_CONTENT_STATE, ptr, end, nextTokPtr)

#define XmlCdataSectionTok(enc, ptr, end, nextTokPtr) \
   XmlTok(enc, XML_CDATA_SECTION_STATE, ptr, end, nextTokPtr)

#ifdef XML_DTD

#define XmlIgnoreSectionTok(enc, ptr, end, nextTokPtr) \
   XmlTok(enc, XML_IGNORE_SECTION_STATE, ptr, end, nextTokPtr)

#endif 

#define XmlLiteralTok(enc, literalType, ptr, end, nextTokPtr) \
  (((enc)->literalScanners[literalType])(enc, ptr, end, nextTokPtr))

#define XmlAttributeValueTok(enc, ptr, end, nextTokPtr) \
   XmlLiteralTok(enc, XML_ATTRIBUTE_VALUE_LITERAL, ptr, end, nextTokPtr)

#define XmlEntityValueTok(enc, ptr, end, nextTokPtr) \
   XmlLiteralTok(enc, XML_ENTITY_VALUE_LITERAL, ptr, end, nextTokPtr)

#define XmlSameName(enc, ptr1, ptr2) (((enc)->sameName)(enc, ptr1, ptr2))

#define XmlNameMatchesAscii(enc, ptr1, end1, ptr2) \
  (((enc)->nameMatchesAscii)(enc, ptr1, end1, ptr2))

#define XmlNameLength(enc, ptr) \
  (((enc)->nameLength)(enc, ptr))

#define XmlSkipS(enc, ptr) \
  (((enc)->skipS)(enc, ptr))

#define XmlGetAttributes(enc, ptr, attsMax, atts) \
  (((enc)->getAtts)(enc, ptr, attsMax, atts))

#define XmlCharRefNumber(enc, ptr) \
  (((enc)->charRefNumber)(enc, ptr))

#define XmlPredefinedEntityName(enc, ptr, end) \
  (((enc)->predefinedEntityName)(enc, ptr, end))

#define XmlUpdatePosition(enc, ptr, end, pos) \
  (((enc)->updatePosition)(enc, ptr, end, pos))

#define XmlIsPublicId(enc, ptr, end, badPtr) \
  (((enc)->isPublicId)(enc, ptr, end, badPtr))

#define XmlUtf8Convert(enc, fromP, fromLim, toP, toLim) \
  (((enc)->utf8Convert)(enc, fromP, fromLim, toP, toLim))

#define XmlUtf16Convert(enc, fromP, fromLim, toP, toLim) \
  (((enc)->utf16Convert)(enc, fromP, fromLim, toP, toLim))

typedef struct {
  ENCODING initEnc;
  const ENCODING **encPtr;
} INIT_ENCODING;

int XmlParseXmlDecl(int isGeneralTextEntity,
                    const ENCODING *enc,
                    const char *ptr,
                    const char *end,
                    const char **badPtr,
                    const char **versionPtr,
                    const char **versionEndPtr,
                    const char **encodingNamePtr,
                    const ENCODING **namedEncodingPtr,
                    int *standalonePtr);

int XmlInitEncoding(INIT_ENCODING *, const ENCODING **, const char *name);
const ENCODING *XmlGetUtf8InternalEncoding(void);
const ENCODING *XmlGetUtf16InternalEncoding(void);
int FASTCALL XmlUtf8Encode(int charNumber, char *buf);
int FASTCALL XmlUtf16Encode(int charNumber, unsigned short *buf);
int XmlSizeOfUnknownEncoding(void);

typedef int (*CONVERTER)(void *userData, const char *p);

ENCODING *
XmlInitUnknownEncoding(void *mem,
                       int *table,
                       CONVERTER convert,
                       void *userData);

int XmlParseXmlDeclNS(int isGeneralTextEntity,
                      const ENCODING *enc,
                      const char *ptr,
                      const char *end,
                      const char **badPtr,
                      const char **versionPtr,
                      const char **versionEndPtr,
                      const char **encodingNamePtr,
                      const ENCODING **namedEncodingPtr,
                      int *standalonePtr);

int XmlInitEncodingNS(INIT_ENCODING *, const ENCODING **, const char *name);
const ENCODING *XmlGetUtf8InternalEncodingNS(void);
const ENCODING *XmlGetUtf16InternalEncodingNS(void);
ENCODING *
XmlInitUnknownEncodingNS(void *mem,
                         int *table,
                         CONVERTER convert,
                         void *userData);
#ifdef __cplusplus
}
#endif

#endif 

extern const unsigned namingBitmap[320];
extern const unsigned char nmstrtPages[256];
extern const unsigned char namePages[256];

#ifdef XML_DTD
#define IGNORE_SECTION_TOK_VTABLE , PREFIX(ignoreSectionTok)
#else
#define IGNORE_SECTION_TOK_VTABLE 
#endif

#define VTABLE1 \
  { PREFIX(prologTok), PREFIX(contentTok), \
    PREFIX(cdataSectionTok) IGNORE_SECTION_TOK_VTABLE }, \
  { PREFIX(attributeValueTok), PREFIX(entityValueTok) }, \
  PREFIX(sameName), \
  PREFIX(nameMatchesAscii), \
  PREFIX(nameLength), \
  PREFIX(skipS), \
  PREFIX(getAtts), \
  PREFIX(charRefNumber), \
  PREFIX(predefinedEntityName), \
  PREFIX(updatePosition), \
  PREFIX(isPublicId)

#define VTABLE VTABLE1, PREFIX(toUtf8), PREFIX(toUtf16)

#define UCS2_GET_NAMING(pages, hi, lo) \
   (namingBitmap[(pages[hi] << 3) + ((lo) >> 5)] & (1 << ((lo) & 0x1F)))

#define UTF8_GET_NAMING2(pages, byte) \
    (namingBitmap[((pages)[(((byte)[0]) >> 2) & 7] << 3) \
                      + ((((byte)[0]) & 3) << 1) \
                      + ((((byte)[1]) >> 5) & 1)] \
         & (1 << (((byte)[1]) & 0x1F)))

#define UTF8_GET_NAMING3(pages, byte) \
  (namingBitmap[((pages)[((((byte)[0]) & 0xF) << 4) \
                             + ((((byte)[1]) >> 2) & 0xF)] \
                       << 3) \
                      + ((((byte)[1]) & 3) << 1) \
                      + ((((byte)[2]) >> 5) & 1)] \
         & (1 << (((byte)[2]) & 0x1F)))

#define UTF8_GET_NAMING(pages, p, n) \
  ((n) == 2 \
  ? UTF8_GET_NAMING2(pages, (const unsigned char *)(p)) \
  : ((n) == 3 \
     ? UTF8_GET_NAMING3(pages, (const unsigned char *)(p)) \
     : 0))

#define UTF8_INVALID2(p) \
  ((*p) < 0xC2 || ((p)[1] & 0x80) == 0 || ((p)[1] & 0xC0) == 0xC0)

#define UTF8_INVALID3(p) \
  (((p)[2] & 0x80) == 0 \
  || \
  ((*p) == 0xEF && (p)[1] == 0xBF \
    ? \
    (p)[2] > 0xBD \
    : \
    ((p)[2] & 0xC0) == 0xC0) \
  || \
  ((*p) == 0xE0 \
    ? \
    (p)[1] < 0xA0 || ((p)[1] & 0xC0) == 0xC0 \
    : \
    ((p)[1] & 0x80) == 0 \
    || \
    ((*p) == 0xED ? (p)[1] > 0x9F : ((p)[1] & 0xC0) == 0xC0)))

#define UTF8_INVALID4(p) \
  (((p)[3] & 0x80) == 0 || ((p)[3] & 0xC0) == 0xC0 \
  || \
  ((p)[2] & 0x80) == 0 || ((p)[2] & 0xC0) == 0xC0 \
  || \
  ((*p) == 0xF0 \
    ? \
    (p)[1] < 0x90 || ((p)[1] & 0xC0) == 0xC0 \
    : \
    ((p)[1] & 0x80) == 0 \
    || \
    ((*p) == 0xF4 ? (p)[1] > 0x8F : ((p)[1] & 0xC0) == 0xC0)))

static int PTRFASTCALL
isNever(const ENCODING *enc, const char *p);

static int PTRFASTCALL
utf8_isName2(const ENCODING *enc, const char *p);

static int PTRFASTCALL
utf8_isName3(const ENCODING *enc, const char *p);

#define utf8_isName4 isNever

static int PTRFASTCALL
utf8_isNmstrt2(const ENCODING *enc, const char *p);

static int PTRFASTCALL
utf8_isNmstrt3(const ENCODING *enc, const char *p);

#define utf8_isNmstrt4 isNever

static int PTRFASTCALL
utf8_isInvalid2(const ENCODING *enc, const char *p);

static int PTRFASTCALL
utf8_isInvalid3(const ENCODING *enc, const char *p);

static int PTRFASTCALL
utf8_isInvalid4(const ENCODING *enc, const char *p);

struct normal_encoding {
  ENCODING enc;
  unsigned char type[256];
#ifdef XML_MIN_SIZE
  int (PTRFASTCALL *byteType)(const ENCODING *, const char *);
  int (PTRFASTCALL *isNameMin)(const ENCODING *, const char *);
  int (PTRFASTCALL *isNmstrtMin)(const ENCODING *, const char *);
  int (PTRFASTCALL *byteToAscii)(const ENCODING *, const char *);
  int (PTRCALL *charMatches)(const ENCODING *, const char *, int);
#endif 
  int (PTRFASTCALL *isName2)(const ENCODING *, const char *);
  int (PTRFASTCALL *isName3)(const ENCODING *, const char *);
  int (PTRFASTCALL *isName4)(const ENCODING *, const char *);
  int (PTRFASTCALL *isNmstrt2)(const ENCODING *, const char *);
  int (PTRFASTCALL *isNmstrt3)(const ENCODING *, const char *);
  int (PTRFASTCALL *isNmstrt4)(const ENCODING *, const char *);
  int (PTRFASTCALL *isInvalid2)(const ENCODING *, const char *);
  int (PTRFASTCALL *isInvalid3)(const ENCODING *, const char *);
  int (PTRFASTCALL *isInvalid4)(const ENCODING *, const char *);
};

#define AS_NORMAL_ENCODING(enc)   ((const struct normal_encoding *) (enc))

#ifdef XML_MIN_SIZE

#define STANDARD_VTABLE(E) \
 E ## byteType, \
 E ## isNameMin, \
 E ## isNmstrtMin, \
 E ## byteToAscii, \
 E ## charMatches,

#else

#define STANDARD_VTABLE(E) 

#endif

#define NORMAL_VTABLE(E) \
 E ## isName2, \
 E ## isName3, \
 E ## isName4, \
 E ## isNmstrt2, \
 E ## isNmstrt3, \
 E ## isNmstrt4, \
 E ## isInvalid2, \
 E ## isInvalid3, \
 E ## isInvalid4

static int FASTCALL checkCharRefNumber(int);

/*
Copyright (c) 1998, 1999 Thai Open Source Software Center Ltd
See the file COPYING for copying permission.
*/

enum {
  BT_NONXML,
  BT_MALFORM,
  BT_LT,
  BT_AMP,
  BT_RSQB,
  BT_LEAD2,
  BT_LEAD3,
  BT_LEAD4,
  BT_TRAIL,
  BT_CR,
  BT_LF,
  BT_GT,
  BT_QUOT,
  BT_APOS,
  BT_EQUALS,
  BT_QUEST,
  BT_EXCL,
  BT_SOL,
  BT_SEMI,
  BT_NUM,
  BT_LSQB,
  BT_S,
  BT_NMSTRT,
  BT_COLON,
  BT_HEX,
  BT_DIGIT,
  BT_NAME,
  BT_MINUS,
  BT_OTHER, 
  BT_NONASCII, 
  BT_PERCNT,
  BT_LPAR,
  BT_RPAR,
  BT_AST,
  BT_PLUS,
  BT_COMMA,
  BT_VERBAR
};

#ifndef _STDDEF_H
#define _STDDEF_H
#ifndef SHIM_SIZE_T
#define SHIM_SIZE_T unsigned int
#endif
typedef SHIM_SIZE_T size_t;
#ifndef SHIM_PTRDIFF_T
#define SHIM_PTRDIFF_T int
#endif
typedef SHIM_PTRDIFF_T ptrdiff_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif

/* Copyright (c) 1998, 1999 Thai Open Source Software Center Ltd
   See the file COPYING for copying permission.
*/

#define ASCII_A 0x41
#define ASCII_B 0x42
#define ASCII_C 0x43
#define ASCII_D 0x44
#define ASCII_E 0x45
#define ASCII_F 0x46
#define ASCII_G 0x47
#define ASCII_H 0x48
#define ASCII_I 0x49
#define ASCII_J 0x4A
#define ASCII_K 0x4B
#define ASCII_L 0x4C
#define ASCII_M 0x4D
#define ASCII_N 0x4E
#define ASCII_O 0x4F
#define ASCII_P 0x50
#define ASCII_Q 0x51
#define ASCII_R 0x52
#define ASCII_S 0x53
#define ASCII_T 0x54
#define ASCII_U 0x55
#define ASCII_V 0x56
#define ASCII_W 0x57
#define ASCII_X 0x58
#define ASCII_Y 0x59
#define ASCII_Z 0x5A

#define ASCII_a 0x61
#define ASCII_b 0x62
#define ASCII_c 0x63
#define ASCII_d 0x64
#define ASCII_e 0x65
#define ASCII_f 0x66
#define ASCII_g 0x67
#define ASCII_h 0x68
#define ASCII_i 0x69
#define ASCII_j 0x6A
#define ASCII_k 0x6B
#define ASCII_l 0x6C
#define ASCII_m 0x6D
#define ASCII_n 0x6E
#define ASCII_o 0x6F
#define ASCII_p 0x70
#define ASCII_q 0x71
#define ASCII_r 0x72
#define ASCII_s 0x73
#define ASCII_t 0x74
#define ASCII_u 0x75
#define ASCII_v 0x76
#define ASCII_w 0x77
#define ASCII_x 0x78
#define ASCII_y 0x79
#define ASCII_z 0x7A

#define ASCII_0 0x30
#define ASCII_1 0x31
#define ASCII_2 0x32
#define ASCII_3 0x33
#define ASCII_4 0x34
#define ASCII_5 0x35
#define ASCII_6 0x36
#define ASCII_7 0x37
#define ASCII_8 0x38
#define ASCII_9 0x39

#define ASCII_TAB 0x09
#define ASCII_SPACE 0x20
#define ASCII_EXCL 0x21
#define ASCII_QUOT 0x22
#define ASCII_AMP 0x26
#define ASCII_APOS 0x27
#define ASCII_MINUS 0x2D
#define ASCII_PERIOD 0x2E
#define ASCII_COLON 0x3A
#define ASCII_SEMI 0x3B
#define ASCII_LT 0x3C
#define ASCII_EQUALS 0x3D
#define ASCII_GT 0x3E
#define ASCII_LSQB 0x5B
#define ASCII_RSQB 0x5D
#define ASCII_UNDERSCORE 0x5F

#ifdef XML_MIN_SIZE
#define sb_isNameMin isNever
#define sb_isNmstrtMin isNever
#endif

#ifdef XML_MIN_SIZE
#define MINBPC(enc) ((enc)->minBytesPerChar)
#else

#define MINBPC(enc) 1
#endif

#define SB_BYTE_TYPE(enc, p) \
  (((struct normal_encoding *)(enc))->type[(unsigned char)*(p)])

#ifdef XML_MIN_SIZE
static int PTRFASTCALL
sb_byteType(const ENCODING *enc, const char *p);
#define BYTE_TYPE(enc, p) \
 (AS_NORMAL_ENCODING(enc)->byteType(enc, p))
#else
#define BYTE_TYPE(enc, p) SB_BYTE_TYPE(enc, p)
#endif

#ifdef XML_MIN_SIZE
#define BYTE_TO_ASCII(enc, p) \
 (AS_NORMAL_ENCODING(enc)->byteToAscii(enc, p))
static int PTRFASTCALL
sb_byteToAscii(const ENCODING *enc, const char *p);
#else
#define BYTE_TO_ASCII(enc, p) (*(p))
#endif

#define IS_NAME_CHAR(enc, p, n) \
 (AS_NORMAL_ENCODING(enc)->isName ## n(enc, p))
#define IS_NMSTRT_CHAR(enc, p, n) \
 (AS_NORMAL_ENCODING(enc)->isNmstrt ## n(enc, p))
#define IS_INVALID_CHAR(enc, p, n) \
 (AS_NORMAL_ENCODING(enc)->isInvalid ## n(enc, p))

#ifdef XML_MIN_SIZE
#define IS_NAME_CHAR_MINBPC(enc, p) \
 (AS_NORMAL_ENCODING(enc)->isNameMin(enc, p))
#define IS_NMSTRT_CHAR_MINBPC(enc, p) \
 (AS_NORMAL_ENCODING(enc)->isNmstrtMin(enc, p))
#else
#define IS_NAME_CHAR_MINBPC(enc, p) (0)
#define IS_NMSTRT_CHAR_MINBPC(enc, p) (0)
#endif

#ifdef XML_MIN_SIZE
#define CHAR_MATCHES(enc, p, c) \
 (AS_NORMAL_ENCODING(enc)->charMatches(enc, p, c))
static int PTRCALL
sb_charMatches(const ENCODING *enc, const char *p, int c);
#else

#define CHAR_MATCHES(enc, p, c) (*(p) == c)
#endif

#define PREFIX(ident) normal_ ## ident
/* Copyright (c) 1998, 1999 Thai Open Source Software Center Ltd
   See the file COPYING for copying permission.
*/

#ifndef IS_INVALID_CHAR
#define IS_INVALID_CHAR(enc, ptr, n) (0)
#endif

#define INVALID_LEAD_CASE(n, ptr, nextTokPtr) \
    case BT_LEAD ## n: \
      if (end - ptr < n) \
        return XML_TOK_PARTIAL_CHAR; \
      if (IS_INVALID_CHAR(enc, ptr, n)) { \
        *(nextTokPtr) = (ptr); \
        return XML_TOK_INVALID; \
      } \
      ptr += n; \
      break;

#define INVALID_CASES(ptr, nextTokPtr) \
  INVALID_LEAD_CASE(2, ptr, nextTokPtr) \
  INVALID_LEAD_CASE(3, ptr, nextTokPtr) \
  INVALID_LEAD_CASE(4, ptr, nextTokPtr) \
  case BT_NONXML: \
  case BT_MALFORM: \
  case BT_TRAIL: \
    *(nextTokPtr) = (ptr); \
    return XML_TOK_INVALID;

#define CHECK_NAME_CASE(n, enc, ptr, end, nextTokPtr) \
   case BT_LEAD ## n: \
     if (end - ptr < n) \
       return XML_TOK_PARTIAL_CHAR; \
     if (!IS_NAME_CHAR(enc, ptr, n)) { \
       *nextTokPtr = ptr; \
       return XML_TOK_INVALID; \
     } \
     ptr += n; \
     break;

#define CHECK_NAME_CASES(enc, ptr, end, nextTokPtr) \
  case BT_NONASCII: \
    if (!IS_NAME_CHAR_MINBPC(enc, ptr)) { \
      *nextTokPtr = ptr; \
      return XML_TOK_INVALID; \
    } \
  case BT_NMSTRT: \
  case BT_HEX: \
  case BT_DIGIT: \
  case BT_NAME: \
  case BT_MINUS: \
    ptr += MINBPC(enc); \
    break; \
  CHECK_NAME_CASE(2, enc, ptr, end, nextTokPtr) \
  CHECK_NAME_CASE(3, enc, ptr, end, nextTokPtr) \
  CHECK_NAME_CASE(4, enc, ptr, end, nextTokPtr)

#define CHECK_NMSTRT_CASE(n, enc, ptr, end, nextTokPtr) \
   case BT_LEAD ## n: \
     if (end - ptr < n) \
       return XML_TOK_PARTIAL_CHAR; \
     if (!IS_NMSTRT_CHAR(enc, ptr, n)) { \
       *nextTokPtr = ptr; \
       return XML_TOK_INVALID; \
     } \
     ptr += n; \
     break;

#define CHECK_NMSTRT_CASES(enc, ptr, end, nextTokPtr) \
  case BT_NONASCII: \
    if (!IS_NMSTRT_CHAR_MINBPC(enc, ptr)) { \
      *nextTokPtr = ptr; \
      return XML_TOK_INVALID; \
    } \
  case BT_NMSTRT: \
  case BT_HEX: \
    ptr += MINBPC(enc); \
    break; \
  CHECK_NMSTRT_CASE(2, enc, ptr, end, nextTokPtr) \
  CHECK_NMSTRT_CASE(3, enc, ptr, end, nextTokPtr) \
  CHECK_NMSTRT_CASE(4, enc, ptr, end, nextTokPtr)

#ifndef PREFIX
#define PREFIX(ident) ident
#endif

static int PTRCALL
PREFIX(scanComment)(const ENCODING *enc, const char *ptr,
                    const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanDecl)(const ENCODING *enc, const char *ptr,
                 const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(checkPiTarget)(const ENCODING *enc, const char *ptr,
                      const char *end, int *tokPtr);

static int PTRCALL
PREFIX(scanPi)(const ENCODING *enc, const char *ptr,
               const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanCdataSection)(const ENCODING *enc, const char *ptr,
                         const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(cdataSectionTok)(const ENCODING *enc, const char *ptr,
                        const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanEndTag)(const ENCODING *enc, const char *ptr,
                   const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanHexCharRef)(const ENCODING *enc, const char *ptr,
                       const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanCharRef)(const ENCODING *enc, const char *ptr,
                    const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanRef)(const ENCODING *enc, const char *ptr, const char *end,
                const char **nextTokPtr);

static int PTRCALL
PREFIX(scanAtts)(const ENCODING *enc, const char *ptr, const char *end,
                 const char **nextTokPtr);

static int PTRCALL
PREFIX(scanLt)(const ENCODING *enc, const char *ptr, const char *end,
               const char **nextTokPtr);

static int PTRCALL
PREFIX(contentTok)(const ENCODING *enc, const char *ptr, const char *end,
                   const char **nextTokPtr);

static int PTRCALL
PREFIX(scanPercent)(const ENCODING *enc, const char *ptr, const char *end,
                    const char **nextTokPtr);

static int PTRCALL
PREFIX(scanPoundName)(const ENCODING *enc, const char *ptr, const char *end,
                      const char **nextTokPtr);

static int PTRCALL
PREFIX(scanLit)(int open, const ENCODING *enc,
                const char *ptr, const char *end,
                const char **nextTokPtr);

static int PTRCALL
PREFIX(prologTok)(const ENCODING *enc, const char *ptr, const char *end,
                  const char **nextTokPtr);

static int PTRCALL
PREFIX(attributeValueTok)(const ENCODING *enc, const char *ptr,
                          const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(entityValueTok)(const ENCODING *enc, const char *ptr,
                       const char *end, const char **nextTokPtr);

#ifdef XML_DTD

static int PTRCALL
PREFIX(ignoreSectionTok)(const ENCODING *enc, const char *ptr,
                         const char *end, const char **nextTokPtr);

#endif 

static int PTRCALL
PREFIX(isPublicId)(const ENCODING *enc, const char *ptr, const char *end,
                   const char **badPtr);

static int PTRCALL
PREFIX(getAtts)(const ENCODING *enc, const char *ptr,
                int attsMax, ATTRIBUTE *atts);

static int PTRFASTCALL
PREFIX(charRefNumber)(const ENCODING *enc, const char *ptr);

static int PTRCALL
PREFIX(predefinedEntityName)(const ENCODING *enc, const char *ptr,
                             const char *end);

static int PTRCALL
PREFIX(sameName)(const ENCODING *enc, const char *ptr1, const char *ptr2);

static int PTRCALL
PREFIX(nameMatchesAscii)(const ENCODING *enc, const char *ptr1,
                         const char *end1, const char *ptr2);

static int PTRFASTCALL
PREFIX(nameLength)(const ENCODING *enc, const char *ptr);

static const char * PTRFASTCALL
PREFIX(skipS)(const ENCODING *enc, const char *ptr);

static void PTRCALL
PREFIX(updatePosition)(const ENCODING *enc,
                       const char *ptr,
                       const char *end,
                       POSITION *pos);

#undef DO_LEAD_CASE
#undef MULTIBYTE_CASES
#undef INVALID_CASES
#undef CHECK_NAME_CASE
#undef CHECK_NAME_CASES
#undef CHECK_NMSTRT_CASE
#undef CHECK_NMSTRT_CASES

#undef MINBPC
#undef BYTE_TYPE
#undef BYTE_TO_ASCII
#undef CHAR_MATCHES
#undef IS_NAME_CHAR
#undef IS_NAME_CHAR_MINBPC
#undef IS_NMSTRT_CHAR
#undef IS_NMSTRT_CHAR_MINBPC
#undef IS_INVALID_CHAR

enum {  
  UTF8_cval1 = 0x00,
  UTF8_cval2 = 0xc0,
  UTF8_cval3 = 0xe0,
  UTF8_cval4 = 0xf0
};

static void PTRCALL
utf8_toUtf8(const ENCODING *enc,
            const char **fromP, const char *fromLim,
            char **toP, const char *toLim);

static void PTRCALL
utf8_toUtf16(const ENCODING *enc,
             const char **fromP, const char *fromLim,
             unsigned short **toP, const unsigned short *toLim);

#ifdef XML_NS
extern const struct normal_encoding utf8_encoding_ns;
#endif

extern const struct normal_encoding utf8_encoding;

#ifdef XML_NS

extern const struct normal_encoding internal_utf8_encoding_ns;

#endif

extern const struct normal_encoding internal_utf8_encoding;

static void PTRCALL
latin1_toUtf8(const ENCODING *enc,
              const char **fromP, const char *fromLim,
              char **toP, const char *toLim);

static void PTRCALL
latin1_toUtf16(const ENCODING *enc,
               const char **fromP, const char *fromLim,
               unsigned short **toP, const unsigned short *toLim);

#ifdef XML_NS

extern const struct normal_encoding latin1_encoding_ns;

#endif

extern const struct normal_encoding latin1_encoding;

static void PTRCALL
ascii_toUtf8(const ENCODING *enc,
             const char **fromP, const char *fromLim,
             char **toP, const char *toLim);

#ifdef XML_NS

extern const struct normal_encoding ascii_encoding_ns;

#endif

extern const struct normal_encoding ascii_encoding;

static int PTRFASTCALL
unicode_byte_type(char hi, char lo);

#define DEFINE_UTF16_TO_UTF8(E) \
static void  PTRCALL \
E ## toUtf8(const ENCODING *enc, \
            const char **fromP, const char *fromLim, \
            char **toP, const char *toLim) \
{ \
  const char *from; \
  for (from = *fromP; from != fromLim; from += 2) { \
    int plane; \
    unsigned char lo2; \
    unsigned char lo = GET_LO(from); \
    unsigned char hi = GET_HI(from); \
    switch (hi) { \
    case 0: \
      if (lo < 0x80) { \
        if (*toP == toLim) { \
          *fromP = from; \
          return; \
        } \
        *(*toP)++ = lo; \
        break; \
      } \
       \
    case 0x1: case 0x2: case 0x3: \
    case 0x4: case 0x5: case 0x6: case 0x7: \
      if (toLim -  *toP < 2) { \
        *fromP = from; \
        return; \
      } \
      *(*toP)++ = ((lo >> 6) | (hi << 2) |  UTF8_cval2); \
      *(*toP)++ = ((lo & 0x3f) | 0x80); \
      break; \
    default: \
      if (toLim -  *toP < 3)  { \
        *fromP = from; \
        return; \
      } \
       \
      *(*toP)++ = ((hi >> 4) | UTF8_cval3); \
      *(*toP)++ = (((hi & 0xf) << 2) | (lo >> 6) | 0x80); \
      *(*toP)++ = ((lo & 0x3f) | 0x80); \
      break; \
    case 0xD8: case 0xD9: case 0xDA: case 0xDB: \
      if (toLim -  *toP < 4) { \
        *fromP = from; \
        return; \
      } \
      plane = (((hi & 0x3) << 2) | ((lo >> 6) & 0x3)) + 1; \
      *(*toP)++ = ((plane >> 2) | UTF8_cval4); \
      *(*toP)++ = (((lo >> 2) & 0xF) | ((plane & 0x3) << 4) | 0x80); \
      from += 2; \
      lo2 = GET_LO(from); \
      *(*toP)++ = (((lo & 0x3) << 4) \
                   | ((GET_HI(from) & 0x3) << 2) \
                   | (lo2 >> 6) \
                   | 0x80); \
      *(*toP)++ = ((lo2 & 0x3f) | 0x80); \
      break; \
    } \
  } \
  *fromP = from; \
}

#define DEFINE_UTF16_TO_UTF16(E) \
static void  PTRCALL \
E ## toUtf16(const ENCODING *enc, \
             const char **fromP, const char *fromLim, \
             unsigned short **toP, const unsigned short *toLim) \
{ \
   \
  if (fromLim - *fromP > ((toLim - *toP) << 1) \
      && (GET_HI(fromLim - 2) & 0xF8) == 0xD8) \
    fromLim -= 2; \
  for (; *fromP != fromLim && *toP != toLim; *fromP += 2) \
    *(*toP)++ = (GET_HI(*fromP) << 8) | GET_LO(*fromP); \
}

#define SET2(ptr, ch) \
  (((ptr)[0] = ((ch) & 0xff)), ((ptr)[1] = ((ch) >> 8)))
#define GET_LO(ptr) ((unsigned char)(ptr)[0])
#define GET_HI(ptr) ((unsigned char)(ptr)[1])

 
static void  PTRCALL 
little2_toUtf8(const ENCODING *enc, 
            const char **fromP, const char *fromLim, 
            char **toP, const char *toLim);
 
static void  PTRCALL 
little2_toUtf16(const ENCODING *enc, 
             const char **fromP, const char *fromLim, 
             unsigned short **toP, const unsigned short *toLim);

#undef SET2
#undef GET_LO
#undef GET_HI

#define SET2(ptr, ch) \
  (((ptr)[0] = ((ch) >> 8)), ((ptr)[1] = ((ch) & 0xFF)))
#define GET_LO(ptr) ((unsigned char)(ptr)[1])
#define GET_HI(ptr) ((unsigned char)(ptr)[0])

 
static void  PTRCALL 
big2_toUtf8(const ENCODING *enc, 
            const char **fromP, const char *fromLim, 
            char **toP, const char *toLim);
 
static void  PTRCALL 
big2_toUtf16(const ENCODING *enc, 
             const char **fromP, const char *fromLim, 
             unsigned short **toP, const unsigned short *toLim);

#undef SET2
#undef GET_LO
#undef GET_HI

#define LITTLE2_BYTE_TYPE(enc, p) \
 ((p)[1] == 0 \
  ? ((struct normal_encoding *)(enc))->type[(unsigned char)*(p)] \
  : unicode_byte_type((p)[1], (p)[0]))
#define LITTLE2_BYTE_TO_ASCII(enc, p) ((p)[1] == 0 ? (p)[0] : -1)
#define LITTLE2_CHAR_MATCHES(enc, p, c) ((p)[1] == 0 && (p)[0] == c)
#define LITTLE2_IS_NAME_CHAR_MINBPC(enc, p) \
  UCS2_GET_NAMING(namePages, (unsigned char)p[1], (unsigned char)p[0])
#define LITTLE2_IS_NMSTRT_CHAR_MINBPC(enc, p) \
  UCS2_GET_NAMING(nmstrtPages, (unsigned char)p[1], (unsigned char)p[0])

#ifdef XML_MIN_SIZE

static int PTRFASTCALL
little2_byteType(const ENCODING *enc, const char *p);

static int PTRFASTCALL
little2_byteToAscii(const ENCODING *enc, const char *p);

static int PTRCALL
little2_charMatches(const ENCODING *enc, const char *p, int c);

static int PTRFASTCALL
little2_isNameMin(const ENCODING *enc, const char *p);

static int PTRFASTCALL
little2_isNmstrtMin(const ENCODING *enc, const char *p);

#undef VTABLE
#define VTABLE VTABLE1, little2_toUtf8, little2_toUtf16

#else 

#undef PREFIX
#define PREFIX(ident) little2_ ## ident
#define MINBPC(enc) 2

#define BYTE_TYPE(enc, p) LITTLE2_BYTE_TYPE(enc, p)
#define BYTE_TO_ASCII(enc, p) LITTLE2_BYTE_TO_ASCII(enc, p)
#define CHAR_MATCHES(enc, p, c) LITTLE2_CHAR_MATCHES(enc, p, c)
#define IS_NAME_CHAR(enc, p, n) 0
#define IS_NAME_CHAR_MINBPC(enc, p) LITTLE2_IS_NAME_CHAR_MINBPC(enc, p)
#define IS_NMSTRT_CHAR(enc, p, n) (0)
#define IS_NMSTRT_CHAR_MINBPC(enc, p) LITTLE2_IS_NMSTRT_CHAR_MINBPC(enc, p)

/* Copyright (c) 1998, 1999 Thai Open Source Software Center Ltd
   See the file COPYING for copying permission.
*/

#ifndef IS_INVALID_CHAR
#define IS_INVALID_CHAR(enc, ptr, n) (0)
#endif

#define INVALID_LEAD_CASE(n, ptr, nextTokPtr) \
    case BT_LEAD ## n: \
      if (end - ptr < n) \
        return XML_TOK_PARTIAL_CHAR; \
      if (IS_INVALID_CHAR(enc, ptr, n)) { \
        *(nextTokPtr) = (ptr); \
        return XML_TOK_INVALID; \
      } \
      ptr += n; \
      break;

#define INVALID_CASES(ptr, nextTokPtr) \
  INVALID_LEAD_CASE(2, ptr, nextTokPtr) \
  INVALID_LEAD_CASE(3, ptr, nextTokPtr) \
  INVALID_LEAD_CASE(4, ptr, nextTokPtr) \
  case BT_NONXML: \
  case BT_MALFORM: \
  case BT_TRAIL: \
    *(nextTokPtr) = (ptr); \
    return XML_TOK_INVALID;

#define CHECK_NAME_CASE(n, enc, ptr, end, nextTokPtr) \
   case BT_LEAD ## n: \
     if (end - ptr < n) \
       return XML_TOK_PARTIAL_CHAR; \
     if (!IS_NAME_CHAR(enc, ptr, n)) { \
       *nextTokPtr = ptr; \
       return XML_TOK_INVALID; \
     } \
     ptr += n; \
     break;

#define CHECK_NAME_CASES(enc, ptr, end, nextTokPtr) \
  case BT_NONASCII: \
    if (!IS_NAME_CHAR_MINBPC(enc, ptr)) { \
      *nextTokPtr = ptr; \
      return XML_TOK_INVALID; \
    } \
  case BT_NMSTRT: \
  case BT_HEX: \
  case BT_DIGIT: \
  case BT_NAME: \
  case BT_MINUS: \
    ptr += MINBPC(enc); \
    break; \
  CHECK_NAME_CASE(2, enc, ptr, end, nextTokPtr) \
  CHECK_NAME_CASE(3, enc, ptr, end, nextTokPtr) \
  CHECK_NAME_CASE(4, enc, ptr, end, nextTokPtr)

#define CHECK_NMSTRT_CASE(n, enc, ptr, end, nextTokPtr) \
   case BT_LEAD ## n: \
     if (end - ptr < n) \
       return XML_TOK_PARTIAL_CHAR; \
     if (!IS_NMSTRT_CHAR(enc, ptr, n)) { \
       *nextTokPtr = ptr; \
       return XML_TOK_INVALID; \
     } \
     ptr += n; \
     break;

#define CHECK_NMSTRT_CASES(enc, ptr, end, nextTokPtr) \
  case BT_NONASCII: \
    if (!IS_NMSTRT_CHAR_MINBPC(enc, ptr)) { \
      *nextTokPtr = ptr; \
      return XML_TOK_INVALID; \
    } \
  case BT_NMSTRT: \
  case BT_HEX: \
    ptr += MINBPC(enc); \
    break; \
  CHECK_NMSTRT_CASE(2, enc, ptr, end, nextTokPtr) \
  CHECK_NMSTRT_CASE(3, enc, ptr, end, nextTokPtr) \
  CHECK_NMSTRT_CASE(4, enc, ptr, end, nextTokPtr)

#ifndef PREFIX
#define PREFIX(ident) ident
#endif

static int PTRCALL
PREFIX(scanComment)(const ENCODING *enc, const char *ptr,
                    const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanDecl)(const ENCODING *enc, const char *ptr,
                 const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(checkPiTarget)(const ENCODING *enc, const char *ptr,
                      const char *end, int *tokPtr);

static int PTRCALL
PREFIX(scanPi)(const ENCODING *enc, const char *ptr,
               const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanCdataSection)(const ENCODING *enc, const char *ptr,
                         const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(cdataSectionTok)(const ENCODING *enc, const char *ptr,
                        const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanEndTag)(const ENCODING *enc, const char *ptr,
                   const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanHexCharRef)(const ENCODING *enc, const char *ptr,
                       const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanCharRef)(const ENCODING *enc, const char *ptr,
                    const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanRef)(const ENCODING *enc, const char *ptr, const char *end,
                const char **nextTokPtr);

static int PTRCALL
PREFIX(scanAtts)(const ENCODING *enc, const char *ptr, const char *end,
                 const char **nextTokPtr);

static int PTRCALL
PREFIX(scanLt)(const ENCODING *enc, const char *ptr, const char *end,
               const char **nextTokPtr);

static int PTRCALL
PREFIX(contentTok)(const ENCODING *enc, const char *ptr, const char *end,
                   const char **nextTokPtr);

static int PTRCALL
PREFIX(scanPercent)(const ENCODING *enc, const char *ptr, const char *end,
                    const char **nextTokPtr);

static int PTRCALL
PREFIX(scanPoundName)(const ENCODING *enc, const char *ptr, const char *end,
                      const char **nextTokPtr);

static int PTRCALL
PREFIX(scanLit)(int open, const ENCODING *enc,
                const char *ptr, const char *end,
                const char **nextTokPtr);

static int PTRCALL
PREFIX(prologTok)(const ENCODING *enc, const char *ptr, const char *end,
                  const char **nextTokPtr);

static int PTRCALL
PREFIX(attributeValueTok)(const ENCODING *enc, const char *ptr,
                          const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(entityValueTok)(const ENCODING *enc, const char *ptr,
                       const char *end, const char **nextTokPtr);

#ifdef XML_DTD

static int PTRCALL
PREFIX(ignoreSectionTok)(const ENCODING *enc, const char *ptr,
                         const char *end, const char **nextTokPtr);

#endif 

static int PTRCALL
PREFIX(isPublicId)(const ENCODING *enc, const char *ptr, const char *end,
                   const char **badPtr);

static int PTRCALL
PREFIX(getAtts)(const ENCODING *enc, const char *ptr,
                int attsMax, ATTRIBUTE *atts);

static int PTRFASTCALL
PREFIX(charRefNumber)(const ENCODING *enc, const char *ptr);

static int PTRCALL
PREFIX(predefinedEntityName)(const ENCODING *enc, const char *ptr,
                             const char *end);

static int PTRCALL
PREFIX(sameName)(const ENCODING *enc, const char *ptr1, const char *ptr2);

static int PTRCALL
PREFIX(nameMatchesAscii)(const ENCODING *enc, const char *ptr1,
                         const char *end1, const char *ptr2);

static int PTRFASTCALL
PREFIX(nameLength)(const ENCODING *enc, const char *ptr);

static const char * PTRFASTCALL
PREFIX(skipS)(const ENCODING *enc, const char *ptr);

static void PTRCALL
PREFIX(updatePosition)(const ENCODING *enc,
                       const char *ptr,
                       const char *end,
                       POSITION *pos);

#undef DO_LEAD_CASE
#undef MULTIBYTE_CASES
#undef INVALID_CASES
#undef CHECK_NAME_CASE
#undef CHECK_NAME_CASES
#undef CHECK_NMSTRT_CASE
#undef CHECK_NMSTRT_CASES

#undef MINBPC
#undef BYTE_TYPE
#undef BYTE_TO_ASCII
#undef CHAR_MATCHES
#undef IS_NAME_CHAR
#undef IS_NAME_CHAR_MINBPC
#undef IS_NMSTRT_CHAR
#undef IS_NMSTRT_CHAR_MINBPC
#undef IS_INVALID_CHAR

#endif 

#ifdef XML_NS

extern const struct normal_encoding little2_encoding_ns;

#endif

extern const struct normal_encoding little2_encoding;

#if BYTEORDER != 4321

#ifdef XML_NS

extern const struct normal_encoding internal_little2_encoding_ns;

#endif

extern const struct normal_encoding internal_little2_encoding;

#endif

#define BIG2_BYTE_TYPE(enc, p) \
 ((p)[0] == 0 \
  ? ((struct normal_encoding *)(enc))->type[(unsigned char)(p)[1]] \
  : unicode_byte_type((p)[0], (p)[1]))
#define BIG2_BYTE_TO_ASCII(enc, p) ((p)[0] == 0 ? (p)[1] : -1)
#define BIG2_CHAR_MATCHES(enc, p, c) ((p)[0] == 0 && (p)[1] == c)
#define BIG2_IS_NAME_CHAR_MINBPC(enc, p) \
  UCS2_GET_NAMING(namePages, (unsigned char)p[0], (unsigned char)p[1])
#define BIG2_IS_NMSTRT_CHAR_MINBPC(enc, p) \
  UCS2_GET_NAMING(nmstrtPages, (unsigned char)p[0], (unsigned char)p[1])

#ifdef XML_MIN_SIZE

static int PTRFASTCALL
big2_byteType(const ENCODING *enc, const char *p);

static int PTRFASTCALL
big2_byteToAscii(const ENCODING *enc, const char *p);

static int PTRCALL
big2_charMatches(const ENCODING *enc, const char *p, int c);

static int PTRFASTCALL
big2_isNameMin(const ENCODING *enc, const char *p);

static int PTRFASTCALL
big2_isNmstrtMin(const ENCODING *enc, const char *p);

#undef VTABLE
#define VTABLE VTABLE1, big2_toUtf8, big2_toUtf16

#else 

#undef PREFIX
#define PREFIX(ident) big2_ ## ident
#define MINBPC(enc) 2

#define BYTE_TYPE(enc, p) BIG2_BYTE_TYPE(enc, p)
#define BYTE_TO_ASCII(enc, p) BIG2_BYTE_TO_ASCII(enc, p)
#define CHAR_MATCHES(enc, p, c) BIG2_CHAR_MATCHES(enc, p, c)
#define IS_NAME_CHAR(enc, p, n) 0
#define IS_NAME_CHAR_MINBPC(enc, p) BIG2_IS_NAME_CHAR_MINBPC(enc, p)
#define IS_NMSTRT_CHAR(enc, p, n) (0)
#define IS_NMSTRT_CHAR_MINBPC(enc, p) BIG2_IS_NMSTRT_CHAR_MINBPC(enc, p)

/* Copyright (c) 1998, 1999 Thai Open Source Software Center Ltd
   See the file COPYING for copying permission.
*/

#ifndef IS_INVALID_CHAR
#define IS_INVALID_CHAR(enc, ptr, n) (0)
#endif

#define INVALID_LEAD_CASE(n, ptr, nextTokPtr) \
    case BT_LEAD ## n: \
      if (end - ptr < n) \
        return XML_TOK_PARTIAL_CHAR; \
      if (IS_INVALID_CHAR(enc, ptr, n)) { \
        *(nextTokPtr) = (ptr); \
        return XML_TOK_INVALID; \
      } \
      ptr += n; \
      break;

#define INVALID_CASES(ptr, nextTokPtr) \
  INVALID_LEAD_CASE(2, ptr, nextTokPtr) \
  INVALID_LEAD_CASE(3, ptr, nextTokPtr) \
  INVALID_LEAD_CASE(4, ptr, nextTokPtr) \
  case BT_NONXML: \
  case BT_MALFORM: \
  case BT_TRAIL: \
    *(nextTokPtr) = (ptr); \
    return XML_TOK_INVALID;

#define CHECK_NAME_CASE(n, enc, ptr, end, nextTokPtr) \
   case BT_LEAD ## n: \
     if (end - ptr < n) \
       return XML_TOK_PARTIAL_CHAR; \
     if (!IS_NAME_CHAR(enc, ptr, n)) { \
       *nextTokPtr = ptr; \
       return XML_TOK_INVALID; \
     } \
     ptr += n; \
     break;

#define CHECK_NAME_CASES(enc, ptr, end, nextTokPtr) \
  case BT_NONASCII: \
    if (!IS_NAME_CHAR_MINBPC(enc, ptr)) { \
      *nextTokPtr = ptr; \
      return XML_TOK_INVALID; \
    } \
  case BT_NMSTRT: \
  case BT_HEX: \
  case BT_DIGIT: \
  case BT_NAME: \
  case BT_MINUS: \
    ptr += MINBPC(enc); \
    break; \
  CHECK_NAME_CASE(2, enc, ptr, end, nextTokPtr) \
  CHECK_NAME_CASE(3, enc, ptr, end, nextTokPtr) \
  CHECK_NAME_CASE(4, enc, ptr, end, nextTokPtr)

#define CHECK_NMSTRT_CASE(n, enc, ptr, end, nextTokPtr) \
   case BT_LEAD ## n: \
     if (end - ptr < n) \
       return XML_TOK_PARTIAL_CHAR; \
     if (!IS_NMSTRT_CHAR(enc, ptr, n)) { \
       *nextTokPtr = ptr; \
       return XML_TOK_INVALID; \
     } \
     ptr += n; \
     break;

#define CHECK_NMSTRT_CASES(enc, ptr, end, nextTokPtr) \
  case BT_NONASCII: \
    if (!IS_NMSTRT_CHAR_MINBPC(enc, ptr)) { \
      *nextTokPtr = ptr; \
      return XML_TOK_INVALID; \
    } \
  case BT_NMSTRT: \
  case BT_HEX: \
    ptr += MINBPC(enc); \
    break; \
  CHECK_NMSTRT_CASE(2, enc, ptr, end, nextTokPtr) \
  CHECK_NMSTRT_CASE(3, enc, ptr, end, nextTokPtr) \
  CHECK_NMSTRT_CASE(4, enc, ptr, end, nextTokPtr)

#ifndef PREFIX
#define PREFIX(ident) ident
#endif

static int PTRCALL
PREFIX(scanComment)(const ENCODING *enc, const char *ptr,
                    const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanDecl)(const ENCODING *enc, const char *ptr,
                 const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(checkPiTarget)(const ENCODING *enc, const char *ptr,
                      const char *end, int *tokPtr)

{
  int upper = 0;
  *tokPtr = XML_TOK_PI;
  if (end - ptr != MINBPC(enc)*3)
    return 1;
  switch (BYTE_TO_ASCII(enc, ptr)) {
  case ASCII_x:
    break;
  case ASCII_X:
    upper = 1;
    break;
  default:
    return 1;
  }
  ptr += MINBPC(enc);
  switch (BYTE_TO_ASCII(enc, ptr)) {
  case ASCII_m:
    break;
  case ASCII_M:
    upper = 1;
    break;
  default:
    return 1;
  }
  ptr += MINBPC(enc);
  switch (BYTE_TO_ASCII(enc, ptr)) {
  case ASCII_l:
    break;
  case ASCII_L:
    upper = 1;
    break;
  default:
    return 1;
  }
  if (upper)
    return 0;
  *tokPtr = XML_TOK_XML_DECL;
  return 1;
}

static int PTRCALL
PREFIX(scanPi)(const ENCODING *enc, const char *ptr,
               const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanCdataSection)(const ENCODING *enc, const char *ptr,
                         const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(cdataSectionTok)(const ENCODING *enc, const char *ptr,
                        const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanEndTag)(const ENCODING *enc, const char *ptr,
                   const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanHexCharRef)(const ENCODING *enc, const char *ptr,
                       const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanCharRef)(const ENCODING *enc, const char *ptr,
                    const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(scanRef)(const ENCODING *enc, const char *ptr, const char *end,
                const char **nextTokPtr);

static int PTRCALL
PREFIX(scanAtts)(const ENCODING *enc, const char *ptr, const char *end,
                 const char **nextTokPtr);

static int PTRCALL
PREFIX(scanLt)(const ENCODING *enc, const char *ptr, const char *end,
               const char **nextTokPtr);

static int PTRCALL
PREFIX(contentTok)(const ENCODING *enc, const char *ptr, const char *end,
                   const char **nextTokPtr);

static int PTRCALL
PREFIX(scanPercent)(const ENCODING *enc, const char *ptr, const char *end,
                    const char **nextTokPtr);

static int PTRCALL
PREFIX(scanPoundName)(const ENCODING *enc, const char *ptr, const char *end,
                      const char **nextTokPtr);

static int PTRCALL
PREFIX(scanLit)(int open, const ENCODING *enc,
                const char *ptr, const char *end,
                const char **nextTokPtr);

static int PTRCALL
PREFIX(prologTok)(const ENCODING *enc, const char *ptr, const char *end,
                  const char **nextTokPtr);

static int PTRCALL
PREFIX(attributeValueTok)(const ENCODING *enc, const char *ptr,
                          const char *end, const char **nextTokPtr);

static int PTRCALL
PREFIX(entityValueTok)(const ENCODING *enc, const char *ptr,
                       const char *end, const char **nextTokPtr);

#ifdef XML_DTD

static int PTRCALL
PREFIX(ignoreSectionTok)(const ENCODING *enc, const char *ptr,
                         const char *end, const char **nextTokPtr);

#endif 

static int PTRCALL
PREFIX(isPublicId)(const ENCODING *enc, const char *ptr, const char *end,
                   const char **badPtr);

static int PTRCALL
PREFIX(getAtts)(const ENCODING *enc, const char *ptr,
                int attsMax, ATTRIBUTE *atts);

static int PTRFASTCALL
PREFIX(charRefNumber)(const ENCODING *enc, const char *ptr);

static int PTRCALL
PREFIX(predefinedEntityName)(const ENCODING *enc, const char *ptr,
                             const char *end);

static int PTRCALL
PREFIX(sameName)(const ENCODING *enc, const char *ptr1, const char *ptr2);

static int PTRCALL
PREFIX(nameMatchesAscii)(const ENCODING *enc, const char *ptr1,
                         const char *end1, const char *ptr2);

static int PTRFASTCALL
PREFIX(nameLength)(const ENCODING *enc, const char *ptr);

static const char * PTRFASTCALL
PREFIX(skipS)(const ENCODING *enc, const char *ptr);

static void PTRCALL
PREFIX(updatePosition)(const ENCODING *enc,
                       const char *ptr,
                       const char *end,
                       POSITION *pos);

#undef DO_LEAD_CASE
#undef MULTIBYTE_CASES
#undef INVALID_CASES
#undef CHECK_NAME_CASE
#undef CHECK_NAME_CASES
#undef CHECK_NMSTRT_CASE
#undef CHECK_NMSTRT_CASES

#undef MINBPC
#undef BYTE_TYPE
#undef BYTE_TO_ASCII
#undef CHAR_MATCHES
#undef IS_NAME_CHAR
#undef IS_NAME_CHAR_MINBPC
#undef IS_NMSTRT_CHAR
#undef IS_NMSTRT_CHAR_MINBPC
#undef IS_INVALID_CHAR

#endif 

#ifdef XML_NS

extern const struct normal_encoding big2_encoding_ns;

#endif

extern const struct normal_encoding big2_encoding;

#if BYTEORDER != 1234

#ifdef XML_NS

extern const struct normal_encoding internal_big2_encoding_ns;

#endif

extern const struct normal_encoding internal_big2_encoding;

#endif

#undef PREFIX

static int FASTCALL
streqci(const char *s1, const char *s2);

static void PTRCALL
initUpdatePosition(const ENCODING *enc, const char *ptr,
                   const char *end, POSITION *pos);

static int
toAscii(const ENCODING *enc, const char *ptr, const char *end);

static int FASTCALL
isSpace(int c);

static int
parsePseudoAttribute(const ENCODING *enc,
                     const char *ptr,
                     const char *end,
                     const char **namePtr,
                     const char **nameEndPtr,
                     const char **valPtr,
                     const char **nextTokPtr);

extern const char KW_version[7];

extern const char KW_encoding[8];

extern const char KW_standalone[10];

extern const char KW_yes[3];

extern const char KW_no[2];

static int
doParseXmlDecl(const ENCODING *(*encodingFinder)(const ENCODING *,
                                                 const char *,
                                                 const char *),
               int isGeneralTextEntity,
               const ENCODING *enc,
               const char *ptr,
               const char *end,
               const char **badPtr,
               const char **versionPtr,
               const char **versionEndPtr,
               const char **encodingName,
               const ENCODING **encoding,
               int *standalone);

static int FASTCALL
checkCharRefNumber(int result);

int FASTCALL
XmlUtf8Encode(int c, char *buf);

int FASTCALL
XmlUtf16Encode(int charNum, unsigned short *buf);

struct unknown_encoding {
  struct normal_encoding normal;
  int (*convert)(void *userData, const char *p);
  void *userData;
  unsigned short utf16[256];
  char utf8[256][4];
};

#define AS_UNKNOWN_ENCODING(enc)  ((const struct unknown_encoding *) (enc))

int
XmlSizeOfUnknownEncoding(void);

static int PTRFASTCALL
unknown_isName(const ENCODING *enc, const char *p);

static int PTRFASTCALL
unknown_isNmstrt(const ENCODING *enc, const char *p);

static int PTRFASTCALL
unknown_isInvalid(const ENCODING *enc, const char *p);

static void PTRCALL
unknown_toUtf8(const ENCODING *enc,
               const char **fromP, const char *fromLim,
               char **toP, const char *toLim);

static void PTRCALL
unknown_toUtf16(const ENCODING *enc,
                const char **fromP, const char *fromLim,
                unsigned short **toP, const unsigned short *toLim);

ENCODING *
XmlInitUnknownEncoding(void *mem,
                       int *table,
                       CONVERTER convert, 
                       void *userData);

enum {
  UNKNOWN_ENC = -1,
  ISO_8859_1_ENC = 0,
  US_ASCII_ENC,
  UTF_8_ENC,
  UTF_16_ENC,
  UTF_16BE_ENC,
  UTF_16LE_ENC,
  
  NO_ENC
};

extern const char KW_ISO_8859_1[10];
extern const char KW_US_ASCII[8];
extern const char KW_UTF_8[5];
extern const char KW_UTF_16[6];
extern const char KW_UTF_16BE[8];
extern const char KW_UTF_16LE[8];

static int FASTCALL
getEncodingIndex(const char *name);

#define INIT_ENC_INDEX(enc) ((int)(enc)->initEnc.isUtf16)
#define SET_INIT_ENC_INDEX(enc, i) ((enc)->initEnc.isUtf16 = (char)i)

static int
initScan(const ENCODING **encodingTable,
         const INIT_ENCODING *enc,
         int state,
         const char *ptr,
         const char *end,
         const char **nextTokPtr);

#define NS(x) x
#define ns(x) x
const ENCODING *
NS(XmlGetUtf8InternalEncoding)(void);

const ENCODING *
NS(XmlGetUtf16InternalEncoding)(void);

extern const ENCODING *NS(encodings)[7];

static int PTRCALL
NS(initScanProlog)(const ENCODING *enc, const char *ptr, const char *end,
                   const char **nextTokPtr);

static int PTRCALL
NS(initScanContent)(const ENCODING *enc, const char *ptr, const char *end,
                    const char **nextTokPtr);

int
NS(XmlInitEncoding)(INIT_ENCODING *p, const ENCODING **encPtr,
                    const char *name);

static const ENCODING *
NS(findEncoding)(const ENCODING *enc, const char *ptr, const char *end);

int
NS(XmlParseXmlDecl)(int isGeneralTextEntity,
                    const ENCODING *enc,
                    const char *ptr,
                    const char *end,
                    const char **badPtr,
                    const char **versionPtr,
                    const char **versionEndPtr,
                    const char **encodingName,
                    const ENCODING **encoding,
                    int *standalone);

#undef NS
#undef ns

#ifdef XML_NS

#define NS(x) x ## NS
#define ns(x) x ## _ns

const ENCODING *
NS(XmlGetUtf8InternalEncoding)(void);

const ENCODING *
NS(XmlGetUtf16InternalEncoding)(void);

extern const ENCODING *NS(encodings)[7];

static int PTRCALL
NS(initScanProlog)(const ENCODING *enc, const char *ptr, const char *end,
                   const char **nextTokPtr);

static int PTRCALL
NS(initScanContent)(const ENCODING *enc, const char *ptr, const char *end,
                    const char **nextTokPtr);

int
NS(XmlInitEncoding)(INIT_ENCODING *p, const ENCODING **encPtr,
                    const char *name);

static const ENCODING *
NS(findEncoding)(const ENCODING *enc, const char *ptr, const char *end);

int
NS(XmlParseXmlDecl)(int isGeneralTextEntity,
                    const ENCODING *enc,
                    const char *ptr,
                    const char *end,
                    const char **badPtr,
                    const char **versionPtr,
                    const char **versionEndPtr,
                    const char **encodingName,
                    const ENCODING **encoding,
                    int *standalone);

#undef NS
#undef ns

ENCODING *
XmlInitUnknownEncodingNS(void *mem,
                         int *table,
                         CONVERTER convert, 
                         void *userData);

#endif 

