/**
 * @file tuya_home_ctrl_event.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 订阅事件
 * @version 0.1
 * @date 2021-03-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CTRL_EVENT__
#define __TUYA_HOME_CTRL_EVENT__

/**
 * @addtogroup product_type_unity linux中控SDK统一接口
 * @{
 */

#include "tuya_cloud_types.h"
#include "tuya_ctrl_center.h"
#include "tuya_error_code.h"

#pragma pack(1)
/// 设备上下线回调函数
typedef INT_T (*DEV_ONLINE_CB)(TUYA_EVENT_DEV_ONLINE_S *);
/// 设备快捷开关回调函数
typedef INT_T (*DEV_SHORTCUT_CB)(TUYA_EVENT_SHORTCUT_S *);
/// DP名称改变回调函数
typedef INT_T (*DP_NAME_UPDATE_CB)(TUYA_EVENT_DP_NAME_S *);

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 订阅设备上下线事件
 * 
 * @param dev_online_cb 上下线事件的回调函数
 * @return OPERATE_RET 错误码
 * @note 可以调用多次，不同的回调函数会识别成不同的订阅。在事件发布之前就订阅的，可以收到事件；在事件发布之后订阅的，收不到之前发布的事件
 */
OPERATE_RET tuya_home_ctrl_subscribe_dev_online(CONST DEV_ONLINE_CB dev_online_cb);

/**
 * @brief 去订阅设备上下线事件
 * 
 * @param dev_online_cb 上下线事件的回调函数
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_home_ctrl_unsubscribe_dev_online(CONST DEV_ONLINE_CB dev_online_cb);

/**
 * @brief 订阅设备快捷开关事件
 * 
 * @param dev_shortcut_cb 快捷开关状态改变回调函数
 * @note 可以调用多次，不同的回调函数会识别成不同的订阅。在事件发布之前就订阅的，可以收到事件；在事件发布之后订阅的，收不到之前发布的事件
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_home_ctrl_subscribe_dev_shortcut(CONST DEV_SHORTCUT_CB dev_shortcut_cb);

/**
 * @brief 去订阅设备快捷开关事件
 * 
 * @param dev_shortcut_cb 快捷开关状态改变回调函数
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_home_ctrl_unsubscribe_dev_shortcut(CONST DEV_SHORTCUT_CB dev_shortcut_cb);

/**
 * @brief 订阅dp名称改变事件
 * 
 * @param dp_name_update_cb dp名称改变回调函数
 * @note 可以调用多次，不同的回调函数会识别成不同的订阅。在事件发布之前就订阅的，可以收到事件；在事件发布之后订阅的，收不到之前发布的事件
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_home_ctrl_subscribe_dp_name_update(CONST DP_NAME_UPDATE_CB dp_name_update_cb);

/**
 * @brief 去订阅dp名称改变事件
 * 
 * @param dp_name_update_cb dp名称改变回调函数
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_home_ctrl_unsubscribe_dp_name_update(CONST DP_NAME_UPDATE_CB dp_name_update_cb);


#ifdef __cplusplus
}  // extern "C"
#endif

/** @} */  // end for gourp product_type_unity

#endif  // __TUYA_HOME_CTRL_EVENT__