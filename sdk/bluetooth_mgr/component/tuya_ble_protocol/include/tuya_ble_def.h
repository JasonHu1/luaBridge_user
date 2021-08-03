#ifndef __TUYA_BLE_DEF_H__
#define __TUYA_BLE_DEF_H__

#include "tuya_bt_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum TY_BLE_M2S_CMD_ {
	TY_BLE_M2S_QUERY_DEV_INFO 			= 0x0000, // 查询设备信息
	TY_BLE_M2S_PAIR 					= 0x0001, // 发起配对
	TY_BLE_M2S_CMD_ISSUE 				= 0x0002, // 命令下发
	TY_BLE_M2S_QUERY_DEV_STATUS 		= 0x0003, // 设备状态查询
	TY_BLE_M2S_SET_PASSWD 				= 0x0004, // 设置密码
	TY_BLE_M2S_UNBIND_DEV 				= 0x0005, // 设备解绑
	TY_BLE_M2S_RESET_DEV 				= 0x0006, // 设备重置
	TY_BLE_M2S_ASK_STARTUP 				= 0x0007, // 申请启动（APP）
	TY_BLE_M2S_DATA_TRAN_RESPOND 		= 0x0008, // 数据传输响应（APP）
	TY_BLE_M2S_TRAN_END_RESPOND 		= 0x0009, // 传输结束响应（APP）
	TY_BLE_M2S_FORCE_TRAN_END 			= 0x000A, // 强制传输终止（APP）
	TY_BLE_M2S_OTA_START 				= 0x000C, // OTA开始升级
	TY_BLE_M2S_OTA_FILE_INFO 			= 0x000D, // OTA升级文件信息
	TY_BLE_M2S_OTA_FILE_OFFSET_REQUEST 	= 0x000E, // OTA升级文件偏移请求
	TY_BLE_M2S_OTA_DATA 				= 0x000F, // OTA数据
	TY_BLE_M2S_OTA_END 					= 0x0010, // OTA升级结束
	TY_BLE_M2S_FACTORY_TEST_CMD 		= 0x0012, // 出厂测试指令
	TY_BLE_M2S_CONNECT_NETWORK 			= 0x0013, // 发送配网信息
	TY_BLE_M2S_UNBIND_ABNORMAL 			= 0x0014, // 异常解绑
} TY_BLE_M2S_CMD_E;


typedef enum TY_BLE_S2M_CMD_ {
	TY_BLE_S2M_STATUS_REPORT 			= 0x8001, // 状态上报
	// TY_BLE_S2M_ 						= 0x8002, // 设备调试信息显示
	// TY_BLE_S2M_ 						= 0x8003, // 记录型状态数据上报
	// TY_BLE_S2M_ASK_STARTUP_RESPOND 		= 0x8007, // 申请启动响应（设备）
	// TY_BLE_S2M_DATA_TRAN 				= 0x8008, // 数据传输（设备）
	// TY_BLE_S2M_TRAN_END 				= 0x8009, // 传输结束（设备）
	// TY_BLE_S2M_FORCE_TRAN_END_RESPOND 	= 0x800A, // 强制传输终止响应（设备）
	// TY_BLE_S2M_ 						= 0x8010, // 设备获取实时时间
	// TY_BLE_S2M_ 						= 0x8011, // 设备获取实时时间1
	// TY_BLE_S2M_ 						= 0x8012, // 设备获取实时时间2
} TY_BLE_S2M_CMD_E;


