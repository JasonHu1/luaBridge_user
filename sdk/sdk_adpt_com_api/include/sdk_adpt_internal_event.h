/**
 * @file sdk_adpt_internal_event.h
 * @brief sdk adpt internal event
 * @version 1.0
 * @date 2021-7-16
 * 
 * @copyright Copyright (c) tuya.inc 2021
 * 
 */
#ifndef __SDK_ADPT_INTERNAL_EVENT_H__
#define __SDK_ADPT_INTERNAL_EVENT_H__

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
    extern "C" {
#endif

/**
 * @brief event type
 * 
 */
#define EVT_SDK_WIRD_NET_STAT         "evt.wired_stat"  // wired network status
#define EVT_SDK_WIFI_NET_STAT         "evt.wifi_stat"   // wifi network status
#define EVT_SDK_ACTIVE_STAT           "evt.active_stat"  // active status
#define EVT_SDK_UPGRADE               "evt.upgrade"      // upgrade event
#define EVT_SDK_RESET_STAT            "evt.reset_stat"   // reset event
#define EVT_SDK_SUB_DEV_UPGRADE       "evt.subdev_upg"   // sub-device upgrade event
#define EVT_SDK_SUB_DEV_RESET_STAT    "evt.subdev_rst"   // sub-device reset event
#define EVT_SDK_REBOOT                "evt.reboot"       // reboot event
#define EVT_SDK_INIT_STAT             "evt.init_stat"    // init status
#define EVT_SDK_ACTIVE_URL            "evt_act_url"      // active URL notification event.

/**
 * @brief the event sub-device upgrade msg
 * 
 */
typedef struct {
    CHAR_T *dev_id;
    FW_UG_S *fw;
} EVT_SUBDEV_UPG_MSG_t;

/**
 * @brief the event sub-device reset msg
 * 
 */
typedef struct {
    CHAR_T *dev_id;
    DEV_RESET_TYPE_E reset_type;
} EVT_SUBDEV_RESET_MSG_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __SDK_ADPT_INTERNAL_EVENT_H__ */
