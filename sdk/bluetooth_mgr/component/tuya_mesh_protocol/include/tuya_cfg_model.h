
#ifndef __CFG_MODEL_H__
#define __CFG_MODEL_H__

#ifdef __cplusplus
extern"C"{
#endif

#include "tuya_mesh_type.h"

//MESH CONFIG OPCODE
#define TUYA_MESH_MSG_CFG_MODEL_PUB_GET                      0x8018
#define TUYA_MESH_MSG_CFG_MODEL_PUB_SET                      0x03
#define TUYA_MESH_MSG_CFG_MODEL_PUB_STAT                     0x8019
#define TUYA_MESH_MSG_CFG_MODEL_PUB_VA_SET                   0x801A
#define TUYA_MESH_MSG_CFG_MODEL_SUB_ADD                      0x801B
#define TUYA_MESH_MSG_CFG_MODEL_SUB_DELETE                   0x801C
#define TUYA_MESH_MSG_CFG_MODEL_SUB_DELETE_ALL               0x801D
#define TUYA_MESH_MSG_CFG_MODEL_SUB_OVERWRITE                0x801E
#define TUYA_MESH_MSG_CFG_MODEL_SUB_STAT                     0x801F
#define TUYA_MESH_MSG_CFG_MODEL_SUB_VA_ADD                   0x8020
#define TUYA_MESH_MSG_CFG_MODEL_SUB_VA_DELETE                0x8021
#define TUYA_MESH_MSG_CFG_MODEL_SUB_VA_OVERWRITE             0x8022
#define TUYA_MESH_MODEL_CFG_SERVER                           0x0000
#define TUYA_MESH_MODEL_CFG_CLIENT                           0x0001


#ifdef __cplusplus
}
#endif

#endif //__CFG_MODEL_H__






