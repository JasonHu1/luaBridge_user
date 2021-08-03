/**
 * @file tuya_router_api.h
 * @brief sdk router api
 * @version 1.0
 * @date 2021-7-16
 * 
 * @copyright Copyright (c) tuya.inc 2021
 * 
 */
#ifndef __TUYA_ROUTER_API__
#define __TUYA_ROUTER_API__

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TY_ROUTER_LOGIN_STR_MAX      64 // ssid: 0 - 32, pwd: 8 - 63
#define TY_ROUTER_DEV_NAME_MAX       64
#define TY_ROUTER_MAC_STR_LEN        18

#ifndef WIFI_SSID_LEN
#define WIFI_SSID_LEN 32    // tuya sdk definition WIFI SSID MAX LEN
#endif
#ifndef WIFI_PASSWD_LEN
#define WIFI_PASSWD_LEN 64  // tuya sdk definition WIFI PASSWD MAX LEN
#endif

/**
 * @brief WIFI type
 * 
 */
typedef BYTE_T TY_WIFI_TYPE;
#define TY_WIFI_TYPE_2_4G           1
#define TY_WIFI_TYPE_5G             2

/**
 * @brief WIFI signal strength
 * 
 */
typedef BYTE_T TY_WIFI_SIG_STRENGTH;
#define TY_WIFI_SIG_LOW             1
#define TY_WIFI_SIG_MID             2
#define TY_WIFI_SIG_HIGH            3


/**
 * @brief router cmd type
 * 
 */
typedef enum {
    TY_ROUTER_CMD_GET_ONLINE_LIST = 1,   // get online device list
    TY_ROUTER_CMD_GET_BLACK_LIST = 2,    // get black device list
    TY_ROUTER_CMD_GET_WIFI_LIST = 3,     // get available AP list
    TY_ROUTER_CMD_INVALD                 // invalid cmd
} TY_ROUTER_CMD_E;

/**
 * @brief station cmd type
 * 
 */
typedef enum {
    TY_STA_CMD_ALLOW_NET = 1,      // station whether allowed network
    TY_STA_CMD_SPEED_LIMIT = 2,    // station whether speed limt
    TY_STA_CMD_UP_LIMIT = 3,       // the limit of upload speed
    TY_STA_CMD_DOWN_LIMIT = 4,     // the limit of download speed
    TY_STA_CMD_GET_ALL_CONFIG = 5, // get all config
    TTY_STA_CMD_INVALD             // invalid cmd
} TY_ROUTER_STA_CMD_E;

/**
 * @brief station configure
 * 
 */
typedef struct {
    BOOL_T allow;        // allow network
    BOOL_T limit;        // the speed limit
    UINT_T up_limit;     // the max limit of upload speed
    UINT_T down_limit;   // the max limt of download speed
} TUYA_ROUTER_STA_CONF_S;

/**
 * @brief AP list info
 * 
 */
typedef struct {
    CHAR_T ssid[TY_ROUTER_LOGIN_STR_MAX];
    BOOL_T b_encrypted;
    TY_WIFI_SIG_STRENGTH signal_strength; // 1-2.4G, 2-5G
} TUYA_ROUTER_WIFI_LIST_S;

/**
 * @brief hostspot info
 * 
 */
typedef struct {
    TY_WIFI_TYPE wifi_types;
    CHAR_T ssid[TY_ROUTER_LOGIN_STR_MAX];
    CHAR_T pwd[TY_ROUTER_LOGIN_STR_MAX];
} TUYA_ROUTER_HOTSPOT_S;

/**
 * @brief device info under the router/repeater
 * 
 */
typedef struct {
    CHAR_T dev_name[TY_ROUTER_DEV_NAME_MAX];
    CHAR_T mac[TY_ROUTER_MAC_STR_LEN];
    TY_WIFI_TYPE wifi_types; // 1-2.4G, 2-5G
} TUYA_ROUTER_DEV_LIST_S;

/**
 * @brief password type
 * 
 */
typedef enum {
    TY_ROUTER_PWD_INVALID = 0,
    TY_ROUTER_PWD_2_4G = 1,
    TY_ROUTER_PWD_5G = 2,
} TUYA_ROUTER_PWD_E;

/**
 * @brief brand connection type
 * 
 */
typedef BYTE_T BRAND_CONN_TYPE_T;
#define BRAND_CONN_TYPE_PPPOE          0   // pppoe
#define BRAND_CONN_TYPE_DHCP           1   // dhcp
#define BRAND_CONN_TYPE_STATIC_IP      2   // static IP
#define BRAND_CONN_TYPE_WIRED_REPEATER 3   // wired repeater
#define BRAND_CONN_TYPE_WIFI_REPEATER  4   // WIFI repeater
#define BRAND_CONN_TYPE_INVALID        5   // invalid brand conntion type

/**
 * @brief pppoe account
 * 
 */
typedef struct {
    CHAR_T account[WIFI_SSID_LEN + 1];
    CHAR_T pwd[WIFI_PASSWD_LEN + 1];
} PPPOE_INFO_T;

/**
 * @brief hostspot info
 * 
 */
