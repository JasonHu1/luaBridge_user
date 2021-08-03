
#ifndef __GENERIC_ON_OFF_H__
#define __GENERIC_ON_OFF_H__

#ifdef __cplusplus
extern"C"{
#endif

#include "generic_transition_time.h"
#include "tuya_mesh_type.h"

//ON/OFF
#define TUYA_MESH_MSG_GENERIC_ON_OFF_GET                     		(0x8201)
#define TUYA_MESH_MSG_GENERIC_ON_OFF_SET                     		(0x8202)
#define TUYA_MESH_MSG_GENERIC_ON_OFF_SET_UNACK               		(0x8203)
#define TUYA_MESH_MSG_GENERIC_ON_OFF_STAT                    		(0x8204)
#define TUYA_MESH_MODEL_GENERIC_ON_OFF_SERVER                		(0x1000)
#define TUYA_MESH_MODEL_GENERIC_ON_OFF_CLIENT                		(0x1001)

typedef enum{
    GENERIC_ON_OFF_SERVER_GET = 0,
    GENERIC_ON_OFF_SERVER_GET_DEFAULT_TRANSITION_TIME,
    GENERIC_ON_OFF_SERVER_SET,
}genric_on_off_op_type_t;

typedef struct
{
    uint8_t on_off;
} generic_on_off_server_get_t;

typedef struct
{
    uint8_t on_off;
//    generic_transition_time_t total_time;
//    generic_transition_time_t remaining_time;
} generic_on_off_server_set_t;

typedef struct{
	uint8_t present;
	uint8_t target;
	uint8_t remain_t;
}PACKED mesh_cmd_g_onoff_st_t;

typedef struct{
	uint8_t onoff;
	uint8_t tid;
//	uint8_t transit_t;
//	uint8_t delay;		// unit 5ms
}PACKED mesh_cmd_g_onoff_set_t;



#ifdef __cplusplus
}
#endif

#endif //__GENERIC_ON_OFF_H__

