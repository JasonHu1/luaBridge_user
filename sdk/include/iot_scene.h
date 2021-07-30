#ifndef __IOT_SCENE_H__
#define __IOT_SCENE_H__
#include "tuya_cloud_types.h"
#include "tuya_cloud_error_code.h"
#include "tuya_iot_com_api.h"

#define SCENE_ID_MAX_LEN        20
#define SCENE_NAME_LEN          32
#define SCENE_ICON_PATH_LEN     128

typedef enum  {
    SCENE_DEV_ALL_OFFLINE = 0,              //场景下的设备全部离线
    SCENE_DEV_PART_ONLINE,                  //场景下的设备部分在线
    SCENE_DEV_ALL_ONLINE,                   //场景下的设备全部在线
}TUYA_SCENE_DEV_STAT_E;

typedef struct {
    CHAR_T id[SCENE_ID_MAX_LEN+1];
    CHAR_T name[SCENE_NAME_LEN+1];
    CHAR_T icon_path[SCENE_ICON_PATH_LEN+1];
    USHORT_T frequency;
}TUYA_SCENE_INFO_S;

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************
*  Function: tuya_scene_init
*  Desc:     scene init
*  Input:    null
*  Output:   null
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_scene_init();

/***********************************************************
*  Function: tuya_scene_sync
*  Desc:     sync scene 
*  Input:    null
*  Output:   null
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_scene_sync();

/***********************************************************
*  Function: tuya_scene_triggle
*  Desc:     triggle scene
*  Input:    id: ruleId
*  Output:   *status: devs status  SCENE_DEV_ALL_OFFLINE/SCENE_DEV_PART_ONLINE/SCENE_DEV_ALL_ONLINE
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_scene_triggle(IN CHAR_T *id, OUT TUYA_SCENE_DEV_STAT_E *status);

/***********************************************************
*  Function: tuya_scene_info_list_get
*  Desc:     get scene list 
*  Input:    pp_list: scene list pointer
*  Input:    p_cnt: scene cnt poinit
*  Return:   TUYA_SCENE_ACTION_S: scene content, use tuya_scene_info_list_free release after use
***********************************************************/
OPERATE_RET tuya_scene_info_list_get(OUT TUYA_SCENE_INFO_S **pp_list, OUT UINT_T *p_cnt);

/***********************************************************
*  Function: tuya_scene_info_list_free
*  Desc:     free scene list
*  Input:    pp_list: scene list pointer
*  Input:    cnt: scene cnt
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_scene_info_list_free(IN TUYA_SCENE_INFO_S *p_list, IN UINT_T cnt);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __IOT_SCENE_H__

