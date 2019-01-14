/*
 ***************************************************************************
 * This software/firmware and related documentation ("MediaTek Software") 
 * are protected under relevant copyright laws. The information contained 
 * herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek Inc. and/or its licensors, 
 * any reproduction, modification, use or disclosure of MediaTek Software, and 
 * information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C)2014. All rights reserved.
 ***************************************************************************
 */
#ifndef _SPECIAL_DEFINED_H_
#define _SPECIAL_DEFINED_H_

typedef int INT;
typedef char CHAR, TCHAR;
typedef unsigned int UINT;
typedef unsigned long ULONG;
typedef unsigned char UCHAR;
typedef unsigned short USHORT;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef long LONG;
typedef SInt64 LONGLONG;
typedef UInt64 ULONGLONG;
typedef void * PVOID;
typedef ULONG * PULONG;
typedef CHAR * PCHAR;
typedef UCHAR * PUCHAR;
typedef CHAR * LPTSTR;
typedef double *PLONGLONG;
typedef unsigned short *PWORD;
typedef long *PLONG;
typedef unsigned char BYTE;

typedef union _LARGE_INTEGER
{
	struct{
		DWORD LowPart;
		LONG HighPart;
	};
	struct{
		DWORD LowPart;
		LONG HighPart;
	} u;
	LONGLONG QuadPart;
} LARGE_INTEGER;

#define SWAP16(x) \
	((WORD)( \
	(((WORD)(x) & (WORD) 0x00ffU) << 8) | \
	(((WORD)(x) & (WORD) 0xff00U) >> 8) ))

#define SWAP32(x) \
    ((UINT)( \
    (((UINT)(x) & (UINT) 0x000000ffUL) << 24) | \
    (((UINT)(x) & (UINT) 0x0000ff00UL) <<  8) | \
    (((UINT)(x) & (UINT) 0x00ff0000UL) >>  8) | \
    (((UINT)(x) & (UINT) 0xff000000UL) >> 24) ))

#endif _SPECIAL_DEFINED_H_