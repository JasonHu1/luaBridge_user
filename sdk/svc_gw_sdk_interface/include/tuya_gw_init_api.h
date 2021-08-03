/*
tuya_iot_base_api.h
Copyright(C),2018-2020, 涂鸦科技 www.tuya.comm
*/

#ifndef __TUYA_GW_INIT_API_H
#define __TUYA_GW_INIT_API_H

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


/***********************************************************
*  Function: tuya_iot_gw_init
*  Desc:     init tuya-sdk (wired version, [pure gateway] mode)
*  Input:    cbs: tuya-sdk user callbacks
*  Input:    gw_cbs: tuya-sdk sub-device management callbacks
*  Input:    product_key: product key
*  Input:    sw_ver: gateway version.format:xx.xx.xx (0<=x<=9)
*  Input:    attr && attr_num: gateway attributes attr array
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_iot_gw_init(IN CONST TY_IOT_CBS_S *cbs,IN CONST TY_IOT_GW_CBS_S *gw_cbs,\
                                     IN CONST CHAR_T *product_key,IN CONST CHAR_T *sw_ver,\
                                     IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num);

/***********************************************************
*  Function: tuya_iot_gw_dev_init
*  Desc:     init tuya-sdk (wired version, [gateway+inner_dev] mode)
*  Input:    cbs: tuya-sdk user callbacks
*  Input:    gw_cbs: tuya-sdk sub-device management callbacks
*  Input:    product_key: product key
*  Input:    sw_ver: gateway version.format:xx.xx.xx (0<=x<=9)
*  Input:    attr && attr_num: gateway attributes attr array
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_iot_gw_dev_init(IN CONST TY_IOT_CBS_S *cbs,IN CONST TY_IOT_GW_CBS_S *gw_cbs,\
                                           IN CONST CHAR_T *product_key,IN CONST CHAR_T *sw_ver,\
                                           IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num);


#if defined(WIFI_GW) && (WIFI_GW==1)
/***********************************************************
*  Function: tuya_iot_wf_gw_init->tuya iot entity gateway initialization
*  Input: cfg
*         cbs->tuya wifi sdk user callbacks
*         gw_cbs->tuya gw user callbacks
*         product_key->product key/proudct id,get from tuya open platform
*         wf_sw_ver->wifi module software version format:xx.xx.xx (0<=x<=9)
*         attr->gw attr
*         attr_num
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
#define tuya_iot_wf_gw_init(cfg, start_mode, cbs, gw_cbs, product_key,wf_sw_ver, attr, attr_num) \
        tuya_iot_wf_gw_init_param(cfg, start_mode, cbs, gw_cbs, NULL, product_key, wf_sw_ver, attr, attr_num)

OPERATE_RET tuya_iot_wf_gw_init_param(IN CONST GW_WF_CFG_MTHD_SEL cfg, IN CONST GW_WF_START_MODE start_mode,
                                IN CONST TY_IOT_CBS_S *cbs, IN CONST TY_IOT_GW_CBS_S *gw_cbs,
                                IN CONST CHAR_T *firmware_key, IN CONST CHAR_T *product_key, IN CONST CHAR_T *wf_sw_ver,
                                IN CONST GW_ATTACH_ATTR_T *attr, IN CONST UINT_T attr_num);


/***********************************************************
*  Function: tuya_iot_wf_gw_dev_init->tuya iot entity gateway initialization
*                                     the gateway make as a device meanwhile
*  Input: cfg
*         cbs->tuya wifi sdk user callbacks
*         gw_cbs->tuya gw user callbacks
*         product_key->product key/proudct id,get from tuya open platform
*         wf_sw_ver->wifi module software version format:xx.xx.xx (0<=x<=9)
*         attr->gw attr
*         attr_num
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
#define tuya_iot_wf_gw_dev_init(cfg, start_mode, cbs, gw_cbs, product_key,wf_sw_ver, attr, attr_num) \
        tuya_iot_wf_gw_dev_init_param(cfg, start_mode, cbs, gw_cbs, NULL, product_key, wf_sw_ver, attr, attr_num)

OPERATE_RET tuya_iot_wf_gw_dev_init_param(IN CONST GW_WF_CFG_MTHD_SEL cfg,  IN CONST GW_WF_START_MODE start_mode,
                                    IN CONST TY_IOT_CBS_S *cbs, IN CONST TY_IOT_GW_CBS_S *gw_cbs,
                                    IN CONST CHAR_T *firmware_key, IN CONST CHAR_T *product_key, IN CONST CHAR_T *wf_sw_ver,
                                    IN CONST GW_ATTACH_ATTR_T *attr, IN CONST UINT_T attr_num);
#endif

#if defined(GW_SUPPORT_WIRED_WIFI) && (GW_SUPPORT_WIRED_WIFI==1)

/***********************************************************
*  Function: tuya_iot_wf_gw_init->tuya iot entity gateway initialization
*  Input: cfg
*         cbs->tuya wifi sdk user callbacks
*         gw_cbs->tuya gw user callbacks
*         product_key->product key/proudct id,get from tuya open platform
*         wf_sw_ver->wifi module software version format:xx.xx.xx (0<=x<=9)
*         attr->gw attr
*         attr_num
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_wired_wifi_gw_init(IN CONST IOT_GW_NET_TYPE_T net_mode, 
                                IN CONST GW_WF_CFG_MTHD_SEL cfg, IN CONST GW_WF_START_MODE start_mode,
                                IN CONST TY_IOT_CBS_S *cbs, IN CONST TY_IOT_GW_CBS_S *gw_cbs,
                                IN CONST CHAR_T *product_key, IN CONST CHAR_T *wf_sw_ver,
                                IN CONST GW_ATTACH_ATTR_T *attr, IN CONST UINT_T attr_num);

/***********************************************************
*  Function: tuya_iot_wf_gw_dev_init->tuya iot entity gateway initialization
*                                     the gateway make as a device meanwhile
*  Input: cfg
*         cbs->tuya wifi sdk user callbacks
*         gw_cbs->tuya gw user callbacks
*         product_key->product key/proudct id,get from tuya open platform
*         wf_sw_ver->wifi module software version format:xx.xx.xx (0<=x<=9)
*         attr->gw attr
*         attr_num
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_wired_wifi_gw_dev_init(IN CONST IOT_GW_NET_TYPE_T net_mode, 
                                    IN CONST GW_WF_CFG_MTHD_SEL cfg,  IN CONST GW_WF_START_MODE start_mode,
                                    IN CONST TY_IOT_CBS_S *cbs, IN CONST TY_IOT_GW_CBS_S *gw_cbs,
                                    IN CONST CHAR_T *product_key, IN CONST CHAR_T *wf_sw_ver,
                                    IN CONST GW_ATTACH_ATTR_T *attr, IN CONST UINT_T attr_num);

#endif

/***********************************************************
*  Function: tuya_iot_gw_set_ota_proc_on_iotos
*  Desc: set main link module ota process on iot os, if no 
*        not call this function, default process on app.
*  Input: none
*  Output: none
*  Return: none
***********************************************************/
VOID tuya_iot_gw_set_ota_proc_on_iotos(VOID);

#ifdef __cplusplus
}
#endif
#endif

