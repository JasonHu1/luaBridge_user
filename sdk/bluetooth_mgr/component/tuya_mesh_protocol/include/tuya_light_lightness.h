
#ifndef __LIGHT_LIGHTNESS_H__
#define __LIGHT_LIGHTNESS_H__

#ifdef __cplusplus
extern"C"{
#endif

#include "generic_transition_time.h"

//LIGHTNESS
#define TUYA_MESH_MSG_LIGHT_LIGHTNESS_GET                    		(0x824B)
#define TUYA_MESH_MSG_LIGHT_LIGHTNESS_SET                    		(0x824C)
#define TUYA_MESH_MSG_LIGHT_LIGHTNESS_SET_UNACK              		(0x824D)
#define TUYA_MESH_MSG_LIGHT_LIGHTNESS_STAT                   		(0x824E)
#define TUYA_MESH_MODEL_LIGHT_LIGHTNESS_SERVER               		(0x1300)
#define TUYA_MESH_MODEL_LIGHT_LIGHTNESS_SETUP_SERVER         		(0x1301)
#define TUYA_MESH_MODEL_LIGHT_LIGHTNESS_CLIENT               		(0x1302)

typedef enum{
    LIGHT_LIGHTNESS_SERVER_GET = 0,
    LIGHT_LIGHTNESS_SERVER_SET,
}light_lightness_op_type_t;

typedef struct
{
    uint16_t lightness;
} light_lightness_server_get_t;

typedef struct
{
    uint16_t lightness;
//    generic_transition_time_t total_time;
//    generic_transition_time_t remaining_time;
} light_lightness_server_set_t;

typedef struct{
	uint16_t present;
	uint16_t target;
	uint8_t remain_t;
}PACKED mesh_cmd_lightness_st_t;

typedef struct{
	uint16_t lightness;
	uint8_t tid;
//	generic_transition_time_t transit_t;
//	uint8_t delay;		// unit 5ms
}PACKED mesh_cmd_lightness_set_t;

#ifdef __cplusplus
}
#endif

#endif //__LIGHT_LIGHTNESS_H__

