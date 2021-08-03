/*
tuya_gw_bt_comm.h
*/

#ifndef TUYA_GW_BT_COMM_H
#define TUYA_GW_BT_COMM_H

#include <stdio.h>
#include <string.h>
#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "uni_log.h"
#include "ty_cJSON.h"
#include "mem_pool.h"
#include "uni_slist.h"
#include "tuya_iot_com_api.h"
#include "tuya_gw_com_api.h"
#include "tuya_hal_mutex.h"
// #include "tuya_global_errcode.h"
#include "tuya_bt_hal.h"
#include "tuya_os_adapter.h"
#include "uni_thread.h"
#include "uni_time.h"
#include "sys_timer.h"
#include "gw_intf.h"
#include "tuya_gw_bt_api.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef PACKED
#define PACKED __attribute__ ((packed))
#endif

#define TY_BT_DEV_HB_TM                     (300) 
#define TY_BT_DEV_LOWPOER_HB_TM             (12 * 3600) //lowpower dev: use this value; not lowpower dev: not use this value, base sdk adaptive
#define TY_BT_DEV_MAX_RESEND_TM     2       

#define TY_BT_DP_CNT_MAX        10

#define TY_BT_DP_TP_RAW         0
#define TY_BT_DP_TP_BOOL        1
#define TY_BT_DP_TP_VALUE       2
#define TY_BT_DP_TP_STR         3
#define TY_BT_DP_TP_ENUM        4
#define TY_BT_DP_TP_BITMAP      5

typedef enum {
    TY_BT_OP_MIN = -1,
    TY_BT_OP_GET,
    TY_BT_OP_SET,
    TY_BT_OP_DEL,
    TY_BT_OP_MAX,
    
} TY_BT_DEV_OP_E;  

typedef enum {
    TY_BT_JOIN_START = 1,
    TY_BT_JOIN_STOP = 2,

} TY_BT_JOIN_STAT_E;

typedef enum {
    TY_BT_ADAPTER_BLE = 1,
    TY_BT_ADAPTER_MESH = 2,
    TY_BT_ADAPTER_INVALD,

}TY_BT_ADAPTER_TP_E;        //tuya bt adapter type

typedef enum{
    TY_BT_TYPE_OBJ = 0,
    TY_BT_TYPE_RAW,

}TY_BT_RECV_DP_TYPE_S;

typedef struct {
    BYTE_T  dpid;
    BYTE_T  type;
    BYTE_T  len;
    BYTE_T  data[0];

} PACKED TY_BT_COM_DATA_S;

#define TY_GW_BT_LOCK(mutex)                                \
                    do {                                    \
                        PR_DEBUG("%s lock", __func__);      \
                        tuya_hal_mutex_lock(mutex);         \
                    }while(0) 


#define TY_GW_BT_UNLOCK(mutex)                              \
                    do {                                    \
                        tuya_hal_mutex_unlock(mutex);       \
                        PR_DEBUG("%s unlock", __func__);    \
                    }while(0) 

#define TY_BT_TIME_UP(start_tm, interval) ((uni_time_get_posix() > start_tm) && (uni_time_get_posix() - start_tm >= interval))

#ifndef PR_TRACE_WITH_MAC
#define PR_TRACE_WITH_MAC(str, mac, fmt, ...) \
do \
{ \
    PR_TRACE("MAC: %02x:%02x:%02x:%02x:%02x:%02x " str, \
             mac[0],mac[1],mac[2],mac[3],mac[4],mac[5], fmt,##__VA_ARGS__); \
}while(0)
#endif

#ifndef PR_DEBUG_WITH_MAC
#define PR_DEBUG_WITH_MAC(str, mac, fmt, ...) \
do \
{ \
    PR_DEBUG("MAC: %02x:%02x:%02x:%02x:%02x:%02x " str, \
             mac[0],mac[1],mac[2],mac[3],mac[4],mac[5], fmt,##__VA_ARGS__); \
}while(0)
#endif

#ifndef PR_ERR_WITH_MAC
#define PR_ERR_WITH_MAC(str, mac, fmt, ...) \
do \
{ \
    PR_ERR("MAC: %02x:%02x:%02x:%02x:%02x:%02x " str, \
             mac[0],mac[1],mac[2],mac[3],mac[4],mac[5], fmt,##__VA_ARGS__); \
}while(0)
#endif

OPERATE_RET tuya_bt_get_mesh_pk_type(UINT16_T addr, UINT16_T *pk_tpye);
OPERATE_RET tuya_bt_get_mesh_dev_info(INOUT TUYA_BT_HAL_MESH_DEV_S *p_dev);
void tuya_bt_hex2str(unsigned char *pbDest, unsigned char *pbSrc, int nLen);

OPERATE_RET tuya_bt_set_gw_stat(TY_BT_GW_STAT_E stat);
TY_BT_GW_STAT_E tuya_bt_get_gw_stat();
OPERATE_RET tuya_bt_set_bt_mode(TUYA_BT_HAL_WORK_MODE_E mode);
TUYA_BT_HAL_WORK_MODE_E tuya_bt_get_bt_mode();

OPERATE_RET tuya_bt_com_to_dp(CONST TY_BT_COM_DATA_S *p_com, TY_OBJ_DP_S *p_dp);
OPERATE_RET tuya_bt_dp_to_com(CONST TY_OBJ_DP_S *p_dp, TY_BT_COM_DATA_S **pp_com);
OPERATE_RET tuya_bt_raw_dp_to_com(CONST TY_RECV_RAW_DP_S *p_dp, TY_BT_COM_DATA_S **pp_com);

OPERATE_RET tuya_bt_report_join_stat(TY_BT_ADAPTER_TP_E type, TY_BT_JOIN_STAT_E stat);

#ifdef __cplusplus
}
#endif
#endif
