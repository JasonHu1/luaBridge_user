/**
 * @file tuya_home_ctrl_airer.h
 * @author diao(HongWangZheng) (diao.hong@tuya.com)
 * @brief 中控SDK，晾衣架品类
 * @version 0.1
 * @date 2021-04-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CTRL_AIRER__
#define __TUYA_HOME_CTRL_AIRER__

/**
 * @defgroup product_type_airer 晾衣架品类
 * @{
 */


/**
 * @name 晾衣架支持的DP
 * @{
 */

#define HOME_CTRL_AIRER_SWITCH            "switch"            ///< 开关 @remark 类型 Boolean
#define HOME_CTRL_AIRER_CONTROL           "control"           ///< 设备控制 @remark 类型 Enum @remark 取值说明 {"range":["up","down","stop"]}
#define HOME_CTRL_AIRER_LIGHT             "light"             ///< 灯光 @remark 类型 Boolean
#define HOME_CTRL_AIRER_DISINFECTION      "disinfection"      ///< 消毒 @remark 类型 Boolean
#define HOME_CTRL_AIRER_WIND_DRY          "wind_dry"          ///< 风干 @remark 类型 Boolean
#define HOME_CTRL_AIRER_HOT_DRY           "hot_dry"           ///< 烘干 @remark 类型 Boolean
#define HOME_CTRL_AIRER_DISINFECTION_SET  "disinfection_set"  ///< 消毒倒计时设置 @remark 类型 Enum @remark 取值说明 {"range":["1h","2h","3h","4h","5h","6h","7h","8h","9h","10h","11h","12h","cancel"]}
#define HOME_CTRL_AIRER_HOT_DRY_SET       "hot_dry_set"       ///< 烘干倒计时设置 @remark 类型 Enum @remark 取值说明 {"range":["1h","2h","3h","4h","5h","6h","7h","8h","9h","10h","11h","12h","cancel"]}
#define HOME_CTRL_AIRER_ANION_SET         "anion_set"         ///< 负离子倒计时设置 @remark 类型 Enum @remark 取值说明 {"range":["1h","2h","3h","4h","5h","6h","7h","8h","9h","10h","11h","12h","cancel"]}
#define HOME_CTRL_AIRER_WIND_DRY_SET      "wind_dry_set"      ///< 风干倒计时设置 @remark 类型 Enum @remark 取值说明 {"range":["1h","2h","3h","4h","5h","6h","7h","8h","9h","10h","11h","12h","cancel"]}
#define HOME_CTRL_AIRER_ANION             "anion"             ///< 负离子 @remark 类型 Boolean
#define HOME_CTRL_AIRER_POSITION          "position"          ///< 位置 @remark 类型 Integer @remark 取值说明 {"unit":"%","min":0,"max":100,"scale":0,"step":1}
#define HOME_CTRL_AIRER_DISINFECT_LEFT    "disinfect_left"    ///< 消毒剩余时间 @remark 类型 Integer @remark 取值说明 {"unit":"min","min":0,"max":720,"scale":0,"step":1}
#define HOME_CTRL_AIRER_WIND_LEFT         "wind_left"         ///< 风干剩余时间 @remark 类型 Integer @remark 取值说明 {"unit":"min","min":1,"max":720,"scale":0,"step":1}
#define HOME_CTRL_AIRER_HOT_LEFT          "hot_left"          ///< 烘干剩余时间 @remark 类型 Integer @remark 取值说明 {"unit":"min","min":1,"max":720,"scale":0,"step":1}
#define HOME_CTRL_AIRER_ANION_LEFT        "anion_left"        ///< 负离子剩余时间 @remark 类型 Integer @remark 取值说明 {"unit":"min","min":0,"max":720,"scale":0,"step":1}
#define HOME_CTRL_AIRER_WORK_STATE        "work_state"        ///< 工作状态 @remark 类型 Enum @remark 取值说明 {"range":["up","down","stop"]}

/** @} */

#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
} // extern "C"
#endif

/** @} */  // end for gourp product_type_airer

#endif // __TUYA_HOME_CTRL_AIRER__