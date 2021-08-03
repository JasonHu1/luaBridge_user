/***********************************************************
*  File: gw_encrypt.h
*  Author: dingsl
*  Date: 20180707
***********************************************************/
#ifndef ___REX_GATEWAY_ENCRYPT_H
#define ___REX_GATEWAY_ENCRYPT_H

#ifdef __cplusplus
    extern "C" {
#endif

#include <time.h>
#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "uni_module.h"
#include "tuya_hal_mutex.h"
#include "uni_slist.h"
#include "tuya_encrypt.h"
#include "tuya_rex_gw_encrypt.h"

#ifndef PACKED
#define PACKED __attribute__((packed))
#endif

#define REX_ENCRYPT_HEAD_LEN        3
#define ENCRYPT_DATA_HEAD_LEN       10
#define ENCRYPT_MAX_LEN             MSG_BUF_MAX_LEN
#define ENCRYPT_ADDRESS_LEN         16

#define ENCRYPT_CONTENT_LEN_MAX     128
#define REX_ENCRYPT_KEY_FIX_STR     "11aa22bb"
#define ENCRYPT_PROTOCOL_ID         0x10

#define GW_ENCRYPT_CHECK_TIME           3           //3s
#define GW_ENCRYPT_SYNC_TIME            (60 * 60)   //1h
#define GW_ENCRYPT_SYNC_RETRY_TIME      60          //60s
#define GW_ENCRYPT_DEV_JOIN_SYNC_TIME   10          //10s
#define GW_ENCRYPT_RETRY_TIME           8           //8s  
#define GW_ENCRYPT_ACK_RETRY_TIME       3           //3s  
#define GW_ENCRYPT_UNLOCK_RETRY_MAX     2  
#define GW_ENCRYPT_CMD_RETRY_MAX        3 
#define GW_ENCRYPT_CMD_NOT_RETRY        0  
#define GW_ENCRYPT_ACK_RETRY_MAX        3  
#define GW_ENCRYPT_CMD_NUM_MAX          200

#define GW_ENCRYPT_DP_TYPE_RAW          0x0

#define REX_DP_ID_SL_UNLOCK             121
#define REX_DP_ID_SL_UNLOCK_RESULT      122
#define REX_DP_ID_SL_PWD_CREAT          124
#define REX_DP_ID_SL_PWD_DEL            125
#define REX_DP_ID_SL_PWD_UPDATE         126
#define REX_DP_ID_SL_PWD_DISABLE        127
#define REX_DP_ID_SL_PWD_ENABLE         128
#define REX_DP_ID_SL_PWD_CLEAR          139

typedef enum {
    REQUEST_TYPE_MIN = -1,
    REQUEST_SEND_A = 1,
    REQUEST_SEND_B = 2,
    REQUEST_SEND_CMD = 3, 
    REQUEST_SEND_CMD_RESULT = 4, 
    REQUEST_SEND_BASE_KEY = 5,
    REQUEST_TYPE_MAX,
    
} REQUEST_TYPE_E;              

typedef struct {
    CHAR_T      addr[ENCRYPT_ADDRESS_LEN + 1];
    CHAR_T      cmd[ENCRYPT_CMD_LEN_MAX + 1];        
    UINT16_T    cmd_len;
    BYTE_T      type;                                   //REX_ENCRYPT_DATA_S type    
    BYTE_T      dp_type;                                //raw(0) bool(1) value(2) string(3) enum(4) bitmap(5)
    ENCRYPT_FLAG_E encrypt_flag;
    CHAR_T      retry_max;
    CMD_RESULT_PRO_E result_process;                    //cmd result process type
    CHAR_T      real_time;                              //real time cmd need to respond as quickly as possible
    
}PACKED REX_CMD_ATTR_S;

typedef struct {
    CHAR_T      base_key[ENCRYPT_KEY_LEN + 1];    
    BYTE_T      key[ENCRYPT_KEY_LEN + 1];
    BYTE_T      random_a[ENCRYPT_RANDOM_LEN + 1];      
    BYTE_T      random_b[ENCRYPT_RANDOM_LEN + 1];     
    ENCRYPT_STATE_E state;
    UINT16_T    seq;
    CHAR_T      result[ENCRYPT_RESULT_LEN_MAX + 1];        
    UINT16_T    result_len;
    BYTE_T      result_type; 
    BYTE_T      result_dp_type; 
    REX_CMD_ATTR_S  attr;                              
    
}PACKED REX_ENCRYPT_INFO_S;

typedef struct {
    BYTE_T      type;                                   //cmd type:dpid
    BYTE_T      dp_type;                                //raw(0) bool(1) value(2) string(3) enum(4) bitmap(5)
    BYTE_T      length;                                 //cmd data length
    BYTE_T      protocol_id;
    UINT16_T    seq;                                    //cmd seq
    time_t      tm;
    BYTE_T      content[ENCRYPT_CONTENT_LEN_MAX];       //cmd data
    
}PACKED REX_ENCRYPT_DATA_S;

typedef struct {
    BYTE_T      flag;                                   //ENCRYPT_FLAG_E, 0x10: not encrypt, 0x11: encrypt
    BYTE_T      type;                                   //REQUEST_TYPE_E    
    BYTE_T      length;                                 //data length
    BYTE_T      data[ENCRYPT_DATA_MAX_LEN];
    
}PACKED REX_ENCRYPT_S;

typedef struct
{
    REX_ENCRYPT_INFO_S  info;    
    UCHAR_T         send_count;                         //cmd send count
    UCHAR_T         ack_count;                          //http ack count
    time_t          send_start;                         //cmd send start time
    time_t          ack_start;                          //http ack start time
    SLIST_HEAD      node;   
    
}PACKED REX_ENCRYPT_CMD_S;

typedef struct
{
    CHAR_T      addr[ENCRYPT_ADDRESS_LEN + 1];
    BYTE_T      key[ENCRYPT_KEY_LEN + 1];
    BYTE_T      base_key[ENCRYPT_KEY_LEN + 1];
    ENCRYPT_STATE_E state;
    SLIST_HEAD  node;   
    
}PACKED REX_ENCRYPT_DEV_S;

#define REX_INIT_CMD_ATTR(attr, _addr, _type, _dp_type ,_len, _encrypt_flag, _retry_max, _result_process, _real_time) \
                    do {                                                                            \
                        memset(&(attr), 0x0, sizeof(REX_CMD_ATTR_S));                                     \
                        memcpy((attr).addr, _addr, ENCRYPT_ADDRESS_LEN);                              \
                        (attr).type = _type;                                                          \
                        (attr).dp_type = _dp_type;                                                    \
                        (attr).cmd_len = _len;                                                        \
                        (attr).encrypt_flag = _encrypt_flag;                                          \
                        (attr).retry_max = _retry_max;                                                \
                        (attr).result_process = _result_process;                                      \
                        (attr).real_time = _real_time;                                                \
                    }while(0) 

VOID print_buf(BYTE_T *in, UINT_T len, CHAR_T *name);
OPERATE_RET rex_encrypt_get_request(REX_ENCRYPT_INFO_S *info, REX_ENCRYPT_S *p_encrypt, REQUEST_TYPE_E type);
OPERATE_RET rex_encrypt_gen_base_key(CONST char *address, REX_ENCRYPT_INFO_S *p_info, TY_Z3_GLOBAL_T *p_global);
OPERATE_RET rex_encrypt_gen_key(REX_GW_ENCRYPT_S *p_gw_encrypt, BYTE_T *p_base_key, 
                                    REX_ENCRYPT_S *p_encrypt, REX_ENCRYPT_CMD_S *p_cmd);
OPERATE_RET rex_encrypt_get_cmd_result(REX_GW_ENCRYPT_S *p_gw_encrypt, BYTE_T *p_key, 
                                            REX_ENCRYPT_S *p_encrypt, REX_ENCRYPT_CMD_S *p_cmd);
OPERATE_RET rex_encrypt_process_rept(CONST CHAR_T *address, REX_ENCRYPT_S *p_rcv_encrypt, USHORT_T length,
                                        REX_GW_ENCRYPT_S *p_gw_encrypt, REX_ENCRYPT_INFO_S *p_out_info);
OPERATE_RET rex_encrypt_process_cmd(IN CONST REX_CMD_ATTR_S *p_attr, IN REX_GW_ENCRYPT_S *p_gw_encrypt);
OPERATE_RET rex_encrypt_sync_config();
TIME_T rex_encrypt_next_sync_time(REX_GW_ENCRYPT_S *p_gw_encrypt, UINT_T interval);
VOID rex_encrypt_check_cmd(UINT_T timerID, PVOID_T pTimerArg);
OPERATE_RET rex_gw_encrypt_init(REX_GW_ENCRYPT_S *p_gw_encrypt);
OPERATE_RET rex_gw_encrypt_del_dev(REX_GW_ENCRYPT_S *p_gw_encrypt, CHAR_T *dev_id);
OPERATE_RET rex_encrypt_start(IN REX_GW_ENCRYPT_S *p_gw_encrypt, CHAR_T *address, TY_Z3_GLOBAL_T *p_global);
BOOL_T tuya_isRexEncryptLock(UINT_T uddd);
OPERATE_RET rex_gw_encrypt_sync_config(TIME_S timeCycle);
OPERATE_RET rex_lock_encrypt_init(REX_GW_ENCRYPT_S *p_gw_encrypt);

#ifdef __cplusplus
}
#endif

#endif
