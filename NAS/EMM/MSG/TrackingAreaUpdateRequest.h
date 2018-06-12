/*
 * Copyright (c) 2015, EURECOM (www.eurecom.fr)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the FreeBSD Project.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "ProtocolDiscriminator.h"
#include "SecurityHeaderType.h"
#include "MessageType.h"
#include "EpsUpdateType.h"
#include "NasKeySetIdentifier.h"
#include "EpsMobileIdentity.h"
#include "CipheringKeySequenceNumber.h"
#include "PTmsiSignature.h"
#include "Nonce.h"
#include "UeNetworkCapability.h"
#include "TrackingAreaIdentity.h"
#include "DrxParameter.h"
#include "UeRadioCapabilityInformationUpdateNeeded.h"
#include "EpsBearerContextStatus.h"
#include "MsNetworkCapability.h"
#include "LocationAreaIdentification.h"
#include "TmsiStatus.h"
#include "MobileStationClassmark2.h"
#include "MobileStationClassmark3.h"
#include "SupportedCodecList.h"
#include "AdditionalUpdateType.h"
#include "GutiType.h"
#include "VoiceDomainPreferenceAndUeUsageSetting.h"
#include "DeviceProperties.h"
#include "MsNetworkFeatureSupport.h"
#include "NetworkResourceIdentifierContainer.h"

#ifndef TRACKING_AREA_UPDATE_REQUEST_H_
#define TRACKING_AREA_UPDATE_REQUEST_H_

/* Minimum length macro. Formed by minimum length of each mandatory field */
#define TRACKING_AREA_UPDATE_REQUEST_MINIMUM_LENGTH ( \
    EPS_UPDATE_TYPE_MINIMUM_LENGTH + \
    NAS_KEY_SET_IDENTIFIER_MINIMUM_LENGTH + \
    EPS_MOBILE_IDENTITY_MINIMUM_LENGTH )

/* Maximum length macro. Formed by maximum length of each field */
#define TRACKING_AREA_UPDATE_REQUEST_MAXIMUM_LENGTH ( \
    EPS_UPDATE_TYPE_MAXIMUM_LENGTH + \
    NAS_KEY_SET_IDENTIFIER_MAXIMUM_LENGTH + \
    EPS_MOBILE_IDENTITY_MAXIMUM_LENGTH + \
    NAS_KEY_SET_IDENTIFIER_MAXIMUM_LENGTH + \
    CIPHERING_KEY_SEQUENCE_NUMBER_MAXIMUM_LENGTH + \
    P_TMSI_SIGNATURE_MAXIMUM_LENGTH + \
    EPS_MOBILE_IDENTITY_MAXIMUM_LENGTH + \
    NONCE_MAXIMUM_LENGTH + \
    UE_NETWORK_CAPABILITY_MAXIMUM_LENGTH + \
    TRACKING_AREA_IDENTITY_MAXIMUM_LENGTH + \
    DRX_PARAMETER_MAXIMUM_LENGTH + \
    UE_RADIO_CAPABILITY_INFORMATION_UPDATE_NEEDED_MAXIMUM_LENGTH + \
    EPS_BEARER_CONTEXT_STATUS_MAXIMUM_LENGTH + \
    MS_NETWORK_CAPABILITY_MAXIMUM_LENGTH + \
    LOCATION_AREA_IDENTIFICATION_MAXIMUM_LENGTH + \
    TMSI_STATUS_MAXIMUM_LENGTH + \
    MOBILE_STATION_CLASSMARK_2_MAXIMUM_LENGTH + \
    MOBILE_STATION_CLASSMARK_3_MAXIMUM_LENGTH + \
    SUPPORTED_CODEC_LIST_MAXIMUM_LENGTH + \
    ADDITIONAL_UPDATE_TYPE_MAXIMUM_LENGTH + \
	VOICE_DOMAIN_PREFERENCE_AND_UE_USAGE_SETTING_MAXIMUM_LENGTH + \
	DEVICE_PROPERTIES_MAXIMUM_LENGTH + \
	MS_NETWORK_FEATURE_SUPPORT_MAXIMUM_LENGTH + \
	NETWORK_RESOURCE_IDENTIFIER_CONTAINER_MAXIMUM_LENGTH)

/* If an optional value is present and should be encoded, the corresponding
 * Bit mask should be set to 1.
 */
