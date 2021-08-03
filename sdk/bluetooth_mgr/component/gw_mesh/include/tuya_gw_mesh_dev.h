/*
tuya_gw_mesh_dev.h
*/

#ifndef TUYA_GW_MESH_DEV_H
#define TUYA_GW_MESH_DEV_H

#include "tuya_gw_bt_api.h"
#include "tuya_bt_hal.h"
#include "tuya_gw_bt_comm.h"
#include "tuya_gw_bt_adapter.h"
#include "mesh_adapter.h"
#include "group_manage.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TY_MESH_ADD_LIST_MAX        50

#pragma pack(1)
typedef struct{
    TUYA_BT_HAL_MESH_SCAN_DEV_S scan_dev;
    UINT16_T    dev_addr;                  //sub device id 

    SLIST_HEAD  node;    

} TUYA_MESH_DEV_S;

typedef struct{
    SLIST_HEAD          dev_list;
    UINT16_T            dev_num;
    MUTEX_HANDLE        dev_mutex;

} TUYA_MESH_DEV_MGR_S;
#pragma pack()

OPERATE_RET tuya_mesh_list_operate(TY_BT_DEV_OP_E op, UINT8_T *mac, TUYA_MESH_DEV_S *p_dev);
OPERATE_RET tuya_mesh_list_add(TUYA_MESH_DEV_S *p_dev);
OPERATE_RET tuya_mesh_list_clear();
OPERATE_RET tuya_gw_mesh_dev_start();

#ifdef __cplusplus
}
#endif
#endif
