#ifndef __SUBDEV_BIND_H__
#define __SUBDEV_BIND_H__


#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"


#ifdef __cplusplus
    extern "C" {
#endif

//该接口是NVR产品的历史接口，实现有特殊处理，其他网关产品不要调用。
//支持批量绑定
OPERATE_RET tuya_iot_gw_binds_dev_attr(IN CONST GW_PERMIT_DEV_TP_T tp,IN CONST USER_DEV_DTL_DEF_T uddd,\
                                      IN CONST CHAR_T **ids, IN CONST INT_T num,IN CONST CHAR_T *pk,IN CONST CHAR_T *ver, \
                                      IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num);


typedef VOID (*SUBDEV_SKILL_PARAM_GET_CB)(IN CONST CHAR_T * devId,INOUT CHAR_T **skill_param);


VOID gw_subdev_reg_skill_param_get_cb(IN SUBDEV_SKILL_PARAM_GET_CB cb);

SUBDEV_SKILL_PARAM_GET_CB gw_subdev_get_skill_param_cb(VOID);


typedef BYTE_T GW_SUBDEV_BIND_VER_T;
#define SD_BIND_VER_DEF 0xFF //默认使用主线的版本
#define SD_BIND_VER_46 1     //使用v4.6的版本

VOID gw_subdev_set_bind_version(IN GW_SUBDEV_BIND_VER_T version);

GW_SUBDEV_BIND_VER_T gw_subdev_get_bind_version();

#ifdef __cplusplus
} // extern "C"
#endif

#endif 

