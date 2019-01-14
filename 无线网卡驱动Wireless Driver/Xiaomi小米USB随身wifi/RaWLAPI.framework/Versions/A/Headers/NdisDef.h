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

 *  NdisDef.h
 *  RaConfig2500
 *
*/

#ifndef _NDIS_DEF_H_
#define _NDIS_DEF_H_

#define OID_GEN_MEDIA_CONNECT_STATUS					0x00010114

typedef enum _NDIS_MEDIA_STATE{
	NdisMediaStateConnected,
	NdisMediaStateDisconnected
} NDIS_MEDIA_STATE, *PNDIS_MEDIA_STATE;


// 802.3 Objects (Ethernet)
#define OID_802_3_CURRENT_ADDRESS						0x01010102

//Required statistics
#define OID_GEN_RCV_OK									0x00020102
#define OID_GEN_RCV_NO_BUFFER							0x00020105

#endif _NDIS_DEF_H_

