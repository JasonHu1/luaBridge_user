/*
tuya_gw_subdev_api.h
Copyright(C),2018-2020, 涂鸦科技 www.tuya.comm
*/

#ifndef __TUYA_GW_SUBDEV_API_H
#define __TUYA_GW_SUBDEV_API_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#include "tuya_gw_com_defs.h"

#ifdef __cplusplus
extern "C" {
#endif


#define SIGMESH_AUTH_KEY_LEN 32
#define SIGMESH_RADOM_LEN    32

typedef struct {
    CHAR_T net_key[SIGMESH_NET_KEY_LEN+1];
    CHAR_T app_key[SIGMESH_APP_KEY_LEN+1];
    USHORT_T node_id;
}TY_SIGMESH_NET_INFO_S;

typedef struct{
    CHAR_T encrypted_auth_key[SIGMESH_AUTH_KEY_LEN+1];
    CHAR_T random[SIGMESH_RADOM_LEN+1];
}TY_SIGMESH_AUTH_KEY;

typedef struct {
    INT_T nodeId_num;
    USHORT_T *node_list;
}TY_SIGMESH_NODE_LIST_S;


/***********************************************************
*  Function: tuya_iot_gw_bind_dev_attr
*  Desc:     bind a sub-device to gateway
*  Input:    tp: sub-device type
*  Input:    uddd: sub-device detail type
*  Input:    id: sub-device id
*  Input:    pk: sub-device product key
*  Input:    ver: sub-device version
*  Input:    attr: sub-device mcu versions
*  Input:    attr_num: sub-device mcu versions
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
#define tuya_iot_gw_bind_user_dev(tp, uddd, id, pk, ver) \
    tuya_iot_gw_bind_dev_attr(tp, 0, uddd, id, pk, ver, NULL, 0, FALSE, NULL)

#define tuya_iot_gw_bind_dev(tp, uddd, id, pk, ver) \
    tuya_iot_gw_bind_dev_attr(tp, uddd, 0, id, pk, ver, NULL, 0, FALSE, NULL)
OPERATE_RET tuya_iot_gw_bind_dev_attr(IN CONST GW_PERMIT_DEV_TP_T tp,IN CONST USER_DEV_DTL_DEF_T uddd, USER_DEV_DTL_DEF_T uddd2,\
                                      IN CONST CHAR_T *id,IN CONST CHAR_T *pk,IN CONST CHAR_T *ver, \
                                      IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num, \
                                      IN CONST BOOL_T oem, IN CONST CHAR_T *p_firmwarekey);

typedef struct {
   GW_PERMIT_DEV_TP_T tp;           // sub-device type, Required
   USER_DEV_DTL_DEF_T uddd;         // sub-device detail type, Required
   USER_DEV_DTL_DEF_T uddd2;        // sub-device detail type extend, Optional
   CHAR_T *id;                      // sub-device id, Required
   CHAR_T *pid;                     // sub-device id, Required
   CHAR_T *firmware_key;            // sub-device product id, Optional
   CHAR_T *ver;                     // sub-device version, Required
   GW_ATTACH_ATTR_T *attr;          // sub-device mcu versions, Optional
   UINT_T attr_num;                 // sub-device mcu versions num, Optional
   BOOL_T oem;                      // sub-device support oem or not, Required
   BOOL_T is_support_ota;           // sub-device support ota or not, Required
   CHAR_T *uuid;                     // sub-device uuid, Optional
} TUYA_GW_SUBDEV_BIND_INFO_S;

OPERATE_RET tuya_iot_gw_subdev_bind(TUYA_GW_SUBDEV_BIND_INFO_S *ty_gw_subdev_info);


/***********************************************************
*  Function: tuya_iot_gw_unbind_dev
*  Desc:     unbind a sub-device from gateway
*  Input:    id: sub-device id
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_iot_gw_unbind_dev(IN CONST CHAR_T *id);

/***********************************************************
*  Function: tuya_iot_dev_online_stat_update
*  Desc:     update sub-device online state
*  Input:    dev_id: sub-device id
*  Input:    online: online state
*  Input:    is_force: true, force update state, false:the same of status,don't update
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
#define tuya_iot_dev_online_stat_update(dev_id, online) \
    tuya_iot_dev_online_update(dev_id, online, FALSE)
OPERATE_RET tuya_iot_dev_online_update(IN CONST CHAR_T *dev_id,IN CONST BOOL_T online, IN CONST BOOL_T is_force);

/***********************************************************
*  Function: tuya_iot_sys_mag_hb_init
*  Desc:     enable gateway hearbeat check mechanism.if enabled,
*            gateway will check all the sub-devices every 3000 ms,
*            if sub-device not send a heartbeat to gateway during
*            its heartbeat timeout time. the gateway will make
*            the subdevice offline,and notify user by hb_send_cb
*            for at most 3 times.
*  Input:    hb_send_cb: sub-device_id
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
#define tuya_iot_sys_mag_hb_init(hb_send_cb) \
    tuya_iot_sys_mag_hb_send_init(hb_send_cb, 1000)
OPERATE_RET tuya_iot_sys_mag_hb_send_init(IN CONST DEV_HEARTBEAT_SEND_CB hb_send_cb, IN CONST UINT_T min_query_interval);

/***********************************************************
DON'T USE, NEW INTERFACE: tuya_iot_set_dev_hb_cfg
***********************************************************/
#define tuya_iot_set_dev_hb_timeout(dev_id, hb_timeout_time) \
    tuya_iot_set_dev_hb_timeout_cfg(dev_id, hb_timeout_time, 2)
OPERATE_RET tuya_iot_set_dev_hb_timeout_cfg(IN CONST CHAR_T *dev_id,IN CONST TIME_S hb_timeout_time, IN CONST UINT_T max_resend_times);


/***********************************************************
*  Function: tuya_iot_set_dev_hb_cfg
*  Desc:     set sub-device heartbeat timeout param.
*            if is_sleep:TRUE, this sub-device
*            will skip the heartbeat check.
*  Input:    devid: sub-device_id
*  Input:    is_sleep: true is lowpower dev.
*  Input:    hb_timeout_time: heartbeat timeout, hb_timeout_time==0xffffffff,always online;if is_sleep==flase, the hb_timeout_time is invaild.
*  Input:    max_resend_times: max resend times, default set is 2, don't modify, if you don't know.
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_iot_set_dev_hb_cfg(IN CONST CHAR_T *dev_id,IN CONST TIME_S hb_timeout_time, IN CONST UINT_T max_resend_times, BOOL_T is_lowpower);


/***********************************************************
*  Function: tuya_iot_fresh_dev_hb
*  Desc:     gateway recv a sub-device heartbeat info
*  Input:    devid: sub-device_id
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_iot_fresh_dev_hb(IN CONST CHAR_T *dev_id);

/***********************************************************
*  Function: tuya_iot_set_hb_status
*  Desc:     set heartbeat query status,
*  Input:    is_stop:true:stop query, false:query,default is false.
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_iot_set_hb_status(IN CONST BOOL_T is_stop);

/***********************************************************
*  Function: tuya_iot_gw_reset_dev
*  Input: id
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_gw_reset_dev(IN CONST CHAR_T *id);

#if defined(ENABLE_SIGMESH) && (ENABLE_SIGMESH==1)
#if defined(ENABLE_MESH_GW_SW) && (ENABLE_MESH_GW_SW==1)
/***********************************************************
*  Function: tuya_iot_sigmesh_set_net_info
*            设置sigmesh网络信息
*  Input: none
*  Output: TY_SIGMESH_NET_INFO_S: net_key, app_key, node_id
*  Return: 0:success, other:error
***********************************************************/
OPERATE_RET tuya_iot_sigmesh_set_net_info(INOUT TY_SIGMESH_NET_INFO_S *sigmesh_net_info);
/***********************************************************
*  Function: tuya_iot_sigmesh_get_net_info
*            获取sigmesh网络信息
*  Input: none
*  Output: TY_SIGMESH_NET_INFO_S: net_key, app_key
*  Return: 0:success, other:error
***********************************************************/
OPERATE_RET tuya_iot_sigmesh_get_net_info(INOUT TY_SIGMESH_NET_INFO_S *sigmesh_net_info);
#else
/***********************************************************
*  Function: tuya_iot_sigmesh_get_net_info
*            获取sigmesh网络信息
*  Input: none
*  Output: TY_SIGMESH_NET_INFO_S: net_key, app_key
*  Return: 0:success, other:error
***********************************************************/
OPERATE_RET tuya_iot_sigmesh_get_net_info(INOUT TY_SIGMESH_NET_INFO_S *sigmesh_net_info);
#endif

/***********************************************************
*  Function: tuya_iot_sigmesh_get_free_node_list
*            获取sigmesh网络信息
*  Input: node_num, nose_list
*  Output: TY_SIGMESH_NET_INFO_S: net_key, app_key
*  Return: 0:success, other:error
***********************************************************/
OPERATE_RET tuya_iot_sigmesh_get_free_node_list(IN CONST INT_T node_num, INOUT TY_SIGMESH_NODE_LIST_S *node_list);

/***********************************************************
*  Function: tuya_iot_sigmesh_get_source_node
*            获取sigmesh网关侧蓝牙端源nodeid
*  Input: NULL
*  Output: source node id
*  Return: 0:success, other:error
***********************************************************/
OPERATE_RET tuya_iot_sigmesh_get_source_node(USHORT_T *source_node);

/***********************************************************
*  Function: tuya_iot_sigmesh_bind
*            获取sigmesh网络信息
*  Input: node_num, nose_list
*  Output: TY_SIGMESH_NET_INFO_S: net_key, app_key
*  Return: 0:success, other:error
***********************************************************/
OPERATE_RET tuya_iot_sigmesh_bind(IN CONST GW_PERMIT_DEV_TP_T tp,IN CONST USER_DEV_DTL_DEF_T uddd,\
                                      IN CONST CHAR_T *id,IN CONST CHAR_T *pk,IN CONST CHAR_T *ver, \
                                      IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num, \
                                      IN CONST BOOL_T oem, IN CONST CHAR_T *p_firmwarekey, \
                                      IN CONST CHAR_T *mac, IN CONST CHAR_T *uuid, IN CONST CHAR_T *dev_key);

/***********************************************************
*  Function: tuya_iot_ble_bind
*            单点蓝牙子设备邦定
*  Input:
*  Output: none
*  Return: 0:success, other:error
***********************************************************/
OPERATE_RET tuya_iot_ble_bind(IN CONST GW_PERMIT_DEV_TP_T tp,IN CONST USER_DEV_DTL_DEF_T uddd,\
                          IN CONST CHAR_T *id,IN CONST CHAR_T *pk,IN CONST CHAR_T *ver, \
                          IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num, \
                          IN CONST BOOL_T oem, IN CONST CHAR_T *p_firmwarekey, \
                          IN CONST CHAR_T *mac, IN CONST CHAR_T *uuid);

/***********************************************************
*  Function: tuya_iot_sigmesh_get_auth_key
*  Desc:     Get key1 information interface while gateway
*            bind devices
*  Input: sigmesh_auth_key
*  Output: TY_SIGMESH_AUTH_KEY: encrypted_auth_key, random
*  Return: 0:success, other:error
***********************************************************/
OPERATE_RET tuya_iot_sigmesh_get_auth_key(IN CONST CHAR_T *uuid,INOUT TY_SIGMESH_AUTH_KEY *sigmesh_auth_key);

/***********************************************************
*  Function: tuya_iot_sigmesh_get_bind_status
*  Desc:  Check sigmesh device bind status
*  Input: uuid: sigmesh device mac
*         encryptedValue: produced by uuid and localKey
*                         with aes encryption
*  Output: bind_status
*  Return: 0:success, other:error
***********************************************************/
OPERATE_RET tuya_iot_sigmesh_get_bind_status(IN CONST CHAR_T *uuid,IN CONST CHAR_T *encryptedValue,\
                                                INOUT BOOL_T *bind_status);

/***********************************************************
*  Function: tuya_iot_sig_ble_rept_bind_status
*  Desc:  获取sigmesh ble 设备绑定状态
*  Input: node_id: 设备短地址，sigmesh用云端分配的地址，蓝牙单点用uuid
*         bind_status: TURE:绑定成功，FALSE:绑定失败
*  Return: 0:success, other:error
***********************************************************/
OPERATE_RET tuya_iot_sig_ble_rept_bind_status(IN CONST CHAR_T *node_id,IN BOOL_T bind_status);
#endif


/***********************************************************
*  Function: tuya_iot_push_dev_wakeup_status
*  Input: dev_id: subdevice id
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_push_dev_wakeup_status(IN CONST CHAR_T *dev_id);

/***********************************************************
*  Function: tuya_gw_set_subdev_max_cnt
*  Input: cnt: sub dev max count
*  Output: none
*  Return: BOOL_T
***********************************************************/
BOOL_T tuya_gw_set_subdev_max_cnt(UINT_T cnt);

/***********************************************************
*  Function: tuya_gw_get_subdev_cnt
*  Input: none
*  Output: none
*  Return: sub dev count
***********************************************************/
UINT_T tuya_gw_get_subdev_cnt(VOID);


/***********************************************************
*  Function: tuya_gw_get_subdev_cnt_in_db
*  Input: none
*  Output: none
*  Return: sub dev count
***********************************************************/
UINT_T tuya_gw_get_subdev_cnt_in_db(VOID);

BOOL_T tuya_gw_dev_is_exist(IN CONST CHAR_T *dev_id);

/***********************************************************
*  Function: tuya_iot_get_dev_online_status
*  Desc:     get device online & offline status
*  Input:    unique id of device
*  Output:   status: TRUE is online, FALSE is offline
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_iot_get_dev_online_status(IN CONST CHAR_T *dev_id, OUT BOOL_T *status);


/***********************************************************
*  Function: tuya_iot_get_dev_if
*  Desc:     get sub-device info
*  Input:    devid: if devid = sub-device_id, then return the sub-dev info
*                   if devid = NULL, then return the gateway info
*  Return:   (DEV_DESC_IF_S *): success  NULL: fail
***********************************************************/
DEV_DESC_IF_S *tuya_iot_get_dev_if(IN CONST CHAR_T *dev_id);




/***********************************************************
*  Function: tuya_iot_dev_traversal
*  Desc:     Traversing all devices under the gateway,
*            except the gateway device.should access a data token first.
*  Input:    token
*  Input:    iterator
*  Return:   (DEV_DESC_IF_S *) (NULL means end)
***********************************************************/
DEV_DESC_IF_S *tuya_iot_dev_traversal(INOUT VOID **iterator);

#define DEV_DESC_TRAVERSAL_BEGIN(dev_if) \
do { \
    DEV_DESC_IF_S * dev_if = NULL; \
    VOID *iterator = NULL; \
    do { \
        dev_if = (DEV_DESC_IF_S *)tuya_iot_dev_traversal(&iterator); \
        if(dev_if) {

#define DEV_DESC_TRAVERSAL_FINISH(dev_if) \
        } \
    }while(dev_if); \
}while(0);

#define DEV_DESC_TRAVERSAL_BREAK(dev_if)     break;
#define DEV_DESC_TRAVERSAL_CONTINUE(dev_if)  continue;



/***********************************************************
*  Function: tuya_iot_gw_subdevice_update
*  Desc:     update sub-device version
*  Input:    id: sub-device id
*  Input:    ver: sub-device version
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
#define tuya_iot_gw_subdevice_update(id, ver) \
    tuya_iot_gw_subdevice_update_versions(id, ver, NULL, 0, 0)
OPERATE_RET tuya_iot_gw_subdevice_update_versions(IN CONST CHAR_T *id,IN CONST CHAR_T *ver,
                                                  IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num, IN CONST BOOL_T is_force);

/***********************************************************
*  Function: tuya_iot_gw_subdevice_update_ext
*  Desc:     update sub-device version
*  Input:    id: sub-device id
*  Input:    ver: sub-device version
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
#define tuya_iot_gw_subdevice_update_ext(id, ver) \
    tuya_iot_gw_subdevice_update_versions_ext(id, ver, NULL, 0, 0)
OPERATE_RET tuya_iot_gw_subdevice_update_versions_ext(IN CONST CHAR_T *id,IN CONST CHAR_T *ver,
                                                IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num, 
                                                IN CONST BOOL_T is_force, IN CONST BOOL_T is_support_ota);

/**
 * @brief 子设备升级失败上报，会推送一次当前版本记录到云端
 *
 * @param dev_id 子设备id，String
 */
VOID tuya_iot_gw_subdevice_upgrade_failed_rpt(IN CONST CHAR_T* dev_id);


#ifdef __cplusplus
}
#endif
#endif

