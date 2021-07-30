/**
 * @file tuya_home_ctrl_fresh_air.h
 * @author diao(HongWangZheng) (diao.hong@tuya.com)
 * @brief 中控SDK，新风品类
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CTRL_FRESH_AIR__
#define __TUYA_HOME_CTRL_FRESH_AIR__

/**
 * @defgroup product_type_fresh_air 新风品类
 * @{
 */

/**
 * @name 新风支持的DP
 * @{
 */
#define HOME_CTRL_FRESH_AIR_SWITCH "switch"                             ///< 开关 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_MODE "mode"                                 ///< 工作模式 @remark 类型 Enum @remark 取值说明 {"range":["auto","sleep","manual"],"type":"enum"}
#define HOME_CTRL_FRESH_AIR_PM25 "pm25"                                 ///< PM2.5 @remark 类型 Integer @remark 取值说明 {"min":0,"max":999,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_UV_LIGHT "uv_light"                         ///< UV灯 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_ANION "anion"                               ///< 负离子 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_ECO2 "eco2"                                 ///< eCO2 @remark 类型 Integer @remark 取值说明 {"min":0,"max":1000,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_TVOC "tvoc"                                 ///< TVOC @remark 类型 Integer @remark 取值说明 {"min":0,"max":1000,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_HUMIDITY_INDOOR "humidity_indoor"           ///< 室内湿度 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_TEMP_INDOOR "temp_indoor"                   ///< 室内温度 @remark 类型 Integer @remark 取值说明 {"unit":"℃","min":0,"max":50,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_UV_LIFE "uv_life"                           ///< UV寿命 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_FILTER_LIFE "filter_life"                   ///< 滤网寿命 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_FAN_SPEED_ENUM "fan_speed_enum"             ///< 风速 @remark 类型 Enum @remark 取值说明 {"range":["low","mid","high","sleep"],"type":"enum"}
#define HOME_CTRL_FRESH_AIR_FILTER_RESET "filter_reset"                 ///< 滤芯复位 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_CHILD_LOCK "child_lock"                     ///< 童锁开关 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_FACTORY_RESET "factory_reset"               ///< 恢复出厂设置 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_COUNTDOWN_SET "countdown_set"               ///< 倒计时 @remark 类型 Enum @remark 取值说明 {"range":["cancel","1h","2h","3h","4h","5h","6h"],"type":"enum"}
#define HOME_CTRL_FRESH_AIR_COUNTDOWN_LEFT "countdown_left"             ///< 倒计时剩余时间 @remark 类型 Integer @remark 取值说明 {"unit":"min","min":0,"max":360,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_FAULT "fault"                               ///< 故障告警 @remark 类型 Bitmap @remark 取值说明 {"label":["e1"],"type":"bitmap","maxlen":1}
#define HOME_CTRL_FRESH_AIR_HCHO_SENSOR_VALUE "hcho_sensor_value"       ///< 室外湿度 @remark 类型 Integer @remark 取值说明 {"unit":"mg/m3","min":0,"max":1000,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_PM10 "pm10"                                 ///< PM10 @remark 类型 Integer @remark 取值说明 {"unit":"μg/m3","min":0,"max":999,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_HUMIDITY_OUTDOOR "humidity_outdoor"         ///< 室外湿度 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_TEMP_OUTDOOR "temp_outdoor"                 ///< 室外温度 @remark 类型 Integer @remark 取值说明 {"unit":"℃","min":-50,"max":50,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_AIR_QUALITY "air_quality"                   ///< 空气质量 @remark 类型 Enum @remark 取值说明 {"range":["great","good","mild","medium","bad"],"type":"enum"}
#define HOME_CTRL_FRESH_AIR_AIR_VOLUME "air_volume"                     ///< 风量 @remark 类型 Integer @remark 取值说明 {"unit":"m3/h","min":0,"max":1000,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_LOOP_MODE "loop_mode"                       ///< 循环模式 @remark 类型 Enum @remark 取值说明 {"range":["auto","indoor_loop","outdoor_loop"],"type":"enum"}
#define HOME_CTRL_FRESH_AIR_SUPPLY_FAN_SPEED "supply_fan_speed"         ///< 送风风速 @remark 类型 Enum @remark 取值说明 {"range":["off","low","mid","high"],"type":"enum"}
#define HOME_CTRL_FRESH_AIR_EXHAUST_FAN_SPEED "exhaust_fan_speed"       ///< 排风风速 @remark 类型 Enum @remark 取值说明 {"range":["off","low","mid","high"],"type":"enum"}
#define HOME_CTRL_FRESH_AIR_SUPPLY_TEMP "supply_temp"                   ///< 送风温度 @remark 类型 Integer @remark 取值说明{"unit":"℃","min":-50,"max":50,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_EXHAUST_TEMP "exhaust_temp"                 ///< 排风温度 @remark 类型 Integer @remark 取值说明 {"unit":"℃","min":-50,"max":50,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_SUPPLY_AIR_VOL "supply_air_vol"             ///< 送风风量 @remark 类型 Integer @remark 取值说明 {"min":0,"max":1000,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_EXHAUST_AIR_VOL "exhaust_air_vol"           ///< 排风风量 @remark 类型 Integer @remark 取值说明 {"min":0,"max":1000,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_FRESH_AIR_VALVE "fresh_air_valve"           ///< 新风阀 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_AIR_EXHAUST_FAN "air_exhaust_fan"           ///< 排风扇 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_PRIMARY_FILTER_LIFE "primary_filter_life"   ///< 初效滤网剩余/寿命 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_PRIMARY_FILTER_RESET "primary_filter_reset" ///< 初效滤网复位 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_MEDIUM_FILTER_LIFE "medium_filter_life"     ///< 中效滤网剩余/寿命 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_MEDIUM_FILTER_RESET "medium_filter_reset"   ///< 中效滤网复位 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_HIGH_FILTER_LIFE "high_filter_life"         ///< 高效滤网剩余/寿命 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_HIGH_FILTER_RESET "high_filter_reset"       ///< 高效滤网复位 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_STERILIZE "sterilize"                       ///< 杀菌 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_BYPASS_FUNCTION "bypass_function"           ///< 旁通功能 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_HEAT "heat"                                 ///< 加热 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_PM25_SET "pm25_set"                         ///< PM2.5参数设定 @remark 类型 Integer @remark 取值说明 {"unit":"μg/m3","min":1,"max":999,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_ECO2_SET "eco2_set"                         ///< eCO2参数设定 @remark 类型 Integer @remark 取值说明 {"unit":"ppm","min":1,"max":1000,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_TEMP_SET "temp_set"                         ///< 温度设置 @remark 类型 Integer @remark 取值说明 {"unit":"℃","min":-50,"max":50,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_HUMIDITY_SET "humidity_set"                 ///< 湿度设置 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_TVOC_SET "tvoc_set"                         ///< TVOC参数设定 @remark 类型 Integer @remark 取值说明 {"unit":"ppm","min":1,"max":1000,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_AIR_CONDITIONING "air_conditioning"         ///< 空调 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_BACKLIGHT "backlight"                       ///< 背光亮度 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1,"type":"value"}
#define HOME_CTRL_FRESH_AIR_PURIFY_MODE "purify_mode"                   ///< 净化模式 @remark 类型 Enum @remark 取值说明 {"range":["high","low"],"type":"enum"}
#define HOME_CTRL_FRESH_AIR_PURIFICATION "purification"                 ///< 净化/除尘 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_DEHUMIDIFIER "dehumidifier"                 ///< 除湿 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_DEFROST "defrost"                           ///< 除霜 @remark 类型 Boolean
#define HOME_CTRL_FRESH_AIR_PM10_SET "pm10_set"                         ///< PM10参数设定 @remark 类型 Integer @remark 取值说明 {"unit":"mg/m3","min":0,"max":999,"scale":0,"step":1,"type":"value"}
/** @} */

#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for gourp product_type_fresh_air

#endif // __TUYA_HOME_CTRL_AC__