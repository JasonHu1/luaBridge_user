#ifndef __TUYA_BT_HAL_H__
#define __TUYA_BT_HAL_H__

#include <stdint.h>
#include <stdbool.h>
#include "tuya_cloud_error_code.h"
// #include "tuya_basic_types.h"

#ifndef TY_BT_NET_KEY_LEN   
#define TY_BT_NET_KEY_LEN   16
#endif

#ifndef TY_BT_APP_KEY_LEN   
#define TY_BT_APP_KEY_LEN   16
#endif

#ifndef TY_BT_DEV_KEY_LEN   
#define TY_BT_DEV_KEY_LEN   16
#endif

#ifndef TY_BT_MAC_LEN   
#define TY_BT_MAC_LEN       6
#endif

#ifndef TY_MESH_UUID_LEN   
#define TY_MESH_UUID_LEN    16
#endif

/*
 * mesh key
 */
typedef struct{
    uint8_t netkey[TY_BT_NET_KEY_LEN];
    uint8_t appkey[TY_BT_APP_KEY_LEN];
    uint16_t local_addr;
}TUYA_BT_HAL_MESH_INFO_S;

/*
 * gateway work mode
 */
typedef enum{
	TUYA_BT_HAL_ADV_MESH    = 0x01,
	TUYA_BT_HAL_GATT_MESH   = 0x02,
	TUYA_BT_HAL_BLE_MASTER  = 0x04,
	TUYA_BT_HAL_BLE_SLAVE   = 0x08

}TUYA_BT_HAL_WORK_MODE_E;

/*
 * @brief Advertising report type.
*/
typedef enum{
    TUYA_BT_AD_TYPE_ADV_RSP         = 0x00,  // rsp + adv     
    TUYA_BT_AD_TYPE_ADV_ONLY        = 0x01,  // adv-only
    TUYA_BT_AD_TYPE_RSP_ONLY        = 0x02,  // rsp-only
    TUYA_BT_AD_TYPE_CONNECTABLE     = 0x04,  // Connectable advertising event type
    TUYA_BT_AD_TYPE_NOCONNECTABLE   = 0x08,  // Noconnectable advertising event type
    TUYA_BT_AD_TYPE_DIRECTED        = 0x10,  // Directed advertising event type
    TUYA_BT_AD_TYPE_UNDIRECTED      = 0x20,  // UnDirected advertising event type
    TUYA_BT_AD_TYPE_EXTENDED_PDU    = 0x40,  // For 5.0 using, IPC 5.0 Project >> Received an extended advertising set.
    TUYA_BT_AD_TYPE_RESERVED        = 0xff

}TUYA_BT_HAL_DEV_AD_TYPE_T;

/*
 * sub-device type
*/
typedef enum{
    TUYA_BT_HAL_NONE_DEV   = 0x00,
	TUYA_BT_HAL_BLE_DEV    = 0x10,
	TUYA_BT_HAL_UNPROV_DEV = 0x12,
	TUYA_BT_HAL_PROV_NODE  = 0x14,

    TUYA_BT_ADDR_RANDOM    = 0x40,  
    TUYA_BT_ADDR_PUBLIC    = 0x80,
}TUYA_BT_HAL_DEV_TYPE_T;

/*
 * ble or mesh scan callback struct
 */
typedef struct{
	uint8_t mac[TY_BT_MAC_LEN];
	uint8_t *adv_data;
	uint16_t adv_data_len; 
	int8_t  rssi;

    TUYA_BT_HAL_DEV_AD_TYPE_T ad_type;
    TUYA_BT_HAL_DEV_TYPE_T type;    
}TUYA_BT_HAL_BLE_SCAN_DEV_S;

typedef struct{
    uint8_t mac[TY_BT_MAC_LEN];
    uint8_t uuid[TY_MESH_UUID_LEN];
    uint16_t oob;
    uint32_t uri_hash;
    uint8_t rssi;
}TUYA_BT_HAL_MESH_SCAN_DEV_S;

/*
 * ble or mesh dev strcut
 */
typedef struct{
    uint8_t mac[TY_BT_MAC_LEN];
    uint16_t dev_addr;  //sub device id 
    uint8_t dev_key[TY_BT_DEV_KEY_LEN];   
}TUYA_BT_HAL_MESH_DEV_S;

typedef struct{
    uint16_t len;
    uint8_t *data;  //only store page 0's data   
}TUYA_BT_HAL_MESH_DEV_COMPOSITE_DATA_S;

/*
 * mesh/device manage operate type (include add and delete)
 */
typedef enum{
    TUYA_BT_HAL_MESH_DEV_OP_ADD = 0x00,
    TUYA_BT_HAL_MESH_DEV_OP_DEL,
    TUYA_BT_HAL_MESH_DEV_OP_DEL_CONFIG,     //delete config and disconnect device for app drag 
    TUYA_BT_HAL_MESH_DEV_OP_SYNC_CONFIG     //sync config for app drag
}TUYA_BT_HAL_MESH_DEV_OP_E;

/*
 * mesh/device type (for data report or send)
 */
typedef enum{
    TUYA_BT_HAL_DATA_TYPE_MESH_DEV = 0x00,
    TUYA_BT_HAL_DATA_TYPE_BLE_DEV,
}TUYA_BT_HAL_DATA_TYPE_E;

