#ifndef __FAULT_REPLACE_H
#define __FAULT_REPLACE_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "ty_cJSON.h"
#include "gw_event_info.h"

#include "tuya_gw_fault_replace_api.h"

#if defined(GW_FAULT_REPLACE) && (GW_FAULT_REPLACE==1)
#ifdef __cplusplus
extern "C" {
#endif

BOOL_T tuya_gw_flt_rpl_upgrade_allow();

#ifdef __cplusplus
}
#endif

#endif

#endif