// Generic Access Profile Class
#define GAP_ADTYPE_FLAGS                        0x01 //!< The Flags data type contains one bit Boolean flags. Please reference @ref ADV_TYPE_FLAGS for details.
#define GAP_ADTYPE_16BIT_MORE                   0x02 //!< Service: More 16-bit UUIDs available
#define GAP_ADTYPE_16BIT_COMPLETE               0x03 //!< Service: Complete list of 16-bit UUIDs
#define GAP_ADTYPE_32BIT_MORE                   0x04 //!< Service: More 32-bit UUIDs available
#define GAP_ADTYPE_32BIT_COMPLETE               0x05 //!< Service: Complete list of 32-bit UUIDs
#define GAP_ADTYPE_128BIT_MORE                  0x06 //!< Service: More 128-bit UUIDs available
#define GAP_ADTYPE_128BIT_COMPLETE              0x07 //!< Service: Complete list of 128-bit UUIDs
#define GAP_ADTYPE_LOCAL_NAME_SHORT             0x08 //!< Shortened local name
#define GAP_ADTYPE_LOCAL_NAME_COMPLETE          0x09 //!< Complete local name
#define GAP_ADTYPE_POWER_LEVEL                  0x0A //!< TX Power Level: 0xXX: -127 to +127 dBm
#define GAP_ADTYPE_OOB_CLASS_OF_DEVICE          0x0D //!< Simple Pairing OOB Tag: Class of device (3 octets)
#define GAP_ADTYPE_OOB_SIMPLE_PAIRING_HASHC     0x0E //!< Simple Pairing OOB Tag: Simple Pairing Hash C (16 octets)
#define GAP_ADTYPE_OOB_SIMPLE_PAIRING_RANDR     0x0F //!< Simple Pairing OOB Tag: Simple Pairing Randomizer R (16 octets)
#define GAP_ADTYPE_SM_TK                        0x10 //!< Security Manager TK Value
#define GAP_ADTYPE_SM_OOB_FLAG                  0x11 //!< Secutiry Manager OOB Flags
#define GAP_ADTYPE_SLAVE_CONN_INTERVAL_RANGE    0x12 //!< Min and Max values of the connection interval (2 octets Min, 2 octets Max) (0xFFFF indicates no conn interval min or max)
#define GAP_ADTYPE_SIGNED_DATA                  0x13 //!< Signed Data field
#define GAP_ADTYPE_SERVICES_LIST_16BIT          0x14 //!< Service Solicitation: list of 16-bit Service UUIDs
#define GAP_ADTYPE_SERVICES_LIST_128BIT         0x15 //!< Service Solicitation: list of 128-bit Service UUIDs
#define GAP_ADTYPE_SERVICE_DATA                 0x16 //!< Service Data
#define GAP_ADTYPE_PUBLIC_TGT_ADDR              0x17 //!< Public Target Address
#define GAP_ADTYPE_RANDOM_TGT_ADDR              0x18 //!< Random Target Address
#define GAP_ADTYPE_APPEARANCE                   0x19 //!< Appearance
#define GAP_ADTYPE_ADV_INTERVAL                 0x1A //!< Advertising Interval
#define GAP_ADTYPE_LE_BT_ADDR                   0x1B //!< LE Bluetooth Device Address
#define GAP_ADTYPE_LE_ROLE                      0x1C //!< LE Role
#define GAP_ADTYPE_SP_HASH_C256                 0x1D //!< Simple Pairing Hash C-256
#define GAP_ADTYPE_SP_RAND_R256                 0x1E //!< Simple Pairing Randomizer R-256
#define GAP_ADTYPE_LIST_32BIT_SILI              0x1F //!< List of 32-bit Service Solicitation UUIDs
#define GAP_ADTYPE_SERVICE_DATA_32BIT           0x20 //!< Service Data - 32-bit UUID
#define GAP_ADTYPE_SERVICE_DATA_128BIT          0x21 //!< Service Data - 128-bit UUID
#define GAP_ADTYPE_SC_CONF_VALUE                0x22 //!< LE Secure Connections Confirmation Value
#define GAP_ADTYPE_SC_RAND_VALUE                0x23 //!< LE Secure Connections Random Value
#define GAP_ADTYPE_URI                          0x24 //!< URI
#define GAP_ADTYPE_INDOOR_POSITION              0x25 //!< Indoor Positioning
#define GAP_ADTYPE_TRANSPORT_DISCOVERY_DATA     0x26 //!< Transport Discovery Data
#define GAP_ADTYPE_LE_SUPPORTED_FEATURES        0x27 //!< LE Supported Features
#define GAP_ADTYPE_CHAN_MAP_UPDATE_IND          0x28 //!< Channel Map Update Indication
#define GAP_ADTYPE_MESH_PB_ADV                  0x29 //!< Mesh Pb-Adv
#define GAP_ADTYPE_MESH_PACKET                  0x2A //!< Mesh Packet
#define GAP_ADTYPE_MESH_BEACON                  0x2B //!< Mesh Beacon
#define GAP_ADTYPE_3D_INFO_DATA                 0x3D //!< 3D Information Data
#define GAP_ADTYPE_MANUFACTURER_SPECIFIC        0xFF //!< Manufacturer Specific Data: first 2 octets contain the Company Identifier Code followed by the additional manufacturer specific data


#define BLE_ADVERTISING_SCAN_RESPONSE_MAX_LEN 		31

#define TY_BLE_COMPANY_ID_5902 						0x5902
#define TY_BLE_COMPANY_ID_07d0    					0x07d0
#define TY_BLE_COMPANY_ID_0259   					0x0259

#define TY_BLE_PROTOCOL_A201 						0xa201
#define TY_BLE_PROTOCOL_A300 						0xa300
#define TY_BLE_PROTOCOL_FD50 						0xfd50 // Tuya Specific UUID,


#define TY_MESH_PROTOCOL_1827 						0x1827
#define TY_MESH_PROTOCOL_1828 						0x1828

#define TY_BLE_DEVICE_TYPE_BLE                      0x00
#define TY_BLE_DEVICE_TYPE_IPC 						0x01

#define TY_BLE_VERSION_3_0                          0x03
#define TY_BLE_VERSION_2_0                          0x02


#define TY_BLE_PRODUCT_ID_MAX_LEN       8
#define TY_BLE_DEVICE_ID_MAX_LEN        16
#define TY_BLE_DEVICE_SERVICE_DATA_LEN  20

typedef struct ty_ble_adv_decode_ {
    char            bind;
    char            link_req;
    char            config;

// scan response    
    unsigned char   sdk_version;
    unsigned short  com_ability;
    unsigned short  company_id;
    unsigned char   encrypt_mode;
    unsigned short  com_way;
    unsigned char   data_type;
    unsigned char   device_id[TY_BLE_DEVICE_ID_MAX_LEN];

// advertising data
    unsigned short  service_id;
    unsigned char   device_type;
    unsigned char   product_id[TY_BLE_PRODUCT_ID_MAX_LEN + 1];
// service data
    unsigned char   service_data[TY_BLE_DEVICE_SERVICE_DATA_LEN];
}ty_ble_adv_decode_s;

typedef struct ty_mesh_adv_decode_ {
    unsigned short  service_id;

    unsigned char   service_data[TY_BLE_DEVICE_SERVICE_DATA_LEN];
    unsigned char   virtural_mac[6];
    unsigned char   category[2];
    unsigned char   product_id[8];
    
}ty_mesh_adv_decode_s;

typedef struct ty_ble_broadcast_data_ {
    TUYA_BT_HAL_DEV_TYPE_T  type;
    
//  Ble Adv Decode
    ty_ble_adv_decode_s ble;

// Mesh Adv Decode
    ty_mesh_adv_decode_s mesh;
} TY_BLE_BROADCAST_DATA_S;


#ifdef __cplusplus
}
#endif

#endif // end __TY_BLE_DEF_H__
