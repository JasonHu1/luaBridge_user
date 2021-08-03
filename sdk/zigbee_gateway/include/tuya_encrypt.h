/***********************************************************
*  File: gw_encrypt.h
*  Author: dingsl
*  Date: 20180707
***********************************************************/
#ifndef __GATEWAY_ENCRYPT_H
#define __GATEWAY_ENCRYPT_H

#include <time.h>
#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "uni_module.h"
#include "tuya_hal_mutex.h"
#include "uni_slist.h"

#include "tuya_z3.h"

#include "tuya_z3_msg_api.h"
#include "tuya_cloud_com_defs.h"
#include "tuya_z3_base.h"
#include "tuya_gw_encrypt.h"

#ifndef PACKED
#define PACKED __attribute__((packed))
#endif

#define ENCRYPT_RANDOM_LEN          4
#define ENCRYPT_CMD_LEN_MAX         128
#define ENCRYPT_RESULT_LEN_MAX      64
#define RELIABLE_HEAD_LEN           2
#define RELIABLE_DATA_START         RELIABLE_HEAD_LEN
#define RELIABLE_DATA_LEN_MAX       (ENCRYPT_CMD_LEN_MAX - RELIABLE_HEAD_LEN)
#define ENCRYPT_HEAD_LEN            2
#define ENCRYPT_MAX_LEN             MSG_BUF_MAX_LEN
#define ENCRYPT_DATA_MAX_LEN        (ENCRYPT_MAX_LEN - ENCRYPT_HEAD_LEN)
#define ENCRYPT_KEY_FIX_LEN         8
#define ENCRYPT_KEY_FIX_STR         "tuya22ff"
#define ENCRYPT_KEY_LEN             16
#define ENCRYPT_ADDR_LEN            16
#define ENCRYPT_SEQ_MIN             1
#define ENCRYPT_SEQ_MAX             65000

#define ENCRYPT_SEND_RANDOM         0x55  
#define ENCRYPT_SEND_BASE_KEY       0x56  
#define KEY_PAN_ID_LEN              4
#define KEY_NETWORK_KEY_LEN         8
#define KEY_ADDR_LEN                4

#define ENCRYPT_SYNC_INTERVAL       (60 * 60)   //1h
#define SYNC_RETRY_INTERVAL         60          //60s
#define DEV_JOIN_SYNC_INTERVAL      30          //30s
#define CMD_CHECK_INTERVAL          3           //3s
#define CMD_RETRY_INTERVAL          8           //8s  
#define CMD_ACK_RETRY_INTERVAL      3           //3s  
#define CMD_NUM_MAX                 200
#define CMD_SEND_COUNT_MIN          0
#define CMD_DP_TYPE_RAW             0x0
#define DEF_SEQ                     0

#define CMD_LESS_RETRY              2           //2 times  
#define CMD_DEF_RETRY               3 
#define CMD_MORE_RETRY              5 
#define CMD_NOT_RETRY               0  
#define CMD_ACK_RETRY               (CMD_DEF_RETRY)  

#define COM_HEAD_LEN                4
#define RELIABLE_COM_LEN_MAX        (RELIABLE_DATA_LEN_MAX)
#define RELIABLE_COM_DATA_LEN_MAX   (RELIABLE_COM_LEN_MAX - COM_HEAD_LEN)
#define OPRT_DP_CONTINUE_PROCESS    (-2001)


#define ENCRYPT_AUTHKEY_VERSION     0
#define ENCRYPT_AUTHKEY_VERSION_LEN     1
#define ENCRYPT_AUTHKEY_KEYDATALEN_LEN  1

#define ENCRYPT_AUTHKEY_HMACRA_NAME "hmacRandomA"
#define ENCRYPT_AUTHKEY_HMACRA_LEN  32
#define ENCRYPT_AUTHKEY_HMACRB_NAME "hmacRandomB"
#define ENCRYPT_AUTHKEY_HMACRB_LEN  32
#define ENCRYPT_AUTHKEY_AESRB_NAME  "aesRandomB"
#define ENCRYPT_AUTHKEY_AESRB_LEN   32 //已经加密的
#define ENCRYPT_AUTHKEY_SESSIONKEY_NAME "sessionKey"
#define ENCRYPT_AUTHKEY_SESSIONKEY_LEN  16



