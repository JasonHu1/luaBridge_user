#ifndef __TUYA_GW_TRD_PARTY_H__
#define __TUYA_GW_TRD_PARTY_H__

#include "tuya_gw_config.h"

#if defined (TUYA_GW_THIRD_PARTY_SUPPORT) && (1 == TUYA_GW_THIRD_PARTY_SUPPORT)

#include "tuya_gw_trd_party_cfg.h"
#include "tuya_cloud_types.h"
#include "tuya_z3_zigbee_bash.h"
#include "tuya_z3.h"

#ifdef __cplusplus
    extern "C" {
#endif

/**
 * @brief get 3rd-party device bacic info
 *
 * @fn ty_gw_trd_get_dev_info
 * @param sZ3DescInfoTemp
 * @param uddd
 * @param uddd2
 * @param pid
 * @param pid_len
 * @return OPERATE_RET OPRT_OK is success
 */
OPERATE_RET ty_gw_trd_get_dev_info(IN DEV_Z3_DESC_IF_S *sZ3DescInfoTemp, OUT UINT_T *uddd, OUT UINT_T *uddd2, OUT CHAR_T* pid, IN INT_T pid_len);

/**
 * @brief get 3rd-party device current status
 *
 * @fn ty_gw_trd_get_dev_status
 * @param uddd
 * @param uddd2
 * @param address
 * @return OPERATE_RET OPRT_OK is success
 */
OPERATE_RET ty_gw_trd_get_dev_status(IN UINT_T uddd, IN UINT_T uddd2, IN CHAR_T* address);

/*****************************************************************
 * @Function: ty_gw_trd_get_dev_hb_timeout
 * @Description: 获取设备心跳超时时间
 * @Param[in]:  uddd2
 * @Param[out]: hb_timeout
 * @Return: OPERATE_RET
 *****************************************************************/
OPERATE_RET ty_gw_trd_get_dev_hb_timeout(IN UINT_T uddd2, OUT UINT_T *hb_timeout);

/**
 * @brief query 3rd-party device some datapoints status
 *
 * @fn ty_gw_trd_query_dev_dp
 * @param uddd
 * @param uddd2
 * @param dp_qry
 * @param sTyApsFrameTmp
 * @return OPERATE_RET OPRT_OK is success
 */
OPERATE_RET ty_gw_trd_query_dev_dp(IN UINT_T uddd, IN UINT_T uddd2, IN CONST TY_DP_QUERY_S *dp_qry, IN TuYaApsFrame *sTyApsFrameTmp);

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
OPERATE_RET ty_gw_trd_download_dev_data(IN UINT_T uddd, IN UINT_T uddd2, IN TY_CMD_U *cmd, IN CHAR_T type, IN TuYaApsFrame *sTyApsFrameTmp);

/**
 * @brief 3rd-party device upload datapoints
 *
 * @fn ty_gw_trd_upload_dev_data
 * @param sTyApsFrameTmp
 * @param address
 * @param uddd
 * @param uddd2
 * @param buffer
 */
VOID ty_gw_trd_upload_dev_data(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UINT_T uddd2, IN UCHAR_T *buffer);

/**
 * @brief 3rd-party device get version
 *
 * @fn ty_gw_trd_get_dev_version
 * @param uddd
 * @param uddd2
 * @param address
 * @return TRUE: success
 */
BOOL_T ty_gw_trd_get_dev_version(IN UINT_T uddd, IN UINT_T uddd2, IN CHAR_T* address);

/**
 * @brief is dev need special process
 *
 * @fn ty_gw_trd_need_dev_special_version
 * @param uddd2
 * @return TRUE: need special process
 */
BOOL_T ty_gw_trd_need_dev_special_version(IN UINT_T uddd2);

/**
 * @brief get 3rd-party device endpoint info list
 *
 * @fn ty_gw_trd_get_dev_ep_info
 * @param uddd
 * @param uddd2
 * @param count
 * @return DEVICE_PID_EP_INFO
 */
CONST DEVICE_PID_EP_INFO* ty_gw_trd_get_dev_ep_info(IN UINT_T uddd, IN UINT_T uddd2, OUT INT_T *count);

/**
 * @brief check 3rd-party by manufacturer name
 *
 * @fn ty_gw_is_trd_party
 * @param manu_name
 * @return BOOL_T TRUE is 3rd-party device
 */
BOOL_T ty_gw_is_trd_party(IN CONST CHAR_T *manu_name);

/**
 * @brief check 3rd-party by device id
 *
 * @fn ty_gw_is_trd_party_dev
 * @param cid
 * @return BOOL_T TRUE is 3rd-party device
 */
BOOL_T ty_gw_is_trd_party_dev(IN CONST CHAR_T *cid);

/**
 * @brief check 3rd-party by uddd2
 *
 * @fn ty_gw_is_trd_party_dev_by_uddd2
 * @param uddd2
 * @return BOOL_T
 */
BOOL_T ty_gw_is_trd_party_dev_by_uddd2(IN CONST UINT_T uddd2);

UINT_T tuya_get_dev_dp_transfer_cnt(IN CONST CHAR_T *id,IN CONST BYTE_T dpid);

#ifdef __cplusplus
}
#endif
#endif // TUYA_GW_THIRD_PARTY_SUPPORT
#endif // __TUYA_GW_TRD_PARTY_H__
