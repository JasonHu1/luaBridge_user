#ifndef __FAULT_REPLACE_HTTP_H
#define __FAULT_REPLACE_HTTP_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "ty_cJSON.h"
#if defined(GW_FAULT_REPLACE) && (GW_FAULT_REPLACE==1)
#ifdef __cplusplus
extern "C" {
#endif

#define GW_FLT_RPL_IV             "TuyaFaultReplace"    //16字节

typedef struct {
    CHAR_T *url;
    CHAR_T *local_key;
    CHAR_T *allocate_id;
}OSS_CONFIG_S;

OPERATE_RET http_get_config_backup_filepath(IN CHAR_T *filename, IN CHAR_T *content_type, OUT ty_cJSON **result);

OPERATE_RET http_get_config_restore_url(OUT ty_cJSON **result);

OPERATE_RET  http_save_backup_filepath(IN CONST CHAR_T * allocate_id,IN CONST CHAR_T *filename, IN CONST CHAR_T *content_type);

OPERATE_RET http_device_config_restore_done_notify(IN INT_T result);

OPERATE_RET http_service_config_restore_done_notify(IN CHAR_T *ncp_mac,IN INT_T result);

OPERATE_RET http_get_ncp_mac(OUT ty_cJSON **result);

OPERATE_RET http_put_backup_file_to_oss(IN OSS_CONFIG_S *config,IN ty_cJSON *header,IN CHAR_T *local_filename);

OPERATE_RET http_dec_buf_with_aes_cbc_128(IN BYTE_T *buf, IN UINT_T size, OUT BYTE_T **dec_buf, 
                                                OUT UINT_T *dec_size, IN BYTE_T *key,IN BYTE_T *iv);

#ifdef __cplusplus
}
#endif

#endif

#endif

