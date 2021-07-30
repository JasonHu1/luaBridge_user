/**
 * @file base_event.h
 * @brief tuya simple event module
 * @version 1.0
 * @date 2021-7-16
 * 
 * @copyright Copyright (c) tuya.inc 2021
 * 
 */
#ifndef __SDK_DISTRIBUTOR_INTERNAL_API_H__
#define __SDK_DISTRIBUTOR_INTERNAL_API_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#include "tuya_iot_sdk_defs.h"

#if defined(ENABLE_SUBDEVICE) && (ENABLE_SUBDEVICE==1)
#include "tuya_gw_com_defs.h"
#endif

/**
 * @brief DP management 
 * 
 */
typedef struct {
    TY_IOT_DP_CBS_S    cbs; 
    DP_DEV_TYPE_T      sub_dev_type;
    GW_PERMIT_DEV_TP_T tp;
} TY_IOT_MGR_S;

/**
 * @brief DP CNTL
 * 
 */
typedef struct  {
    TY_IOT_MGR_S *iot_mgr;
    UINT_T        reg_cnt;
} TY_IOT_DP_CNTL_S;

#if defined(ENABLE_SUBDEVICE) && (ENABLE_SUBDEVICE==1)
typedef struct {
    TY_IOT_DEV_CBS_S     cbs;
    GW_PERMIT_DEV_TP_T   tp;
} TY_IOT_GW_MGR_S;

typedef struct {
    TY_IOT_GW_MGR_S   *gw_mgr;
    UINT_T             reg_cnt;
} TY_IOT_GW_MGR_CNTL_S;

TY_IOT_GW_MGR_CNTL_S* tuya_iot_gw_mgr_cntl_get(VOID);
#endif

TY_IOT_DP_CNTL_S* tuya_iot_dp_cntl_get(VOID);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __SDK_DISTRIBUTOR_INTERNAL_API_H__ */
