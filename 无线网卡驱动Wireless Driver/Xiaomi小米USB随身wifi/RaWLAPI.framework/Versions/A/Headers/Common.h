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
//  Common.h
//  RaWLAPI
//
#import "SpecialDef.h"
#import "StructDef.h"

ULONG DeviceDriverType();

ULONG FrequencyToChannel(ULONG nFreq);
ULONG ChannelToFrequency(ULONG nChannel);
UINT RssiToPercent(int nRssi);
UINT ConvertRssiToSignalQuality(NDIS_802_11_RSSI RSSI);
BOOL IsDeviceExist();
void GetSNR(ULONG *SNR0, ULONG *SNR1);

// Link Status
BOOL GetLinkStatus(RT_802_11_LINK_STATUS *LinkStatus);
ULONG GetLastTxRate(RT_802_11_LINK_STATUS *LinkStatus, ULONG *lHTSetting);
ULONG GetLastTxRateforLegacy(RT_802_11_LINK_STATUS *LinkStatus);
ULONG GetLastTxRxRatefor11n(ULONG nID, ULONG *lHTSetting);
BOOL GetHTTxRateByBW_GI_MCS(int nBW, int nGI, int nMCS, double *dRate);
BOOL GetVHTTxRateByBW_GI_MCS(int nBW, int nNSS, int nGI, int nMCS, double *dRate);
ULONG GetTxThroughput(BOOL bFirstTime, RT_802_11_LINK_STATUS *LinkStatus);
ULONG GetRxThroughput(BOOL bFirstTime, RT_802_11_LINK_STATUS *LinkStatus);
void GetNoiseLevel(NDIS_802_11_RSSI RSSI, NDIS_802_11_RSSI RSSI2, NDIS_802_11_RSSI RSSI3, ULONG SNR0, ULONG SNR1, int *nNoisePercent, int *nNoiseDbm, ULONG lLastTxHTSetting, double dLastRxRate);
void GetHTStatus(HTTRANSMIT_SETTING *HTSetting, int nTxOrRx);
ULONG GetTxPower();
ULONG GetLastRxRate();
ULONG GetLastRxRateforLegacy(int nID);
DWORD QueryHWArchitectureVer(PHW_ARCHITECTURE_VERSION pHwArchitecVer);

//DBG Info
void SetDbgLevel(ULONG dbg);

// Set Profile
DWORD SetWLANProfile(PWLANPROFILE pWLANProfile);
BOOL SetOIDForConnect(PWLANPROFILE pWLANProfile);
DWORD SetSOFTAPProfile(PSOFTAPPROFILE pSOFTAPProfile);
int ConvertExtChannel(int nBW, int nSelChannel);
BOOL SetOIDForSOFTAP(PSOFTAPPROFILE pSOFTAPProfile);
void SetTxRatesForConnect(RT_802_11_PHY_MODE enumWirelessMode, int MCS);
BOOL KeyToWepData(PNDIS_802_11_KEY pWepData, TCHAR *pWepKey, ULONG wepKeyType, int nKeyIdx, int wepDefaultKey);
int HexStrToHexValue(TCHAR *hexStr, BYTE *hexValue);
int	PasswordHash(char* password, unsigned char* ssid, int ssidlength, unsigned char* output);
void hmac_sha1(unsigned char *text, int text_len, unsigned char *key, int key_len, unsigned char *digest);
void F(char* password, unsigned char * ssid, int ssidlength, int iterations, int count, unsigned char* output);
void AtoH(char* src, UCHAR* dest, int destlen);
UCHAR BtoH(char ch);

// About Info
BOOL GetMacAddrs(NDIS_802_11_MAC_ADDRESS *MacAddrs);

// Other
void GetCompensativeWirelessMode(RT_802_11_PHY_MODE *RTPhyMode);
BOOL Is80211aSupport();
BOOL Is80211nSupport();

// Advance
void AdvanceSetOID(ADVANCE_OID AdvOID);
BOOL ConvertPhyModeToAdHocMode(RT_802_11_PHY_MODE phyMode, RT_802_11_ADHOC_MODE *adhocMode);
BOOL SetRadio(BOOL bRadio);
void Disassociate();
BOOL QueryNetworkTypeSupport(PNDIS_802_11_NETWORK_TYPE_LIST pNetworkTypelist);

// WPS
void GetWPSWlanProfile(PWLANPROFILE pProfileData, WPS_CREDENTIAL wpsProfile);
DWORD WPSDisconnect();

// Other
void GetChannelListByNetworkPhyModeAdhocMode(int nNetworkType, RT_802_11_PHY_MODE WirelessMode, int iAdHocMode, UCHAR *aryChan, int *nIndex, BOOL bBeaconChannelOnly);
UINT GetOSVersion();
BOOL SetIPAddressManual(NSString *IPAddress, NSString *Router, NSString *SubnetMask, NSString *InterfaceName);
BOOL SetIPAddressDHCP(NSString *InterfaceName);
int PassDataToDaemon(PUCHAR data, int dataLength);
int PassDataToCommandServer(PUCHAR data, int dataLength);
NSString *GetUIPathName();
BOOL CheckFileExist(NSString *strFileName);
BOOL CheckScutumFileExist();
void GetActivedPrimaryInterfaces( NSString *strWithoutDeivceName, NSMutableArray *Interfaces );
BOOL GetIsNatEnabled();
BOOL SetNatInfo(NSString *strSharingDeviceName, NSString *strPrimaryDeviceName, NSString *strPrimaryUserDefinedName, NSString *strPrimaryServiceKey, NSString *strDNSIP, BOOL bEnabledInternetSharing);
													  
// Scan AP Info
BOOL ParseInfoElement(PNDIS_WLAN_BSSID_EX pBssid, PIE_INFO pIE_DetailInfo);
static char * get_iface_address (char *interface);