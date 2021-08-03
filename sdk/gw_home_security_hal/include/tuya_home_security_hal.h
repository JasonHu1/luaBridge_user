#ifndef __TUYA_HOME_SECURITY_HAL_H
#define __TUYA_HOME_SECURITY_HAL_H

#include "tuya_cloud_types.h"
#include "uni_log.h"
#ifdef __cplusplus
	extern "C" {
#endif

#if defined(ENABLE_ALARM) && (ENABLE_ALARM==1)
typedef enum{
    NONE_LOOP_LED = -1,
    JOIN_CLOUND_START = 0,
    JOIN_CLOUND_NOT_START,
    JOIN_CLOUND_SUCCESS,
    DISARM_STAT,
    ARM_LEAVING_STAT,
    ARM_HOME_STAT,
    WARNING_STAT,
    ARM_DELAY_STAT,
    WARNING_DELAY_STAT,
    MAX_LOOP_LED_STA,
}LOOP_LED_STATUS;

#if defined(GW_PLATFORM) && (GW_PLATFORM==GW_RTL8197F)
#define STAY_ARM_MODE 1
#define AWAY_ARM_MODE 2
#endif

VOID tuya_hal_gw_security_alarm(INT_T dp_val, UINT_T time);
VOID tuya_hal_gw_security_alarm_cancel(VOID);
VOID tuya_hal_gw_security_alarm_mute(BOOL_T mute_on);
VOID tuya_hal_gw_security_disalarm(INT_T volume);
VOID tuya_hal_gw_security_away_and_armed(INT_T volume);
VOID tuya_hal_gw_security_home_and_armed(INT_T volume);
VOID tuya_hal_gw_security_ignore(INT_T volume);
VOID tuya_hal_gw_security_set_arm_status(INT_T arm_status);
VOID tuya_hal_gw_security_arming_countdown(INT_T volume, UINT_T countdown_time);
VOID tuya_hal_gw_security_warning_countdown(INT_T volume, UINT_T countdown_time);
VOID tuya_hal_gw_security_alarm_door(INT_T volume);
VOID tuya_hal_gw_security_set_arm_color(INT_T arm_status);
VOID tyua_hal_gw_security_set_nl_color(INT_T color);
VOID tyua_hal_gw_security_set_nl_brightness(INT_T brightness);
VOID tyua_hal_gw_security_set_nl_swtich(INT_T on);
VOID tyua_hal_gw_security_set_system_vol(INT_T volume);
VOID tuya_hal_gw_security_door_ringing(UCHAR_T ring_tone_index, UCHAR_T volume, UCHAR_T door_ring_times);
VOID tuya_hal_gw_security_alarm_dev(INT_T volume, CHAR_T *dev_voice_name);
VOID tyua_hal_gw_security_set_nl_color_HSV(CHAR_T *hsv);
VOID tyua_hal_gw_security_hsv_2_color(CHAR_T *hsv, INT_T* color_rgb);
VOID tuya_hal_gw_security_set_clock(UCHAR_T ringtone, UCHAR_T volume);
VOID tuya_hal_gw_security_set_clock_vol(UCHAR_T volume);
VOID tuya_hal_gw_security_set_clock_play(UCHAR_T ringtone);

#endif

#ifdef __cplusplus
}
#endif

#endif

