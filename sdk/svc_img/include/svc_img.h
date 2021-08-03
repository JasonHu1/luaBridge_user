#ifndef __SVC_IMG_H__
#define __SVC_IMG_H__


#include "tuya_cloud_com_defs.h"
#include "svc_img_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * tuya_img_service_init 
 * @param  NULL
 * @return tuya_img_service_init result.
 * The image pull service is initialized
 */
OPERATE_RET tuya_img_service_init(IN CHAR_T p_path[PATH_MAX_LEN]);


/**
 * tuya_img_service_register 
 * @param  id_name
 * @param  img_result_cb 
 * @return tuya_img_service_register result.
 * Picture pull service registration
 * The service name needs to remain unique and cannot be registered twice
 */
OPERATE_RET tuya_img_service_register(IN CHAR_T id_name[ID_NAME_MAX_LEN],TY_IMG_ID_RESULT_CB img_result_cb);

/**
 * tuya_img_service_start 
 * @param  id_name
 * @param  p_img
 * @param  img_cnt
 * @return tuya_img_service_start result.
 * Start the image pull
 */
OPERATE_RET tuya_img_service_start(IN CHAR_T id_name[ID_NAME_MAX_LEN],IN TUYA_IMG_INFO_PARM_S *p_img, IN UINT_T img_cnt);

/**
 * tuya_img_service_conf_img_size 
 * @param  img_w
 * @param  img_h
 * @return tuya_img_service_conf_img_size result.
 */
OPERATE_RET tuya_img_service_conf_img_size(IN INT_T img_w, IN INT_T img_h);
#ifdef __cplusplus
} // extern "C"
#endif

#endif // __COMPONENT_HELLO_H__

