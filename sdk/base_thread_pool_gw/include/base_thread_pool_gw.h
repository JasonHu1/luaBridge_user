#ifndef _BASE_THREAD_POOL_GW_H
#define _BASE_THREAD_POOL_GW_H

#include "tuya_cloud_types.h"
#include "uni_msg_queue.h"
#include "uni_time_queue.h"
#include "uni_thread.h"

#ifdef __cplusplus
    extern "C" {
#endif

typedef void* GW_THREAD_POOL_HANDLE;

#define GW_THREAD_POOL_HANDLE_INVALID NULL

typedef void* GW_THREAD_ID;


typedef BYTE_T THREAD_POOL_TYPE;
#define THREAD_POOL_TYPE_FAST 	1		//快速线程. 无阻塞 无sleep 简单的快速处理
#define THREAD_POOL_TYPE_NORMAL 2		//普通线程. 偶尔短时间的阻塞或有sleep 比如几十ms-几百ms 级别
#define THREAD_POOL_TYPE_TEMP 	3		//临时使用.前后获取的线程不保证是同一个
#define THREAD_POOL_TYPE_SELF 	4		//模块独占。


#define MODULE_NUM_LEN 15

typedef struct {
	BYTE_T fast_type_num;		//快速线程个数，默认1个       
	BYTE_T normal_type_num;		//普通线程个数，默认rtos 下2个，          linux下2个 
	
	BYTE_T temp_type_num;		//临时线程初始化个数 默认rtos 下1个，          linux下2个 
	BYTE_T temp_type_num_max; 	//临时线程最大个数， 默认rtos 下4个，          linux下8个
	//DEBUG info TODO	
} GW_THREAD_POOL_INIT_PARAM;


//TODO	 
//DEBUG info policy
typedef struct {
	CHAR_T *mod_name;
	
} GW_THREAD_POOL_GET_MORE_PARAM;


//需要在init之前调用，否则使用默认的配置
OPERATE_RET gw_thread_pool_set_param(IN CONST GW_THREAD_POOL_INIT_PARAM *init_param);

OPERATE_RET gw_thread_pool_init();

//获取公共线程接口 
//支持类型 THREAD_POOL_TYPE_FAST       THREAD_POOL_TYPE_NORMAL
OPERATE_RET gw_thread_pool_get(THREAD_POOL_TYPE type, GW_THREAD_POOL_GET_MORE_PARAM *get_param, OUT GW_THREAD_POOL_HANDLE *hdl);


//获取模块独占线程接口 
//支持类型 THREAD_POOL_TYPE_SELF
OPERATE_RET gw_thread_pool_get_self(IN CONST THRD_PARAM_S *thrd_param, OUT GW_THREAD_POOL_HANDLE *hdl);


OPERATE_RET gw_get_cur_thread_ID(GW_THREAD_ID *thr_id);

OPERATE_RET gw_get_handle_thread_ID(IN GW_THREAD_POOL_HANDLE hdl, GW_THREAD_ID *thr_id);

VOID gw_thread_pool_dump(IN       GW_THREAD_POOL_HANDLE hdl);
VOID gw_thread_pool_dump_all();


///////////下面是线程的操作逻辑////////////////
OPERATE_RET gw_thread_pool_reg_msgcb(IN GW_THREAD_POOL_HANDLE hdl, IN CONST MSG_CALLBACK msg_cb, OUT MSG_ID *msg_id);

OPERATE_RET gw_thread_pool_unreg_msgcb(IN GW_THREAD_POOL_HANDLE hdl, IN CONST MSG_ID msgID);

OPERATE_RET gw_thread_pool_post_msg(IN GW_THREAD_POOL_HANDLE hdl, IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                           IN CONST MSG_DATA_LEN msgDataLen);

OPERATE_RET gw_thread_pool_post_msg_malloc(IN GW_THREAD_POOL_HANDLE hdl, IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                  IN CONST MSG_DATA_LEN msgDataLen);

OPERATE_RET gw_thread_pool_post_instancy_msg(IN GW_THREAD_POOL_HANDLE hdl, IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                    IN CONST MSG_DATA_LEN msgDataLen);

OPERATE_RET gw_thread_pool_post_instancy_msg_malloc(IN GW_THREAD_POOL_HANDLE hdl, IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                           IN CONST MSG_DATA_LEN msgDataLen);


OPERATE_RET gw_thread_pool_cr_tm_msg_hand(IN GW_THREAD_POOL_HANDLE hdl, IN CONST TM_MSG_CB cb,IN CONST VOID *data,OUT TM_MSG_S **tm_msg);


OPERATE_RET gw_thread_pool_start_tm_msg(IN GW_THREAD_POOL_HANDLE hdl,  IN CONST TM_MSG_S *tm_msg,IN CONST TIME_MS timeCycle,\
                               IN CONST TIMER_TYPE timer_type);

OPERATE_RET gw_thread_pool_stop_tm_msg(IN GW_THREAD_POOL_HANDLE hdl, IN CONST TM_MSG_S *tm_msg);

OPERATE_RET gw_thread_pool_release_tm_msg(IN GW_THREAD_POOL_HANDLE hdl, IN CONST TM_MSG_S *tm_msg);


OPERATE_RET gw_thread_pool_get_msg_node_num(IN GW_THREAD_POOL_HANDLE hdl, OUT INT_T *p_msg_num);


#ifdef __cplusplus
}
#endif
#endif

