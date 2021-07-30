/**
 * @file tuya_home_ctrl_dev.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 中控SDK设备相关
 * @version 0.1
 * @date 2021-03-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CTRL_DEV__
#define __TUYA_HOME_CTRL_DEV__

/**
 * @defgroup product_type_unity linux中控SDK统一接口
 * @{
 */

#include "tuya_cloud_types.h"
#include "tuya_ctrl_center.h"
#include "tuya_home_ctrl_base.h"
#include "tuya_home_ctrl_light.h"

/**
 * @name 品类
 * @{
 */
#define TY_HOME_CTRL_CATEGORY_LIGHT "dj"         ///< 灯具
#define TY_HOME_CTRL_CATEGORY_SWITCH "kg"        ///< 开关
#define TY_HOME_CTRL_CATEGORY_SOCKET "cz"        ///< 插座
#define TY_HOME_CTRL_CATEGORY_CURTAIN "cl"       ///< 窗帘
#define TY_HOME_CTRL_CATEGORY_AC "kt"            ///< 空调
#define TY_HOME_CTRL_CATEGORY_FRESH_AIR "xfj"    ///< 新风机
#define TY_HOME_CTRL_CATEGORY_TEMP_CTRL "wk"     ///< 温控器
#define TY_HOME_CTRL_CATEGORY_AIR_PURIFIER "kj"  ///< 空气净化器
#define TY_HOME_CTRL_CATEGORY_AIRER "lyj"        ///< 晾衣架
#define TY_HOME_CTRL_CATEGORY_SOCKETS "pc"       ///< 排插

#define TY_HOME_CTRL_CATEGORY_PIR_SENSOR "pir"                         ///< pir传感器
#define TY_HOME_CTRL_CATEGORY_DOOR_SENSOR "mcs"                        ///< 门磁传感器
#define TY_HOME_CTRL_CATEGORY_WATER_SENSOR "sj"                        ///< 水浸传感器
#define TY_HOME_CTRL_CATEGORY_TEMPERATURE_AND_HUMIDITY_SENSOR "wsdcg"  ///< 温湿度传感器
#define TY_HOME_CTRL_CATEGORY_GAS_ALARM_SENSOR "rqbj"                  ///< 燃气报警传感器
#define TY_HOME_CTRL_CATEGORY_SOS_SENSOR "sos"                         ///< sos传感器

/** @} */

#pragma pack(1)
typedef INT_T *TY_HOME_CTRL_DEV_T;  ///< 设备描述符

/// 设备的简要信息
typedef struct
{
    CHAR_T id[DEV_ID_LEN + 1];             ///< 设备ID
    CHAR_T name[TY_DEV_NAME_LEN + 1];      ///< 设备名称
    CHAR_T category[TY_CATEGORY_LEN + 1];  ///< 品类
    BOOL_T online_stat;                    ///< 在线状态
} TY_HOME_CTRL_DEV_BRIEF_S;

/**
 * @brief 设备上报状态的回调函数
 * 
 * @note 可以回传用户数据，方便定位是哪个设备回调
 */
typedef VOID (*TY_HOME_CTRL_DEV_REPORT_FUNC)(IN CONST TY_HOME_CTRL_DEV_DP_S *dp, IN VOID *user_arg);

/**
 * @brief 设备上下线状态改变的回调函数
 * 
 * @note 可以回传用户数据，方便定位是哪个设备回调
 */
typedef VOID (*TY_HOME_CTRL_DEV_ONLINE_FUNC)(IN CONST TUYA_EVENT_DEV_ONLINE_S *data, IN VOID *user_arg);

/**
 * @brief 设备DP名称改变的回调函数
 * 
 * @note 可以回传用户数据，方便定位是哪个设备回调
 */
typedef VOID (*TY_HOME_CTRL_DP_NAME_UPDATE_FUNC)(IN CONST TUYA_EVENT_DP_NAME_S *data, IN VOID *user_arg);

/// 设备上报状态的回调接口
typedef struct
{
    TY_HOME_CTRL_DEV_REPORT_FUNC function;  ///< 回调函数
    VOID *user_arg;  ///< 用户数据，用户自定义，可以为存储数据的地址，设备ID的地址，或者NULL等
} TY_HOME_CTRL_DEV_REPORT_CB;

/// 设备上下线状态改变的回调接口
typedef struct
{
    TY_HOME_CTRL_DEV_ONLINE_FUNC function;  ///< 回调函数
    VOID *user_arg;  ///< 用户数据，用户自定义，可以为存储数据的地址，设备ID的地址，或者NULL等
} TY_HOME_CTRL_DEV_ONLINE_CB;

