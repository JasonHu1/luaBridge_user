/*
tuya_iot_base_api.h
Copyright(C),2018-2020, 涂鸦科技 www.tuya.comm
*/

#ifndef __TUYA_GW_INIT_MIX_API_H
#define __TUYA_GW_INIT_MIX_API_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_base_defs.h"
#include "tuya_iot_com_api.h"
#include "tuya_os_adapter.h"
#include "tuya_cloud_wifi_defs.h"

#include "tuya_gw_com_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

//默认是 GW_ENTITY_ATTH_DEV
VOID tuya_iot_set_abi(GW_ABI abi);

OPERATE_RET tuya_iot_gw_pre_init(IN CONST TY_IOT_GW_CBS_S *gw_cbs);

OPERATE_RET tuya_iot_upgrade_init(IN CONST TY_IOT_CBS_S *cbs);
 
OPERATE_RET tuya_iot_entity_init(IN CONST TY_IOT_CBS_S *cbs, \
                                  IN CONST CHAR_T *product_key,IN CONST CHAR_T *sw_ver,\
                                  IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num);

                                  
#if defined(WIFI_GW) && (WIFI_GW==1)
OPERATE_RET tuya_iot_wf_entity_init(IN CONST GW_WF_CFG_MTHD_SEL cfg, IN CONST GW_WF_START_MODE start_mode,
                                IN CONST TY_IOT_CBS_S *cbs, 
                                IN CONST CHAR_T *firmware_key, IN CONST CHAR_T *product_key, IN CONST CHAR_T *wf_sw_ver,
                                IN CONST GW_ATTACH_ATTR_T *attr, IN CONST UINT_T attr_num);
                              
#endif


#if defined(GW_SUPPORT_WIRED_WIFI) && (GW_SUPPORT_WIRED_WIFI==1)
OPERATE_RET tuya_iot_wired_wifi_entity_init(IN CONST IOT_GW_NET_TYPE_T net_mode, 
                                IN CONST GW_WF_CFG_MTHD_SEL cfg, IN CONST GW_WF_START_MODE start_mode,
                                IN CONST TY_IOT_CBS_S *cbs,
                                IN CONST CHAR_T *product_key, IN CONST CHAR_T *wf_sw_ver,
                                IN CONST GW_ATTACH_ATTR_T *attr, IN CONST UINT_T attr_num);

#endif

#ifdef __cplusplus
}
#endif
#endif

