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


#if !defined(_STRUCTDEF_H_)
#include "Oid.h"
#define _STRUCTDEF_H_

//ERROR values
#define RAWL_ERROR_SUCCESS						( 1) // on success
#define RAWL_ERROR_FAILURE						( 0) // on failure
#define RAWL_ERROR_PARAM							(-1)
#define RAWL_ERROR_NOT_CALL_INIT					(-2)
#define RAWL_ERROR_NOT_CALL_DETECT					(-3)
#define RAWL_ERROR_REG_OPEN_KEY						(-4)
#define RAWL_ERROR_REG_GET_VALUE					(-5)
#define RAWL_ERROR_REG_WRITE_VALUE					(-6)
#define RAWL_ERROR_INVALID_HANDLE					(-7)
#define RAWL_ERROR_FILE_NOT_FOUND					(-8)
#define RAWL_ERROR_DEVICE_NOT_FOUND					(-9)
#define RAWL_ERROR_OVERFLOW							(-10)
#define RAWL_ERROR_ADAPTER_NOT_SUPPORTED			(-11) // don't support the adapter because it's not ralink's adapter
#define RAWL_ERROR_NOT_INITIALIZED					(-12) // the feature of Scutum supplicant is not initialized
#define RAWL_ERROR_ALREADY_INITIALIZED				(-13) // the feature of Scutum supplicant is already initialized
#define RAWL_ERROR_MORE_THAN_ONE_PROFILE_IN_FILE	(-14) // there are more than one profile in the imported file
#define RAWL_ERROR_NO_PROFILE_IN_FILE				(-15) // there is no profile in the imported file
#define RAWL_ERROR_DUPLICATE_PROFILE				(-16) // the same name profile exists
#define RAWL_ERROR_WAPI_NOT_SUPPORTED				(-17) // don't support wapi feature for the adapter
#define RAWL_ERROR_UNKNOWN				(-99)



#define MYWM_NOTIFYICON		(WM_USER+100)

#define SITE_STATUS_CONNECTED		0
//#define SITE_STATUS_DISCONNECTED	1

#define PROFILE_STATUS_DEF_ACTIVE	0
#define PROFILE_STATUS_DEF_INACTIVE	1
#define PROFILE_STATUS_DEF_NOACT    -1

// --------------- OUI definition --------------------//
#ifdef __BIG_ENDIAN__

#define WPA_OUI_TYPE				0x0050F201
#define WPA_OUI_TYPE_WPS			0x0050F204
#define WPA_OUI_TYPE_1				0x0050F202
#define WPA_OUI						0x0050F200
#define WPA_OUI_98					0x00004200
#define WPA_OUI_1					0x00000300
#define WPA2_OUI					0x000FAC00
#define CISCO_OUI					0x00409600 // CCKM for Cisco, modify by candy 2006.11.04
#define WPA_OUI_80211N_45			0x00904C34 // 802.11n for elementID = 45
#define WPA_OUI_80211N_61			0x00904C34 // 802.11n for elementID = 61
#define BROADCOM_OUI				0x00904C33

#define WAPI_PSK_OUI				0x00147202 // WAPI/PSK (0x00, 0x14, 0x72, 0x02)
#define WAPI_CA_OUI					0x00147201 // WAPI/CA (0x00, 0x14, 0x72, 0x01)
#define WAPI_SMS4_OUI				0x00147201 // WAPI/SMS4 (0x00, 0x14, 0x72, 0x01)

#else

#define WPA_OUI_TYPE				0x01F25000
#define WPA_OUI_TYPE_WPS			0x04F25000
#define WPA_OUI_TYPE_1				0x02F25000
#define WPA_OUI						0x00F25000
#define WPA_OUI_98					0x00420000
#define WPA_OUI_1					0x00030000
#define WPA2_OUI					0x00AC0F00
#define CISCO_OUI					0x00964000 // CCKM for Cisco, modify by candy 2006.11.04
#define WPA_OUI_80211N_45			0x344C9000 // 802.11n for elementID = 45
#define WPA_OUI_80211N_61			0x344C9000 // 802.11n for elementID = 61
#define BROADCOM_OUI				0x334C9000