# define TRACKING_AREA_UPDATE_REQUEST_NONCURRENT_NATIVE_NAS_KEY_SET_IDENTIFIER_PRESENT      (1<<0)
# define TRACKING_AREA_UPDATE_REQUEST_GPRS_CIPHERING_KEY_SEQUENCE_NUMBER_PRESENT            (1<<1)
# define TRACKING_AREA_UPDATE_REQUEST_OLD_PTMSI_SIGNATURE_PRESENT                           (1<<2)
# define TRACKING_AREA_UPDATE_REQUEST_ADDITIONAL_GUTI_PRESENT                               (1<<3)
# define TRACKING_AREA_UPDATE_REQUEST_NONCEUE_PRESENT                                       (1<<4)
# define TRACKING_AREA_UPDATE_REQUEST_UE_NETWORK_CAPABILITY_PRESENT                         (1<<5)
# define TRACKING_AREA_UPDATE_REQUEST_LAST_VISITED_REGISTERED_TAI_PRESENT                   (1<<6)
# define TRACKING_AREA_UPDATE_REQUEST_DRX_PARAMETER_PRESENT                                 (1<<7)
# define TRACKING_AREA_UPDATE_REQUEST_UE_RADIO_CAPABILITY_INFORMATION_UPDATE_NEEDED_PRESENT (1<<8)
# define TRACKING_AREA_UPDATE_REQUEST_EPS_BEARER_CONTEXT_STATUS_PRESENT                     (1<<9)
# define TRACKING_AREA_UPDATE_REQUEST_MS_NETWORK_CAPABILITY_PRESENT                         (1<<10)
# define TRACKING_AREA_UPDATE_REQUEST_OLD_LOCATION_AREA_IDENTIFICATION_PRESENT              (1<<11)
# define TRACKING_AREA_UPDATE_REQUEST_TMSI_STATUS_PRESENT                                   (1<<12)
# define TRACKING_AREA_UPDATE_REQUEST_MOBILE_STATION_CLASSMARK_2_PRESENT                    (1<<13)
# define TRACKING_AREA_UPDATE_REQUEST_MOBILE_STATION_CLASSMARK_3_PRESENT                    (1<<14)
# define TRACKING_AREA_UPDATE_REQUEST_SUPPORTED_CODECS_PRESENT                              (1<<15)
# define TRACKING_AREA_UPDATE_REQUEST_ADDITIONAL_UPDATE_TYPE_PRESENT                        (1<<16)
# define TRACKING_AREA_UPDATE_REQUEST_OLD_GUTI_TYPE_PRESENT                                 (1<<17)
# define TRACKING_AREA_UPDATE_REQUEST_VOICE_DOMAIN_PREFERENCE_AND_UE_USAGE_SETTING_PRESENT  (1<<18)
# define TRACKING_AREA_UPDATE_REQUEST_DEVICE_PROPERTIES_PRESENT                             (1<<19)
# define TRACKING_AREA_UPDATE_REQUEST_MS_NETWORK_FEATURE_SUPPORT_PRESENT                    (1<<20)
# define TRACKING_AREA_UPDATE_REQUEST_TMSI_BASED_NRI_CONTAINER_PRESENT                      (1<<21)


