/**
 * @file    tuya_gw_z3_user.h
 * 
 * @copyright Copyright 2021 Tuya Inc. www.tuya.com
 */
#ifndef TUYA_GW_Z3_USER_H
#define TUYA_GW_Z3_USER_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#include "tuya_zigbee_defs.h"
#include "tuya_z3_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  load user device to memory from db.
 *
 * @retval  0: success
 * @retval !0: failure
 */
OPERATE_RET tuya_z3_user_dev_load(VOID);

/**
 * @brief    register 3rd-party ZigBee device management. It will ignore the list of device,
 *           those devices should be developed by developer.
 * 
 * @param[in] devlist. a set of device contains its information.
 * @param[in] cbs.     register callback function.
 * 
 * @retval   0: success
 * @retval  !0: failure
 */
OPERATE_RET tuya_z3_user_dev_register(TY_Z3_DEVLIST_S *devlist, TY_Z3_DEV_CBS_S *cbs);

/**
 * @brief  check if a device is user device.
 *
 * @param[in] dev_id. device unique ID.
 *
 * @retval TRUE.  found
 * @retval FALSE. not found
 */
BOOL_T tuya_z3_user_dev_find(CONST CHAR_T *dev_id);

/**
 * @brief  check if a device is match user predefined device.
 *
 * @param[in] dev_id. device unique ID.
 *
 * @retval TRUE.  matched
 * @retval FALSE. not match
 */
BOOL_T tuya_z3_user_dev_match(CONST CHAR_T *manu_name, CONST CHAR_T *model_id);

/**
 * @brief  check if user's device list is empty or not.
 *
 * @retval TRUE.  empty
 * @retval FALSE. not empty
 */
BOOL_T tuya_z3_user_dev_empty(VOID);

/**
 * @brief  add a device to user's device list.
 *
 * @param[in] dev_id. device unique ID.
 *
 * @retval  0: success
 * @retval !0: failure
 */
OPERATE_RET tuya_z3_user_dev_add(CONST CHAR_T *dev_id);

/**
 * @brief  delete a device from user's device list.
 *
 * @param[in] dev_id. device unique ID.
 *
 * @retval  0: success
 * @retval !0: failure
 */
OPERATE_RET tuya_z3_user_dev_del(CONST CHAR_T *dev_id);

/**
 * @brief  clear user's device list.
 *
 * @retval  0: success
 * @retval !0: failure
 */
OPERATE_RET tuya_z3_user_dev_del_all(VOID);

/**
 * @brief  user device joined.
 *
 * @param[in] dev. device information.
 * 
 * @retval  0: success
 * @retval !0: failure
 */
OPERATE_RET tuya_z3_user_dev_join(CONST DEV_Z3_DESC_IF_S *dev);

/**
 * @brief  user device left.
 *
 * @param[in] dev_id. device unique ID.
 * 
 * @retval  0: success
 * @retval !0: failure
 */
OPERATE_RET tuya_z3_user_dev_leave(CONST CHAR_T *dev_id);

/**
 * @brief  user device report data.
 *
 * @param[in] frame. zcl frame.
 * 
 * @retval  0: success
 * @retval !0: failure
 */
OPERATE_RET tuya_z3_user_dev_report(CONST TuYaApsFrame *frame);

/**
 * @brief  zigbee host had been started, send a notification to user.
 *
 * @retval  0: success
 * @retval !0: failure
 */
OPERATE_RET tuya_z3_user_dev_notify(VOID);

/**
 * @brief  user device upgrade complete.
 *
 * @param[in] dev_id.  device unique ID.
 * @param[in] rc.      upgrade result.
 * @param[in] version. new version.
 * 
 * @retval  0: success
 * @retval !0: failure
 */
OPERATE_RET tuya_z3_user_dev_upgrade_end(CONST CHAR_T *dev_id, INT_T rc, UCHAR_T version);

#ifdef __cplusplus
}
#endif
#endif