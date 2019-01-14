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
//
//  KeyChainTransfer.h
//  RaConfig2800
//


#import <Cocoa/Cocoa.h>
#include <Security/SecAccess.h>

NSString *GetKeyChainPath();
int KeyChainExport(unsigned char *chCertName, unsigned char *chPrivateKeyName);
void GetCertificationName(NSString *strName[], unsigned *numCerts);
void GetPrivateKeyName(NSString *strName[], unsigned *numKeys);