#define WAPI_PSK_OUI				0x02721400 // WAPI/PSK (0x00, 0x14, 0x72, 0x02)
#define WAPI_CA_OUI					0x01721400 // WAPI/CA (0x00, 0x14, 0x72, 0x01)
#define WAPI_SMS4_OUI				0x01721400 // WAPI/SMS4 (0x00, 0x14, 0x72, 0x01)

#endif
// ---------------------------------------------------//

#define RTS_MAX						2347
#define RTS_SLIDER_MAX				2347
#define RTS_SLIDER_MIN				0
#define RTS_SLIDER_LINE				32
#define RTS_SLIDER_PAGE				256

#define FRAG_MAX					2346
#define FRAG_SLIDER_MAX				2346
#define FRAG_SLIDER_MIN				256
#define FRAG_SLIDER_LINE			32
#define FRAG_SLIDER_PAGE			256

#define REGISTER_TYPE_MAC			0
#define REGISTER_TYPE_BBP			1
#define REGISTER_TYPE_RF			2
#define REGISTER_TYPE_EEPROM		3

#define REGSTR_COUNTRYREGION_FCC		0	// FCC, CH1-11
#define REGSTR_COUNTRYREGION_IC			1	// IC (Canada), CH1-11
#define REGSTR_COUNTRYREGION_ETSI		2	// ETSI, CH1-13
#define REGSTR_COUNTRYREGION_SPAIN		3	// SPAIN, CH10-11
#define REGSTR_COUNTRYREGION_FRANCE		4	// FRANCE, CH10-13
#define REGSTR_COUNTRYREGION_MKK		5	// MKK, CH14
#define REGSTR_COUNTRYREGION_MKK1		6	// MKK1(TELEC), CH1-14
#define REGSTR_COUNTRYREGION_ISRAEL		7	// ISRAEL, CH3-9
#define REGSTR_COUNTRYREGION_ISRAEL_1	8	// ISRAEL, CH5-13


#define REGSTR_COUNTRYREGION_11BG_00	0
#define REGSTR_COUNTRYREGION_11BG_01	1
#define REGSTR_COUNTRYREGION_11BG_02	2
#define REGSTR_COUNTRYREGION_11BG_03	3
#define REGSTR_COUNTRYREGION_11BG_04	4
#define REGSTR_COUNTRYREGION_11BG_05	5
#define REGSTR_COUNTRYREGION_11BG_06	6
#define REGSTR_COUNTRYREGION_11BG_07	7

#define REGSTR_COUNTRYREGION_11A_00		0
#define REGSTR_COUNTRYREGION_11A_01		1
#define REGSTR_COUNTRYREGION_11A_02		2
#define REGSTR_COUNTRYREGION_11A_03		3
#define REGSTR_COUNTRYREGION_11A_04		4
#define REGSTR_COUNTRYREGION_11A_05		5
#define REGSTR_COUNTRYREGION_11A_06		6
#define REGSTR_COUNTRYREGION_11A_07		7
#define REGSTR_COUNTRYREGION_11A_08		8
#define REGSTR_COUNTRYREGION_11A_09		9
#define REGSTR_COUNTRYREGION_11A_10		10
#define REGSTR_COUNTRYREGION_11A_11		11
#define REGSTR_COUNTRYREGION_11A_12		12
#define REGSTR_COUNTRYREGION_11A_13		13
#define REGSTR_COUNTRYREGION_11A_14		14
#define REGSTR_COUNTRYREGION_11A_15		15
#define REGSTR_COUNTRYREGION_11A_16		16
#define REGSTR_COUNTRYREGION_11A_30		30

// value domain for pAd->RfIcType
#define RFIC_5226               1  //A/B/G
#define RFIC_2528               2  //B/G
#define RFIC_5225				3  //A/B/G
#define RFIC_2527				4  //B/G
#define RFIC_2820                   1       // 2.4G 2T3R
#define RFIC_2850                   2       // 2.4G/5G 2T3R
#define RFIC_2720                   3       // 2.4G 1T2R
#define RFIC_2750                   4       // 2.4G/5G 1T2R
#define RFIC_3020                   5       // 2.4G/5G 1T1R
#define RFIC_2020                   6       // 2.4G B/G

