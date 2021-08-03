#ifndef __TUYA_GW_USER_DP_H
#define __TUYA_GW_USER_DP_H


#ifdef __cplusplus
	extern "C" {
#endif

#include <stdio.h>
#include <pthread.h>
#include "tuya_cloud_com_defs.h"
#include <string.h>
#include "uni_log.h"
#include "uni_thread.h"
#include "tuya_hal_system.h"
#include "sys_timer.h"
#include "uni_time.h"
#include "tuya_ws_db.h"
#include "mem_pool.h"
#include "tuya_iot_com_api.h"
#include "cJSON.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

OPERATE_RET gw_user_dp_init(CHAR_T *dp_default);
OPERATE_RET gw_user_dp_update(IN TY_OBJ_DP_S dp);
CHAR_T * _get_dp_tmp_data(VOID);
OPERATE_RET gw_user_dp_clear(VOID);
UINT_T get_default_dp_ids_array(CHAR_T** pdp_ids);

#ifdef __cplusplus
}
#endif

#endif

