/*
 * common.h
 *
 *  Created on: 2019��5��5��
 *      Author: pu
 */

#ifndef COMMON_COMMON_H_
#define COMMON_COMMON_H_

#include <xdc/std.h>
#include <ti/ipc/MessageQ.h>

#define CORE_NUM                8
#define MASTER_CORE             0

#define MASTER_MSGQ_NAME         "masterMsgQ";

#define CORE0_TXQ_NUM           800
#define CORE1_TXQ_NUM           800
#define CORE2_TXQ_NUM           800
#define CORE3_TXQ_NUM           800
#define CORE4_TXQ_NUM           800
#define CORE5_TXQ_NUM           800
#define CORE6_TXQ_NUM           800
#define CORE0_TXQ_NUM           800

#define CORE0_RXQ_NUM           800
#define CORE1_RXQ_NUM           800
#define CORE2_RXQ_NUM           800
#define CORE3_RXQ_NUM           800
#define CORE4_RXQ_NUM           800
#define CORE5_RXQ_NUM           800
#define CORE6_RXQ_NUM           800
#define CORE7_RXQ_NUM           800

#define CORE0_RXCH_NUM          800
#define CORE1_RXCH_NUM          800
#define CORE2_RXCH_NUM          800
#define CORE3_RXCH_NUM          800
#define CORE4_RXCH_NUM          800
#define CORE5_RXCH_NUM          800
#define CORE6_RXCH_NUM          800
#define CORE7_RXCH_NUM          800

#define CORE0_TXCH_NUM           800
#define CORE1_TXCH_NUM           800
#define CORE2_TXCH_NUM           800
#define CORE3_TXCH_NUM           800
#define CORE4_TXCH_NUM           800
#define CORE5_TXCH_NUM           800
#define CORE6_TXCH_NUM           800
#define CORE0_TXCH_NUM           800



typedef struct  notify_msg{
    MessageQ_MsgHeader  header;
    Int     initDone;
}Notifye_Msg;

//�����ز���Ϣ�������ݽṹ
typedef union carrier_u {
    struct {
        uint16_t physCellId9:9;
        uint16_t DIR:1;
        uint16_t en:1;
        uint16_t Res:1;
        uint16_t RFBN:4;
    } carrier;
    struct {
        uint16_t PhysCellID:8;
        uint16_t PhyCellIDmsb:1;
        uint16_t DIR:1;
        uint16_t en:1;
        uint16_t Res:1;
        uint16_t RFBN:4;
    } carrier_2pid;
    uint16_t carrier_u16;
} CARRIER_t;

//����忨��Ϣ������������
typedef union {
    struct {
        uint16_t slotid:5;      //Դ�����λ��
        uint16_t src_bdtype:3;  //Դ��������
        uint16_t dst_rfbn:4;    //Ŀ�Ļ������λ�ţ���dst_type ==0 ʱ��Ч
        uint16_t dst_bdtype:3;  //Ŀ�ĵ�������
        uint16_t single:1;      //�Ƿ�ֻ����һ���Ӱ�
    } bdinfo_s;
    uint16_t bdinfo_u16;
} BDinfo_t;

//���常��ͷ�ṹ
typedef struct FpkH_s {
    uint16_t mark;  //����ͷ��־�����ģʽ���̶�Ϊ0xDCBA
    uint16_t flen;  //�����ܳ���
    BDinfo_t bdinfo;    //�����Ϣ
    CARRIER_t carrier_info; //FIXME �ز���Ϣ�����ֶα��뾭����С��ת������
} FpkH_t;



#endif /* COMMON_COMMON_H_ */