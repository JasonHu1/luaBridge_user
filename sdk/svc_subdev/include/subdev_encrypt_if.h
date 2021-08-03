
#ifndef __SUBDEV_ENCRYPT_IF_H__
#define __SUBDEV_ENCRYPT_IF_H__


#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"


#ifdef __cplusplus
    extern "C" {
#endif


OPERATE_RET wd_encrypt_if_write(IN CONST CHAR_T *dev_id, BYTE_T *p_key);
OPERATE_RET wd_encrypt_if_read(IN CONST CHAR_T *dev_id, BYTE_T *p_key);
OPERATE_RET wd_encrypt_if_delete(IN CONST CHAR_T *dev_id);
OPERATE_RET wd_encrypt_delete_all(VOID);


#ifdef __cplusplus
} // extern "C"
#endif

#endif  // __SUBDEV_ENCRYPT_IF_H__

