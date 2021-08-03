/**
 * @file tuya_home_ctrl_socket.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 中控SDK插座封装
 * @version 0.1
 * @date 2021-03-10
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __TUYA_HOME_CTRL_SOCKET__
#define __TUYA_HOME_CTRL_SOCKET__

/**
 * @defgroup product_type_socket 插座品类
 * @{
 */

/**
 * @name 插座支持的DP
 * @{
 */
#define HOME_CTRL_SOCKET_SWITCH            "home_ctrl_socket_switch"       ///< 开关 @remark 类型 @ref BOOL_T
#define HOME_CTRL_SOCKET_CHILD_LOCK        "child_lock"                    ///< 童锁 @remark 类型 Boolean
#define HOME_CTRL_SOCKET_RELAY_STATUS      "relay_status"                  ///< 上电状态设置 @remark 类型 Enum @remark 取值说明 {"range":["power_on", "power_off", "last"]}
#define HOME_CTRL_SOCKET_LIGHT_MODE        "light_mode"                    ///< 指示灯状态设置 @remark 类型 Enum @remark 取值说明 {"range":["none","relay","pos"]}
#define HOME_CTRL_SOCKET_COUNTDOWN_1       "countdown_1"                   ///< 开关 倒计时 @remark 类型 Integer @remark 取值说明 {"unit":"s","min":0,"max":86400,"scale":0,"step":1}
/** @} */

#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for gourp product_type_socket

#endif // __TUYA_HOME_CTRL_SOCKET__