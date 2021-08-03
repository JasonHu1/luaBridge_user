#ifndef __TUYA_Z3_LQI_H
#define __TUYA_Z3_LQI_H

#ifdef __cplusplus
	extern "C" {
#endif
#include "tuya_cloud_types.h"

VOID zigbee_LQI_TM_rpt_insert(UINT_T time, UCHAR_T idx);
VOID zigbee_LQI_rpt_insert(CHAR_T * euid64str, UCHAR_T lqi, UCHAR_T idx);
VOID zigbee_LQI_rpt_end(CHAR_T* gweuid64str, UCHAR_T idx);
OPERATE_RET zigbee_lqi_init(VOID);

#ifdef __cplusplus
}
#endif

#endif