#ifndef __LAN_DEV_BASE_API_H
#define __LAN_DEV_BASE_API_H

#include "tuya_cloud_com_defs.h"
#include "lan_dev_base.h"

#ifdef __cplusplus
	extern "C" {
#endif

#if defined(ENABLE_LAN_DEV_MASTER) && (ENABLE_LAN_DEV_MASTER==1)
#define LAN_CLUSTER_CAP_DFT (CLS_CAP_MASTER_MIN * 5)
#else
#define LAN_CLUSTER_CAP_DFT (CLS_CAP_NODE_MIN * 5)
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
//关于cap的能力值分配说明
//8000: 有局域网涂鸦协议控制能力的master, 当前linux中控设备
//5000: 有普通master能力的默认值, 当前 8196 8197等linux网关使用该值
//500:  没有master能力的默认值, 当前8711am 8720cs等rtos网关使用改造
VOID lan_dev_base_set_cap(IN USHORT_T cap);

USHORT_T lan_dev_base_get_cap();

OPERATE_RET lan_dev_base_module_init(IN CONST CHAR_T * dev_id);


#ifdef __cplusplus
}
#endif
#endif

