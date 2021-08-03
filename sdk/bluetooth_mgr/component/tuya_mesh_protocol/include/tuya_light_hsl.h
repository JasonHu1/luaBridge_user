
#ifndef __LIGHT_HSL_H__
#define __LIGHT_CTL_H__

#ifdef __cplusplus
extern"C"{
#endif

#include "generic_transition_time.h"
#include "tuya_mesh_type.h"

//HSL
#define TUYA_MESH_MSG_LIGHT_HSL_GET                          		(0x826D)
#define TUYA_MESH_MSG_LIGHT_HSL_HUE_GET                      		(0x826E)
#define TUYA_MESH_MSG_LIGHT_HSL_HUE_SET                      		(0x826F)
#define TUYA_MESH_MSG_LIGHT_HSL_HUE_SET_UNACK                		(0x8270)
#define TUYA_MESH_MSG_LIGHT_HSL_HUE_STAT                     		(0x8271)
#define TUYA_MESH_MSG_LIGHT_HSL_SATURATION_GET               		(0x8272)
#define TUYA_MESH_MSG_LIGHT_HSL_SATURATION_SET               		(0x8273)
#define TUYA_MESH_MSG_LIGHT_HSL_SATURATION_SET_UNACK         		(0x8274)
#define TUYA_MESH_MSG_LIGHT_HSL_SATURATION_STAT              		(0x8275)
#define TUYA_MESH_MSG_LIGHT_HSL_SET                          		(0x8276)
#define TUYA_MESH_MSG_LIGHT_HSL_SET_UNACK                    		(0x8277)
#define TUYA_MESH_MSG_LIGHT_HSL_STAT                         		(0x8278)
#define TUYA_MESH_MODEL_LIGHT_HSL_SERVER                     		(0x1307)
#define TUYA_MESH_MODEL_LIGHT_HSL_SETUP_SERVER               		(0x1308)
#define TUYA_MESH_MODEL_LIGHT_HSL_CLIENT                     		(0x1309)
#define TUYA_MESH_MODEL_LIGHT_HSL_HUE_SERVER                 		(0x130A)
#define TUYA_MESH_MODEL_LIGHT_HSL_SATURATION_SERVER          		(0x130B)

typedef enum{
    LIGHT_HSL_SERVER_GET = 0,
    LIGHT_HSL_SERVER_GET_HUE,
    LIGHT_HSL_SERVER_GET_SATURATION,
    LIGHT_HSL_SERVER_GET_DEFAULT,
    LIGHT_HSL_SERVER_GET_RANGE,
    LIGHT_HSL_SERVER_GET_DEFAULT_TRANSITION_TIME,
    LIGHT_HSL_SERVER_SET,
    LIGHT_HSL_SERVER_SET_HUE,
    LIGHT_HSL_SERVER_SET_SATURATION,
    LIGHT_HSL_SERVER_SET_DEFAULT,
    LIGHT_HSL_SERVER_SET_RANGE,
}light_hsl_op_type_t;

typedef struct
{
    uint16_t lightness;
    uint16_t hue;
    uint16_t saturation;
} light_hsl_server_get_t;

typedef struct
{
    uint16_t lightness;
    uint16_t hue;
    uint16_t saturation;
    generic_transition_time_t total_time;
    generic_transition_time_t remaining_time;
} light_hsl_server_set_t;

typedef struct{
	uint16_t lightness;
	uint16_t hue;
	uint16_t sat;
	uint8_t remain_t;
}PACKED mesh_cmd_light_hsl_st_t;

typedef struct{
	uint16_t lightness;
	uint16_t hue;
	uint16_t sat;
	uint8_t tid;
//	uint8_t transit_t;
//	uint8_t delay;		// unit 5ms
}PACKED mesh_cmd_light_hsl_set_t;


#ifdef __cplusplus
}
#endif

#endif //__LIGHT_CTL_H__

