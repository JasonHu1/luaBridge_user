/**
 * @file tuya_home_ctrl_air_purifier.h
 * @author diao(HongWangZheng) (diao.hong@tuya.com)
 * @brief 中控SDK，空气净化器品类
 * @version 0.1
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CTRL_AIR_PURIFIER__
#define __TUYA_HOME_CTRL_AIR_PURIFIER__

/**
 * @defgroup product_type_air_purifier 空气净化器品类
 * @{
 */


/**
 * @name 空气净化器支持的DP
 * @{
 */
#define HOME_CTRL_AIR_PURIFIER_SWITCH          "switch"          ///< 开关 @remark 类型 Boolean
#define HOME_CTRL_AIR_PURIFIER_MODE            "mode"            ///< 模式 @remark 类型 Enum @remark 取值说明 {"range":["auto","sleep","manual","pollen","comfortable","strong"]}
#define HOME_CTRL_AIR_PURIFIER_SPEED           "speed"           ///< 风速档位 @remark 类型 Enum @remark 取值说明 {"range":["1","2","3","4","5","6"]}
#define HOME_CTRL_AIR_PURIFIER_FAN_SPEED_ENUM  "fan_speed_enum"  ///< 风速模式 @remark 类型 Enum @remark 取值说明 {"range":["sleep","low","mid","high","auto"]}
#define HOME_CTRL_AIR_PURIFIER_ANION           "anion"           ///< 负离子 @remark 类型 Boolean
#define HOME_CTRL_AIR_PURIFIER_LOCK            "lock"            ///< 童锁 @remark 类型 Boolean
#define HOME_CTRL_AIR_PURIFIER_LIGHT           "light"           ///< 灯光 @remark 类型 Boolean
#define HOME_CTRL_AIR_PURIFIER_UV              "uv"              ///< UV 杀菌 @remark 类型 Boolean
#define HOME_CTRL_AIR_PURIFIER_WET             "wet"             ///< 加湿 @remark 类型 Boolean
#define HOME_CTRL_AIR_PURIFIER_FILTER_RESET    "filter_reset"    ///< 滤芯复位 @remark 类型 Boolean
#define HOME_CTRL_AIR_PURIFIER_COUNTDOWN_SET   "countdown_set"   ///< 倒计时 @remark 类型 Enum @remark 取值说明 {"range":["cancel","1h","2h","3h","4h","5h"]}
#define HOME_CTRL_AIR_PURIFIER_FILTER          "filter"          ///< 滤芯使用率 @remark 类型 Integer @remark 取值说明 {"unit":"％","min":0,"max":100,"scale":0,"step":1}
#define HOME_CTRL_AIR_PURIFIER_PM25            "pm25"            ///< PM2.5 @remark 类型 Integer @remark 取值说明 {"unit":"","min":0,"max":999,"scale":0,"step":1}
#define HOME_CTRL_AIR_PURIFIER_TEMP            "temp"            ///< 室内温度 @remark 类型 Integer @remark 取值说明 {"unit":"℃","min":-20,"max":50,"scale":0,"step":1}
#define HOME_CTRL_AIR_PURIFIER_HUMIDITY        "humidity"        ///< 室内湿度 @remark 类型 Integer @remark 取值说明 {"unit":"％","min":0,"max":100,"scale":0,"step":1}
#define HOME_CTRL_AIR_PURIFIER_TVOC            "tvoc"            ///< TVOC @remark 类型 Integer @remark 取值说明 {"unit":"ppm","min":0,"max":1000,"scale":0,"step":1}
#define HOME_CTRL_AIR_PURIFIER_ECO2            "eco2"            ///< eCO2 @remark 类型 Integer @remark 取值说明 {"unit":"ppm","min":0,"max":5000,"scale":0,"step":1}
#define HOME_CTRL_AIR_PURIFIER_FILTER_DAYS     "filter_days"     ///< 滤芯剩余天数 @remark 类型 Integer @remark 取值说明 {"unit":"day","min":0,"max":1000,"scale":0,"step":1}
#define HOME_CTRL_AIR_PURIFIER_TOTAL_TIME      "total_time"      ///< 累计运行时间 @remark 类型 Integer @remark 取值说明 {"unit":"min","min":0,"max":5256000,"scale":0,"step":1}
#define HOME_CTRL_AIR_PURIFIER_TOTAL_PM        "total_pm"        ///< 累计吸收颗粒 @remark 类型 Integer @remark 取值说明 {"unit":"mg","min":0,"max":10000000,"scale":0,"step":1}
#define HOME_CTRL_AIR_PURIFIER_COUNTDOWN_LEFT  "countdown_left"  ///< 倒计时剩余时间 @remark 类型 Integer @remark 取值说明 {"unit":"min","min":0,"max":360,"scale":0,"step":1}
#define HOME_CTRL_AIR_PURIFIER_AIR_QUALITY     "air_quality"     ///< 室内空气质量 @remark 类型 Enum @remark 取值说明 {"range":["great","mild","good","medium","severe"]}


/** @} */

#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for gourp product_type_air_purifier

#endif // __TUYA_HOME_CTRL_AIR_PURIFIER__