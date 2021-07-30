/**
 * @file tuya_home_ctrl_temp_ctrl.h
 * @author diao(HongWangZheng) (diao.hong@tuya.com)
 * @brief 中控SDK，温控器品类
 * @version 0.1
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CTRL_TEMP_CTRL__
#define __TUYA_HOME_CTRL_TEMP_CTRL__

/**
 * @defgroup product_type_temp_ctrl 温控器品类
 * @{
 */


/**
 * @name 温控器支持的DP
 * @{
 */
#define HOME_CTRL_TEMP_CTRL_SWITCH              "switch"              ///< 开关 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_MODE                "mode"                ///< 工作模式 @remark 类型 Enum @remark 取值说明 {"range":["cold","hot","wind","comfortable","energy","auto","holiday","eco","manual","sleep","dry","program","floor_heat","auxiliary_heat"]}
#define HOME_CTRL_TEMP_CTRL_ECO                 "eco"                 ///< ECO 模式 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_ANION               "anion"               ///< 负离子 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_LIGHT               "light"               ///< 灯光 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_SOUND               "sound"               ///< 声音 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_FACTORY_RESET       "factory_reset"       ///< 恢复出厂设置 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_WINDOW_CHECK        "window_check"        ///< 开窗检测 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_SLEEP               "sleep"               ///< 睡眠功能 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_FROST               "frost"               ///< 防霜冻功能 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_VALVE_CHECK         "valve_check"         ///< 阀门检测 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_SWITCH_VERTICAL     "switch_vertical"     ///< 上下摆风开关 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_SWITCH_HORIZONTAL   "switch_horizontal"   ///< 左右摆风开关 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_FAN_HORIZONTAL      "fan_horizontal"      ///< 左右摆风角度 @remark 类型 Enum @remark 取值说明 {"range":["30","90"]}
#define HOME_CTRL_TEMP_CTRL_FAN_VERTICAL        "fan_vertical"        ///< 上下摆风角度 @remark 类型 Enum @remark 取值说明 {"range":["30","90"]}
#define HOME_CTRL_TEMP_CTRL_TEMP_SET            "temp_set"            ///< 目标摄氏温度 @remark 类型 Integer @remark 取值说明 {"unit":"℃","min":5,"max":40,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_UPPER_TEMP          "upper_temp"          ///< 设置摄氏温度上限 @remark 类型 Integer @remark 取值说明 {"unit":"℃","min":20,"max":40,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_LOWER_TEMP          "lower_temp"          ///< 设置温度下限 @remark 类型 Integer @remark 取值说明 {"unit":"℃","min":0,"max":20,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_TEMP_SET_F          "temp_set_f"          ///< 目标华氏温度 @remark 类型 Integer @remark 取值说明 {"unit":"℉","min":32,"max":104,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_UPPER_TEMP_F        "upper_temp_f"        ///< 设置华氏温度上限 @remark 类型 Integer @remark 取值说明 {"unit":"℉","min":70,"max":104,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_LOWER_TEMP_F        "lower_temp_f"        ///< 设置华氏温度下限 @remark 类型 Integer @remark 取值说明 {"unit":"℉","min":32,"max":70,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_CAPACITY_SET        "capacity_set"        ///< 功率设置 @remark 类型 Enum @remark 取值说明 {"range":["2000W","3000W","5000W"]}
#define HOME_CTRL_TEMP_CTRL_TEMP_CORRECTION     "temp_correction"     ///< 温度校准 @remark 类型 Integer @remark 取值说明 {"min":-9,"max":9,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_LEVEL               "level"               ///< 档位 @remark 类型 Enum @remark 取值说明 {"range":["low","middle","high","auto","closed"]}
#define HOME_CTRL_TEMP_CTRL_WORK_DAYS           "work_days"           ///< 工作日设置 @remark 类型 Enum @remark 取值说明 {"range":["5_2","6_1","7"]}
#define HOME_CTRL_TEMP_CTRL_HOLIDAY_TEMP_SET    "holiday_temp_set"    ///< 假日模式摄氏温度设置 @remark 类型 Integer @remark 取值说明 {"unit":"℃","min":0,"max":40,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_HOLIDAY_TEMP_SET_F  "holiday_temp_set_f"  ///< 假日模式华氏度温度设置 @remark 类型 Integer @remark 取值说明 {"unit":"℉","min":32,"max":104,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_HOLIDAY_DAYS_SET    "holiday_days_set"    ///< 假日模式天数设置 @remark 类型 Integer @remark 取值说明 {"unit":"day","min":0,"max":99,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_HOLIDAY_SET         "holiday_set"         ///< 假日模式时间设置 @remark 类型 String @remark 取值说明 {"maxlen": 255}
#define HOME_CTRL_TEMP_CTRL_CHILD_LOCK          "child_lock"          ///< 童锁 @remark 类型 Boolean
#define HOME_CTRL_TEMP_CTRL_COUNTDOWN           "countdown"           ///< 倒计时 @remark 类型 Enum @remark 取值说明 {"range":["cancel","1h","2h","3h","4h","5h","6h","7h","8h","9h","10h","11h","12h","13h","14h","15h","16h","17h","18h","19h","20h","21h","22h","23h","24h"]}
#define HOME_CTRL_TEMP_CTRL_SENSOR_CHOOSE       "sensor_choose"       ///< 传感器选择 @remark 类型 Enum @remark 取值说明 {"range":["in","out"]}
#define HOME_CTRL_TEMP_CTRL_BACKLIGHT           "backlight"           ///< 背光亮度 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_BACKLIGHT_ENUM      "backlight_enum"      ///< 背光亮度快捷设置 @remark 类型 Enum @remark 取值说明 {"range":["closed","half_bright","full_bright"]}
#define HOME_CTRL_TEMP_CTRL_TEMP_UNIT_CONVERT   "temp_unit_convert"   ///< 温标切换 @remark 类型 Enum @remark 取值说明 {"range":["c","f"]}
#define HOME_CTRL_TEMP_CTRL_LOOP_MODE           "loop_mode"           ///< 循环模式 @remark 类型 Enum @remark 取值说明 {"range":["auto","indoor_loop","outdoor_loop"]}
#define HOME_CTRL_TEMP_CTRL_FAN_SPEED_ENUM      "fan_speed_enum"      ///< 风速设置 @remark 类型 Enum @remark 取值说明 {"range":["low","mid","high","off"]}
#define HOME_CTRL_TEMP_CTRL_WORK_STATE          "work_state"          ///< 工作状态 @remark 类型 Enum @remark 取值说明 {"range":["cold","hot","wind","comfortable","energy","auto","holiday","eco","manual","sleep","dry","program","floor_heat","auxiliary_heat"]}
#define HOME_CTRL_TEMP_CTRL_WORK_POWER          "work_power"          ///< 当前功率 @remark 类型 Integer @remark 取值说明 {"unit":"W","min":0,"max":5000,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_TEMP_CURRENT        "temp_current"        ///< 当前摄氏温度 @remark 类型 Integer @remark 取值说明 {"unit":"℃","min":0,"max":50,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_WINDOW_STATE        "window_state"        ///< 窗户状态 @remark 类型 Enum @remark 取值说明 {"range":["close","open"]}
#define HOME_CTRL_TEMP_CTRL_TEMP_CURRENT_F      "temp_current_f"      ///< 当前华氏温度 @remark 类型 Integer @remark 取值说明 {"unit":"℉","min":-4,"max":122,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_VALVE_STATE         "valve_state"         ///< 阀门状态 @remark 类型 Enum @remark 取值说明 {"range":["open","close"]}
#define HOME_CTRL_TEMP_CTRL_COUNTDOWN_LEFT      "countdown_left"      ///< 倒计时剩余分钟 @remark 类型 Integer @remark 取值说明 {"unit":"min","min":0,"max":1440,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_BATTERY_PERCENTAGE  "battery_percentage"  ///< 电池电量 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1}
#define HOME_CTRL_TEMP_CTRL_HUMIDITY            "humidity"            ///< 湿度 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1}

/** @} */

#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for gourp product_type_temp_ctrl

#endif // __TUYA_HOME_CTRL_TEMP_CTRL__