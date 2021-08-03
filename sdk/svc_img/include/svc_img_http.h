#ifndef __SVC_IMG_HTTP_H__
#define __SVC_IMG_HTTP_H__

#include "tuya_cloud_com_defs.h"
#include "svc_img_common.h"
#include "http_manager.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * get_dev_img_data_https_get 
 * @param  p_dev_info
 * @param  cnt
 * @param  cb
 * @return get_dev_img_data_https_get result.
 * Function to obtain the display image data from the cloud
 */
OPERATE_RET get_dev_img_data_https_get(IN TUYA_IMG_INFO_MSG_S *p_dev_info,IN UINT_T cnt, IN HTTP_GET_DEV_DATA_CB cb, OUT SESSION_ID session);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __COMPONENT_HELLO_H__