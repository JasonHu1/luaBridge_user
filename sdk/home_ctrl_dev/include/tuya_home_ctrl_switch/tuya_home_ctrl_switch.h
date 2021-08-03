/**
 * @file tuya_home_ctrl_switch.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 中控SDK开关品类的封装
 * @version 0.1
 * @date 2021-03-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CTRL_SWITCH__
#define __TUYA_HOME_CTRL_SWITCH__

/**
 * @defgroup product_type_switch 开关品类
 * @{
 */

#pragma pack(1)

/**
 * @name 开关支持的DP
 * @{
 */
#define HOME_CTRL_SWITCH_SWITCH_INDEX(index_num) "switch_" #index_num  ///< 开关1-8, @note 通过输入HOME_CTRL_SWITCH_SWITCH_INDEX(1)，即为switch_1,要求必须输入数字
#define HOME_CTRL_SWITCH_COUNTDOWN_INDEX(index_num) "countdown_" #index_num  ///< 开关1-8倒计时, @note 通过输入HOME_CTRL_SWITCH_COUNTDOWN_INDEX(1)，即为countdown_1,要求必须输入数字
#define HOME_CTRL_SWITCH_SWITCH_ALL     "switch_all"       ///< 总开关 @remark 类型 Boolean

/** @} */

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for gourp product_type_switch

#endif // __TUYA_HOME_CTRL_SWITCH__