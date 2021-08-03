#ifndef __TUYA_STRATEGY_CODE_H__
#define __TUYA_STRATEGY_CODE_H__

#include "tuya_ctrl_base.h"

typedef struct {
    CHAR_T *strategy_value;
    DP_PROP_TP_E src_tp;
    DP_PROP_TP_E dst_tp;

} TY_STRATEGY_PARAM_S;

#ifdef __cplusplus
extern "C" {
#endif

typedef OPERATE_RET (*TY_STRATEGY_CONVERT_CB)(INOUT TY_STRATEGY_PARAM_S *param, IN CONST TY_CTRL_OBJ_DP_VALUE_U *src, 
                                              OUT TY_CTRL_OBJ_DP_VALUE_U *dst);
OPERATE_RET tuya_strategy_code_register(IN CONST CHAR_T *code, IN TY_STRATEGY_CONVERT_CB handler);

OPERATE_RET tuya_strategy_convert(IN CONST CHAR_T *code, INOUT TY_STRATEGY_PARAM_S *param, 
                                  IN CONST TY_CTRL_OBJ_DP_VALUE_U *src, OUT TY_CTRL_OBJ_DP_VALUE_U *dst);

#ifdef __cplusplus
} // extern "C"
#endif

#endif 
