/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-b00.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER -pdu=auto`
 */

#ifndef	_UE_EUTRA_Capability_v1060_IEs_H_
#define	_UE_EUTRA_Capability_v1060_IEs_H_


#include "asn_application.h"

/* Including external dependencies */
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct UE_EUTRA_CapabilityAddXDD_Mode_v1060;
struct RF_Parameters_v1060;

/* UE-EUTRA-Capability-v1060-IEs */
typedef struct UE_EUTRA_Capability_v1060_IEs {
	struct UE_EUTRA_CapabilityAddXDD_Mode_v1060	*fdd_Add_UE_EUTRA_Capabilities_v1060	/* OPTIONAL */;
	struct UE_EUTRA_CapabilityAddXDD_Mode_v1060	*tdd_Add_UE_EUTRA_Capabilities_v1060	/* OPTIONAL */;
	struct RF_Parameters_v1060	*rf_Parameters_v1060	/* OPTIONAL */;
	struct UE_EUTRA_Capability_v1060_IEs__nonCriticalExtension {
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *nonCriticalExtension;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UE_EUTRA_Capability_v1060_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UE_EUTRA_Capability_v1060_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "UE-EUTRA-CapabilityAddXDD-Mode-v1060.h"
#include "RF-Parameters-v1060.h"

#endif	/* _UE_EUTRA_Capability_v1060_IEs_H_ */
#include "asn_internal.h"
