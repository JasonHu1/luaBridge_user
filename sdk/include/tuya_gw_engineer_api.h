/*
tuya_gw_engineer_api.h
Copyright(C),2018-2020, 涂鸦科技 www.tuya.comm
*/

#ifndef __TUYA_GW_ENGINEER_API_H
#define __TUYA_GW_ENGINEER_API_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
extern "C" {
#endif


/***********************************************************
*  callback function: GW_UG_LAN_INFORM_CB
*  Desc:    gateway ota firmware available nofity callback in lan.
*  Input:   fw: firmware info
***********************************************************/

typedef OPERATE_RET (*GW_UG_LAN_INFORM_CB)(IN CONST FW_UG_S *fw);

typedef OPERATE_RET (*DEV_UG_LAN_INFORM_CB)(IN CONST CHAR_T *dev_id,IN CONST FW_UG_S *fw);

typedef OPERATE_RET (*GW_SET_CHANNEL_CB)(IN INT_T channel);
typedef OPERATE_RET (*GW_GET_CHANNEL_CB)(OUT INT_T *channel);
typedef OPERATE_RET (*GW_GET_LOG_CB)(OUT CHAR_T *path, IN CONST INT_T len);
typedef OPERATE_RET (*GW_SYNC_CONFIG_CB)(VOID);
typedef OPERATE_RET (*GW_ENG_FIN_CB)(VOID);

typedef struct {
    INT_T btn;
    CHAR_T *grp;
    CHAR_T *sce;
    CHAR_T *sce_name;
}SCE_PANEL_S;
typedef OPERATE_RET (*GW_SCE_PANEL_BIND_CB)(IN CONST CHAR_T *dev_id,IN CONST SCE_PANEL_S *sce_panel, IN CONST INT_T btn_num);

typedef OPERATE_RET (*GW_ENG_RESET_CB)(VOID);

typedef VOID (*ENGR_TO_NORMAL_FINISH_CB)(IN CONST CHAR_T* path);

typedef struct {
    GW_UG_LAN_INFORM_CB gw_lan_ug_cb;  /*!< 局域网网关固件升级通知信息回调函数，可以为NULL */
    DEV_UG_LAN_INFORM_CB dev_lan_ug_cb;
    GW_SET_CHANNEL_CB gw_set_channel_cb;
    GW_GET_CHANNEL_CB gw_get_channel_cb;
    GW_GET_LOG_CB gw_get_log_cb;
    GW_SYNC_CONFIG_CB gw_sync_config_cb;
    GW_ENG_FIN_CB gw_engineer_finish_cb;
    GW_SCE_PANEL_BIND_CB gw_sce_panel_cb;
    GW_ENG_RESET_CB gw_eng_reset_cb;
}GW_CBS_ENGR_S;

//工程模式初始化，cbs为工程模式回调接口集合
OPERATE_RET tuya_gw_engr_advance_init(IN GW_CBS_ENGR_S *cbs);

/***********************************************************
*  Function: tuya_iot_set_engineer_mode
*  Desc:     set tuya_iot_sdk in engineer mode
*  Return:   sdk info
***********************************************************/
VOID tuya_iot_set_engineer_mode(VOID);

/***********************************************************
*  Function: tuya_iot_get_engineer_mode
*  Desc:     get whether tuya_iot_sdk in engineer mode.
*  Return:   TRUE: in engineer mode.
***********************************************************/
BOOL_T tuya_iot_get_engineer_mode(VOID);

/***********************************************************
*  Function: tuya_iot_gw_engineer_check
*  Desc:     gw started from engineer mode to normal mode.
*  Return:   TRUE: OPERATE_RET.
***********************************************************/
OPERATE_RET tuya_iot_gw_engineer_check(IN CONST CHAR_T *engineer_path, ENGR_TO_NORMAL_FINISH_CB cb);

/***********************************************************
*  Function: engr_del_all_sub_dev
*  Desc:     delete all subdev in engineer mode.
*  Return:   void
***********************************************************/
VOID engr_del_all_sub_dev(VOID);

/***********************************************************
*  Function: tuya_iot_engr_extra_lan_data_report
*  Desc:     工程模式局域网扩展协议发送
*  Return:   TRUE: OPERATE_RET.
***********************************************************/
OPERATE_RET tuya_iot_engr_extra_lan_data_report(IN CHAR_T *data);

/***********************************************************
*  Function: tuya_iot_gw_engineer_pre_init
*  Desc:     工程功能预初始化接口，需要使用工程功能时，普通模式和工程模式在tuya_iot_entity_init之前调用该接口
*  Return:   TRUE: OPERATE_RET.
***********************************************************/
OPERATE_RET tuya_iot_gw_engineer_pre_init(IN CONST CHAR_T *product_key);


#ifdef __cplusplus
}
#endif
#endif

