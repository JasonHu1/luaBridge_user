#ifndef _TUYA_IOT_EXT_API_H_
#define _TUYA_IOT_EXT_API_H_

#include "gw_intf.h"
#include "tuya_cloud_types.h"
#include "tuya_app_plateform_cfg.h"
#include "tuya_gw_com_api.h"


#ifdef __cplusplus
    extern "C" {
#endif

GW_CNTL_S *tuya_iot_get_gw_cntl(VOID);

DEV_CNTL_N_S *tuya_iot_get_dev_cntl(IN CONST CHAR_T *id);

GW_WORK_STAT_MAG_S *tuya_iot_get_gw_wsm(VOID);

GW_DESC_IF_S *tuya_iot_get_gw_if(VOID);

TY_IOT_CBS_S *tuya_iot_get_cbs(VOID);

GW_ACTV_IF_S *tuya_iot_get_gw_actv(VOID);

GW_BASE_IF_S *tuya_iot_get_gw_base(VOID);

TY_IOT_GW_CBS_S  *tuya_iot_get_gw_cbs(VOID);

OPERATE_RET tuya_iot_get_storage_dir(INOUT CHAR_T *storage_dir);

VOID tuya_iot_set_gw_ext_stat(IN CONST GW_EXT_STAT_T ext_stat);

DP_CNTL_S *tuya_iot_get_dev_dp_cntl(IN CONST CHAR_T *id,IN CONST BYTE_T dpid);

BOOL_T tuya_iot_gw_set_subdev_max_cnt(UINT_T cnt);

UINT_T tuya_iot_gw_get_subdev_cnt(VOID);

BOOL_T tuya_iot_gw_is_subdev_cnt_over_max(VOID);

GW_NW_STAT_T tuya_iot_get_gw_nw_status(VOID);

//设置工程模式下子设备是否存在的flag
VOID tuya_iot_set_engineer_dev_flag(BOOL_T flag);
//获取工程模式下子设备是否存在的flag
BOOL_T tuya_iot_get_engineer_dev_flag(VOID);
//设置普通模式下子设备是否存在的flag
VOID tuya_iot_set_normal_dev_flag(BOOL_T flag);
//获取普通模式下子设备是否存在的flag
BOOL_T tuya_iot_get_normal_dev_flag(VOID);


#ifdef __cplusplus
}
#endif

#endif

