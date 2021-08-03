/**
* @file tuya_gw_base_event.h
* @author zhangyu@tuya.com
* @brief Gateway event processing middle layer
*
* @copyright Copyright (c) tuya.inc 2020
*
*/

#ifndef __TUYA_GW_BASE_EVENT_H__
#define __TUYA_GW_BASE_EVENT_H__

#include "tuya_cloud_types.h"
#include "tuya_gw_event_list.h"

#ifdef __cplusplus
	extern "C" {
#endif //__cplusplus

/**
 * @brief 事件处理回调函数
 *
 */
typedef INT_T (*gw_event_subscribe_cb)(VOID *data);

/** 
 * @brief: 发布指定事件，会通知所有订阅该事件的订阅者处理
 *
 * @param[in] name: 事件名，事件标识，字符串，14字节长的
 * @param[in] data: 事件数据，数据和事件类型绑定，发布事件和订阅事件必须使用同一事件数据类型定义
 * @param[in] len: 事件数据长度
 *
 * @return INT_T: 0成功，非0，请参照tuya error code描述文档 
 */
OPERATE_RET gw_event_publish(CONST CHAR_T* name, CONST VOID *data);

/** 
 * @brief: 订阅指定事件，会通过回调函数处理消息发布内容
 *
 * @param[in] name: 事件名，事件标识，字符串，14字节长的
 * @param[in] desc: 描述信息，表面订阅者身份、目的，30字节长度，方便定位问题
 * @param[in] cb: 事件处理回调函数
 * @param[in] is_emergency: 紧急事件，必须第一个处理
 *
 * @note： desc、cb构成了一个二元组，这个二元组标识一个唯一订阅者，同一个desc不同的cb，也会认为是不同的
 *      订阅。在事件发布之前就订阅的，可以收到事件；在事件发布之后订阅的，收不到之前发布的事件。
 *
 * @return INT_T: 0成功，非0，请参照tuya error code描述文档 
 */
OPERATE_RET gw_event_subscribe(CONST CHAR_T *name, CONST CHAR_T *desc, CONST gw_event_subscribe_cb cb, INT_T is_emergency);

/** 
 * @brief: 订阅指定事件，会通过回调函数处理消息发布内容
 *
 * @param[in] name: 事件名，事件标识，字符串，14字节长的
 * @param[in] desc: 描述信息，订阅者身份、目的，30字节长度，方便定位问题
 * @param[in] cb: 事件处理回调函数
 *
 * @note： desc、cb构成了一个二元组，这个二元组标识一个唯一订阅者，同一个desc不同的cb，也会认为是不同的
 *      订阅
 *
 * @return INT_T: 0成功，非0，请参照tuya error code描述文档 
 */
OPERATE_RET gw_event_unsubscribe(CONST CHAR_T *name, CONST CHAR_T *desc, CONST gw_event_subscribe_cb cb);

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //!__TUYA_GW_BASE_EVENT_H__