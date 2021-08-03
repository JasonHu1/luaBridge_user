#ifndef __SUBDEV_STO_H__
#define __SUBDEV_STO_H__



#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#include "subdev_api.h"

#ifdef __cplusplus
    extern "C" {
#endif


//遍历所有的子设备
//支持在遍历过程中，修改已有的节点
OPERATE_RET subdev_sto_if_traversal_all(SUBDEV_IF_TRAVERSAL_CB trave_all_cb, VOID * param);


/***********************************************************
*  Function: subdev_sto_if_write
*  Input: ddi
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET subdev_sto_if_write(IN DEV_DESC_IF_S *ddi);

OPERATE_RET subdev_sto_if_delete(IN CONST CHAR_T *p_dev_id);


//设置sub_dev_ddi配置回调函数
typedef OPERATE_RET (*SUBDEV_IF_SET_CB)(void);
/***********************************************************
*  Function: subdev_sto_if_set_all_protect
*  Input: set_all_cb cb_param
*  Output: none
*  Return: OPERATE_RET
带保护地修改sub_dev_ddi配置
***********************************************************/
OPERATE_RET subdev_sto_if_set_all_protect(SUBDEV_IF_SET_CB set_all_cb, VOID * cb_param);

OPERATE_RET gw_wd_dev_set_uddd(IN CONST CHAR_T *dev_id, IN CONST USER_DEV_DTL_DEF_T uddd);

#ifdef __cplusplus
} // extern "C"
#endif

#endif  // __SUBDEV_STO_H__

