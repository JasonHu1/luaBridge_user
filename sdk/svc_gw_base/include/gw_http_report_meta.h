#ifndef __GW_HTTP_REPORT_META_H__
#define __GW_HTTP_REPORT_META_H__



#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
    extern "C" {
#endif

OPERATE_RET gw_http_report_meta_init();

//meta_name 如  zigChannel 用于唯一标识，相同的name 会以最后一次调用的为准
//meta_data 如  {\\\"zigChannel\\\":%d,\\\"zigBleSubEnable\\\":true}
OPERATE_RET gw_http_report_meta(IN CONST CHAR_T *meta_name, IN CONST CHAR_T *meta_data);


#ifdef __cplusplus
} // extern "C"
#endif

#endif  // __GW_HTTP_REPORT_META_H__
#define __GW_HTTP_REPORT_META_H__

