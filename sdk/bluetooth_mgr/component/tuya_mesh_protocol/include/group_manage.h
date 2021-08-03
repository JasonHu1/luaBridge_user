/*
 * group_manage.h
 *
 *  Created on: 2020-05-20
 *      Author: Joey
 */
 
#ifndef _GROUP_MANAGE_H
#define _GROUP_MANAGE_H

#include "tuya_mesh_type.h"
#include "mesh_protocol.h"

typedef enum{
    MESH_MSG_STAT_SUCCESS = 0x00,
    MESH_MSG_STAT_INVALID_ADDR,
    MESH_MSG_STAT_INVALID_MODEL,
    MESH_MSG_STAT_INVALID_APP_KEY_INDEX,
    MESH_MSG_STAT_INVALID_NET_KEY_INDEX,
    MESH_MSG_STAT_INSUFFICIENT_RESOURCES,
    MESH_MSG_STAT_KEY_INDEX_ALREADY_STORED,
    MESH_MSG_STAT_INVALID_PUB_PARAMS,
    MESH_MSG_STAT_NOT_SUB_MODEL, //8,
    MESH_MSG_STAT_STORAGE_FAIL,
    MESH_MSG_STAT_FEATURE_NOT_SUPPORTED,
    MESH_MSG_STAT_CANNOT_UPDATE,
    MESH_MSG_STAT_CANNOT_REMOVE,
    MESH_MSG_STAT_CANNOT_BIND,
    MESH_MSG_STAT_TEMP_UNABLE_CHANGE_STATE,
    MESH_MSG_STAT_CANNOT_SET,
    MESH_MSG_STAT_UNSPECIFIED_ERROR, //16
    MESH_MSG_STAT_INVALID_BINDING,
} mesh_msg_stat_t;

typedef enum{
    NONEED = 0x0,
    NEED_SUB,
    SUB_SUCCESS,
    SUB_FAIL,
    SUB_INSUFFICIENT_RESOURCES,
}sub_flag_t;


typedef struct {
    uint16_t ele_addr;
    uint16_t group_addr;
    uint32_t model_id;
    sub_flag_t  sub_flg;
}PACKED model_sub_info_t;

typedef struct {
    uint8_t stat;
    uint16_t element_addr;
    uint16_t addr;
    uint32_t model_id; //!< 2 bytes or 4 bytes
}PACKED model_sub_status_t;

#define MODEL_SUB_MAX_CNT    10

typedef struct {
    uint16_t cnt;
    model_sub_info_t model_sub[MODEL_SUB_MAX_CNT];
}PACKED model_sub_t;

typedef enum{
    GROUP_ADD = 0,
    GROUP_DEL = 1,
}group_manage_type_t;


typedef VOID (*mesh_grp_manage_result_cb)(OPERATE_RET op_ret, VOID *prv_data);
void tuya_mesh_group_manage(group_manage_type_t manage_type, uint16_t mesh_addr, uint16_t group_addr, 
                            mesh_grp_manage_result_cb result_cb, VOID *prv_data);
void tuya_mesh_group_manage_asyn(group_manage_type_t manage_type, uint16_t mesh_addr, uint16_t group_addr);
void group_sub_proc_check_proc(void);
void group_sub_status_recv(uint16_t mesh_addr, tuya_mesh_client_data_t *mesh_data);

#endif /* _GROUP_MANAGE_H */



