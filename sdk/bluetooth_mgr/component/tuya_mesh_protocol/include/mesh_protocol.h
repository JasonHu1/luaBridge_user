/*
 * mesh_protocol.h
 *
 *  Created on: 2020-05-15
 *      Author: Joey
 */
 
#ifndef _MESH_PROTOCOL_H
#define _MESH_PROTOCOL_H

#include "tuya_cloud_com_defs.h"
#include "tuya_iot_com_api.h"
#include "uni_log.h"
#include "mem_pool.h"
#include "tuya_mesh_type.h"
#include "tuya_generic_on_off.h"
#include "tuya_light_ctl.h"
#include "tuya_light_hsl.h"
#include "tuya_light_lightness.h"
#include "tuya_datatrans.h"
#include "tuya_cfg_model.h"

#include "mesh_adapter.h"

#define VENDOR_ID    0x07D0

#define MESH_UNASSIGNED_ADDR                    0x0000
#define MESH_GROUP_ADDR_DYNAMIC_START           0xC000
#define MESH_GROUP_ADDR_DYNAMIC_END             0xFEFF
#define MESH_GROUP_ADDR_FIX_START               0xFF00
#define MESH_GROUP_ADDR_ALL_PROXY               0xFFFC
#define MESH_GROUP_ADDR_ALL_FRND                0xFFFD
#define MESH_GROUP_ADDR_ALL_RELAY               0xFFFE
#define MESH_GROUP_ADDR_ALL_NODE                0xFFFF

#define MESH_IS_UNASSIGNED_ADDR(addr)           ((addr) == MESH_UNASSIGNED_ADDR)
#define MESH_NOT_UNASSIGNED_ADDR(addr)          ((addr) != MESH_UNASSIGNED_ADDR)
#define MESH_IS_UNICAST_ADDR(addr)              ((addr) != MESH_UNASSIGNED_ADDR && ((addr) & 0x8000) == 0x0000)
#define MESH_NOT_UNICAST_ADDR(addr)             ((addr) == MESH_UNASSIGNED_ADDR || ((addr) & 0x8000) != 0x0000)
#define MESH_IS_VIRTUAL_ADDR(addr)              (((addr) & 0xC000) == 0x8000)
#define MESH_NOT_VIRTUAL_ADDR(addr)             (((addr) & 0xC000) != 0x8000)
#define MESH_IS_GROUP_ADDR(addr)                (((addr) & 0xC000) == 0xC000)
#define MESH_NOT_GROUP_ADDR(addr)               (((addr) & 0xC000) != 0xC000)
#define MESH_IS_RFU_GROUP_ADDR(addr)            ((addr) >= MESH_GROUP_ADDR_FIX_START && (addr) < MESH_GROUP_ADDR_ALL_PROXY)
#define MESH_IS_BROADCAST_ADDR(addr)            ((addr) == MESH_GROUP_ADDR_ALL_NODE)
#define MESH_NOT_BROADCAST_ADDR(addr)           ((addr) != MESH_GROUP_ADDR_ALL_NODE)
#define MESH_IS_SUBSCRIBE_ADDR(addr)            ((addr) != MESH_GROUP_ADDR_ALL_NODE && ((addr) & 0x8000) == 0x8000)
#define MESH_NOT_SUBSCRIBE_ADDR(addr)           ((addr) == MESH_GROUP_ADDR_ALL_NODE || ((addr) & 0x8000) != 0x8000)

/** @defgroup Access_Opcode Access Opcode
  * @brief
  * @{
  */
/** #pragma diag_suppress 175 */
#define ACCESS_OPCODE_SIZE(opcode)              ((opcode) >= 0xc00000 ? 3 : ((opcode) >= 0x8000 ? 2 : 1))
#define ACCESS_OPCODE_BYTE(pbuffer, opcode)\
    do\
    {\
        if(ACCESS_OPCODE_SIZE(opcode) == 1)\
        {\
            *((uint8_t *)(pbuffer)) = (opcode) & 0xff;\
        }\
        else if(ACCESS_OPCODE_SIZE(opcode) == 2)\
        {\
            *((uint8_t *)(pbuffer)) = ((opcode) >> 8) & 0xff;\
            *((uint8_t *)(pbuffer) + 1) = (opcode) & 0xff;\
        }\
        else\
        {\
            *((uint8_t *)(pbuffer)) = ((opcode) >> 16) & 0xff;\
            *((uint8_t *)(pbuffer) + 1) = ((opcode) >> 8) & 0xff;\
            *((uint8_t *)(pbuffer) + 2) = (opcode) & 0xff;\
        }\
    } while(0)

//-----------------
typedef enum
{
    TUYA_RESULT_OK = 0,
    TUYA_RESULT_ERROR,
    TUYA_RESULT_VALUE_OUT_OF_RANGE,
    TUYA_RESULT_NO_NEED_REPORT,
} tuya_result_t;

//-----------------

#define DEVICE_TYPE(pk_type)  ((pk_type & 0x3000) >> 12)
#define PRODUCT_TYPE(pk_type)  ((pk_type & 0x00F0) >> 4)
#define SUB_TYPE(pk_type)  (pk_type & 0x000F)

typedef enum
{
    STANDARD_DEVICE = 0x01,
    VENDOR_DEVICE   = 0x02,
} tuya_mesh_device_type_t;

typedef enum
{
    DEVICE_LIGHT  = 0x01,
    DEVICE_SWITCH = 0x02,
//    DEVICE_SOCKET = 0x03,
    DEVICE_SENSOR = 0x04,
    DEVICE_REMOTECONTROL = 0x05,
    DEVICE_CONTROLLER    = 0x06,
} tuya_mesh_product_type_t;

typedef enum
{
    LIGHT_W = 1,
    LIGHT_CW,
    LIGHT_RGB,
    LIGHT_RGBW,
    LIGHT_RGBCW,
} tuya_mesh_light_sub_type_t;

typedef struct
{
    uint32_t model_id;
    uint32_t opcode;
    uint16_t data_len;
    uint8_t data[256];
} tuya_mesh_client_data_t; 

typedef struct
{
    uint8_t dp_id;
    uint8_t dp_type;
    uint8_t dp_len;
    union{
        uint8_t *dp_data;
        uint32_t dp_value;
        uint8_t dp_enum;
        uint8_t dp_bool;
        uint32_t dp_bitmap;
    };
} tuya_mesh_dp_point_t;

extern uint16_t get_device_pk_type(uint16_t mesh_addr);

extern void tuya_mesh_data_send(uint16_t mesh_addr, uint16_t primary_addr, tuya_mesh_client_data_t *mesh_data, uint8_t *dev_key);


#endif /* _MESH_PROTOCOL_H */

