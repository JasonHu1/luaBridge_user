#ifndef __TUYA_WHITELIST_H__
#define __TUYA_WHITELIST_H__
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
    extern "C" {
#endif

/**
 * @brief 子设备名单发送回调
 * 
 * @param dev_id 子设备id
 * @param timeout 子设备白名单添加超时时间
 */
typedef VOID (*host_msg_whitelist_dev_add_cb)(CHAR_T* dev_id, UINT_T timeout);

/**
 * @brief 发送获取子设备
 */
typedef VOID (*host_msg_zigbee_net_info_cb)(VOID);

/**
 * @brief 子设备白名单入网管理初始化
 * 
 * @param dev_add 子设备名单发送回调
 * @param info_get 获取zigbee网络信息回调
 */
VOID zigbee_dev_whitelist_mgr_init(host_msg_whitelist_dev_add_cb dev_add, host_msg_zigbee_net_info_cb info_get);

/**
 * @brief 设备是否在入网白名单中
 * 
 * @param id 待查询设备id
 * @return BOOL_T TRUE:在白名单中
 */
BOOL_T is_dev_in_whitelist(CHAR_T * id);

/**
 * @brief 上报zigbeew网络信息
 * 
 * @param data 网络信息结构体
 */
OPERATE_RET zigbee_network_info_rpt(TY_NETWORK_INOF_T* data);
#ifdef __cplusplus
    }
#endif

#endif //!__TUYA_WHITELIST_H__