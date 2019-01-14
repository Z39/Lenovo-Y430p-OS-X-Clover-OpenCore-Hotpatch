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


#ifndef _OID_H_
#define _OID_H_

#include "SpecialDef.h"

#define ETH_LENGTH_OF_ADDRESS 6
#define MAX_NUM_OF_EVENT      10  // entry # in EVENT table
#define MAX_LEN_OF_MAC_TABLE  32

#define IterateLimit	10

// OID definition

#define OID_GEN_MACHINE_NAME               0x0001021A

//
// IEEE 802.11 OIDs
//
#define OID_802_11_BSSID                        0x0D010101
#define OID_802_11_SSID                         0x0D010102
#define OID_802_11_NETWORK_TYPES_SUPPORTED      0x0D010203
#define OID_802_11_NETWORK_TYPE_IN_USE          0x0D010204
#define OID_802_11_TX_POWER_LEVEL               0x0D010205
#define OID_802_11_RSSI                         0x0D010206
#define OID_802_11_RSSI_TRIGGER                 0x0D010207
#define OID_802_11_INFRASTRUCTURE_MODE          0x0D010108
#define OID_802_11_FRAGMENTATION_THRESHOLD      0x0D010209
#define OID_802_11_RTS_THRESHOLD                0x0D01020A
#define OID_802_11_NUMBER_OF_ANTENNAS           0x0D01020B
#define OID_802_11_RX_ANTENNA_SELECTED          0x0D01020C
#define OID_802_11_TX_ANTENNA_SELECTED          0x0D01020D
#define OID_802_11_SUPPORTED_RATES              0x0D01020E
#define OID_802_11_DESIRED_RATES                0x0D010210
#define OID_802_11_CONFIGURATION                0x0D010211
#define OID_802_11_STATISTICS                   0x0D020212
#define OID_802_11_ADD_WEP                      0x0D010113
#define OID_802_11_REMOVE_WEP                   0x0D010114
#define OID_802_11_DISASSOCIATE                 0x0D010115
#define OID_802_11_POWER_MODE                   0x0D010216
#define OID_802_11_BSSID_LIST                   0x0D010217
// for repeating get BSSID on Macintosh
#define OID_802_11_BSSID_LIST_NEXT				0x0D010218
#define OID_802_11_AUTHENTICATION_MODE          0x0D010118
#define OID_802_11_PRIVACY_FILTER               0x0D010119
#define OID_802_11_BSSID_LIST_SCAN              0x0D01011A
#define OID_802_11_WEP_STATUS                   0x0D01011B
// Renamed to reflect better the extended set of encryption status
#define OID_802_11_ENCRYPTION_STATUS            OID_802_11_WEP_STATUS
#define OID_802_11_RELOAD_DEFAULTS              0x0D01011C
// Added to allow key mapping and default keys
#define OID_802_11_ADD_KEY                      0x0D01011D
#define OID_802_11_REMOVE_KEY                   0x0D01011E
#define OID_802_11_ASSOCIATION_INFORMATION      0x0D01011F
#define OID_802_11_TEST_SLEEP					0x0D010120
#define OID_802_11_DEVICE_READY_AFTER_SLEEP		0x0D010121
#define OID_802_11_IS_PORT_SECURED				0x0D010124


// value domain of pAd->StaCfg.PortSecured. 802.1X controlled port definition
#define WPA_802_1X_PORT_SECURED     1
#define WPA_802_1X_PORT_PASS_4_WAY  2
#define WPA_802_1X_PORT_NOT_SECURED 3

//
// IEEE 802.11 Structures and definitions
//
// new types for Media Specific Indications

#define NDIS_802_11_LENGTH_SSID         32
#define NDIS_802_11_LENGTH_RATES        8
#define NDIS_802_11_LENGTH_RATES_EX     16

// Added new types for OFDM 5G and 2.4G
typedef enum _NDIS_802_11_NETWORK_TYPE
{
    Ndis802_11FH,
    Ndis802_11DS,
    Ndis802_11OFDM5,
    Ndis802_11OFDM24,
    Ndis802_11NetworkTypeMax    // not a real type, defined as an upper bound
} NDIS_802_11_NETWORK_TYPE, *PNDIS_802_11_NETWORK_TYPE;

typedef struct _NDIS_802_11_NETWORK_TYPE_LIST
{
    ULONG                       NumberOfItems;  // in list below, at least 1
    NDIS_802_11_NETWORK_TYPE    NetworkType [1];
} NDIS_802_11_NETWORK_TYPE_LIST, *PNDIS_802_11_NETWORK_TYPE_LIST;

typedef enum _NDIS_802_11_POWER_MODE
{
    Ndis802_11PowerModeCAM,
    Ndis802_11PowerModeMAX_PSP,
    Ndis802_11PowerModeFast_PSP,
    Ndis802_11PowerModeMax      // not a real mode, defined as an upper bound
} NDIS_802_11_POWER_MODE, *PNDIS_802_11_POWER_MODE;

typedef ULONG   NDIS_802_11_TX_POWER_LEVEL; // in milliwatts

//
// Received Signal Strength Indication
//
typedef LONG   NDIS_802_11_RSSI;           // in dBm

typedef struct _NDIS_802_11_CONFIGURATION_FH
{
    ULONG           Length;             // Length of structure
    ULONG           HopPattern;         // As defined by 802.11, MSB set
    ULONG           HopSet;             // to one if non-802.11
    ULONG           DwellTime;          // units are Kusec
} NDIS_802_11_CONFIGURATION_FH, *PNDIS_802_11_CONFIGURATION_FH;

typedef struct _NDIS_802_11_CONFIGURATION
{
    ULONG           Length;             // Length of structure
    ULONG           BeaconPeriod;       // units are Kusec
    ULONG           ATIMWindow;         // units are Kusec
    ULONG           DSConfig;           // Frequency, units are kHz
    NDIS_802_11_CONFIGURATION_FH    FHConfig;
} NDIS_802_11_CONFIGURATION, *PNDIS_802_11_CONFIGURATION;

typedef struct _RT_802_11_STATISTICS
{
   UInt64          Length;             // Length of structure
   LARGE_INTEGER   TransmittedFragmentCount;
   LARGE_INTEGER   MulticastTransmittedFrameCount;
   LARGE_INTEGER   FailedCount;
   LARGE_INTEGER   RetryCount;
   LARGE_INTEGER   MultipleRetryCount;
   LARGE_INTEGER   RTSSuccessCount;
   LARGE_INTEGER   RTSFailureCount;
   LARGE_INTEGER   ACKFailureCount;
   LARGE_INTEGER   FrameDuplicateCount;
   LARGE_INTEGER   ReceivedFragmentCount;
   LARGE_INTEGER   MulticastReceivedFrameCount;
   LARGE_INTEGER   FCSErrorCount;
   LARGE_INTEGER   TKIPLocalMICFailures;
   LARGE_INTEGER   TKIPRemoteMICErrors;
   LARGE_INTEGER   TKIPICVErrors;
   LARGE_INTEGER   TKIPCounterMeasuresInvoked;
   LARGE_INTEGER   TKIPReplays;
   LARGE_INTEGER   CCMPFormatErrors;
   LARGE_INTEGER   CCMPReplays;
   LARGE_INTEGER   CCMPDecryptErrors;
   LARGE_INTEGER   FourWayHandshakeFailures;
} RT_802_11_STATISTICS, *PRT_802_11_STATISTICS;

typedef ULONG  NDIS_802_11_KEY_INDEX;

typedef struct _NDIS_802_11_WEP
{
    ULONG           Length;             // Length of this structure
    ULONG           KeyIndex;           // 0 is the per-client key, 1-N are the global keys
    ULONG           KeyLength;          // length of key in bytes
    UCHAR           KeyMaterial[1];     // variable length depending on above field
} NDIS_802_11_WEP, *PNDIS_802_11_WEP;

