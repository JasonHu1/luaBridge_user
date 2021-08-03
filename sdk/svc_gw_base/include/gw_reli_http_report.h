#ifndef __GW_RELI_HTTP_REPORT_H__
#define __GW_RELI_HTTP_REPORT_H__



#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
    extern "C" {
#endif

// rpt_param 参数透传 gw_reli_http_report_data 的参数
// 返回OPRT_OK时，成功，否则重试
typedef OPERATE_RET (*GW_RELI_HTTP_RPT_FUNC)(IN VOID *rpt_param, IN UINT_T cur_try_cnt);

// 结束后，释放接口
typedef VOID (*GW_RELI_HTTP_RPT_FIN_FUNC)(IN VOID *rpt_param);

OPERATE_RET gw_reli_http_report_init();


//每个上报的请求会轮训执行，每个都上报之后再尝试重试，最大重试次数为total_try_cnt
//free_func 允许为空，当上报成功或者重试次数达到上限时回调
OPERATE_RET gw_reli_http_report_data(IN GW_RELI_HTTP_RPT_FUNC rpt_func, IN GW_RELI_HTTP_RPT_FIN_FUNC free_func,  IN VOID *rpt_param, IN UINT_T total_try_cnt);


#ifdef __cplusplus
} // extern "C"
#endif

#endif  // __GW_RELI_HTTP_REPORT_H__

