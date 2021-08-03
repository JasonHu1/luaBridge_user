/*
 * mesh_adapter.h
 *
 *  Created on: 2020-05-20
 *      Author: Joey
 */
 
#ifndef _MESH_ADAPT_H
#define _MESH_ADAPT_H
#include "tuya_gw_com_api.h"
typedef enum{
    OBJ_TYPE = 0,
    RAW_TYPE,
}TY_RECV_DP_TYPE_S;

typedef struct{
    union
    {
        TY_RECV_OBJ_DP_S *obj_dp;
        TY_RECV_RAW_DP_S *raw_dp;
    };
    TY_RECV_DP_TYPE_S type;
}TY_RECV_DP_S;


void tuya_dp_data_send(TY_RECV_DP_S *recv_dp);

void tuya_dp_data_get(TY_DP_QUERY_S *dp_qry);

OPERATE_RET tuya_group_manage(GRP_ACTION_E action, CHAR_T *dev_id,CHAR_T *grp_id);

extern OPERATE_RET tuya_mesh_uuid_data_transmit(uint8_t *data, uint16_t data_len, uint8_t *pid, uint16_t pid_len, uint16_t *pk_type);

extern OPERATE_RET tuya_mesh_compsition_data_transmit(uint8_t *data, uint16_t data_len, uint8_t *ver, uint16_t ver_len, uint8_t *is_oem);




#endif /* _MESH_ADAPT_H */






















