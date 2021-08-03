/**
 * @file      tuya_ble_mesh_ctrl.h
 * @brief     芯科蓝牙低功耗底层接口基础上封装的涂鸦蓝牙低功耗接口
 *            用于管理mesh的子设备
 * @copyright Copyright(C),2018-2020, 涂鸦科技 www.tuya.com
 * @author    liuyi
 * @date      2020/8/21 
 * @version   1.0.0
 *
 */


#ifndef _TUYA_BLE_MESH_CTRL_H
#define _TUYA_BLE_MESH_CTRL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes *********************************************************** */
// #include "tuya_basic_types.h"
#include "host_gecko.h"
#include "board.h"

void tuya_convert_to_tuyamac(uint8_t *mac);
void tuya_mesh_ctrl_init();
void tuya_mesh_event_unprov_beacon(struct gecko_msg_mesh_prov_unprov_beacon_evt_t* evt);
void tuya_mesh_cmd_prov_info(uint8_t *mac, uint16_t addr, uint8_t *uuid);
void tuya_mesh_event_provisioned(uint8_t *uuid);
void tuya_mesh_event_dcd_data(uint32_t handle, bal_mesh_event_composition_data_status_t *p_composition_data, uint8_t *p_data, uint8_t len);
void tuya_mesh_event_dcd_data_end(uint32_t handle);
void tuya_mesh_event_appkey(uint32_t handle, uint16_t result);
void tuya_mesh_event_bind(uint32_t handle);
void tuya_mesh_clear_mesh_node();
void __add_failed_unprov_beacon(uint8_t *uuid);
// void tuya_save_failed_unprov_beacon(uint8_t *uuid);

#ifdef __cplusplus
}
#endif

#endif