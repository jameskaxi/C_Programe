/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-b00.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER -pdu=auto`
 */

#ifndef	_RRCConnectionReestablishmentComplete_r8_IEs_H_
#define	_RRCConnectionReestablishmentComplete_r8_IEs_H_


#include "asn_application.h"

/* Including external dependencies */
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RRCConnectionReestablishmentComplete_v920_IEs;

/* RRCConnectionReestablishmentComplete-r8-IEs */
typedef struct RRCConnectionReestablishmentComplete_r8_IEs {
	struct RRCConnectionReestablishmentComplete_v920_IEs	*nonCriticalExtension	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RRCConnectionReestablishmentComplete_r8_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RRCConnectionReestablishmentComplete_r8_IEs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RRCConnectionReestablishmentComplete-v920-IEs.h"

#endif	/* _RRCConnectionReestablishmentComplete_r8_IEs_H_ */
#include "asn_internal.h"