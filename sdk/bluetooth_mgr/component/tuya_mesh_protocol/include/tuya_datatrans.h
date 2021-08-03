
#ifndef __TUYA_DATATRANS_H__
#define __TUYA_DATATRANS_H__

#ifdef __cplusplus
extern"C"{
#endif
//FAST PROV
#define TUYA_MESH_MSG_TUYA_FAST_PROV_GET_MAC                 0xC0D007
#define TUYA_MESH_MSG_TUYA_FAST_PROV_GET_MAC_STATUS          0xC1D007
#define TUYA_MESH_MSG_TUYA_FAST_PROV_SET_ADDR                0xC2D007
#define TUYA_MESH_MSG_TUYA_FAST_PROV_SET_ADDR_STATUS         0xC3D007
#define TUYA_MESH_MSG_TUYA_FAST_PROV_SET_PROVISON_DATA       0xC4D007
#define TUYA_MESH_MSG_TUYA_FAST_PROV_PROV_CONFIRM            0xC5D007
#define TUYA_MESH_MSG_TUYA_FAST_PROV_PROV_CONFIRM_STATUS     0xC6D007
#define TUYA_MESH_MSG_TUYA_FAST_PROV_COMMPLETE               0xC7D007

//VENDOR
#define TUYA_MESH_MSG_TUYA_DATATRANS_WRITE                        0xC9D007
#define TUYA_MESH_MSG_TUYA_DATATRANS_WRITE_UNACK                  0xCAD007
#define TUYA_MESH_MSG_TUYA_DATATRANS_STATUS                       0xCBD007
#define TUYA_MESH_MSG_TUYA_DATATRANS_READ                         0xCCD007
#define TUYA_MESH_MSG_TUYA_DATATRANS_DATA                         0xCDD007
#define TUYA_MESH_MODEL_TUYA_DATATRANS_SERVER                     0x000407D0
#define TUYA_MESH_MODEL_TUYA_DATATRANS_CLIENT                     0x000507D0

#define VD_CMD_MIN_LEN    5
#define VD_CMD_DP_MIN_LEN    4

typedef enum{
    DP_DATA = 0x01,

    SUB_SET = 0x81,
    SUB_GET = 0x82,
    SENSOR_RESET = 0x85,
}vendor_cmd_type;

#define F_CMD_DP    0x00
#define F_DATA_DP   0x01
#define F_LEN       0x01
#define F_DP_GET    0x02




#ifdef __cplusplus
}
#endif

#endif //__TUYA_DATATRANS_H__

