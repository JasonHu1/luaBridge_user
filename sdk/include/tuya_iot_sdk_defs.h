/**
 * @file tuya_iot_sdk_defs.h
 * @brief defination of tuya SDK
 * @version 1.0
 * @date 2021-7-16
 * 
 * @copyright Copyright (c) tuya.inc 2021
 * 
 */
#ifndef __TUYA_IOT_SDK_DEFS__
#define __TUYA_IOT_SDK_DEFS__

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#if defined(ENABLE_SUBDEVICE) && (ENABLE_SUBDEVICE==1)
#include "tuya_gw_com_defs.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief subscirbe DP type
 * 
 */
typedef UINT_T DP_DEV_TYPE_T;
#define DP_DEV     0  // only subscribe DP of subdevices
#define DP_GW      1  // only subscirbe DP of gw
#define DP_GW_DEV  2  // subscirbe DP of gw and subdevices

/**
 * @brief network status
 * 
 */
typedef UINT8_T SDK_NW_STAT_T;
#define SDK_NWK_OFFLINE 0 // online 
#define SDK_NWK_ONLINE 1  // offline

/**
 * @brief WIFI status
 * 
 */
typedef UINT8_T SDK_WIFI_NW_STAT_T;
#define SDK_STAT_LOW_POWER          0   // idle status,use to external config network
#define SDK_STAT_UNPROVISION        1   // smart config status
#define SDK_STAT_AP_STA_UNCFG       2   // ap WIFI config status
#define SDK_STAT_AP_STA_DISC        3   // ap WIFI already config,station disconnect
#define SDK_STAT_AP_STA_CONN        4   // ap station mode,station connect
#define SDK_STAT_STA_DISC           5   // only station mode,disconnect
#define SDK_STAT_STA_CONN           6   // station mode connect
#define SDK_STAT_UNPROVISION_AP_STA_UNCFG 7 //smart-cfg and ap-cfg concurrent config status

/**
 * @brief Handler when netowrk status changed.
 * 
 * @param[in] stat State code, see SDK_NW_STAT_T
 */
typedef VOID (*SDK_GET_NW_STAT_CB)(IN CONST SDK_NW_STAT_T stat);

/**
 * @brief Handler when WIFI status changed.
 * 
 *  @param[in] stat State code, see SDK_WIFI_NW_STAT_T
 */
typedef VOID (*SDK_WIFI_NW_STAT_CB)(IN CONST SDK_WIFI_NW_STAT_T stat);

/**
 * @brief Handler when dev_id need to send heartbeat 
 * 
 * @param[in] dev_id device id of sub-device
 */
typedef VOID (*GW_DEV_HB_SEND_CB)(IN CONST CHAR_T *dev_id);

/**
 * @brief Handler when dev_id need to upgrade.
 * 
 * @param[in] dev_id device id of sub-device
 * @param[in] fw, see FW_UG_S
 * 
 */
typedef VOID (*GW_DEV_UPGRADE_CB)(IN CONST CHAR_T *dev_id, IN CONST FW_UG_S *fw);

/**
 * @brief Handler when dev_id is reseted
 * 
 * @param[in] dev_id device id of sub-device
 * @param[in] type reset type, see DEV_RESET_TYPE_E
 */
typedef VOID (*GW_DEV_RESET_CB)(IN CONST CHAR_T *dev_id, IN CONST DEV_RESET_TYPE_E type);

/**
 * @brief the registered DP 
 * 
 */
typedef struct  {
    DEV_OBJ_DP_CMD_CB   obj;   // obj dp, see DEV_OBJ_DP_CMD_CB
    DEV_RAW_DP_CMD_CB   raw;   // raw dp, see DEV_RAW_DP_CMD_CB
    DEV_DP_QUERY_CB     query; // query dp, see DEV_DP_QUERY_CB
} TY_IOT_DP_CBS_S;

/**
 * @brief user need to register callback functions
 * 
 */
typedef struct {
    VOID (*gw_reset_cb)(GW_RESET_TYPE_E type);   // reset callback
    VOID (*gw_reboot_cb)(VOID);                  // reboot callback
    VOID (*gw_upgrade_cb)(CONST FW_UG_S *fw);    // upgrade 
    VOID (*gw_active_stat_cb)(GW_STATUS_E stat); // active status
    VOID (*gw_active_url_cb)(CHAR_T *url);       // active URL 
} TY_GW_INFRA_CBS_S;

#if defined(ENABLE_SUBDEVICE) && (ENABLE_SUBDEVICE==1)
typedef struct {
    GW_PERMIT_ADD_DEV_CB            dev_add;      //permit to add subdevices, see GW_PERMIT_ADD_DEV_CB
    GW_DEV_DEL_CB                   dev_del;      // delete subdevices, see GW_DEV_DEL_CB
    GW_DEV_GRP_INFM_CB              dev_grp;      // the group process command, see GW_DEV_GRP_INFM_CB
    GW_DEV_SCENE_INFM_CB            dev_sce;      // the scene process command, see GW_DEV_SCENE_INFM_CB
    GW_BIND_DEV_INFORM_CB           dev_bind_ifm; // subdevice bind result, see GW_BIND_DEV_INFORM_CB
    GW_DEV_HB_SEND_CB               dev_hb;       // subdevice need to send hearbeat, see GW_DEV_HB_SEND_CB
    GW_DEV_UPGRADE_CB               dev_upgrade;  // subdevice need to upgrade, see GW_DEV_UPGRADE_CB
    GW_DEV_RESET_CB                 dev_reset;    // subdevice is reseted, see GW_DEV_RESET_CB
    GW_DEV_WAKEUP_CB                dev_wakeup;   // wake up the low power subdevice, see GW_DEV_WAKEUP_CB
    #if defined(ENABLE_SIGMESH) && (ENABLE_SIGMESH==1)
    GW_DEV_SIGMESH_TOPO_UPDAET_CB   bt_topo_update;// the sigmesh topo update, see GW_DEV_SIGMESH_TOPO_UPDAET_CB
    GW_DEV_SIGMESH_DEV_CACHE_DEL_CB bt_cache_del;  // the sigmesh dev cahce deleted, see GW_DEV_SIGMESH_DEV_CACHE_DEL_CB
    GW_DEV_SIGMESH_CONN_CB          bt_conn;       // the sigmesh connected, see GW_DEV_SIGMESH_CONN_CB
    GW_BIND_BLE_MESH_DEV_INFORM_CB  bt_bind_ifm;   // the ble mesh subdevice bind result, see GW_BIND_BLE_MESH_DEV_INFORM_CB
    #endif
} TY_IOT_DEV_CBS_S;
#endif

/**
 * @brief reported dp hook callback handlers
 * 
 */
typedef struct {
    VOID (*obj_dp_rept_cb)(CONST CHAR_T *dev_id, CONST TY_OBJ_DP_S *dps, CONST UINT_T dp_cnt);
    VOID (*raw_dp_rept_cb)(CONST CHAR_T *dev_id, BYTE_T dpid, CONST BYTE_T *data, UINT_T len);
} TY_DP_REPORT_HOOK_CBS_S;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /*__TUYA_IOT_SDK_DEFS__ */
