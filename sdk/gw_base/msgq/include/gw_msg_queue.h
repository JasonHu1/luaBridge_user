#ifndef __GW_MSG_QUEUE_H
#define __GW_MSG_QUEUE_H

#include "tuya_cloud_types.h"
#include "uni_msg_queue.h"
#include "uni_time_queue.h"

#ifdef __cplusplus
    extern "C" {
#endif

#ifdef  __GW_MSG_QUEUE_GLOBALS
    #define __GW_MSG_QUEUE
#else
    #define __GW_MSG_QUEUE extern
#endif

/***********************************************************
*************************micro define***********************
***********************************************************/

/***********************************************************
*************************variable define********************
***********************************************************/

/***********************************************************
*************************function define********************
***********************************************************/
__GW_MSG_QUEUE \
OPERATE_RET normal_queue_release(VOID);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_init(VOID);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_get_free_msgid(OUT MSG_ID *msg_id);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_reg_msgcb(IN CONST MSG_CALLBACK msg_cb, OUT MSG_ID *msgID);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_unreg_msgcb(IN CONST MSG_ID msgID);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_post_msg(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                           IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_post_msg_malloc(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                  IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_post_instancy_msg(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                    IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_post_instancy_msg_malloc(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                           IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_cr_tm_msg_hand(IN CONST TM_MSG_CB cb,IN CONST VOID *data,OUT TM_MSG_S **tm_msg);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_start_tm_msg(IN CONST TM_MSG_S *tm_msg,IN CONST TIME_MS timeCycle,\
                               IN CONST TIMER_TYPE timer_type);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_stop_tm_msg(IN CONST TM_MSG_S *tm_msg);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_release_tm_msg(IN CONST TM_MSG_S *tm_msg);

__GW_MSG_QUEUE \
OPERATE_RET normal_queue_get_msg_node_num(OUT INT_T *p_msg_num);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_release(VOID);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_init(VOID);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_get_free_msgid(OUT MSG_ID *msg_id);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_reg_msgcb(IN CONST MSG_CALLBACK msg_cb, OUT MSG_ID *msgID);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_unreg_msgcb(IN CONST MSG_ID msgID);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_post_msg(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                           IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_post_msg_malloc(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                  IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_post_instancy_msg(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                    IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_post_instancy_msg_malloc(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                           IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_cr_tm_msg_hand(IN CONST TM_MSG_CB cb,IN CONST VOID *data,OUT TM_MSG_S **tm_msg);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_start_tm_msg(IN CONST TM_MSG_S *tm_msg,IN CONST TIME_MS timeCycle,\
                               IN CONST TIMER_TYPE timer_type);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_stop_tm_msg(IN CONST TM_MSG_S *tm_msg);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_release_tm_msg(IN CONST TM_MSG_S *tm_msg);

__GW_MSG_QUEUE \
OPERATE_RET slow_queue_get_msg_node_num(OUT INT_T *p_msg_num);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_release(VOID);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_init(VOID);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_get_free_msgid(OUT MSG_ID *msg_id);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_reg_msgcb(IN CONST MSG_CALLBACK msg_cb, OUT MSG_ID *msgID);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_unreg_msgcb(IN CONST MSG_ID msgID);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_post_msg(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                           IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_post_msg_malloc(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                  IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_post_instancy_msg(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                    IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_post_instancy_msg_malloc(IN CONST MSG_ID msgID,IN CONST P_MSG_DATA pMsgData,\
                                           IN CONST MSG_DATA_LEN msgDataLen);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_cr_tm_msg_hand(IN CONST TM_MSG_CB cb,IN CONST VOID *data,OUT TM_MSG_S **tm_msg);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_start_tm_msg(IN CONST TM_MSG_S *tm_msg,IN CONST TIME_MS timeCycle,\
                               IN CONST TIMER_TYPE timer_type);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_stop_tm_msg(IN CONST TM_MSG_S *tm_msg);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_release_tm_msg(IN CONST TM_MSG_S *tm_msg);

__GW_MSG_QUEUE \
OPERATE_RET delay_queue_get_msg_node_num(OUT INT_T *p_msg_num);

#ifdef __cplusplus
}
#endif
#endif

