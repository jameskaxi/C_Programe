/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-b00.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER -pdu=auto`
 */

#ifndef	_SecurityAlgorithmConfig_H_
#define	_SecurityAlgorithmConfig_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NativeEnumerated.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SecurityAlgorithmConfig__cipheringAlgorithm {
	SecurityAlgorithmConfig__cipheringAlgorithm_eea0	= 0,
	SecurityAlgorithmConfig__cipheringAlgorithm_eea1	= 1,
	SecurityAlgorithmConfig__cipheringAlgorithm_eea2	= 2,
	SecurityAlgorithmConfig__cipheringAlgorithm_eea3_v11xy	= 3,
	SecurityAlgorithmConfig__cipheringAlgorithm_spare4	= 4,
	SecurityAlgorithmConfig__cipheringAlgorithm_spare3	= 5,
	SecurityAlgorithmConfig__cipheringAlgorithm_spare2	= 6,
	SecurityAlgorithmConfig__cipheringAlgorithm_spare1	= 7
	/*
	 * Enumeration is extensible
	 */
} e_SecurityAlgorithmConfig__cipheringAlgorithm;
typedef enum SecurityAlgorithmConfig__integrityProtAlgorithm {
	SecurityAlgorithmConfig__integrityProtAlgorithm_eia0_v920	= 0,
	SecurityAlgorithmConfig__integrityProtAlgorithm_eia1	= 1,
	SecurityAlgorithmConfig__integrityProtAlgorithm_eia2	= 2,
	SecurityAlgorithmConfig__integrityProtAlgorithm_eia3_v11xy	= 3,
	SecurityAlgorithmConfig__integrityProtAlgorithm_spare4	= 4,
	SecurityAlgorithmConfig__integrityProtAlgorithm_spare3	= 5,
	SecurityAlgorithmConfig__integrityProtAlgorithm_spare2	= 6,
	SecurityAlgorithmConfig__integrityProtAlgorithm_spare1	= 7
	/*
	 * Enumeration is extensible
	 */
} e_SecurityAlgorithmConfig__integrityProtAlgorithm;

/* SecurityAlgorithmConfig */
typedef struct SecurityAlgorithmConfig {
	long	 cipheringAlgorithm;
	long	 integrityProtAlgorithm;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SecurityAlgorithmConfig_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_cipheringAlgorithm_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_integrityProtAlgorithm_12;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_SecurityAlgorithmConfig;

#ifdef __cplusplus
}
#endif

#endif	/* _SecurityAlgorithmConfig_H_ */
#include "asn_internal.h"
