/**
 * @file tuya_home_ctrl_sockets.h
 * @author diao(HongWangZheng) (diao.hong@tuya.com)
 * @brief 中控SDK，排插品类
 * @version 0.1
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CTRL_SOCKETS__
#define __TUYA_HOME_CTRL_SOCKETS__

/**
 * @defgroup product_type_sockets 排插品类
 * @{
 */


/**
 * @name 排插支持的DP
 * @{
 */

#define HOME_CTRL_SOCKETS_SWITCH            "switch"            ///< 开关 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_SWITCH_1          "switch_1"          ///< 开关 1 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_SWITCH_2          "switch_2"          ///< 开关 2 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_SWITCH_3          "switch_3"          ///< 开关 3 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_SWITCH_4          "switch_4"          ///< 开关 4 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_SWITCH_5          "switch_5"          ///< 开关 5 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_SWITCH_6          "switch_6"          ///< 开关 6 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_COUNTDOWN_1       "countdown_1"       ///< 开关 1 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_COUNTDOWN_2       "countdown_2"       ///< 开关 2 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_COUNTDOWN_3       "countdown_3"       ///< 开关 3 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_COUNTDOWN_4       "countdown_4"       ///< 开关 4 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_COUNTDOWN_5       "countdown_5"       ///< 开关 5 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_COUNTDOWN_6       "countdown_6"       ///< 开关 6 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_SWITCH_USB1       "switch_usb1"       ///< USB1 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_SWITCH_USB2       "switch_usb2"       ///< USB2 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_SWITCH_USB3       "switch_usb3"       ///< USB3 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_SWITCH_USB4       "switch_usb4"       ///< USB4 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_SWITCH_USB5       "switch_usb5"       ///< USB5 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_SWITCH_USB6       "switch_usb6"       ///< USB6 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_COUNTDOWN_USB1    "countdown_usb1"    ///< USB1 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_COUNTDOWN_USB2    "countdown_usb2"    ///< USB2 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_COUNTDOWN_USB3    "countdown_usb3"    ///< USB3 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_COUNTDOWN_USB4    "countdown_usb4"    ///< USB4 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_COUNTDOWN_USB5    "countdown_usb5"    ///< USB5 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_COUNTDOWN_USB6    "countdown_usb6"    ///< USB6 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_CHILD_LOCK        "child_lock"        ///< 童锁 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_RELAY_STATUS      "relay_status"      ///< 上电状态设置 @remark 类型 Enum @remark 取值说明 {"range":["power_on", "power_off", "last"]}
#define HOME_CTRL_SOCKETS_LIGHT_MODE        "light_mode"        ///< 指示灯状态设置 @remark 类型 Enum @remark 取值说明 {"range":["none","relay","pos"]}
#define HOME_CTRL_SOCKETS_SWITCH_BACKLIGHT  "switch_backlight"  ///< 背光开关 @remark 类型 Boolean
#define HOME_CTRL_SOCKETS_CUR_CURRENT       "cur_current"       ///< 当前电流 @remark 类型 Integer @remark 取值说明 {"unit":"mA","min":0,"max":30000,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_CUR_POWER         "cur_power"         ///< 当前功率 @remark 类型 Integer @remark 取值说明 {"unit":"W","min":0,"max":50000,"scale":0,"step":1}
#define HOME_CTRL_SOCKETS_CUR_VOLTAGE       "cur_voltage"       ///< 当前电压 @remark 类型 Integer @remark 取值说明 {"unit":"W","min":0,"max":50000,"scale":1,"step":1}
/** @} */

#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for group product_type_sockets

#endif // __TUYA_HOME_CTRL_SOCKETS__


