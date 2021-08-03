/**
 * @file    tuya_zigbee_defs.h
 * @brief   This file define data type for ZigBee
 * @version 0.1
 * 
 * @copyright Copyright (c) tuya.inc 2019
 */
#ifndef __TUYA_ZIGBEE_DEFS_H__
#define __TUYA_ZIGBEE_DEFS_H__

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define Z3_DEV_ID_LEN    32
#define MAX_EP_NUM       10
#define MAX_CLUSTER_NUM  10
#define MANU_NAME_LEN    32
#define MODEL_ID_LEN     32

typedef VOID (*TY_Z3_RFTEST_RESULT_CB)(USHORT_T npacket);

typedef struct {
    CHAR_T *manu_name;
    CHAR_T *model_id;
} TY_Z3_DEV_S;

typedef struct {
    TY_Z3_DEV_S  *devs;
    UINT16_T      dev_num;
} TY_Z3_DEVLIST_S;

typedef struct {
    CHAR_T     id[Z3_DEV_ID_LEN+1];
    UINT16_T   profile_id[MAX_EP_NUM];
    UINT16_T   device_id[MAX_EP_NUM];
    UINT16_T   cluster_id[MAX_EP_NUM][MAX_CLUSTER_NUM];
    UINT16_T   endpoint[MAX_EP_NUM];
    UCHAR_T    ep_num; // endpoints count
    UCHAR_T    uc_num; // clusters count
    UINT16_T   node_id;
    CHAR_T     manu_name[MANU_NAME_LEN+1];
    CHAR_T     model_id[MODEL_ID_LEN+1];
    CHAR_T     rejoin_flag;
    CHAR_T     power_source;
    UCHAR_T    version;
} TY_Z3_DESC_S;

typedef struct {
    CHAR_T     id[Z3_DEV_ID_LEN+1];
    UINT16_T   node_id;
    UINT16_T   profile_id;
    UINT16_T   cluster_id;
    UCHAR_T    src_endpoint;
    UCHAR_T    dst_endpoint;
    UINT16_T   group_id;
    UCHAR_T    cmd_type;          // zcl command type. 0x00: global command, 0x01: command is specific to a cluster.
    UCHAR_T    cmd_id;            // zcl command id
    UCHAR_T    frame_type;        // 0: Unicast, 1: Multicast, 2: Broadcast
    UINT16_T   manufacturer_code;
    CHAR_T     disable_ack;
    UINT16_T   msg_length;
    UCHAR_T   *message;
} TY_Z3_APS_FRAME_S;

typedef struct {
    VOID (*join)(TY_Z3_DESC_S *dev);
    VOID (*leave)(CONST CHAR_T *dev_id);
    VOID (*report)(TY_Z3_APS_FRAME_S *frame);
    VOID (*notify)(VOID);
    VOID (*upgrade_end)(CONST CHAR_T *dev_id, INT_T rc, UCHAR_T version);
} TY_Z3_DEV_CBS_S;

#ifdef __cplusplus
}
#endif
#endif