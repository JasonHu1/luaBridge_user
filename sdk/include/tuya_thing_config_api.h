/**
 * @file    tuya_thing_config_api.h
 * @brief   This file contains send broadcast packet interface
 * @version 0.1
 * 
 * @copyright Copyright 2021 Tuya Inc. www.tuya.com
 */
#ifndef __TUYA_THING_CONFIG_API_H__
#define __TUYA_THING_CONFIG_API_H__

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef OPERATE_RET (*TY_THING_CONFIG_GET_INFO_CB)(CHAR_T *ssid, UINT_T ssid_size, CHAR_T *key, UINT_T key_size);

/**
 * @brief    initiate thing config.
 *
 * @param[in] ifname  WiFi interface name.
 * @param[in] cb      get ssid and passwd callback.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_thing_config_init(CONST CHAR_T *ifname, CONST TY_THING_CONFIG_GET_INFO_CB cb);

/**
 * @brief    start thing config.
 *
 * @param[in] timeout  timeout to stop smart config.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_thing_config_start(UINT_T timeout);

/**
 * @brief    stop thing config.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_thing_config_stop(VOID);

#ifdef __cplusplus
}
#endif

#endif  /* __TUYA_THING_CONFIG_API_H__ */