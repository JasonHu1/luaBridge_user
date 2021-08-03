#ifndef __TUYA_GW_USER_DEV_H
#define __TUYA_GW_USER_DEV_H

#include "tuya_gw_user_dev_security.h"
#include "tuya_uf_db.h"

#ifdef __cplusplus
	extern "C" {
#endif


#define GW_DEV_TYPE_SECURITY 0 //安防网关
#define GW_DEV_TYPE  GW_DEV_TYPE_SECURITY  //

OPERATE_RET gw_user_dev_init(VOID);
OPERATE_RET gw_user_data_init(VOID);
OPERATE_RET gw_user_dev_clear_data(VOID);
#if defined(ENABLE_ALARM) && (ENABLE_ALARM==1)
OPERATE_RET tuya_gw_user_dp_cmd_recv(IN CHAR_T *dev_id, IN TY_CMD_U *cmd, IN CHAR_T type);
VOID gw_security_alarm_dev(IN CONST CHAR_T *cid, cJSON *dp_inf);
OPERATE_RET  gw_security_alarm_info_set_cb(IN CONST CHAR_T *mode_str, IN CONST UINT_T time, BOOL_T is_sound);
OPERATE_RET gw_security_sos_alarm(IN CONST CHAR_T *dev_id, IN TY_OBJ_DP_S *dp_data);
OPERATE_RET gw_security_alarm_test_set(BOOL_T is_alarm);
BOOL_T  gw_security_alarm_get_alarm_status(VOID);
VOID gw_security_alarm_delay_status(IN ALARM_DELAY_STATE alarm_status);
VOID gw_security_event(IN SECURITY_EVENT_E security_event, PVOID_T data);
VOID gw_security_cancel_alarm(VOID);
VOID gw_security_enter_alarm(IN BOOL_T alarm_status, IN CHAR_T*alarm_info);
VOID gw_security_alarm_dev_hardware_triggle(HOME_SECURITY_DEV_TRIGGLE dev_triggle);
VOID  gw_security_cloud_link_status(GW_BASE_NW_STAT_T link_status);
OPERATE_RET gw_security_switch_low_battery(BOOL_T status);
VOID gw_security_alarm_voice_play_status(BOOL_T status);
VOID gw_security_alarm_env_dev(CONST CHAR_T *cid, cJSON *dp_inf);

/********************************offline log**********************************/
#if defined(GW_PLATFORM) && (GW_PLATFORM==GW_RTL8711AM)
#define OFFLOG_FILE "offline_log"
#define MAX_DEV_JSON_LEN 512
#define MAX_OFFLOG_FILE_SIZE (12*1024)
#define M_MAX_MSQ_NUM 100
#else
#define OFFLOG_FILE "/data/offline_log"
#define MAX_DEV_JSON_LEN 512
#define MAX_OFFLOG_FILE_SIZE (1*1024*1024)
#define M_MAX_MSQ_NUM 1000
#endif

//一次上报JSON_REP_CNT条json数据
#define JSON_REP_CNT 1

#define TI_OFFLINE_LOG_REPORT "tuya.device.dp.batchreport"
#define TI_OFFLINE_LOG_VERSION "1.0"

typedef struct tygw_offlog_cntl{
    MUTEX_HANDLE mutex;
    BOOL_T has_init;    
    BOOL_T read_init;    
    uFILE *log_fp;
    LONG_T cur_offset;  //离线日志的偏移
    THRD_HANDLE offlog_thread;    
    MSG_ID mid;
    //BOOL_T log_need_report;    
}TYGW_OFFLOG_CNTL;

OPERATE_RET offline_log_init(VOID);
OPERATE_RET offline_dp_save_to_file(IN CONST CHAR_T *dev_id,IN CONST TY_OBJ_DP_S *dp_data,IN CONST UINT_T cnt);


#endif
#ifdef __cplusplus
}
#endif

#endif