typedef struct {
    CHAR_T ap_ssid[WIFI_SSID_LEN+1]; // ap ssid info
    CHAR_T ap_passwd[WIFI_PASSWD_LEN+1]; // ap passwd info
} WIFI_INFO_T;

/**
 * @brief static IP info
 * 
 */
typedef struct {
    char ip[16];    /* ip addr:  xxx.xxx.xxx.xxx  */
    char mask[16];  /* net mask: xxx.xxx.xxx.xxx  */
    char gw[16];    /* gateway:  xxx.xxx.xxx.xxx  */
    char primary_dns[16];
    char secondary_dns[16];;
} STATIC_IP_T;

/**
 * @brief brand connecton setting
 * 
 */
typedef struct {
    BRAND_CONN_TYPE_T brand_conn_type; // see BRAND_CONN_TYPE_T
    PPPOE_INFO_T pppoe_info;           // see PPPOE_INFO_T
    STATIC_IP_T  static_ip_info;       // see STATIC_IP_T
    WIFI_INFO_T wifi_info;             // see WIFI_INFO_T
} BRAND_CONN_SETTING_INFO;

/**
 * @brief Handler to process cmd
 * 
 * @param[out] VOID
 */
typedef VOID (*TY_ROUTER_CMD_HANDLE_CB)(IN CONST TY_ROUTER_CMD_E cmd);

/**
 * @brief Handler to process getting ssid & passwod info connected hotspot 
 * 
 * @param[out] VOID
 */
typedef VOID (*TY_ROUTER_GET_SOURCE_CB)(VOID);

/**
 * @brief Handler to process connecting hotspot with ssid & password
 * 
 * @param[out] VOID
 */
typedef VOID (*TY_ROUTER_SET_SOURCE_CB)(IN CONST CHAR_T *ssid, IN CONST CHAR_T *pwd);

/**
 * @brief Handler to process need to report hotspot info of own router/repeater.
 * 
 * @param[out] VOID
 */
typedef VOID (*TY_ROUTER_GET_HOTSPOT_CB)(VOID);

/**
 * @brief Handler to process setting hotspot of own router/repeater
 * 
 * @param[out] VOID
 */
typedef VOID (*TY_ROUTER_SET_HOTSPOT_CB)(IN CONST TUYA_ROUTER_HOTSPOT_S *p_hotspot, IN CONST USHORT_T num);

/**
 * @brief Handler to process station cmd
 * 
 * @param[out] VOID
 */
typedef VOID (*TY_ROUTER_STA_CMD_CB)(IN CONST TY_ROUTER_STA_CMD_E cmd, IN CONST CHAR_T *mac, IN CONST UINT_T value);

/**
 * @brief Handler to query WIFI password
 * 
 * @param[out] VOID
 */
typedef VOID (*TY_ROUTER_QUERY_PWD_CB)(IN CONST TUYA_ROUTER_PWD_E type);

/**
 * @brief Handler to process set WIFI password
 * 
 * @param[out] VOID
 */
typedef VOID (*TY_ROUTER_SET_PWD_CB)(IN CONST TUYA_ROUTER_PWD_E type, IN CONST CHAR_T *pwd);

/**
 * @brief Handler to process get brand connection info.
 * 
 * @param[out] VOID
 */
typedef VOID (*TY_ROUTER_GET_CONN_TYPE_CB)(VOID);

/**
 * @brief Handler to process set brand connection.
 * 
 * @param[out] VOID
 */
typedef VOID (*TY_ROUTER_SET_CONN_TYPE_CB)(IN CONST BRAND_CONN_SETTING_INFO *setting);

/**
 * @brief callback functions fo router/repeatr
 * 
 */
typedef struct {
    TY_ROUTER_CMD_HANDLE_CB cmd_handle_cb;                   // cmd handler
    TY_ROUTER_GET_SOURCE_CB get_source_cb;                   // get ssid & passwod info connected hotspot source.
    TY_ROUTER_SET_SOURCE_CB set_source_cb;                   // to connect hostpot source
    TY_ROUTER_GET_HOTSPOT_CB get_hotspot_cb;                 // get hotspot of own router/repeater
    TY_ROUTER_SET_HOTSPOT_CB set_hotspot_cb;                 // setting hotspot of own router/repeater
    TY_ROUTER_QUERY_PWD_CB   router_query_pwd_cb;             // query WIFI passowrd
    TY_ROUTER_SET_PWD_CB     router_set_pwd_cb;               // set WIFI password

    TY_ROUTER_GET_CONN_TYPE_CB router_get_brand_conn_type_cb; // get connection type callback
    TY_ROUTER_SET_CONN_TYPE_CB router_set_brand_conn_type_cb; // set connection type callback
} TUYA_ROUTER_CBS_S;

/**
 * @brief the stations handlers callback functions.
 * 
 */
typedef struct {
    TY_ROUTER_STA_CMD_CB     sta_cmd_cb; // station control cmd handler
} TUYA_ROUTER_STA_CBS_S;

