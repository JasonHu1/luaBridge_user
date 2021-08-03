#ifndef __TUYA_GW_TRD_PARTY_DANFOSS_H__
#define __TUYA_GW_TRD_PARTY_DANFOSS_H__

#include "tuya_gw_trd_party_cfg.h"

#if defined (TUYA_GW_THIRD_PARTY_DANFOSS_SUPPORT) && (1 == TUYA_GW_THIRD_PARTY_DANFOSS_SUPPORT)
#include "tuya_cloud_types.h"
#include "tuya_z3_zigbee_bash.h"
#include "tuya_z3.h"
#include "tuya_z3_api_tmp.h"
#include "tuya_dev_mgr.h"

#ifdef __cplusplus
    extern "C" {
#endif

extern CONST DEVICE_PID_EP_INFO g_trd_party_ep_info_list_danfoss[];
extern CONST INT_T g_trd_party_ep_info_cnt_danfoss;

/*****************************************************************
 * @Function: ty_gw_trd_get_dev_info_danfoss
 * @Description: get danfoss 3rd-party device bacic info
 * @Param: Do not edit
 * @Return: OPERATE_RET
 *****************************************************************/
OPERATE_RET ty_gw_trd_get_dev_info_danfoss(IN DEV_Z3_DESC_IF_S *sZ3DescInfoTemp, OUT UINT_T *uddd, OUT CHAR_T* pid, IN INT_T pid_len);

/*****************************************************************
 * @Function: ty_gw_trd_get_dev_status_danfoss
 * @Description: get danfoss 3rd-party device current status
 * @Param: Do not edit
 * @Return: OPERATE_RET
 *****************************************************************/
OPERATE_RET ty_gw_trd_get_dev_status_danfoss(IN UINT_T uddd, IN TuYaApsFrame *sTyApsFrameTmp);

OPERATE_RET ty_gw_trd_get_dev_hb_timeout_danfoss(OUT UINT_T *hb_timeout);

/*****************************************************************
 * @Function: ty_gw_trd_query_dev_dp_danfoss
 * @Description: query danfoss 3rd-party device some datapoints status
 * @Param: Do not edit
 * @Return: void
 *****************************************************************/
OPERATE_RET ty_gw_trd_query_dev_dp_danfoss(IN UINT_T uddd, IN CONST TY_DP_QUERY_S *dp_qry, IN TuYaApsFrame *sTyApsFrameTmp);

OPERATE_RET ty_gw_trd_download_dev_data_danfoss(IN UINT_T uddd, IN TY_CMD_U *cmd, IN CHAR_T type, IN TuYaApsFrame *sTyApsFrameTmp);

VOID ty_gw_trd_upload_dev_data_danfoss(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer);

CONST DEVICE_PID_EP_INFO* ty_gw_trd_get_dev_ep_info_danfoss(IN UINT_T uddd, OUT INT_T *count);

VOID danfoss_dev_thermostat_room_info_cb(IN TY_ROOM_INFO_S *room_info);
BOOL_T danfoss_thermostat_dev_check_cb(IN CONST CHAR_T *dev_id);

#ifdef __cplusplus
}
#endif
#endif // TUYA_GW_THIRD_PARTY_DANFOSS_SUPPORT
#endif // __TUYA_GW_TRD_PARTY_DANFOSS_H__
