/**
 * @file tuya_zigbee_mgr.h
 * @author zhangyu
 * @brief zigbee应用对外接口
 * 
 * @date 2021-03-16
 * @copyright Copyright (c) tuya.inc 2021
 */

#ifndef __TUYA_ZIGBIE_MGR_H__
#define __TUYA_ZIGBIE_MGR_H__

#include "tuya_cloud_types.h"

#ifdef __cplusplus
	extern "C" {
#endif

/**
 * @brief zigbee网关初始化
 * 
 * @param storage_dir zigbee数据存储目录
 * @param multipro TRUE: 多进程启动; FALSE: 多线程启动
 */
OPERATE_RET tuya_zigbee_srv_init(IN CONST CHAR_T *storage_dir, BOOL_T multipro);

/**
 * @brief zigbee版本号获取
 * 
 * @param ver 
 * @return OPERATE_RET 
 */
OPERATE_RET tuya_zigbee_srv_ver_get(CHAR_T *ver);
OPERATE_RET tuya_zigbee_srv_set_ncp_mac_writable(CHAR_T *cur_ver, CHAR_T *valid_ver);
BOOL_T tuya_zigbee_srv_get_ncp_mac_writable(VOID);

#ifdef __cplusplus
}
#endif

#endif