/*
tuya_gw_ble_adv.h
*/

#ifndef TUYA_GW_BLE_ADV_H
#define TUYA_GW_BLE_ADV_H

#include "tuya_gw_bt_api.h"
#include "tuya_bt_hal.h"
#include "tuya_gw_bt_comm.h"
#include "tuya_gw_ble_dev.h"
#include "tuya_ble_master.h"

#define TY_BLE_ADV_LIST_MAX         100
#define TY_BLE_ADV_DATA_LEN_MAX     32

#pragma pack(1)
typedef struct{
    BYTE_T mac[TY_BT_MAC_LEN];
	BYTE_T adv_data[TY_BLE_ADV_DATA_LEN_MAX];
	UINT16_T adv_data_len; 
	UINT8_T  rssi;

    SLIST_HEAD  node;    

} TUYA_BLE_DEV_ADV_S;

typedef struct {
    SLIST_HEAD      adv_list;
    UINT16_T        dev_adv_num;
    MUTEX_HANDLE    adv_mutex;

} TUYA_BLE_ADV_MGR_S;
#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

OPERATE_RET tuya_ble_adv_mgmt_start();
VOID tuya_ble_adv_report(TUYA_BT_HAL_BLE_SCAN_DEV_S *p_scan_dev);

#ifdef __cplusplus
}
#endif
#endif
