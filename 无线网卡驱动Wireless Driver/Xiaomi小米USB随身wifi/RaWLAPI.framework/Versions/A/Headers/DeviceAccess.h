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
//  Device.h
//  RaWLAPI
//


#import <Cocoa/Cocoa.h>
#import <IOKit/IOTypes.h>
#import "StructDef.h"

#define kServiceClassName_60	"CardBusWirelessDriver"
#define kServiceClassName_61	"RT61CardBusDriver"
#define kServiceClassName_2860	"RT2860WirelessDriver"

#define kServiceClassName_73	"RT2573USBWirelessDriver"
#define kServiceClassName_70	"RT2500USBWirelessDriver"
#define kServiceClassName_2870	"RT2870USBWirelessDriver"

DEVICE_DRIVER_TYPE SearchDevice();
BOOL OpenConnectToDevice();
void CloseConnectToDevice();
BOOL OidQueryInformation(ULONG OidQueryCode,  PVOID InformationBuffer, UINT InformationBufferLength, PULONG pBytesReturn);
BOOL OidSetInformation(ULONG OidSetCode, PVOID InformationBuffer, UINT InformationBufferLength, PULONG pBytesReturn);
BOOL GetWLANStatus(WLANSTATUS *pWLANStatus);