#ifndef __SUB_DEV_LOG_H__
#define __SUB_DEV_LOG_H__

#include "tuya_cloud_types.h"

#ifdef __cplusplus
    extern "C" {
#endif

#define dev_log_errcode_rpt_insert(time, code) \
    dev_log_errcode_rpt(NULL,time,code)
#define dev_log_errcode_rpt_end(device_id,time, code) \
    dev_log_errcode_rpt(device_id,time,code)

VOID dev_log_errcode_rpt(CHAR_T * device_id, UINT_T time, INT_T code);

#ifdef __cplusplus
}
#endif
#endif // __SUB_DEV_LOG_H__