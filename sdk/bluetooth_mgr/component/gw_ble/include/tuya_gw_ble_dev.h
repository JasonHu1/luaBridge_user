/*
tuya_gw_ble_dev.h
*/

#ifndef TUYA_GW_BLE_DEV_H
#define TUYA_GW_BLE_DEV_H

#include "tuya_gw_bt_api.h"
#include "tuya_bt_hal.h"
#include "tuya_gw_bt_comm.h"
#include "tuya_ble_master.h"

#define TY_BLE_LIST_MAX             60
#define TY_BLE_UNBIND_DEV_MAX       5
#define TY_BLE_CONN_TO_TM           70      //app heartbeat: once every 60 seconds. may be lost
#define TY_BLE_CONNING_TO_TM        15      
#define TY_BLE_DISCONNING_TO_TM     1      
#define TY_BLE_UNCONNECT_RETRY_TM   2      
#define TY_BLE_UNBIND_CONN_INTR     1       //second
#define TY_BLE_CHECK_STAT_INTR      1       //second
#define TY_BLE_SCAN_TO_TM_MIN       5
#define TY_BLE_SCAN_TO_TM_MAX       60
#define TY_BLE_DEV_ID_LEN           16
#define TY_BLE_GATT_CONN_RETRY_MAX  2

#define TY_BLE_OP_UPDATE_SCAN_TIME      0x20
#define TY_BLE_OP_UPDATE_SCAN_REQ_INFO  0x21
#define TY_BLE_OP_UPDATE_DEV_STAT       0x22
#define TY_BLE_OP_UPDATE_CONN           0x23

#ifdef __cplusplus
extern "C" {
#endif

typedef enum{
    TY_BLE_STAT_UNCONNECT = 0,
    TY_BLE_STAT_WAITING = 1,
    TY_BLE_STAT_CONNECTING = 2,
    TY_BLE_STAT_CONNECTED = 3,
    TY_BLE_STAT_DISCONNING = 4,
    TY_BLE_STAT_NONE = 5            

} TY_BLE_DEV_STAT_E;

typedef enum{
    TY_BLE_CONN_NORMAL = 0,
    TY_BLE_CONN_IMMEDIATE = 1,      //immediate connect device 

} TY_BLE_CONN_REQ_TYPE_E;

#pragma pack(1)
typedef struct {
    UINT8_T connected;
    UINT8_T connecting;
    UINT8_T unbind;
    UINT8_T disconning;
    UINT8_T waiting;

    UINT8_T bind_connecting;    //already bind and connecting

} TUYA_BLE_DEV_COUNT_S;

typedef struct {
    BOOL_T      fail;
    UINT8_T     retry;

} TUYA_BLE_CONNECT_S;

typedef struct{
    CHAR_T              id[TY_BLE_DEV_ID_LEN + 1];
    TY_BLE_DEV_STAT_E   stat;
    TUYA_BLE_DEV_INFO_S info;

    BOOL_T              online;
    TIME_T              stat_update_tm;
    TIME_T              scan_tm;
    TUYA_BLE_CONNECT_S  connect;

    SLIST_HEAD  node;    

} TUYA_BLE_DEV_S;

typedef struct {
    UINT8_T         max_count;
    BOOL_T          join_permit;
    UINT8_T         scan_to_tm;
    
    SLIST_HEAD      dev_list;
    UINT16_T        dev_num;
    MUTEX_HANDLE    dev_mutex;

} TUYA_BLE_DEV_MGR_S;
#pragma pack()

OPERATE_RET tuya_ble_dev_mgmt_start(UINT8_T max_conn, UINT8_T scan_to_tm);
VOID tuya_ble_dev_check_conn();
VOID tuya_ble_dev_check_stat();
OPERATE_RET tuya_ble_unbind_scan_req(TUYA_BLE_DEV_INFO_S *p_info);
OPERATE_RET tuya_ble_bind_scan_req(TUYA_BLE_DEV_INFO_S *p_info);
OPERATE_RET tuya_ble_dev_conn_list(UCHAR_T dev_num, CHAR_T **dev_list);
OPERATE_RET tuya_ble_dev_conn(TUYA_BLE_DEV_S *p_dev, TY_BLE_CONN_REQ_TYPE_E type);
OPERATE_RET tuya_ble_dev_disconn(TUYA_BLE_DEV_S *p_dev);
OPERATE_RET tuya_ble_dev_disconn_longest();
OPERATE_RET tuya_ble_dev_heartbeat();
OPERATE_RET tuya_ble_conn_update_stat(TUYA_BLE_DEV_S *p_dev, TY_BLE_DEV_STAT_E stat);
OPERATE_RET tuya_ble_update_scan_time(TUYA_BLE_DEV_S *p_dev);
OPERATE_RET tuya_ble_get_dev_count(TUYA_BLE_DEV_COUNT_S *p_count);
OPERATE_RET tuya_ble_get_dev_auth_key(INOUT TUYA_BLE_DEV_INFO_S *p_info);
OPERATE_RET tuya_ble_get_dev(IN CHAR_T *id, OUT TUYA_BLE_DEV_S *p_dev);
OPERATE_RET tuya_ble_get_dev_by_mac(IN BYTE_T *pmac, OUT TUYA_BLE_DEV_S *p_dev);
OPERATE_RET tuya_ble_dev_clear_unbind();
OPERATE_RET tuya_ble_dev_join(BOOL_T permit);
OPERATE_RET tuya_ble_dev_del(TUYA_BLE_DEV_S *p_dev);
CHAR_T *tuya_ble_dev_stat_to_str(TY_BLE_DEV_STAT_E stat);
OPERATE_RET tuya_ble_check_conn_retry(CHAR_T *id);
OPERATE_RET tuya_ble_report_conn_fail(TUYA_BLE_DEV_S *p_dev);
OPERATE_RET tuya_ble_sync_to_dev_list(IN CHAR_T *id);

#define TY_BLE_NOT_NEED_RECONNECT(stat) (TY_BLE_STAT_WAITING == stat || TY_BLE_STAT_CONNECTING == stat ||\
                                         TY_BLE_STAT_CONNECTED == stat || TY_BLE_STAT_DISCONNING == stat)

#define TY_BLE_STAT tuya_ble_dev_stat_to_str

#define TY_BLE_SET_DEV_STAT(p_dev, dev_stat)                                \
                    do {                                                    \
                        p_dev->stat = dev_stat;                             \
                        p_dev->stat_update_tm = uni_time_get_posix();       \
                        PR_DEBUG("set stat: %s", TY_BLE_STAT(dev_stat));    \
                    }while(0)

#ifdef __cplusplus
}
#endif
#endif
