 /*
 util_engr.h
 Copyright(C),2018-2020, 涂鸦科技 www.tuya.comm
 */
#ifndef _GW_ENGR_H
#define _GW_ENGR_H

#include "tuya_cloud_types.h"
#include "ty_cJSON.h"
#include "tuya_cloud_com_defs.h"
#include "gw_intf.h"

#include "tuya_gw_engineer_api.h"

#ifdef __cplusplus
 extern "C" {
#endif
#define ENGINEER_STAT   "engineer_stat"
typedef enum {
    ENGINEER_STAT_MIN = 0,
    ENGINEER_NEED_SYNC,
    ENGINEER_ALREADY_SYNC,
    ENGINEER_ALREADY_UPLOAD,    //upload cloud config
    ENGINEER_STAT_MAX,

} ENGINEER_STAT_E;              //engineer state


/*!
\typedef typedef VOID (*GW_SCE_PANEL_BIND_CB)(IN CONST CHAR_T *dev_id,IN CONST SCE_PANEL_S *sce_panel,IN CONST INT btn_num);
\brief 场景面板绑定通知回调

\param dev_id [in] 子设备ID
\param sce_panel [in] 场景相关操作
\param btn_num [in] 场景面板操作数
\return VOID
*/
#define GRP_LEN 5
#define SCE_LEN 3
#define SCE_NAME_LEN 4
#define MAX_BTN 9

/* tuya-sdk gateway callback functions */


//获取工程模式回调接口集合
GW_CBS_ENGR_S *engr_get_gw_cbs();

OPERATE_RET gw_engineer_init(IN CONST GW_CFG_S *cfg,IN CONST CHAR_T *product_key, IN CONST CHAR_T *firmware_key,\
                               IN CONST CHAR_T *sw_ver,IN CONST CHAR_T *dev_sw_ver,\
                               IN CONST DEV_TYPE_T tp,IN CONST GW_ATTACH_ATTR_T *attr,\
                               IN CONST UINT_T attr_num);

OPERATE_RET engr_gw_cntl_supply_init(IN CONST GW_CFG_S *cfg,IN CONST CHAR_T *product_key, IN CONST CHAR_T *firmware_key,\
                               IN CONST CHAR_T *sw_ver,IN CONST CHAR_T *dev_sw_ver,\
                               IN CONST DEV_TYPE_T tp,IN CONST GW_ATTACH_ATTR_T *attr,\
                               IN CONST UINT_T attr_num);

OPERATE_RET gw_engineer_active();

BOOL_T gw_engineer_upgrade_allow();

OPERATE_RET tuya_engr_iot_api_pre_handle_register_cb();

OPERATE_RET gw_engineer_init_pre();


#ifdef __cplusplus
}
#endif
#endif