typedef ULONGLONG NDIS_802_11_KEY_RSC;
typedef UCHAR   NDIS_802_11_MAC_ADDRESS[6];

// Key mapping keys require a BSSID
typedef struct _NDIS_802_11_KEY
{
    ULONG           Length;             // Length of this structure
    ULONG           KeyIndex;           
    ULONG           KeyLength;          // length of key in bytes
    NDIS_802_11_MAC_ADDRESS BSSID;
    NDIS_802_11_KEY_RSC KeyRSC;
    UCHAR           KeyMaterial[1];     // variable length depending on above field
} NDIS_802_11_KEY, *PNDIS_802_11_KEY;

typedef struct _NDIS_802_11_REMOVE_KEY
{
    ULONG           Length;             // Length of this structure
    ULONG           KeyIndex;           
    NDIS_802_11_MAC_ADDRESS BSSID;      
} NDIS_802_11_REMOVE_KEY, *PNDIS_802_11_REMOVE_KEY;

typedef enum _NDIS_802_11_NETWORK_INFRASTRUCTURE
{
    Ndis802_11IBSS,
    Ndis802_11Infrastructure,
    Ndis802_11AutoUnknown,
    Ndis802_11InfrastructureMax         // Not a real value, defined as upper bound
} NDIS_802_11_NETWORK_INFRASTRUCTURE, *PNDIS_802_11_NETWORK_INFRASTRUCTURE;

// Add new authentication modes
typedef enum _NDIS_802_11_AUTHENTICATION_MODE
{
    Ndis802_11AuthModeOpen,
    Ndis802_11AuthModeShared,
    Ndis802_11AuthModeAutoSwitch,
    Ndis802_11AuthModeWPA,
    Ndis802_11AuthModeWPAPSK,
    Ndis802_11AuthModeWPANone,
    Ndis802_11AuthModeWPA2,
    Ndis802_11AuthModeWPA2PSK,
	Ndis802_11AuthModeWPA1WPA2,
	Ndis802_11AuthModeWPA1PSKWPA2PSK,
    Ndis802_11AuthModeMax               // Not a real mode, defined as upper bound
} NDIS_802_11_AUTHENTICATION_MODE, *PNDIS_802_11_AUTHENTICATION_MODE;

typedef UCHAR   NDIS_802_11_RATES[NDIS_802_11_LENGTH_RATES];        // Set of 8 data rates
typedef UCHAR   NDIS_802_11_RATES_EX[NDIS_802_11_LENGTH_RATES_EX];  // Set of 16 data rates

typedef struct _NDIS_802_11_SSID
{
    ULONG   SsidLength;         // length of SSID field below, in bytes;
                                // this can be zero.
    UCHAR   Ssid[NDIS_802_11_LENGTH_SSID];           // SSID information field

} NDIS_802_11_SSID, *PNDIS_802_11_SSID;

typedef struct _NDIS_WLAN_BSSID
{
    ULONG                               Length;             // Length of this structure
    NDIS_802_11_MAC_ADDRESS             MacAddress;         // BSSID
    UCHAR                               Reserved[2];
    NDIS_802_11_SSID                    Ssid;               // SSID
    ULONG                               Privacy;            // WEP encryption requirement
    NDIS_802_11_RSSI                    Rssi;               // receive signal
                                                            // strength in dBm
    NDIS_802_11_NETWORK_TYPE            NetworkTypeInUse;
    NDIS_802_11_CONFIGURATION           Configuration;
    NDIS_802_11_NETWORK_INFRASTRUCTURE  InfrastructureMode;
    NDIS_802_11_RATES                   SupportedRates;
} NDIS_WLAN_BSSID, *PNDIS_WLAN_BSSID;

typedef struct _NDIS_802_11_BSSID_LIST
{
    ULONG           NumberOfItems;      // in list below, at least 1
    NDIS_WLAN_BSSID Bssid[1];
} NDIS_802_11_BSSID_LIST, *PNDIS_802_11_BSSID_LIST;

// Added Capabilities, IELength and IEs for each BSSID
typedef struct _NDIS_WLAN_BSSID_EX
{
    ULONG                               Length;             // Length of this structure
    NDIS_802_11_MAC_ADDRESS             MacAddress;         // BSSID
    UCHAR                               Reserved[2];
    NDIS_802_11_SSID                    Ssid;               // SSID
    ULONG                               Privacy;            // WEP encryption requirement
    NDIS_802_11_RSSI                    Rssi;               // receive signal
                                                            // strength in dBm
    NDIS_802_11_NETWORK_TYPE            NetworkTypeInUse;
    NDIS_802_11_CONFIGURATION           Configuration;
    NDIS_802_11_NETWORK_INFRASTRUCTURE  InfrastructureMode;
    NDIS_802_11_RATES_EX                SupportedRates;
    ULONG                               IELength;
    UCHAR                               IEs[1];
} NDIS_WLAN_BSSID_EX, *PNDIS_WLAN_BSSID_EX;

typedef struct _NDIS_802_11_FIXED_IEs 
{
    UCHAR Timestamp[8];
    USHORT BeaconInterval;
    USHORT Capabilities;
} NDIS_802_11_FIXED_IEs, *PNDIS_802_11_FIXED_IEs;

typedef struct _NDIS_802_11_VARIABLE_IEs 
{
    UCHAR ElementID;
    UCHAR Length;    // Number of bytes in data field
    UCHAR data[1];
} NDIS_802_11_VARIABLE_IEs, *PNDIS_802_11_VARIABLE_IEs;

typedef struct _NDIS_802_11_BSSID_LIST_EX
{
    ULONG                   NumberOfItems;      // in list below, at least 1
    NDIS_WLAN_BSSID_EX      Bssid[1];
} NDIS_802_11_BSSID_LIST_EX, *PNDIS_802_11_BSSID_LIST_EX;

typedef  ULONG   NDIS_802_11_FRAGMENTATION_THRESHOLD;

typedef  ULONG   NDIS_802_11_RTS_THRESHOLD;

typedef  ULONG   NDIS_802_11_ANTENNA;

typedef enum _NDIS_802_11_PRIVACY_FILTER
{
    Ndis802_11PrivFilterAcceptAll,
    Ndis802_11PrivFilter8021xWEP
} NDIS_802_11_PRIVACY_FILTER, *PNDIS_802_11_PRIVACY_FILTER;

// Added new encryption types
// Also aliased typedef to new name
typedef enum _NDIS_802_11_WEP_STATUS
{
    Ndis802_11WEPEnabled,
    Ndis802_11Encryption1Enabled = Ndis802_11WEPEnabled,
    Ndis802_11WEPDisabled,
    Ndis802_11EncryptionDisabled = Ndis802_11WEPDisabled,
    Ndis802_11WEPKeyAbsent,
    Ndis802_11Encryption1KeyAbsent = Ndis802_11WEPKeyAbsent,
    Ndis802_11WEPNotSupported,
    Ndis802_11EncryptionNotSupported = Ndis802_11WEPNotSupported,
    Ndis802_11Encryption2Enabled,
    Ndis802_11Encryption2KeyAbsent,
    Ndis802_11Encryption3Enabled,
    Ndis802_11Encryption3KeyAbsent,
	Ndis802_11Encryption4Enabled
} NDIS_802_11_WEP_STATUS, *PNDIS_802_11_WEP_STATUS,
  NDIS_802_11_ENCRYPTION_STATUS, *PNDIS_802_11_ENCRYPTION_STATUS;