typedef enum tracking_area_update_request_iei_tag {
  TRACKING_AREA_UPDATE_REQUEST_NONCURRENT_NATIVE_NAS_KEY_SET_IDENTIFIER_IEI       = 0xB0, /* 0xB0 = 176 */
  TRACKING_AREA_UPDATE_REQUEST_GPRS_CIPHERING_KEY_SEQUENCE_NUMBER_IEI             = 0x80, /* 0x80 = 128 */
  TRACKING_AREA_UPDATE_REQUEST_OLD_PTMSI_SIGNATURE_IEI                            = 0x19, /* 0x19 = 25 */
  TRACKING_AREA_UPDATE_REQUEST_ADDITIONAL_GUTI_IEI                                = 0x50, /* 0x50 = 80 */
  TRACKING_AREA_UPDATE_REQUEST_NONCEUE_IEI                                        = 0x55, /* 0x55 = 85 */
  TRACKING_AREA_UPDATE_REQUEST_UE_NETWORK_CAPABILITY_IEI                          = 0x58, /* 0x58 = 88 */
  TRACKING_AREA_UPDATE_REQUEST_LAST_VISITED_REGISTERED_TAI_IEI                    = 0x52, /* 0x52 = 82 */
  TRACKING_AREA_UPDATE_REQUEST_DRX_PARAMETER_IEI                                  = 0x5C, /* 0x5C = 92 */
  TRACKING_AREA_UPDATE_REQUEST_UE_RADIO_CAPABILITY_INFORMATION_UPDATE_NEEDED_IEI  = 0xA0, /* 0xA0 = 160 */
  TRACKING_AREA_UPDATE_REQUEST_EPS_BEARER_CONTEXT_STATUS_IEI                      = 0x57, /* 0x57 = 87 */
  TRACKING_AREA_UPDATE_REQUEST_MS_NETWORK_CAPABILITY_IEI                          = 0x31, /* 0x31 = 49 */
  TRACKING_AREA_UPDATE_REQUEST_OLD_LOCATION_AREA_IDENTIFICATION_IEI               = 0x13, /* 0x13 = 19 */
  TRACKING_AREA_UPDATE_REQUEST_TMSI_STATUS_IEI                                    = 0x90, /* 0x90 = 144 */
  TRACKING_AREA_UPDATE_REQUEST_MOBILE_STATION_CLASSMARK_2_IEI                     = 0x11, /* 0x11 = 17 */
  TRACKING_AREA_UPDATE_REQUEST_MOBILE_STATION_CLASSMARK_3_IEI                     = 0x20, /* 0x20 = 32 */
  TRACKING_AREA_UPDATE_REQUEST_SUPPORTED_CODECS_IEI                               = 0x40, /* 0x40 = 64 */
  TRACKING_AREA_UPDATE_REQUEST_ADDITIONAL_UPDATE_TYPE_IEI                         = 0xF0, /* 0xF0 = 240 */
  TRACKING_AREA_UPDATE_REQUEST_OLD_GUTI_TYPE_IEI                                  = 0xE0, /* 0xE0 = 224 */
  TRACKING_AREA_UPDATE_REQUEST_VOICE_DOMAIN_PREFERENCE_AND_UE_USAGE_SETTING_IEI   = 0x5D,
  TRACKING_AREA_UPDATE_REQUEST_DEVICE_PROPERTIES_IEI						      = 0xD0,
  TRACKING_AREA_UPDATE_REQUEST_MS_NETWORK_FEATURE_SUPPORT_IEI                     = 0xC0,
  TRACKING_AREA_UPDATE_REQUEST_TMSI_BASED_NRI_CONTAINER_IEI                       = 0x10,
} tracking_area_update_request_iei;

/*
 * Message name: Tracking area update request
 * Description: The purposes of sending the tracking area update request by the UE to the network are described in subclause 5.5.3.1. See table 8.2.29.1.
 * Significance: dual
 * Direction: UE to network
 */

typedef struct tracking_area_update_request_msg_tag {
  /* Mandatory fields */
  ProtocolDiscriminator                    protocoldiscriminator:4;
  SecurityHeaderType                       securityheadertype:4;
  MessageType                              messagetype;
  EpsUpdateType                            epsupdatetype;
  NasKeySetIdentifier                      naskeysetidentifier;
  EpsMobileIdentity                        oldguti;
  /* Optional fields */
  uint32_t                                 presencemask;
  NasKeySetIdentifier                      noncurrentnativenaskeysetidentifier;
  CipheringKeySequenceNumber               gprscipheringkeysequencenumber;
  PTmsiSignature                           oldptmsisignature;
  EpsMobileIdentity                        additionalguti;
  Nonce                                    nonceue;
  UeNetworkCapability                      uenetworkcapability;
  TrackingAreaIdentity                     lastvisitedregisteredtai;
  DrxParameter                             drxparameter;
  UeRadioCapabilityInformationUpdateNeeded ueradiocapabilityinformationupdateneeded;
  EpsBearerContextStatus                   epsbearercontextstatus;
  MsNetworkCapability                      msnetworkcapability;
  LocationAreaIdentification               oldlocationareaidentification;
  TmsiStatus                               tmsistatus;
  MobileStationClassmark2                  mobilestationclassmark2;
  MobileStationClassmark3                  mobilestationclassmark3;
  SupportedCodecList                       supportedcodecs;
  AdditionalUpdateType                     additionalupdatetype;
  GutiType                                 oldgutitype;
  VoiceDomainPreferenceAndUeUsageSetting   voicedomianpreferenceandueusagesetting;
  DeviceProperties                         deviceproperties;
  MsNetworkFeatureSupport                  msnetworkfeaturesupport;
  NetworkResourceIdentifierContainer       tmsibasednricontainer;
} tracking_area_update_request_msg;

int decode_tracking_area_update_request(tracking_area_update_request_msg *trackingareaupdaterequest, uint8_t *buffer, uint32_t len);

int encode_tracking_area_update_request(tracking_area_update_request_msg *trackingareaupdaterequest, uint8_t *buffer, uint32_t len);

#endif /* ! defined(TRACKING_AREA_UPDATE_REQUEST_H_) */