#define TIMER_WPS_DLG_RESCAN					1
#define TIMER_WPS_DLG_STATUS					2
#define TIMER_WPS_DLG_CONNECT_STATUS			3
#define TIMER_WPS_DLG_HW_PBC					5
#define TIMER_WPS_DLG_TWO_MINUTES				6
#define TIMER_WPS_NDIS_MEDIA_DISCONNECTED		7
#define TIMER_WPS_DLG_UPPER_BOUND				4

// WPS Opcode
#define	WPS_START			0x01
#define	WPS_ACK				0x02
#define	WPS_NACK			0x03
#define	WPS_MSG				0x04
#define	WPS_DONE			0x05
#define	WPS_FRAG_ACK		0x06

// WPS connection mode
#define	WPS_PIN_MODE		0x10000000
#define	WPS_PBC_MODE		0x20000000

// WPS IE definitions infortant:: big edian
#define	WPS_IE_CONF_MTHD		0x0810
#define	WPS_IE_DEV_NAME			0x1110
#define	WPS_IE_DEV_PASS_ID		0x1210
#define	WPS_IE_EN_NOUNCE		0x1A10
#define	WPS_IE_MANUFACTURER		0x2110
#define	WPS_IE_MODEL_NAME		0x2310
#define	WPS_IE_MODEL_NO			0x2410
#define	WPS_IE_RF_BANDS			0x3C10
#define	WPS_IE_SEL_REG			0x4110
#define	WPS_IE_SERIAL			0x4210
#define	WPS_IE_STATE			0x4410
#define	WPS_IE_SSID				0x4510
#define	WPS_IE_UUIE_E			0x4710
#define	WPS_IE_VERSION			0x4A10
#define	WPS_IE_REG_CFG_MTHD		0x5310
#define	WPS_IE_PRI_DEV_TYPE		0x5410
#define	WPS_IE_AP_SETUP_LOCK	0x5710

// 1. common
#define	STATUS_WPS_NOTUSED						0x0000		// Not used
#define	STATUS_WPS_IDLE							0x0001
#define	STATUS_WPS_SCAN_AP						0x0002		// Scanning AP
#define	STATUS_WPS_START_ASSOC					0x0003		// Begin associating to WPS AP
#define	STATUS_WPS_LINK_UP						0x0004		// Associated to WPS AP
#define	STATUS_WPS_EAPOL_START_SENT				0x0005		// Sending EAPOL-Start
#define	STATUS_WPS_EAP_RSP_ID_SENT				0x0006		// Sending EAP-Rsp(ID)
#define	STATUS_WPS_EAP_RSP_ACK_SENT				0x0007		// Sending EAP-Rsp (ACK)
#define	STATUS_WPS_EAP_RSP_NACK_SENT			0x0008		// Sending EAP-Rsp (NACK)
#define	STATUS_WPS_EAP_REQ_NACK_RECEIVED		0x0009		// Receive EAP-Req (NACK)
#define	STATUS_WPS_EAP_CONFIGURED				0x000F		// Configured
// 2. for enrollee
#define	STATUS_WPS_EAP_REQ_START_RECEIVED		0x0011		// Receive EAP-Req (Start)
#define	STATUS_WPS_EAP_M1_SENT					0x0012		// Sending M1
#define	STATUS_WPS_EAP_M2_RECEIVED				0x0013		// Received M2
#define	STATUS_WPS_EAP_M2D_RECEIVED				0x0014		// Received M2D
#define	STATUS_WPS_EAP_M3_SENT					0x0015		// Sending M3
#define	STATUS_WPS_EAP_M4_RECEIVED				0x0016		// Received M4
#define	STATUS_WPS_EAP_M5_SENT					0x0017		// Sending M5
#define	STATUS_WPS_EAP_M6_RECEIVED				0x0018		// Received M6
#define	STATUS_WPS_EAP_M7_SENT					0x0019		// Sending M7
#define	STATUS_WPS_EAP_M8_RECEIVED				0x001A		// Received M8
#define	STATUS_WPS_EAP_RSP_DONE_SENT			0x001B		// Sending EAP-Rsp (Done)
// 3. for registrar
#define	STATUS_WPS_EAP_M1_RECEIVED				0x0022		// Received M1
#define	STATUS_WPS_EAP_M2_SENT					0x0023		// Sending M2
#define	STATUS_WPS_EAP_M2D_SENT					0x0024		// Sending M2D
#define	STATUS_WPS_EAP_M3_RECEIVED				0x0025		// Received M3
#define	STATUS_WPS_EAP_M4_SENT					0x0026		// Sending M4
#define	STATUS_WPS_EAP_M5_RECEIVED				0x0027		// Received M5
#define	STATUS_WPS_EAP_M6_SENT					0x0028		// Sending M6
#define	STATUS_WPS_EAP_M7_RECEIVED				0x0029		// Received M7
#define	STATUS_WPS_EAP_M8_SENT					0x002A		// Sending M8
#define	STATUS_WPS_EAP_REQ_DONE_RECEIVED		0x002B		// Received EAP-Req (Done)

