#ifndef HOME_SECURITY_H
#define HOME_SECURITY_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "uni_msg_queue.h"
#include "ty_cJSON.h"
#include "base_thread_pool_gw.h"
#include "tuya_gw_home_security_api.h"

#if defined(ENABLE_ALARM) && (ENABLE_ALARM==1)


#ifdef __cplusplus
extern "C" {
#endif


#define CONDTION_ALARM_STR   "$mode"



BOOL_T check_is_loade_ignore_device(CHAR_T *cid);
OPERATE_RET home_secruity_get_security_mode(OUT CHAR_T *mode_str, INT_T mode_str_buflen);
OPERATE_RET home_secruity_mq_cmd_handle(ty_cJSON *json);
OPERATE_RET home_secruity_info_set(IN CONST CHAR_T *mode_str, IN CONST CHAR_T *node_id, IN CONST CHAR_T *delay_str);
OPERATE_RET home_security_net_mode_set_report(HOME_SECURITY_NET_MODE net_mode);
VOID home_security_alarm_start_countdown(UINT_T delay_time);
//BOOL_T home_security_alarm_judge_delay(VOID);
VOID home_security_alarm_set_delay_start_status(BOOL_T is_bool);
BOOL_T home_security_alarm_get_delay_start_status(VOID);
ALARM_DELAY_STATE home_security_get_alarm_delay_status(VOID);
VOID home_security_set_alarm_delay_status(ALARM_DELAY_STATE alarm_delay_status);
VOID home_security_clear_save(VOID);
OPERATE_RET home_secruity_set_alarm_status(IN CONST BOOL_T alarm_status, IN CONST HOME_SECURITY_INFO_SET_E cmd_from);
BOOL_T home_secruity_get_alarm_status(VOID);
BOOL_T home_security_get_init_status(VOID);
OPERATE_RET home_security_net_mode_get(CHAR_T *net_mode);
VOID home_security_init(VOID);
OPERATE_RET home_secruity_alarm_info_get(OUT ALARM_INFO_S *alarm_info);
OPERATE_RET home_secruity_alarm_dev_new_cb(IN CHAR_T *cid,  IN ty_cJSON *dp_inf, SECURITY_DEV_TYPE_E dev_type);

OPERATE_RET home_security_alarm_start_delay(GW_THREAD_POOL_HANDLE thr_hdl, UINT_T msecond, TM_MSG_S * delay_tm, PVOID_T p_action);


/***********************************************************
*  Function: wd_app_user_if_write
*  Input: key, val, len
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET wd_app_user_if_write(IN CONST CHAR_T *key, IN CONST BYTE_T *val, IN CONST UINT_T len);

/***********************************************************
*  Function: wd_app_user_if_read
*  Input: key,
*  Output: val, len
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET wd_app_user_if_read(IN CONST CHAR_T *key, OUT BYTE_T **val, OUT UINT_T *p_len);

/***********************************************************
*  Function: wd_app_user_if_del
*  Input: key
*  Output: null
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET wd_app_user_if_del(IN CONST CHAR_T *key);

/***********************************************************
*  Function: wd_app_user_if_del_all
*  Input: none
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET wd_app_user_if_del_all(VOID);


BOOL_T gw_is_support_home_security(VOID);

OPERATE_RET gw_set_support_home_security(BOOL_T is_support);


OPERATE_RET home_security_compatible_pre();


#ifdef __cplusplus
};
#endif

#endif

#endif

