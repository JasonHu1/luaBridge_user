#ifndef __TUYA_BLE_BROADCAST_H__
#define __TUYA_BLE_BROADCAST_H__

#include "tuya_ble_def.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


int ty_ble_broadcast_data_unpack(TY_BLE_BROADCAST_DATA_S* pbcast, const unsigned char* pdata, int len);


void ty_ble_print_broadcast_data(TY_BLE_BROADCAST_DATA_S* pbcast);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif