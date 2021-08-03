#ifndef __COMPONENT_TUYA_USER_MQAPP_H__
#define __COMPONENT_TUYA_USER_MQAPP_H__

#include "tuya_cloud_types.h"

typedef VOID (*TY_ROOM_INFO_UPDATE_CB)(VOID);

typedef struct {
    TY_ROOM_INFO_UPDATE_CB  room_info_update_cb;    
}TUYA_USER_CBS_S;

#ifdef __cplusplus
extern "C" {
#endif

OPERATE_RET tuya_user_mqc_init(IN CONST TUYA_USER_CBS_S * p_user_cbs);


#ifdef __cplusplus
} // extern "C"
#endif

#endif // __COMPONENT_TUYA_USER_MQAPP_H__
