/*
 * ipc_service_demo.h
 *Copyright(C),2017-2022, TUYA company www.tuya.comm
 *
 *FILE description:
  *
 *  Created on: 2021年7月26日
 *      Author: kuiba
 */

#include"ty_cJSON.h"
#include <stdio.h>
#include "tuya_cloud_types.h"
#include "tuya_ipc_api.h"

#ifndef TY_GW_ZIGBEE_EXT_SDK_OUTPUT_DIST_TY_GW_ZIGBEE_EXT_SDK_LINUX_UBUNTU_6_2_0_64BIT_3_0_1_BETA_249_DEMOS_DEMO_IPC_INCLUDE_IPC_SERVICE_DEMO_H_
#define TY_GW_ZIGBEE_EXT_SDK_OUTPUT_DIST_TY_GW_ZIGBEE_EXT_SDK_LINUX_UBUNTU_6_2_0_64BIT_3_0_1_BETA_249_DEMOS_DEMO_IPC_INCLUDE_IPC_SERVICE_DEMO_H_

typedef struct
{
    CHAR_T storage_path[IPC_STORAGE_PATH_LEN + 1];/**Path to save sdk cfg ,need to read and write, doesn't loss when poweroff */
    CHAR_T upgrade_file_path[IPC_STORAGE_PATH_LEN + 1];/*Path to save upgrade file when OTA upgrading*/
    CHAR_T sd_base_path[IPC_STORAGE_PATH_LEN + 1];/**SD Card Mount Directory */
    CHAR_T product_key[IPC_PRODUCT_KEY_LEN + 1]; /**< product key */
    CHAR_T uuid[IPC_UUID_LEN + 1]; /*UUID is the unique identification of each device */
    CHAR_T auth_key[IPC_AUTH_KEY_LEN + 1]; /*AUTHKEY is the authentication codes corresponding to UUID, one machine one code, paired with UUID.*/
    CHAR_T p2p_id[IPC_P2P_ID_LEN + 1]; /*p2p_id is no need to provide*/
    CHAR_T dev_sw_version[IPC_SW_VER_LEN + 1]; /*version of the software */
    UINT_T max_p2p_user;/*max num of P2P supports*/
}IPC_MGR_INFO_S;


OPERATE_RET tuya_ipc_sdk_service_init(ty_cJSON *js_tuya_cfg);
VOID tuya_ipc_sdk_service_mqtt_online_set();


#endif /* TY_GW_ZIGBEE_EXT_SDK_OUTPUT_DIST_TY_GW_ZIGBEE_EXT_SDK_LINUX_UBUNTU_6_2_0_64BIT_3_0_1_BETA_249_DEMOS_DEMO_IPC_INCLUDE_IPC_SERVICE_DEMO_H_ */
