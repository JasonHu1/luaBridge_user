/*
tuya_gw_ble_mgmt.h
*/

#ifndef TUYA_GW_BLE_MGMT_H
#define TUYA_GW_BLE_MGMT_H

#include "tuya_gw_bt_api.h"
#include "tuya_bt_hal.h"
#include "tuya_gw_bt_comm.h"
#include "tuya_gw_bt_adapter.h"
#include "tuya_ble_master.h"

#define TY_BLE_TM_TP_LEN        1
#define TY_BLE_TM_STR_LEN       13
#define TY_BLE_TIMESTAMP_LEN    4
#define TY_BLE_MGR_TIMER_INTR   500 //ms

typedef enum {
    TY_BLE_TYPE_HEARTBEAT = 0,
    TY_BLE_TYPE_CONN,
    TY_BLE_TYPE_DISCONN
    
} TY_BLE_CONN_TYPE_E;  

typedef enum {
    TY_BLE_STAT_SUCCESS = 0,
    TY_BLE_STAT_FAIL = 1,
    
} TY_BLE_RESP_STAT_E;  

typedef enum {
    TY_BLE_TIME_TP_STR = 0,
    TY_BLE_TIME_TP_TIMESTAMP = 1,
    
} TY_BLE_TIME_TYPE_E;  

typedef struct {
    BOOL_T  permit;
    UINT_T  timeout;
    TIME_T  start_tm;

} TUYA_BLE_JOIN_S;

#ifdef __cplusplus
extern "C" {
#endif

void tuya_ble_hal_data_report(TUYA_BT_HAL_DATA_TYPE_E type, TUYA_BT_HAL_DATA_ADDR_U *src, uint8_t *data, uint32_t lenght);
BOOL_T tuya_gw_ble_dev_join(IN CONST BOOL_T permit,IN CONST UINT_T timeout);
VOID tuya_gw_ble_dev_del(IN CONST CHAR_T *dev_id);
VOID tuya_ble_dev_bind_notify(IN CONST CHAR_T *dev_id, IN CONST OPERATE_RET op_ret);
VOID tuya_gw_ble_dev_reset(IN CONST CHAR_T *dev_id, IN DEV_RESET_TYPE_E type);
VOID tuya_gw_ble_dp_cmd(IN CONST TY_BT_RECV_DP_TYPE_S type, IN CONST VOID *dp);
VOID tuya_gw_ble_dp_query(IN CONST TY_DP_QUERY_S *dp_qry);
void tuya_ble_hal_scan_cb(uint16_t dev_num, VOID *dev);
void tuya_ble_hal_connect_cb(TUYA_BT_HAL_DATA_TYPE_E type, TUYA_BT_HAL_DATA_ADDR_U *src, TUYA_BT_HAL_STATUS_EVENT_E event);
void tuya_ble_hal_disconnect_cb(TUYA_BT_HAL_DATA_TYPE_E type, TUYA_BT_HAL_DATA_ADDR_U *src, TUYA_BT_HAL_STATUS_EVENT_E event);
OPERATE_RET tuya_gw_ble_start(UINT8_T max_conn, UINT8_T scan_to_tm);
VOID tuya_ble_conn_notify(OUT CHAR_T *dev_conn_inf_json);
VOID tuya_ble_bind_change_notify(IN CONST CHAR_T *dev_id, TY_BT_DEV_BIND_CHANGE_E change);
VOID tuya_ble_process_adv_resp(TUYA_BT_HAL_BLE_SCAN_DEV_S *p_scan_dev);
OPERATE_RET tuya_ble_set_connect_timeout(UINT8_T timeout);

#ifdef __cplusplus
}
#endif
#endif
