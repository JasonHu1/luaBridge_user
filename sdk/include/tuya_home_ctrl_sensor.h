/**
* @file tuya_home_ctrl_sensor.h
* @author diao(HongWangZheng) (diao.hong@tuya.com)
* @brief 中控SDK，通用传感器支持的指令集和状态集
* @version 0.1
* @date 2021-05-02
* 
* @copyright Copyright (c) 2021
* 
*/

#ifndef __TUYA_HOME_CTRL_SENSOR__
#define __TUYA_HOME_CTRL_SENSOR__

/**
 * @defgroup product_type_sensor 通用传感器
 * @{
 */
 
 #pragma pack(1)

 /**
 * @name 通用传感器支持的DP
 * @{
 */
#define HOME_CTRL_SENSOR_TEMPER_ALARM        "temper_alarm"        ///< 防拆报警 @remark 类型 Boolean
#define HOME_CTRL_SENSOR_BATTERY_PERCENTAGE  "battery_percentage"  ///< 电池电量百分比 @remark 类型 Integer @remark 取值说明 {"unit":"%" ,"min":0 ,"max":100 ,"scale":0 ,"step":1}
#define HOME_CTRL_SENSOR_BATTERY_VALUE       "battery_value"       ///< 电池电量值 @remark 类型 Integer @remark 取值说明 {"unit":"","min":0,"max":30000,"scale":0,"step":1}
#define HOME_CTRL_SENSOR_BATTERY_STATE       "battery_state"       ///< 电池电量状态 @remark 类型 Enum @remark 取值说明 {"range":["low" ,"middle" ,"high"]}


/** @} */

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for group product_type_sensor

#endif // __TUYA_HOME_CTRL_SENSOR__