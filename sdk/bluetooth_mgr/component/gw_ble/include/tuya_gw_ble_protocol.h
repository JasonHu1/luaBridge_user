/*
tuya_gw_ble_protocol.h
*/

#ifndef TUYA_GW_BLE_PROTOCOL_H
#define TUYA_GW_BLE_PROTOCOL_H

#include "tuya_gw_bt_api.h"
#include "tuya_bt_hal.h"
#include "tuya_gw_bt_comm.h"

#ifdef __cplusplus
extern "C" {
#endif

VOID tuya_ble_protocol_get_ver(IN UINT16_T ver, OUT CHAR_T *ver_str, IN UINT8_T str_Len);

#ifdef __cplusplus
}
#endif
#endif
