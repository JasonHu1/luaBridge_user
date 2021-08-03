#ifndef __TUYA_MESH_SW_API_H
#define __TUYA_MESH_SW_API_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "tuya_device_gateway_switch.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef BYTE_T TUYA_MESH_GW_ST_T;
#define TUYA_MESH_ST_UNCFG      0   // 未配置
#define TUYA_MESH_ST_DEV        1   // 子设备
#define TUYA_MESH_ST_GW         2   // 网关

typedef struct {
    CHAR_T dev_id[GW_ID_LEN + 1];
} TUYA_MESH_NET_INFO_S;

VOID tuya_mesh_sw_subdev_ota_end(VOID);
BOOL_T tuya_mesh_sw_is_subdev_ota(VOID);
VOID tuya_mesh_sw_reset(VOID);
TUYA_MESH_GW_ST_T tuya_mesh_sw_sto_get_stat(VOID);
OPERATE_RET tuya_mesh_sw_net_info_read(TUYA_MESH_NET_INFO_S *mesh_net_info);
OPERATE_RET tuya_mesh_sw_base_init(VOID);
OPERATE_RET tuya_mesh_sw_send_gw_busy_notify(USHORT_T time);

#ifdef __cplusplus
}
#endif

#endif



