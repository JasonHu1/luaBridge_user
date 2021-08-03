/*************************************************************************
    > File Name: fast_prov.h
    > Author: 
    > Mail: 
    > Created Time: Sat 08 Dec 2018 04:10:00 PM CST
 ************************************************************************/

#ifndef _FASET_PROV_H
#define _FASET_PROV_H

#include "tuya_mesh_type.h"

#define GET_MAC_DELAY    3000
#define FP_MAX_CNT       16
#define FP_SET_ADDR_CYCLE        (1)// 1s
#define FP_GET_MAC_DELAY         (1500)
#define FP_SET_PROVDATA_CNT      (1)
#define FP_SET_PROVDATA_DELAY    (1500)
#define FP_CONFIRM_DELAY         (1500)


#define MESH_NET_KEY    {0x07, 0xD0, 0x14, 0x33, 0xA9, 0x54, 0xA4, 0x60, 0xAD, 0x16, 0x89, 0xE6, 0x59, 0x4F, 0x07, 0xDA}
#define MESH_APP_KEY    {0xD0, 0x07, 0x10, 0xA0, 0xA6, 0x01, 0x37, 0x08, 0x54, 0xE3, 0x2E, 0x17, 0x7A, 0xFD, 0x11, 0x59}

typedef enum
{
    FP_SUC = 0,
    FP_FAIL,
}fp_ret_t;

typedef enum {
    TY_MESH_FAST_PROV_STOP = 1,

}TY_MESH_FAST_PROV_STAT_E;

typedef fp_ret_t (*fp_retry_func_t)(void *context);


typedef struct
{
    uint8_t bt_addr[6];
    uint16_t kind_num;
    uint8_t tuya_pid[8];
} PACKED tuya_mesh_device_info, *tuya_mesh_device_info_p;

typedef struct
{
    tuya_mesh_device_info device_info;
    uint16_t mesh_addr;
    uint16_t version;
    bool is_FK;
} PACKED tuya_mesh_node_t, *tuya_mesh_node_p;


typedef enum{
    FP_IDLE = 0,
    FP_START,
    FP_DATA_CLEAR,
    FP_GET_MAC,
    FP_GET_MAC_WAIT,
    FP_NEW_ADDR_DISTIBUT,
    FP_SET_ADDR,
    FP_PROV_DATA_SET,
    FP_PROV_DATA_SET_WAIT,
    FP_CONFIRM,
    FP_CONFIRM_WAIT,
    FP_CONFIRM_CHECK,
    FP_COMMPLETE,
    FP_NODE_JOIN,
    FP_STOP,

    LP_KEY_REFRESH,
    LP_PROV_SET,
    LP_PROV_DATA_SET_WAIT,
}fp_state;

typedef struct{
    fp_state pre_state;
    fp_state cur_state;
}fp_par_t;

typedef struct{
    uint16_t category;
    uint16_t ele_addr;
}mac_get_t;

typedef struct{
    uint8_t mac[6];
    uint16_t category;
}mac_get_st_t;

typedef struct{
    uint8_t mac[6];
    uint16_t unicast_addr;
}mac_set_t;

typedef struct{
    uint16_t unicast_addr;
    uint8_t is_FK;
    uint8_t pid[8];
    uint16_t version;
}PACKED mac_set_st_t;


typedef struct{
    uint8_t KeyRefresh   :1;
    uint8_t IVUpdate     :1;
    uint8_t RFU          :6;
}mesh_ctl_fri_update_flag_t;

typedef struct{
    uint8_t  net_key[16];
    uint16_t  key_index;
    union{
        mesh_ctl_fri_update_flag_t prov_flags;
        uint8_t  flags;
    };
    uint8_t  iv_index[4];
    uint16_t  unicast_address;
    uint8_t net_app_idx[3];
    uint8_t app_key[16];
}PACKED prov_data_set_t;

typedef struct{
    bool is_FK;
    bool addr_rsp;
    bool join_send_flg;
    bool confirm_rsp;
    uint8_t mac[6];
    uint8_t pid[8];
    uint16_t category;
    uint16_t init_addr;
    uint16_t unicast_addr;
    uint16_t version;
}PACKED unprov_device_info;

typedef struct{
    uint16_t old_addr;
    uint16_t new_addr;
}node_addr_update_list_t;

void fast_prov_data_recv(uint16_t mesh_addr, tuya_mesh_client_data_t *mesh_data);

typedef VOID (*TY_MESH_FAST_PROV_STAT_CB)(TY_MESH_FAST_PROV_STAT_E stat);
void tuya_fast_provision_start(TY_MESH_FAST_PROV_STAT_CB stat_cb);
void tuya_fast_provision_stop(void);
void fast_prov_proc(void);

#endif
