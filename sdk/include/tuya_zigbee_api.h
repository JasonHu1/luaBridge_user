/**
 * @file    tuya_zigbee_api.h
 * @brief   This file contains ZigBee wireless protocol interface
 * @version 0.1
 * 
 * @copyright Copyright (c) tuya.inc 2019
 */
#ifndef __TUYA_ZIGBEE_API_H__
#define __TUYA_ZIGBEE_API_H__

#include "ty_cJSON.h"
#include "tuya_zigbee_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef VOID (*TY_Z3_PERMIT_JOIN_CB)(BOOL_T permit, UINT_T timeout);
typedef VOID (*TY_Z3_NCP_UPGRADE_STATUS_CB)(BOOL_T status);

/**
 * @brief    initialize ZigBee service.
 * 
 * @param[in] cfg  service configuration.
 *                 {
 *                     "storage_path": "./",       // persistent storage path
 *                     "cache_path": "/tmp/",      // cache path, use to save ota firmware
 *                     "dev_name": "/dev/ttyUSB0", // serial port
 *                     "cts": 0,                   // is support hardware flow control
 *                     "thread_mode": 1,           // user pthread or fork to start service
 *                     "sw_ver": "1.0.8"           // NCP version
 *                 }
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_zigbee_svc_init(ty_cJSON *cfg);

/**
 * @brief    start ZigBee service.
 * 
 * @param[in] cfg  service configuration.
 *                 {
 *                     "storage_path": "./",       // persistent storage path
 *                     "cache_path": "/tmp/",      // cache path, use to save ota firmware
 *                     "dev_name": "/dev/ttyUSB0", // serial port
 *                     "cts": 0,                   // is support hardware flow control
 *                     "thread_mode": 1,           // user pthread or fork to start service
 *                     "sw_ver": "1.0.8"           // NCP version
 *                 }
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_zigbee_svc_start(ty_cJSON *cfg);

/**
 * @brief    register ZigBee permit join callback.
 *
 * @param[in] cb. callback function.
 *
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_zigbee_reg_permit_join_cb(TY_Z3_PERMIT_JOIN_CB cb);

/**
 * @brief    initialize 3rd-party ZigBee device manager. SDK will ignore the list of device,
 *           those devices should be developed by developer.
 * 
 * @param[in] devlist  a set of device contains its information.
 *                     devlist == NULL, mean filter all device.
 * @param[in] cbs      register callback function.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_zigbee_custom_dev_mgr_init(TY_Z3_DEVLIST_S *devlist, TY_Z3_DEV_CBS_S *cbs);

/**
 * @brief    send a ZCL frame to ZigBee device.
 *
 * @param[in] frame  ZCL message header and payload.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_zigbee_send_data(TY_Z3_APS_FRAME_S *frame);

/**
 * @brief    delete a device from ZigBee network.
 *
 * @param[in] id  unique ID for device.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_zigbee_del_dev(CONST CHAR_T *dev_id);

/**
 * @brief    upgrade a device.
 *
 * @param[in] id  unique ID for device.
 * @param[in] fw  firmware info.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_zigbee_upgrade_dev(CONST CHAR_T *dev_id, CONST FW_UG_S *fw);

/**
 * @brief    upgrade NCP firmware.
 *
 * @param[in] fw_file  firmware file path.
 * @param[in] cb       upgrade result callback.
 *
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_zigbee_upgrade_ncp(CONST CHAR_T *fw_file, TY_Z3_NCP_UPGRADE_STATUS_CB cb);

/**
 * @brief    set NCP MAC address.
 *
 * @param[in] mac  new MAC address.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_zigbee_set_ncp_mac(CONST CHAR_T *mac);

 /**
  * @brief    reset NCP to factory settings.
  *
  * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
  */
OPERATE_RET tuya_zigbee_reset_ncp(VOID);

/**
 * @brief    get NCP software version.
 *
 * @param[out] ver  version buffer.
 *
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_zigbee_get_ncp_ver(CHAR_T *ver);

/**
 * @brief    rf test for coordinator.
 * 
 * @param[in] cb       callback function.
 * @param[in] channel  select a channel to send packet.
 * @param[in] power    set coordinator tx power.
 * @param[in] msg_len  length of payload.
 * @param[in] msg      payload.
 *                     if use Tuya ZigBee dongle for testing, msg must be:
 *                     {0x55, 0xaa, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39}
 * @param[in] npacket  number of packet.
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tuya_zigbee_rftest(TY_Z3_RFTEST_RESULT_CB cb, UCHAR_T channel, CHAR_T power, \
                               UCHAR_T msg_len, UCHAR_T *msg, USHORT_T npacket);

#ifdef __cplusplus
}
#endif
#endif