/*
tuya_iot_com_api.h
Copyright(C),2018-2020, 涂鸦科技 www.tuya.comm
*/

#ifndef __TUYA_IOT_ENGINEER_H
#define __TUYA_IOT_ENGINEER_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

VOID gw_engineer_to_normal_finish(IN CONST CHAR_T *engineer_path);
//工程模式切换到普通模式，需要判断是否施工完成，施工完成判断子设备是否全部绑定，都绑定时会把设备配置上传到云端
VOID gw_engineer_to_normal_sync();

#ifdef __cplusplus
}
#endif

#endif

