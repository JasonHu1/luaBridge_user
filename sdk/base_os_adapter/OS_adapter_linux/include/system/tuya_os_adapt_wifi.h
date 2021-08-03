#ifndef __TUYA_OS_ADAPT_WIFI_H__
#define __TUYA_OS_ADAPT_WIFI_H__


#include <stdbool.h>
#include <stdint.h>
#include "tuya_os_adapter.h"


#ifdef __cplusplus
extern "C" {
#endif


OPERATE_RET tuya_adapter_wifi_all_ap_scan(AP_IF_S **ap_ary, UINT_T *num);
OPERATE_RET tuya_adapter_wifi_assign_ap_scan(CONST SCHAR_T *ssid, AP_IF_S **ap);
OPERATE_RET tuya_adapter_wifi_release_ap(AP_IF_S *ap);
OPERATE_RET tuya_adapter_wifi_set_cur_channel(CONST UCHAR_T chan);
OPERATE_RET tuya_adapter_wifi_get_cur_channel(UCHAR_T *chan);
OPERATE_RET tuya_adapter_wifi_sniffer_set(CONST BOOL_T en, CONST SNIFFER_CALLBACK cb);
OPERATE_RET tuya_adapter_wifi_get_ip(CONST WF_IF_E wf, NW_IP_S *ip);
OPERATE_RET tuya_adapter_wifi_set_mac(CONST WF_IF_E wf, CONST NW_MAC_S *mac);
OPERATE_RET tuya_adapter_wifi_get_mac(CONST WF_IF_E wf, NW_MAC_S *mac);
OPERATE_RET tuya_adapter_wifi_set_work_mode(CONST WF_WK_MD_E mode);
OPERATE_RET tuya_adapter_wifi_get_work_mode(WF_WK_MD_E *mode);
OPERATE_RET tuya_adapter_wifi_ap_start(CONST WF_AP_CFG_IF_S *cfg);
OPERATE_RET tuya_adapter_wifi_ap_stop(VOID_T);
OPERATE_RET tuya_adapter_wifi_get_connected_ap_info_v2(FAST_WF_CONNECTED_AP_INFO_V2_S **fast_ap_info);
OPERATE_RET tuya_adapter_wifi_fast_station_connect_v2(CONST FAST_WF_CONNECTED_AP_INFO_V2_S *fast_ap_info);
OPERATE_RET tuya_adapter_wifi_station_connect(CONST SCHAR_T *ssid, CONST SCHAR_T *passwd);
OPERATE_RET tuya_adapter_wifi_station_disconnect(VOID_T);
OPERATE_RET tuya_adapter_wifi_station_get_conn_ap_rssi(SCHAR_T *rssi);
OPERATE_RET tuya_adapter_wifi_get_bssid(UCHAR_T *mac);
OPERATE_RET tuya_adapter_wifi_station_get_status(WF_STATION_STAT_E *stat);
OPERATE_RET tuya_adapter_wifi_set_country_code(CONST COUNTRY_CODE_E ccode);
OPERATE_RET tuya_adapter_wifi_send_mgnt(CONST UCHAR_T *buf, CONST UINT_T len);
OPERATE_RET tuya_adapter_wifi_register_recv_mgnt_callback(CONST BOOL_T enable, CONST WIFI_REV_MGNT_CB recv_cb);
OPERATE_RET tuya_adapter_wifi_set_lp_mode(CONST BOOL_T en, CONST UCHAR_T dtim);
BOOL_T      tuya_adapter_wifi_rf_calibrated(VOID_T);

OPERATE_RET tuya_os_adapt_reg_wifi_intf(void);


#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif 

