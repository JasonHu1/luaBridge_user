/*
tuya_gw_ble_rx.h
*/

#ifndef TUYA_GW_BLE_RX_H
#define TUYA_GW_BLE_RX_H

#include "tuya_gw_bt_api.h"
#include "tuya_bt_hal.h"
#include "tuya_gw_bt_comm.h"
#include "tuya_gw_ble_dev.h"
#include "tuya_ble_master.h"

#ifdef __cplusplus
extern "C" {
#endif

VOID tuya_ble_data_report_cb(CONST UINT8_T *pmac, UINT16_T cmd, BYTE_T *buffer, INT_T len);

#ifdef __cplusplus
}
#endif
#endif