/** 
 * @brief: report online device list under the router/repeater.
 *
 * @param[in] dev_count: device num
 * @param[in] p_list: online device list, see TUYA_ROUTE_DEV_LIST_S
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_rept_online_list(IN CONST USHORT_T dev_count, 
                                        IN CONST TUYA_ROUTER_DEV_LIST_S *p_list);
/** 
 * @brief: report available WIFI AP list.
 *
 * @param[in] dev_count: device num
 * @param[in] p_list: available AP list, see TUYA_ROUTE_WIFI_LIST_S
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_rept_wifi_list(IN CONST USHORT_T dev_count, 
                                      IN CONST TUYA_ROUTER_WIFI_LIST_S *p_list);
/** 
 * @brief: report info(ssid & passd) connected by the router/repeater
 *
 * @param[in] ssid: ssid string.
 * @param[in] pwd:  password sring.
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_rept_source(IN CONST CHAR_T *ssid, IN CONST CHAR_T *pwd);

/** 
 * @brief: report hotspot info(such as 2.4G/5G, ssid, password) of own router/repeater.
 *
 * @param[in] p_hotspot: hotspot info
 * @param[in] num: num of hotspot
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_rept_hotspot(IN CONST TUYA_ROUTER_HOTSPOT_S *p_hotspot, IN CONST USHORT_T num);

/** 
 * @brief: set whether allowed internet service for the specified device.
 *
 * @param[in] mac: MAC addr of the specified device
 * @param[in] allow: whether the specified device allowed internet servce.
 * @param[in] sta_dpid: station DP ID
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_rept_sta_allow_net(IN CONST CHAR_T *mac, 
                                          IN CONST BOOL_T allow, 
                                          IN CONST UINT_T sta_dpid);

/** 
 * @brief: set the speed limit of download/upload for the specified device
 *
 * @param[in] mac: MAC addr of the specified device
 * @param[in] limit: whether limit the speed of upload/download.
 * @param[in] sta_dpid: station DP ID
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_rept_sta_limit(IN CONST CHAR_T *mac, 
                                      IN CONST BOOL_T limit, 
                                      IN CONST UINT_T sta_dpid);

/** 
 * @brief: repot the max limit of upload for the specified device..
 *
 * @param[in] mac: MAC addr of the specified device
 * @param[in] limit: the max limit of upload
 * @param[in] sta_dpid: station DP ID
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_rept_sta_up_limit(IN CONST CHAR_T *mac, 
                                         IN CONST UINT_T limit, 
                                         IN CONST UINT_T sta_dpid);

/** 
 * @brief: report the max limit of download for the specified device.
 *
 * @param[in] mac: MAC addr of the specified device
 * @param[in] limit: the max limit of download
 * @param[in] sta_dpid: station DP ID
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_rept_sta_down_limit(IN CONST CHAR_T *mac, 
                                           IN CONST UINT_T limit, 
                                           IN CONST UINT_T sta_dpid);

/** 
 * @brief: report station info of the specified device.
 *
 * @param[in] mac: MAC addr of the specified device
 * @param[in] config: statin info, including whether allowed network, max limit of upload, max limit of download, see TUYA_ROUTE_STA_CONF_S
 * @param[in] sta_dpid: station DP ID. 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_rept_sta_all(IN CONST CHAR_T *mac, 
                                    IN CONST TUYA_ROUTER_STA_CONF_S *config, 
                                    IN CONST UINT_T sta_dpid);

/** 
 * @brief: station data parse.
 *
 * @param[in] data: from obj dp of STA_DPID
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_sta_data_parse(IN CONST CHAR_T *data);

/** 
 * @brief: service init API. register callback functions.
 *
 * @param[in] p_router_cbs: router/repeater cmd callback functions.
 * @param[in] p_sta_cbs:  the station control cmd callback functions.
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_svc_init(IN CONST TUYA_ROUTER_CBS_S *p_router_cbs, 
                                    IN CONST TUYA_ROUTER_STA_CBS_S *p_sta_cbs);

/** 
 * @brief: report the password of WIFI.
 *
 * @param[in] type: WIFI type, see TUYA_ROUTER_PWD_E
 * @param[in] pwd:  password stirng.
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_rept_pwd(IN CONST TUYA_ROUTER_PWD_E type, IN CONST CHAR_T *pwd);

/** 
 * @brief: report the router's supporting brand connection type.
 *
 * @param[in] error_code: error code, if OK, set 0, if FAIL, set 1.
 * @param[in] data: string array. Currently support "PPPOE","DHCP","STATIC_IP","WIRED_REPEAT", "WIFI_REPEAT"
 * @param[in] data_num: the length of error info string.
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_brand_conn_type_resp(CHAR_T error_code, CONST CHAR_T *data[], UCHAR_T data_num);

/** 
 * @brief: report the status code after setting the brand connection
 *
 * @param[in] error_code: error code, if OK, set 0, if FAIL, set 1.
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_router_brand_conn_setting_resp(CHAR_T error_code);

/** 
 * @brief: set ext network status of router/repeater
 *
 * @param[in] online: If internet available, set TRUE, otherwise set FALSE.
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
VOID tuya_router_set_ext_net_stat(BOOL_T online);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /*__TUYA_ROUTER_API__ */