// All error message dtarting from 0x0100
#define	STATUS_WPS_PBC_TOO_MANY_AP				0x0101		// Too many PBC AP avaliable
#define	STATUS_WPS_PBC_NO_AP					0x0102		// No PBC AP avaliable
#define	STATUS_WPS_EAP_FAIL_RECEIVED			0x0103		// Received EAP-FAIL
#define	STATUS_WPS_EAP_NONCE_MISMATCH			0x0104		// Receive EAP with wrong NONCE
#define	STATUS_WPS_EAP_INVALID_DATA				0x0105		// Receive EAP without integrity (Hmac mismatch)
#define STATUS_WPS_PASSWORD_MISMATCH			0x0106		// Error PIN Code (R-Hash mismatch)


// Error message, UI stop querying
#define	STATUS_WPS_INVALID_SSID					0x0201		// Invalid SSID in PIN mode
#define	STATUS_WPS_EAP_REQ_WRONG_SMI			0x0202		// Receive EAP-Req with wrong WPS SMI Vendor Id
#define	STATUS_WPS_EAP_REQ_WRONG_VENDOR_TYPE	0x0203		// Receive EAPReq with wrong WPS Vendor Type
#define	STATUS_WPS_EAP_FAILED					0x0204		// WPS Eap process failed
#define STATUS_WPS_CONFIG_ERROR					0x0205	


// WPS set mode
typedef	struct _WPS_MODE
{
	ULONG					WpsMode;		// predefined WPS mode, 1: PIN, 2: PBC
	UCHAR					PIN[8];
	NDIS_802_11_SSID		WpsSSID;
	NDIS_802_11_MAC_ADDRESS Bssid;
	UCHAR					Channel;
	UCHAR					ConfigMode;
	UCHAR					Rsv[8]; // in order to meet 64-bits OS
}	WPS_MODE, *PWPS_MODE;

//
// Preferred WPS AP type.
//
// a) PREFERRED_WPS_AP_PHY_TYPE_2DOT4_G_FIRST
//     Select the WPS AP with 2.4G first. Otherwise select the WPS AP with 5G.
// b) PREFERRED_WPS_AP_PHY_TYPE_5_G_FIRST
//     Select the WPS AP with 5G first. Otherwise select the WPS AP with 2.4G.
// c) PREFERRED_WPS_AP_PHY_TYPE_AUTO_SELECTION
//     Automactically select WPS AP.
//
typedef enum _PREFERRED_WPS_AP_PHY_TYPE
{
 PREFERRED_WPS_AP_PHY_TYPE_2DOT4_G_FIRST = 0, 
 PREFERRED_WPS_AP_PHY_TYPE_5_G_FIRST, 
 PREFERRED_WPS_AP_PHY_TYPE_AUTO_SELECTION, 
 PREFERRED_WPS_AP_PHY_TYPE_MAXIMUM, 
} PREFERRED_WPS_AP_PHY_TYPE;

