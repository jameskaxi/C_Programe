/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-b00.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER -pdu=auto`
 */

#ifndef	_UECapabilityInformation_r8_IEs_H_
#define	_UECapabilityInformation_r8_IEs_H_


#include "asn_application.h"

/* Including external dependencies */
#include "UE-CapabilityRAT-ContainerList.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct UECapabilityInformation_v8a0_IEs;

/* UECapabilityInformation-r8-IEs */
typedef struct UECapabilityInformation_r8_IEs {
	UE_CapabilityRAT_ContainerList_t	 ue_CapabilityRAT_ContainerList;
	struct UECapabilityInformation_v8a0_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UECapabilityInformation_r8_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UECapabilityInformation_r8_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "UECapabilityInformation-v8a0-IEs.h"

#endif	/* _UECapabilityInformation_r8_IEs_H_ */
#include "asn_internal.h"