/**
 * @file sdk_adpt_internal_api.h
 * @brief sdk adpt internal api
 * @version 1.0
 * @date 2021-7-16
 * 
 * @copyright Copyright (c) tuya.inc 2021
 * 
 */
#ifndef __SDK_ADPT_INTERNAL_API_H__
#define __SDK_ADPT_INTERNAL_API_H__

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "tuya_os_adapter.h"

#if defined(WIFI_GW) && (WIFI_GW == 1)
#include "tuya_cloud_wifi_defs.h"
#endif

#if defined(ENABLE_SUBDEVICE) && (ENABLE_SUBDEVICE == 1)
#include "tuya_gw_com_defs.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

/**
 * @brief sdk_adpt_base_nw_stat 
 *
 * @param[in] stat: network status
 *
 * @return VOID
 */
VOID sdk_adpt_base_nw_stat(IN CONST GW_BASE_NW_STAT_T stat);

#if defined(WIFI_GW) && (WIFI_GW == 1)
/**
 * @brief sdk_adpt_wf_nw_stat 
 *
 * @param[in] stat: wifi network status.=
 *
 * @return VOID
 */
VOID sdk_adpt_wf_nw_stat(IN CONST GW_WIFI_NW_STAT_E stat);
#endif

/**
 * @brief sdk_adpt_active_stat_notify 
 *
 * @param[in] status: the status of gw
 *
 * @return VOID
 */
VOID sdk_adpt_active_stat_notify(IN CONST GW_STATUS_E status);

/**
 * @brief sdk_adpt_gw_upgrade 
 *
 * @param[in] fw
 *
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET sdk_adpt_gw_upgrade(IN CONST FW_UG_S *fw);

/**
 * @brief sdk_adpt_reset_stat_notify 
 *
 * @param[in] type
 *
 * @return VOID
 */
VOID sdk_adpt_reset_stat_notify(GW_RESET_TYPE_E type);

/**
 * @brief sdk_adpt_dp_cmd_obj 
 *
 * @param[in] dp
 *
 * @return VOID
 */
VOID sdk_adpt_dp_cmd_obj(IN CONST TY_RECV_OBJ_DP_S *dp);

/**
 * @brief sdk_adpt_dp_cmd_raw 
 *
 * @param[in] dp
 *
 * @return VOID
 */
VOID sdk_adpt_dp_cmd_raw(IN CONST TY_RECV_RAW_DP_S *dp);

/**
 * @brief sdk_adpt_dp_query 
 *
 * @param[in] dp_qry
 *
 * @return VOID
 */
VOID sdk_adpt_dp_query(IN CONST TY_DP_QUERY_S *dp_qry);

/**
 * @brief sdk_adpt_subdev_upgrade 
 *
 * @param[in] dev_id
 * @param[in] fw
 *
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET sdk_adpt_subdev_upgrade(IN CONST CHAR_T *dev_id, IN CONST FW_UG_S *fw);

/**
 * @brief sdk_adpt_subdev_reset 
 *
 * @param[in] dev_id
 * @param[in] type 
 *
 * @return VOID
 */
VOID sdk_adpt_subdev_reset(IN CONST CHAR_T *dev_id, IN CONST DEV_RESET_TYPE_E type);

/**
 * @brief sdk_adpt_active_shorturl 
 *
 * @param[OUT] shorturl
 *
 * @return VOID
 */
VOID sdk_adpt_active_shorturl(OUT CONST CHAR_T *shorturl);

#if defined(ENABLE_SUBDEVICE) && (ENABLE_SUBDEVICE == 1)
/**
 * @brief sdk_adpt_subdev_add 
 *
 * @param[in] tp
 * @param[in] permit
 * @param[in] timeout 
 *
 * @return BOOL_T
 */
BOOL_T sdk_adpt_subdev_add(IN CONST GW_PERMIT_DEV_TP_T tp, IN CONST BOOL_T permit, IN CONST UINT_T timeout);

/**
 * @brief sdk_adpt_subdev_del 
 *
 * @param[in] dev_id
 * @param[in] type 
 *
 * @return VOID
 */
VOID sdk_adpt_subdev_del(IN CONST CHAR_T *dev_id, IN CONST GW_DELDEV_TYPE type);

/**
 * @brief sdk_adpt_subdev_hb_send 
 *
 * @param[in] dev_id
 *
 * @return VOID
 */
VOID sdk_adpt_subdev_hb_send(IN CONST CHAR_T *dev_id);

/**
 * @brief sdk_adpt_subdev_grp_info 
 *
 * @param[in] action:
 * @param[in] dev_id:
 * @param[in] grp_id:
 *
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET sdk_adpt_subdev_grp_info(IN CONST GRP_ACTION_E action, IN CONST CHAR_T *dev_id, IN CONST CHAR_T *grp_id);

/**
 * @brief sdk_adpt_subdev_sce_info 
 *
 * @param[in] action
 * @param[in] dev_id 
 * @param[in] grp_id 
 * @param[in] sce_id
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET sdk_adpt_subdev_sce_info(IN CONST SCE_ACTION_E action, IN CONST CHAR_T *dev_id, IN CONST CHAR_T *grp_id, IN CONST CHAR_T *sce_id);

/**
 * @brief sdk_adpt_subdev_bind_info 
 *
 * @param[in] dev_id:
 * @param[in] op_ret:
 * @return VOID
 */
VOID sdk_adpt_subdev_bind_info(IN CONST CHAR_T *dev_id, IN CONST OPERATE_RET op_ret);

/**
 * @brief sdk_adpt_subdev_wakeup 
 *
 * @param[in] dev_id
 * @param[in] duration
 * @return VOID
 */
VOID sdk_adpt_subdev_wakeup(IN CONST CHAR_T *dev_id, IN UINT_T duration);

#if defined(ENABLE_SIGMESH) && (ENABLE_SIGMESH==1)
/**
 * @brief sdk_adpt_subdev_bt_topo_update 
 *
 * @param[in] dev_id
 *
 * @return VOID
 */
VOID sdk_adpt_subdev_bt_topo_update(IN CONST CHAR_T *dev_id);

/**
 * @brief sdk_adpt_subdev_bt_cache_del 
 *
 * @param[in] dev_id
 *
 * @return VOID
 */
VOID sdk_adpt_subdev_bt_cache_del(IN CONST CHAR_T *dev_id);

/**
 * @brief sdk_adpt_subdev_bt_dev_conn_inf 
 *
 * @param[in] dev_conn_inf_json
 *
 * @return VOID
 */
VOID sdk_adpt_subdev_bt_dev_conn_inf(OUT CHAR_T *dev_conn_inf_json);
#endif

#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*__SDK_ADPT_INTERNAL_API_H__ */

