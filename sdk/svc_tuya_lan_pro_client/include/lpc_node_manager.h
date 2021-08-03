/**
 * @file lpc_node_manager.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 局域网协议客户端模块节点管理
 * @version 0.1
 * @date 2021-05-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __LPC_NODE_MANAGER__
#define __LPC_NODE_MANAGER__

#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_types.h"
#include "tuya_error_code.h"

#define LPC_NODE_TIMEOUT 20  ///< 节点超时时间为20秒（UDP广播时间是5秒一次，20秒相当于连续四次没有收到包）

///master感知到的单个节点的状态变化
typedef BYTE_T TUYA_LAN_DEV_CHANGE_ST_T;
#define TUYA_LAN_DEV_JOIN 0    // 节点新增
#define TUYA_LAN_DEV_LEAVE 1   // 节点删除
#define TUYA_LAN_DEV_CON 2     // 节点连接成功
#define TUYA_LAN_DEV_DISCON 3  // 节点连接断开

// 节点状态变化后的回调函数
typedef VOID (*LAN_DEV_ST_CHANGE_CB)(IN TUYA_LAN_DEV_CHANGE_ST_T st, IN CONST CHAR_T *virt_id);

#pragma pack(1)
///局域网涂鸦设备信息，后续按需扩展字段
typedef struct
{
    CHAR_T id[GW_ID_LEN + 1];  // virtual id
    TUYA_LAN_DEV_CHANGE_ST_T st;
} TUYA_LAN_PRO_DEV_INFO_S;

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 初始化
 * 
 * @return OPERATE_RET 错误码
 */
OPERATE_RET lpc_node_manager_init();

/**
 * @brief 接收到udp发现广播时的处理函数，实现发现（不支持的版本或者设备在列表中过滤掉）和保活（保活超时时间20秒）。这里仅仅是维护节点列表，默认不建立tcp连接
 * 
 * @param ip IP地址
 * @param recv_data 收到的报文
 * @param recv_data_len 收到的报文长度
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_on_discover_msg(IN UINT_T ip, IN CONST BYTE_T *recv_data, UINT_T recv_data_len);


OPERATE_RET tuya_lan_pro_reg_dev_st_change_cb(IN LAN_DEV_ST_CHANGE_CB cb);


/**
 * @brief 节点保活定时器
 * 
 * @return VOID 
 */
VOID tuya_lan_pro_client_timeout_check();

/**
 * @brief 查询局域网中的节点全量列表
 * 
 * @param lan_dev_list 设备列表
 * @param dev_num 设备列表数量
 * @return OPERATE_RET 
 * @note 调用者使用完lan_dev_list后，需要调用 @ref tuya_lan_pro_dev_list_free 释放
 */
OPERATE_RET tuya_lan_pro_dev_list_get(OUT TUYA_LAN_PRO_DEV_INFO_S **lan_dev_list, OUT UINT_T *dev_num);

/**
 * @brief 释放 @ref tuya_lan_pro_dev_list_get获取的设备列表
 * 
 * @param lan_dev_list 设备列表
 * @return VOID
 */
VOID tuya_lan_pro_dev_list_free(IN TUYA_LAN_PRO_DEV_INFO_S *lan_dev_list);

/**
 * @brief 根据节点虚拟id查询节点信息
 * 
 * @param virt_id 节点虚拟ID
 * @param dev_info 查到的节点状态
 * @return OPERATE_RET 错误码
 * @retval OPRT_OK 查询到了指定的节点虚拟ID
 * @retval 其他 没有查询到指定的节点虚拟ID
 */
OPERATE_RET tuya_lan_pro_dev_list_find(IN CONST CHAR_T *virt_id, OUT TUYA_LAN_PRO_DEV_INFO_S *dev_info);
#ifdef __cplusplus
} // extern "C"
#endif

#endif // __LPC_NODE_MANAGER__