typedef enum {
    ENCRYPT_STATE_MIN = -1,
    STATE_SEND_BASE_KEY,            //send base key
    STATE_SEND_RANDOM,              //send random
    STATE_GEN_KEY,                  //already generate final key    
    STATE_SEND_CMD,
    STATE_GET_RESULT,
    ENCRYPT_STATE_MAX,
    
} ENCRYPT_STATE_E;                  //encrypt communication state

typedef enum {
    REQ_TYPE_MIN = -1,
    REQ_SEND_A = 1,
    REQ_SEND_B = 2,
    REQ_SEND_CMD = 3, 
    REQ_SEND_CMD_RESULT = 4, 
    REQ_SEND_BASE_KEY = 5,
    REQ_TYPE_MAX,
    
} REQ_TYPE_E;              

typedef enum {
    EN_FLAG_MIN = -1,    
    FLAG_NOT_ENCRYPT = 0x10,
    FLAG_ENCRYPT = 0x11,
    EN_FLAG_MAX,
    
} ENCRYPT_FLAG_E;          

typedef enum {
    RE_FLAG_MIN = -1,    
    FLAG_RELIABLE = 1,
    FLAG_NOT_RELIABLE = 0,
    RE_FLAG_MAX,
    
} RELIABLE_FLAG_E;                   //reliable data flag, have seq      

typedef enum {
    RT_FLAG_MIN = -1,    
    FLAG_RT = 1,
    FLAG_NOT_RT = 0,
    RT_FLAG_MAX,
    
} REAL_TIME_FLAG_E;          

typedef enum {
    EL_FLAG_MIN = -1,    
    FLAG_LOCK = 1,
    FLAG_NOT_LOCK = 0,
    EL_FLAG_MAX,
    
} LOCK_FLAG_E;  

typedef enum {
    GW_REQ_TYPE_MIN = -1,    
    TYPE_REQ = 0,                   //gw request, default
    TYPE_RESP = 1,                  //gw response for sub dev
    GW_REQ_TYPE_MAX,
    
} GW_REQ_TYPE_E;          

typedef enum {
    ENCRYPT_OP_MIN = -1,
    ENCRYPT_OP_GET,
    ENCRYPT_OP_SET,
    ENCRYPT_OP_DEL,
    ENCRYPT_OP_RECORD_CHECK,
    ENCRYPT_OP_RECORD_UPDATE,
    ENCRYPT_OP_MAX,
    
} ENCRYPT_CMD_OP_E;                                     //smart lock cmd operate

typedef enum {
    ENCRYPT_CMD_STAT_MIN = -1,
    CMD_NEED_CMD_RETRY,
    CMD_NEED_ACK_RETRY,
    CMD_NEED_DEL,
    CMD_STAT_NORMAL,
    ENCRYPT_CMD_STAT_MAX,
    
} ENCRYPT_CMD_STAT_E;                                   //smart lock cmd status

typedef enum {
    CMD_RESULT_PRO_MIN = -1,
    RESULT_DP_REPORT,
    RESULT_HTTP_ACK,
    RESULT_KEY_PRO,                                     //result need key process
    RESULT_DO_NOTHING,
    CMD_RESULT_PRO_MAX,
    
} CMD_RESULT_PRO_E;                                     //cmd result process type when parse success

typedef struct {
    CHAR_T      addr[ENCRYPT_ADDR_LEN + 1];
    CHAR_T      cmd[ENCRYPT_CMD_LEN_MAX];        
    UINT16_T    cmd_len;
    BYTE_T      type;                                   //ENCRYPT_DATA_S type    
    RELIABLE_FLAG_E     reliable_flag;                  //reliable data, first two bytes is seq     //one byte
    ENCRYPT_FLAG_E      encrypt_flag;    
    REAL_TIME_FLAG_E    real_time;                      //real time cmd need to respond as quickly as possible
    CHAR_T              retry_max;
    CMD_RESULT_PRO_E    result_process;                 //cmd result process type
    TY_PRO_CMD          command_id;                              
    GW_REQ_TYPE_E       req_type;                       //request or response
    
}PACKED CMD_ATTR_S;

