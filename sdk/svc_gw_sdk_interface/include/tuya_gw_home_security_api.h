/*
tuya_iot_base_api.h
Copyright(C),2018-2020, 涂鸦科技 www.tuya.comm
*/

#ifndef __TUYA_GW_HOME_SECURITY_API_H
#define __TUYA_GW_HOME_SECURITY_API_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
extern "C" {
#endif


#define HOME_SECURITY_VER "1.0.1"
typedef BYTE_T HOME_SECURITY_INFO_SET_E;
#define HOME_SECURITY_INFO_SET_MQ      0       // cmd from mqtt
#define HOME_SECURITY_INFO_SET_AP      1       // cmd from application
#define HOME_SECURITY_INFO_SET_LAN     2       // cmd from LAN
#define HOME_SECURITY_INFO_SET_SDK     3       // cmd from SDK

#define ALARM_SECURITY_MODE_STR_LEN_MAX 32
#define HOME_SECURITY_ARMED_DISARMED "0"        //撤防,固定为0

typedef enum  {
    HOME_SECURITY_MODE_DISARMED=0,         //撤防
    HOME_SECURITY_MODE_ARMED_STAYING,      //在家布防
    HOME_SECURITY_MODE_ARMED_LEAVING,      //离家布防
    HOME_SECURITY_MODE_BUT,                
}HOME_SECURITY_MODE;

typedef enum  {
    HOME_SECURITY_NET_MODE_WAN=0,     //以太网
    HOME_SECURITY_NET_MODE_WIFI,      //wifi
    HOME_SECURITY_NET_MODE_4G,        //4G
}HOME_SECURITY_NET_MODE;

typedef enum  {
    ALARM_DELAY_DONOT_CREATE=0, //报警延时未创建
    ALARM_DELAY_COUNTDOWN,      //报警延时进行中
    ALARM_DELAY_END,            //报警延时结束
}ALARM_DELAY_STATE;


typedef enum  {
    DISARMED_EVENT,
    ARMED_EVENT,                //进入布防(倒计时后,在家或离家)
    BYPASS_EVNET,               //忽略
    WARING_COUNTDOWN,           //报警倒计时
}SECURITY_EVENT_E;

typedef enum  {
    NO_ENV_DEV,   //非环境设备，如门磁，pir等
    ENV_DEV,      //环境设备，如燃气报警器，co报警器等
}SECURITY_DEV_TYPE_E;


typedef struct {
    CHAR_T alarm_mode[ALARM_SECURITY_MODE_STR_LEN_MAX+1];  // alarm mode
    BOOL_T alarm_status;//报警状态（报警延时，报警中为true）
    BOOL_T enable_countdown_status;//布防延时中为true
}ALARM_INFO_S;


typedef OPERATE_RET (*GW_OFFLINE_DP_SAVE)(IN CONST CHAR_T *dev_id,IN CONST TY_OBJ_DP_S *dp_data,IN CONST UINT_T cnt);

typedef VOID (*GW_HOME_SECURITY_IF_CB)(IN CONST CHAR_T *mode_str, IN CONST UINT_T time, BOOL_T is_sound);
typedef VOID (*GW_HOME_SECURITY_ALARM_DEV_CB)(IN CONST CHAR_T *cid,  IN ty_cJSON *dp_inf);
typedef VOID (*GW_HOME_SECURITY_ALARM_DELAY_STATUS_CB)(IN ALARM_DELAY_STATE alarm_status);
typedef VOID (*GW_HOME_SECURITY_EVENT_CB)(IN SECURITY_EVENT_E security_event_status, PVOID_T data);
typedef VOID (*GW_HOME_SECURITY_CANCEL_ALARM_CB)(VOID);
typedef VOID (*GW_HOME_SECURITY_ALARM_DEV_NEW_CB)(IN CONST CHAR_T *cid,  IN ty_cJSON *dp_inf, SECURITY_DEV_TYPE_E dev_type);
typedef VOID (*GW_HOME_SECURITY_ENTER_ALARM_CB)(IN BOOL_T alarm_status, IN CHAR_T *alarm_info);

typedef struct {
    GW_OFFLINE_DP_SAVE gw_offline_dp_save_cb;

    GW_HOME_SECURITY_IF_CB gw_home_security_if_cb;
    GW_HOME_SECURITY_ALARM_DEV_CB gw_home_security_alarm_dev_cb;//no use, new interface:  gw_home_security_alarm_dev_new_cb
    GW_HOME_SECURITY_ALARM_DEV_CB gw_home_security_alarm_env_dev_cb;//no use, new interface:  gw_home_security_alarm_dev_new_cb
    GW_HOME_SECURITY_ALARM_DELAY_STATUS_CB gw_home_security_alarm_delay_status_cb;
    GW_HOME_SECURITY_EVENT_CB gw_home_security_event_cb;
    GW_HOME_SECURITY_CANCEL_ALARM_CB gw_home_security_cancel_alarm;
    GW_HOME_SECURITY_ALARM_DEV_NEW_CB gw_home_security_alarm_dev_new_cb;//replace dev_cb and env_dev_cb interface,application show
	GW_HOME_SECURITY_ENTER_ALARM_CB gw_home_security_enter_alarm_cb;
}TY_GW_HOME_SECURITY_APP_CBS_S;


/***********************************************************
*  Function: tuya_iot_home_secruity_info_set
*  Input: mode_str: mode str: "0":disarm, "1","2".
*         delay_json: {"1":1000}.mode 1 is delay time 1000s or NULL
*
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_home_secruity_info_set(IN CONST CHAR_T *mode_str, IN CONST CHAR_T *node_id, IN CONST CHAR_T *delay_str);

/***********************************************************
*no use, use new interface tuya_iot_home_secruity_set_alarm_status
*  Function: tuya_iot_home_secruity_alarm_status
*            application must sync alarm status by this interface 
*  Input:  BOOL_T alarm_status: true: alarm status, false: normal status
*
*  Output: none
*  Return: OPERATE_RET
************************************************************/
OPERATE_RET tuya_iot_home_secruity_alarm_status(IN CONST BOOL_T alarm_status);//no use, use new interface tuya_iot_home_secruity_set_alarm_status

/***********************************************************
*  Function: tuya_iot_home_secruity_set_alarm_status
*            application must sync alarm status by this interface 
*  Input:  BOOL_T alarm_status: true: alarm status, false: normal status,HOME_SECURITY_INFO_SET_E cmd_from: HOME_SECURITY_INFO_SET_MQ: from mqtt,
*  HOME_SECURITY_INFO_SET_AP: from app, HOME_SECURITY_INFO_SET_LAN: from lan, HOME_SECURITY_INFO_SET_SDK: from sdk.
*  Output: none
*  Return: OPERATE_RET
************************************************************/
OPERATE_RET tuya_iot_home_secruity_set_alarm_status(IN CONST BOOL_T alarm_status, IN CONST HOME_SECURITY_INFO_SET_E cmd_from);

/***********************************************************
*  Function: tuya_iot_home_secruity_get_alarm_info
*  Input: mode_str: mode str: "0":disarm, "1","2".
*
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_home_secruity_get_alarm_info(OUT ALARM_INFO_S *alarm_info);

/***********************************************************
*  Function: tuya_iot_net_mode_reprot
*  Input: net_mode
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_net_mode_reprot(IN CONST HOME_SECURITY_NET_MODE net_mode);

/***********************************************************
*  Function: tuya_iot_is_support_home_security
*  Input: none
*  Output: none
*  Return: BOOL_T
***********************************************************/
BOOL_T tuya_iot_is_support_home_security(VOID);

/***********************************************************
*  Function: tuya_iot_support_home_security_set
*  Input: is_support： TRUE/FALSE support home security,must init,
*                   the interface was used to the new and old versions compatible
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_support_home_security_set(BOOL_T is_support);


VOID tuya_gw_home_security_app_cbs_init(IN CONST TY_GW_HOME_SECURITY_APP_CBS_S *app_cbs);


#ifdef __cplusplus
}
#endif
#endif

