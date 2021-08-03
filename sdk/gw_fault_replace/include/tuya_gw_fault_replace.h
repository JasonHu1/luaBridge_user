#ifndef __TUYA_GW_FAULT_REPLACE_H
#define __TUYA_GW_FAULT_REPLACE_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_error_code.h"


#ifdef __cplusplus
extern "C" {
#endif

#if defined(GW_FAULT_REPLACE) && (GW_FAULT_REPLACE==1)

OPERATE_RET tuya_gw_user_fault_replace_init(VOID);

#endif

#ifdef __cplusplus
}
#endif

#endif //__TUYA_GW_FAULT_REPLACE_H
