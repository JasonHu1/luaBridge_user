#ifndef __TUYA_CTRL_BASE_H__
#define __TUYA_CTRL_BASE_H__

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "tuya_iot_com_api.h"
#include "uni_log.h"

typedef struct {
    INT_T cnt;
    CHAR_T **pp_enum;
    CHAR_T *value;

} TY_CTRL_DP_ENUM_S;

typedef struct {
    CHAR_T *value;

} TY_CTRL_DP_STR_S;

typedef union {
    DP_PROP_VAL_S prop_value;
    DP_BOOL_S prop_bool;
    DP_PROP_BITMAP prop_bitmap;
    TY_CTRL_DP_STR_S prop_str;
    TY_CTRL_DP_ENUM_S prop_enum;

} TY_CTRL_DP_PROP_U;

typedef union {
    INT_T dp_value;             // valid when dp type is value
    CHAR_T *dp_enum_str;        // valid when dp type is enum
    CHAR_T *dp_str;             // valid when dp type is str
    BOOL_T dp_bool;             // valid when dp type is bool
    UINT_T dp_bitmap;           // valid when dp type is bitmap

}TY_CTRL_OBJ_DP_VALUE_U;

#endif 