/*
 * (for data report or send) the dst_addr or src_addr is different with different TUYA_BT_HAL_DATA_TYPE
 */
typedef union{
    struct{
        uint16_t dev_addr;
        uint16_t primary_addr;
    }mesh_dev;
    struct{
        uint8_t mac[TY_BT_MAC_LEN];
    }ble;
}TUYA_BT_HAL_DATA_ADDR_U;

typedef enum{
    TUYA_BT_EVENT_FAIL = -1,
    TUYA_BT_EVENT_SUCCESS = 0,
}TUYA_BT_HAL_STATUS_EVENT_E;

typedef void (*TUYA_BT_HAL_BLE_SCAN_CB)(uint16_t dev_num, TUYA_BT_HAL_BLE_SCAN_DEV_S *dev);
typedef void (*TUYA_BT_HAL_MESH_SCAN_CB)(uint16_t dev_num, TUYA_BT_HAL_MESH_SCAN_DEV_S *dev);
typedef void (*TUYA_BT_HAL_MESH_ADD_CB)(uint16_t dev_num, TUYA_BT_HAL_MESH_DEV_S *dev, TUYA_BT_HAL_MESH_DEV_COMPOSITE_DATA_S *composite_data);
typedef void (*TUYA_BT_HAL_MESH_DELETE_CB)(uint16_t dev_num, TUYA_BT_HAL_MESH_DEV_S *dev);
typedef void (*TUYA_BT_HAL_DATA_REPORT)(TUYA_BT_HAL_DATA_TYPE_E type, TUYA_BT_HAL_DATA_ADDR_U *src, uint8_t *data, uint32_t lenght);
typedef void (*TUYA_BT_HAL_STATUS_EVENT)(TUYA_BT_HAL_DATA_TYPE_E type, TUYA_BT_HAL_DATA_ADDR_U *src, TUYA_BT_HAL_STATUS_EVENT_E event);

typedef struct{
    TUYA_BT_HAL_BLE_SCAN_CB                 ble_scan_cb;
    TUYA_BT_HAL_MESH_SCAN_CB                mesh_scan_cb;
    TUYA_BT_HAL_MESH_ADD_CB                 mesh_add_cb;
    TUYA_BT_HAL_MESH_DELETE_CB              mesh_delete_cb;
    TUYA_BT_HAL_DATA_REPORT                 data_report_cb;
    TUYA_BT_HAL_STATUS_EVENT                bt_connect_cb;     //  get the disconnect event
    TUYA_BT_HAL_STATUS_EVENT                bt_disconnect_cb;  //  get the disconnect event
}TUYA_BT_HAL_GW_CBS_S;

typedef enum{
  TY_INFO_TP_GENERAL_DATA,
  TY_INFO_TP_DEVKEY,
}TUYA_BT_HAL_DATA_INFO_TYPE_E;

typedef struct 
{
    TUYA_BT_HAL_DATA_INFO_TYPE_E info_type;
    union 
    {
        uint8_t dev_key[TY_BT_DEV_KEY_LEN];
    }data;
} TUYA_BT_HAL_DATA_INFO_T;

OPERATE_RET tuya_bt_hal_gw_start(TUYA_BT_HAL_WORK_MODE_E mode, TUYA_BT_HAL_GW_CBS_S *cbs);
OPERATE_RET tuya_bt_hal_set_mesh_info(TUYA_BT_HAL_MESH_INFO_S *info);
OPERATE_RET tuya_bt_hal_get_max_connect_ability(uint16_t *num);
OPERATE_RET tuya_bt_hal_ble_get_mtu(uint8_t *mac, uint8_t mac_len, uint16_t *mtu);//only for ble 

OPERATE_RET tuya_bt_hal_ble_scan(bool enable, uint16_t timeout);//enable=1 start; enable=0 stop; timeout second
OPERATE_RET tuya_bt_hal_mesh_scan(bool enable, uint16_t timeout);//timeout second

/*
 * function connect and disconnect, need to post this device belong to which types, it is important. otherwise cannot connect
 * mac lenght = 6bytes, connect ble devices and mesh devices. when gateway reboot, use this api to reconnect
 * timeout: second, 0 will block
 */
OPERATE_RET tuya_bt_hal_connect(uint8_t *mac, TUYA_BT_HAL_DEV_TYPE_T type, uint8_t timeout);
OPERATE_RET tuya_bt_hal_disconnect(uint8_t *mac, TUYA_BT_HAL_DEV_TYPE_T type);

/*
 * function device manage
 * note:the function of ble dev add and delete, whitch can be realized based on data_report and data_send. place this private protocol on the component layer.
 * //call this function will auto connect the device , no need call connect function
 * add and delete config: need mac+dev_addr 
 * delete and sync config: need mac+dev_addr+devicekey, 
 */
OPERATE_RET tuya_bt_hal_mesh_dev_manage(TUYA_BT_HAL_MESH_DEV_OP_E op, uint8_t dev_num, TUYA_BT_HAL_MESH_DEV_S *dev); 
                                                                                                             
OPERATE_RET tuya_bt_hal_data_send(TUYA_BT_HAL_DATA_TYPE_E type, TUYA_BT_HAL_DATA_ADDR_U *dst, uint8_t *data, uint32_t len,TUYA_BT_HAL_DATA_INFO_T *data_info);

#endif







