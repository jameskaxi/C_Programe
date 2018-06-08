/*
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-b00.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER -pdu=auto`
 */

#ifndef	_CSI_RS_Config_r10_H_
#define	_CSI_RS_Config_r10_H_


#include "asn_application.h"

/* Including external dependencies */
#include "NULL.h"
#include "NativeEnumerated.h"
#include "NativeInteger.h"
#include "constr_SEQUENCE.h"
#include "constr_CHOICE.h"
#include "BIT_STRING.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum CSI_RS_Config_r10__csi_RS_r10_PR {
	CSI_RS_Config_r10__csi_RS_r10_PR_NOTHING,	/* No components present */
	CSI_RS_Config_r10__csi_RS_r10_PR_release,
	CSI_RS_Config_r10__csi_RS_r10_PR_setup
} CSI_RS_Config_r10__csi_RS_r10_PR;
typedef enum CSI_RS_Config_r10__csi_RS_r10__setup__antennaPortsCount_r10 {
	CSI_RS_Config_r10__csi_RS_r10__setup__antennaPortsCount_r10_an1	= 0,
	CSI_RS_Config_r10__csi_RS_r10__setup__antennaPortsCount_r10_an2	= 1,
	CSI_RS_Config_r10__csi_RS_r10__setup__antennaPortsCount_r10_an4	= 2,
	CSI_RS_Config_r10__csi_RS_r10__setup__antennaPortsCount_r10_an8	= 3
} e_CSI_RS_Config_r10__csi_RS_r10__setup__antennaPortsCount_r10;
typedef enum CSI_RS_Config_r10__zeroTxPowerCSI_RS_r10_PR {
	CSI_RS_Config_r10__zeroTxPowerCSI_RS_r10_PR_NOTHING,	/* No components present */
	CSI_RS_Config_r10__zeroTxPowerCSI_RS_r10_PR_release,
	CSI_RS_Config_r10__zeroTxPowerCSI_RS_r10_PR_setup
} CSI_RS_Config_r10__zeroTxPowerCSI_RS_r10_PR;

/* CSI-RS-Config-r10 */
typedef struct CSI_RS_Config_r10 {
	struct CSI_RS_Config_r10__csi_RS_r10 {
		CSI_RS_Config_r10__csi_RS_r10_PR present;
		union CSI_RS_Config_r10__csi_RS_r10_u {
			NULL_t	 release;
			struct CSI_RS_Config_r10__csi_RS_r10__setup {
				long	 antennaPortsCount_r10;
				long	 resourceConfig_r10;
				long	 subframeConfig_r10;
				long	 p_C_r10;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} setup;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *csi_RS_r10;
	struct CSI_RS_Config_r10__zeroTxPowerCSI_RS_r10 {
		CSI_RS_Config_r10__zeroTxPowerCSI_RS_r10_PR present;
		union CSI_RS_Config_r10__zeroTxPowerCSI_RS_r10_u {
			NULL_t	 release;
			struct CSI_RS_Config_r10__zeroTxPowerCSI_RS_r10__setup {
				BIT_STRING_t	 zeroTxPowerResourceConfigList_r10;
				long	 zeroTxPowerSubframeConfig_r10;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} setup;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *zeroTxPowerCSI_RS_r10;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CSI_RS_Config_r10_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_antennaPortsCount_r10_5;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_CSI_RS_Config_r10;

#ifdef __cplusplus
}
#endif

#endif	/* _CSI_RS_Config_r10_H_ */
#include "asn_internal.h"
