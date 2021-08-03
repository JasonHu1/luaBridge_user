/*****************************************************************
*@brief     tuya_ble_mesh_host.h
*           蓝牙mesh host接口   
*@author    liuyi
*@date      2020/7/22 
*@version   1.0.0
*
*****************************************************************/

#ifndef _TUYA_BLE_MESH_HOST_H
#define _TUYA_BLE_MESH_HOST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "tuya_cloud_types.h"
#include "tuya_bt_hal.h"
#include "host_gecko.h"

#define MAX_MESH_LIST_NUM 256

typedef enum {
  EN_MESH_HOST_IDLE = 0,
  EN_MESH_HOST_SCAN
}EN_MESH_HOST_STATE;

typedef struct{  
  uint32_t bind_flag;     //< 0 未使用 1 需要绑定 2 绑定中 3 绑定成功
  uint32_t ele_id;
  uint32_t model_id;
  uint32_t num;
}ELE_MODEL_ID;

typedef struct {
  uint32_t num;
  uint8_t b_enble[MAX_MESH_LIST_NUM];
  struct gecko_msg_mesh_prov_ddb_list_evt_t dev_list[MAX_MESH_LIST_NUM];
}ST_SUB_MESH_DEV;

void get_opcode_by_modelID(uint16_t model_id, uint8_t *p_opcode, uint8_t *p_opcode_len);

/**
 * @brief   涂鸦ble mesh添加mesh列表 
 */
void tuya_ble_mesh_host_add_list(uuid_128 *uuid, uint16_t addr, uint8_t elements);

/**
 * @brief   涂鸦ble mesh添加数据库 
 */
void tuya_ble_mesh_host_add_ddb(uint8_t *mac, uint8_t *device_key, uint16_t addr);

/**
 * @brief   涂鸦ble mesh删除数据库 
 */
void tuya_ble_mesh_host_del_ddb(uint16_t addr);

/**
 * @brief   涂鸦ble mesh初始化 
 */
OPERATE_RET tuya_ble_mesh_host_init();

/**
 * @brief   涂鸦ble mesh 广播模式
 */
OPERATE_RET tuya_ble_mesh_host_adv();

/**
 * @brief   涂鸦ble mesh 网关模式
 */
OPERATE_RET tuya_ble_mesh_host_gatt();

/**
 * @brief   涂鸦ble mesh 设置netkey、appkey
 */
OPERATE_RET tuya_ble_mesh_host_set_meshinfo(TUYA_BT_HAL_MESH_INFO_S *info);

/**
 * @brief     涂鸦ble mesh 设置状态
 * @param[in] state 参考 EN_MESH_HOST_STATE
 */
VOID tuya_ble_mesh_set_state(uint8_t state);

/**
 * @brief       涂鸦ble mesh 获取状态
 * @param[out]  state 参考 EN_MESH_HOST_STATE
 */
VOID tuya_ble_mesh_get_state(uint8_t *state);

/**
 * @brief   涂鸦ble mesh 开始扫描
 */
OPERATE_RET tuya_ble_mesh_host_start_scan();

/**
 * @brief   涂鸦ble mesh 停止扫描
 */
OPERATE_RET tuya_ble_mesh_host_stop_scan();

/**
 * @brief   涂鸦ble mesh 添加子设备
 */
OPERATE_RET tuya_ble_mesh_host_add(uint8_t dev_num, TUYA_BT_HAL_MESH_DEV_S *dev);

/**
 * @brief   涂鸦ble mesh 删除子设备
 */
OPERATE_RET tuya_ble_mesh_host_delete(uint8_t dev_num, TUYA_BT_HAL_MESH_DEV_S *dev);

/**
 * @brief   涂鸦ble mesh 删除子设备配置
 */
OPERATE_RET tuya_ble_mesh_host_del_config(uint8_t dev_num, TUYA_BT_HAL_MESH_DEV_S *dev);

/**
 * @brief   涂鸦ble mesh 同步子设备配置
 */
OPERATE_RET tuya_ble_mesh_host_sync_config(uint8_t dev_num, TUYA_BT_HAL_MESH_DEV_S *dev);

/**
 * @brief   涂鸦ble mesh 发送数据到子设备
 */
OPERATE_RET tuya_ble_mesh_host_send_data(uint16_t dev_addr, uint16_t ele_idx, uint8_t *data, uint32_t len, TUYA_BT_HAL_DATA_INFO_T *data_info);

/**
 * @brief   涂鸦ble mesh 子设备订阅后上报status
 */
void tuya_ble_mesh_host_update_sub(uint32_t handle, uint16_t result);

#ifdef __cplusplus
}
#endif

#endif