/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-b00.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER -pdu=auto`
 */

#ifndef	_ReportConfigToAddModList_H_
#define	_ReportConfigToAddModList_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct ReportConfigToAddMod;

/* ReportConfigToAddModList */
typedef struct ReportConfigToAddModList {
	A_SEQUENCE_OF(struct ReportConfigToAddMod) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ReportConfigToAddModList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ReportConfigToAddModList;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "ReportConfigToAddMod.h"

#endif	/* _ReportConfigToAddModList_H_ */
#include "asn_internal.h"
