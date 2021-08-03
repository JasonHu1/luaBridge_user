/**
 * @file lpc_con_core.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 局域网协议客户端连接模块核心
 * @version 0.1
 * @date 2021-05-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __LPC_CON_CORE__
#define __LPC_CON_CORE__

#include "lpc_con_db.h"
#include "tuya_cloud_types.h"
#include "tuya_error_code.h"

#define LPC_CON_TASK_SLEEP_TIME (3 * 1000) ///<任务等待时间

#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 局域网连接初始化
 * 
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_client_connet_init();

/**
 * @brief 增加连接节点
 * 
 * @param id 设备虚拟ID
 * @param user_cbs 回调函数
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_client_connet_add_peer_node(IN CONST CHAR_T *id, LPC_CON_NODE_USER_INFO_S *user_cbs);

/**
 * @brief 删除指定设备ID的连接的节点
 * 
 * @param id 设备虚拟ID
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_client_connet_del_peer_node(IN CONST CHAR_T *id);

/**
 * @brief 删除所有连接的节点
 * 
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_client_connet_del_all_peer_node();

/**
 * @brief 指定的设备ID的连接节点是否存在
 * 
 * @param id 设备虚拟ID
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_client_connet_is_peer_node_valid(IN CONST CHAR_T *id);
#ifdef __cplusplus
} // extern "C"
#endif

#endif // __LPC_CON_CORE__