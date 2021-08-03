#ifndef _BLE_UP_MID_H
#define _BLE_UP_MID_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "tuya_cloud_types.h"
#include "tuya_bt_hal.h"
#include "uni_msg_queue.h"
#include "uni_time_queue.h"


/***********************************************************
*************************micro define***********************
***********************************************************/

/***********************************************************
*************************variable define********************
***********************************************************/

/***********************************************************
*************************function define********************
***********************************************************/


typedef struct {
    BOOL_T is_init;
    MSG_ID tmm_ble_scan_cb;
    MSG_ID tmm_mesh_scan_cb;
    MSG_ID tmm_mesh_add_cb;
    MSG_ID tmm_mesh_delete_cb;
    MSG_ID tmm_data_report_cb;
    MSG_ID tmm_bt_connect_cb;
    MSG_ID tmm_bt_disconnect_cb;
    MSG_ID tmm_bt_ble_data_cb;
}TUYA_BLE_UP_MID_t;


typedef struct {
    UINT16_T dev_num;
    uint8_t mac[TY_BT_MAC_LEN];
	int8_t rssi;
    uint8_t lenght;
    uint8_t data[32];
    TUYA_BT_HAL_DEV_TYPE_T type;  
    TUYA_BT_HAL_DEV_AD_TYPE_T ad_type;
}BLE_SCAN_t;

typedef struct {
    UINT16_T dev_num;
    TUYA_BT_HAL_MESH_SCAN_DEV_S dev;
}MESH_SCAN_t;

typedef struct {
    UINT16_T dev_num;
    TUYA_BT_HAL_MESH_DEV_S dev;
    TUYA_BT_HAL_MESH_DEV_COMPOSITE_DATA_S composite_data;
}MESH_ADD_t;

typedef struct {
    UINT16_T dev_num;
    TUYA_BT_HAL_MESH_DEV_S dev;
}MESH_DELETE_t;

typedef struct {
    TUYA_BT_HAL_DATA_TYPE_E type;
    TUYA_BT_HAL_DATA_ADDR_U src;
    UINT_T lenght;
    UCHAR_T data[0];
}DATA_REPORT_t;

typedef struct {
    TUYA_BT_HAL_DATA_TYPE_E type;
    TUYA_BT_HAL_DATA_ADDR_U src;
    TUYA_BT_HAL_STATUS_EVENT_E event;
}STATUS_EVENT_t;

typedef struct {
    INT_T id;
    INT_T e;
    UINT_T len;
    UCHAR_T data[0];
}BLE_DATA_t;


OPERATE_RET tuya_bt_up_mid_init(VOID);
OPERATE_RET tuya_bt_mid_ble_scan_cb_post(BLE_SCAN_t *bt_data);
OPERATE_RET tuya_bt_mid_mesh_scan_cb_post(MESH_SCAN_t *bt_data);
OPERATE_RET tuya_bt_mid_mesh_add_cb_post(MESH_ADD_t *bt_data);
OPERATE_RET tuya_bt_mid_mesh_delete_cb_post(MESH_DELETE_t *bt_data);
OPERATE_RET tuya_bt_mid_data_report_cb_post(DATA_REPORT_t *bt_data, MSG_DATA_LEN len);
OPERATE_RET tuya_bt_mid_bt_connect_cb_post(STATUS_EVENT_t *bt_data);
OPERATE_RET tuya_bt_mid_bt_disconnect_cb_post(STATUS_EVENT_t *bt_data);
OPERATE_RET tuya_bt_mid_ble_data_cb_post(BLE_DATA_t *bt_data, MSG_DATA_LEN len);

#ifdef __cplusplus
}
#endif
#endif
