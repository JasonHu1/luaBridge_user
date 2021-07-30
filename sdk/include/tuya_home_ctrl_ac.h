/**
 * @file tuya_home_ctrl_ac.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 中控SDK，空调品类
 * @version 0.1
 * @date 2021-03-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CTRL_AC__
#define __TUYA_HOME_CTRL_AC__

/**
 * @defgroup product_type_ac 空调品类
 * @{
 */


/**
 * @name 空调支持的DP
 * @{
 */
#define HOME_CTRL_AC_SWITCH "switch"                        ///< 开关 @remark 类型 Boolean
#define HOME_CTRL_AC_TEMP_SET "temp_set"                    ///< 设置摄氏温度 @remark 类型 Integer @remark 取值说明 {“min”:0,“unit”:“℃”, “scale”:0,“max”:50,“type”:“value”, “step”:1}
#define HOME_CTRL_AC_TEMP_CURRENT "temp_current"            ///< 当前温度 @remark 类型 Integer @remark 取值说明 {“min”:-20,“unit”:“℃”, “scale”:0,“max”:100,“type”:“value”, “step”:1} @warning 某些设备的取值有缩放，如{“min”:0,“unit”:“℃”, “scale”:1,“max”:1000,“type”:“value”, “step”:1},使用的时候请注意
#define HOME_CTRL_AC_MODE "mode"                            ///< 工作模式 @remark 类型 Enum @remark 取值说明 {“range”:[“auto”, “cold”, “hot”, “wet”, “wind”, “eco”, “floor_heat”, “floor_heat_and_heat”]}
#define HOME_CTRL_AC_FAN_SPEED_ENUM "fan_speed_enum"        ///< 风速模式 @remark 类型 Enum @remark 取值说明 {“range”:[“low”, “mid”, “high”, “auto”, “strong”]}
#define HOME_CTRL_AC_MODE_ECO "mode_eco"                    ///< ECO 模式 @remark 类型 Boolean
#define HOME_CTRL_AC_HEAT "heat"                            ///< 辅热 @remark 类型 Boolean
#define HOME_CTRL_AC_LIGHT "light"                          ///< 灯光 @remark 类型 Boolean
#define HOME_CTRL_AC_LOCK "lock"                            ///< 童锁 @remark 类型 Boolean
#define HOME_CTRL_AC_SWITCH_VERTICAL "switch_vertical"      ///< 上下摆风开关 @remark 类型 Boolean
#define HOME_CTRL_AC_SWING_3D "swing_3d"                    ///< 3D扫风 @remark 类型 Boolean
#define HOME_CTRL_AC_SLEEP "sleep"                          ///< 睡眠 @remark 类型 Boolean
#define HOME_CTRL_AC_HEALTH "health"                        ///< 健康 @remark 类型 Boolean
#define HOME_CTRL_AC_CLEANING "cleaning"                    ///< 自清洁 @remark 类型 Boolean
#define HOME_CTRL_AC_GEAR_HORIZONTAL "gear_horizontal"      ///< 左右摆风 @remark 类型 Enum @remark 取值说明 {“range”:["off", "opposite", "same", "vane_1", "vane_2", "vane_3", "vane_4", "vane_5", "vane_6", "vane_7", "vane_8", "vane_9", "vane_10"]}
#define HOME_CTRL_AC_POWER_CONSUMPTION "power_consumption"  ///< 能耗统计 @remark 类型 Integer @remark 取值说明 {“min”:0,“unit”:“kW·h”, “scale”:0,“max”:999999,“type”:“value”, “step”:1}
#define HOME_CTRL_AC_TEMP_SET_F         "temp_set_f"        ///< 设置华氏温度 @remark 类型 Integer @remark 取值说明 {"unit":"℉", "min":0,"max":100,"scale":0,"step":1}
#define HOME_CTRL_AC_WINDSPEED          "windspeed"         ///< 风速档位 @remark 类型 Enum @remark 取值说明 {"range":["1", "2", "3", "4", "5", "6"]}
#define HOME_CTRL_AC_MODE_AUTO          "mode_auto"         ///< 自动模式 @remark 类型 Boolean
#define HOME_CTRL_AC_MODE_DRY           "mode_dry"          ///< 干燥模式 @remark 类型 Boolean
#define HOME_CTRL_AC_MODE_VENTILATION   "mode_ventilation"  ///< 换气模式 @remark 类型 Boolean
#define HOME_CTRL_AC_ANION              "anion"             ///< 负离子 @remark 类型 Boolean
#define HOME_CTRL_AC_SWITCH_HORIZONTAL  "switch_horizontal" ///< 左右摆风开关 @remark 类型 Boolean
#define HOME_CTRL_AC_WINDSHAKE          "windshake"         ///< 风摆 @remark 类型 Enum @remark 取值说明 {"range":["horizontal", "vertical"]}
#define HOME_CTRL_AC_BEEP               "beep"              ///< 蜂鸣 @remark 类型 Boolean
#define HOME_CTRL_AC_HUMIDITY_SET       "humidity_set"      ///< 设置湿度 @remark 类型 Integer @remark 取值说明 {"min":0,"unit":"%", "scale":0,"max":100,"type":"value", "step":1}
#define HOME_CTRL_AC_TEMP_UNIT_CONVERT  "temp_unit_convert" ///< 温标切换 @remark 类型 Enum @remark 取值说明 {"range":["c", "f"]}
#define HOME_CTRL_AC_COUNTDOWN          "countdown"         ///< 倒计时 @remark 类型 Enum @remark 取值说明 {"range":["cancel", "1", "2", "3", "4", "5", "6"]}
#define HOME_CTRL_AC_TEMP_CURRENT_F     "temp_current_f"    ///< 当前华氏温度 @remark 类型 Integer @remark 取值说明 {"unit":"℉","min":-40,"max":200,"scale":0,"step":1}
#define HOME_CTRL_AC_WORK_STATUS        "work_status"       ///< 工作状态 @remark 类型 Enum @remark 取值说明 {"range":["heating","cooling","ventilation","off"]}
#define HOME_CTRL_AC_HUMIDITY_CURRENT   "humidity_current"  ///< 当前湿度 @remark 类型 Integer @remark 取值说明 {"min":0,"scale":0,"unit":"%","max":100,"step":1}
#define HOME_CTRL_AC_COUNTDOWN_LEFT     "countdown_left"    ///< 倒计时剩余时间 @remark 类型 Integer @remark 取值说明 {"min":0,"scale":0,"unit":"min","max":360,"step":1}
#define HOME_CTRL_AC_STATUS             "status"            ///< 工作状态 @remark 类型 Enum @remark 取值说明 {"range":["1","2","3","off"]}
/** @} */

#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for gourp product_type_ac

#endif // __TUYA_HOME_CTRL_AC__