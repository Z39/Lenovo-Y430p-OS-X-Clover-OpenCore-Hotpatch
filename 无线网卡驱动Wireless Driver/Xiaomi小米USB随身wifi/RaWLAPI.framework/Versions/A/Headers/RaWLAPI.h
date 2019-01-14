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
//  RaWLAPI.h
//  RAWLAPI
//

#import <Cocoa/Cocoa.h>
#import "SpecialDef.h"
#import "StructDef.h"
#import "ScanFuncs.h"
#import "ConfigFuncs.h"
#import "KeyChainTransfer.h"

@interface RaWLAPI : NSObject
{
	BOOL bInitialed;
	ScanFuncs *ScanFunctions;
	ConfigFuncs *ConfigFunctions;
}

- (ULONG)RAWL_DeviceDriverType;
- (ULONG)RAWL_ChannelToFrequency:(ULONG)nChannel;
- (DWORD)RAWL_CheckDuplicatedProfileName:(NSString *)strProfileName;
- (DWORD)RAWL_ConnectWPSProfile:(WPS_CREDENTIAL)wpsProfile;
- (DWORD)RAWL_GetWPSWlanProfile:(PWLANPROFILE)pProfileData WpsProfile:(WPS_CREDENTIAL)wpsProfile;
- (BOOL)RAWL_ConvertPhyModeToAdHocMode:(RT_802_11_PHY_MODE)phyMode AdhocMode:(RT_802_11_ADHOC_MODE *)adhocMode;
- (DWORD)RAWL_DeleteProfile:(NSString *)strProfileName;
- (void)RAWL_DeleteActiveProfile;
- (void)RAWL_Disassociate;
- (ULONG)RAWL_FrequencyToChannel:(ULONG)nFreq;
- (void)RAWL_GetAvailableChannels:(int)nNetworkType WirelessMode:(RT_802_11_PHY_MODE)enumWirelessMode AdhocMode:(int)iAdHocMode AryChannel:(UCHAR *)aryChan Index:(int *)nIndex BeaconChannelOnly:(BOOL)bBeaconChannelOnly;
- (void)RAWL_GetCountryChannels:(int)n24Gor5G CountryRegion:(int)nCountryRegion AryChannel:(UCHAR *)aryChan  Count:(int *)nCount;
- (BOOL)RAWL_Is80211ASupport;
- (BOOL)RAWL_Is80211NSupport;
- (BOOL)RAWL_IsDeviceExist;
- (BOOL)RAWL_OIDQueryInfo:(ULONG)Oid InfoBuffer:(PVOID)pInfoBuffer InfoBufferLen:(UINT)nInfoBufferLen BytesReturn:(PVOID)pBytesReturn;
- (BOOL)RAWL_OIDSetInfo:(ULONG)Oid InfoBuffer:(PVOID)pInfoBuffer InfoBufferLen:(UINT)nInfoBufferLen;
- (BOOL)RAWL_ParseInfoElement:(PNDIS_WLAN_BSSID_EX)pBssid IeInfo:(PIE_INFO)pIeInfo;
- (int)RAWL_PasswordHash:(char *)password Ssid:(UCHAR *)ssid SsidLength:(int)ssidlength Output:(UCHAR *)output;
- (BOOL)RAWL_QueryCountryRegion:(ULONG *)lCountryRegion Set11A:(BOOL *)bSet11A Set11BG:(BOOL *)bSet11BG;
- (BOOL)RAWL_QueryCurrAddress:(UCHAR *)chCurAddress;
- (BOOL)RAWL_QueryEEPROMVersion:(UCHAR *)chEEPROMVer;
- (BOOL)RAWL_QueryFWVersion:(UCHAR *)chFirmwareVer;
- (BOOL)RAWL_QueryHTPhyMode:(POID_SET_HT_PHYMODE)pOIDHtPhyMode;
- (LONG)RAWL_QueryMacAddrs:(NDIS_802_11_MAC_ADDRESS *)MacAddrs;
- (BOOL)RAWL_QueryNetworkTypeSupport:(PNDIS_802_11_NETWORK_TYPE_LIST)pNetworkTypelist;
- (BOOL)RAWL_QuerySTAConfig:(PRT_802_11_STA_CONFIG)pRTSTAConfig;
- (BOOL)RAWL_QueryWirelessMode:(RT_802_11_PHY_MODE *)enumWirelessMode;
- (BOOL)RAWL_QueryWLANStatus:(WLANStatus)WLANStatus;
- (BOOL)RAWL_QueryWPSAPChannel:(ULONG *)lWpsChannel;
- (BOOL)RAWL_QueryWPSHwPbc:(ULONG *)lHwPbc;
- (BOOL)RAWL_QueryWPSProfile:(PWPS_PROFILE)pProfileWPS;
- (BOOL)RAWL_QueryWPSStatus:(ULONG *)wpsStatus;
- (DWORD)RAWL_ReadAdvanceCfgData:(ADVANCE_OID *)AdvCfgData;
- (BOOL)RAWL_ReadProfileData:(PWLANPROFILE)pProfileData ProfileName:(NSString *)strProfileName;
- (NSString *)RAWL_ReadActiveProfileData:(PWLANPROFILE)pProfileData;
- (UINT)RAWL_GetProfileCount;
- (NSString *)RAWL_GetNextProfileName;
- (DWORD)RAWL_ReadProfileList:(WLANPROFILE *)ProfileList;
- (DWORD)RAWL_ReadWPSFlag:(BOOL *)bWps;
- (DWORD)RAWL_ReadWPSProfile:(WPS_MODE *)wpsMode WpsProfileList:(WPS_PROFILE *)wpsProfileList;
- (BOOL)RAWL_ResetCounter;
- (UINT)RAWL_RssiToPercent:(int)nRssi;
- (void)RAWL_SetAdvanceSetting:(ADVANCE_OID)AdvOID;
- (BOOL)RAWL_SetAndWriteRadioState:(BOOL)bRadio;
- (BOOL)RAWL_SetAuthMode:(NDIS_802_11_AUTHENTICATION_MODE)enumAuthenMode;
- (BOOL)RAWL_SetBSSID:(NDIS_802_11_MAC_ADDRESS)BSSID;
- (BOOL)RAWL_SetCountryRegion:(ULONG)ulCountryRegion;
- (BOOL)RAWL_SetDesiredRate:(NDIS_802_11_RATES)aryRates;
- (BOOL)RAWL_SetHTPhyMode:(OID_SET_HT_PHYMODE)phyMode;
- (BOOL)RAWL_SetPhyMode:(RT_802_11_PHY_MODE)phyMode;
- (void)RAWL_SetSSID:(NDIS_802_11_SSID)ssid;
- (BOOL)RAWL_SetSTAConfig:(RT_802_11_STA_CONFIG)configSta;
- (BOOL)RAWL_SetTXRate:(RT_802_11_TX_RATES)arySupDesRates;
- (DWORD)RAWL_SetWLANProfile:(PWLANPROFILE)pWLANProfile;
- (DWORD)RAWL_SetSOFTAPProfile:(PSOFTAPPROFILE)pSOFTAPProfile;
- (BOOL)RAWL_SetWPSAssociateIE:(BOOL)bAssociateIE;
- (BOOL)RAWL_SetWPSAutoSelect:(ULONG)lAutoSelect;
- (BOOL)RAWL_SetWPSMode:(WPS_MODE)modeWPS;
- (BOOL)RAWL_SetWPSProbeReqIE:(BOOL)bProbeIE;
- (BOOL)RAWL_SetWPSProfile:(WPS_PROFILE)profileWps;
- (LONG)RAWL_SiteSurveyQuery:(PNDIS_802_11_BSSID_LIST_EX)pBssidList ListSize:(ULONG *)pListSize;
- (LONG)RAWL_SiteSurveyScan:(id)objId  CallBackFunc:(SEL)callBackFunc;
- (DWORD)RAWL_WPSDisconnect;
- (BOOL)RAWL_WriteAdvanceCfgData:(ADVANCE_OID)AdvOID;
- (DWORD)RAWL_WriteProfileData:(NSString *)strProfileName ProfileData:(PWLANPROFILE)pProfileData;
- (BOOL)RAWL_ReadSoftApProfileData:(PSOFTAPPROFILE)pProfileData;
- (DWORD)RAWL_WriteSoftApProfileData:(PSOFTAPPROFILE)pProfileData;
- (DWORD)RAWL_WriteActiveProfileData:(NSString *)strProfileName ProfileData:(PWLANPROFILE)pProfileData;
- (DWORD)RAWL_WriteWPSFlag:(BOOL)bWps;
- (DWORD)RAWL_WriteWPSProfile:(WPS_MODE)wpsMode WpsProfileList:(WPS_PROFILE)wpsProfileList;
- (UINT)RAWL_GetOSVersion;
- (BOOL)RaWL_CheckScutumSupport;
- (NSString *)RAWL_GetInterfaceName;
- (BOOL)RAWL_SetIPAddressManual:(NSString *)strIPAddress Router:(NSString *)strRouter SubnetMask:(NSString *)strSubnetMask;
- (BOOL)RAWL_SetIPAddressDHCP;
- (void)RAWL_GetCertificationName:(NSString *[])strCertName CertsNum:(unsigned *)certsNum;
- (void)RAWL_GetPrivateKeyName:(NSString *[])strKeyName KeysNum:(unsigned *)keysNum;
- (void)RAWL_GetActivedPrimaryInterfaces:(NSString *)strWithoutDeivceName Interfaces:(NSMutableArray *)arrayInterfaces;
- (BOOL)RAWL_GetIsNatEnabled;
- (BOOL)RAWL_SetNatInfo:(NSString *)strSharingDeviceName PrimaryDeviceName:(NSString *)strPrimaryDeviceName PrimaryUserDefinedName:(NSString *)strPrimaryUserDefinedName PrimaryServiceKey:(NSString *)strPrimaryServiceKey DNSIP:(NSString *)strDNSIP EnabledInternetSharing:(BOOL)bEnabledInternetSharing;
- (void)RAWL_SwitchOpMode:(ULONG)opMode;
- (int)RAWL_QueryOpMode;
- (void)RAWL_ReadOpMode:(ULONG *)bOpMode;
- (void)RAWL_WriteOpMode:(BOOL)bOpMode;
- (NSString *)RAWL_ReadInternetSharingInterfaceName;
- (void)RAWL_WriteInternetSharingInterfaceName:(NSString *)strName;
- (void)RAWL_PassDataToCommandServer:(NSString *)command;
- (RAWLAN_STATUS)RAWL_QueryConnectStatus;
- (int)RAWL_QueryWPAPortSecured;
- (void)RAWL_DBG:(ULONG)Dbginfo;
- (BOOL)RAWL_IsNewDevice;
- (BOOL)RAWL_QueryIEEE80211H;
- (BOOL)RAWL_SetIEEE80211H:(BOOL)bIEEE80211H;
- (BOOL)RAWL_QueryEDCCA;
- (BOOL)RAWL_SetEDCCA:(BOOL)bEDCCA;


@end
