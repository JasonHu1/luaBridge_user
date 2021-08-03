
#ifndef __TUYA_OS_ADAPT_WIRED_H__
#define __TUYA_OS_ADAPT_WIRED_H__


#include <stdbool.h>
#include <stdint.h>
#include "tuya_os_adapter.h"


#ifdef __cplusplus
extern "C" {
#endif


OPERATE_RET tuya_adapter_wired_get_nw_stat(GW_BASE_NW_STAT_T *stat);
// 获取有线网卡的ip地址
OPERATE_RET tuya_adapter_wired_get_ip(OUT NW_IP_S *ip);
// 硬件是否连接外网
BOOL_T tuya_adapter_wired_station_conn(VOID);
// 若硬件形态为wifi+有线模式，而且用户需要连接外部WIFI，那么需要实现连接WIFI回调函数，sdk内部会自动调用
OPERATE_RET tuya_adapter_wired_wifi_set_station_connect(IN CONST CHAR_T *ssid,IN CONST CHAR_T *passwd);
// 若硬件形态为wifi+有线模式，而且用户需要连接外部WIFI，则返回TRUE，否者返回FALSE
BOOL_T tuya_adapter_wired_wifi_need_cfg(VOID);
// 若硬件形态为wifi+有线模式，而且用户需要连接外部WIFI，则返回WIFI实际信号强度，否者返回99
OPERATE_RET tuya_adapter_wired_wifi_station_get_conn_ap_rssi(OUT SCHAR_T *rssi);
// 获取有线网卡的MAC地址
OPERATE_RET tuya_adapter_wired_get_mac(OUT NW_MAC_S *mac);
// 当前无需实现
OPERATE_RET tuya_adapter_wired_set_mac(IN CONST NW_MAC_S *mac);
OPERATE_RET tuya_adapter_wired_if_connect_internet(BOOL_T *status);

OPERATE_RET tuya_os_adapt_reg_wired_intf(void);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif 
