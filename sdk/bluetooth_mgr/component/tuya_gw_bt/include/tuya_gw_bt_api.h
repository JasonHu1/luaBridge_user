/*
tuya_gw_bt_api.h
*/

#ifndef TUYA_GW_BT_API_H
#define TUYA_GW_BT_API_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "tuya_bt_hal.h"
#include "tuya_gw_init_api.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TY_BT_DEV_HB_QUERY_DEF      1000    //device hearbeat query interval, 1s
#define TY_BLE_SCAN_TO_TM_DEF       10      //ble device scan timeout time, 10s
#define TY_BLE_CONNECT_TO_TM_DEF    5       //ble device connect timeout time, 5s

typedef enum {
    TY_BT_GW_STAT_CLOUD_NOT_CONN = 0,   //mqtt not connect
    TY_BT_GW_STAT_CLOUD_CONN = 1,       //mqtt connect
    TY_BT_GW_STAT_RESET = 2,            //device reset
    TY_BT_GW_STAT_ACTIVED = 3,          //device http active
    
} TY_BT_GW_STAT_E;  

typedef struct{
    BOOL_T      enable_hb;              //enable hearbeat query
    UINT8_T     ble_scan_to_tm;         //second, ble scan timeout time

} TUYA_GW_BT_CONFIG_S;

OPERATE_RET tuya_gw_bt_init(TUYA_BT_HAL_WORK_MODE_E mode);
OPERATE_RET tuya_gw_bt_start(TUYA_GW_BT_CONFIG_S *p_config);
VOID tuya_gw_bt_dev_hb_query(IN CONST CHAR_T *dev_id);
VOID tuya_gw_bt_obj_dp_cmd(IN CONST TY_RECV_OBJ_DP_S *dp);
VOID tuya_gw_bt_raw_dp_cmd(IN CONST TY_RECV_RAW_DP_S *dp);
VOID tuya_gw_bt_dp_query(IN CONST TY_DP_QUERY_S *dp_qry);
BOOL_T tuya_gw_bt_dev_add(IN CONST GW_PERMIT_DEV_TP_T tp,IN CONST BOOL_T permit,IN CONST UINT_T timeout);
VOID tuya_gw_bt_dev_del(IN CONST CHAR_T *dev_id);
OPERATE_RET tuya_gw_bt_dev_grp_notify(IN CONST GRP_ACTION_E action,IN CONST CHAR_T *dev_id,IN CONST CHAR_T *grp_id);
VOID tuya_gw_bt_bind_dev_notify(IN CONST CHAR_T *dev_id, IN CONST OPERATE_RET op_ret);
VOID tuya_gw_bt_conn_notify(OUT CHAR_T *dev_conn_inf_json);
VOID tuya_gw_bt_dev_reset_notify(IN CONST CHAR_T *dev_id, IN DEV_RESET_TYPE_E type);
INT_T tuya_gw_bt_ug_notify(IN CONST CHAR_T *dev_id, IN CONST FW_UG_S *fw);
VOID tuya_gw_bt_topo_update_notify(IN CONST CHAR_T *dev_id);
VOID tuya_gw_bt_cache_del_notify(IN CONST CHAR_T *dev_id);
OPERATE_RET tuya_gw_bt_set_stat(TY_BT_GW_STAT_E stat);

//timeout: second, 0 will block
OPERATE_RET tuya_gw_ble_set_connect_timeout(UINT8_T timeout);

#ifdef __cplusplus
}
#endif
#endif
