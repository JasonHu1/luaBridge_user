#ifndef __GW_ASYNC_TASK_H__
#define __GW_ASYNC_TASK_H__


#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
    extern "C" {
#endif

//异步任务最大的 线程个数
#if OPERATING_SYSTEM == SYSTEM_LINUX
#define GW_ASYNC_TASK_MAX_NUM 4
#else
#define GW_ASYNC_TASK_MAX_NUM 2
#endif

//task_func_param 参数透传 gw_async_task_exe 的参数
typedef VOID (*GW_ASYNC_TASK_FUNC)(IN VOID *task_func_param);

OPERATE_RET gw_async_task_init();

//异步执行接口，该函数调用后马上返回，在网关的线程池中回调task_func函数，task_func允许阻塞
//最大同时处理个数为 GW_ASYNC_TASK_MAX_NUM 剩下的会等待
//如果需要重试，在 task_func 回调中调用 gw_async_task_exe 即可
OPERATE_RET gw_async_task_exe(IN GW_ASYNC_TASK_FUNC task_func, IN VOID *task_func_param);


#ifdef __cplusplus
} // extern "C"
#endif

#endif  // __GW_ASYNC_TASK_H__

