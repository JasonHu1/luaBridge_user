/**
 * @file tuya_home_ctrl_light.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 中控灯具的SDK
 * @version 0.1
 * @date 2021-03-03
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __TUYA_HOME_CTRL_LIGHT__
#define __TUYA_HOME_CTRL_LIGHT__

/**
 * @defgroup product_type_light 灯具品类
 * @{
 */

#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_types.h"
#include "tuya_ctrl_base.h"
#include "tuya_ctrl_center.h"
#include "tuya_home_ctrl_base.h"

#pragma pack(1)

/**
 * @name 灯具支持的DP
 * @{
 */
#define HOME_CTRL_LIGHT_SWITCH_LED "switch_led"     ///< 开关 @remark 类型 Boolean
#define HOME_CTRL_LIGHT_WORK_MODE "work_mode"       ///< 模式 @remark 类型 Enum @remark 取值说明 {“range”:[“white”,“colour”,“scene”,“music”,“scene_1”,“scene_2”,“scene_3”,“scene_4”]}
#define HOME_CTRL_LIGHT_BRIGHT "home_ctrl_light_bright"   ///< 亮度 @remark 类型 Integer @remark 取值说明 {“min”:1,“scale”:0,“unit”:“”,“max”:100,“step”:1}
#define HOME_CTRL_LIGHT_TEMP "home_ctrl_light_temp"       ///< 冷暖 @remark 类型 Integer @remark 取值说明 {“min”:0,“scale”:0,“unit”:“”,“max”:100,“step”:1}
#define HOME_CTRL_LIGHT_COLOUR "home_ctrl_light_colour"   ///< 彩光模式 @remark 类型 @ref TY_HOME_CTRL_LIGHT_DP_COLOR_S
#define HOME_CTRL_LIGHT_SCENE "home_ctrl_light_scene"     ///< 情景模式 @remark 类型 @ref TY_HOME_CTRL_LIGHT_DP_SCENE_E
/** @} */


#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}  // extern "C"
#endif

/** @} */  // end for gourp product_type_light

#endif  // __TUYA_HOME_CTRL_LIGHT__