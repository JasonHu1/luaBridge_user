/*
tuya_gw_bt_adapter.h
*/

#ifndef TUYA_GW_BT_ADAPTER_H
#define TUYA_GW_BT_ADAPTER_H

#include "tuya_gw_bt_api.h"
#include "tuya_gw_bt_comm.h"

#define TY_BT_ADAPTER_MAX          2

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    TY_BT_BIND_CHANGE_TOPO_UPDATE = 1,
    TY_BT_BIND_CHANGE_DEL = 2,

}TY_BT_DEV_BIND_CHANGE_E;

typedef VOID (*TY_BT_SCAN_CB)(uint16_t dev_num, VOID *dev);
typedef void (*TY_BT_DATA_REPORT)(TUYA_BT_HAL_DATA_TYPE_E type, TUYA_BT_HAL_DATA_ADDR_U *src, uint8_t *data, uint32_t lenght);
typedef void (*TY_BT_STATUS_EVENT)(TUYA_BT_HAL_DATA_TYPE_E type, TUYA_BT_HAL_DATA_ADDR_U *src, TUYA_BT_HAL_STATUS_EVENT_E event);
typedef void (*TY_BT_ADD_CB)(uint16_t dev_num, TUYA_BT_HAL_MESH_DEV_S *dev, TUYA_BT_HAL_MESH_DEV_COMPOSITE_DATA_S *composite_data);
typedef void (*TY_BT_DELETE_CB)(uint16_t dev_num, TUYA_BT_HAL_MESH_DEV_S *dev);

typedef VOID (*TY_BT_DP_CMD_CB)(IN CONST TY_BT_RECV_DP_TYPE_S type, IN CONST VOID *dp);
typedef VOID (*TY_BT_DP_QUERY_CB)(IN CONST TY_DP_QUERY_S *dp_qry);
typedef BOOL_T (*TY_BT_DEV_ADD_CMD_CB)(IN CONST BOOL_T permit,IN CONST UINT_T timeout);
typedef VOID (*TY_BT_DEV_DEL_CMD_CB)(IN CONST CHAR_T *dev_id);
typedef OPERATE_RET (*TY_BT_DEV_GRP_NOTIFY)(IN CONST GRP_ACTION_E action,IN CONST CHAR_T *dev_id,IN CONST CHAR_T *grp_id);
typedef VOID (*TY_BT_DEV_BIND_NOTIFY)(IN CONST CHAR_T *dev_id, IN CONST OPERATE_RET op_ret);
typedef VOID (*TY_BT_DEV_RESET_NOTIFY)(IN CONST CHAR_T *dev_id, IN DEV_RESET_TYPE_E type);
typedef int (*TY_BT_DEV_UG_NOTIFY)(IN CONST CHAR_T *dev_id, IN CONST FW_UG_S *fw);
typedef VOID (*TY_BT_DEV_HB_QUERY_CB)(IN CONST CHAR_T *dev_id);
typedef VOID (*TY_BT_SET_STAT_CB)(IN CONST TY_BT_GW_STAT_E stat);
typedef VOID (*TY_BT_CONN_NOTIFY)(OUT CHAR_T *dev_conn_inf_json);
typedef VOID (*TY_BT_BIND_CHANGE_NOTIFY)(IN CONST CHAR_T *dev_id, TY_BT_DEV_BIND_CHANGE_E change);

typedef struct {
    TY_BT_ADAPTER_TP_E  type;

    //bt hal cb
    TY_BT_SCAN_CB       scan_cb;
    TY_BT_DATA_REPORT   report_cb;
    TY_BT_STATUS_EVENT  connect_cb;
    TY_BT_STATUS_EVENT  disconnect_cb;
    TY_BT_ADD_CB        add_cb;
    TY_BT_DELETE_CB     del_cb;

    //tuya base cb
    TY_BT_DP_CMD_CB         dp_cmd_cb;
    TY_BT_DP_QUERY_CB       dp_query_cb;
    TY_BT_DEV_ADD_CMD_CB    add_cmd_cb;
    TY_BT_DEV_DEL_CMD_CB    del_cmd_cb;
    TY_BT_DEV_GRP_NOTIFY    grp_notify;
    TY_BT_DEV_BIND_NOTIFY   bind_notify;
    TY_BT_DEV_RESET_NOTIFY  reset_notify;
    TY_BT_DEV_UG_NOTIFY     ug_notify;
    TY_BT_CONN_NOTIFY       bt_conn_notify;
    TY_BT_DEV_HB_QUERY_CB   hb_query_cb;
    TY_BT_BIND_CHANGE_NOTIFY bind_change_notify;
    TY_BT_SET_STAT_CB       set_gw_stat_cb;
    
} TUYA_BT_ADAPTER_INFO_S;

typedef struct {
    TUYA_BT_ADAPTER_INFO_S  info_arr[TY_BT_ADAPTER_MAX];
    UINT_T count;

} TUYA_BT_ADAPTER_MGR_S;

TUYA_BT_ADAPTER_INFO_S *tuya_bt_get_adapter_info(TY_BT_ADAPTER_TP_E type);
TY_BT_ADAPTER_TP_E tuya_bt_get_type_from_hal(TUYA_BT_HAL_DATA_TYPE_E hal_type);
TY_BT_ADAPTER_TP_E tuya_bt_get_type_from_id(CONST CHAR_T *id);
OPERATE_RET tuya_gw_bt_adapter_register_cb(CONST TUYA_BT_ADAPTER_INFO_S *p_info);
TUYA_BT_ADAPTER_MGR_S *tuya_bt_get_adapter_mgr();

#ifdef __cplusplus
}
#endif
#endif
