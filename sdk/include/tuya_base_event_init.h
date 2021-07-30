#ifndef __TUYA_BASE_EVENT_INIT_H__
#define __TUYA_BASE_EVENT_INIT_H__

#include "tuya_cloud_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

///< 异步消息模块初始化，接口对外暴露
OPERATE_RET tuya_base_event_init();

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __TUYA_BASE_EVENT_INIT_H__