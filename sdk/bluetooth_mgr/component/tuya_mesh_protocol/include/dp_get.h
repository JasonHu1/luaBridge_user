/*
 * dp_get.h
 *
 *  Created on: 2020-05-20
 *      Author: Joey
 */
 
#ifndef _DP_GET_H
#define _DP_GET_H

#include "tuya_mesh_type.h"
#include "mesh_protocol.h"


typedef tuya_result_t (*tuya_dp_get_map_func_t)(tuya_mesh_client_data_t* mesh_data);

typedef struct
{
	uint8_t dp_id;
    uint32_t model_id;
	tuya_dp_get_map_func_t handle_func;
} tuya_get_dp_map_t;



#endif /* _DP_GET_H */
