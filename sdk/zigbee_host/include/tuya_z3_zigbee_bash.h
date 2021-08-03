#ifndef __TUYA_Z3_ZIGBEE_BASE_H
#define __TUYA_Z3_ZIGBEE_BASE_H

#include "tuya_cloud_types.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
	extern "C" {
#endif
#define Z3_PRINTF_DEBUG
//#define TY_ZIGBEE_SDK


#define ZIGBEE_UPGRADE_FILE_FOLD_NAME "ota-files"       // update dir,:the file of update must download to current_tmp_dir/ZIGBEE_UPGRADE_FILE_FOLD_NAME
#define NCP_UPGRADE_FILE_NAME         "NcpUpgrade.ota"       // coo update file name, don't modify
#define ZIGBEE_DEV_UPGRADE_FILE_NAME  "ZigbeeDevUpgrade.ota" // dev update file name, don't modify
#define BLE_UPGRADE_FILE_FOLD_NAME "ble-ota-files"       // update dir,:the file of update must download to current_tmp_dir/ZIGBEE_UPGRADE_FILE_FOLD_NAME
#define BLE_NCP_UPGRADE_FILE_NAME  "BleNcpUpgrade.gbl" // dev update file name, don't modify



#ifdef Z3_PRINTF_DEBUG
#ifdef __ANDROID__
#define PR_Z3_WARING(fmt, ...)  __android_log_print(ANDROID_LOG_WARN, "ty_zb", fmt, ##__VA_ARGS__)
#define PR_Z3_DEBUG(fmt, ...)   __android_log_print(ANDROID_LOG_DEBUG, "ty_zb", fmt, ##__VA_ARGS__)
#define PR_Z3_ERR(fmt, ...)     __android_log_print(ANDROID_LOG_ERROR, "ty_zb", fmt, ##__VA_ARGS__)
#else
#define PR_Z3_WARING(fmt, ...)	printf("[WARING][%s:%d]: "fmt,__FUNCTION__, __LINE__, ##__VA_ARGS__)
#define PR_Z3_DEBUG(fmt, ...)	printf("[DEBUG ][%s:%d]: "fmt,__FUNCTION__, __LINE__, ##__VA_ARGS__)
#define PR_Z3_ERR(fmt, ...)	    printf("[ERROR ][%s:%d]: "fmt,__FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif // end __ANDROID__
#else
#define PR_Z3_WARING(fmt, ...)
#define PR_Z3_DEBUG(fmt, ...)
#define PR_Z3_ERR(fmt, ...)
#endif	

#define TY_ZIGBEE_EUI64       8
#define DEV_ID_MAX_LEN        32
#define TY_EPAN_STR_LEN       16
#define TY_NETWORK_KEY        16
#define SW_VER_LEN            10 // sw ver len
#define RF_MSG_LEN_MAX        16


#define TY_CLUSTER_CMD_INDEX     0
#define TY_MANU_CODE_INDEX       1
#define TY_SEQUENCE_NUM_INDEX    1
#define TY_ATTR_CMD_INDEX        2
#define TY_ATTR_ID_INDEX         3
#define TY_DATA_INDEX            3

#define TY_ZCL_FRAME_CONTROL_FRAME_TYPE_MASK     (BIT(0) | BIT(1))
#define TY_ZCL_CLUSTER_SPECIFIC_COMMAND          BIT(0)
#define TY_ZCL_PROFILE_WIDE_COMMAND              0
#define TY_ZCL_GLOBAL_COMMAND                    (TY_ZCL_PROFILE_WIDE_COMMAND)
// Bit 2 is Manufacturer Specific Sub-field
//#define TY_ZCL_MANUFACTURER_SPECIFIC_OFFSET      2
#define TY_ZCL_MANUFACTURER_SPECIFIC_MASK        BIT(2)
// Bit 3 is Direction Sub-field
#define TY_ZCL_FRAME_CONTROL_DIRECTION_MASK      BIT(3)
#define TY_ZCL_FRAME_CONTROL_SERVER_TO_CLIENT    BIT(3)
#define TY_ZCL_FRAME_CONTROL_CLIENT_TO_SERVER    0
// Bit 4 is Disable Default Response Sub-field
#define TY_ZCL_DISABLE_DEFAULT_RESPONSE_MASK     BIT(4)
// Bits 5 to 7 are reserved

#define TY_ZCL_DIRECTION_CLIENT_TO_SERVER 0
#define TY_ZCL_DIRECTION_SERVER_TO_CLIENT 1


#ifdef TY_ZIGBEE_SDK
#define PROFILE_ID_HA              0x0104

#define TY_CMD_TYPE_GLOBAL         0x01
#define TY_CMD_TYPE_PRIVATE        0x02
#define TY_CMD_TYPE_ZDO            0x03

#define TY_GW_SOURCE_ENDPOINT      0x01
#endif

typedef UCHAR_T TYEmberEUI64[TY_ZIGBEE_EUI64];

typedef struct{
    
    USHORT_T     nodeId;
    TYEmberEUI64 srcNodeEui64;
    UCHAR_T      srcEndpoint;
    USHORT_T     clusterId;
    TYEmberEUI64 dstNodeEui64;
    USHORT_T     groupAddress;
    UCHAR_T      dstEndpoint;
}DEV_Z3_BIND_DATA_S;


typedef struct{
    CHAR_T  nodeEuiStr[DEV_ID_MAX_LEN];
    USHORT_T nodeId;
    USHORT_T panId;
    UCHAR_T  epanIdStr[TY_EPAN_STR_LEN+1];
    UCHAR_T  netWorkKey[TY_NETWORK_KEY];
    UCHAR_T  channel;
    CHAR_T  ver[SW_VER_LEN+1];
    UCHAR_T  netStatus;
}TY_NETWORK_INOF_T;


typedef struct{
    CHAR_T nodeEuiStr[DEV_ID_MAX_LEN+1];
    CHAR_T  cFlag;                        //Is enable aps ack. 0:enable; 1:disable
    USHORT_T node_id;                     // 0 don't care
    CHAR_T ucTyProfile;                   // Ty Profile
}TY_DEV_DEL_T;


typedef struct {
    UCHAR_T  nodeEui64[TY_ZIGBEE_EUI64];
    USHORT_T nodeId;
    USHORT_T profileId;
    USHORT_T clusterId;
    UCHAR_T  sourceEndpoint;
    UCHAR_T  destinationEndpoint;
    USHORT_T groupId;
    UCHAR_T  cmdType;             // zcl frame type:0x01 is global , 0x02 is specific to a cluster
    UCHAR_T  command;             // zcl command id
    UCHAR_T  frameType;           // 0:Unicast 1:Multicast 2:Broadcast
    USHORT_T messageLength;       // the len of message(zcl PayLoad)
    UCHAR_T  seqNum;              // aps seq num
    CHAR_T   isNoAck;             // is need aps ack; 1:no need ack
    //BOOL_T   ManufacturerSpecific;// ManufacturerSpecific
    USHORT_T manufacturerCode;
    CHAR_T   isArp;               // no use
    BOOL_T   isFindEnd;           // no use
    CHAR_T   isFastJoin;
	UCHAR_T  isDefRsp;            //Default Response flag, 1:open Default Response
    BYTE_T   dp_id;
    CHAR_T   is_poweron;          // 1 is power on
    UCHAR_T   lastHopLqi;
}TuYaApsFrameHeader;

typedef struct {
    TuYaApsFrameHeader sHeader; // aps header+zcl header
    UCHAR_T *message;           // the data of zcl PayLoad
} TuYaApsFrame;


typedef struct{
    BOOL_T   type;        // TRUE:send and receive; FALSE: only send
    UCHAR_T  channel;     // test channel
    USHORT_T numPackets;  // the num of test packet
    UCHAR_T  length;      // the len of message
    CHAR_T   power;       // transmitted power
    UCHAR_T  message[RF_MSG_LEN_MAX+1];
}ZIGBEE_RF_TEST_S;


typedef struct {
    USHORT_T grp_id;
    USHORT_T sce_id;
    USHORT_T cluster_Id;
    USHORT_T zcl_len;
    CHAR_T   zcl_payload[32];
}TY_GRP_SCE_INFO_S;


typedef enum {
    TY_EMBER_NO_NETWORK,
    TY_EMBER_JOINING_NETWORK,
    TY_EMBER_JOINED_NETWORK,
    TY_EMBER_JOINED_NETWORK_NO_PARENT,
    TY_EMBER_LEAVING_NETWORK
} TUYA_NETSTAT_E;

#define Z3_NODE_EUI64_TO_STRIN(nodeEuistr, nodeEui64) do{ \
sprintf(nodeEuistr,"%02x%02x%02x%02x%02x%02x%02x%02x", \
                                    nodeEui64[7]&0xFF, nodeEui64[6]&0xff, nodeEui64[5]&0xFF, nodeEui64[4]&0xFF,\
                                    nodeEui64[3]&0xFF, nodeEui64[2]&0xFF, nodeEui64[1]&0xFF, nodeEui64[0]&0xFF);}while(0)

