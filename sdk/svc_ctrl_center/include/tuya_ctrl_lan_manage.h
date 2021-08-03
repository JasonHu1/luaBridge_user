/**
 * @file tuya_ctrl_lan_manage.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 中控局域网控制模块
 * @version 0.1
 * @date 2021-06-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_CTRL_LAN_MANAGE__
#define __TUYA_CTRL_LAN_MANAGE__

#include "tuya_cloud_types.h"
#include "tuya_error_code.h"

#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 判断设备是否是局域网在线
 * 
 * @param dev_id 设备（包括网关、子设备、wifi单品设备）的虚拟ID
 * @return BOOL_T 设备是否局域网在线
 * @retval true 设备局域网在线且建立了TCP连接
 * @retval false 设备没有建立TCP连接
 */
BOOL_T tuya_ctrl_is_dev_lan_online(IN CONST CHAR_T *dev_id);

/**
 * @brief 往局域网模块注册需要监控的设备
 * 
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_ctrl_lan_watch_set();

/**
 * @brief 查询网关或网关下的子设备或者WIFI单品的全部dp值
 * 
 * @param dev_id 设备（包括网关、子设备、wifi单品设备）的虚拟ID
 * @return OPERATE_RET 错误码
 * @note 该操作是去实际设备上查询，是个异步的操作, 查询成功后回调 @ref LAN_CTRL_DEV_DP_QUERY_CB
 * @warning 该接口适合大量的子设备查询的情况，内部处理会有几秒的延时和针对大量数据优化机制，不适合针对单个子设备的快速查询
 */
OPERATE_RET tuya_ctrl_lan_dev_dp_query(IN CONST CHAR_T *dev_id);

/**
 * @brief 执行标准场景
 * 
 * @param gw_dev_id 网关或wifi单品的虚拟ID
 * @param grp_id 标准场景的gid
 * @param sce_id 标准场景中的sid
 * @return OPERATE_RET 
 */
OPERATE_RET tuya_ctrl_lan_dev_scene_exce(IN CONST CHAR_T *gw_dev_id, IN CONST CHAR_T *grp_id, IN CONST CHAR_T *sce_id);

/**
 * @brief 中控局域网模块初始化
 * 
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_ctrl_lan_dev_init();

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __TUYA_CTRL_LAN_MANAGE__