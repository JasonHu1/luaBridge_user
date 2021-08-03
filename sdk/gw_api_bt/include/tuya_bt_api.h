/**
 * @file    tuya_bt_api.h
 * @brief   This file contains Bluetooth wireless protocol interface
 * @version 0.1
 * 
 * @copyright Copyright (c) tuya.inc 2019
 */
#ifndef __TUYA_BT_API_H__
#define __TUYA_BT_API_H__

#include "ty_cJSON.h"
#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    MESH_ADV    = 0x01,
    MESH_GATT   = 0x02,
    BLE_MASTER  = 0x04,
    BLE_SLAVE   = 0x08
} BT_WORK_MODE_E;

/**
 * @brief    initialize Bluetooth service.
 * 
 * @param[in] cfg  service configuration.
 *                 {
 *                     "enable_hb": 1,             // enable hearbeat query
 *                     "scan_timeout": 60,         // scan timeout, unit: second
 *                     "mode": 5,                  // OR bit operation in `BT_WORK_MODE_E`
 *                     "sw_ver": "1.0.8"           // NCP version
 *                 }
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_bt_svc_init(IN ty_cJSON *cfg);

/**
 * @brief    start Bluetooth service.
 * 
 * @param[in] cfg  service configuration.
 *                 {
 *                     "enable_hb": 1,             // enable hearbeat query
 *                     "scan_timeout": 60,         // scan timeout, unit: second
 *                     "mode": 5,                  // OR bit operation in `BT_WORK_MODE_E`
 *                     "sw_ver": "1.0.8"           // NCP version
 *                 }
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_bt_svc_start(IN ty_cJSON *cfg);

/**
 * @brief    get Bluetooth NCP version.
 * 
 * @param[out] ver  NCP version.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_bt_get_ncp_ver(CHAR_T *ver);

/**
 * @brief    initialize Bluetooth host.
 * 
 * @param[in] port  serial port.
 * 
 * @return none
 */
VOID tuya_bt_host_init(CONST CHAR_T *port);

/**
 * @brief    get rssi.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_bt_host_get_rssi(VOID);

/**
 * @brief    send data.
 * 
 * @param[in] type  type.
 * @param[in] mac   mac.
 * @param[in] data  data.
 * @param[in] len   len of data.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_bt_host_send_data(INT_T type, UCHAR_T *mac, BYTE_T *data, UINT_T len);

/**
 * @brief    send data.
 * 
 * @param[in] adv_len    len of advertise data.
 * @param[in] adv_data   advertise data.
 * @param[in] scan_len   len of scan response data.
 * @param[in] scan_data  scan response data.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_bt_host_adv_reset(UINT_T adv_len, BYTE_T *adv_data, UINT_T scan_len, BYTE_T *scan_data);

/**
 * @brief    start advertise.
 *
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_bt_host_adv_start(VOID);

/**
 * @brief    stop advertise.
 *
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_bt_host_adv_stop(VOID);

#ifdef __cplusplus
}
#endif
#endif