// Mixed mode enum, only use for MAC OS X.
typedef enum _MIXED_MODE_ENCRYPTION
{
	Mixed_None,
	Mixed_WEP40_TKIP,
	Mixed_WEP104_TKIP,
	Mixed_TKIP_AES,
	Mixed_WEP40_AES,
	Mixed_WEP104_AES
} MIXED_MODE_ENCRYPTION, *PMIXED_MODE_ENCRYPTION;
	

typedef enum _NDIS_802_11_RELOAD_DEFAULTS
{
    Ndis802_11ReloadWEPKeys
} NDIS_802_11_RELOAD_DEFAULTS, *PNDIS_802_11_RELOAD_DEFAULTS;

#define NDIS_802_11_AI_REQFI_CAPABILITIES      1
#define NDIS_802_11_AI_REQFI_LISTENINTERVAL    2
#define NDIS_802_11_AI_REQFI_CURRENTAPADDRESS  4

#define NDIS_802_11_AI_RESFI_CAPABILITIES      1
#define NDIS_802_11_AI_RESFI_STATUSCODE        2
#define NDIS_802_11_AI_RESFI_ASSOCIATIONID     4

typedef struct _NDIS_802_11_ASSOCIATION_INFORMATION
{
    ULONG                   Length;
    USHORT                  AvailableRequestFixedIEs;
    struct _NDIS_802_11_AI_REQFI {
		USHORT Capabilities;
		USHORT ListenInterval;
        NDIS_802_11_MAC_ADDRESS  CurrentAPAddress;
    } RequestFixedIEs;
    ULONG                   RequestIELength;
    ULONG                   OffsetRequestIEs;
    USHORT                  AvailableResponseFixedIEs;
    struct _NDIS_802_11_AI_RESFI {
		USHORT Capabilities;
		USHORT StatusCode;
		USHORT AssociationId;
    } ResponseFixedIEs;
    ULONG                   ResponseIELength;
    ULONG                   OffsetResponseIEs;
} NDIS_802_11_ASSOCIATION_INFORMATION, *PNDIS_802_11_ASSOCIATION_INFORMATION;

#define NDIS_802_11_LENGTH_SSID         32
#define NDIS_802_11_LENGTH_RATES        8
#define NDIS_802_11_LENGTH_RATES_EX     16

typedef enum _NDIS_802_11_STATUS_TYPE
{
    Ndis802_11StatusType_Authentication,
    Ndis802_11StatusType_PMKID_CandidateList=2,
    Ndis802_11StatusTypeMax
} NDIS_802_11_STATUS_TYPE, *PNDIS_802_11_STATUS_TYPE;

typedef struct _NDIS_802_11_STATUS_INDICATION
{
    NDIS_802_11_STATUS_TYPE StatusType;
} NDIS_802_11_STATUS_INDICATION, *PNDIS_802_11_STATUS_INDICATION;

// mask for authentication/integrity fields
#define NDIS_802_11_AUTH_REQUEST_AUTH_FIELDS        0x0f

#define NDIS_802_11_AUTH_REQUEST_REAUTH             0x01
#define NDIS_802_11_AUTH_REQUEST_KEYUPDATE          0x02
#define NDIS_802_11_AUTH_REQUEST_PAIRWISE_ERROR     0x06
#define NDIS_802_11_AUTH_REQUEST_GROUP_ERROR        0x0E

typedef struct _NDIS_802_11_AUTHENTICATION_REQUEST
{
    ULONG Length;            // Length of structure
    NDIS_802_11_MAC_ADDRESS Bssid;
    ULONG Flags;
} NDIS_802_11_AUTHENTICATION_REQUEST, *PNDIS_802_11_AUTHENTICATION_REQUEST;

typedef struct _PMKID_CANDIDATE {
    NDIS_802_11_MAC_ADDRESS BSSID;
    ULONG Flags;
} PMKID_CANDIDATE, *PPMKID_CANDIDATE;

typedef struct _NDIS_802_11_PMKID_CANDIDATE_LIST
{
    ULONG Version;       // Version of the structure
    ULONG NumCandidates; // No. of pmkid candidates
    PMKID_CANDIDATE CandidateList[1];
} NDIS_802_11_PMKID_CANDIDATE_LIST, *PNDIS_802_11_PMKID_CANDIDATE_LIST;

//Flags for PMKID Candidate list structure

#define NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED	0x01
 

typedef struct _NDIS_802_11_TEST
{
    ULONG Length;
    ULONG Type;
	union {
		struct _AuthenticationEvent {
		NDIS_802_11_STATUS_TYPE StatusType;
		NDIS_802_11_AUTHENTICATION_REQUEST Request[1];
	} AuthenticationEvent;
        NDIS_802_11_RSSI RssiTrigger;
    };
} NDIS_802_11_TEST, *PNDIS_802_11_TEST;

typedef UCHAR   NDIS_802_11_PMKID_VALUE[16]; 

typedef struct _BSSID_INFO
{
    NDIS_802_11_MAC_ADDRESS BSSID;
    NDIS_802_11_PMKID_VALUE PMKID;
} BSSID_INFO, *PBSSID_INFO;

typedef struct _NDIS_802_11_PMKID
{
    ULONG Length;
    ULONG BSSIDInfoCount;
    BSSID_INFO BSSIDInfo[1];
} NDIS_802_11_PMKID, *PNDIS_802_11_PMKID;
 
typedef struct _NDIS_802_11_AUTHENTICATION_ENCRYPTION
{
	NDIS_802_11_AUTHENTICATION_MODE AuthModeSupported;
	NDIS_802_11_ENCRYPTION_STATUS EncryptStatusSupported;
} NDIS_802_11_AUTHENTICATION_ENCRYPTION, *PNDIS_802_11_AUTHENTICATION_ENCRYPTION;

typedef struct _NDIS_802_11_CAPABILITY
{
    ULONG Length;
    ULONG Version;
    ULONG NoOfPMKIDs;
    ULONG NoOfAuthEncryptPairsSupported;
    NDIS_802_11_AUTHENTICATION_ENCRYPTION AuthenticationEncryptionSupported[1];
} NDIS_802_11_CAPABILITY, *PNDIS_802_11_CAPABILITY; 


// Ralink defined OIDs
#define OID_GET_SET_TOGGLE                    0x00800000