#define Z3_NODE_STRIN_TO_EUI64(nodeEuistr, nodeEui64) do{ \
INT_T iTmp[8] = {0}; \
sscanf(nodeEuistr,"%02x%02x%02x%02x%02x%02x%02x%02x", &iTmp[7], &iTmp[6], &iTmp[5], &iTmp[4], &iTmp[3], &iTmp[2], &iTmp[1], &iTmp[0]);\
                nodeEui64[7] = iTmp[7]&0xFF; nodeEui64[6] = iTmp[6]&0xFF; nodeEui64[5] = iTmp[5]&0xFF; nodeEui64[4] = iTmp[4]&0xFF;\
                nodeEui64[3] = iTmp[3]&0xFF; nodeEui64[2] = iTmp[2]&0xFF; nodeEui64[1] = iTmp[1]&0xFF; nodeEui64[0] = iTmp[0]&0xFF;}while(0)



typedef UCHAR_T TY_EMBER_NETWORK_STATUS;
#define TY_EMBER_NETWORK_UP   0x90
#define TY_EMBER_NETWORK_DOWN 0x91

typedef VOID (*TUYA_Z3_CMD_RECV_CB)(TuYaApsFrame *sTyApsFrameTmp);
typedef VOID (*TUYA_Z3_ZDO_RECV_CB)(TuYaApsFrame *sTyApsFrameTmp);
typedef VOID(*TUYA_Z3_DEV_UPDATE_COMPLETE_CB)(TYEmberEUI64 nodeEui64, UCHAR_T status, UINT_T firmwareVersion);
typedef VOID(*TUYA_Z3_BLOCK_REQUEST_CB)(TYEmberEUI64 nodeEui64, UINT_T offset);
typedef UINT_T(*TUYA_Z3_GET_UNI_TIME)(VOID);
typedef UINT_T(*TUYA_Z3_GET_LOCAL_TIME)(VOID);
typedef VOID (*TUYA_DEV_JOIN_CB)(TYEmberEUI64 nodeEui64,  USHORT_T nodeId);
typedef VOID (*TUYA_Z3_DEV_REJOIN_CB)(TYEmberEUI64 nodeEui64);
typedef VOID (*TUYA_Z3_DEV_LEAVE_CB)(TYEmberEUI64 nodeEui64);
typedef VOID (*TUYA_Z3_NET_STATUS_CB)(TY_EMBER_NETWORK_STATUS status);
typedef VOID(*TUYA_Z3_INIT_COMPLETE_CB)(UCHAR_T status);
typedef VOID(*TUYA_Z3_APP_REBOOT)(VOID);


typedef struct {
    TUYA_Z3_CMD_RECV_CB             cmd_recv_cb;
    TUYA_Z3_ZDO_RECV_CB             zdo_recv_cb;
    TUYA_Z3_DEV_UPDATE_COMPLETE_CB  dev_up_complete_cb;
    TUYA_Z3_BLOCK_REQUEST_CB        dev_up_block_req;
    TUYA_Z3_GET_UNI_TIME            update_uni_time;
    TUYA_Z3_GET_LOCAL_TIME          update_local_time;
    TUYA_DEV_JOIN_CB                dev_join_cb;
    TUYA_Z3_DEV_REJOIN_CB           dev_rejoin_cb;
    TUYA_Z3_DEV_LEAVE_CB            dev_leave_cb;
    TUYA_Z3_NET_STATUS_CB           net_status_cb;
    TUYA_Z3_INIT_COMPLETE_CB        init_complete_cb;
    TUYA_Z3_APP_REBOOT              app_reboot;
}TUYA_Z3_API_CB_S;


typedef struct {
    CHAR_T  ver[SW_VER_LEN+1];

}TY_NCP_INFO_S;

#ifdef __cplusplus
}
#endif

#endif