typedef struct {
    CHAR_T      base_key[ENCRYPT_KEY_LEN + 1];    
    BYTE_T      key[ENCRYPT_KEY_LEN + 1];
    BYTE_T      random_a[ENCRYPT_RANDOM_LEN + 1];      
    BYTE_T      random_b[ENCRYPT_RANDOM_LEN + 1];     
    ENCRYPT_STATE_E state;
    UINT16_T    seq;
    CHAR_T      result[ENCRYPT_RESULT_LEN_MAX + 1];        
    UINT16_T    result_len;
    CMD_ATTR_S  attr;                              
    
}PACKED ENCRYPT_INFO_S;

typedef struct {
    UINT16_T    seq;                                    //cmd seq
    BYTE_T      content[RELIABLE_DATA_LEN_MAX];         //cmd data
    
}PACKED RELIABLE_DATA_S;

typedef struct {
    UINT_T      tm;
    UINT16_T    seq;    
    
}PACKED ANTI_REPLAY_VAR_S;

typedef struct {
    UINT16_T    length;                                 //data length
    BYTE_T      data[ENCRYPT_DATA_MAX_LEN];
    
}PACKED ENCRYPT_S;

typedef struct
{
    ENCRYPT_INFO_S  info;    
    UCHAR_T         send_count;                         //cmd send count
    UCHAR_T         ack_count;                          //http ack count
    time_t          send_start;                         //cmd send start time
    time_t          ack_start;                          //http ack start time
    SLIST_HEAD      node;   
    
}PACKED ENCRYPT_CMD_S;

typedef struct {
    UINT16_T    seq;
    UINT_T      time;

}PACKED ENCRYPT_RECORD_UNIT_S;

#define ENCRYPT_RECORD_UNIT_MAX_CNT 10
typedef struct {
    BYTE_T                  offset;
    ENCRYPT_RECORD_UNIT_S   uint[ENCRYPT_RECORD_UNIT_MAX_CNT];
}PACKED ENCRYPT_RECORD_S;

typedef struct
{
    CHAR_T              addr[ENCRYPT_ADDR_LEN + 1];
    UINT_T              uddd;
    BYTE_T              key[ENCRYPT_KEY_LEN + 1];
    CHAR_T              base_key[ENCRYPT_KEY_LEN + 1];
    ENCRYPT_STATE_E     state;
    ty_cJSON*           authkey;
    ENCRYPT_RECORD_S    record;
    SLIST_HEAD  node;   
    
}PACKED ENCRYPT_DEV_S;

#define INIT_CMD_ATTR(attr, _addr, _type, _len, _encrypt_flag, _reliable_flag, _real_time, _retry_max, _result_process, _command_id, _req_type) \
                    do {                                                                            \
                        memset(&(attr), 0x0, sizeof(CMD_ATTR_S));                                     \
                        memcpy((attr).addr, _addr, ENCRYPT_ADDR_LEN);                                 \
                        (attr).type = _type;                                                          \
                        (attr).cmd_len = _len;                                                        \
                        (attr).encrypt_flag = _encrypt_flag;                                          \
                        (attr).reliable_flag = _reliable_flag;                                        \
                        (attr).real_time = _real_time;                                                \
                        (attr).retry_max = _retry_max;                                                \
                        (attr).result_process = _result_process;                                      \
                        (attr).command_id = _command_id;                                              \
                        (attr).req_type = _req_type;                                                  \
                    }while(0) 

#define RELIABLE_DATA_PACK(data, _seq, _msg, _len)                                                  \
                    do {                                                                            \
                        memset(&(data), 0x0, sizeof(RELIABLE_DATA_S));                                \
                        (data).seq = _seq;                                                            \
                        memcpy((data).content, _msg, _len);                                           \
                    }while(0) 

#define RELIABLE_COUNT_LEN(len)   (RELIABLE_HEAD_LEN + COM_HEAD_LEN + (len))

