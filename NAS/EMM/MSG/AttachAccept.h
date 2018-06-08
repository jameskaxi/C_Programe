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
#include "EpsAttachResult.h"
#include "GprsTimer.h"
#include "GprsTimer3.h"
#include "TrackingAreaIdentityList.h"
#include "EsmMessageContainer.h"
#include "EpsMobileIdentity.h"
#include "LocationAreaIdentification.h"
#include "MobileIdentity.h"
#include "EmmCause.h"
#include "PlmnList.h"
#include "EmergencyNumberList.h"
#include "EpsNetworkFeatureSupport.h"
#include "AdditionalUpdateResult.h"

#ifndef ATTACH_ACCEPT_H_
#define ATTACH_ACCEPT_H_

/* Minimum length macro. Formed by minimum length of each mandatory field */
#define ATTACH_ACCEPT_MINIMUM_LENGTH ( \
    EPS_ATTACH_RESULT_MINIMUM_LENGTH + \
    GPRS_TIMER_MINIMUM_LENGTH + \
    TRACKING_AREA_IDENTITY_LIST_MINIMUM_LENGTH + \
    ESM_MESSAGE_CONTAINER_MINIMUM_LENGTH )

/* Maximum length macro. Formed by maximum length of each field */
#define ATTACH_ACCEPT_MAXIMUM_LENGTH ( \
    EPS_ATTACH_RESULT_MAXIMUM_LENGTH + \
    GPRS_TIMER_MAXIMUM_LENGTH + \
    TRACKING_AREA_IDENTITY_LIST_MAXIMUM_LENGTH + \
    ESM_MESSAGE_CONTAINER_MAXIMUM_LENGTH + \
    EPS_MOBILE_IDENTITY_MAXIMUM_LENGTH + \
    LOCATION_AREA_IDENTIFICATION_MAXIMUM_LENGTH + \
    MOBILE_IDENTITY_MAXIMUM_LENGTH + \
    EMM_CAUSE_MAXIMUM_LENGTH + \
    GPRS_TIMER_MAXIMUM_LENGTH + \
    GPRS_TIMER_MAXIMUM_LENGTH + \
    PLMN_LIST_MAXIMUM_LENGTH + \
    EMERGENCY_NUMBER_LIST_MAXIMUM_LENGTH + \
    EPS_NETWORK_FEATURE_SUPPORT_MAXIMUM_LENGTH + \
    ADDITIONAL_UPDATE_RESULT_MAXIMUM_LENGTH +\
	GPRS_TIMER3_MAXIMUM_LENGTH) //add 20180502,by:pu

/* If an optional value is present and should be encoded, the corresponding
 * Bit mask should be set to 1.
 */
# define ATTACH_ACCEPT_GUTI_PRESENT                         (1<<0)
# define ATTACH_ACCEPT_LOCATION_AREA_IDENTIFICATION_PRESENT (1<<1)
# define ATTACH_ACCEPT_MS_IDENTITY_PRESENT                  (1<<2)
# define ATTACH_ACCEPT_EMM_CAUSE_PRESENT                    (1<<3)
# define ATTACH_ACCEPT_T3402_VALUE_PRESENT                  (1<<4)
# define ATTACH_ACCEPT_T3423_VALUE_PRESENT                  (1<<5)
# define ATTACH_ACCEPT_EQUIVALENT_PLMNS_PRESENT             (1<<6)
# define ATTACH_ACCEPT_EMERGENCY_NUMBER_LIST_PRESENT        (1<<7)
# define ATTACH_ACCEPT_EPS_NETWORK_FEATURE_SUPPORT_PRESENT  (1<<8)
# define ATTACH_ACCEPT_ADDITIONAL_UPDATE_RESULT_PRESENT     (1<<9)
# define ATTACH_ACCEPT_T3412_EXTENDED_VALUE_PRESENT         (1<<10) //release 11, add:2018.04.29 by:pu

typedef enum attach_accept_iei_tag {
  ATTACH_ACCEPT_GUTI_IEI                          = 0x50, /* 0x50 = 80 */
  ATTACH_ACCEPT_LOCATION_AREA_IDENTIFICATION_IEI  = 0x13, /* 0x13 = 19 */
  ATTACH_ACCEPT_MS_IDENTITY_IEI                   = 0x23, /* 0x23 = 35 */
  ATTACH_ACCEPT_EMM_CAUSE_IEI                     = 0x53, /* 0x53 = 83 */
  ATTACH_ACCEPT_T3402_VALUE_IEI                   = 0x17, /* 0x17 = 23 */
  ATTACH_ACCEPT_T3423_VALUE_IEI                   = 0x59, /* 0x59 = 89 */
  ATTACH_ACCEPT_EQUIVALENT_PLMNS_IEI              = 0x4A, /* 0x4A = 74 */
  ATTACH_ACCEPT_EMERGENCY_NUMBER_LIST_IEI         = 0x34, /* 0x34 = 52 */
  ATTACH_ACCEPT_EPS_NETWORK_FEATURE_SUPPORT_IEI   = 0x64, /* 0x64 = 100 */
  ATTACH_ACCEPT_ADDITIONAL_UPDATE_RESULT_IEI      = 0xF0, /* 0xF0 = 240 */
  ATTACH_ACCEPT_T3412_EXTENDED_VALUE_IEI		  = 0x5E, /* 0x5E = 94 release 11, add:2018.04.29 by:pu */
} attach_accept_iei;

/*
 * Message name: Attach accept
 * Description: This message is sent by the network to the UE to indicate that the corresponding attach request has been accepted. See table 8.2.1.1.
 * Significance: dual
 * Direction: network to UE
 */

typedef struct attach_accept_msg_tag {
  /* Mandatory fields */
  ProtocolDiscriminator       protocoldiscriminator:4;
  SecurityHeaderType          securityheadertype:4;
  MessageType                 messagetype;
  EpsAttachResult             epsattachresult;
  GprsTimer                   t3412value;
  TrackingAreaIdentityList    tailist;
  EsmMessageContainer         esmmessagecontainer;
  /* Optional fields */
  uint32_t                    presencemask;
  EpsMobileIdentity           guti;
  LocationAreaIdentification  locationareaidentification;
  MobileIdentity              msidentity;
  EmmCause                    emmcause;
  GprsTimer                   t3402value;
  GprsTimer                   t3423value;
  PlmnList                    equivalentplmns;
  EmergencyNumberList         emergencynumberlist;
  EpsNetworkFeatureSupport    epsnetworkfeaturesupport;
  AdditionalUpdateResult      additionalupdateresult;
  GprsTimer3				  t3412extendedvalue;
} attach_accept_msg;

int decode_attach_accept(attach_accept_msg *attachaccept, uint8_t *buffer, uint32_t len);

int encode_attach_accept(attach_accept_msg *attachaccept, uint8_t *buffer, uint32_t len);

#endif /* ! defined(ATTACH_ACCEPT_H_) */

