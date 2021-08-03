#ifndef _BASE_THREAD_POOL_GW_TEMP_H
#define _BASE_THREAD_POOL_GW_TEMP_H

#include "tuya_cloud_types.h"
#include "uni_msg_queue.h"
#include "uni_time_queue.h"
#include "uni_thread.h"

#ifdef __cplusplus
    extern "C" {
#endif


typedef void* GW_THREAD_POOL_TEMP_HANDLE;


typedef VOID(*TEMP_THREAD_CALLBACK)(IN GW_THREAD_POOL_TEMP_HANDLE hdl, VOID *param);

typedef struct {	
	BYTE_T temp_type_num;		//临时线程初始化个数
	BYTE_T temp_type_num_max; 	//临时线程最大个数，超过之后就返回失败	
} GW_THREAD_POOL_TEMP_INIT_PARAM;


OPERATE_RET gw_thread_pool_temp_init(IN GW_THREAD_POOL_TEMP_INIT_PARAM * temp_param);


//获取临时线程handle
OPERATE_RET gw_thread_pool_temp_get(OUT GW_THREAD_POOL_TEMP_HANDLE *hdl);


//调用临时线程执行函数，异步，在线程池中的临时线程中回调
//相同的hdl，不保证在相同的线程中执行，但是能保证在同一个时间，最多只有一个线程在执行，因此不会有并发的问题
//!!! 如果当前临时线程使用超过设置的阈值后，会返回失败。需要使用者重试
OPERATE_RET gw_thread_pool_temp_run(IN GW_THREAD_POOL_TEMP_HANDLE hdl, TEMP_THREAD_CALLBACK cb, VOID *param);

//和 gw_thread_pool_temp_run 的差异在于当线程池使用到达设置的阈值之后，不会返回失败，在内部队列中等待
//保证串行和可以执行到，但是无法保证执行的延时时间
OPERATE_RET gw_thread_pool_temp_add(IN GW_THREAD_POOL_TEMP_HANDLE hdl, TEMP_THREAD_CALLBACK cb, VOID *param);


#ifdef __cplusplus
}
#endif
#endif

