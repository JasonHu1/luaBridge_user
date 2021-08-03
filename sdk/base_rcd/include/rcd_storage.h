#ifndef __RCD_STORGE_H
#define __RCD_STORGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "tuya_cloud_types.h"
#include "rcd_storage_errcode.h"

typedef UCHAR_T rcd_mode;
#define RCD_SET 0
#define RCD_CUR 1
#define RCD_END 2

typedef struct{
    BOOL_T need_backup;     //是否需要备份，仅POSIX系统有效
    BOOL_T enable_encrypt;  //是否需要加密
}RCD_STORAGE_EXT_T;

OPERATE_RET rcd_init(IN CONST CHAR_T *path);

OPERATE_RET rcd_db_create(IN CONST CHAR_T *name, IN CONST UINT_T max_len);
OPERATE_RET rcd_db_create_ext(IN CONST CHAR_T *name, IN CONST UINT_T max_len, IN CONST RCD_STORAGE_EXT_T *rcd_ext);
VOID rcd_db_drop(IN CONST CHAR_T *name);

OPERATE_RET rcd_entry_kv_is_exist(IN CONST CHAR_T *name, IN CONST CHAR_T *p_key, OUT BOOL_T *is_exist);
OPERATE_RET rcd_entry_kv_read(IN CONST CHAR_T *name, IN CONST CHAR_T *p_key, OUT BYTE_T **pp_data, OUT UINT_T *p_len);
OPERATE_RET rcd_entry_kv_write(IN CONST CHAR_T *name, IN CONST CHAR_T *p_key, IN CONST BYTE_T *p_data, IN CONST UINT_T data_len);
OPERATE_RET rcd_entry_kv_delete(IN CONST CHAR_T *name, IN CONST CHAR_T *p_key);

OPERATE_RET rcd_entry_lseek(IN CONST CHAR_T *name, IN CONST INT_T num, IN CONST rcd_mode mode);
OPERATE_RET rcd_entry_read(IN CONST CHAR_T *name, OUT BYTE_T **pp_data, OUT UINT_T *p_len);
OPERATE_RET rcd_entry_read_next(IN CONST CHAR_T *name, OUT BYTE_T **pp_data, OUT UINT_T *p_len);
OPERATE_RET rcd_entry_read_with_key(IN CONST CHAR_T *name, OUT CHAR_T **pp_key, OUT BYTE_T **pp_data, OUT UINT_T *p_len);
OPERATE_RET rcd_entry_read_next_with_key(IN CONST CHAR_T *name, OUT CHAR_T **pp_key, OUT BYTE_T **pp_data, OUT UINT_T *p_len);
OPERATE_RET rcd_entry_write(IN CONST CHAR_T *name, IN CONST BYTE_T *p_data, IN CONST UINT_T data_len);
OPERATE_RET rcd_entry_delete(IN CONST CHAR_T *name);
OPERATE_RET rcd_entry_num_get(IN CONST CHAR_T *name, OUT UINT_T *num);

VOID rcd_show_status(IN CONST CHAR_T *name);
OPERATE_RET rcd_get_cur_used_len(IN CONST CHAR_T *name, OUT UINT_T *cur_used_len);
OPERATE_RET rcd_is_db_exist(IN CONST CHAR_T *name, BOOL_T *is_exist);

// The functions below RCD file only
INT_T rcd_entry_file_backup_access(IN CONST CHAR_T *filename);
OPERATE_RET rcd_entry_file_recovery(IN CONST CHAR_T *name);
OPERATE_RET rcd_entry_file_backup(IN CONST CHAR_T *name);
VOID rcd_entry_file_backup_remove(IN CONST CHAR_T *filename);
VOID rcd_db_unload(IN CONST CHAR_T *name);

// The functions below RCD flash only
UINT_T rcd_db_storage_size_get(VOID);

#ifdef __cplusplus
}
#endif
#endif


