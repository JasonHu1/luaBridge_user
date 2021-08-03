/***********************************************************
*  File: smart_frame.h
*  Author: nzy
*  Date: 20170413
***********************************************************/
#ifndef _SMART_FRAME_ENGR_H
#define _SMART_FRAME_ENGR_H

#include "tuya_cloud_types.h"
#include "smart_frame.h"

#ifdef __cplusplus
    extern "C" {
#endif

OPERATE_RET engr_sf_subdev_register_cb(IN SF_SUBDEV_HANDLE_CB_S *subdev_cbs);
/* 接收并处理来自mqtt，tcp，本地定时的消息 */
OPERATE_RET engr_sf_send_gw_dev_cmd(IN SF_GW_DEV_CMD_S *gd_cmd);

#ifdef __cplusplus
}
#endif
#endif

