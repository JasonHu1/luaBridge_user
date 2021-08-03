/**
 * @file lpc_node_connect.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 节点连接部分
 * @version 0.1
 * @date 2021-05-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __LPC_NODE_CONNECT__
#define __LPC_NODE_CONNECT__

#include "tuya_cloud_types.h"
#include "tuya_error_code.h"

#pragma pack(1)

/// 网关或wifi单品的属性
typedef struct
{
    CHAR_T *localkey;     ///< 用于局域网加密算法
    CHAR_T *cad_version;  ///< 用于判断网关或wifi单品的局域网协议是老协议还是新协议
} TUYA_LAN_PRO_DEV_ATTR_S;

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 设置某个节点的local key
 * 
 * @param virt_id 设备虚拟ID
 * @param localkey 设备的localkey
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_localkey_set(IN CONST CHAR_T *virt_id, IN CONST CHAR_T *localkey);


/**
 * @brief 设置某个节点的local key
 * 
 * @param virt_id 网关或wifi单品的虚拟ID
 * @param attr 设备的属性
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_attr_set(IN CONST CHAR_T *virt_id, IN CONST TUYA_LAN_PRO_DEV_ATTR_S *attr);

/**
 * @brief 设置指定节点是否需要连接
 * 
 * @param virt_id 设备虚拟ID
 * @param need_connect 是否需要连接
 * @return OPERATE_RET 错误码
 * @note 如果上层判断需要连接时，先获取到localkey,调用 @ref tuya_lan_pro_localkey_set 设置下来，再调用这个接口; 如果上层判断不需要连接时，need_connect 置位false
 */
OPERATE_RET tuya_lan_pro_connect_set(IN CONST CHAR_T *virt_id, IN BOOL_T need_connect);

/**
 * @brief 断开所有连接, 但是维护节点的列表 不变
 * 
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_disconnect_all();
#ifdef __cplusplus
} // extern "C"
#endif

#endif // __LPC_NODE_CONNECT__