// WPS configured credential
typedef	struct	_WPS_CREDENTIAL
{
	NDIS_802_11_SSID	SSID;				// mandatory
	ULONG				AuthType;			// mandatory, 1: open, 2: wpa-psk, 4: shared, 8:wpa, 0x10: wpa2, 0x20: wpa2-psk
	ULONG				EncrType;			// mandatory, 1: none, 2: wep, 4: tkip, 8: aes
	ULONG				KeyIndex;			// optional, default is 1, but the value is 0
	ULONG				KeyLength;		
	UCHAR				Key[64];			// mandatory, Maximum 64 byte
	UCHAR				MacAddr[6];			// mandatory, AP MAC address
    UCHAR               NetIndex;
    UCHAR               Reserved[5]; // in order to meet 64-bits OS
}	WPS_CREDENTIAL, *PWPS_CREDENTIAL;

// WPS configured profiles
typedef	struct	_WPS_PROFILE
{
	ULONG			ProfileCnt;
	WPS_CREDENTIAL	Profile[8];				// Support up to 8 profiles
    UCHAR           Reserved[60]; // in order to meet 64-bits OS
}	WPS_PROFILE, *PWPS_PROFILE;

typedef struct _PAIR_CHANNEL_FREQ_ENTRY
{
	ULONG	lChannel;	
    ULONG	lFreq;		
} PAIR_CHANNEL_FREQ_ENTRY, *PPAIR_CHANNEL_FREQ_ENTRY;

#define Authen_Unknown				0x00
#define Authen_WPA					0x01
#define Authen_WPAPSK				0x02
#define Authen_WPANONE				0x04
#define Authen_WPA2					0x08
#define Authen_WPA2PSK				0x10
#define Authen_WPA2NONE				0x20
#define Authen_WAPIPSK				0x40
#define Authen_WAPICERT				0x80

#define Encrypt_None				0x00
#define Encrypt_WEP40				0x01
#define Encrypt_TKIP				0x02
#define Encrypt_AES					0x04
#define Encrypt_WEP104				0x05
#define Encrypt_SMS4				0x08

#define WEP_KEY_TYPE_HEX			0
#define WEP_KEY_TYPE_ASCII			1

#define TIMER_CONNECT_STATUS		1
#define TIMER_ACTIVE_PROFILE		2

#define PAGE_COUNT					6
#define REPOSITE_EXPIRE_SECONDS		20

typedef void (*SCANCALLBACK)(id, SEL);

typedef enum _AUTHEN_PROTOCOL
{
	Peap,
	Tls,
	Ttls,
	Leap,
	Md5,
	Fast,
} AUTHEN_PROTOCOL, *PAUTHEN_PROTOCOL;

typedef enum _AC_EAP_METHOD
{
	AC_EAP_MD5                          = 4,
	AC_EAP_GTC                          = 6,
	AC_EAP_TLS                          = 13,
	AC_EAP_LEAP                         = 17,
	AC_EAP_SIM                          = 18,
	AC_EAP_TTLS                         = 21,
	AC_EAP_PEAP                         = 25,
	AC_EAP_MSCHAPv2                     = 26,
	AC_EAP_FAST                         = 43
} AC_EAP_METHOD;

typedef enum _AC_EAP_TTLS_TUNNEL
{
	AC_EAP_TTLS_CHAP                    = 1,
	AC_EAP_TTLS_MSCHAP                  = 2,
	AC_EAP_TTLS_MSCHAPv2                = 3,
	AC_EAP_TTLS_PAP                     = 4,
	AC_EAP_TTLS_EAP                     = 5
} AC_EAP_TTLS_TUNNEL;

typedef enum _AC_EAP_FAST_PROVISION_MODE
{
	AC_EAP_FAST_PROVISION_UNAUTHENTICATED       = 1,
	AC_EAP_FAST_PROVISION_AUTHENTICATED         = 2
} AC_EAP_FAST_PROVISION_MODE;

typedef enum _AC_EAP_FAST_MODE
{
	AC_EAP_FAST_UNAUTHENTICATED_PROVISIONING    = 1,
	AC_EAP_FAST_AUTHENTICATED_PROVISIONING      = 2,
	AC_EAP_FAST_AUTHENTICATING                  = 3
} AC_EAP_FAST_MODE;

typedef enum _AC_EAP_FAST_PAC_TYPE
{
	AC_EAP_FAST_PAC_TUNNEL                      = 1,
	AC_EAP_FAST_PAC_MACHINE_AUTHENTICATION      = 2
} AC_EAP_FAST_PAC_TYPE;