#define RT_OID_802_11_BSSID                   (OID_GET_SET_TOGGLE | OID_802_11_BSSID)
#define RT_OID_802_11_SSID                    (OID_GET_SET_TOGGLE | OID_802_11_SSID)
#define RT_OID_802_11_INFRASTRUCTURE_MODE     (OID_GET_SET_TOGGLE | OID_802_11_INFRASTRUCTURE_MODE)
#define RT_OID_802_11_ADD_WEP                 (OID_GET_SET_TOGGLE | OID_802_11_ADD_WEP)
#define RT_OID_802_11_ADD_KEY                 (OID_GET_SET_TOGGLE | OID_802_11_ADD_KEY)
#define RT_OID_802_11_REMOVE_WEP              (OID_GET_SET_TOGGLE | OID_802_11_REMOVE_WEP)
#define RT_OID_802_11_DISASSOCIATE            (OID_GET_SET_TOGGLE | OID_802_11_DISASSOCIATE)
#define RT_OID_802_11_AUTHENTICATION_MODE     (OID_GET_SET_TOGGLE | OID_802_11_AUTHENTICATION_MODE)
#define RT_OID_802_11_PRIVACY_FILTER          (OID_GET_SET_TOGGLE | OID_802_11_PRIVACY_FILTER)
#define RT_OID_802_11_BSSID_LIST_SCAN         (OID_GET_SET_TOGGLE | OID_802_11_BSSID_LIST_SCAN)
#define RT_OID_802_11_WEP_STATUS              (OID_GET_SET_TOGGLE | OID_802_11_WEP_STATUS)
#define RT_OID_802_11_RELOAD_DEFAULTS         (OID_GET_SET_TOGGLE | OID_802_11_RELOAD_DEFAULTS)
#define RT_OID_802_11_NETWORK_TYPE_IN_USE     (OID_GET_SET_TOGGLE | OID_802_11_NETWORK_TYPE_IN_USE)
#define RT_OID_802_11_TX_POWER_LEVEL          (OID_GET_SET_TOGGLE | OID_802_11_TX_POWER_LEVEL)
#define RT_OID_802_11_RSSI_TRIGGER            (OID_GET_SET_TOGGLE | OID_802_11_RSSI_TRIGGER)
#define RT_OID_802_11_FRAGMENTATION_THRESHOLD (OID_GET_SET_TOGGLE | OID_802_11_FRAGMENTATION_THRESHOLD)
#define RT_OID_802_11_RTS_THRESHOLD           (OID_GET_SET_TOGGLE | OID_802_11_RTS_THRESHOLD)
#define RT_OID_802_11_RX_ANTENNA_SELECTED     (OID_GET_SET_TOGGLE | OID_802_11_RX_ANTENNA_SELECTED)
#define RT_OID_802_11_TX_ANTENNA_SELECTED     (OID_GET_SET_TOGGLE | OID_802_11_TX_ANTENNA_SELECTED)
#define RT_OID_802_11_SUPPORTED_RATES         (OID_GET_SET_TOGGLE | OID_802_11_SUPPORTED_RATES)
#define RT_OID_802_11_DESIRED_RATES           (OID_GET_SET_TOGGLE | OID_802_11_DESIRED_RATES)
#define RT_OID_802_11_CONFIGURATION           (OID_GET_SET_TOGGLE | OID_802_11_CONFIGURATION)
#define RT_OID_802_11_POWER_MODE              (OID_GET_SET_TOGGLE | OID_802_11_POWER_MODE)
#define RT_OID_802_11_STATISTICS              (OID_GET_SET_TOGGLE | OID_802_11_STATISTICS)

#define RT_OID_802_11_QUERY_PREAMBLE          0x0D710101
#define RT_OID_802_11_SET_PREAMBLE            (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_PREAMBLE)
#define RT_OID_802_11_QUERY_LINK_STATUS       0x0D710102
#define RT_OID_802_11_RESET_COUNTERS          (OID_GET_SET_TOGGLE | 0x0D710103)
#define RT_OID_802_11_QUERY_AC_CAM            0x0D710104
#define RT_OID_802_11_SET_AC_CAM              (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_AC_CAM)
#define RT_OID_802_11_QUERY_HARDWARE_REGISTER 0x0D710105
#define RT_OID_802_11_SET_HARDWARE_REGISTER   (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_HARDWARE_REGISTER)
#define RT_OID_802_11_QUERY_RACONFIG          0x0D710106
#define RT_OID_802_11_SET_RACONFIG            (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_RACONFIG)
#define RT_OID_802_11_QUERY_COUNTRY_REGION    0x0D710107
#define RT_OID_802_11_SET_COUNTRY_REGION      (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_COUNTRY_REGION)
#define	RT_OID_802_11_QUERY_RADIO             0x0D710108
#define RT_OID_802_11_SET_RADIO               (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_RADIO)
#define RT_OID_802_11_QUERY_RX_AGC_VGC_TUNING 0x0D710109
#define RT_OID_802_11_SET_RX_AGC_VGC_TUNING   (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_RX_AGC_VGC_TUNING)
#define RT_OID_802_11_QUERY_EVENT_TABLE       0x0D71010A
#define RT_OID_802_11_QUERY_MAC_TABLE         0x0D71010B
#define RT_OID_802_11_QUERY_PHY_MODE          0x0D71010C
#define RT_OID_802_11_SET_PHY_MODE            (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_PHY_MODE)
#define RT_OID_802_11_QUERY_TX_PACKET_BURST   0x0D71010D
#define RT_OID_802_11_SET_TX_PACKET_BURST     (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_TX_PACKET_BURST)
#define RT_OID_802_11_QUERY_TURBO_MODE        0x0D71010E
#define RT_OID_802_11_SET_TURBO_MODE          (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_TURBO_MODE)
#define RT_OID_802_11_QUERY_AP_CONFIG         0x0D71010F
#define RT_OID_802_11_SET_AP_CONFIG           (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_AP_CONFIG)
#define RT_OID_802_11_QUERY_ACL               0x0D710110
#define RT_OID_802_11_SET_ACL                 (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_ACL)
#define RT_OID_802_11_QUERY_STA_CONFIG        0x0D710111
#define RT_OID_802_11_SET_STA_CONFIG          (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_STA_CONFIG)
#define RT_OID_802_11_QUERY_WDS               0x0D710112
#define RT_OID_802_11_SET_WDS                 (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_WDS)

// Add by James to fit WPA Soft-AP extra data
#define RT_OID_802_11_QUERY_RADIUS_DATA       0x0D710113
#define RT_OID_802_11_SET_RADIUS_DATA         (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_RADIUS_DATA)
#define RT_OID_802_11_QUERY_WPA_REKEY         0x0D710114
#define RT_OID_802_11_SET_WPA_REKEY           (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_WPA_REKEY)
//wpa counter measure test
#define RT_OID_802_11_QUERY_GEN_MIC_ERROR     0x0D710115
#define RT_OID_802_11_SET_GEN_MIC_ERROR       (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_GEN_MIC_ERROR)

#define RT_OID_802_11_ADD_WPA                 (OID_GET_SET_TOGGLE | 0x0D710116)
#define RT_OID_802_11_QUERY_CURRENT_CHANNEL_ID 0x0D710117
#define RT_OID_802_11_QUERY_TX_POWER_LEVEL_1  0x0D710118
#define RT_OID_802_11_SET_TX_POWER_LEVEL_1    (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_TX_POWER_LEVEL_1)
#define RT_OID_802_11_QUERY_EEPROM_VERSION    0x0D710119
#define	RT_OID_802_11_QUERY_NOISE_LEVEL       0x0D71011A
#define	RT_OID_802_11_QUERY_LAST_RX_RATE      0x0D71011B
#define	RT_OID_802_11_QUERY_LAST_TX_RATE      0x0D71011C
#define	RT_OID_802_11_LEAP_AUTH_INFO          (OID_GET_SET_TOGGLE | 0x0D71011C)
#define	RT_OID_802_11_EXTRA_INFO	          0x0D71011D
#define	RT_OID_802_11_CCX20_INFO	          (OID_GET_SET_TOGGLE | 0x0D71011E)
#define	RT_OID_802_11_QUERY_AIRONETIP_INFO	  0x0D71011F
#define	RT_OID_802_11_SET_RF_REGISTER	      (OID_GET_SET_TOGGLE | 0x0D710120)
#define	RT_OID_802_11_SET_BBP_TUNING	      (OID_GET_SET_TOGGLE | 0x0D710121)
#define OID_CUSTOM_LAST_RX_BEACON_INFO        0x0D710120
#define OID_CUSTOM_QUERY_SELECT_ANTENNA_INFO  0x0D710121
#define OID_CUSTOM_SET_SELECT_ANTENNA_INFO    (OID_GET_SET_TOGGLE | 0x0D710121)
#define OID_CUSTOM_QUERY_STEERING_ALGORITHM_PARAMS_INFO 0x0D710122
#define OID_CUSTOM_SET_STEERING_ALGORITHM_PARAMS_INFO (OID_GET_SET_TOGGLE | 0x0D710122)
#define OID_CUSTOM_STEERING_ALGORITHM_STATE_INFO 0x0D710123
#define OID_CUSTOM_AVERAGE_RSSI_INFO          0x0D710124 
#define	RT_OID_802_11_RSSI_1                  0x0D710125
#define RT_OID_802_11_QUERY_OP_MODE				0x0D710126
#define RT_OID_802_11_SET_OP_MODE				(OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_OP_MODE)
#define	RT_OID_802_11_RSSI_2                  0x0D710134
#define RT_OID_802_11_RSSI_COUNT			  0x0D710201
#define RT_OID_802_11_SET_TX_RATES            (OID_GET_SET_TOGGLE | 0x0D710127)
#define RT_OID_802_11_SET_PSPXLINK_MODE			(OID_GET_SET_TOGGLE | 0x0D710150)