#define COM_DATA_PACK(com_data, _dpid, _type, _len, _data)                                          \
                    do {                                                                            \
                        (com_data)->dpid = _dpid;                                                     \
                        (com_data)->type = _type;                                                     \
                        (com_data)->len = _len;                                                       \
                        (com_data)->len = UNI_HTONS((com_data)->len);                                       \
                        memcpy((com_data)->data, _data, _len);                                        \
                    }while(0) 


VOID print_buf(BYTE_T *in, UINT_T len, CHAR_T *name);
OPERATE_RET encrypt_get_request(ENCRYPT_INFO_S *info, ENCRYPT_S *p_encrypt, REQ_TYPE_E type);
OPERATE_RET encrypt_gen_base_key(CONST char *address, ENCRYPT_INFO_S *info, TY_Z3_GLOBAL_T *p_global);
OPERATE_RET encrypt_gen_key(GW_ENCRYPT_S *p_gw_encrypt, BYTE_T *p_base_key, 
                                    ENCRYPT_S *p_encrypt, ENCRYPT_CMD_S *p_cmd);
OPERATE_RET encrypt_get_cmd_result(GW_ENCRYPT_S *p_gw_encrypt, ENCRYPT_S *p_encrypt, ENCRYPT_CMD_S *p_cmd);
OPERATE_RET gw_process_rept(CHAR_T *address, UCHAR_T command, ENCRYPT_S *p_rcv_encrypt, 
                                        GW_ENCRYPT_S *p_gw_encrypt, ENCRYPT_INFO_S *p_out_info);
OPERATE_RET gw_process_cmd(IN CONST CMD_ATTR_S *p_attr, IN GW_ENCRYPT_S *p_gw_encrypt);
OPERATE_RET encrypt_sync_config(IN GW_ENCRYPT_S *p_gw_encrypt, TY_Z3_GLOBAL_T *p_global);
TIME_T encrypt_next_sync_time(GW_ENCRYPT_S *p_gw_encrypt, UINT_T interval);
VOID encrypt_check_cmd(UINT_T timerID, PVOID_T pTimerArg);
OPERATE_RET gw_encrypt_init(GW_ENCRYPT_S *p_gw_encrypt);
OPERATE_RET gw_encrypt_dev_del(GW_ENCRYPT_S *p_gw_encrypt, CHAR_T *dev_id);
OPERATE_RET encrypt_start(IN GW_ENCRYPT_S *p_gw_encrypt, CHAR_T *address, TY_Z3_GLOBAL_T *p_global, UINT_T uddd);
OPERATE_RET encrypt_decode_result(TuYaApsFrame *p_aps, CHAR_T *address, UCHAR_T *data, UINT16_T length, GW_ENCRYPT_S *p_gw_encrypt,
                                            UCHAR_T **pp_out, UINT16_T *p_out_len);
OPERATE_RET encrypt_cmd_operate(GW_ENCRYPT_S *p_gw_encrypt, UINT16_T seq, ENCRYPT_CMD_S *p_cmd, 
                                                    ENCRYPT_CMD_OP_E op, LOCK_FLAG_E need_lock);
OPERATE_RET get_tail_buffer(CHAR_T *in, UINT_T in_size, BYTE_T *out, UINT_T out_size);

OPERATE_RET encrypt_start_v2_authkey(IN GW_ENCRYPT_S *p_gw_encrypt, IN CHAR_T *address, IN UINT_T uddd);
OPERATE_RET tuya_encrypt_authkey_send(IN GW_ENCRYPT_S *p_gw_encrypt, UINT_T uddd, CHAR_T *address, UCHAR_T *req_data, INT_T req_len);
OPERATE_RET tuya_encrypt_authkey_rand_check(IN GW_ENCRYPT_S *p_gw_encrypt, UINT_T uddd, CHAR_T *address, UCHAR_T *req_data, INT_T req_len);
OPERATE_RET encrypt_dev_record_opt(GW_ENCRYPT_S *p_gw_encrypt, CHAR_T *address, USHORT_T seq, UINT_T time, BOOL_T isCheck);

#endif
