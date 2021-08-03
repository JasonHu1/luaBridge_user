/*
 * dp_control.h
 *
 *  Created on: 2020-05-15
 *      Author: Joey
 */
 
#ifndef _DP_CONTROL_H
#define _DP_CONTROL_H

#include "tuya_mesh_type.h"
#include "mesh_protocol.h"

//--------------------

typedef enum
{
    DP_TO_MESH=0,
    MESH_TO_DP,
}tuya_dp_map_convert_direct_t;


#define TUYA_DP_TYPE_RAW 0
#define TUYA_DP_TYPE_BOOL 1
#define TUYA_DP_TYPE_VALUE 2
#define TUYA_DP_TYPE_STRING 3
#define TUYA_DP_TYPE_ENUM 4
#define TUYA_DP_TYPE_BITMAP 5

#define TUYA_DP_VALUE_LEN 4 // int
#define TUYA_DP_BOOL_LEN 1
#define TUYA_DP_ENUM_LEN 1
#define TUYA_DP_STR_MAX 255

typedef tuya_result_t (*tuya_dp_map_convert_func_t)(tuya_mesh_dp_point_t *dp_data, tuya_mesh_client_data_t *mesh_data,
                                            tuya_dp_map_convert_direct_t direct, uint8_t need_ack);

typedef struct
{
    uint8_t dp_id;
    uint32_t model_id;
    tuya_dp_map_convert_func_t handle_func;
} tuya_dp_map_t;



extern int tuya_vendor_mesh2dp_frame(uint8_t *frame_buf, uint16_t frame_len, tuya_mesh_dp_point_t *dp_data);

extern int tuya_vendor_dp2mesh_frame(tuya_mesh_dp_point_t *dp_data, uint8_t *frame_buf, uint16_t* frame_len);

extern void tuya_dp_data_upload(uint8_t *dev_id, tuya_mesh_dp_point_t *dp_data);


void tuya_mesh_dp_data_recv(uint16_t mesh_addr, tuya_mesh_client_data_t *mesh_data);


#endif /* _DP_CONTROL_H */
