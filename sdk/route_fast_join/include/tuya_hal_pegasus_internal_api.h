/**
 * @file tuya_hal_pegasus_internal_api.h
 * @brief sdk api
 * @version 1.0
 * @date 2021-7-16
 * 
 * @copyright Copyright (c) tuya.inc 2021
 * 
 */

#ifndef TUYA_HAL_PEGASUS_INTERNAL_API_H
#define TUYA_HAL_PEGASUS_INTERNAL_API_H

#include <stdint.h>
#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_types.h"
#include "tuya_cloud_error_code.h"
#include "uni_log.h"
#include "tuya_hal_network.h"

#ifdef __cplusplus
extern "C" {
#endif

int tuya_hal_pegasus_get_ssid_passwd(uint8_t *ssid, int32_t slen, uint8_t *passwd, int32_t plen);
int tuya_hal_pegasus_get_mac(NW_MAC_S *mac);

typedef void (*PEGASUS_REV_MGNT_CB)(uint8_t *vsie, uint32_t vsie_len, NW_MAC_S *src_mac, NW_MAC_S *dst_mac);
int tuya_hal_pegasus_register_recv_mgnt_callback(bool enable, PEGASUS_REV_MGNT_CB recv_cb, uint8_t *tuya_oui);

int tuya_hal_pegasus_beacon_config(bool en, uint8_t *vsie, uint32_t vsie_len, uint32_t timeout);
int tuya_hal_pegasus_send_probe_response_mgnt(const uint8_t *vsie,  
                                              const uint32_t vsie_len, 
                                              const uint8_t  *ssid, 
                                              NW_MAC_S       *srcmac, 
                                              NW_MAC_S       *dstmac);
int tuya_hal_pegasus_stop(void);

#ifdef __cplusplus
}
#endif
#endif /* TUYA_HAL_PEGASUS_INTERNAL_API_H */
