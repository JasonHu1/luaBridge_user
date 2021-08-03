#ifndef __TUYA_BLE_MASTER_INTERNAL_H__
#define __TUYA_BLE_MASTER_INTERNAL_H__


#include "tuya_ble_master.h"
#include "tuya_ble_process.h"

#define TY_BLE_RDBUF_LEN    256

#ifdef __cplusplus
extern "C" {
#endif
#pragma pack(1)

#define TY_MASTER_CHECK_STAT_INTR       1       //second
#define TY_BLE_BIND_CONN_TM_MAX         5
#define TY_BLE_UNBIND_CONN_TM_MAX       8
#define TY_BLE_GATT_CONN_TM_MAX         10

typedef enum{
    TY_MASTER_STAT_INIT             = 0x0,
    TY_MASTER_STAT_START            = 0x1,
    TY_MASTER_STAT_WAIT_CONNECT     = 0x2,
    TY_MASTER_STAT_GET_INFO         = 0x3,
    TY_MASTER_STAT_WAIT_GET_INFO    = 0x4,
    TY_MASTER_STAT_GET_LOGIN_KEY    = 0x5,
    TY_MASTER_STAT_PAIR             = 0x6,
    TY_MASTER_STAT_WAIT_PAIR        = 0x7,
    TY_MASTER_STAT_SESSION_OPEN     = 0x8,

} TY_MASTER_DEV_STAT_E;

typedef enum{
    TY_MASTER_SET_ALL = 0,
    TY_MASTER_UPDATE_KEY = 1,
    TY_MASTER_UPDATE_STAT = 2,

} TY_MASTER_SET_TP_E;

typedef struct {
    ty_ble_key              *dev_key;
    ty_blep_recv_packet_s   *packet;
    BYTE_T                  *rdbuf;
	ty_frm_trsmitr_proc_s   trproc;
    INT_T                   rdlen;
    
    INT_T                   sn;
    INT_T                   bind;
	UINT8_T 			    mac[6];
    unsigned char           version;  // this is ble protocol version. should be 1/2/3
    TUYA_BT_HAL_DEV_TYPE_T  type;

    TY_MASTER_DEV_STAT_E    stat;
    TIME_T                  stat_update_tm;

    SLIST_HEAD              node;    

} TUYA_BLE_DEV_CONNECT_S;

typedef struct {
    SLIST_HEAD      dev_list;
    UINT16_T        dev_num;
    MUTEX_HANDLE    dev_mutex;

    TUYA_BLE_MASTER_CB_S cbs;
    UINT8_T         max_link;
    UINT8_T         gatt_conn_timeout;

} TUYA_MASTER_MGR_S;

#pragma pack()

CHAR_T *tuya_ble_master_stat_to_str(TY_MASTER_DEV_STAT_E stat);

#define TY_MASTER_STAT tuya_ble_master_stat_to_str
#define TY_MASTER_SET_STAT(p_dev, dev_stat)                                \
                    do {                                                    \
                        p_dev->stat = dev_stat;                             \
                        p_dev->stat_update_tm = uni_time_get_posix();       \
                        PR_DEBUG("set stat: %s", TY_MASTER_STAT(dev_stat));    \
                    }while(0)

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __TUYA_BLE_MASTER_H__

