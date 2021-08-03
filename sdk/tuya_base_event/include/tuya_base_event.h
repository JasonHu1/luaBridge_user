#ifndef __TUYA_BASE_EVENT_H__
#define __TUYA_BASE_EVENT_H__

#include "base_event.h"
#include "tuya_base_event_init.h"

#ifdef __cplusplus
extern "C" {
#endif

/** 
 * @brief: 发布指定事件，会通知所有订阅该事件的订阅者处理
 *
 * @param[in] name: 事件名，事件标识，字符串，16字节长的
 * @param[in] data: 事件数据，数据和事件类型绑定，发布事件和订阅事件必须使用同一事件数据类型定义
 * @param[in] len: 事件数据长度
 *
 * @return int: 0成功，非0，请参照tuya error code描述文档 
 */
int tuya_publish(const char *name, void *data);

/** 
 * @brief: 订阅指定事件，会通过回调函数处理消息发布内容
 *
 * @param[in] name: 事件名，事件标识，字符串，16字节长的
 * @param[in] desc: 描述信息，表面订阅者身份、目的，32字节长度，方便定位问题
 * @param[in] cb: 事件处理回调函数
 * @param[in] is_emergency: 紧急事件，必须第一个处理
 *
 * @note： desc、cb构成了一个二元组，这个二元组标识一个唯一订阅者，同一个desc不同的cb，也会认为是不同的
 *      订阅。在事件发布之前就订阅的，可以收到事件；在事件发布之后订阅的，收不到之前发布的事件。
 *
 * @return int: 0成功，非0，请参照tuya error code描述文档 
 */
int tuya_subscribe(const char *name, const char *desc, const event_subscribe_cb cb, int is_emergency);

/** 
 * @brief: 订阅指定事件，会通过回调函数处理消息发布内容
 *
 * @param[in] name: 事件名，事件标识，字符串，16字节长的
 * @param[in] desc: 描述信息，订阅者身份、目的，32字节长度，方便定位问题
 * @param[in] cb: 事件处理回调函数
 *
 * @note： desc、cb构成了一个二元组，这个二元组标识一个唯一订阅者，同一个desc不同的cb，也会认为是不同的
 *      订阅
 *
 * @return int: 0成功，非0，请参照tuya error code描述文档 
 */
int tuya_unsubscribe(const char *name, const char *desc, event_subscribe_cb cb);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __TUYA_BASE_EVENT_H__