typedef enum _ACTION_TYPE {
	BssidListScan,
	Profile,
	SSID,
	BSSID
} ACTION_TYPE, *PACTION_TYPE;

typedef struct _ACTION_DATA {
	ACTION_TYPE enumActionType;
	PVOID pActionBuffer;
} ACTION_DATA, *PACTION_DATA;

typedef enum _DEVICE_DRIVER_TYPE{
	CardBusWirelessDriver,
	RT61CardBusDriver,
	RT2860WirelessDriver,

	RT2500USBWirelessDriver,
	RT2573USBWirelessDriver,
	RT2870USBWirelessDriver,
	NoDriver
} DEVICE_DRIVER_TYPE, *PDEVICE_DRIVER_TYPE;

typedef struct _WLANStatus
{
	RAWLAN_STATUS						status;
	ULONG								ulExtraInfo;
	NDIS_802_11_SSID					ssid;
	NDIS_802_11_MAC_ADDRESS				bssid;
	NDIS_802_11_NETWORK_INFRASTRUCTURE	networkType;
	NDIS_802_11_RSSI					rssi;
	UINT								nSigQua;
	BOOL								bRssi_2;
	NDIS_802_11_RSSI					rssi_2;
	UINT								nSigQua2;
	BOOL								bRssi_3;
	NDIS_802_11_RSSI					rssi_3;
	UINT								nSigQua3;
	ULONG								ulSNR0;
	ULONG								ulSNR1;
	int									nNoisePercent;
	int									nNoiseDbm;
	NDIS_802_11_CONFIGURATION			phyConfig;
	NDIS_802_11_AUTHENTICATION_MODE		authenticationMode;
	NDIS_802_11_ENCRYPTION_STATUS		encryptStatus;
	RT_802_11_LINK_STATUS				linkStatus;
	double								txRate;
	double								rxRate;
	double								txthroughput;
	double								rxthroughput;
	ULONG								ultxpower;
	HTTRANSMIT_SETTING					txHTSetting;
	HTTRANSMIT_SETTING					rxHTSetting;
	RT_802_11_STATISTICS				statistics;
	ULONGLONG							ullRcvSucFrame;
	ULONG								lRcvOk;
	ULONG								lRcvNoBuf; // Frames Dropped Due To Out-of-Resource
	BOOL								bConnectedWithNModeAP;
	ULONG								Reserved;
}WLANSTATUS, *WLANStatus;

typedef struct _WLANPROFILE
{
	UCHAR								ProfileName[128];
	BOOL								bBssid;
	NDIS_802_11_SSID					SSID;
    NDIS_802_11_MAC_ADDRESS             BSSID;
    UCHAR                               Reserved[2];
	NDIS_802_11_NETWORK_INFRASTRUCTURE	enumNetworkType;
	RT_802_11_PREAMBLE					enumPreamType;
	NDIS_802_11_RTS_THRESHOLD			lRtsThre;
	NDIS_802_11_FRAGMENTATION_THRESHOLD	lFragThre;
	NDIS_802_11_AUTHENTICATION_MODE		enumAuthenMode;
	NDIS_802_11_ENCRYPTION_STATUS		enumEncryStatus;
	MIXED_MODE_ENCRYPTION				enumMixedModeEncryption;
	ULONG								lTxPower;
	CHAR								WEPKey1[64];		//WEP Key1
	ULONG								WEPKey1Type;		//WEP Key1 Type
	CHAR								WEPKey2[64];		//WEP Key2
	ULONG								WEPKey2Type;		//WEP Key2 Type
	CHAR								WEPKey3[64];		//WEP Key3
	ULONG								WEPKey3Type;		//WEP Key3 Type
	CHAR								WEPKey4[64];		//WEP Key4
	ULONG								WEPKey4Type;		//WEP Key4 Type
	ULONG								wepDefaultKey;		//WEP Default Key 	
	NDIS_802_11_POWER_MODE				enumPSMode;
	BOOL								bIsWPS;
	BOOL								bACCam;
	ULONG								lFreq;
	BOOL								bSetAdvance;
	NDIS_802_11_RATES					aryRates;
	RT_802_11_STA_CONFIG				configSta;
	BOOL								bDisassociate;
	
	// 802.1x Setting
	BOOL								b8021X;
	
	AUTHEN_PROTOCOL						enumAuthenProtocol;
	AC_EAP_METHOD						enumTunnel;
	AC_EAP_TTLS_TUNNEL					enumTtlsTunnel;
	BOOL								bSessionResumption;
	BOOL								bClientCert;
	CHAR								chID[128];
	CHAR								chPassword[128];
	CHAR								chDomainName[128];
	CHAR								chPskKey[65];
	int									nPasswordMode;
	UCHAR								chCertName[128];
	UCHAR								chPrivateKeyName[128];
} WLANPROFILE, *PWLANPROFILE;

