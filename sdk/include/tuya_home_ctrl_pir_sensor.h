/**
* @file tuya_home_ctrl_pir.h
* @author diao(HongWangZheng) (diao.hong@tuya.com)
* @brief 中控SDK，pir传感器品类
* @version 0.1
* @date 2021-05-02
* 
* @copyright Copyright (c) 2021
* 
*/

#ifndef __TUYA_HOME_CTRL_PIR__
#define __TUYA_HOME_CTRL_PIR__

/**
 * @defgroup product_type_pir pir传感器品类
 * @{
 */

#pragma pack(1)
 
 /**
 * @name pir传感器支持的DP
 * @{
 */
#define HOME_CTRL_PIR_SENSOR_PIR                "pir"                   ///< 人体感应状态 @remark 类型 Enum @remark 取值说明 {"range":["pir","none"]}
#define HOME_CTRL_PIR_SENSOR_TEMPER_ALARM       "temper_alarm"          ///< 防拆报警 @remark 类型 Boolean
#define HOME_CTRL_PIR_SENSOR_BATTERY_PERCENTAGE "battery_percentage"    ///< 电池电量百分比 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1}
#define HOME_CTRL_PIR_SENSOR_BATTERY_STATE      "battery_state"         ///< 电池电量状态 @remark 类型 Enum @remark 取值说明 {"range":["low","middle","high"]}
#define HOME_CTRL_PIR_SENSOR_BATTERY            "battery"               ///< 电池电量 @remark 类型 	Integer @remark 取值说明 {"unit":"","min":0,"max":10000,"scale":0,"step":1}
#define HOME_CTRL_PIR_SENSOR_BATTERY_VALUE      "battery_value"         ///< 电池电量值 @remark 类型 Integer @remark 取值说明 {"unit":"","min":0,"max":30000,"scale":0,"step":1}


/** @} */

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for group product_type_pir

#endif // __TUYA_HOME_CTRL_PIR__