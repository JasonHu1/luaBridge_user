#ifndef __GW_KV_DB_H__
#define __GW_KV_DB_H__


#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
    extern "C" {
#endif


//基于RCD的kv操作，不加密，适合网关业务存储不敏感的信息
OPERATE_RET gw_kv_db_init();

OPERATE_RET gw_kv_db_clean();

OPERATE_RET gw_kv_db_write(IN CONST CHAR_T *key, IN CONST BYTE_T *value, IN CONST UINT_T len);

OPERATE_RET gw_kv_db_read(IN CONST CHAR_T *key, OUT BYTE_T **value, OUT UINT_T *p_len);

OPERATE_RET gw_kv_db_delete(IN CONST CHAR_T *key);

#ifdef __cplusplus
} // extern "C"
#endif

#endif  // __GW_KV_DB_H__

