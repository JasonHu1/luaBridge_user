/**
 * @file tuya_home_control_init.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 初始化中控SDK
 * @version 0.1
 * @date 2021-03-02
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CONTROL_INIT__
#define __TUYA_HOME_CONTROL_INIT__

/**
 * @addtogroup product_type_unity linux中控SDK统一接口
 * @{
 */

#include "tuya_cloud_types.h"
#include "tuya_ctrl_center.h"
#include "tuya_error_code.h"

#pragma pack(1)

/**
 * @brief 收到dev或room同步完成后的事件处理
 *
 * @param data 同步事件传递过来的数据
 * @return int 错误码
 */
typedef INT_T (*TUYA_HOME_CONTROL_ALL_INFO_SYNC_CB)(TY_INFO_SYNC_TP_E *);

// 从云端拉取图片尺寸，单位为像素，width和height全都不为0才表示需要配置
typedef struct {
    INT_T width;    // 宽度
    INT_T height;   // 高度
} tuya_img_size_s;

// 初始化中控传入配置参数，结构体内部申请的内存需要用户自己释放
typedef struct
{
    CHAR_T *db_path;            // 数据库地址
    tuya_img_size_s img_size;   // 从云端拉取图片尺寸
} tuya_home_init_cfg_s;

// 初始化中控传入回调函数
typedef struct {
    TUYA_HOME_CONTROL_ALL_INFO_SYNC_CB all_info_sync_cb; // 同步的回调函数
} tuya_home_init_cbs_s;

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 初始化中控SDK
 * 
 * @param db_path 数据库地址
 * @param all_info_sync_cb 同步的回调函数
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_home_init(IN CHAR_T *db_path, IN TUYA_HOME_CONTROL_ALL_INFO_SYNC_CB all_info_sync_cb);

/**
 * @brief 初始化中控SDK，需传入配置信息和相关回调函数
 * 
 * @param cfg 初始化配置参数
 * @param cbs 相关回调函数
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_home_init_ex(IN tuya_home_init_cfg_s cfg, IN tuya_home_init_cbs_s cbs);

#ifdef __cplusplus
}  // extern "C"
#endif

/** @} */  // end for gourp product_type_unity

#endif  // __TUYA_HOME_CONTROL_INIT__