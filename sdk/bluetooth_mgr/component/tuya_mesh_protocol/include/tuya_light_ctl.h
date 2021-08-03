
#ifndef __LIGHT_CTL_H__
#define __LIGHT_CTL_H__

#ifdef __cplusplus
extern"C"{
#endif

#include "generic_transition_time.h"
#include "tuya_mesh_type.h"

//CTL
#define TUYA_MESH_MSG_LIGHT_CTL_GET                          		(0x825D)
#define TUYA_MESH_MSG_LIGHT_CTL_SET                          		(0x825E)
#define TUYA_MESH_MSG_LIGHT_CTL_SET_UNACK                    		(0x825F)
#define TUYA_MESH_MSG_LIGHT_CTL_STAT                         		(0x8260)
#define TUYA_MESH_MODEL_LIGHT_CTL_SERVER                     		(0x1303)
#define TUYA_MESH_MODEL_LIGHT_CTL_SETUP_SERVER               		(0x1304)
#define TUYA_MESH_MODEL_LIGHT_CTL_CLIENT                     		(0x1305)

//CTL_TEMP
#define TUYA_MESH_MSG_LIGHT_CTL_TEMPERATURE_GET              		(0x8261)
#define TUYA_MESH_MSG_LIGHT_CTL_TEMPERATURE_RANGE_GET        		(0x8262)
#define TUYA_MESH_MSG_LIGHT_CTL_TEMPERATURE_RANGE_STAT       		(0x8263)
#define TUYA_MESH_MSG_LIGHT_CTL_TEMPERATURE_SET              		(0x8264)
#define TUYA_MESH_MSG_LIGHT_CTL_TEMPERATURE_SET_UNACK        		(0x8265)
#define TUYA_MESH_MSG_LIGHT_CTL_TEMPERATURE_STAT             		(0x8266)
#define TUYA_MESH_MODEL_LIGHT_CTL_TEMPERATURE_SERVER         		(0x1306) //!< TEMPERATURE msg/state is duplicate with CTL SERVER


typedef enum{
    LIGHT_CTL_SERVER_GET,
//    LIGHT_CTL_SERVER_GET_DEFAULT,
    LIGHT_CTL_SERVER_GET_TEMPERATURE,
//    LIGHT_CTL_SERVER_GET_TEMPERATURE_RANGE,
//    LIGHT_CTL_SERVER_GET_DEFAULT_TRANSITION_TIME,
    LIGHT_CTL_SERVER_SET,
    LIGHT_CTL_SERVER_SET_TEMPERATURE,
//    LIGHT_CTL_SERVER_SET_DEFAULT,
//    LIGHT_CTL_SERVER_SET_TEMPERATURE_RANGE,
}light_ctl_op_type_t;

typedef struct
{
    uint16_t lightness;
    uint16_t temperature;
} light_ctl_server_get_t;

typedef struct
{
    uint16_t temperature;
    int16_t delta_uv;
} light_ctl_server_get_temperature_t;

typedef struct
{
    uint16_t lightness;
    uint16_t temperature;
    int16_t delta_uv;
//    generic_transition_time_t total_time;
//    generic_transition_time_t remaining_time;
} light_ctl_server_set_t;

typedef struct
{
    uint16_t temperature;
    int16_t delta_uv;
//    generic_transition_time_t total_time;
//    generic_transition_time_t remaining_time;
} light_ctl_server_set_temperature_t;

typedef struct{
	uint16_t present_lightness;
	uint16_t present_temp;
	uint16_t target_lightness;
	uint16_t target_temp;
	uint8_t remain_t;
}PACKED mesh_cmd_light_ctl_st_t;

typedef struct{
	uint16_t present_temp;
	int16_t present_delta_uv;
	uint16_t target_temp;
	int16_t target_delta_uv;
	uint8_t remain_t;
}PACKED mesh_cmd_light_ctl_temp_st_t;

typedef struct{
	uint16_t lightness;		// lightness ctl is same with lightness
	uint16_t temp;			// 0x0320 -- 0x4E20  :800--20000
	int16_t delta_uv;
	uint8_t tid;
//	uint8_t transit_t;
//	uint8_t delay;		// unit 5ms
}PACKED mesh_cmd_light_ctl_set_t;

typedef struct{
	uint16_t temp;
	int16_t delta_uv;
	uint8_t tid;
//	uint8_t transit_t;
//	uint8_t delay;
}PACKED mesh_cmd_light_ctl_temp_set_t;



#ifdef __cplusplus
}
#endif

#endif //__LIGHT_CTL_H__

