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
//  ScanFuncs.h
//  RaWLAPI
//


#import <Cocoa/Cocoa.h>
#import "StructDef.h"
#import "ConfigFuncs.h"

@interface ScanFuncs : NSObject
{
	SEL				FuncCallBack;
	IMP				Method;
	id				ObjectId;
	BOOL		bScanTimerRunning;
}

- (BOOL)SiteSurveyScan:(id)objId CallBackFunc:(SEL)callBackFunc;
- (void)OnScanTimer:(NSTimer *)timer;
- (LONG)SiteSurveyGet:(PNDIS_802_11_BSSID_LIST_EX)pBssidList ListSize:(ULONG *)pListSize;
@end