//Add Paul Chen for Accton
#define RT_OID_TX_POWER_LEVEL                 0xFF020010
#define RT_OID_SET_TX_POWER_LEVEL             (OID_GET_SET_TOGGLE | RT_OID_TX_POWER_LEVEL)

#define RT_OID_802_11_QUERY_FIRMWARE_VERSION              0x0D710129

//Add APSD Test Page
#define RT_OID_802_11_QUERY_APSD_SETTING  0x0D71012A
#define RT_OID_802_11_SET_APSD_SETTING   (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_APSD_SETTING)
#define RT_OID_802_11_QUERY_APSD_PSM   0x0D71012B
#define RT_OID_802_11_SET_APSD_PSM    (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_APSD_PSM)
#define RT_OID_802_11_QUERY_WMM                            0x0D71012D
#define RT_OID_802_11_SET_WMM                           (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_WMM)


//Add by candy for DLGPage
#define MAX_NUM_OF_DLS_ENTRY				4
#define RT_OID_802_11_QUERY_EVENT_CAPABLE	0x0D71012F
#define RT_OID_802_11_SET_EVENT_CAPABLE		(OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_EVENT_CAPABLE)
#define RT_OID_802_11_QUERY_EVENT_MESSAGE	0x0D710130 
#define RT_OID_802_11_QUERY_DLS				0x0D710131
#define RT_OID_802_11_SET_DLS				(OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_DLS)
#define RT_OID_802_11_QUERY_DLS_PARAM		0x0D710132
#define RT_OID_802_11_SET_DLS_PARAM			(OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_DLS_PARAM)
//add by candy 2006.6.21
//// Aegis4 doesn°¶t send OID_MH_CCX_LEAP, UI sends RT_OID_SET_CCX_LEAP instead
#define RT_OID_QUERY_CCX_LEAP				0x0D710139
#define RT_OID_SET_CCX_LEAP					(OID_GET_SET_TOGGLE | RT_OID_QUERY_CCX_LEAP)

// 2006/05/25 Shufen added
#define RT_OID_802_11_QUERY_PRIVATE_MESSAGE 0x0D710133    

#define RT_OID_USB_VENDOR_EEPROM_WRITE			0x0D73010A
#define RT_OID_USB_VENDOR_EEPROM_READ			0x0D73010B


#define RT_OID_802_11_QUERY_RFIC_TYPE			0x0D710299

#define   RT_OID_802_11_SET_DISABLED_INTERNET_SHARING         (OID_GET_SET_TOGGLE | 0x0D710300)

#define	RT_OID_802_11_WPS_SET_MODE						(OID_GET_SET_TOGGLE | 0x0D710140)		// No query for this OID
#define	RT_OID_802_11_WPS_QUERY_STATUS					0x0D710141
#define	RT_OID_802_11_WPS_QUERY_PROFILE					0x0D710142
#define	RT_OID_802_11_WPS_SET_PROFILE					(OID_GET_SET_TOGGLE | 0x0D710142)
#define	RT_OID_802_11_WPS_SET_PROFILE_TYPE				(OID_GET_SET_TOGGLE | 0x0D710143)
#define RT_OID_802_11_WPS_SET_ASSOCIATE_IE				(OID_GET_SET_TOGGLE | 0x0D710144)
#define RT_OID_802_11_WPS_QUERY_HW_PBC					0x0D710145
#define RT_OID_802_11_WPS_SET_PROBEREQ_IE				(OID_GET_SET_TOGGLE | 0x0D710146)
#define RT_OID_802_11_WPS_SET_AUTO_SELECT				(OID_GET_SET_TOGGLE | 0x0D710148)
#define RT_OID_802_11_WPS_SET_CONNECT					(OID_GET_SET_TOGGLE | 0x0D710149)
#define RT_OID_802_11_QUERY_PREFERRED_WPS_AP_PHY_TYPE	0x0D710151
#define RT_OID_802_11_SET_PREFERRED_WPS_AP_PHY_TYPE		(OID_GET_SET_TOGGLE | 0x0D710151)
#define RT_OID_802_11_WPS_QUERY_WPS_AP_CHANNEL			0x0D710152

//Close Scutum
#define RT_OID_CLOSE_SCUTUM								(OID_GET_SET_TOGGLE | 0x0D7101F1)

#define PROXY_RT_OID_WPS_QUERY_HW_PBC					RT_OID_802_11_WPS_QUERY_HW_PBC
#define PROXY_RT_OID_WPS_QUERY_STATUS					RT_OID_802_11_WPS_QUERY_STATUS
#define PROXY_RT_OID_WPS_SET_MODE						RT_OID_802_11_WPS_SET_MODE
#define PROXY_RT_OID_WPS_SET_PROFILE					RT_OID_802_11_WPS_SET_PROFILE
#define PROXY_RT_OID_WPS_SET_ASSOCIATE_IE				RT_OID_802_11_WPS_SET_ASSOCIATE_IE
#define PROXY_RT_OID_WPS_SET_PROBEREQ_IE				RT_OID_802_11_WPS_SET_PROBEREQ_IE
#define PROXY_RT_OID_WPS_SET_AUTO_SELECT				RT_OID_802_11_WPS_SET_AUTO_SELECT
#define PROXY_RT_OID_WPS_QUERY_PROFILE					RT_OID_802_11_WPS_QUERY_PROFILE
#define PROXY_RT_OID_WPS_SET_CONNECT					RT_OID_802_11_WPS_SET_CONNECT

#define RT_OID_DEVICE_ID								0x0D730316
#define RT_OID_DEVICE_PREFIX_NAME					0x0D730317
#define RT_OID_QUERY_HW_ARCHITECTURE_VERSION			(0x0D7C0050)

#define RT_OID_802_11_DBGINFO							(OID_GET_SET_TOGGLE | 0x0D730318)

#define RT_OID_802_11_QUERY_BATABLE           0x0D710138
#define RT_OID_802_11_QUERY_IMME_BA_CAP       0x0D710137
#define RT_OID_802_11_SET_IMME_BA_CAP		  (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_IMME_BA_CAP)
//#define RT_OID_802_11_ADD_IMME_BA_CAP         (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_IMME_BA_CAP)
#define RT_OID_802_11_ADD_IMME_BA             (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_BATABLE)
#define RT_OID_802_11_TEAR_IMME_BA            (OID_GET_SET_TOGGLE | 0x0D71013a)
#define RT_OID_802_11_QUERY_HT_PHYMODE    0x0D71013b
#define RT_OID_802_11_SET_HT_PHYMODE      (OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_HT_PHYMODE)

#define RT_OID_802_11_QUERY_IEEE80211H			0x0D710128
#define RT_OID_802_11_SET_IEEE80211H			(OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_IEEE80211H)

#define RT_OID_802_11_QUERY_EDCCA			0xFF71019A
#define RT_OID_802_11_SET_EDCCA			(OID_GET_SET_TOGGLE | RT_OID_802_11_QUERY_EDCCA)

#define MAX_LEN_OF_BA_ORI_TABLE               32
#define MAX_LEN_OF_BA_REC_TABLE               32

#define RFIC_2820                   1       // 2.4G 2T3R
#define RFIC_2850                   2       // 2.4G/5G 2T3R
#define RFIC_2720                   3       // 2.4G 1T2R
#define RFIC_2750                   4       // 2.4G/5G 1T2R
#define RFIC_3020                   5       // 2.4G/5G 1T1R
#define RFIC_2020                   6       // 2.4G B/G

