/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-b00.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER -pdu=auto`
 */

#ifndef	_CarrierFreqsInfoListGERAN_H_
#define	_CarrierFreqsInfoListGERAN_H_


#include "asn_application.h"

/* Including external dependencies */
#include "asn_SEQUENCE_OF.h"
#include "constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct CarrierFreqsInfoGERAN;

/* CarrierFreqsInfoListGERAN */
typedef struct CarrierFreqsInfoListGERAN {
	A_SEQUENCE_OF(struct CarrierFreqsInfoGERAN) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CarrierFreqsInfoListGERAN_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CarrierFreqsInfoListGERAN;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "CarrierFreqsInfoGERAN.h"

#endif	/* _CarrierFreqsInfoListGERAN_H_ */
#include "asn_internal.h"