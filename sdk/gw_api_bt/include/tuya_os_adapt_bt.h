#ifndef __TUYA_OS_ADAPT_BT_H__
#define __TUYA_OS_ADAPT_BT_H__

#include "tuya_os_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif

OPERATE_RET tuya_adapter_bt_port_init(ty_bt_param_t *p);
OPERATE_RET tuya_adapter_bt_port_deinit(VOID);
OPERATE_RET tuya_adapter_bt_gap_disconnect(VOID);
OPERATE_RET tuya_adapter_bt_send(BYTE_T *data, UINT8_T len);
OPERATE_RET tuya_adapter_bt_adv_reset(tuya_ble_data_buf_t *adv, tuya_ble_data_buf_t *scan_resp);
OPERATE_RET tuya_adapter_bt_adv_start(VOID);
OPERATE_RET tuya_adapter_bt_adv_stop(VOID);
OPERATE_RET tuya_adapter_bt_get_rssi(SCHAR_T *rssi);
OPERATE_RET tuya_adapter_bt_scan_assign(INOUT ty_bt_scan_info_t *info);
OPERATE_RET tuya_adapter_bt_scan_init(IN TY_BT_SCAN_ADV_CB scan_adv_cb);
OPERATE_RET tuya_adapter_bt_scan_start(VOID_T);
OPERATE_RET tuya_adapter_bt_scan_stop(VOID_T);

OPERATE_RET tuya_os_adapt_reg_bt_intf(VOID);

#ifdef __cplusplus
}
#endif
#endif