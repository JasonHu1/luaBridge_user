/*
tuya_gw_mesh_mgmt.h
*/

#ifndef TUYA_GW_MESH_MGMT_H
#define TUYA_GW_MESH_MGMT_H

#include "tuya_gw_bt_api.h"
#include "tuya_bt_hal.h"
#include "tuya_gw_bt_comm.h"
#include "tuya_gw_bt_adapter.h"
#include "mesh_adapter.h"
#include "group_manage.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TY_MESH_MAC_LEN 
#define TY_MESH_MAC_LEN 6
#endif

#define TY_MESH_UUID_LEN            16
#define TY_MESH_GET_ADDR_NUM        20
#define TY_MESH_CHECK_NET_INTR      15  //s
#define TY_MESH_MGR_TIMER_INTR      200 //ms
#define TY_MESH_GRP_MANAGE_TM_TO    8   //s

#define TY_MESH_SRC_ADDR_SAVE_KEY   "mesh_source"

#pragma pack(1)
typedef struct{
    TY_SIGMESH_NODE_LIST_S list;
    UINT16_T    addr_idx;  
    BOOL_T      have_addr;    

} TUYA_MESH_ADDR_S;

typedef struct{
    TUYA_MESH_ADDR_S    free_addr;          //free node addr
    BOOL_T              net_config;         //set mesh net info ok
    TIMER_ID            mgr_tm;

} TUYA_MESH_MGR_S;
#pragma pack()

OPERATE_RET tuya_gw_mesh_start();
void tuya_mesh_hal_data_report(TUYA_BT_HAL_DATA_TYPE_E type, TUYA_BT_HAL_DATA_ADDR_U *src, uint8_t *data, uint32_t lenght);
VOID tuya_gw_mesh_dp_cmd(IN CONST TY_BT_RECV_DP_TYPE_S type, IN CONST VOID *dp);
VOID tuya_gw_mesh_dp_query(IN CONST TY_DP_QUERY_S *dp_qry);
VOID tuya_gw_mesh_dev_del(IN CONST CHAR_T *dev_id);
VOID tuya_gw_mesh_dev_reset(IN CONST CHAR_T *dev_id, IN DEV_RESET_TYPE_E type);
OPERATE_RET tuya_gw_mesh_dev_grp_notify(IN CONST GRP_ACTION_E action,IN CONST CHAR_T *dev_id,IN CONST CHAR_T *grp_id);
VOID tuya_mesh_bind_change_notify(IN CONST CHAR_T *dev_id, TY_BT_DEV_BIND_CHANGE_E change);
OPERATE_RET tuya_get_mesh_info(TUYA_BT_HAL_MESH_INFO_S *p_hal_info);
VOID tuya_mesh_set_gw_stat(IN CONST TY_BT_GW_STAT_E stat);
OPERATE_RET tuya_mesh_dev_hb_update(CHAR_T *sub_id);
OPERATE_RET tuya_mesh_get_node_addr(UINT16_T *p_node_addr);

#ifdef __cplusplus
}
#endif
#endif
