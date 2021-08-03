#ifndef __SVC_FILE_H__
#define __SVC_FILE_H__


#include "tuya_error_code.h"
#include "tuya_cloud_types.h"
#include "svc_img_common.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * tuya_dev_img_file_data_resever_handle
 * @param  p_path 
 * @param  buf 
 * @param  len
 * @return tuya_dev_img_file_data_resever_handle result.
 */
OPERATE_RET tuya_dev_img_file_data_resever_handle(IN CONST CHAR_T *p_path,IN CONST BYTE_T *buf,UINT_T len);

/**
 * tuya_set_img_set_root_path
 * @param  p_path pointer to the device image file path.
 * @return tuya_set_img_set_root_path result.
 */
OPERATE_RET tuya_set_img_set_root_path(IN CHAR_T *p_path);


/**
 * tuya_dir_id_file_find_delete
 * @param  p_dir_path pointer to the device image file path.
 * @param  p_file_name pointer to the device image file name path.
 * @return tuya_dir_id_file_find_delete result.
 */
OPERATE_RET tuya_dir_id_file_find_delete(IN CHAR_T *p_dir_path, IN CHAR_T *p_file_name);


/**
 * tuya_img_url_md5_file_delete
 * @param  p_path pointer to the device image file path.
 * @param  p_url pointer to the device image url.
 * @return tuya_img_url_md5_file_delete result.
 */
OPERATE_RET tuya_img_url_md5_file_delete(IN CHAR_T *p_path, IN CHAR_T *p_url);

/**
 * tuya_get_string_md5_result_common
 * @param  p_path 
 * @param  data_len 
 * @param  digest 
 * @return tuya_get_string_md5_result_common result.
 */
VOID tuya_get_string_md5_result_common(IN CHAR_T *p_data, IN UINT_T data_len, OUT CHAR_T digest[MD5_LEN_MAX+1]);

/**
 * tuya_dir_file_find_path_result_for_url
 * @param  p_dir_path pointer to the device image file path.
 * @param  p_url pointer to the device image file path.
 * @param  pp_path pointer to the device image file path.
 * @return tuya_dir_file_find_path_result_for_url result.
 */
OPERATE_RET tuya_dir_file_find_path_result_for_url(IN CHAR_T *p_dir_path, IN CHAR_T *p_url, OUT CHAR_T **pp_path);


/**
 * tuya_dir_file_delete_for_url
 * @param  p_msg pointer to the device image file path.
 * @return tuya_dir_file_delete_for_url result.
 */
OPERATE_RET tuya_dir_file_delete_for_url(IN TUYA_IMG_INFO_MSG_S *p_msg);

#ifdef __cplusplus
} 
#endif

#endif 
