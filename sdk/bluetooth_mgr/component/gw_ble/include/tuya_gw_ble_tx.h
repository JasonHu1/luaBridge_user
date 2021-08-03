/*
tuya_gw_ble_tx.h
*/

#ifndef TUYA_GW_BLE_TX_H
#define TUYA_GW_BLE_TX_H

#include "tuya_gw_bt_api.h"
#include "tuya_bt_hal.h"
#include "tuya_gw_bt_comm.h"
#include "tuya_gw_ble_dev.h"
#include "tuya_ble_master.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TY_BLE_CMD_LIST_MAX     20
#define TY_BLE_PACKET_EXPIRE_TM 15

typedef VOID (*TY_BLE_SEND_CB)(IN CONST OPERATE_RET ret, IN CONST VOID *prv_data);

#pragma pack(1)
typedef struct{
    CHAR_T      id[TY_BLE_DEV_ID_LEN + 1];
    BYTE_T      *buf;
    UINT8_T     len;
    UINT16_T    cmd;

    TIME_T      send_start;
    TY_BLE_SEND_CB send_cb;
    VOID        *prv_data;
    SLIST_HEAD  node;    

} TUYA_BLE_TX_PACKET_S;

typedef struct {
    
    SLIST_HEAD      packet_list;
    UINT16_T        packet_num;
    MUTEX_HANDLE    mutex;

} TUYA_BLE_PACKET_MGR_S;
#pragma pack()

OPERATE_RET tuya_ble_packet_mgmt_start();
VOID tuya_ble_tx_packet_check();

OPERATE_RET tuya_gw_ble_send_sync(const UINT8_T *pmac, UINT16_T cmd, CONST BYTE_T *buf, INT_T len);
OPERATE_RET tuya_gw_ble_send_async(CONST CHAR_T *id, UINT16_T cmd, CONST BYTE_T *buf, INT_T len, 
                                   CONST TY_BLE_SEND_CB send_cb, CONST VOID *prv_data);
OPERATE_RET tuya_gw_ble_send(CONST CHAR_T *id, UINT16_T cmd, CONST BYTE_T *buf, INT_T len, 
                             CONST TY_BLE_SEND_CB send_cb, CONST VOID *prv_data);
#ifdef __cplusplus
}
#endif
#endif