#define TxHTSetting 0
#define RxHTSetting 1

typedef enum _RT_802_11_PREAMBLE {
    Rt802_11PreambleLong,
    Rt802_11PreambleShort,
    Rt802_11PreambleAuto
} RT_802_11_PREAMBLE, *PRT_802_11_PREAMBLE;

typedef enum _RT_802_11_PHY_MODE {
    PHY_11BG_MIXED,
    PHY_11B,
    PHY_11A,
    PHY_11ABG_MIXED,
    PHY_11G,
    PHY_11ABGN_MIXED,   
    PHY_11N,  
    PHY_11GN_MIXED,
    PHY_11AN_MIXED,
    PHY_11BGN_MIXED,
    PHY_11AGN_MIXED,
	PHY_11VHT, // VHT (HT on 2.4GHz and HT/VHT on 5GHz)
	PHY_11VHT5G_ONLY, // VHT (2.4GHz disabled, only operate HT/VHT on 5GHz)
	PHY_11MAX
} RT_802_11_PHY_MODE;

// 2006/07/06 Shufen : Add
typedef enum _RT_802_11_ADHOC_MODE {
    ADHOC_11B,
    ADHOC_11BG_MIXED,
    ADHOC_11G,
    ADHOC_11A,
	ADHOC_11ABG_MIXED,
    ADHOC_11ABGN_MIXED,   
    ADHOC_11N,
    ADHOC_11GN_MIXED,
    ADHOC_11AN_MIXED,
    ADHOC_11BGN_MIXED,
    ADHOC_11AGN_MIXED,
} RT_802_11_ADHOC_MODE;

typedef enum _RAWLAN_STATUS
{
	RaStatus_Device_Inactive,
	RaStatus_Radio_Off,
	RaStatus_Disconnected,
	RaStatus_Connected
} RAWLAN_STATUS, *PRAWLAN_STATUS;

// put all proprietery for-query objects here to reduce # of Query_OID
typedef struct _RT_802_11_LINK_STATUS {
    ULONG   CurrTxRate;         // in units of 0.5Mbps
    ULONG   ChannelQuality;     // 0..100 %
    ULONG   TxByteCount;        // both ok and fail
    ULONG   RxByteCount;        // both ok and fail
	ULONG   CentralChannel;        //  40MHz central channel
} RT_802_11_LINK_STATUS, *PRT_802_11_LINK_STATUS;

// put all proprietery for-query objects here to reduce # of Query_OID
typedef struct _RT_802_11_LEGACY_LINK_STATUS {
    ULONG   CurrTxRate;         // in units of 0.5Mbps
    ULONG   ChannelQuality;     // 0..100 %
    ULONG   TxByteCount;        // both ok and fail
    ULONG   RxByteCount;        // both ok and fail
} RT_802_11_LEGACY_LINK_STATUS, *PRT_802_11_LEGACY_LINK_STATUS;

typedef struct _RT_802_11_EVENT_LOG {
    LARGE_INTEGER   SystemTime;  // timestammp via NdisGetCurrentSystemTime()
    UCHAR           Addr[ETH_LENGTH_OF_ADDRESS];
    USHORT          Event;       // EVENT_xxx
} RT_802_11_EVENT_LOG, *PRT_802_11_EVENT_LOG;

typedef struct _RT_802_11_EVENT_TABLE {
    ULONG       Num;
    ULONG       Rsv;     // to align Log[] at LARGE_INEGER boundary
    RT_802_11_EVENT_LOG   Log[MAX_NUM_OF_EVENT];
} RT_802_11_EVENT_TABLE, PRT_802_11_EVENT_TABLE;

// All PHY rate summary in TXD
// Preamble MODE in TxD
#define MODE_CCK 0
#define MODE_OFDM   1
#define MODE_HTMIX 2
#define MODE_HTGREENFIELD 3

typedef union  _HTTRANSMIT_SETTING {
	struct {
#ifdef __BIG_ENDIAN__
		ULONG  rev2:16;
		ULONG  MODE:2; // 0: CCK, 1:OFDM, 2:Mixedmode, 3:GreenField
		ULONG  rsv1:1;
		ULONG  bITxBfPacket:1; // Apply the beamforming matrix of the explicit TxBf
		ULONG  bETxBfPacket:1; // Apply the beamforming matrix of the explicit TxBf
		ULONG  STBC:2; //SPACE 
		ULONG  ShortGI:1;
		ULONG  BW:1; //channel bandwidth 20MHz or 40 MHz
		ULONG  MCS:7;                 // MCS
#else
		ULONG  MCS:7;                 // MCS
		ULONG  BW:1; //channel bandwidth 20MHz or 40 MHz
		ULONG  ShortGI:1;
		ULONG  STBC:2; //SPACE 
		ULONG  bETxBfPacket:1; // Apply the beamforming matrix of the explicit TxBf
		ULONG  bITxBfPacket:1; // Apply the beamforming matrix of the implicit TxBf
		ULONG  rsv1:1;
		ULONG  MODE:2; // 0: CCK, 1:OFDM, 2:Mixedmode, 3:GreenField
		ULONG  rsv2:16; // 0: CCK, 1:OFDM, 2:Mixedmode, 3:GreenField
#endif
	} field;
	struct {
#ifdef __BIG_ENDIAN__
		ULONG	Reserved:13; // Reserved
		ULONG	Nss:2; // Nss, NSS_XXX
		ULONG	MODE:3;	// Phy mode, MODE_XXX
		ULONG	bETxBfPacket:1; // Apply the beamforming matrix of the explicit TxBf
		ULONG	bITxBfPacket:1; // Apply the beamforming matrix of the implicit TxBf
		ULONG	STBC:1; // STBC
		ULONG	ShortGI:1; // Short GI
		ULONG	BW:3; // Bandwidth, BW_XXX
		ULONG	MCS:7; // MCS, MCS_XXX
#else
		ULONG	MCS:7; // MCS, MCS_XXX
		ULONG	BW:3; // Bandwidth, BW_XXX
		ULONG	ShortGI:1; // Short GI
		ULONG	STBC:1; // STBC
		ULONG	bITxBfPacket:1; // Apply the beamforming matrix of the implicit TxBf
		ULONG	bETxBfPacket:1; // Apply the beamforming matrix of the explicit TxBf
		ULONG	MODE:3;	// Phy mode, MODE_XXX
		ULONG	NSS:2; // Nss, NSS_XXX
		ULONG	rsv:13; // Reserved
#endif
	} Ext;
	
	ULONG  DoubleWord;
} HTTRANSMIT_SETTING, *PHTTRANSMIT_SETTING;//mapping to driver struct PHY_CFG

typedef struct _RT_802_11_MAC_ENTRY {
    UCHAR       Addr[ETH_LENGTH_OF_ADDRESS];
    UCHAR       Aid;
    UCHAR       Psm;     // 0:PWR_ACTIVE, 1:PWR_SAVE
    HTTRANSMIT_SETTING TxRate;
} RT_802_11_MAC_ENTRY, *PRT_802_11_MAC_ENTRY;

typedef struct _RT_802_11_MAC_TABLE {
    ULONG       Num;
    RT_802_11_MAC_ENTRY Entry[MAX_LEN_OF_MAC_TABLE];
} RT_802_11_MAC_TABLE, *PRT_802_11_MAC_TABLE;

// structure for query/set hardware register - MAC, BBP, RF register
typedef struct _RT_802_11_HARDWARE_REGISTER {
    ULONG   HardwareType;       // 0:MAC, 1:BBP, 2:RF register
    ULONG   Offset;             // Q/S register offset addr
    ULONG   Data;               // R/W data buffer
} RT_802_11_HARDWARE_REGISTER, *PRT_802_11_HARDWARE_REGISTER;

