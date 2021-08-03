/**
 * @file lpc_cmd.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 局域网协议客户端协议命令部分
 * @version 0.1
 * @date 2021-05-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __LPC_CMD__
#define __LPC_CMD__

#include "tuya_cloud_types.h"
#include "tuya_error_code.h"

/**
 * @brief 节点dp查询成功后的回调(如果查询时的cid_list有多个，会回调多次)
 * @param dev_virt_id 网关或WIFI单品的虚拟id
 * @param dp_value 某个子设备或WIFI单品的全部dp值的内容，json格式 @remark 如 {"dps":{"4":false,"25":false,"32":"normal"},"cid":"000d6ffffe6d7100"}
 */
typedef VOID (*LAN_DEV_DP_QUERY_CB)(IN CONST CHAR_T *dev_virt_id, IN CONST CHAR_T *dp_value);

/**
 * @brief 节点dp上报通知回调
 * @param dev_virt_id 网关或WIFI单品的虚拟id
 * @param dp_value 上报的dp值的内容，json格式 @remark 如{"cid":"000d6ffffe6d7100","dps":{"1":true,"2":false}}
 * 
 */
typedef VOID (*LAN_DEV_DPUP_CB)(IN CONST CHAR_T *dev_virt_id, IN CONST CHAR_T *dp_value);
#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 查询某个子设备或者WIFI单品的全部dp值
 * 
 * @param dev_virt_id 网关或WIFI单品的虚拟id
 * @param cid WIFI单品为NULL，网关的子设备node_id
 * @return OPERATE_RET 错误码
 * @note 该操作是去实际设备上查询，是个异步的操作, 查询成功后回调 @ref LAN_DEV_DP_QUERY_CB
 */
OPERATE_RET tuya_lan_pro_dev_dp_query(IN CONST CHAR_T *dev_virt_id, IN CONST CHAR_T *cid);

/**
 * @brief 注册主动节点dp查询回调
 * 
 * @param cb 节点dp查询成功后的回调函数后
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_reg_dev_dp_query_cb(IN LAN_DEV_DP_QUERY_CB cb);

/**
 * @brief 注册节点dp上报通知回调
 * 
 * @param cb 节点dp上报通知回调函数
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_reg_dev_dpup_cb(IN LAN_DEV_DPUP_CB cb);

/**
 * @brief 下发dp
 * 
 * @param dev_virt_id 网关或WIFI单品的虚拟id
 * @param dp_value 
 * @return OPERATE_RET 某个子设备或WIFI单品的全部dp值的内容，json格式 @remark 如 {"dps":{"4":false,"25":false,"32":"normal"},"cid":"000d6ffffe6d7100"}
 */
OPERATE_RET tuya_lan_pro_dev_dp_send(IN CONST CHAR_T *dev_virt_id, IN CONST CHAR_T *dp_value);

/**
 * @brief 局域网场景执行
 * 
 * @param dev_virt_id 网关或WIFI单品的虚拟id
 * @param grp_id 设备组ID
 * @param sce_id 场景ID
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_dev_scene_exce(IN CONST CHAR_T *dev_virt_id, IN CONST CHAR_T *grp_id, IN CONST CHAR_T *sce_id);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __LPC_CMD__