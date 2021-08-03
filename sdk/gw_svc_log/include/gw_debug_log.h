#ifndef __GW_DEBUG_LOG_H
#define __GW_DEBUG_LOG_H

#include "tuya_cloud_types.h"
#include "ty_cJSON.h"

#ifdef __cplusplus
    extern "C" {
#endif

typedef OPERATE_RET (*GW_DEBUG_HANDLER_CB)(IN ty_cJSON *root_json);

OPERATE_RET tuya_gw_debug_log_reg_proto(CONST CHAR_T *log_pro, GW_DEBUG_HANDLER_CB handler);

OPERATE_RET tuya_gw_debug_log_unreg_proto(IN CONST CHAR_T *log_pro);

OPERATE_RET tuya_gw_debug_log_upload(IN CONST CHAR_T *upload_data);


#ifdef __cplusplus
}
#endif

#endif

