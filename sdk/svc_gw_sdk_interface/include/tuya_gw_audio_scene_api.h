/*
tuya_gw_audio_scene_api.h
Copyright(C),2018-2020, 涂鸦科技 www.tuya.comm
*/

#ifndef __TUYA_GW_AUDIO_SCENE_API_H
#define __TUYA_GW_AUDIO_SCENE_API_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
extern "C" {
#endif


#define MAX_AUDIO_SCENE_NAME (128-1)

typedef enum{	 
	AUDIO_SCENE_RESULT_NOT_FOUND = 0,
    AUDIO_SCENE_RESULT_OK = 1,
	AUDIO_SCENE_RESULT_NET_ERROR = 2,
	AUDIO_SCENE_RESULT_OTHER = 3,
} AUDIO_SCENE_RESULT_E;

typedef struct 
{ 
    USHORT_T seq_no;
    USHORT_T scene_id;
    CHAR_T country_code[4];
    CHAR_T cid[DEV_ID_LEN + 1];
    CHAR_T scene_name[0];
} AUDIO_SCENE_REQ_ST;


typedef struct 
{
    USHORT_T seq_no;
    USHORT_T scene_id;
    AUDIO_SCENE_RESULT_E result;
    CHAR_T cid[DEV_ID_LEN + 1];
    CHAR_T scene_name[0];
} AUDIO_SCENE_RSP_ST;

typedef VOID (*AUDIO_SCENE_CB)(CONST AUDIO_SCENE_RSP_ST * rsp);

OPERATE_RET audio_scene_module_init();

OPERATE_RET audio_scene_reg_cb(AUDIO_SCENE_CB cb);

OPERATE_RET audio_scene_exe(CONST AUDIO_SCENE_REQ_ST * req);


#ifdef __cplusplus
}
#endif
#endif

