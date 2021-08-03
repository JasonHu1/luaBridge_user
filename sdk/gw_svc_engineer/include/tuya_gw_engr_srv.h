/**
 * @file tuya_gw_engr_srv.h
 * @author zhangyu
 * @brief 工程模式切换
 * 
 * @date 2021-03-11
 * @copyright Copyright (c) tuya.inc 2021
 */


#ifndef __TUYA_GW_ENGR_SRV_H__
#define __TUYA_GW_ENGR_SRV_H__

#include "tuya_cloud_types.h"
#include "tuya_gw_engr_com_api.h"
#ifdef __cplusplus
extern "C" {
#endif

VOID tuya_gw_engineer_enter_notify(VOID);
OPERATE_RET tuya_gw_engineer_switch_service_init(ENGR_MODE_CHANGE_CB cb);

#ifdef __cplusplus
}
#endif

#endif //__TUYA_GW_ENGR_SRV_H__