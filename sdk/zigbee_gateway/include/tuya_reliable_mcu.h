#ifndef TUYA_RELIABLE_MCU_H
#define TUYA_RELIABLE_MCU_H


#include "tuya_reliable.h"

#ifdef TUYA_RELIABLE_MCU_OTA_SUPPORT

#ifdef __cplusplus
    extern "C" {
#endif // __cplusplus

#define TY_DEV_MCU_VER_DEFULT "4.0.0"

OPERATE_RET tuya_reliable_mcu_upgrade(IN CONST CHAR_T* dev_id, IN CONST FW_UG_S* fw,IN CONST BOOL_T otafile_is_two,\
                                            IN CONST CHAR_T* file_path,IN CONST CHAR_T* file_path_2);
OPERATE_RET tuya_reliable_mcu_ota_block_data_rep(DEV_DESC_IF_S* dev_if, UCHAR_T* req_data, INT_T req_len);
OPERATE_RET tuya_reliable_mcu_ota_result_rep(DEV_DESC_IF_S* dev_if, UCHAR_T* req_data, INT_T req_len);

OPERATE_RET tuya_reliable_mcu_sw_version_update(DEV_DESC_IF_S* dev_if, UCHAR_T* req_data, INT_T req_len);
OPERATE_RET tuya_reliable_mcu_sw_version_req(IN CONST CHAR_T* dev_id);

VOID tuya_reliable_mcu_update_end(VOID);
BOOL_T is_need_get_mcu_version(CHAR_T * zigbee_ver, UINT_T uddd);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TUYA_RELIABLE_MCU_OTA_SUPPORT
#endif // TUYA_RELIABLE_MCU_H
