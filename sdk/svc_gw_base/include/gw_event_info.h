#ifndef __GW_EVENT_INFO_H__
#define __GW_EVENT_INFO_H__


#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"


#ifdef __cplusplus
    extern "C" {
#endif


/*网关故障替换事件*/
//事件描述
#define GW_EVT_DESC_FAULT_REPLACE            "gw_flt_rpl"

//事件名 备份
#define GW_EVT_NAME_CONFIG_BACK_UP           "fr.back.up"

//事件名 数据更新完成
#define GW_EVT_NAME_SYNC_DONE           "fr.sync.done"  // 业务数据同步完成
#define GW_EVT_NAME_REPLACE             "fr.conf.rpl"   // 配置回滚


/******工程模式事件相关*******/
//事件描述，工程
#define GW_EVT_DESC_ENGINEER            "gw_engineer"   // 工程事件
//事件名
#define GW_EVT_ENGR_SUBDEV_BIND         "eng.dev.bind"  // 工程模式子设备绑定
#define GW_EVT_ENGR_SUBDEV_UNBIND       "eng.dev.unbind"  // 工程模式子设备移除
typedef struct {
    UINT_T fr_type;
    UINT_T ret_code;
    BYTE_T *data;
    UINT_T len;
}GW_EVT_ENGR_REPORT_DATA;
#define GW_EVT_ENGR_DATA_REPORT         "eng.da.report"  // 工程模式数据上报


/******设备schema和云端同步完成*******/
#define GW_EVT_SCHEMA_SYNC_DONE          "gw_sch_sync"   // 设备schema和云端同步完成

#define GW_EVT_ADD_DEV_NOTIFY           "gw.add.notify"    // 子设备入网通知

#define GW_EVT_MESH_KEY_SET             "gw.mesh.key.set"   //动态mesh网关设置mesh key

typedef struct {
    CHAR_T *dev_id;
} EVENT_BLE_MESH_SUBDEV_BIND;
typedef struct {
    CHAR_T *dev_id;
} EVENT_SUBDEV_BIND;
typedef struct {
    CHAR_T *dev_id;
} EVENT_SUBDEV_UNBIND;
//事件描述
#define GW_EVT_SUBDEV_DESC                  "subdev"
//事件名
#define GW_EVT_SUBDEV_BIND                  "dev.bind"          // 子设备绑定
#define GW_EVT_SUBDEV_UNBIND                "dev.unbind"        // 子设备移除
#define GW_EVT_BLE_MESH_SUBDEV_BIND         "sig.ble.bind"      // 子设备拖拽绑定成功

/**
 * @brief 网关子设备群组添加成功回调
 */
#define GW_SDK_EVENT_GRP_ADD "sub.grpadd"
typedef struct {
    CHAR_T* grp_id;
    CHAR_T* dev_id;
} EVENT_GRP_ADD_SUCCESS;


/******网关基线初始化事件*******/
#define GW_EVT_GW_BASE_RUN              "gw.base.run"  // 网关基线组件初始化完成



#ifdef __cplusplus
} // extern "C"
#endif

#endif  //