// structure for set RF register
typedef struct _RT_802_11_RF_REGISTER {
    ULONG   R1Value;			
    ULONG   R2Value;			
    ULONG   R3Value;			
    ULONG   R4Value;			
	ULONG	EnableRFTuning;	// 0x00000001: Enable RF tunning, 0x00000000: Disable RF tunning
} RT_802_11_RF_REGISTER, *PRT_802_11_RF_REGISTER;

// structure to tune BBP R17 "RX AGC VGC init"
typedef struct _RT_802_11_RX_AGC_VGC_TUNING {
    UCHAR   FalseCcaLowerThreshold;  // 0-255, def 10
    UCHAR   FalseCcaUpperThreshold;  // 0-255, def 100
    UCHAR   VgcDelta;                // R17 +-= VgcDelta whenever flase CCA over UpprThreshold
                                     // or lower than LowerThresholdupper threshold
    UCHAR   VgcUpperBound;           // max value of R17
} RT_802_11_RX_AGC_VGC_TUNING, *PRT_802_11_RX_AGC_VGC_TUNING;

// structure to define Radius Data
typedef struct _RT_802_11_RADIUS_DATA {
	DWORD RediusIP;				// Radius Server IP Address
	ULONG RediusPort;           // Radius Server Port
	UCHAR RediusKey[64];
}RT_802_11_RADIUS_DATA, *PRT_802_11_RADIUS_DATA;

// structure to define WPA Group Key Rekey Interval
typedef struct _RT_802_11_WPA_REKEY {
	ULONG ReKeyMethod;          // mechanism for rekeying: 0: time-based, 1: packet-based
	ULONG ReKeyInterval;		// time-based: 10seconds, packet-based: kilo-packets
}RT_802_11_WPA_REKEY, *PRT_802_11_WPA_REKEY;

typedef struct _RT_802_11_AP_CONFIG {
    ULONG   EnableTxBurst;      // 0-disable, 1-enable
    ULONG   EnableTurboRate;    // 0-disable, 1-enable 72/100mbps turbo rate
    ULONG   IsolateInterStaTraffic;     // 0-disable, 1-enable isolation
    ULONG   HideSsid;           // 0-disable, 1-enable hiding
    ULONG   UseBGProtection;    // 0-AUTO, 1-always ON, 2-always OFF
    ULONG   UseShortSlotTime;   // 0-no use, 1-use 9-us short slot time
	USHORT	AgeoutTime;			// default 300, unit : sec
    USHORT  Rsv1;               // must be 0
    ULONG   SystemErrorBitmap;  // ignore upon SET, return system error upon QUERY
} RT_802_11_AP_CONFIG, *PRT_802_11_AP_CONFIG;

// structure to query/set STA_CONFIG
typedef struct _RT_802_11_STA_CONFIG {
    ULONG   bEnableTxBurst;      // 0-disable, 1-enable
    ULONG   EnableTurboRate;    // 0-disable, 1-enable 72/100mbps turbo rate
    ULONG   UseBGProtection;    // 0-AUTO, 1-always ON, 2-always OFF
    ULONG   UseShortSlotTime;   // 0-no use, 1-use 9-us short slot time when applicable
    ULONG   AdhocMode; // 0-11b rates only (WIFI spec), 1 - allow B/G rates, 2 - G Only, 3 - A only, 4 - allow A/B/G rates and channel
    ULONG   HwRadioStatus;      // 0-OFF, 1-ON, default is 1, Read-Only
    ULONG   Rsv1;        		// must be 0
    ULONG   SystemErrorBitmap;  // ignore upon SET, return system error upon QUERY
} RT_802_11_STA_CONFIG, *PRT_802_11_STA_CONFIG;

typedef struct _RT_802_11_ACL_ENTRY {
    UCHAR   Addr[ETH_LENGTH_OF_ADDRESS];
    USHORT  Rsv;
} RT_802_11_ACL_ENTRY, *PRT_802_11_ACL_ENTRY;

typedef struct _RT_802_11_ACL {
    ULONG   Policy;             // 0-disable, 1-positive list, 2-negative list
    ULONG   Num;
    RT_802_11_ACL_ENTRY Entry[MAX_LEN_OF_MAC_TABLE];
} RT_802_11_ACL, *PRT_802_11_ACL;

typedef struct _RT_802_11_WDS {
    ULONG   Num;
    NDIS_802_11_MAC_ADDRESS MacAddress[3];
	ULONG	KeyLength;
	UCHAR	KeyMaterial[32];
} RT_802_11_WDS, *PRT_802_11_WDS;

typedef struct _LEAP_AUTH_INFO {
	Boolean	Enabled;
	Boolean	CCKM;
	UCHAR   Reserved[2];
	UCHAR   UserName[256];
    ULONG   UserNameLen;
	UCHAR	Password[256];
    ULONG   PasswordLen;
	UCHAR	DomainName[256];
	ULONG	DomainNameLen;
} LEAP_AUTH_INFO, *PLEAP_AUTH_INFO;

// CCX administration control
typedef	union	_CCX2_CONTROL	{
	struct	{
		ULONG		Enable:1;			// Enable CCX2
		ULONG		LeapEnable:1;		// Enable LEAP at CCX2
		ULONG		RMEnable:1;			// Radio Measurement Enable
		ULONG		DCRMEnable:1;		// Non serving channel Radio Measurement enable
		ULONG		QOSEnable:1;		// Enable QOS for CCX 2.0 support
		ULONG		FastRoamEnable:1;	// Enable fast roaming
		ULONG		Rsvd:2;				// Not used
		ULONG		dBmToRoam:8;		// the condition to roam when receiving Rssi less than this value. It's negative value.
		ULONG		TuLimit:16;			// Limit for different channel scan
	}	field;
	ULONG			word;
}	CCX2_CONTROL, *PCCX2_CONTROL;


#define MAX_LEN_OF_SUPPORTED_RATES      12    // 1, 2, 5.5, 11, 6, 9, 12, 18, 24, 36, 48, 54
typedef struct _RT_802_11_TX_RATES_ {
    UCHAR       SupRateLen;	
    UCHAR       SupRate[MAX_LEN_OF_SUPPORTED_RATES];
    UCHAR       ExtRateLen;	
    UCHAR       ExtRate[MAX_LEN_OF_SUPPORTED_RATES];
} RT_802_11_TX_RATES, *PRT_802_11_TX_RATES;

// structure for DLS
typedef struct _RT_802_11_DLS {
 USHORT						TimeOut;		// unit: second , set by UI
 USHORT						CountDownTimer;	// unit: second , used by driver only
 NDIS_802_11_MAC_ADDRESS	MacAddr;		// set by UI
 UCHAR						Status;			//  set by driver only
 Boolean					Valid;			// 1: valid , 0: invalid , set by UI, use to setup or tear down DLS link
} RT_802_11_DLS, *PRT_802_11_DLS;

typedef enum _RT_802_11_DLS_MODE {
    DLS_NONE,
    DLS_WAIT_KEY,
    DLS_FINISH
} RT_802_11_DLS_MODE;

// 2006/01/23 Block Ack added by Shufen

typedef enum _ORI_BLOCKACK_STATUS
{
	Originator_NONE,
	Originator_WaitRes,
	Originator_Done
} ORI_BLOCKACK_STATUS, *PORI_BLOCKACK_STATUS;

typedef enum _REC_BLOCKACK_STATUS
{
    Recipient_NONE,
    Recipient_Accept
} REC_BLOCKACK_STATUS, *PREC_BLOCKACK_STATUS;

