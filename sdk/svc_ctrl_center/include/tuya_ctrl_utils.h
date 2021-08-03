#ifndef __TUYA_CTRL_UTILS_H__
#define __TUYA_CTRL_UTILS_H__

#include "tuya_ctrl_center.h"

#ifdef __cplusplus
extern "C" {
#endif

OPERATE_RET tuya_ctrl_publish_info_sync(TY_INFO_SYNC_TP_E sync_type);
OPERATE_RET tuya_ctrl_http_post(IN CONST CHAR_T *api_name, IN CONST CHAR_T *api_ver,
                                IN CONST CHAR_T *uuid, IN CHAR_T *post_data,
                                IN CONST CHAR_T *p_head_other,
                                OUT ty_cJSON **pp_result);
OPERATE_RET tuya_remove_truncated_char_in_str(IN OUT CHAR_T *str, IN INT_T str_len);

#ifdef __cplusplus
} // extern "C"
#endif

#endif 
