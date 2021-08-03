#ifndef __TUYA_LAN_DEV_MANAGE_H
#define __TUYA_LAN_DEV_MANAGE_H

#include "tuya_cloud_com_defs.h"
#include "gw_ez_set.h"
#include "lpc_cmd.h"

#ifdef __cplusplus
	extern "C" {
#endif


/***********************************************************
*************************micro define***********************
***********************************************************/


/***********************************************************
*************************variable define********************
***********************************************************/

/***********************************************************
*************************function define********************
***********************************************************/

//局域网涂鸦设备信息，后续按需扩展字段
typedef struct  {
    CHAR_T id[GW_ID_LEN+1]; // virtual id    
}TUYA_LAN_DEV_INFO_S;


typedef struct  {
    UINT_T dev_num;
    TUYA_LAN_DEV_INFO_S lan_dev_list[0];
} LAN_DEV_LIST_NODE_S;


//查询局域网中的节点全量列表
//需要调用者 调用 tuya_lan_dev_list_free 释放 lan_dev_list
OPERATE_RET tuya_lan_dev_list_get(OUT LAN_DEV_LIST_NODE_S **lan_dev_list);


VOID tuya_lan_dev_list_free(IN LAN_DEV_LIST_NODE_S *lan_dev_list);


//根据节点虚拟id查询，如果存在返回OPRT_OK.
//dev_info 可以是NULL
OPERATE_RET tuya_lan_dev_list_find(IN CONST CHAR_T *virt_id, OUT TUYA_LAN_DEV_INFO_S *dev_info);


//局域网设备是否可控制的状态变化之后回调
typedef VOID(*LAN_DEV_AVAIL_CB)(IN CONST CHAR_T *virt_id, IN BOOL_T avail);

//注册单个节点是否可控 状态变化回调
OPERATE_RET tuya_lan_reg_dev_avail_cb(IN LAN_DEV_AVAIL_CB cb);



//查询网关下的子设备或者WIFI单品的全部dp值, 
//dev_virt_id: 网关或WIFI单品的虚拟id, 
//cid: WIFI单品为NULL，网关的子设备node_id
//该操作是去实际设备上查询，是个异步的操作, 查询成功后回调        LAN_DEV_DP_QUERY_CB
//该接口适合大量的子设备查询的情况，内部处理会有几秒的延时和针对大量数据优化机制，
//不适合针对单个子设备的快速查询
OPERATE_RET tuya_lan_dev_dp_query(IN CONST CHAR_T *dev_virt_id, IN CONST CHAR_T *cid);


//注册主动节点dp查询回调
OPERATE_RET tuya_lan_reg_dev_dp_query_cb(IN LAN_DEV_DP_QUERY_CB cb);


//设置需要关注的设备列表，设置之后，只有设备列表中的设备dp变化后会 回调 LAN_DEV_DP_UP_CB 通知
//set_dev_virt_list:  需要关注的设备列表
//当不需要关注任何设备时， set_dev_virt_list传NULL
//默认情况下 不关注任何设备
//如果需要关注自己的dp，需要传入自己的虚拟ID
//OPERATE_RET tuya_lan_watch_dev_dp_set(IN CONST CHAR_T *dev_virt_list);
OPERATE_RET tuya_lan_watch_dev_dp_set(       GW_EZ_SET_ID set_dev_virt_list);


//注册节点dp上报通知回调
OPERATE_RET tuya_lan_reg_dev_dpup_cb(IN LAN_DEV_DPUP_CB cb);


//下发dp
//dev_virt_id: 网关或WIFI单品的虚拟id,可以是网关本身
//dp_value: 某个子设备或WIFI单品的全部dp值的内容，json格式，
//如 {"dps":{"4":false,"25":false,"32":"normal"},"cid":"000d6ffffe6d7100"}
OPERATE_RET tuya_lan_dev_dp_send(IN CONST CHAR_T *dev_virt_id, IN CONST CHAR_T *dp_value);

//执行标准场景
//dev_virt_id: 网关的虚拟id,可以是网关本身
//grp_id: 标准场景的gid
//sce_id: 标准场景中的sid
OPERATE_RET tuya_lan_dev_scene_exce(IN CONST CHAR_T *dev_virt_id, IN CONST CHAR_T *grp_id, IN CONST CHAR_T *sce_id);


//模块初始化
OPERATE_RET tuya_lan_dev_init();


#ifdef __cplusplus
}
#endif
#endif

