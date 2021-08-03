/**
 * @file tuya_iot_sdk_api_engr.h
 * @brief sdk api for engineer mode
 * @version 1.0
 * @date 2021-7-16
 * 
 * @copyright Copyright (c) tuya.inc 2021
 * 
 */
#ifndef __TUYA_IOT_SDK_API_ENGR__
#define __TUYA_IOT_SDK_API_ENGR__


#ifdef __cplusplus
extern "C" {
#endif
#include "tuya_cloud_types.h"
#include "tuya_iot_config.h"

#if defined(ENABLE_ENGINEER_TO_NORMAL) && (ENABLE_ENGINEER_TO_NORMAL==1)

#include "tuya_gw_engr_com_api.h"
#include "tuya_gw_engineer_api.h"

/**
 * @brief user register callback funcitons
 * 
 */
typedef struct {
    GW_GET_LOG_CB engineer_get_log;
    GW_SYNC_CONFIG_CB engineer_sync_config;
    GW_ENG_FIN_CB engineer_finish;
    GW_ENG_RESET_CB engineer_reset;
    ENGR_MODE_CHANGE_CB engineer_mode_change;
} TY_GW_INFRA_ENGR_CBS_S;

/** 
 * @brief: engineer SDK init
 *
 * @param[in] product_key: product id
 * @param[in] eng_cbs: callbacks, see TY_GW_INFRA_ENGR_CBS_S
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_engineer_sdk_init(IN CONST CHAR_T *product_key, TY_GW_INFRA_ENGR_CBS_S *eng_cbs);
#endif
#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif
