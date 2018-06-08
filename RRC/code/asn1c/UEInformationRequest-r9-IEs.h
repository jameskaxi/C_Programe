/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-b00.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER -pdu=auto`
 */

#ifndef	_UEInformationRequest_r9_IEs_H_
#define	_UEInformationRequest_r9_IEs_H_


#include "asn_application.h"

/* Including external dependencies */
#include "BOOLEAN.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct UEInformationRequest_v930_IEs;

/* UEInformationRequest-r9-IEs */
typedef struct UEInformationRequest_r9_IEs {
	BOOLEAN_t	 rach_ReportReq_r9;
	BOOLEAN_t	 rlf_ReportReq_r9;
	struct UEInformationRequest_v930_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UEInformationRequest_r9_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UEInformationRequest_r9_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "UEInformationRequest-v930-IEs.h"

#endif	/* _UEInformationRequest_r9_IEs_H_ */
#include "asn_internal.h"