typedef struct {
 Boolean  IsRecipient;  // If True, I want to add/tear-down BA session with {MACAddr, TID}. I am Recipient. Peer is Originator.
 NDIS_802_11_MAC_ADDRESS   MACAddr;
 UCHAR   TID;
 UCHAR   BufSize;
 USHORT   TimeOut;
 Boolean AllTid;  // If True, delete all TID BA session with this MACaddr. 
} OID_ADD_BA_ENTRY, *POID_ADD_BA_ENTRY;

typedef struct  _OID_BA_REC_ENTRY{
 NDIS_802_11_MAC_ADDRESS   MACAddr;
 UCHAR   BaBitmap;   // if (BaBitmap&(1<<TID)), this session with {MACAddr, TID}exists, so read BufSize[TID] for BufferSize., read ORI_BA_Status[TID] for status
 UCHAR   rsv;
 UCHAR   BufSize[8];  
 REC_BLOCKACK_STATUS REC_BA_Status[8];
} OID_BA_REC_ENTRY, *POID_BA_REC_ENTRY;

typedef struct  _OID_BA_ORI_ENTRY{
 NDIS_802_11_MAC_ADDRESS   MACAddr;
 UCHAR   BaBitmap; // if (BaBitmap&(1<<TID)), this session with {MACAddr, TID}exists, so read BufSize[TID] for BufferSize., read ORI_BA_Status[TID] for status
 UCHAR   rsv;
 UCHAR   BufSize[8];
 ORI_BLOCKACK_STATUS  ORI_BA_Status[8];
} OID_BA_ORI_ENTRY, *POID_BA_ORI_ENTRY;
 
typedef struct _QUERYBA_TABLE
{
	OID_BA_ORI_ENTRY    BAOriEntry[MAX_LEN_OF_BA_ORI_TABLE];
	OID_BA_REC_ENTRY    BARecEntry[MAX_LEN_OF_BA_REC_TABLE];
    UCHAR				OriNum;
	UCHAR				RecNum;
} QUERYBA_TABLE, *PQUERYBA_TABLE;

typedef struct _OID_BACAP_STRUC
{
  UCHAR  RxBAWinLimit;
  UCHAR  TxBAWinLimit;
  UCHAR  Policy; // 0: DELAY_BA 1:IMMED_BA  (//BA Policy subfiled value in ADDBA frame)   2:BA-not use. other value invalid
  UCHAR  MpduDensity; // 
  UCHAR        AmsduEnable; //Enable AMSDU transmisstion
  UCHAR        AmsduSize; // 0: 3839 bytes, 1:7935 bytes. UINT  MSDUSizeToBytes[] = { 3839, 7935};
  UCHAR        MMPSmode; // MIMO power save more, 0:static, 1:dynamic, 2:rsv, 3:mimo enable
  Boolean  AutoBA; // Auto BA will automatically    <===  put AutoBA at last 
} OID_BACAP_STRUC, *POID_BACAP_STRUC;

typedef union _BACAP_STRUC {
 struct {
  ULONG  RxBAWinLimit:8;
  ULONG  TxBAWinLimit:8;
  ULONG  AutoBA:1; // automatically BA   
  ULONG  Policy:2; // 0: DELAY_BA 1:IMMED_BA  (//BA Policy subfiled value in ADDBA frame)   2:BA-not use
  ULONG  MpduDensity:3; //  valid value 0-7
  ULONG  AmsduEnable:1; //Enable AMSDU transmisstion
  ULONG  AmsduSize:1; // 0:3839, 1:7935 bytes. UINT  MSDUSizeToBytes[] = { 3839, 7935};
  ULONG  MMPSmode:2; // MIMO power save more, 0:static, 1:dynamic, 2:rsv, 3:mimo enable
  ULONG  :6; 
 } field;

 ULONG   word;
} BACAP_STRUC, *PBACAP_STRUC;

//
// PHY mode in TxWI and RxWI
//
// Note: Reserved (5~7)
//
#define MODE_CCK			0 // CCK
#define MODE_OFDM			1 // OFDM
#define MODE_HTMIX			2 // HT mixed mode
#define MODE_HTGREENFIELD	3 // HT green field
#define MODE_VHT			4 // VHT

// MIMO power safe 
#define MMPS_STATIC 0
#define MMPS_DYNAMIC  1
#define   MMPS_RSV  2
#define   MMPS_ENABLE  3
// A-MSDU size
#define AMSDU_0 0
#define AMSDU_1  1

// 802.11 HT PHY MODE


// HtMode
#define HTMODE_MM 0
#define HTMODE_GF 1 
// ExtOffset
#define EXTCHA_NONE 0  
#define EXTCHA_ABOVE 0x1
#define EXTCHA_BELOW 0x3
// BW
#define BW_20       0
#define BW_40       1
#define BW_80       2
#define BW_160      3
#define BW_10       4
// SHORTGI
#define GI_400      1 // only support in HT mode
#define GI_800      0 
// STBC
#define STBC_NONE   0
#define STBC_USE    1 // limited use in rt2860b phy

typedef struct { 
 RT_802_11_PHY_MODE  PhyMode;  // ?ﾠￃﾏ￢ﾀﾢￂ?RT_OID_802_11_SET_PHY_MODEￂﾮ??ﾢￅﾒ￢ﾄﾢ??
 UCHAR  TransmitNo;     //  =1 or 2 since rt2860 is 2T3R at maximum.  Now use 2.
 UCHAR  HtMode;   //see below definition. GF or MM. Now set HTMODE_GF.
 UCHAR  ExtOffset;    //extension channel lies above or below control channel. see below definition.
 UCHAR  MCS; // see below
 UCHAR  BW;
 UCHAR  STBC;
 UCHAR  SHORTGI;
 UCHAR  rsv;
} OID_SET_HT_PHYMODE, *POID_SET_HT_PHYMODE;

typedef union _TRANSMIT_SETTING {
 struct {
         ULONG  PhyMode:4;                
         ULONG  MCS:7;                 // MCS
         ULONG  BW:1; //channel bandwidth 20MHz or 40 MHz
         ULONG  ShortGI:1;
         ULONG  STBC:1; //SPACE 
         ULONG  TRANSNO:2; 
         ULONG  HTMODE:1;
         ULONG  EXTCHA:2;
         ULONG        :13;
    } field;
 ULONG   word;
} TRANSMIT_SETTING, *PTRANSMIT_SETTING;

#define RT_OID_802_11_SNR_0      0x0D710135
#define RT_OID_802_11_SNR_1      0x0D710136
#define RT_OID_CHECK_DEVICE_TERMINATE          0xFF710199


// Definition of extra information code
#define	GENERAL_LINK_UP			0x0			// Link is Up
#define	GENERAL_LINK_DOWN		0x1			// Link is Down
#define	HW_RADIO_OFF			0x2			// Hardware radio off
#define	SW_RADIO_OFF			0x3			// Software radio off
#define	AUTH_FAIL				0x4			// Open authentication fail
#define	AUTH_FAIL_KEYS			0x5			// Shared authentication fail
#define	ASSOC_FAIL				0x6			// Association failed
#define	EAP_MIC_FAILURE			0x7			// Deauthencation because MIC failure
#define	EAP_4WAY_TIMEOUT		0x8			// Deauthencation on 4-way handshake timeout
#define	EAP_GROUP_KEY_TIMEOUT	0x9			// Deauthencation on group key handshake timeout
#define	EAP_SUCCESS				0xa			// EAP succeed
#define	EXTRA_INFO_MAX			0xa			// EXTRA INFO MAX

// group rekey interval
#define TIME_REKEY                          0
#define PKT_REKEY                           1
#define DISABLE_REKEY                       2
#define MAX_REKEY                           2

// definition of pAd->OpMode
#define OPMODE_STA                  0
#define OPMODE_AP                   1

#endif
