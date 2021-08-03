
/**
 * @file tuya_pegasus_api.h
 * @brief sdk api
 * @version 1.0
 * @date 2021-7-16
 * 
 * @copyright Copyright (c) tuya.inc 2021
 * 
 */
#ifndef TUYA_PEGASUS_API_H
#define TUYA_PEGASUS_API_H

#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_types.h"
#include "tuya_cloud_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TUYA_VSIE_LEN_MAX           512
#define TUYA_GET_PROBE_INTR_DEF     500     //ms

/**
 * @brief pegasus event type
 * 
 */
typedef enum {
    TY_PEGASUS_START = 1,              // event pegasus start
    TY_PEGASUS_STOP = 2,               // event pegasus stop
    TY_PEGASUS_GET_PROBE_START = 3,    // event pegasus get probe start
    TY_PEGASUS_STOP_DICOVERY = 4,      // event pegasus stop discovery
    TY_PEGASUS_EVENT_INVALD            // event pegasus invalid
} TY_PEGASUS_EVENT_E;

/**
 * @brief frame type
 * 
 */
typedef enum {
    TY_FRAME_TP_BEACON = 1,
    TY_FRAME_TP_PROBE_REQ = 2,
    TY_FRAME_TP_PROBE_RESP = 3,
    TY_FRAME_TP_INVALD
} TY_FRAME_TYPE_E;

/**
 * @brief pegasus event callback function
 * 
 * @param[in] event: pegasus event
 */
typedef VOID (*TY_PEGASUS_EVENT_CB)(IN CONST TY_PEGASUS_EVENT_E event);

/**
 * @brief handler sending frame callback
 * 
 * @param[in] type device id of sub-device
 * @param[in] vsie reset type, see DEV_RESET_TYPE_E
 * @param[in] vsie_len reset type, see DEV_RESET_TYPE_E
 * @param[in] srcmac reset type, see DEV_RESET_TYPE_E
 * @param[in] dstmac reset type, see DEV_RESET_TYPE_E
 */
typedef OPERATE_RET (*TY_PEGASUS_SEND_FRAME_CB)(IN CONST TY_FRAME_TYPE_E type, IN CONST UINT8_T *vsie, 
                                                IN CONST UINT_T vsie_len, IN NW_MAC_S *srcmac, IN NW_MAC_S *dstmac);

/**
 * @brief Handler getting ssid & pwd callback
 * 
 * @param[in] ssid ssid 
 * @param[in] slen string length of ssid
 * @param[in] pwd password
 * @param[in] plen string length of password
 */                                           
typedef OPERATE_RET (*TY_PEGASUS_GET_SSID_PWD_CB)(OUT UINT8_T *ssid, IN INT_T slen, OUT UINT8_T *pwd, IN INT_T plen);

/**
 * @brief Handler getting MAC addr callback
 * 
 * @param[in] mac  MAC addr, see NW_MAC_S
 */
typedef OPERATE_RET (*TY_PEGASUS_GET_MAC_CB)(OUT NW_MAC_S *mac);

/**
 * @brief Handler sending oui data.
 * 
 * @param[in] oui oui data
 * @param[in] oui_len the lenght of oui data
 */
typedef OPERATE_RET (*TY_PEGASUS_SET_OUI_CB)(IN BYTE_T *oui, IN BYTE_T oui_len);

/**
 * @brief pegasus callback functions
 * 
 */
typedef struct {
    TY_PEGASUS_EVENT_CB event_cb;
    TY_PEGASUS_SEND_FRAME_CB send_frame_cb;
    TY_PEGASUS_GET_SSID_PWD_CB get_ssid_pwd_cb;
    TY_PEGASUS_GET_MAC_CB get_mac_cb;
    TY_PEGASUS_SET_OUI_CB set_oui_cb;
} TUYA_PEGASUS_CBS_S;

/** 
 * @brief: pegasus service init API.
 *
 * @param[in] p_cbs: user need to reigister pegasus callback functions.
 * @param[in] probe_intr_ms: probe interval time
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h   
 */
OPERATE_RET tuya_pegasus_svc_init(TUYA_PEGASUS_CBS_S *p_cbs, UINT_T probe_intr_ms);

#ifdef __cplusplus
} /* __cplusplus */
#endif

#endif /* TUYA_PEGASUS_API_H */
