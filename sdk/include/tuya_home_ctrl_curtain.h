/**
 * @file tuya_home_ctrl_curtain.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 中控窗帘的SDK
 * @version 0.1
 * @date 2021-03-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CTRL_CURTAIN__
#define __TUYA_HOME_CTRL_CURTAIN__

/**
 * @defgroup product_type_curtain 窗帘品类
 * @{
 */

#pragma pack(1)

/**
 * @name 窗帘支持的DP
 * @{
 */
#define HOME_CTRL_CURTAIN_CONTROL            "control"            ///< 控制 @remark 类型 Enum @remark 取值说明 {"range":["open", "stop", "close", "continue"]}
#define HOME_CTRL_CURTAIN_PERCENT_CONTROL    "percent_control"    ///< 开启百分比控制 @remark 类型 Integer @remark 取值说明 {"unit":"%", "min":0, "max":100, "scale":0, "step":1}
#define HOME_CTRL_CURTAIN_MODE               "mode"               ///< 工作模式 @remark 类型 Enum @remark 取值说明 {"range":["morning", "night"]}
#define HOME_CTRL_CURTAIN_CONTROL_BACK_MODE  "control_back_mode"  ///< 电机反转模式 @remark 类型 Enum @remark 取值说明 {"range":["forward", "back"]}
#define HOME_CTRL_CURTAIN_AUTO_POWER         "auto_power"         ///< 自动开启 @remark 类型 Boolean
#define HOME_CTRL_CURTAIN_COUNTDOWN_SET      "countdown_set"      ///< 倒计时（新） @remark 类型 Enum @remark 取值说明 {"range":["cancel", "1h", "2h", "3h", "4h"]}
#define HOME_CTRL_CURTAIN_PERCENT_STATE      "percent_state"      ///< 开启百分比状态 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1}
#define HOME_CTRL_CURTAIN_WORK_STATE         "work_state"         ///< 工作状态 @remark 类型 Enum @remark 取值说明 {"range":["opening","closing"]}
#define HOME_CTRL_CURTAIN_COUNTDOWN_LEFT     "countdown_left"     ///< 倒计时剩余时间 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_CURTAIN_TIME_TOTAL         "time_total"         ///< 全程运行时间 @remark 类型 Integer @remark 取值说明 {"unit":"ms","min":0,"max":120000,"scale":0,"step":1}
#define HOME_CTRL_CURTAIN_SITUATION_SET      "situation_set"      ///< 位置状态 @remark 类型 Enum @remark 取值说明 {"range":["fully_open","fully_close"]}

/** @} */

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for gourp product_type_curtain

#endif // __TUYA_HOME_CTRL_CURTAIN__