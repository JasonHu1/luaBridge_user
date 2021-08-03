#ifndef __SUBDEV_API_H__
#define __SUBDEV_API_H__



#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#include "gw_intf.h"
#include "tuya_gw_subdev_api.h"

#ifdef __cplusplus
    extern "C" {
#endif


OPERATE_RET gw_subdev_init(VOID);

OPERATE_RET gw_subdev_active(VOID);

OPERATE_RET gw_subdev_post_active(VOID);

//子设备相关重置（移除和恢复出厂都会调用）
OPERATE_RET gw_subdev_module_reset(VOID);

//子设备相关的db新老兼容处理
OPERATE_RET gw_subdev_compatible_pre(VOID);



OPERATE_RET gw_subdev_get_dev_num(OUT UINT_T *bind_num, OUT UINT_T *unbind_num);
OPERATE_RET gw_subdev_cad_update(VOID);

OPERATE_RET gw_subdev_clean_db(VOID);

#if defined(GW_FAULT_REPLACE) && (GW_FAULT_REPLACE==1)
OPERATE_RET gw_restore_dev_list(VOID);
#endif
OPERATE_RET gw_subdev_get_dev_num(OUT UINT_T *bind_num, OUT UINT_T *unbind_num);


OPERATE_RET gw_subdev_upgrade_detect_reset(INT_T upgrade_interval);

OPERATE_RET gw_subdev_get_dev_type(IN CONST CHAR_T* dev_id, OUT DEV_TYPE_T *type);

OPERATE_RET gw_subdev_get_if(IN CONST CHAR_T* dev_id, OUT DEV_DESC_IF_S **di);

OPERATE_RET gw_subdev_unbind(IN CONST CHAR_T* dev_id);

OPERATE_RET gw_subdev_unbind_all(VOID);

//如果某次回调返回非OPRT_OK，遍历会停止
typedef OPERATE_RET (*SUBDEV_IF_TRAVERSAL_CB)(IN DEV_DESC_IF_S *ddi, VOID *param);


//遍历所有的子设备..
//支持在遍历过程中，修改已有的节点
OPERATE_RET gw_subdev_dev_traversal_all(SUBDEV_IF_TRAVERSAL_CB trave_all_cb, VOID * param);


DEV_DESC_IF_S *gw_subdev_dev_traversal_all_instance(VOID ** iter);


//遍历所有未绑定的子设备..
//支持在遍历过程中，修改已有的节点
OPERATE_RET gw_subdev_unbind_dev_traversal_all(SUBDEV_IF_TRAVERSAL_CB trave_all_cb, VOID * param);


OPERATE_RET gw_subdev_on_mq_con(BOOL_T online);


OPERATE_RET gw_subdev_dp_cache_push(IN CONST CHAR_T *dev_id);


OPERATE_RET gw_subdev_get_online_state(IN CONST CHAR_T* dev_id, OUT BOOL_T *online);

VOID gw_compat_invalid_schema(VOID);

#if defined(ENABLE_MESH_GW_SW) && (ENABLE_MESH_GW_SW==1)
OPERATE_RET gw_subdev_get_dev_list(VOID);
#endif
OPERATE_RET gw_subdev_clear_dp_reli_trans_flag(IN CONST CHAR_T *dev_id, IN BYTE_T dpid);


#ifdef __cplusplus
} // extern "C"
#endif

#endif  // __SUBDEV_API_H__

