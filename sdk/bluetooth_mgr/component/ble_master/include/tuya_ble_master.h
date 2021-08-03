#ifndef __TUYA_BLE_MASTER_H__
#define __TUYA_BLE_MASTER_H__

#include <stdio.h>
#include "string.h"
#include <stdlib.h>

#include "tuya_gw_bt_comm.h"
#include "tuya_ble_def.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	TUYA_BLE_CONNECT_EVENT,
    TUYA_BLE_DISCONNECT_EVENT

} TUYA_BLE_EVENT_TYPE_E;

typedef enum {
	TUYA_BLE_DEV_BIND_SUCCESS       =0x1000,        
    TUYA_BLE_DEV_BIND_FAIL          =0x1001,
    
    TUYA_BLE_DEV_DISCONNECT_SUCCESS =0x1002,
    TUYA_BLE_DEV_DISCONNECT_FAIL    =0x1003,

    TUYA_BLE_DEV_UNBOUND_SUCCESS    =0x1004,
    TUYA_BLE_DEV_UNBOUND_FAIL       =0x1005,

    TUYA_BLE_DEV_REBIND_SUCCESS     =0x1006,        
    TUYA_BLE_DEV_REBIND_FAIL        =0x1007,

    TUYA_BLE_DEV_IN_CONNECTING

} TUYA_BLE_MASTER_STATUS_TYPE_E;

typedef struct {
    int                     bind;  // base the last adv, need to update the info ASAP
	unsigned char 			mac[6];
    unsigned char           mac_type;
    unsigned char           sdk_version;
    unsigned char           link_req;

    unsigned char           device_id[16];  
    unsigned char           product_id[8]; // Only Unbind device has product id, if bind, these data will be encrypted

    unsigned short          ble_firmware_version;
    unsigned char           mcu_firmware_version[3];
    unsigned char           register_key[16];  // for backup

    // these data need to check with Tuya Cloud
    unsigned char           secret_key1[16];
    unsigned char           server_rand[16];
    unsigned char 			login_key[6];
    
} TUYA_BLE_DEV_INFO_S;

typedef struct {  // seperate with device info
    // GW need
    unsigned char   device_id[16];
    unsigned char   product_id[8];
    int             bind;

    unsigned short  ble_firmware_version;
    unsigned char   mcu_firmware_version[3];
    unsigned char   register_key[16];  // for backup
    
    // ble master need
    unsigned char   secret_key1[16];
    unsigned char   server_rand[16];
    unsigned char 	login_key[6];

} TUYA_BLE_MASTER_KEY_S;

typedef INT_T (*TY_BLE_GET_LOGIN_KEY_CB)(CONST UINT8_T *pmac, TUYA_BLE_MASTER_KEY_S *key);
typedef VOID (*TY_BLE_DATA_REPT_CB)(CONST UINT8_T *pmac, UINT16_T cmd, BYTE_T *buffer, INT_T len);
typedef VOID (*TY_BLE_STATUS_REPT_CB)(CONST UINT8_T *pmac, TUYA_BLE_MASTER_STATUS_TYPE_E type);

typedef struct {
    TY_BLE_GET_LOGIN_KEY_CB get_login_key_cb; // seperate with exchange key while doing pair device
    TY_BLE_DATA_REPT_CB     data_rept_cb;
    TY_BLE_STATUS_REPT_CB   status_rept_cb;

} TUYA_BLE_MASTER_CB_S;

OPERATE_RET tuya_ble_master_start(TUYA_BLE_MASTER_CB_S *cbs);
OPERATE_RET tuya_ble_master_scan_parse(TUYA_BT_HAL_BLE_SCAN_DEV_S *p_scan, TUYA_BLE_DEV_INFO_S *p_info);

OPERATE_RET tuya_ble_master_connect(UINT8_T *pmac, TUYA_BLE_DEV_INFO_S *p_info);
OPERATE_RET tuya_ble_master_disconnect(UINT8_T *pmac);
INT_T tuya_ble_master_send(CONST UINT8_T *pmac, INT16_T cmd, BYTE_T *buf, int len);

OPERATE_RET tuya_ble_master_data_notify(CONST UINT8_T *pmac, CONST BYTE_T *buf, UINT_T len);
OPERATE_RET tuya_ble_master_set_status(CONST UINT8_T *pmac, TUYA_BLE_EVENT_TYPE_E event, INT8_T result);
OPERATE_RET tuya_ble_master_get_dev_info(CONST UINT8_T *pmac,TUYA_BLE_DEV_INFO_S *p_info);

BOOL_T tuya_ble_master_adv_only_check(TUYA_BT_HAL_BLE_SCAN_DEV_S *p_scan);
BOOL_T tuya_ble_master_rsp_only_check(TUYA_BT_HAL_BLE_SCAN_DEV_S *p_scan);
OPERATE_RET tuya_ble_master_set_max_link(UINT8_T link);
OPERATE_RET tuya_ble_master_set_connect_timeout(UINT8_T timeout);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __TUYA_BLE_MASTER_H__

