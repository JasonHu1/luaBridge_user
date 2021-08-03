/*
tuya_gw_mesh_prov.h
*/

#ifndef TUYA_GW_MESH_PROV_H
#define TUYA_GW_MESH_PROV_H

#include "tuya_gw_bt_api.h"
#include "tuya_bt_hal.h"
#include "tuya_gw_bt_comm.h"
#include "tuya_gw_bt_adapter.h"
#include "mesh_adapter.h"
#include "group_manage.h"

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1)
typedef struct {
    BOOL_T  permit;
    UINT_T  timeout;
    TIME_T  start_tm;

    BOOL_T  fast_prov;

} TUYA_MESH_PROV_S;
#pragma pack()

void tuya_mesh_hal_scan_cb(uint16_t dev_num, VOID *dev);
void tuya_mesh_hal_add_cb(uint16_t dev_num, TUYA_BT_HAL_MESH_DEV_S *dev, TUYA_BT_HAL_MESH_DEV_COMPOSITE_DATA_S *composite_data);
BOOL_T tuya_gw_mesh_dev_join(IN CONST BOOL_T permit,IN CONST UINT_T timeout);
VOID tuya_mesh_check_dev_join();

#ifdef __cplusplus
}
#endif
#endif
