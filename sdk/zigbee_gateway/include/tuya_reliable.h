/***********************************************************
*  File: tuya_reliable.h
*  Author: dingsl
*  Date: 20180707
***********************************************************/
#ifndef __GATEWAY_RELIABLE_H
#define __GATEWAY_RELIABLE_H

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
#include "tuya_encrypt.h"

//Optional feature, need to define a macro
#define TUYA_RELIABLE_TRD_DEV_SUPPORT 1
#define TUYA_RELIABLE_MCU_OTA_SUPPORT 1
#define TUYA_RELIABLE_FINGERPRINT_SUPPORT 1

#define MD5_OUT_LEN                 0x10  
#define LOCK_DYNAMIC_KEY            0x57  
#define LOCK_DYNAMIC_KEY_LEN        MD5_OUT_LEN  
#define SYNC_TIME_DATA_LEN          0x9
#define RECORD_REPORT_RETRY_TIME    0x3
#define REPORT_DP_TIMEOUT           0x3             //3s


#if defined(GW_PLATFORM) && (GW_PLATFORM==GW_RTL8711AM)
#define IS_CLOUD_CONN(x)	((x == STAT_CLOUD_CONN) || (x == STAT_AP_CLOUD_CONN))
#endif

typedef enum {
    FLAG_NO_TS = 0,                                 //no timestamp
    FLAG_HAVE_TS = 1
    
} RECORD_TIME_FLAG_E;   

typedef struct {
    UINT16_T    seq;    
    UINT_T      time;
    UINT_T      local_time;
    
}PACKED RELIABLE_SYNC_TIME_S;

typedef struct {
    UINT16_T    seq;        
    BYTE_T      time_flag;
    UINT_T      time;
    
}PACKED RECORD_DATA_HEAD_S;

typedef struct {
    UINT16_T    seq;    
    UINT8_T     stat;
    
}PACKED RELIABLE_NET_STAT_S;

OPERATE_RET gw_lock_pwd_ack(GW_ENCRYPT_S *p_gw_encrypt, ENCRYPT_CMD_S *p_cmd, LOCK_FLAG_E need_lock);
OPERATE_RET tuya_reliable_down_process(IN UINT_T uddd, UCHAR_T *msg, UINT_T len, TuYaApsFrame *sTyApsFrameTmp, BOOL_T isStdReliable);
OPERATE_RET gw_lock_send_dynamic_key(ENCRYPT_DEV_S *p_dev);
OPERATE_RET tuya_reliable_sync_time(UINT_T uddd, CHAR_T *address, UCHAR_T *req_data, INT_T req_len);
OPERATE_RET tuya_send_reliable_net_stat(UINT_T uddd, CHAR_T *address, UCHAR_T *req_data, INT_T req_len);
OPERATE_RET tuya_report_net_stat_change();
OPERATE_RET tuya_up_record_process(TuYaApsFrame *sTyApsFrameTmp, CHAR_T *address, UCHAR_T *buffer, INT_T len);
OPERATE_RET tuya_reliable_report_process(DEV_DESC_IF_S *dev_if, TuYaApsFrame *aps, UCHAR_T *buffer, USHORT_T *p_len);
char *str_toupper(char *str);
OPERATE_RET tuya_lock_pwd_ack_req(IN CHAR_T *data);
OPERATE_RET tuya_lock_get_confirm_list_req(OUT ty_cJSON **result);

#endif
