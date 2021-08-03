#ifndef __TUYA_GW_TRD_PARTY_SIEMENS_H__
#define __TUYA_GW_TRD_PARTY_SIEMENS_H__

#include "tuya_gw_trd_party_cfg.h"

#if defined (TUYA_GW_THIRD_PARTY_SIEMENS_SUPPORT) && (1 == TUYA_GW_THIRD_PARTY_SIEMENS_SUPPORT)
#include "tuya_cloud_types.h"
#include "tuya_z3_zigbee_bash.h"
#include "tuya_z3.h"

#ifdef __cplusplus
    extern "C" {
#endif

extern CONST DEVICE_PID_EP_INFO g_trd_party_ep_info_list_siemens[];
extern CONST INT_T g_trd_party_ep_info_cnt_siemens;

/**
 * @brief get siemens 3rd-party device bacic info
 *
 * @fn ty_gw_trd_get_dev_info_siemens
 * @param sZ3DescInfoTemp
 * @param uddd
 * @param uddd2
 * @param pid
 * @param pid_len
 * @return OPERATE_RET OPRT_OK is success
 */
OPERATE_RET ty_gw_trd_get_dev_info_siemens(IN DEV_Z3_DESC_IF_S *sZ3DescInfoTemp, OUT UINT_T *uddd, OUT CHAR_T* pid, IN INT_T pid_len);

/**
 * @brief get siemens 3rd-party device current status
 *
 * @fn ty_gw_trd_get_dev_status
 * @param uddd
 * @param uddd2
 * @param sTyApsFrameTmp
 * @return OPERATE_RET OPRT_OK is success
 */
OPERATE_RET ty_gw_trd_get_dev_status_siemens(IN UINT_T uddd, IN TuYaApsFrame *sTyApsFrameTmp);

OPERATE_RET ty_gw_trd_get_dev_hb_timeout_siemens(OUT UINT_T *hb_timeout);

/**
 * @brief query siemens 3rd-party device some datapoints status
 *
 * @fn ty_gw_trd_query_dev_dp
 * @param uddd
 * @param uddd2
 * @param dp_qry
 * @param sTyApsFrameTmp
 * @return OPERATE_RET OPRT_OK is success
 */
OPERATE_RET ty_gw_trd_query_dev_dp_siemens(IN UINT_T uddd, IN CONST TY_DP_QUERY_S *dp_qry, IN TuYaApsFrame *sTyApsFrameTmp);

/**
 * @brief 3rd-party device download datapoints
 *
 * @fn ty_gw_trd_download_dev_data
 * @param uddd
 * @param uddd2
 * @param cmd
 * @param type
 * @param sTyApsFrameTmp
 * @return OPERATE_RET OPRT_OK is success
 */
OPERATE_RET ty_gw_trd_download_dev_data_siemens(IN UINT_T uddd, IN TY_CMD_U *cmd, IN CHAR_T type, IN TuYaApsFrame *sTyApsFrameTmp);

/**
 * @brief siemens 3rd-party device upload datapoints
 *
 * @fn ty_gw_trd_upload_dev_data_siemens
 * @param sTyApsFrameTmp
 * @param address
 * @param uddd
 * @param uddd2
 * @param buffer
 */
VOID ty_gw_trd_upload_dev_data_siemens(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer);

/**
 * @brief get siemens 3rd-party device endpoint info list
 *
 * @fn ty_gw_trd_get_dev_ep_info_siemens
 * @param uddd
 * @param uddd2
 * @param count
 * @return DEVICE_PID_EP_INFO
 */
CONST DEVICE_PID_EP_INFO* ty_gw_trd_get_dev_ep_info_siemens(IN UINT_T uddd, OUT INT_T *count);

#ifdef __cplusplus
}
#endif
#endif // TUYA_GW_THIRD_PARTY_SIEMENS_SUPPORT
#endif // __TUYA_GW_TRD_PARTY_SIEMENS_H__