typedef struct _SOFTAPPROFILE
{
	NDIS_802_11_SSID					SSID;
	ULONG								CountryRegIndex11BG;	// index of country region for 11BG
	ULONG								CountryRegIndex11A;		// index of country region for 11A
	RT_802_11_PHY_MODE					enumWirelessMode;		// PhyMode
	int									Use24Gor5G;				// 0 : 2.4GHz, 1 : 5GHz
	ULONG								lFreq;

	NDIS_802_11_AUTHENTICATION_MODE		enumAuthenMode;
	NDIS_802_11_ENCRYPTION_STATUS		enumEncryStatus;
	CHAR								WEPKey1[64];			//WEP Key1
	ULONG								WEPKey1Type;			//WEP Key1 Type
	CHAR								WEPKey2[64];			//WEP Key2
	ULONG								WEPKey2Type;			//WEP Key2 Type
	CHAR								WEPKey3[64];			//WEP Key3
	ULONG								WEPKey3Type;			//WEP Key3 Type
	CHAR								WEPKey4[64];			//WEP Key4
	ULONG								WEPKey4Type;			//WEP Key4 Type
	ULONG								wepDefaultKey;			//WEP Default Key 	
	
	CHAR								chPskKey[65];
	ULONG								RekeyTime;
} SOFTAPPROFILE, *PSOFTAPPROFILE;

typedef struct _PAIR_802_11N_RATE
{
	UCHAR	HTString[9];
	double	DataRate;		
} PAIR_802_11N_RATE, *PPAIR_802_11N_RATE;

typedef struct _PAIR_802_11AC_RATE
{
	UCHAR	VHTString[11];
	double	DataRate;		
} PAIR_802_11AC_RATE, *PPAIR_802_11AC_RATE;

typedef struct _IE_INFO_CCX
{	
	BOOL	bCCKM;
	BOOL	bCmic;
	BOOL	bCkip;
}IE_INFO_CCX, *PIE_INFO_CCX;

typedef struct _IE_INFO_WPA
{	
	ULONG	nAuthentication;
	ULONG	nEncryption;
}IE_INFO_WPA, *PIE_INFO_WPA;

typedef struct _IE_INFO_WPS
{
	BOOL	bWPSEnabled;
	char	strConfMthd[8];      
	char	strDevPassId[8];     
	char	strSelReg[8];	    
	char	strState[16];        
	char	strVersion[24];      
	char	strUuidE[36];        
	char	strApSetupLock[8];   
	char	strRfBands[16];      
}IE_INFO_WPS, *PIE_INFO_WPS;