/// 设备DP名称改变的回调接口
typedef struct
{
    TY_HOME_CTRL_DP_NAME_UPDATE_FUNC function;  ///< 回调函数
    VOID *user_arg;  ///< 用户数据，用户自定义，可以为存储数据的地址，设备ID的地址，或者NULL等
} TY_HOME_CTRL_DP_NAME_UPDATE_CB;

/// 设备的回调函数
typedef struct
{
    TY_HOME_CTRL_DEV_REPORT_CB report_cb;               ///< 设备状态改变后的回调接口
    TY_HOME_CTRL_DEV_ONLINE_CB dev_online_cb;           ///< 设备上下线状态改变回调接口
    TY_HOME_CTRL_DP_NAME_UPDATE_CB dp_name_update_cb;   ///< 设备DP名称改变的回调接口
} TY_HOME_CTRL_DEV_CB;

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 获取设备描述符
 *
 * @param[in] dev_id 设备ID
 * @param[in] dev_cb 设备回调接口
 * @return TY_HOME_CTRL_DEV_T 设备描述符
 * @retval 0 获取设备描述符失败
 * @retval 其他 设备描述符
 * @warning 需要调用 @ref tuya_home_ctrl_dev_close 关闭
 */
TY_HOME_CTRL_DEV_T tuya_home_ctrl_dev_open(IN CONST CHAR_T *dev_id, IN CONST TY_HOME_CTRL_DEV_CB *dev_cb);

/**
 * @brief 关闭设备
 *
 * @param[in] dev_des 设备描述符
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_home_ctrl_dev_close(IN TY_HOME_CTRL_DEV_T dev_des);

/**
 * @brief 获取设备的所有DP信息
 *
 * @param[in] dev_des 设备描述符
 * @param[out] dp_num DP数量
 * @param[out] dp_sets DP集合
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_home_ctrl_dev_get_all_dp(IN CONST TY_HOME_CTRL_DEV_T dev_des,
                                          OUT BYTE_T *dp_num,
                                          OUT TY_HOME_CTRL_DEV_DP_S **dp_sets);

/**
 * @brief 获取指定DP的值
 *
 * @param[in] dev_des 设备描述符
 * @param[in] dp_code DP
 * @param[out] dp_value 值
 * @return OPERATE_RET
 */
OPERATE_RET tuya_home_ctrl_dev_get_dp_value(IN CONST TY_HOME_CTRL_DEV_T dev_des,
                                            IN CONST CHAR_T *dp_code,
                                            OUT CONST TY_HOME_CTRL_DEV_DP_S **dp_info);
/**
 * @brief 设置设备指定DP的值
 *
 * @param[in] dev_des 设备描述符
 * @param[in] dp_code DP
 * @param[in] dp_type DP值的类型
 * @param[in] dp_value 值
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_home_ctrl_dev_set_dp_value(IN CONST TY_HOME_CTRL_DEV_T dev_des,
                                            IN CONST CHAR_T *dp_code,
                                            IN TY_HOME_CTRL_DEV_DP_DATA_TP_E dp_type,
                                            IN CONST TY_HOME_CTRL_DEV_DP_VALUE_U *dp_value);

/**
 * @brief 打印DP的内容
 *
 * @param[in] dp DP的详细信息
 * @return VOID
 */
VOID tuya_home_ctrl_dev_show_dp(IN CONST TY_HOME_CTRL_DEV_DP_S *dp);

/**
 * @brief 获取dp点对应的名称
 *
 * @param[in] dev_des 设备描述符
 * @param[in] pp_list dp点与名称对应关系列表
 * @param[in] num dp点数量
 * @return OPERATE_RET 错误码
 * @warning 返回的pp_list在调用 @ref tuya_home_ctrl_dev_close 时会被释放
 */

OPERATE_RET tuya_home_ctrl_get_dp_name_list(IN CONST TY_HOME_CTRL_DEV_T dev_des,
                                            OUT TY_HOME_CTRL_DP_NAME_S **pp_list,
                                            OUT BYTE_T *num);

/**
 * @brief 根据设备描述符，获取设备简要信息
 * 
 * @param dev_des 设备描述符
 * @param brief_info 设备简要信息
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_home_ctrl_get_dev_brief(IN CONST TY_HOME_CTRL_DEV_T dev_des, OUT TY_HOME_CTRL_DEV_BRIEF_S *brief_info);

#ifdef __cplusplus
}  // extern "C"
#endif

/** @} */  // end for gourp product_type_unity

#endif  // __TUYA_HOME_CTRL_DEV__
