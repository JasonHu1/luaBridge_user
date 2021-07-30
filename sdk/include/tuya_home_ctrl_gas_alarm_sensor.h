/**
* @file tuya_home_ctrl_gas_alarm_sensor.h
* @author diao(HongWangZheng) (diao.hong@tuya.com)
* @brief 中控SDK，燃气报警传感器品类
* @version 0.1
* @date 2021-05-02
* 
* @copyright Copyright (c) 2021
* 
*/

#ifndef __TUYA_HOME_CTRL_GAS_ALARM_SENSOR__
#define __TUYA_HOME_CTRL_GAS_ALARM_SENSOR__

/**
 * @defgroup product_type_gas_alarm_sensor 燃气报警传感器品类
 * @{
 */
 
 #pragma pack(1)
 
 /**
 * @name 燃气报警传感器支持的DP
 * @{
 */
#define HOME_CTRL_GAS_ALARM_SENSOR_MUFFLING            "muffling"            ///< 消音 @remark 类型 Boolean
#define HOME_CTRL_GAS_ALARM_SENSOR_ALARM_RINGTONE      "alarm_ringtone"      ///< 报警铃声 @remark 类型 Enum @remark 取值说明 {"range":["1","2","3","4","5"]}
#define HOME_CTRL_GAS_ALARM_SENSOR_ALARM_TIME          "alarm_time"          ///< 报警时长 @remark 类型 Integer @remark 取值说明 {"unit":"","min":1,"max":60,"scale":0,"step":1}
#define HOME_CTRL_GAS_ALARM_SENSOR_SELF_CHECKING       "self_checking"       ///< 设备自检 @remark 类型 Boolean
#define HOME_CTRL_GAS_ALARM_SENSOR_ALARM_VOLUME        "alarm_volume"        ///< 报警音量 @remark 类型 Enum @remark 取值说明 {"range":["low","middle","high","mute"]}
#define HOME_CTRL_GAS_ALARM_SENSOR_ALARM_SWITCH        "alarm_switch"        ///< 报警开关 @remark 类型 Boolean
#define HOME_CTRL_GAS_ALARM_SENSOR_PREHEAT             "preheat"             ///< 是否预热中 @remark 类型 Boolean
#define HOME_CTRL_GAS_ALARM_SENSOR_TEMPER_ALARM        "temper_alarm"        ///< 防拆报警 @remark 类型 Boolean
#define HOME_CTRL_GAS_ALARM_SENSOR_LIFECYCLE           "lifecycle"           ///< 使用寿命 @remark 类型 Boolean
#define HOME_CTRL_GAS_ALARM_SENSOR_CHECKING_RESULT     "checking_result"     ///< 设备自检结果 @remark 类型 Enum @remark 取值说明 {"range":["checking","check_success","check_failure","others"]}
#define HOME_CTRL_GAS_ALARM_SENSOR_BATTERY_PERCENTAGE  "battery_percentage"  ///< 电池电量百分比 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1}
#define HOME_CTRL_GAS_ALARM_SENSOR_BATTERY_VALUE       "battery_value"       ///< 电池电量值 @remark 类型 Integer @remark 取值说明 {"unit":"","min":0,"max":30000,"scale":0,"step":1}
#define HOME_CTRL_GAS_ALARM_SENSOR_BATTERY_STATE       "battery_state"       ///< 电池电量状态 @remark 类型 Enum @remark 取值说明 {"range":["low","middle","high"]}
#define HOME_CTRL_GAS_ALARM_SENSOR_GAS_SENSOR_VALUE    "gas_sensor_value"    ///< 燃气检测值 @remark 类型 Integer @remark 取值说明 {"unit":"","min":0,"max":1000,"scale":1,"step":1}
#define HOME_CTRL_GAS_ALARM_SENSOR_GAS_SENSOR_STATUS   "gas_sensor_status"   ///< 燃气检测状态值 @remark 类型 Enum @remark 取值说明 {"range":["alarm","normal"]}

/** @} */

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for group product_type_gas_alarm_sensor

#endif // __TUYA_HOME_CTRL_GAS_ALARM_SENSOR__