typedef struct _IE_INFO_80211N
{
	//Is 802.11n
	BOOL b80211n;

	// Secondary Channel Offset element
	UCHAR chSecChanOffset;

	// Extended Capabilities information element
	BOOL bHtInfoExchangeSupport;

	// Neighbor Report element
	BOOL bMobilityDomain;
	BOOL bHighThroughput;

	// HT Capabilities element
	BOOL bHtcapability;
	BOOL bLdpcCodCapability;
	UCHAR chSupportChanWidthSet;
	UCHAR chSmPowerSave;
	BOOL bGreenField;
	BOOL bShortGi20MHz;
	BOOL bShortGi40MHz;
	BOOL bTxStbc;
	UCHAR chRxStbc;
	BOOL bHtDelayBlockAck;
	UCHAR chMaxAMsdulen;
	BOOL bDsssCckMode40MHz;
	BOOL bPsmpSupport;
	BOOL bHtCapaPsmpSupport;
	BOOL bMaxAMsdulen;
	BOOL bFortyMHzIntolerant;
	BOOL bLSigTxopProtSupport;

	// A-MPDU Parameters field
	UCHAR chMaxRxAMpduFactor;
	UCHAR chMinMpduStartSpacing;

	// Supported MCS Set field
	BOOL bTxMcsSetDefined;
	BOOL bTxRxMcsSetNotEqual;
	UCHAR chTxMaxNumberSpatialStreamsSupported;
	BOOL bTxUnequModulSupport;

	// HT Capabilities Info
	BOOL bDssCckMode40MHz;
	BOOL bHtInfoPsmpSupport;

	// A-MPDU Parameters
	ULONG lMaxRxAmpduFactor;
	ULONG lMinMpduStartSpacing;

	// HT Extended Capabilities
	BOOL bHtcSupport;
	BOOL bRdResponder;

	// HT Information element
	UCHAR chPriChan;
	UCHAR chHtInfoSecChanOffset;
	UCHAR chStaChanWidth;
	BOOL bRifsMode;
	BOOL bPsmpStaOnly;
	UCHAR chServInterGranu;
	UCHAR chOperatMode;
	BOOL bNoneGreenStaPresent;
	BOOL bTransmitBurstLimit;
	BOOL bObssNoneHtStaPresent;
	BOOL bDualBeacon;
	BOOL bDualCtsProtect;
	BOOL bSecBeacon;
	BOOL bLSigTxopProtFullSupport;
	BOOL bPcoActive;
	BOOL bPcoPhase;
	BOOL bBasicMcsSet;
	ULONG lBasicMcsSet0;
	ULONG lBasicMcsSet1;
	ULONG lBasicMcsSet2;
	ULONG lBasicMcsSet3;
	UCHAR MCSSet[16];
}IE_INFO_80211N, *PIE_INFO_80211N;

typedef struct _IE_INFO
{
	IE_INFO_WPA				ieWPA;
	IE_INFO_CCX				ieCCX;
	IE_INFO_WPS				ieWPS;
	IE_INFO_80211N			ie80211N;
	NDIS_802_11_FIXED_IEs	ieFixedIE;
}IE_INFO, *PIE_INFO;

typedef struct {
	int						nBGProtection;
	BOOL					bTXBurst;
	ULONG					CountryRegIndex11BG; // index of country region for 11BG
	ULONG					CountryRegIndex11A;  // index of country region for 11A
	RT_802_11_ADHOC_MODE 	enumAdhocPhyMode;		 // Adhoc Phy Mode
	RT_802_11_PHY_MODE 		enumWirelessMode;		 // PhyMode
	int						nTXRate;
	BOOL					bRadioSwitch;
	BOOL					bPSPXLink;
}ADVANCE_OID, *PADVANCE_OID;

//
// MAC architecture version (MacArchitectureVersion_Xxx)
//
typedef enum _MacArchitectureVersion
{
	MacArchitectureVersion_First = 0, 
	MacArchitectureVersion_Old = 1, 
	
	//
	// RT6X9X
	//	1. New TXWI/RXWI structures
	//	2. New order of RXD/RX_FCE_INFO/RXINFO/RXWI
	//	3. New register address mapping
	//
	MacArchitectureVersion_MacRegRemappingWithAndesEnabled = 2, // RT6X9X
	MacArchitectureVersion_Last = 2
} MacArchitectureVersion, *PMacArchitectureVersion;

//
// HW architecture version
//
typedef union _HW_ARCHITECTURE_VERSION
{
	struct
	{
		ULONG	MacVersion:8; // MacArchitectureVersion_Xxx
		ULONG	BbVersion:8; // BbArchitectureVersion_Xxx
		ULONG	RfVersion:8; // RfArchitectureVersion_Xxx
		ULONG	eFuseVersion:8;// eFuseArchitectureVersion_Xxx
	};
	
	ULONG		Word;
} HW_ARCHITECTURE_VERSION, *PHW_ARCHITECTURE_VERSION;

//Const define

#define MAX_CERT_COUNT 1024  //Certification Max Capacity

#endif // _STRUCTDEF_H_
