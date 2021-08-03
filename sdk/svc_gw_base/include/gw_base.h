#ifndef __GW_BASE_H__
#define __GW_BASE_H__



#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "tuya_gw_init_api.h"
#include "smart_frame.h"

#ifdef __cplusplus
    extern "C" {
#endif


/***********************************************************
*  Function: gw_register_gw_cbs
*  Input: cbs
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
VOID gw_register_gw_cbs(IN CONST TY_IOT_GW_CBS_S *gw_cbs);

TY_IOT_GW_CBS_S *gw_base_gw_cbs_get(VOID);

//smart_frame.h->sf_send_gw_dev_cmd
typedef OPERATE_RET (*GW_SF_SEND_GW_DEV_CMD)(IN SF_GW_DEV_CMD_S *gd_cmd);

typedef OPERATE_RET (*GW_SF_SUBDEV_REG_CB)(IN SF_SUBDEV_HANDLE_CB_S *subdev_cbs);


typedef struct {
    GW_SF_SEND_GW_DEV_CMD gw_sf_send_gw_dev_cmd;
    GW_SF_SUBDEV_REG_CB gw_subdev_register_cb;    
}GW_SF_CBS_S;

//smart_frame接口注册
VOID gw_register_gw_sf_cbs(IN CONST GW_SF_CBS_S *cbs);

//smart_frame接口获取
GW_SF_CBS_S *gw_sf_cbs_get(VOID);


OPERATE_RET gw_base_module_init(VOID);

#ifdef __cplusplus
} // extern "C"
#endif

#endif  // __GW_BASE_H__

