/*****************************************************************
*@brief     tuya_ble_host.h
*           蓝牙低功耗host接口   
*@author    liuyi
*@date      2020/7/14 
*@version   1.0.0
*
*****************************************************************/

#ifndef _TUYA_BLE_HOST_H
#define _TUYA_BLE_HOST_H

#include "tuya_cloud_types.h"
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif




typedef struct {
    uint8_t flag; 
    uint8_t addr[6];
    uint8_t addr_type;
    uint8_t retry_time;
}ST_BLE_CONNECT_ADDR;

/**
 * @brief ble 端口初始化
 */
VOID tuya_ble_host_port_int(const char *port);

/**
 * @brief ble 关闭端口
 */ 
VOID tuya_ble_host_port_deinit(const char *port);

/**
 * @brief ble 重置ncp的数据
 */ 
VOID tuya_ble_host_reset();

/**
 * @brief ble 设置底层广播包过滤机制
 */ 
VOID tuya_ble_host_set_adv_filter(uint8_t enable);

/**
 * @brief 设置蓝牙网关设备名称 
 */
VOID tuya_ble_host_set_device_name(char *name, int len);

/**
 * @brief 设置广播数据
 */
OPERATE_RET tuya_ble_host_set_adv(unsigned int adv_len, unsigned char *adv_data);

/**
 * @brief 设置扫描响应数据
 */
OPERATE_RET tuya_ble_host_set_scan_rsp(unsigned int scan_len, unsigned char *scan_data);

void tuya_ble_host_add_list(uint8_t *mac);
void tuya_ble_host_del_list(uint8_t idx);
uint8_t tuya_ble_host_get_list(uint8_t *mac, uint8_t *idx, uint8_t *handle, uint8_t *tx_handle);
uint8_t tuya_ble_host_get_list_mac(uint8_t *mac, uint8_t *addr_type, uint8_t *idx, uint8_t handle);
void tuya_ble_host_update_list_handle(uint8_t *mac, uint8_t handle, uint8_t addr_type);
void tuya_ble_host_update_list_tx_handle(uint8_t *mac, uint8_t handle, uint8_t tx_handle);
uint8_t tuya_ble_host_check_list();
void tuya_ble_host_disconnect_ble_list();

OPERATE_RET tuya_ble_host_gap_disconnect();
/**
 * @brief 连接 
 */
OPERATE_RET tuya_ble_host_connect(unsigned char *mac, unsigned int type);

/**
 * @brief 断开连接 
 */
OPERATE_RET tuya_ble_host_disconnect(unsigned char *mac);

/**
 * @brief 发送数据 
 */
OPERATE_RET tuya_ble_host_send_data(int type, unsigned char *mac, unsigned char *data, unsigned int len);

/**
 * @brief ble 重置广播数据和扫描响应数据
 */
OPERATE_RET tuya_ble_host_reset_adv(unsigned int adv_len, unsigned char *adv_data, unsigned int scan_len, unsigned char *scan_data);

/**
 * @brief ble 开始广播
 */
OPERATE_RET tuya_ble_host_start_adv();

/**
 * @brief ble 停止广播
 */
OPERATE_RET tuya_ble_host_stop_adv();

/** 
 * @brief ble 开始扫描产测接口
 */
OPERATE_RET tuya_ble_host_test_start_scan();

/** 
 * @brief ble 停止扫描产测接口
 */
OPERATE_RET tuya_ble_host_test_stop_scan();

/** 
 * @brief ble 开始扫描
 */
OPERATE_RET tuya_ble_host_start_scan();

/** 
 * @brief ble 停止扫描
 */
OPERATE_RET tuya_ble_host_stop_scan();

/** 
 * @brief ble 获取信号强度
 */
OPERATE_RET tuya_ble_host_get_rssi();

/** 
 * @brief ble 获取蓝牙固件版本号
 */
OPERATE_RET tuya_ble_host_get_version(char *version);

int tuya_ble_host_ncp_is_exist();

void tuya_ble_host_system_txpower();
void tuya_ble_host_advertise_txpower();


#ifdef __cplusplus
}
#endif

#endif