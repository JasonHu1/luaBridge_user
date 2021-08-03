#ifndef __TUYA_GW_USER_DEV_SECURITY_H
#define __TUYA_GW_USER_DEV_SECURITY_H


#ifdef __cplusplus
	extern "C" {
#endif

#include <stdio.h>
#include <pthread.h>
#include "tuya_cloud_com_defs.h"
#include <string.h>
#include "uni_log.h"
#include "uni_thread.h"
#include "tuya_hal_system.h"
#include "sys_timer.h"
#include "uni_time.h"
#include "tuya_ws_db.h"
#include "mem_pool.h"
#include "tuya_gw_com_api.h"
#include "ty_cJSON.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "gw_intf.h"
#include "gw_com_def.h"
#include "tuya_hal_wired.h"
#include "home_security.h"

#if defined(ENABLE_ALARM) && (ENABLE_ALARM==1)

//云端下发的
#define HOME_SECURITY_ARMED_STAYING  "1"   //在家布防 "armed_staying"
#define HOME_SECURITY_ARMED_LEAVING  "2"   //离家布防 "armed_leaving"

typedef enum  {
    ALARM_STATE_DISARMED=0,   //未报警
    ALARM_STATE_DELAY_ALARM,  //延时中
    ALARM_STATE_ALARMING,     //正在报警
}HOME_SECURITY_ALARM_STATE;

typedef enum  {
    ALARM_FORM_DEV=0,   //报警来自设备联动触发
    ALARM_FORM_KEYPAD,  //报警来自按键报警
    ALARM_FORM_APP_SOS,  //报警来自app上的sos
    ALARM_FORM_APP_TEST,  //报警来自app上的TEST
    ALARM_FORM_TAMPER,   //防拆报警
}HOME_SECURITY_ALARM_SOURCE;

typedef enum  {
    DISALARM_FORM_APP_DISALARM=0,   //解除报警来自app的撤防
    DISALARM_FORM_OTHER,            //解除报警来自其他触发
    DISALARM_FORM_APP_SOS,          //解除报警来自app上sos的取消
    DISALARM_FORM_APP_TEST,         //解除报警来自app上的TEST按键
}HOME_SECURITY_DISALARM_SOURCE;

typedef enum  {
    ALARM_VOLUME_LOW=0,   //解除报警来自app的撤防
    ALARM_VOLUME_MIDDLE,            //解除报警来自其他触发
    ALARM_VOLUME_HIGH,          //解除报警来自app上sos的取消
    ALARM_VOLUME_MUTE,         //解除报警来自app上的TEST按键
}HOME_SECURITY_ALARM_VOLUME;

typedef enum  {
    SYSTEM_VOLUME_LOW=0,   //系统音量低
    SYSTEM_VOLUME_MIDDLE,  //系统音量中
    SYSTEM_VOLUME_HIGH,    //系统音量高
    SYSTEM_VOLUME_MUTE,    //系统音量静音
}HOME_SECURITY_SYSTEM_VOLUME;

typedef struct {
    UINT_T system_volume;   //系统音量
    BOOL_T alarm_station;  //网关报警
	UINT_T alarm_staying_delay;    //延时报警时间 don't use now
    UINT_T alarm_leaving_delay;    //延时报警时间 don't use now
    UINT_T alarm_countdown;
    UINT_T alarm_time;        //报警时长
    UINT_T alarm_volume;   //报警音量
	BOOL_T alarm_test;     //报警测试
	BOOL_T alarm_sos;      //sos报警，与撤防布防无关
	BOOL_T alarm_tamper;      //防拆报警
	BOOL_T power_state;      //充电状态
	HOME_SECURITY_NET_MODE cur_netdev;
    //HOME_SECURITY_MODE security_mode;  //安防模式
	CHAR_T *alarm_id_list;
	CHAR_T *alarm_env_id_list;
    TM_MSG_S *tmm_security_state_update;
    HOME_SECURITY_ALARM_STATE alarm_state;
    CHAR_T security_cur_mode[ALARM_SECURITY_MODE_STR_LEN_MAX+1];
    ALARM_DELAY_STATE alarm_delay;
    GW_BASE_NW_STAT_T link_status;
    BOOL_T vol;//当前是否在播放声音
    INT_T pri;// voice pri
    BOOL_T low_battery;
    BOOL_T nl_switch; //night light 1:ON/0:OFF flag
    INT_T  nl_color;//night light color settings 
    //USHORT_T nl_delay_off; //night light delay off (0~300)
    UCHAR_T nl_bright;//night light bright (0~100)
    
    UCHAR_T doorbell_volume;   //门铃音量
    UCHAR_T doorbell_ringtone;//门铃铃声
    UCHAR_T dorrbell_ringTimes;//门铃响铃次数
}DEV_SECURITY_DATA_S;

typedef enum  {
    DOOR_SENSORS=0,   //门磁

}HOME_SECURITY_DEV_TRIGGLE;

OPERATE_RET security_alarm_switch_low_battery(BOOL_T status);
VOID security_alarm_voice_play_status(BOOL_T status);
VOID security_alarm_dev_hardware_handle(HOME_SECURITY_DEV_TRIGGLE dev_triggle);
BOOL_T security_alarm_get_alarm_status(VOID);
OPERATE_RET security_alarm_sos(IN CONST CHAR_T *dev_id, IN TY_OBJ_DP_S *dp_data);
OPERATE_RET  security_alarm_info_set_cb(IN CONST CHAR_T *mode_str, IN CONST UINT_T time, BOOL_T is_sound);
VOID security_alarm_dev(CONST CHAR_T *cid, ty_cJSON *dp_inf);
VOID security_alarm_delay_status(IN ALARM_DELAY_STATE alarm_status);
VOID security_event(IN SECURITY_EVENT_E security_event_status, PVOID_T data);
VOID security_cancel_alarm(VOID);
VOID security_enter_alarm(IN BOOL_T alarm_status, IN CHAR_T*alarm_info);
VOID security_dp_cmd_recv(IN TY_CMD_U *dp, IN CHAR_T type);
VOID security_alarm_cloud_link_status(GW_BASE_NW_STAT_T link_status);
OPERATE_RET security_dev_clear_data(VOID);
OPERATE_RET security_data_init(VOID);
OPERATE_RET security_dev_init(VOID);
OPERATE_RET security_alarm_list_report(IN CHAR_T *list_id);
VOID security_alarm_env_dev(CONST CHAR_T *cid, cJSON *dp_inf);

VOID security_alarm_xiaoying(BOOL_T status);
OPERATE_RET security_night_light_report_cb(BOOL_T on_off);

#endif
#ifdef __cplusplus
}
#endif

#endif

