/**
 * @file tuya_bluetooth_mgr.h
 * @brief 蓝牙应用对外接口
 * 
 * @copyright Copyright (c) tuya.inc 2021
 */

#ifndef __TUYA_BLUETOOTH_MGR_H__
#define __TUYA_BLUETOOTH_MGR_H__

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#include "tuya_gw_bt_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  蓝牙服务初始化接口
 * 
 * @param[in] config  蓝牙配置参数
 * @param[in] mode    设置蓝牙模式
 * 
 * @retval  0: 成功
 * @retval !0: 失败
 */
OPERATE_RET tuya_bluetooth_srv_init(TUYA_GW_BT_CONFIG_S *config, TUYA_BT_HAL_WORK_MODE_E mode);

/**
 * @brief  获取蓝牙NCP版本号接口
 * 
 * @param[out] ver    NCP版本号
 * 
 * @retval  0: 成功
 * @retval !0: 失败
 */
OPERATE_RET tuya_bluetooth_srv_ver_get(CHAR_T *ver);

#ifdef __cplusplus
}
#endif
#endif