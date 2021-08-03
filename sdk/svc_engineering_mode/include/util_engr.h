 /*
 util_engr.h
 Copyright(C),2018-2020, 涂鸦科技 www.tuya.comm
 */
#ifndef _ENG_UTIL_H
#define _ENG_UTIL_H

#include "tuya_cloud_types.h"
#include "ty_cJSON.h"

#ifdef __cplusplus
 extern "C" {
#endif

#ifdef  __ENG_UTIL_GLOBALS
    #define __ENG_UTIL_EXT
#else
    #define __ENG_UTIL_EXT extern
#endif

__ENG_UTIL_EXT \
OPERATE_RET gw_engineer_reset(VOID);

__ENG_UTIL_EXT \
VOID set_config_path(IN CONST CHAR_T *fs_storge_path);

#ifdef __cplusplus
}
#endif
#endif


