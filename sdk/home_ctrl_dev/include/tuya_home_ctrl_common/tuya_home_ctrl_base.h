/**
 * @file tuya_home_ctrl_base.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 中控SDK基础类型
 * @version 0.1
 * @date 2021-03-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TUYA_HOME_CTRL_BASE__
#define __TUYA_HOME_CTRL_BASE__

#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_types.h"
#include "tuya_ctrl_base.h"

#pragma pack(1)

// 未使用的参数，用来消除[-Werror=unused-parameter]告警
#define UNUSED_VARIABLE(x) ((void)(x))

/**
 * @name 设备DP值的类型
 * @{
 */
typedef USHORT_T
    TY_HOME_CTRL_DEV_DP_DATA_TP_E;  ///< DP的类型 @note具体类型如@ref 设备DP值的类型,此处不使用枚举的原因是为了兼容RTOP，节约内存
#define TY_BASE_DP_DATA_TP_BOOL PROP_BOOL  ///< 布尔类型 @remark 值对应的结构体为 @ref DP_BOOL_S
#define TY_BASE_DP_DATA_TP_VALUE                                                                                       \
    PROP_VALUE  ///< 整型 @remark 值对应的结构体为 @ref DP_PROP_VAL_S, @note DP_PROP_VAL_S.scale表示数据是10的指数，实际值为DP_PROP_VAL_S.value / (10 ^ DP_PROP_VAL_S.scale)
#define TY_BASE_DP_DATA_TP_STR PROP_STR        ///< 字符串 @remark 值对应的结构体为 @ref DP_PROP_STR_S
#define TY_BASE_DP_DATA_TP_ENUM PROP_ENUM      ///< 枚举字符串 @remark 值对应的结构体为 @ref DP_PROP_ENUM_S
#define TY_BASE_DP_DATA_TP_BITMAP PROP_BITMAP  ///< 位域 @remark 值对应的结构体为 @ref DP_PROP_BITMAP
#define TY_BASE_DP_DATA_TP_CUSTOM 100          ///< 预留100个类型给基础组件扩容
#define LIGHT_DP_DATA_TP_LIGHT_COLOR 101  ///< 灯的颜色 @remark 值对应的结构体为 @ref TY_HOME_CTRL_LIGHT_DP_COLOR_S
#define LIGHT_DP_DATA_TP_LIGHT_SCENE 102  ///< 灯的场景 @remark 值对应的结构体为 @ref TY_HOME_CTRL_LIGHT_DP_SCENE_E
#define TY_BASE_DP_DATA_TP_VALUE_SACLE 103  ///< 缩放的整型 @remark 值对应的结构体为 @ref TY_HOME_CTRL_SCALE_INTEGER
/** @} */                                   // 设备DP值的类型

/**
 * @brief 标准指令的名称长度
 *
 */
#define TY_HOME_CTRL_DP_CODE_LEN 32

/**
 * @brief dp点用户自定义的可供显示的名称长度
 *
 * @note 如二位开关的"开关1"和"开关2"
 */
#define TY_HOME_CTRL_DP_NAME_LEN 64

/**
 * @brief 灯的颜色
 *
 * 以HSV方式表示
 */
typedef struct
{
    INT_T h;  ///< 色调, 0~359
    INT_T s;  ///< 饱和度, 0~1000
    INT_T v;  ///< 明度,0~100
} TY_HOME_CTRL_LIGHT_DP_COLOR_S;

/**
 * @brief 灯的场景
 *
 */
typedef enum {
    LIGHT_SCENE_TYPE_NIGHT = 0,  ///< 晚安
    LIGHT_SCENE_TYPE_READ  = 1,  ///< 阅读
    LIGHT_SCENE_TYPE_WORK  = 2,  ///< 工作
    LIGHT_SCENE_TYPE_REST  = 3,  ///< 休闲
} TY_HOME_CTRL_LIGHT_DP_SCENE_E;

/// 自定义缩放的整型值，实际值为value / (10 ^ scale)，@remark 例如想传递25.5，可以设置为value=255，scale=1,则实际值为255/(10^1)=25.5
typedef struct
{
    INT_T value;     ///< 整型缩放过的值，实际值为value / (10 ^ scale)
    USHORT_T scale;  ///< 整型的缩放倍数(10的指数)，实际值为value / (10 ^ scale)
} TY_HOME_CTRL_SCALE_INTEGER;

/**
 * @brief 品类DP的值和取值范围
 *
 */
typedef union
{
    DP_PROP_VAL_S prop_value;                  ///< 整型的值与取值范围
    DP_BOOL_S prop_bool;                       ///< 布尔型的值与取值范围
    DP_PROP_BITMAP prop_bitmap;                ///< 位域型的值与取值范围
    TY_CTRL_DP_STR_S prop_str;                 ///< 字符串类型的值与取值范围
    TY_CTRL_DP_ENUM_S prop_enum;               ///< 枚举字符串类型的值与取值范围
    TY_HOME_CTRL_LIGHT_DP_COLOR_S prop_color;  ///< 灯具颜色的值与取值范围
    TY_HOME_CTRL_LIGHT_DP_SCENE_E prop_scene;  ///< 灯具场景的值与取值范围
} TY_HOME_CTRL_DEV_DP_DATA_U;

/**
 * @brief 品类DP的信息
 *
 */
typedef struct
{
    CHAR_T *dp_code;                        ///< DP
    DP_MODE_E mode;                         ///< 读写模式， @remarks 0 读写 @remarks 1 只写 @remarks 2 只读
    TY_HOME_CTRL_DEV_DP_DATA_TP_E dp_type;  ///< DP的数据类型
    TY_HOME_CTRL_DEV_DP_DATA_U dp_value;    ///< DP内容
} TY_HOME_CTRL_DEV_DP_S;

/**
 * @brief 品类DP的值
 *
 */
typedef union
{
    INT_T int_value;  ///< 整型的值,该值由设备返回的整型里的缩放值控制,如果想要自定义缩放，请使用@ref int_scale_value
    BOOL_T bool_value;                          ///< 布尔型的值
    UINT_T bitmap_value;                        ///<位域型的值
    CHAR_T *str_value;                          ///<字符串类型的值
    CHAR_T *enum_value;                         ///<枚举字符串类型的值
    TY_HOME_CTRL_LIGHT_DP_COLOR_S color_value;  ///<灯具颜色的值
    TY_HOME_CTRL_LIGHT_DP_SCENE_E scene_value;  ///<灯具场景的值
    TY_HOME_CTRL_SCALE_INTEGER
        int_scale_value;  ///< 自定义缩放的整型值，实际类型同@ref int_value,设置的时候可忽略设备的缩放，SDK会自动转换
} TY_HOME_CTRL_DEV_DP_VALUE_U;

typedef struct 
{
    CHAR_T std_code[TY_HOME_CTRL_DP_CODE_LEN + 1];
    CHAR_T dp_name[TY_HOME_CTRL_DP_NAME_LEN + 1];
} TY_HOME_CTRL_DP_NAME_S;
#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // __TUYA_HOME_CTRL_BASE__