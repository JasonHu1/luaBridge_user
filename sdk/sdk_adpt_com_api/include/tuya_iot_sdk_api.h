/**
 * @file tuya_iot_sdk_api.h
 * @brief sdk api
 * @version 1.0
 * @date 2021-7-16
 * 
 * @copyright Copyright (c) tuya.inc 2021
 * 
 */
#ifndef __TUYA_IOT_SDK_API__
#define __TUYA_IOT_SDK_API__


#ifdef __cplusplus
extern "C" {
#endif

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#include "tuya_iot_sdk_defs.h"

#if defined(WIFI_GW) && (WIFI_GW==1)
#include "tuya_cloud_wifi_defs.h"
#endif


/**
 * @brief: set product ability.
 * if user not call this funciton, default ability is GW_ENTITY_ATTH_DEV
 *
 * @param[in] abi: product ability, see GW_ABI.
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
VOID tuya_iot_set_prod_ability(GW_ABI abi);

/** 
 * @brief: sdk preprocessing initialization API.
 *
 * @param[in] is_gw: whether the device has gw feature.
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_sdk_pre_init(BOOL_T is_gw);

#if defined(WIFI_GW) && (WIFI_GW==1)
#if defined(GW_SUPPORT_WIRED_WIFI) && (GW_SUPPORT_WIRED_WIFI==1)
/** 
 * @brief: tuya_iot_wired_wf_sdk_init (wired + WIFI)
 *
 * @param[in] net_mode: network support mode, see IOT_GW_NET_TYPE_T
 * @param[in] cfg:  WIFI work mode, see GW_WF_CFG_MTHD_SEL
 * @param[in] start_mode: WIFI start mode, see GW_WF_START_MODE
 * @param[in] product_key: product key/proudct id,get from tuya open platform
 * @param[in] sw_ver: software version format:xx.xx.xx (0<=x<=9)
 * @param[in] attr: gw attr
 * @param[in] attr_num: attr num
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_wired_wf_sdk_init(IN CONST IOT_GW_NET_TYPE_T net_mode, \
                                       IN CONST GW_WF_CFG_MTHD_SEL cfg, IN CONST GW_WF_START_MODE start_mode,    \
                                       IN CONST CHAR_T *product_key,IN CONST CHAR_T *sw_ver,\
                                       IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num);
#else
/** 
 * @brief: tuya_iot_wf_sdk_init (WIFI)
 *
 * @param[in] cfg:  WIFI work mode, see GW_WF_CFG_MTHD_SEL
 * @param[in] start_mode: WIFI start mode, see GW_WF_START_MODE
 * @param[in] product_key: product key/proudct id,get from tuya open platform
 * @param[in] sw_ver: software version format:xx.xx.xx (0<=x<=9)
 * @param[in] attr: gw attr
 * @param[in] attr_num: attr num
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_wf_sdk_init(IN CONST GW_WF_CFG_MTHD_SEL cfg, IN CONST GW_WF_START_MODE start_mode, \
                                 IN CONST CHAR_T *product_key,IN CONST CHAR_T *sw_ver,\
                                 IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num);
#endif
#else
/** 
 * @brief: tuya_iot_sdk_init (wired)
 *
 * @param[in] product_key: product key/proudct id,get from tuya open platform
 * @param[in] sw_ver: software version format:xx.xx.xx (0<=x<=9)
 * @param[in] attr: gw attr
 * @param[in] attr_num: attr num
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_sdk_init(IN CONST CHAR_T *product_key,IN CONST CHAR_T *sw_ver,\
                              IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num);
#endif

/** 
 * @brief: register callback to get network and WIFI status.
 *
 * @param[in] nw_stat_cb: the callback function to get network status
 * @param[in] wf_nw_stat_cb: the callback function to get WIFI status
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_sdk_reg_net_stat_cb(IN CONST SDK_GET_NW_STAT_CB nw_stat_cb, IN CONST SDK_WIFI_NW_STAT_CB wf_nw_stat_cb);

#if defined(ENABLE_SUBDEVICE) && (ENABLE_SUBDEVICE==1)
/** 
 * @brief: sub-device heartbeat init.
 *
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_gw_dev_hb_init(VOID);

/** 
 * @brief: register gw sub-device mangement callback functions.
 *
 * @param[in] tp: attached types, see GW_PERMIT_DEV_TP_T
 * @param[in] cbs: callback functions, see TY_IOT_DEV_CBS_S
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_reg_gw_mgr_cb(IN GW_PERMIT_DEV_TP_T tp, IN TY_IOT_DEV_CBS_S *cbs);
#endif

/** 
 * @brief: register dp handler.
 *
 * @param[in] sub_dev_type: subcribe DP type, see DP_DEV_TYPE_T
 * @param[in] tp: attached types, see GW_PERMIT_DEV_TP_T
 * @param[in] cb: dp handler callback functions, see TY_IOT_DP_CBS_S
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_reg_dp_cb(IN CONST DP_DEV_TYPE_T subcribe_dev_type, IN GW_PERMIT_DEV_TP_T tp, TY_IOT_DP_CBS_S *cb);

/** 
 * @brief: user service initialization api, and register callback functions.
 *
 * @param[in] cbs: callback funcitons see TY_GW_INFRA_CBS_S
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_user_svc_init(CONST TY_GW_INFRA_CBS_S *cbs);

/** 
 * @brief: user service starting api.
 *
 * @param[in] cbs: currently not used. and you can fill with NULL now.
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_user_svc_start(CONST VOID *cbs);

/** 
 * @brief: register dp report callback.
 *
 * @param[in] cbs: a set of callback.
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_reg_dp_report_cb(TY_DP_REPORT_CBS_S *cbs);

/** 
 * @brief: permit subdevice to join network in local.
 *
 * @param[in] tp: device type.
 * @param[in] permit: FALSE: disable. TRUE: enable. 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_dev_join_permit(GW_PERMIT_DEV_TP_T tp, BOOL_T permit, UINT_T timeout);

/** 
 * @brief: send obj cmd to device in local.
 *
 * @param[in] cmd: obj cmd.
 * @param[in] permit: FALSE: disable. TRUE: enable. 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_dev_obj_cmd_send(CONST TY_RECV_OBJ_DP_S *cmd);

/** 
 * @brief: send raw cmd to device in local.
 *
 * @param[in] cmd: raw cmd.
 * @param[in] permit: FALSE: disable. TRUE: enable. 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_iot_dev_raw_cmd_send(CONST TY_RECV_RAW_DP_S *cmd);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif  /*__TUYA_IOT_SDK_API__ */
