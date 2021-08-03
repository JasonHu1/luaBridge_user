#ifndef __TUYA_Z3_BASE_H
#define __TUYA_Z3_BASE_H

#include "tuya_cloud_types.h"
#include "tuya_z3_zigbee_bash.h"
#include <time.h>

//#include "uni_system.h"
#if 0// to tuya_z3_zigbee_base.h
#define DEV_ID_MAX_LEN        32
#endif
#define MANU_NAME_MAX_LEN     32
#define MODE_ID_MAX_LEN       32
#define DATE_CODE_MAX_LEN     16
#define PRODUCT_CODE_MAX_LEN  16
#define MAX_ENDPOINT_NUM      20
#define TY_ZIGBEE_EUI_STR_LEN 16
#define TUYA_SIMPLE_DATA_TYPE_ERR          0xfe
#if 0// to tuya_z3_zigbee_base.h
#define TY_ZIGBEE_EUI64       8
#endif
#define MAX_ERROR_NUM 3
#define GW_REPORT_RAW_TIMEOUT 3

#define MAX_CLUSTER_ID_NUM 11 //slabs支持20个，todo:改成20???HXH_AAA
#define TY_STR_LEN_MAX128     128
#if 0// to tuya_z3_zigbee_base.h
#define TY_NETWORK_KEY        16
#endif
#define TY_CURRENT_10A        10
#define TY_CURRENT_16A        16

#define TY_ZCL_SEQ_TMP_NUM    12
#define TY_COUNTRY_CODE_LEN   8
#define TY_NO_BUFFERS            0x18
#define TY_SERIAL_TX_OVERFLOW    0x22
#define TY_ZIGBEE_NETWORK_DOWN   0x91
#define TY_EMBER_NETWORK_BUSY    0xA1

#define ZIGBEE_RADION_POWER    19
#define ZIGBEE_US_RADION_POWER 18

#define TY_GP_GPD_CUSTOMER_DATA_PID_LEN         8   ///< Green power自定义数据 ：PID-8字节
#define TY_GP_GPD_CUSTOMER_DATA_VER_LEN         1   ///< Green power自定义数据 ：子设备版本号-1字节
#define TY_GP_GPD_CUSTOMER_DATA_MODEID_LEN      6   ///< Green power自定义数据 ：modeID-6字节
#define TY_GP_GPD_CUSTOMER_DATA_CHECK_LEN       1   ///< Green power自定义数据 ：校验字
#define TY_AF_GP_GPD_COMMISSIONING_CUSTOM_LEN  \
                                            (   TY_GP_GPD_CUSTOMER_DATA_PID_LEN + \
                                                TY_GP_GPD_CUSTOMER_DATA_VER_LEN + \
                                                TY_GP_GPD_CUSTOMER_DATA_MODEID_LEN + \
                                                TY_GP_GPD_CUSTOMER_DATA_CHECK_LEN)  ///< Green power自定义数据总长度

#ifndef TY_FAST_JOIN
#define TY_FAST_JOIN
#endif

#define TY_BIND_REPORT
#define SUPPORT_TUYA_COM_PRO

#define TUYA_DEFAULT_DEBUG_LEVEL 4

#ifdef TY_FAST_JOIN
//#define TY_DEV_FW_CHECK //暂时没用到，先注掉，后面打开要注意入网时可能读不到影响入网流程
#endif

#ifdef TY_DEV_FW_CHECK
#define TY_DEV_FW_CHECK_HASH_TAIL       "tuya_zigbee"
#define TY_DEV_FW_CHECK_HASH_TAIL_LEN   11
#define TY_DEV_FW_CHECK_HASH_HEAD_LEN   16
#define TY_DEV_FW_CHECK_HASH_LEN        (TY_DEV_FW_CHECK_HASH_HEAD_LEN + TY_DEV_FW_CHECK_HASH_TAIL_LEN)
#define TY_DEV_FW_CHECK_PUB_KEY_LEN     40
#define TY_DEV_FW_CHECK_SIG_LEN         40
#endif

#define PRODUCT_KEY_LEN 16
#if 0// to tuya_z3_zigbee_base.h
#define SW_VER_LEN 10 // sw ver len
#endif
#define FW_KEY_LEN 8  // firmware key len
#define TY_EMBER_MAX_MESSAGE_LIMIT_REACHED 0x72
#if 0// to tuya_z3_zigbee_base.h
#define TY_EMBER_NETWORK_UP   0x90
#define TY_EMBER_NETWORK_DOWN 0x91
#endif
#define GROUPS_DIFF_NUMBER       10000

#define TY_MATCH_STANDAR_TYP1 "_TYST"           //"_TYST01_"
#define TY_MATCH_STANDAR_TYP2 "TUYATEC-"
#define TY_MATCH_STANDAR_TYP3 "TUYA-TEC"
#define TY_MATCH_STANDAR_TYP4 "_TYZB"           //"_TYST01_"
#define TY_MATCH_STANDAR_TYP5 "_TZ"             //"_TZ0F1F_pid"

#define MANU_NAME_TUYA       "TUYASMART"
#define MANU_NAME_REX         "REXENSE"
#define MANU_NAME_REX_ALIAS   "REXENS"
#define MANU_NAME_REX_XM     "SEC"
#define MANU_NAME_PHILIPS_LIHGT "Philips Lighting"
#define MANU_NAME_PHILIPS       "Philips"
#define MANU_NAME_IKEA          "IKEA of Sweden"
#define MANU_NAME_IREVO         "ASSA ABLOY iRevo"
#define MANU_NAME_YALE          "Yale"

#define TY_MATCH_STANDAR_PARA1 "01_"  //no oem, pid
#define TY_MATCH_STANDAR_PARA2 "02_"  //oem, firmwarekey

#define TY_STANDAR_TYP_SIGN_LEN    5            //_TYST
#define TY_STANDAR_TYP_PARA_LEN    3            //parameter 01_
#define TY_STANDAR_TYP_LEN         (TY_STANDAR_TYP_SIGN_LEN + TY_STANDAR_TYP_PARA_LEN)

/*******TY_MATCH_STANDAR_TYP5 Head Lenth*******/
#define TY_STANDAR_TYP5_HEAD_ABILITY_MIN_LEN        4
#define TY_STANDAR_TYP5_HEAD_ABILITY_MAX_LEN        12
#define TY_STANDAR_TYP5_HEAD_PID_MIN_LEN            8
#define TY_STANDAR_TYP5_HEAD_PID_MAX_LEN            16
#define TY_STANDAR_TYP5_HEAD_MIN_LEN                (4 + TY_STANDAR_TYP5_HEAD_ABILITY_MIN_LEN + TY_STANDAR_TYP5_HEAD_PID_MIN_LEN)
#define TY_STANDAR_TYP5_HEAD_MAX_LEN                (4 + TY_STANDAR_TYP5_HEAD_ABILITY_MAX_LEN + TY_STANDAR_TYP5_HEAD_PID_MAX_LEN)

/*******TY_MATCH_STANDAR_TYP5 Ability Type*******/
typedef enum {
    TY_STANDAR_ABILITY_TYP_STAND_DP = 0,  ///<支持标准DP(产品不可包含100以上自定义dp)
    TY_STANDAR_ABILITY_TYP_FW_CHECK,      ///<支持固件校验(默认必填)
    TY_STANDAR_ABILITY_TYP_COM,           ///<支持通用对接
    TY_STANDAR_ABILITY_TYP_MCU_UG,        ///<支持MCU升级
    TY_STANDAR_ABILITY_TYP_ENCRYPT,       ///<支持数据加密
    TY_STANDAR_ABILITY_TYP_RELIABLE,      ///<支持可靠数据传输(当前加密门锁使用)
    TY_STANDAR_ABILITY_TYP_OEM,           ///<支持OEM上报固件key(pid部分填写固件key)
    TY_STANDAR_ABILITY_TYP_BIND_REPORT,   ///<设备需要邦定
    TY_STANDAR_ABILITY_TYP_STD_RELIABLE,  ///<标准设备的私有dp点透传能力
    TY_STANDAR_ABILITY_TYP_AUTHKEY,       ///<支持预制密钥通道加密
    TY_STANDAR_ABILITY_TYP_ZB_GRP,        ///<支持zigbee群组遥控能力，群组操作需要特殊处理
    TY_STANDAR_ABILITY_TYP_SUB_PACKAGE,   ///<支持zigbee大数据分包传输能力
    TY_STANDAR_ABILITY_TYP_MAX,           ///<能力值个数
} TY_STANDAR_ABILITY_TYP_E;

/*******XM THERMOSTAT ERROR CODE*******/
#define XM_THERMOSTAT_OK 0
#define XM_THERMOSTAT_IN_TEMP_SENSOR_SHORT 1
#define XM_THERMOSTAT_IN_TEMP_SENSOR_BREAK 2
#define XM_THERMOSTAT_IN_TEMP_SENSOR_ERROR 3
#define XM_THERMOSTAT_OUT_TEMP_SENSOR_ERROR1 4
#define XM_THERMOSTAT_OUT_TEMP_SENSOR_ERROR2 5


#ifdef TY_FAST_JOIN

typedef enum{
    ADD_DEV_STATUS_NULL=0,//读取basic信息
    ADD_DEV_STATUS_BASIC_READ,//读取basic信息
    ADD_DEV_ACTIVE_EP,//获取acivte ep阶段
    ADD_DEV_SIMPLE_DES,//设备已返simple des阶段
    ADD_DEV_SPEC_INFO,//设备别信息阶段
    ADD_DEV_READ_END,
#ifdef TY_DEV_FW_CHECK_REMOVE
    ADD_DEV_FW_CHECK_ERR, //设备固件校验失败需要强制离网
#endif
}ADD_DEV_STAUTS_E;

typedef enum{
    ADD_DEV_SEND_NULL=0,//读取basic信息
    ADD_DEV_SENDING,//发关给tuya应用层
    ADD_DEV_SENDED,//发送给tuya应用层成功

}ADD_DEV_BIND_STAUTS_E;
#else
typedef enum{
    ADD_DEV_ACTIVE_EP = 0,//获取acivte ep阶段
    ADD_DEV_STATUS_JOIN,//设备已返simple des阶段
    ADD_DEV_STATUS_READ_INFO,//发送读取basic及spc信息阶段
    ADD_DEV_STATUS_REDA_INFO_OVER,//信息已获取
    ADD_DEV_STATUS_BIND,//已获取完信息，发送tuya阶段
    ADD_DEV_NOT_SUSPPORT,

}ADD_DEV_STAUTS_E;
#endif
typedef enum{
    DEL_DEV_WAITE_STATUS = 0,//收到设备端发送的删除命令,并进入等待删除状态，此时如果有rejoin包上来，停止删除
    DEL_DEV_STATUS,//删除数据，并已向服务器请求删除，此时如果有rejion包上来，会重新加入
    DEL_DEV_END_REJOIN_STATUS,//收到rejoin，进入重新入网状态

}DEL_DEV_STAUTS_E;


typedef enum{
    TY_NETWORK_STATUS_NULL = 0,
    TY_NETWORK_STATUS_START,
    TY_NETWORK_STATUS_JOINING,
    TY_NETWORK_STATUS_JOINED,
    TY_NETWORK_STATUS_LEAVING,
    TY_NETWORK_STATUS_LEAVED,
}NET_WORK_STAUTS_E;

typedef enum{
    TY_DEV_NEED_BIND = 0,
    TY_DEV_BINDING,
    TY_DEV_BINDED,
    TY_DEV_DONT_BIND,
}DEV_BIND_STAUTS_E;

#ifdef TY_DEV_FW_CHECK
typedef enum{
    TY_DEV_FW_IF_READ_START = 0,
    TY_DEV_FW_IF_READ_ALL   = 0x03,
    TY_DEV_FW_IF_CHECK_END  = 0x0f,
    TY_DEV_FW_IF_READ_END   = 0xf0,
}DEV_FW_IF_READ_STAUTS_E;
#endif

#ifdef TY_BIND_REPORT

typedef enum{
    TY_DEV_NEED_REP = 0,
    TY_DEV_REPING,
    TY_DEV_REPED,
    TY_DEV_DONT_REP,
}DEV_REP_STAUTS_E;


#define EMBER_AF_GP_NOTIFICATION_OPTION_APPLICATION_ID (0x0007)
/**
 * @brief Size of EUI64 (an IEEE address) in bytes (8).
 */
#define EUI64_SIZE 8

/**
 * @brief EUI 64-bit ID (an IEEE address).
 */
typedef UCHAR_T TY_EmberEUI64[EUI64_SIZE];

/**
 * @name GP Types
 */
//@{
/** 32-bit source identifier. */
typedef DWORD_T TY_EmberGpSourceId;

/** @brief Options to use when sending a message. */
#ifdef DOXYGEN_SHOULD_SKIP_THIS
enum TY_EmberGpApplicationId
#else
typedef UCHAR_T TY_EmberGpApplicationId;
enum
#endif
{
  /** Source identifier. */
  TY_EMBER_GP_APPLICATION_SOURCE_ID = 0x00,
  /** IEEE address. */
  TY_EMBER_GP_APPLICATION_IEEE_ADDRESS = 0x02,
};

/** @brief Address for sending and receiving a message. */
typedef struct {
  union {
    /** The IEEE address is used when the application identifier is
     *  ::EMBER_GP_APPLICATION_IEEE_ADDRESS.
     */
    TY_EmberEUI64 gpdIeeeAddress;
    /** The 32-bit source identifier is used when the application identifier is
     *  ::EMBER_GP_APPLICATION_SOURCE_ID.
     *
     */
    TY_EmberGpSourceId sourceId;
  } id;
  /** Application identifier of the GPD. */
  TY_EmberGpApplicationId applicationId;
  UCHAR_T endpoint;
} TY_EmberGpAddress;


typedef struct {
    UCHAR_T ucBindFlag[MAX_ENDPOINT_NUM][MAX_CLUSTER_ID_NUM];
    //UCHAR_T ucReportFlag[MAX_ENDPOINT_NUM][MAX_CLUSTER_ID_NUM];
    UCHAR_T ucErrNum[MAX_CLUSTER_ID_NUM];
    UCHAR_T ucEpFlag[MAX_ENDPOINT_NUM];
    UCHAR_T ucFlag;
}DEV_BIND_REPORT_CFG_S;

#endif

typedef struct {
    CHAR_T nodeEuiStr[DEV_ID_MAX_LEN+1];
    USHORT_T profileId[MAX_ENDPOINT_NUM];
    USHORT_T devid[MAX_ENDPOINT_NUM];
    UCHAR_T ucEnd[MAX_ENDPOINT_NUM];
    UCHAR_T ucBindFlag[MAX_ENDPOINT_NUM];
    UCHAR_T ucBindNum;
    UCHAR_T ucEndNum;
    USHORT_T clusterIds[MAX_ENDPOINT_NUM][MAX_CLUSTER_ID_NUM];
    USHORT_T  usSipFlag;
    ADD_DEV_STAUTS_E dev_status;            //1:zigbee入网；2：读取基本信息状态；
                                           //3：读取特殊信息状态；4：进入tuya云邦定流程
    //CHAR_T cBasicFlag;//basic is read flag
    CHAR_T cSpcFlag;  //spc is read flag
    CHAR_T cBasicFlag;//表明basic全部读完
    CHAR_T zclVersion;
    CHAR_T hardwareVersion;
    CHAR_T appVer;          // tuya标准的识别格式为(00.00.0000)，其他的特殊处理
    CHAR_T manuName[MANU_NAME_MAX_LEN+1]; ///< Green power设备没有前缀，直接是PID
    CHAR_T modeId[MODE_ID_MAX_LEN+1];     
    CHAR_T date_code[PRODUCT_CODE_MAX_LEN+1];
    CHAR_T power_source;
    UCHAR_T ucType;
    UCHAR_T ucIsTypeVaild;
    time_t nowtimer;
    UCHAR_T ucNum;
    USHORT_T nodeid;
#if 1
    UCHAR_T ucFullBasicFlag;
    CHAR_T isOnlyReadOneFlag;//表明要一个一个去读basic信息
#endif
    CHAR_T cRejoinFlag;  //spc is read flag
#ifdef TY_FAST_JOIN
    CHAR_T isFastJoin;//支持快速添加
    ADD_DEV_BIND_STAUTS_E send_status;//消息是否发到上层
    UINT_T ucSendNum;
    UINT_T uddd;
    UINT_T uddd2;
    CHAR_T pid[PRODUCT_KEY_LEN+1];
    CHAR_T sw_ver[SW_VER_LEN+1];
#endif
    UCHAR_T ucReportStatus;
    BOOL_T isOem;
    UCHAR_T ucDevAbility[8];

    //CHAR_T product_code[PRODUCT_CODE_MAX_LEN+1];//tuya product key为16Byte
}DEV_Z3_DESC_IF_S;//

#ifdef TY_DEV_FW_CHECK
typedef struct dev_z3_fw_info_s {
    BOOL_T   isNeedRemoveDev;
    UCHAR_T  ucFwInfoReadFlag;
    UCHAR_T  fw_pub_key[TY_DEV_FW_CHECK_PUB_KEY_LEN];
    UCHAR_T  fw_sig[TY_DEV_FW_CHECK_SIG_LEN];
}DEV_Z3_FW_INFO_S;
#endif

typedef struct dev_z3_table_n_s {
    struct dev_z3_table_n_s *next;
    DEV_Z3_DESC_IF_S dev_if;
    unsigned int uiTime; // 新设备发面时为当前时间，定时检查，时间超过了，删掉？？？
#ifdef TY_DEV_FW_CHECK
    DEV_Z3_FW_INFO_S* fw_if;
#endif

#ifdef TY_BIND_REPORT
    DEV_BIND_REPORT_CFG_S bind_report_info;
    UINT_T debug_flag;
#endif
    CHAR_T country_code_flag;
    CHAR_T zclSeq[TY_ZCL_SEQ_TMP_NUM];
    UCHAR_T send_num;
}DEV_Z3_TABLE_N_S;

typedef struct dev_z3_del_table_n_s {
    struct dev_z3_del_table_n_s *next;
    CHAR_T nodeEuiStr[DEV_ID_MAX_LEN+1];
    DEL_DEV_STAUTS_E dev_status;
    unsigned int uiTime;
}DEV_Z3_DEL_TABLE_N_S;

typedef struct {
    DEV_Z3_TABLE_N_S *pDevTable;

    unsigned int uiDevTableNum;
}DEV_CNTL_S;

typedef struct {
    DEV_Z3_DEL_TABLE_N_S *pDevDelTable;

    unsigned int uiDevDelTableNum;
}DEV_DEL_CNTL_S;

typedef struct {
    CHAR_T nodeEuiStr[DEV_ID_MAX_LEN + 1];
    UINT_T cnt;//unit cnt
    UINT_T uint_len;//defult: 4bytes(time)+4bytes(errcode)
}DEV_ERRCODE_S;

typedef struct {
    CHAR_T nodeEuiStr[DEV_ID_MAX_LEN + 1];
    CHAR_T online_flag;
}DEV_FORCE_ONLINE_S;

#if 0// to tuya_z3_zigbee_base.h

typedef struct {
    UCHAR_T nodeEui64[TY_ZIGBEE_EUI64];
    USHORT_T nodeId;
    USHORT_T profileId;
    USHORT_T clusterId;
    UCHAR_T sourceEndpoint;
    UCHAR_T destinationEndpoint;
    USHORT_T groupId;
    UCHAR_T  cmdType; // 0x01 is global , 0x02 is private
    UCHAR_T  command;
    UCHAR_T frameType;//0单播，1组播，2广播。注：在fresh接口，表示的是版本号
    USHORT_T messageLength;
    UCHAR_T seqNum;
    BOOL_T isFindEnd;
    CHAR_T isNoAck;//是否不需要ack
    CHAR_T isArp;//是否通过广播来恢复路由
}TuYaApsFrameHeader;

typedef struct {
    TuYaApsFrameHeader sHeader;

    UCHAR_T *message;
} TuYaApsFrame;

typedef struct TY_NETWORK_INOF_S{
    UCHAR_T nodeEuiStr[DEV_ID_MAX_LEN];
    USHORT_T nodeId;
    USHORT_T panId;
    UCHAR_T netWorkKey[TY_NETWORK_KEY];
    UCHAR_T channel;
    UCHAR_T ver[SW_VER_LEN+1];
    UCHAR_T netStatus;
}TY_NETWORK_INOF_T;

typedef UCHAR_T TYEmberEUI64[TY_ZIGBEE_EUI64];

#define RF_MSG_LEN_MAX 16
typedef struct zigbee_rf_test_s {
    BOOL_T type;// true,即发即收
    UCHAR_T channel;
    USHORT_T numPackets;
    UCHAR_T length;
    CHAR_T power;
    UCHAR_T message[RF_MSG_LEN_MAX+1];//最大16byte
}ZIGBEE_RF_TEST_S;

typedef struct TY_DEV_DEL_S{
    UCHAR_T nodeEuiStr[DEV_ID_MAX_LEN+1];
    CHAR_T cFlag;//是否要ack，1，disable ack
}TY_DEV_DEL_T;
#endif

typedef struct {
    UCHAR_T dev_id[8];
    UCHAR_T install_code[18];
    INT_T   code_len;
    INT_T   index;
}INSTALL_CODE_INFO;

typedef enum {
    TY_CFG_NET_STOP,//停止配网
    TY_CFG_NET_TIME,//定时配网
    TY_CFG_NET_LONG //长配网 1小时
} TY_CFG_NET_STATUS_E;

#if 0
//typedef int (*Z3_DeviceJoin)(DEV_Z3_DESC_IF_S devDescIf);
typedef int (*Z3_DeviceJoin)(UCHAR_T nodeEui64[8], USHORT_T usProId, USHORT_T endpointIndex);

typedef int (*Z3_DeviceLeave)(UCHAR_T nodeEui64[8]);
typedef int (*Z3_ReadAttrRespCb)(USHORT_T clusterId, UCHAR_T* buffer, USHORT_T bufLen);
typedef int (*Z3_DeviceActiveEpCb)(UCHAR_T nodeEui64[8], UCHAR_T epNum, UCHAR_T *epNumVal);
typedef int (*Z3_ReportAttrbutesCb)(USHORT_T clusterId, UCHAR_T* buffer, USHORT_T bufLen);
typedef int (*z3_CommandReceivedCb)(EmberAfClusterCommand* cmd);

typedef struct {

    Z3_DeviceJoin  join_cb;
    Z3_DeviceLeave leave_cb;
    Z3_ReadAttrRespCb read_attr_resp_cb;
    Z3_DeviceActiveEpCb active_ep_cb;
    Z3_ReportAttrbutesCb report_attrbutes_cb;
    z3_CommandReceivedCb command_recv_cb;

}Z3_API_CB_S;
#endif

#define NODE_EUI64_TO_STRIN(nodeEuistr, nodeEui64) do{ \
sprintf(nodeEuistr,"%02x%02x%02x%02x%02x%02x%02x%02x", \
                                    (nodeEui64)[7]&0xFF, (nodeEui64)[6]&0xff, (nodeEui64)[5]&0xFF, (nodeEui64)[4]&0xFF,\
                                    (nodeEui64)[3]&0xFF, (nodeEui64)[2]&0xFF, (nodeEui64)[1]&0xFF, (nodeEui64)[0]&0xFF);}while(0)

#define NODE_STRIN_TO_EUI64(nodeEuistr, nodeEui64) do{ \
INT_T iTmp[8] = {0}; \
sscanf(nodeEuistr,"%02x%02x%02x%02x%02x%02x%02x%02x", &iTmp[7], &iTmp[6], &iTmp[5], &iTmp[4], &iTmp[3], &iTmp[2], &iTmp[1], &iTmp[0]);\
                (nodeEui64)[7] = iTmp[7]&0xFF; (nodeEui64)[6] = iTmp[6]&0xFF; (nodeEui64)[5] = iTmp[5]&0xFF; (nodeEui64)[4] = iTmp[4]&0xFF;\
                (nodeEui64)[3] = iTmp[3]&0xFF; (nodeEui64)[2] = iTmp[2]&0xFF; (nodeEui64)[1] = iTmp[1]&0xFF; (nodeEui64)[0] = iTmp[0]&0xFF;}while(0)



#define TY_LOW_BYTE(n)                     ((UCHAR_T)((n) & 0xFF))
#define TY_HIGH_BYTE(n)                    ((UCHAR_T)(TY_LOW_BYTE((n) >> 8)))
#define TY_HIGH_LOW_TO_SHORT(high, low) (((high) << 8) + ((low) & 0xFF))
#define TY_INT8U_TO_INT32U(byte3, byte2, byte1, byte0) (((byte3)<< 24) + ((byte2)<< 16) + ((byte1)<< 8) +((byte0) & 0xFF))
#define TY_INT8U_TO_FLOAT(byte3, byte2, byte1, byte0) (((((byte3) & 0xFF)) << 24) | ((((byte2) & 0xFF)) << 16) | ((((byte1) & 0xFF)) << 8) | ((byte0) & 0xFF))


// Global commands

// Either direction
#define TUYA_ZCL_READ_ATTRIBUTES_COMMAND_ID                       0x00 // Ver.: always
#define TUYA_ZCL_READ_ATTRIBUTES_RESPONSE_COMMAND_ID              0x01 // Ver.: always
#define TUYA_ZCL_WRITE_ATTRIBUTES_COMMAND_ID                      0x02 // Ver.: always
#define TUYA_ZCL_WRITE_ATTRIBUTES_UNDIVIDED_COMMAND_ID            0x03 // Ver.: always
#define TUYA_ZCL_WRITE_ATTRIBUTES_RESPONSE_COMMAND_ID             0x04 // Ver.: always
#define TUYA_ZCL_WRITE_ATTRIBUTES_NO_RESPONSE_COMMAND_ID          0x05 // Ver.: always
#define TUYA_ZCL_CONFIGURE_REPORTING_COMMAND_ID                   0x06 // Ver.: always
#define TUYA_ZCL_CONFIGURE_REPORTING_RESPONSE_COMMAND_ID          0x07 // Ver.: always
#define TUYA_ZCL_READ_REPORTING_CONFIGURATION_COMMAND_ID          0x08 // Ver.: always
#define TUYA_ZCL_READ_REPORTING_CONFIGURATION_RESPONSE_COMMAND_ID 0x09 // Ver.: always
#define TUYA_ZCL_REPORT_ATTRIBUTES_COMMAND_ID                     0x0A // Ver.: always
#define TUYA_ZCL_DEFAULT_RESPONSE_COMMAND_ID                      0x0B // Ver.: always
#define TUYA_ZCL_DISCOVER_ATTRIBUTES_COMMAND_ID                   0x0C // Ver.: always
#define TUYA_ZCL_DISCOVER_ATTRIBUTES_RESPONSE_COMMAND_ID          0x0D // Ver.: always
#define TUYA_ZCL_READ_ATTRIBUTES_STRUCTURED_COMMAND_ID            0x0E // Ver.: always
#define TUYA_ZCL_WRITE_ATTRIBUTES_STRUCTURED_COMMAND_ID           0x0F // Ver.: always
#define TUYA_ZCL_WRITE_ATTRIBUTES_STRUCTURED_RESPONSE_COMMAND_ID  0x10 // Ver.: always
#define TUYA_ZCL_DISCOVER_COMMANDS_RECEIVED_COMMAND_ID            0x11 // Ver.: always
#define TUYA_ZCL_DISCOVER_COMMANDS_RECEIVED_RESPONSE_COMMAND_ID   0x12 // Ver.: always
#define TUYA_ZCL_DISCOVER_COMMANDS_GENERATED_COMMAND_ID           0x13 // Ver.: always
#define TUYA_ZCL_DISCOVER_COMMANDS_GENERATED_RESPONSE_COMMAND_ID  0x14 // Ver.: always
#define TUYA_ZCL_DISCOVER_ATTRIBUTES_EXTENDED_COMMAND_ID          0x15 // Ver.: always
#define TUYA_ZCL_DISCOVER_ATTRIBUTES_EXTENDED_RESPONSE_COMMAND_ID 0x16 // Ver.: always

// Command types for cluster: Green Power
// Client to server
#define ZCL_GP_NOTIFICATION_COMMAND_ID 0x00 // Ver.: since gp-1.0-09-5499-24

#define TUYA_ZCL_BASIC_CLUSTER_ID                                               0x0000
#define TUYA_ZCL_POWER_CONFIG_CLUSTER_ID                                        0x0001
#define TUYA_ZCL_DEVICE_TEMP_CLUSTER_ID                                         0x0002
#define TUYA_ZCL_IDENTIFY_CLUSTER_ID                                            0x0003
#define TUYA_ZCL_GROUPS_CLUSTER_ID                                              0x0004
#define TUYA_ZCL_SCENES_CLUSTER_ID                                              0x0005
#define TUYA_ZCL_ON_OFF_CLUSTER_ID                                              0x0006
#define TUYA_ZCL_ON_OFF_SWITCH_CONFIG_CLUSTER_ID                                0x0007
#define TUYA_ZCL_LEVEL_CONTROL_CLUSTER_ID                                       0x0008
#define TUYA_ZCL_ALARM_CLUSTER_ID                                               0x0009
#define TUYA_ZCL_TIME_CLUSTER_ID                                                0x000A
#define TUYA_ZCL_RSSI_LOCATION_CLUSTER_ID                                       0x000B
#define TUYA_ZCL_BINARY_INPUT_BASIC_CLUSTER_ID                                  0x000F
#define TUYA_ZCL_COMMISSIONING_CLUSTER_ID                                       0x0015
#define TUYA_ZCL_PARTITION_CLUSTER_ID                                           0x0016
#define TUYA_ZCL_OTA_BOOTLOAD_CLUSTER_ID                                        0x0019
#define TUYA_ZCL_POWER_PROFILE_CLUSTER_ID                                       0x001A
#define TUYA_ZCL_APPLIANCE_CONTROL_CLUSTER_ID                                   0x001B
#define TUYA_ZCL_POLL_CONTROL_CLUSTER_ID                                        0x0020
#define TUYA_ZCL_GREEN_POWER_CLUSTER_ID                                         0x0021
#define TUYA_ZCL_KEEPALIVE_CLUSTER_ID                                           0x0025
#define TUYA_ZCL_SHADE_CONFIG_CLUSTER_ID                                        0x0100
#define TUYA_ZCL_DOOR_LOCK_CLUSTER_ID                                           0x0101
#define TUYA_ZCL_WINDOW_COVERING_CLUSTER_ID                                     0x0102
#define TUYA_ZCL_BARRIER_CONTROL_CLUSTER_ID                                     0x0103
#define TUYA_ZCL_PUMP_CONFIG_CONTROL_CLUSTER_ID                                 0x0200
#define TUYA_ZCL_THERMOSTAT_CLUSTER_ID                                          0x0201
#define TUYA_ZCL_FAN_CONTROL_CLUSTER_ID                                         0x0202
#define TUYA_ZCL_DEHUMID_CONTROL_CLUSTER_ID                                     0x0203
#define TUYA_ZCL_THERMOSTAT_UI_CONFIG_CLUSTER_ID                                0x0204
#define TUYA_ZCL_COLOR_CONTROL_CLUSTER_ID                                       0x0300
#define TUYA_ZCL_BALLAST_CONFIGURATION_CLUSTER_ID                               0x0301
#define TUYA_ZCL_ILLUM_MEASUREMENT_CLUSTER_ID                                   0x0400
#define TUYA_ZCL_ILLUM_LEVEL_SENSING_CLUSTER_ID                                 0x0401
#define TUYA_ZCL_TEMP_MEASUREMENT_CLUSTER_ID                                    0x0402
#define TUYA_ZCL_PRESSURE_MEASUREMENT_CLUSTER_ID                                0x0403
#define TUYA_ZCL_FLOW_MEASUREMENT_CLUSTER_ID                                    0x0404
#define TUYA_ZCL_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_ID                       0x0405
#define TUYA_ZCL_OCCUPANCY_SENSING_CLUSTER_ID                                   0x0406
#define TUYA_ZCL_CARBON_MONOXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID           0x040C
#define TUYA_ZCL_CARBON_DIOXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID            0x040D
#define TUYA_ZCL_ETHYLENE_CONCENTRATION_MEASUREMENT_CLUSTER_ID                  0x040E
#define TUYA_ZCL_ETHYLENE_OXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID            0x040F
#define TUYA_ZCL_HYDROGEN_CONCENTRATION_MEASUREMENT_CLUSTER_ID                  0x0410
#define TUYA_ZCL_HYDROGEN_SULPHIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID         0x0411
#define TUYA_ZCL_NITRIC_OXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID              0x0412
#define TUYA_ZCL_NITROGEN_DIOXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID          0x0413
#define TUYA_ZCL_OXYGEN_CONCENTRATION_MEASUREMENT_CLUSTER_ID                    0x0414
#define TUYA_ZCL_OZONE_CONCENTRATION_MEASUREMENT_CLUSTER_ID                     0x0415
#define TUYA_ZCL_SULFUR_DIOXIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID            0x0416
#define TUYA_ZCL_DISSOLVED_OXYGEN_CONCENTRATION_MEASUREMENT_CLUSTER_ID          0x0417
#define TUYA_ZCL_BROMATE_CONCENTRATION_MEASUREMENT_CLUSTER_ID                   0x0418
#define TUYA_ZCL_CHLORAMINES_CONCENTRATION_MEASUREMENT_CLUSTER_ID               0x0419
#define TUYA_ZCL_CHLORINE_CONCENTRATION_MEASUREMENT_CLUSTER_ID                  0x041A
#define TUYA_ZCL_FECAL_COLIFORM_AND_E_COLI_CONCENTRATION_MEASUREMENT_CLUSTER_ID 0x041B
#define TUYA_ZCL_FLUORIDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID                  0x041C
#define TUYA_ZCL_HALOACETIC_ACIDS_CONCENTRATION_MEASUREMENT_CLUSTER_ID          0x041D
#define TUYA_ZCL_TOTAL_TRIHALOMETHANES_CONCENTRATION_MEASUREMENT_CLUSTER_ID     0x041E
#define TUYA_ZCL_TOTAL_COLIFORM_BACTERIA_CONCENTRATION_MEASUREMENT_CLUSTER_ID   0x041F
#define TUYA_ZCL_TURBIDITY_CONCENTRATION_MEASUREMENT_CLUSTER_ID                 0x0420
#define TUYA_ZCL_COPPER_CONCENTRATION_MEASUREMENT_CLUSTER_ID                    0x0421
#define TUYA_ZCL_LEAD_CONCENTRATION_MEASUREMENT_CLUSTER_ID                      0x0422
#define TUYA_ZCL_MANGANESE_CONCENTRATION_MEASUREMENT_CLUSTER_ID                 0x0423
#define TUYA_ZCL_SULFATE_CONCENTRATION_MEASUREMENT_CLUSTER_ID                   0x0424
#define TUYA_ZCL_BROMODICHLOROMETHANE_CONCENTRATION_MEASUREMENT_CLUSTER_ID      0x0425
#define TUYA_ZCL_BROMOFORM_CONCENTRATION_MEASUREMENT_CLUSTER_ID                 0x0426
#define TUYA_ZCL_CHLORODIBROMOMETHANE_CONCENTRATION_MEASUREMENT_CLUSTER_ID      0x0427
#define TUYA_ZCL_CHLOROFORM_CONCENTRATION_MEASUREMENT_CLUSTER_ID                0x0428
#define TUYA_ZCL_SODIUM_CONCENTRATION_MEASUREMENT_CLUSTER_ID                    0x0429
#define TUYA_ZCL_PM25_CONCENTRATION_MEASUREMENT_CLUSTER_ID                      0x042A
#define TUYA_ZCL_FORMALDEHYDE_CONCENTRATION_MEASUREMENT_CLUSTER_ID              0x042B
#define TUYA_ZCL_IAS_ZONE_CLUSTER_ID                                            0x0500
#define TUYA_ZCL_IAS_ACE_CLUSTER_ID                                             0x0501
#define TUYA_ZCL_IAS_WD_CLUSTER_ID                                              0x0502
#define TUYA_ZCL_GENERIC_TUNNEL_CLUSTER_ID                                      0x0600
#define TUYA_ZCL_BACNET_PROTOCOL_TUNNEL_CLUSTER_ID                              0x0601
#define TUYA_ZCL_11073_PROTOCOL_TUNNEL_CLUSTER_ID                               0x0614
#define TUYA_ZCL_ISO7816_PROTOCOL_TUNNEL_CLUSTER_ID                             0x0615
#define TUYA_ZCL_PRICE_CLUSTER_ID                                               0x0700
#define TUYA_ZCL_DEMAND_RESPONSE_LOAD_CONTROL_CLUSTER_ID                        0x0701
#define TUYA_ZCL_SIMPLE_METERING_CLUSTER_ID                                     0x0702
#define TUYA_ZCL_MESSAGING_CLUSTER_ID                                           0x0703
#define TUYA_ZCL_TUNNELING_CLUSTER_ID                                           0x0704
#define TUYA_ZCL_PREPAYMENT_CLUSTER_ID                                          0x0705
#define TUYA_ZCL_ENERGY_MANAGEMENT_CLUSTER_ID                                   0x0706
#define TUYA_ZCL_CALENDAR_CLUSTER_ID                                            0x0707
#define TUYA_ZCL_DEVICE_MANAGEMENT_CLUSTER_ID                                   0x0708
#define TUYA_ZCL_EVENTS_CLUSTER_ID                                              0x0709
#define TUYA_ZCL_MDU_PAIRING_CLUSTER_ID                                         0x070A
#define TUYA_ZCL_SUB_GHZ_CLUSTER_ID                                             0x070B
#define TUYA_ZCL_KEY_ESTABLISHMENT_CLUSTER_ID                                   0x0800
#define TUYA_ZCL_INFORMATION_CLUSTER_ID                                         0x0900
#define TUYA_ZCL_DATA_SHARING_CLUSTER_ID                                        0x0901
#define TUYA_ZCL_GAMING_CLUSTER_ID                                              0x0902
#define TUYA_ZCL_DATA_RATE_CONTROL_CLUSTER_ID                                   0x0903
#define TUYA_ZCL_VOICE_OVER_ZIGBEE_CLUSTER_ID                                   0x0904
#define TUYA_ZCL_CHATTING_CLUSTER_ID                                            0x0905
#define TUYA_ZCL_PAYMENT_CLUSTER_ID                                             0x0A01
#define TUYA_ZCL_BILLING_CLUSTER_ID                                             0x0A02
#define TUYA_ZCL_APPLIANCE_IDENTIFICATION_CLUSTER_ID                            0x0B00
#define TUYA_ZCL_METER_IDENTIFICATION_CLUSTER_ID                                0x0B01
#define TUYA_ZCL_APPLIANCE_EVENTS_AND_ALERT_CLUSTER_ID                          0x0B02
#define TUYA_ZCL_APPLIANCE_STATISTICS_CLUSTER_ID                                0x0B03
#define TUYA_ZCL_ELECTRICAL_MEASUREMENT_CLUSTER_ID                              0x0B04
#define TUYA_ZCL_DIAGNOSTICS_CLUSTER_ID                                         0x0B05
#define TUYA_ZCL_ZLL_COMMISSIONING_CLUSTER_ID                                   0x1000
#define TUYA_ZCL_SAMPLE_MFG_SPECIFIC_CLUSTER_ID                                 0xFC00
#define TUYA_ZCL_OTA_CONFIGURATION_CLUSTER_ID                                   0xFC01
#define TUYA_ZCL_HM_AIR_QUALITY_CLUSTER_ID                                      0xFC81
#define TUYA_ZCL_TY_AIR_QUALITY_CLUSTER_ID                                      0xFC82
#define TUYA_ZCL_MFGLIB_CLUSTER_ID                                              0xFC


/******* private cluster id*******/
#define TUYA_ZCL_COMMON_PRIVATE_CLUSTER_ID                                      0XE000 //通用私有cluster,各品类共用
#define TUYA_ZCL_ELECTRICIAN_PRIVATE_CLUSTER_ID                                 0xE001 //私有cluster, 电工品类通用
#define TUYA_ZCL_SENSOR_PRIVATE_CLUSTER_ID                                      0xE002 //私有cluster, 传感品类通用
#define CMD_ALARM_DISARM_NOTIFICATION_COMMAND_ID                                0x00   //私有命令, 传感品类通用


/******* system dpid *******/
#define SYSTEM_DP_ID_CYCLE_TIMING     209 //循环定时
#define SYSTEM_DP_ID_RANDOM_TIMING    210 //随机定时

/******* TUYA_COMMON_PRIVATE_CLUSTER Attrbute*******/
#define PRIVATE_ATTR_ID_COMMON_PRIVATE_CYCLE_TIMING    0xD002 //循环定时
#define PRIVATE_ATTR_ID_COMMON_PRIVATE_RANDOM_TIMING   0xD001 //随机定时
#define PRIVATE_ATTR_ID_COMMON_PRIVATE_SWITCH_INCHING  0xD003 //点动开关


/*tuya com*/
#define TUYA_ZCL_COM_CLUSTER_ID           0xEF00
#define TUYA_ZCL_COM_SRC_EP               0x01
#define TUYA_ZCL_COM_DST_EP               0x01

#define REX_ZDO_PRIVATE_CLUSTER_ID        0x0FA0 //rex 佳宏温控器


#define TUYA_POWER_ON_STATUS_ATTR 0xFFE4 //basic里，设备上报，上报的属性，0x01表示刚上电


typedef enum {
    TUYA_ZCL_COM_DATA_REQUEST =     0x00,
    TUYA_ZCL_COM_DATA_RESPONE =     0x01,
    TUYA_ZCL_COM_DATA_REPORT =      0x02,
    TUYA_ZCL_COM_DATA_QUERY =       0x03,
    TY_MODULE_DATA_REQUEST =        0x04,
    TY_MODULE_DATA_RESPONE =        0x05,
    TY_MODULE_DATA_REPORT =         0x06,
    TY_MODULE_DATA_QUERY =          0x07,

    TUYA_ZCL_MCU_VERSION_REQ =          0x10,
    TUYA_ZCL_MCU_VERSION_RSP =          0x11,
    TUYA_ZCL_MCU_OTA_NOTIFY =           0x12,
    TUYA_ZCL_MCU_OTA_BLOCK_DATA_REP =   0x13,
    TUYA_ZCL_MCU_OTA_BLOCK_DATA_RSP =   0x14,
    TUYA_ZCL_MCU_OTA_RESULT_RPT =       0x15,

    TUYA_ZCL_DYNA_PWD_KEY =         0x20,
    TUYA_ZCL_ENCRYPT_BASE_KEY =     0x21,
    TUYA_ZCL_ENCRYPT_KEY =          0x22,
    TUYA_ZCL_REPORT_LOG =           0x23,   //lock
    TUYA_ZCL_MCU_SYNC_TIME =        0x24,
    TUYA_ZCL_INTERNET_STAT =        0x25,
	TUYA_ZCL_INTERNET_STAT_ACK =    0x26,

    TUYA_ZCL_TRD_DEV_ADD_REQ = 0x30,
    TUYA_ZCL_TRD_DEV_ADD_RSP = 0x31,
    TUYA_ZCL_TRD_DEV_ADD_CONF = 0x32,
    TUYA_ZCL_TRD_DEV_DEL_REQ = 0x33,
    TUYA_ZCL_TRD_DEV_DEL_RSP = 0x34,
    TUYA_ZCL_TRD_DEV_DATA_REQ = 0x35,
    TUYA_ZCL_TRD_DEV_DATA_RSP = 0x36,
    TUYA_ZCL_TRD_DEV_HB_REQ = 0x37,
    TUYA_ZCL_TRD_DEV_HB_RSP = 0x38,
    TUYA_ZCL_TRD_DEV_DATA_SYNC = 0x39,

    TUYA_ZCL_SESSIONE_KEY_REQ = 0x40,
    TUYA_ZCL_SESSIONE_KEY_RSP = 0x41,
    TUYA_ZCL_SESSIONE_KEY_ACK = 0x42,
    TUYA_ZCL_DYNA_PWD_REQ = 0x43,
    TUYA_ZCL_DYNA_PWD_ACK = 0x44,

    TUYA_FILE_SEND_NOTIFY = 0x50,
    TUYA_FILE_BLOCK_DATA_REQ = 0x51,
    TUYA_FILE_BLOCK_DATA_RSP = 0x52,
    TUYA_FILE_RECV_RESULT = 0x53,

    TUYA_ZCL_AUDIO_SCENE = 0x54,

    TUYA_ZCL_CMD_BUT,

} TY_PRO_CMD;


// ZCL attribute types
enum {
  TUYA_ZCL_NO_DATA_ATTRIBUTE_TYPE                        = 0x00, // No data
  TUYA_ZCL_DATA8_ATTRIBUTE_TYPE                          = 0x08, // 8-bit data
  TUYA_ZCL_DATA16_ATTRIBUTE_TYPE                         = 0x09, // 16-bit data
  TUYA_ZCL_DATA24_ATTRIBUTE_TYPE                         = 0x0A, // 24-bit data
  TUYA_ZCL_DATA32_ATTRIBUTE_TYPE                         = 0x0B, // 32-bit data
  TUYA_ZCL_DATA40_ATTRIBUTE_TYPE                         = 0x0C, // 40-bit data
  TUYA_ZCL_DATA48_ATTRIBUTE_TYPE                         = 0x0D, // 48-bit data
  TUYA_ZCL_DATA56_ATTRIBUTE_TYPE                         = 0x0E, // 56-bit data
  TUYA_ZCL_DATA64_ATTRIBUTE_TYPE                         = 0x0F, // 64-bit data
  TUYA_ZCL_BOOLEAN_ATTRIBUTE_TYPE                        = 0x10, // Boolean
  TUYA_ZCL_BITMAP8_ATTRIBUTE_TYPE                        = 0x18, // 8-bit bitmap
  TUYA_ZCL_BITMAP16_ATTRIBUTE_TYPE                       = 0x19, // 16-bit bitmap
  TUYA_ZCL_BITMAP24_ATTRIBUTE_TYPE                       = 0x1A, // 24-bit bitmap
  TUYA_ZCL_BITMAP32_ATTRIBUTE_TYPE                       = 0x1B, // 32-bit bitmap
  TUYA_ZCL_BITMAP40_ATTRIBUTE_TYPE                       = 0x1C, // 40-bit bitmap
  TUYA_ZCL_BITMAP48_ATTRIBUTE_TYPE                       = 0x1D, // 48-bit bitmap
  TUYA_ZCL_BITMAP56_ATTRIBUTE_TYPE                       = 0x1E, // 56-bit bitmap
  TUYA_ZCL_BITMAP64_ATTRIBUTE_TYPE                       = 0x1F, // 64-bit bitmap
  TUYA_ZCL_INT8U_ATTRIBUTE_TYPE                          = 0x20, // Unsigned 8-bit integer
  TUYA_ZCL_INT16U_ATTRIBUTE_TYPE                         = 0x21, // Unsigned 16-bit integer
  TUYA_ZCL_INT24U_ATTRIBUTE_TYPE                         = 0x22, // Unsigned 24-bit integer
  TUYA_ZCL_INT32U_ATTRIBUTE_TYPE                         = 0x23, // Unsigned 32-bit integer
  TUYA_ZCL_INT40U_ATTRIBUTE_TYPE                         = 0x24, // Unsigned 40-bit integer
  TUYA_ZCL_INT48U_ATTRIBUTE_TYPE                         = 0x25, // Unsigned 48-bit integer
  TUYA_ZCL_INT56U_ATTRIBUTE_TYPE                         = 0x26, // Unsigned 56-bit integer
  TUYA_ZCL_INT64U_ATTRIBUTE_TYPE                         = 0x27, // Unsigned 64-bit integer
  TUYA_ZCL_INT8S_ATTRIBUTE_TYPE                          = 0x28, // Signed 8-bit integer
  TUYA_ZCL_INT16S_ATTRIBUTE_TYPE                         = 0x29, // Signed 16-bit integer
  TUYA_ZCL_INT24S_ATTRIBUTE_TYPE                         = 0x2A, // Signed 24-bit integer
  TUYA_ZCL_INT32S_ATTRIBUTE_TYPE                         = 0x2B, // Signed 32-bit integer
  TUYA_ZCL_INT40S_ATTRIBUTE_TYPE                         = 0x2C, // Signed 40-bit integer
  TUYA_ZCL_INT48S_ATTRIBUTE_TYPE                         = 0x2D, // Signed 48-bit integer
  TUYA_ZCL_INT56S_ATTRIBUTE_TYPE                         = 0x2E, // Signed 56-bit integer
  TUYA_ZCL_INT64S_ATTRIBUTE_TYPE                         = 0x2F, // Signed 64-bit integer
  TUYA_ZCL_ENUM8_ATTRIBUTE_TYPE                          = 0x30, // 8-bit enumeration
  TUYA_ZCL_ENUM16_ATTRIBUTE_TYPE                         = 0x31, // 16-bit enumeration
  TUYA_ZCL_FLOAT_SEMI_ATTRIBUTE_TYPE                     = 0x38, // Semi-precision
  TUYA_ZCL_FLOAT_SINGLE_ATTRIBUTE_TYPE                   = 0x39, // Single precision
  TUYA_ZCL_FLOAT_DOUBLE_ATTRIBUTE_TYPE                   = 0x3A, // Double precision
  TUYA_ZCL_OCTET_STRING_ATTRIBUTE_TYPE                   = 0x41, // Octet string
  TUYA_ZCL_CHAR_STRING_ATTRIBUTE_TYPE                    = 0x42, // Character string
  TUYA_ZCL_LONG_OCTET_STRING_ATTRIBUTE_TYPE              = 0x43, // Long octet string
  TUYA_ZCL_LONG_CHAR_STRING_ATTRIBUTE_TYPE               = 0x44, // Long character string
  TUYA_ZCL_ARRAY_ATTRIBUTE_TYPE                          = 0x48, // Array
  TUYA_ZCL_STRUCT_ATTRIBUTE_TYPE                         = 0x4C, // Structure
  TUYA_ZCL_SET_ATTRIBUTE_TYPE                            = 0x50, // Set
  TUYA_ZCL_BAG_ATTRIBUTE_TYPE                            = 0x51, // Bag
  TUYA_ZCL_TIME_OF_DAY_ATTRIBUTE_TYPE                    = 0xE0, // Time of day
  TUYA_ZCL_DATE_ATTRIBUTE_TYPE                           = 0xE1, // Date
  TUYA_ZCL_UTC_TIME_ATTRIBUTE_TYPE                       = 0xE2, // UTC Time
  TUYA_ZCL_CLUSTER_ID_ATTRIBUTE_TYPE                     = 0xE8, // Cluster ID
  TUYA_ZCL_ATTRIBUTE_ID_ATTRIBUTE_TYPE                   = 0xE9, // Attribute ID
  TUYA_ZCL_BACNET_OID_ATTRIBUTE_TYPE                     = 0xEA, // BACnet OID
  TUYA_ZCL_IEEE_ADDRESS_ATTRIBUTE_TYPE                   = 0xF0, // IEEE address
  TUYA_ZCL_SECURITY_KEY_ATTRIBUTE_TYPE                   = 0xF1, // 128-bit security key
  TUYA_ZCL_UNKNOWN_ATTRIBUTE_TYPE                        = 0xFF // Unknown

};



// Attribute reading buffer location definitions
#define TUYA_ATTRIBUTE_BUFFER_ATTRIBUTEID_LOW_BITS  0
#define TUYA_ATTRIBUTE_BUFFER_ATTRIBUTEID_HIGH_BITS 1
#define TUYA_ATTRIBUTE_BUFFER_SUCCESS_CODE          2
#define TUYA_ATTRIBUTE_BUFFER_DATA_TYPE             3
#define TUYA_ATTRIBUTE_BUFFER_DATA_START            4

// Attribute reporting / IAS ZONE buffer location definitions
#define TUYA_ATTRIBUTE_BUFFER_REPORT_CLUSTERID_LOW_BITS  0
#define TUYA_ATTRIBUTE_BUFFER_REPORT_CLUSTERID_HIGH_BITS 1
#define TUYA_ATTRIBUTE_BUFFER_REPORT_DATA_TYPE           2
#define TUYA_ATTRIBUTE_BUFFER_REPORT_DATA_START          3

#define TUYA_ATTRIBUTER_READ_REPORT_HEADER   3 // attributerid(2B) + status(1B)
#define TUYA_ATTRIBUTER_REPORT_HEADER   2 // attributerid(2B)

#define TUYA_ATTRIBUTER_DATA_TYPE_LEN 1

#define NETWORK_FORM_CMD     0x0001
#define NETWORK_WORK_CMD     0x0002
#define NETWORK_INFO_REQ     0x0003
#define DEV_DEL_CMD          0x0004
#define DEV_DATA_CMD         0x0005
#define MSG_COMM_OK_REQ      0x0006
#define DATE_TIME_RSP        0x0007
#define COO_UPDATE_REQ       0x0008
#define DEV_UPDATE_REQ       0x0009
#define DEV_UPDATE_BLOCK_REQ 0x000A
#define DEV_RF_TEST_REQ      0x000B
#define DEV_RF_TEST_RESULT_REQ 0x000C
#define DEV_NET_RECOVER_REQ       0x000D
#define GW_RESET_FACTORY_REQ      0x0011 //
#define GW_COUNTRY_CODE_SET       0x0012 //
#define DATA_ZONE                 0x0013
#define FAULT_REPLACE             0x0014
#define SET_NCP_MAC               0x0015
#define DEV_WHITE_LIST_ADD        0x0016
#define NETWORK_EXPAN_INFO_REQ    0x0017
#define NETWORK_INFO_BAK_NOTIFY   0x0018 //Zigbee网络信息配置备份通知
#define COO_SUPPORT_MAC_WRITE_NOTIFY     0x0019 //NCP 支持mac写入通知
#define COO_MAC_RECOVERY                 0x001A //NCP MAC恢复命令
#define GET_STATISTIC_INFO        0x0020 //DEBUG:获取统计信息

#define DEV_JOIN_CB_CMD        0x1001
#define DEV_LEAV_CB_CMD        0x1002
#define NETWORK_INFO_RSP       0x1003
#define DEV_DATA_REPORT_CB_CMD 0x1004
#define DEV_ONLINE_FRESH_CMD   0x1005
#define MSG_COMM_OK_RSP        0x1006
#define DATE_TIME_REQ          0x1007
#define COO_UPDATE_RSP         0x1008
#define DEV_UPDATE_RSP         0x1009
#define DEV_UPDATE_BLOCK_RSP   0x100A
#define DEV_RF_TEST_RSP        0x100B
#define DEV_RF_TEST_RESULT_RSP 0x100C
#define DEV_NET_RECOVER_RSP    0x100D
#define DEV_RESET_FACTORY_RSP  0x100E
#define DEV_IDENTIFY_TIME_CMD  0x100F
#define DEV_ERRCODE_RPT_CMD    0x1010
#define DEV_COO_VER            0x1011
#define DEV_FORCE_ONOFFLINE    0x1012
#define DEV_DEV_ANNOUNCE_CMD   0x1013
#define NETWORK_EXPAN_INFO_RSP 0x0014


#define NETWORK_FORM_DEBUG_CMD     0x2001
#define NETWORK_WORK_DEBUG_CMD     0x2002
#define NETWORK_INFO_DEBUG_REQ     0x2003
#define DEV_DEL_DEBUG_CMD          0x2004
#define DEV_DATA_DEBUG_CMD         0x2005
#define MSG_COMM_OK_DEBUG_REQ      0x2006
#define DATE_TIME_DEBUG_RSP        0x2007
#define COO_UPDATE_DEBUG_REQ       0x2008
#define INTALL_CODE_SET            0x2009
#define GRP_SCE_CMD_REP            0x2010
#define GET_DEV_NODEID_DEBUG_CMD   0x2011


#define PLUGIN_COUNTER_DEBUG_PRINT_REQ       0x20F0
#define SET_RADIO_POWER                      0x20F1
#define DEV_REPORT_QOS_RSP                   0x20F2
#define GET_ROUTE_TABLE_RSP                  0x20F3

#define Z3_GET_ROUTE_AND_LQI        0x0000       //get route & LQI
#define Z3_GET_ONE_NODE_LQI         0x0001       //get the eui64_str nodeID's QOS
#define Z3_GET_ROUTE_AND_UPLOAD     0xFFFF       //get route then upload to cloud


#define DEV_JOIN_CB_DEBUG_CMD        0x3001
#define DEV_LEAV_CB_DEBUG_CMD        0x3002
#define NETWORK_INFO_DEBUG_RSP       0x3003
#define DEV_DATA_REPORT_CB_DEBUG_CMD 0x3004
#define DEV_ONLINE_FRESH_DEBUG_CMD   0x3005
#define MSG_COMM_OK_DEBUG_RSP        0x3006
#define DATE_TIME_DEBUG_REQ          0x3007
#define COO_UPDATE_DEBUG_RSP         0x3008
#define GET_DEV_NODEID_DEBUG_RSP     0x3011

#define GW_SET_DEV_MAX_CNT           0xFF01
#define GW_SET_USER_CMD_SEND         0xFF02

#define TUYA_SIMPLE_DATA_TYPE_1Byte   0x01
#define TUYA_SIMPLE_DATA_TYPE_2Byte   0x02
#define TUYA_SIMPLE_DATA_TYPE_3Byte   0x03
#define TUYA_SIMPLE_DATA_TYPE_4Byte   0x04
#define TUYA_SIMPLE_DATA_TYPE_5Byte   0x05
#define TUYA_SIMPLE_DATA_TYPE_6Byte   0x06
#define TUYA_SIMPLE_DATA_TYPE_7Byte   0x07
#define TUYA_SIMPLE_DATA_TYPE_8Byte   0x08
#define TUYA_SIMPLE_DATA_TYPE_16Byte  0x09

#define TUYA_SIMPLE_DATA_TYPE_STARING      0x0a
#define TUYA_SIMPLE_DATA_TYPE_LONG_STARING 0x0b

typedef struct NET_PARAM_S
{
    BOOL_T isAuto;
    BOOL_T centralizedNetwork;
    USHORT_T panId;
    UCHAR_T radioTxPower;
    UCHAR_T channel;

}NET_PARAM_T;



#define UDDD_GET_TY_PROID(uddd, usTyProfileId)          do{(usTyProfileId) = ((uddd) >> 16) & 0x0F;}while(0)
#define UDDD_GET_TY_DEVID(uddd, usTyDevId)              do{(usTyDevId) = ((uddd) >> 8) & 0xFF;}while(0)
#define UDDD_GET_TY_TYPE(uddd, ucTyType)                do{(ucTyType) = (uddd) & 0xFF;}while(0)
#define UDDD_GET_TY_STANDARD_DP(uddd, ucStandardDpFlag) do{(ucStandardDpFlag) = ((uddd) >> 21) & 0x01;}while(0)
#define UDDD_GET_TY_SLEPP_FLAG(uddd, ucSleepFlag)       do{(ucSleepFlag) = ((uddd) >> 24) & 0x01;}while(0)
#define UDDD_GET_TY_DATA_VER(uddd, dataVer)             do{(dataVer) = ((uddd) >> 27) & 0x07;}while(0)

#define UDDD_TY_STANDARD_DP_BIT         (1 << 21)
#define UDDD_TY_SLEPP_FLAG_BIT          (1 << 24)
#define UDDD_TY_ZIGBEE_UPDATE_BIT          (1 << 25)
#define IS_UDDD_DEVICE_TYPE_EQUAL(_uddd1, _uddd2)       (((_uddd1) & 0xfffff) == ((_uddd2) & 0xfffff))

#define TY_UDDD2_ZB_SUB_PACKAGE   28 // 1 表示zigbee大数据分包传输能力
#define TY_UDDD2_ZB_GRP_FLAG      29 // 1 表示zigbee群组遥控能力,群组操作时需要特殊处理
#define TY_UDD2_FAST_JOIN_FLAG    30 // 1 表示是快速添加的设备，可以优化一些处理流程
#define TY_UDD2_CUSTOMER_DEV      31 // 1 表示是客户设备，不让用uddd1

/*
uddd1:
4Byte

    7 6       5 4 3       2         1       0      7 6 5 4    3 2 1 0    7 6 5 4 3 2 1 0   7 6 5 4 3 2 1 0
| reserved | version | encrypt | update | sleep  |  manu   | profileid |       deivid    |      type      |
version: gw and zigbee module data format version, 0x0 ~ 0x7
manu: tuya, rex, common,... is 0

////////////////////////////////////////////////////////
uddd2:
BIT30:1表示是快速添加的设备，可以优化一些处理流程
BIT31:1表示是客户设备，不让用uddd1


*/

/*
    HA:
        profile id: 0x0104 -> 0x0
        device  id:
                    0x0402 -> 0x00
                    0x0302 -> 0x01
                    ...
*/

#define TY_COMMEN_MANU  0x00 // 0~15

#define TY_PROFILE_ID_HA 0x00 // 0~15

#define TY_DEVID_HA_IAS_ZONE                    0x00      // 0x0402 -> 0x00，IAS类，pir, 门磁
#define TY_DEVID_HA_TEMPERATURE_SENSOR          0x01      // 0x0302 -> 0x01，温度类（含温湿度）
#define TY_DEVID_HA_ONOF_LIGHT                  0x02      // 0x0100 -> 0x02，照明开关类
#define TY_DEVID_HA_SMART_PLUG                  0x03      // 0x0051 -> 0x03, 智能类插座类
#define TY_DEVID_HA_MAINS_POWER_OUTLET          0x04      // 0x0009 -> 0x04, 非智能类插座
#define TY_DEVID_HA_HEATING_COOLING_UNIT        0x05      // 0x0300 -> 0x05, 地暖
#define TY_DEVID_HA_THERMOSTAT                  0x06      // 0x0301 -> 0x06, 空调，新风系统
#define TY_DEVID_HA_WINDOW_COVERING             0x07      // 0x0202 -> 0x07, 窗帘电机
#define TY_DEVID_HA_SCENE_SELECTOR              0x08      // 0x0004 -> 0x08, 场景
#define TY_DEVID_HA_DOOR_LOCK                   0x09      // 0x000A -> 0x09, 门锁
#define TY_DEVID_HA_ANC_CTR_EQUIPMENT           0x0a      // 0x0401 -> 0x0a, 辅助控制设备，如遥控器
#define TY_DEVID_HA_DIMMABLE_LIGHT              0x0b      // 0x0101 -> 0x0b, 调光灯
#define TY_DEVID_HA_COLOR_DIMMABLE_LIGHT        0x0c      // 0x0102 -> 0x0c, 调色灯
#define TY_DEVID_HA_ON_OFF_SWITCH               0x0d      // 0x0000 -> 0x0d, on/off switch
#define TY_DEVID_HA_OCCUPANCY_SENSOR            0x0e      // 0x0107 -> 0x0e, occupancy sensor
#define TY_DEVID_HA_IAS_WARNING_DEVICE          0x0f      // 0x0403 -> 0x0f，标准报警器
#define TY_DEVID_HA_SHADE                       0x10      // 0x0200 -> 0x10, 窗帘开关
#define TY_DEVID_HA_SIMPLE_SENSOR               0x11      // 0x000C -> 0x11, 采集类传感器
#define TY_DEVID_HA_REMOTE_DIMMABLE_SWITCH      0x12      // 0x0104 -> 0x12, 灯光遥控器
#define TY_DEVID_HA_SIMPLE_SENSOR_LIGHT         0x13      // 0x0106 -> 0x13, 亮度传感器
#define TY_DEVID_HA_WIRELESS_REMOTE_CONTROL     0x14      // 0xF000 -> 0x14, 无线遥控器

/*
    LL or standard:
        profile id: 0xC05E -> 0x1
        device  id:
                    0x0200 -> 0x00
                    0x0210 -> 0x01
                    0x0220 -> 0x02
                    ...
*/
#define TY_PROFILE_ID_LL 0x01

#define TY_DEVID_LL_COLOR_LIGHT             0x00      // 0x0200 -> 0x00, 色彩灯
#define TY_DEVID_LL_EXTENDED_COLOR_LIGHT    0x01      // 0x0210 -> 0x01, 色温色彩灯
#define TY_DEVID_LL_COLOR_TEMPERATURE_LIGHT 0x02      // 0x0220 -> 0x02, 色温灯
#define TY_DEVID_LL_DIMMABLE_LIGHT          0x03      // 0x0100 -> 0x03, 调光灯
#define TY_DEVID_LL_OnOff_LIGHT             0x04      // 0x0000 -> 0x04, 开关灯,或者开关
#define TY_DEVID_LL_OnOff_Plugin            0x05      // 0x0010 -> 0x05, 插座

/*
    Zigbee Repeater:
        profile id: 0x0104 -> 0x2
        device  id:
                    0xFE00 -> 0x00

                    ...
*/
#define TY_PROFILE_ID_RPT 0x02//Repeater
#define TY_DEVID_RPT_485_CONTROLLER         0x00       //三级架构连接器


#define TY_COM0_NUM0    0x00
#define TY_COM0_NUM1    0x01
#define TY_COM0_NUM2    0x02
#define TY_COM0_NUM3    0x03
#define TY_COM0_NUM4    0x04
#define TY_COM0_NUM5    0x05
#define TY_COM0_NUM6    0x06
#define TY_COM0_NUM7    0x07
#define TY_COM0_NUM8    0x08
#define TY_COM0_NUM9    0x09

#define TY_COM1_NUM0    0x10
#define TY_COM1_NUM1    0x11
#define TY_COM1_NUM2    0x12
#define TY_COM1_NUM3    0x13
#define TY_COM1_NUM4    0x14
#define TY_COM1_NUM5    0x15
#define TY_COM1_NUM6    0x16
#define TY_COM1_NUM7    0x17
#define TY_COM1_NUM8    0x18
#define TY_COM1_NUM9    0x19

#define TY_MANU_INDEX            20 ///<通用对接
#define TY_STANDARD_DP_INDEX     21 ///<标准DP
#define TY_RESET_FACTORY_INDEX   22 ///<恢复出厂设置
#define TY_MCU_UPDATE_FLAG_INDEX 23 ///<支持MCU升级
#define TY_SLEEP_FLAG_INDEX      24 ///<休眠设备
#define TY_UPDATE_FLAG_INDEX     25 ///<支持zigbee升级
#define TY_ENCRYPT_FLAG_INDEX    26 ///<支持加密
#define TY_DATA_VER_INDEX        27 ///<支持可靠传输
#define TY_STD_RELIABLE_INDEX    30 ///<标准dp支持下的私有dp透传能力,标准dp走标准指令,私有dp走透传
#define TY_AUTHKEY_FLAG_INDEX    31 ///<支持预制密钥通道加密

#define DEVID_INDEX  8
/******   device id: TU_DEVID_HA_IAS_ZONE 0x00 ******/
#define TY_TYPE_PIR                    0x00
#define TY_TYPE_DOOR_SENSOR            0x01
#define TY_TYPE_FIRE_SENSOR            0x02
#define TY_TYPE_WATER_SENSOR           0x03
#define TY_TYPE_CARBON_MONOXIDE        0x04
#define TY_TYPE_REMOTE_ALARM           0x05
#define TY_TYPE_SHOCK_SENSOR           0x06
#define TY_TYPE_STANDARD_WARING_DEVICE 0x07
#define TY_TYPE_REMOTE_ALARM_B         0x08



#define TY_IAS_ZONE_PIR                        0x01000000 //pir
#define TY_IAS_ZONE_DOOR_SENSOR                0x01000001 //门磁
#define TY_IAS_ZONE_FIRE_SENSOR                0x01000002 //烟雾
#define TY_IAS_ZONE_WATER_SENSOR               0x01000003 //水浸
#define TY_IAS_ZONE_CARBON_MONOXIDE            0x00000004 //可燃气体
#define TY_IAS_ZONE_REMOTE_ALARM               0x00000005 //报警器 非休眠设备
#define TY_IAS_ZONE_REMOTE_ALARM_SLEEP         0x01000005 //报警器    休眠设备
#define TY_IAS_ZONE_SHOCK_SENSOR               0x01000006 //震动传感器
#define TY_IAS_ZONE_REMOTE_ALARM_B             0x00000008 //报警器 真非休眠设备

/* ========================================= 博世多功能传感 ========================================= */
#define UDDD_GET_TY_MANU(uddd, usTyManu) do{(usTyManu) = ((uddd >> 4) & 0x0F);}while(0)
#define TY_MANU_BOSCH                           0X01 //厂商标识
#define TY_TYPE_BOSCH_PIR                       0x10
#define TY_BOSCH_IAS_ZONE_PIR                   0x41200010 //pir
#define TY_TYPE_BOSCH_DOOR_SENSOR               0x11
#define TY_BOSCH_IAS_ZONE_DOOR_SENSOR           0x01200011 //门磁
#define TY_TYPE_BOSCH_WATER_SENSOR              0x13
#define TY_BOSCH_IAS_ZONE_WATER_SENSOR          0x41200013 //水浸

//command
#define TY_ZONE_STATUS_CHANGE_NOTIFI 0x00
#define TY_ZONE_ENROLL_REQUEST       0x01


//通用对接，默认都支持升级
#define TY_COM_UDDD             0x02000000 //休眠通过power source来区分
#define TY_COM_SCENE_UDDD       0x02000800 //devid 08 scene, type bit4=0表示自研，瑞赢的是1


/*   device id: TU_DEVID_HA_TEMPERATURE_SENSOR 0x01 */
#define TY_TYPE_TEMPERATURE_SENSOR           0x00
#define TY_TYPE_TEMPERATURE_SENSOR_HUM       0x01
#define TY_TYPE_HUMIDITY_SENSOR              0x02
#define TY_TYPE_HM_AIR_SENSOR                0x03
#define TY_TYPE_TY_AIR_SENSOR                0x04


#define TY_HA_TEMPERATURE_SENSOR               0x01000100 //温度
#define TY_HA_TEMPERATURE_SENSOR_HUM           0x01000101 //温湿度
#define TY_HA_HUMIDITY_SENSOR_HUM              0x01000102 //湿度

/******   device id: TU_DEVID_HA_ONOF_LIGHT 0x02 ******/
#define TY_TYPE_ONOF_LIGHT_MAX                 10
#define TY_TYPE_ONOF_LIGHT_ONE                 0x00
#define TY_TYPE_ONOF_LIGHT_TWO                 0x01
#define TY_TYPE_ONOF_LIGHT_THREE               0x02
#define TY_TYPE_ONOF_LIGHT_FOUR                0x03
#define TY_TYPE_ONOF_LIGHT_FIVE                0x04
#define TY_TYPE_ONOF_LIGHT_SIX                 0x05
#define TY_TYPE_ONOF_LIGHT_SEVEN               0x06
#define TY_TYPE_ONOF_LIGHT_EGHIT               0x07
#define TY_TYPE_ONOF_LIGHT_NINE                0x08
#define TY_TYPE_ONOF_LIGHT_TEN                 0x09

#define TY_HA_ONOF_LIGHT_ONE                   0x00000200 //一路照明开关
#define TY_HA_ONOF_LIGHT_TWO                   0x00000201 //二路照明开关
#define TY_HA_ONOF_LIGHT_THREE                 0x00000202 //三路照明开关
#define TY_HA_ONOF_LIGHT_FOUR                  0x00000203 //四路照明开关
#define TY_HA_ONOF_LIGHT_FIVE                  0x00000204 //五路照明开关
#define TY_HA_ONOF_LIGHT_SIX                   0x00000205 //六路照明开关
#define TY_HA_ONOF_LIGHT_SEVEN                 0x00000206 //七路照明开关
#define TY_HA_ONOF_LIGHT_EGHIT                 0x00000207 //八路照明开关
#define TY_HA_ONOF_LIGHT_NINE                  0x00000208 //九路照明开关
#define TY_HA_ONOF_LIGHT_TEN                   0x00000209 //十路照明开关

//标准DP开关
#define TY_HA_ONOF_STANDARD_LIGHT_ONE          0x00200200 //一路照明开关,标准DP
#define TY_HA_ONOF_STANDARD_LIGHT_TWO          0x00200201 //二路照明开关,标准DP
#define TY_HA_ONOF_STANDARD_LIGHT_THREE        0x00200202 //三路照明开关,标准DP
#define TY_HA_ONOF_STANDARD_LIGHT_FOUR         0x00200203 //四路照明开关,标准DP
#define TY_HA_ONOF_STANDARD_LIGHT_FIVE         0x00200204 //五路照明开关,标准DP
#define TY_HA_ONOF_STANDARD_LIGHT_SIX          0x00200205 //六路照明开关,标准DP
#define TY_HA_ONOF_STANDARD_LIGHT_SEVEN        0x00200206 //七路照明开关,标准DP
#define TY_HA_ONOF_STANDARD_LIGHT_EGHIT        0x00200207 //八路照明开关,标准DP
#define TY_HA_ONOF_STANDARD_LIGHT_NINE         0x00200208 //九路照明开关,标准DP
#define TY_HA_ONOF_STANDARD_LIGHT_TEN          0x00200209 //十路照明开关,标准DP

//西蒙1 2 3 4路开关
/*
    type 8位 | 0 0 0 1 |  |0 0 0 0|
             置1代表西蒙
             设备

*/
#define TY_HA_XM_ONE_LIGHT                     0x02000210
#define TY_HA_XM_TWO_LIGHT                     0x02000211
#define TY_HA_XM_THREE_LIGHT                   0x02000212
#define TY_HA_XM_FOUR_LIGHT                    0x02000213

/*XM DEVICE TYPE: ON/OFF LIGHT*/
#define XM_DP_ID_ON_OFF_LIGHT_SWITCH1       1
#define XM_DP_ID_ON_OFF_LIGHT_SWITCH2       2
#define XM_DP_ID_ON_OFF_LIGHT_SWITCH3       3
#define XM_DP_ID_ON_OFF_LIGHT_SWITCH4       4
#define XM_DP_ID_ON_OFF_LIGHT_COUNTDOWN1     7
#define XM_DP_ID_ON_OFF_LIGHT_COUNTDOWN2     8
#define XM_DP_ID_ON_OFF_LIGHT_COUNTDOWN3     9
#define XM_DP_ID_ON_OFF_LIGHT_COUNTDOWN4     10
#define XM_DP_ID_ON_OFF_LIGHT_LIGHT_MODE     101

//其他特殊定制开关
/*
    type 8位 |   1 0 0 0     |  |0 0 0 0|
              置1代表特殊定制
*/
#define TY_HA_JP_ONOF_LIGHT_ONE 0x00000280 //佳普插卡定制开关
#define TY_HA_HM_ONOF_LIGHT_AP  0x00000281 //海鳗AP中继
#define TY_HA_ZH_ONOF_LIGHT_ONE 0x00000282 //智慧燃气开关
#define TY_HA_SC_ONOF_LIGHT_ONE 0x00000283 //世创IO模块

//command
#define TY_DPID_MAX_COLOUR_HUE_VALUE                360  //色度    H
#define TY_ZCL_MAX_COLOUR_HUE_VALUE                 254

#define TY_DPID_MAX_COLOUR_SATURATION_VALUE         1000  //饱和 S
#define TY_ZCL_MAX_COLOUR_SATURATION_VALUE          254

#define TY_DPID_MAX_COLOUR_LEVEL_VALUE              1000  //明度 V
#define TY_ZCL_MAX_COLOUR_LEVEL_VALUE               255

#define TY_DPID_MAX_COLOUR_BRIGHT_VALUE             1000  //色温
#define TY_ZCL_MAX_COLOUR_BRIGHT_VALUE              255


#define TY_ZCL_OFF_COMMAND_ID         0x00
#define TY_ZCL_ON_COMMAND_ID          0x01
#define TY_ZCL_TOGGLE_COMMAND_ID      0x02
#define TY_ZCL_ON_WITH_TIMED_OFF_COMMAND    0x42

#define TY_ZCL_ON_OFF_TIME_COMMAND_ID 0x42

#define TY_ZCL_WINDOW_COVER_UP_OPEN      0x00
#define TY_ZCL_WINDOW_COVER_DOWN_CLOSE   0x01
#define TY_ZCL_WINDOW_COVER_STOP         0x02

//UYA_ZCL_LEVEL_CONTROL_CLUSTER_ID                                       0x0008
#define TY_ZCL_MOVE_TO_LEVEL_COMMAND_ID                 0x00
#define TY_ZCL_STOP_LEVEL_CONTROL_COMMAND_ID            0x03
#define TY_ZCL_MOVE_TO_LEVEL_WITH_ON_OFF_COMMAND_ID     0x04

//TUYA_ZCL_COLOR_CONTROL_CLUSTER_ID                                       0x0300
#define TY_ZCL_MOVE_TO_COLOR_TMP_COMMAND_ID             0x0a

#define TY_ZCL_MOVE_TO_SATUR_COMMAND_ID                 0x03
#define TY_ZCL_MOVE_TO_HUE_AND_SATUR_COMMAND_ID         0x06
#define TY_ZCL_CHANGE_LIGHT_MODE_COMMAND_ID             0xf0
#define TY_ZCL_SET_SENCE_MODE_COMMAND_ID                0xf1
#define TY_ZCL_SEND_REAL_TIME_CTL_COMMAND_ID            0xf2
#define TY_ZCL_SET_SIG_COLOR_SENCE_MODE_COMMAND_ID      0xf3
#define TY_ZCL_SLEEP_MODE_COMMAND_ID                    0xf4 //入睡模式
#define TY_ZCL_WAKEUP_MODE_COMMAND_ID                   0xf5 //唤醒模式
#define TY_ZCL_RHYTHM_MODE_COMMAND_ID                   0xf6 //生物节率
#define TY_ZCL_RANDOM_TIMING_COMMAND_ID                 0xf7 //随机定时
#define TY_ZCL_CYCLE_TIMING_COMMAND_ID                  0xf8 //循环定时
#define TY_ZCL_POWER_MEMORY_COMMAND_ID                  0xf9 //断电记忆
#define TY_ZCL_DISTURB_MODE_COMMAND_ID                  0xfa //勿扰模式
#define TY_ZCL_SWITCH_INCHING_COMMAND_ID                0xfb //点动开关
#define TY_ZCL_POWER_STATUS_COMMAND_ID                  0xfc //上电状态 
#define TY_ZCL_MIX_LIGHT_COMMAND_ID                     0xe2 //混光
#define TY_ZCL_MIX_LIGHT_SCENES_COMMAND_ID              0xe3 //混光场景
#define TY_ZCL_NIGHT_LIGHT_COMMAND_ID                   0xe4 //小夜灯
#define TY_ZCL_SEGMENT_DIMMING_COMMAND_ID               0xe5 //分段调光

//DIMMABLE_LIGHT私有指令
#define TY_DIMMABLE_LIGHT_WHITE_BRIGHT_COMMAND_ID       0Xf0//白光亮度
#define TY_DIMMABLE_LIGHT_WHITE_TEMP_COMMAND_ID         0xe0//白光色温
#define TY_DIMMABLE_LIGHT_COLOURFUL_COMMAND_ID          0xe1//彩光颜色
#define TY_DIMMABLE_LIGHT_COUNTDOWN_COMMAND_ID          0xf0//倒计时
#define TY_DIMMABLE_LIGHT_SWITCH_GRADIENT_COMMAND_ID    0xfb//开关渐变

#define TY_REMOTE_DIMMABLE_SWITCH_COMMAND_ID            0xF7///< 白光/彩光场景下发命令

//BASIC COMMAND ID
#define TY_ZCL_BASIC_RESET_FACTORY                      0x00
#define TY_ZCL_BASIC_RESET_DATA_FACTORY                 0xf0



/******   device id: TY_DEVID_HA_SMART_PLUG 0x03 ******/

/******
type:
common:
   7        6        5         4         3       2 1 0
|  0  | reserved | button | 10/16A  | measure  |  8路  |

special:
   7     6543210
|  1  |   type   |

simon: 如果第七位置1 代表西蒙插座10A 16A，作特殊处理
   7     6543210
|  1  |   type   |



******/
#define SPEC_INDEX    6
#define BUTTON_INDEX  5
#define CURRENT_INDEX 4
#define MEASURE_INDEX 3

#define TY_NO_MEASURE_TYPE  0x00
#define TY_MEASURE_TYPE     0x01

#define TY_CURRENT_TYPE_10A 0x00
#define TY_CURRENT_TYPE_16A 0x01

#define TY_BUTTON_TYPE_NO   0x00
#define TY_BUTTON_TYPE_YES  0x01


#define TY_SOCKET_NUM1    0x00
#define TY_SOCKET_NUM2    0x01
#define TY_SOCKET_NUM3    0x02
#define TY_SOCKET_NUM4    0x03
#define TY_SOCKET_NUM5    0x04
#define TY_SOCKET_NUM6    0x05
#define TY_SOCKET_NUM7    0x06
#define TY_SOCKET_NUM8    0x07

#define UDDD_GET_TY_MEASURE_FLAG(uddd, ucMeasureFlag)       do{(ucMeasureFlag) = ((uddd) >> MEASURE_INDEX) & 0x01;}while(0)

//eg



#define TY_HA_SMART_PLUG_MEASURE_BUT_ONE_10A       0x00000328 //计量 一路 10A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_ONE_16A       0x00000338 //计量 一路 16A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_TWO_10A       0x00000329 //计量 二路 10A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_TWO_16A       0x00000339 //计量 二路     16A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_THREE_10A     0x0000032a //计量 三路     10A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_THREE_16A     0x0000033a //计量 三路     16A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_FOUR_10A      0x0000032b //计量 四路     10A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_FOUR_16A      0x0000033b //计量 四路     16A插座,带按键

//标准DP插座
#define TY_HA_SMART_PLUG_MEASURE_BUT_ONE_STANDARD_DP_10A       0x00200328 //计量 一路 10A插座,带按键           标准DP设备
#define TY_HA_SMART_PLUG_MEASURE_BUT_ONE_STANDARD_DP_16A       0x00200338 //计量 一路 16A插座,带按键           标准DP设备

//西蒙10A 16A 插座
#define TY_HA_XM_ONE_SOCKET_MEASURE_10A       0x000003a8 //西蒙计量 一路 10A插座,带按键
#define TY_HA_XM_ONE_SOCKET_MEASURE_16A       0x000003b8 //西蒙计量 一路 16A插座,带按键

//计量，带按键，五路到八路插座uddd是根据一路到四路的uddd定义规则猜出来的，目前还没有实际接入这样的设备
#define TY_HA_SMART_PLUG_MEASURE_BUT_FIVE_10A       0x0000032c //计量 五路 10A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_FIVE_16A       0x0000033c //计量 五路 16A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_SIX_10A        0x0000032d //计量 六路 10A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_SIX_16A        0x0000033d //计量 六路     16A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_SEVEN_10A      0x0000032e //计量 七路     10A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_SEVEN_16A      0x0000033e //计量 七路     16A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_EIGHT_10A      0x0000032f //计量 八路     10A插座,带按键
#define TY_HA_SMART_PLUG_MEASURE_BUT_EIGHT_16A      0x0000033f //计量 八路     16A插座,带按键


#define TY_HA_SMART_PLUG_MEASURE_NBUT_ONE_10A       0x00000308 //计量 一路 10A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_ONE_16A       0x00000318 //计量 一路 16A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_TWO_10A       0x00000309 //计量 二路 10A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_TWO_16A       0x00000319 //计量 二路     16A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_THREE_10A     0x0000030a //计量 三路     10A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_THREE_16A     0x0000031a //计量 三路     16A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_FOUR_10A      0x0000030b //计量 四路     10A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_FOUR_16A      0x0000031b //计量 四路     16A插座,不带按键

//计量，不带按键，五路到八路插座uddd是根据一路到四路的uddd定义规则猜出来的，目前还没有实际接入这样的设备
#define TY_HA_SMART_PLUG_MEASURE_NBUT_FIVE_10A       0x0000030c //计量 五路 10A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_FIVE_16A       0x0000031c //计量 五路 16A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_SIX_10A        0x0000030d //计量 六路 10A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_SIX_16A        0x0000031d //计量 六路     16A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_SEVEN_10A      0x0000030e //计量 七路     10A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_SEVEN_16A      0x0000031e //计量 七路     16A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_EIGHT_10A      0x0000030f //计量 八路     10A插座,不带按键
#define TY_HA_SMART_PLUG_MEASURE_NBUT_EIGHT_16A      0x0000031f //计量 八路     16A插座,不带按键

//OEM
#define TY_HA_SMART_PLUG_RESETSTA_NO_MEASURE_BUT_STANDARD_DP_ONE        0x00200320 //非计量 一路 10A插座,带按键 标准dp设备
#define TY_HA_SMART_PLUG_RESETSTA_NO_MEASURE_BUT_STANDARD_DP_TWO        0x00200321 //非计量 二路 10A插座,带按键            标准dp设备


/******   device id: TY_DEVID_HA_MAINS_POWER_OUTLET 0x04 ******/

#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_ONE_10A    0x00000420 //非计量 一路 10A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_ONE_16A    0x00000430 //非计量 一路 16A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_TWO_10A    0x00000421 //非计量 二路 10A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_TWO_16A    0x00000431 //非计量 二路 16A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_THREE_10A  0x00000422 //非计量 三路 10A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_THREE_16A  0x00000432 //非计量 三路 16A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_FOUR_10A   0x00000423 //非计量 四路 10A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_FOUR_16A   0x00000433 //非计量 四路 16A插座,带按键

//standard dp_id
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_ONE_STANDARD_DP_10A    0x00200420 //非计量 一路 10A插座,带按键，标准DP设备
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_THREE_STANDARD_DP_10A    0x00200422 //非计量 五路 10A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_FIVE_STANDARD_DP_10A    0x00200424 //非计量 五路 10A插座,带按键
#define TY_HA_SMART_PLUG_STANDARD_DP_FULL                       0x00200429 //全功能插座,支持1~8路

//非计量，带按键，五路到八路插座uddd是根据一路到四路的uddd定义规则猜出来的，目前还没有实际接入这样的设备
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_FIVE_10A    0x00000424 //非计量 五路 10A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_FIVE_16A    0x00000434 //非计量 五路 16A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_SIX_10A     0x00000425 //非计量 六路 10A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_SIX_16A     0x00000435 //非计量 六路 16A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_SEVEN_10A   0x00000426 //非计量 七路 10A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_SEVEN_16A   0x00000436 //非计量 七路 16A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_EIGHT_10A   0x00000427 //非计量 八路 10A插座,带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_BUT_EIGHT_16A   0x00000437 //非计量 八路 16A插座,带按键

#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_ONE_10A    0x00000400 //非计量 一路 10A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_ONE_16A    0x00000410 //非计量 一路 16A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_TWO_10A    0x00000401 //非计量 二路 10A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_TWO_16A    0x00000411 //非计量 二路 16A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_THREE_10A  0x00000402 //非计量 三路 10A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_THREE_16A  0x00000412 //非计量 三路 16A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_FOUR_10A   0x00000403 //非计量 四路 10A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_FOUR_16A   0x00000413 //非计量 四路 16A插座,不带按键

//standard dp_id
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_TWO_STANDARD_DP_10A    0x00200401 //非计量 二路 10A插座,不带按键，标准DP设备


//非计量，不带按键，五路到八路插座uddd是根据一路到四路的uddd定义规则猜出来的，目前还没有实际接入这样的设备
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_FIVE_10A    0x00000404 //非计量 五路 10A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_FIVE_16A    0x00000414 //非计量 五路 16A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_SIX_10A     0x00000405 //非计量 六路 10A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_SIX_16A     0x00000415 //非计量 六路 16A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_SEVEN_10A   0x00000406 //非计量 七路 10A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_SEVEN_16A   0x00000416 //非计量 七路 16A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_EIGHT_10A   0x00000407 //非计量 八路 10A插座,不带按键
#define TY_HA_SMART_PLUG_NO_MEASURE_NBUT_EIGHT_16A   0x00000417 //非计量 八路 16A插座,不带按键

/************special*****************/
//type
#define TY_HA_SMART_PLUG_SPECIAL_TYPE      0x80   ///计量(一路计量，一路非计量) 二路 10A插座,带按键
//uddd
#define TY_HA_SMART_PLUG_SPECIAL_TWO      0x00000380 //计量(一路计量，一路非计量) 二路 10A插座,带按键



/******   device id: TY_DEVID_HA_HEATING_COOLING_UNIT 0x05 ******/
/*
type:
common:
   7     6 5  4           3             2        1      0
|  0 |  reserved  | thermostat(mode) | Fan ctr | hum | temp |

special:
    7      6543210
|  tuya |   type    |

special:
   7     6 5  4           3             2        1      0
|  0 |   0 0  1| thermostat(mode) | Fan ctr | hum | temp |
     |  simon  |


*/
#define HEATCOOL_TUYA_INDEX 7
#define TY_HA_HEATCOOL_MODE_FAN_TEMP       0x0000050b //地暖含温，湿度，模式
#define TY_HA_HEATCOOL_MODE_FAN_HUM_TEMP   0x00000509 //地暖温度，模式

#define TY_HA_HEATCOOL_MODE_FAN_TEMP_TY       0x0000058b //涂鸦地暖含温，湿度，模式
#define TY_HA_HEATCOOL_MODE_FAN_HUM_TEMP_TY   0x00000589 //涂鸦地暖温度，模式

#define TY_HA_HEATCOOL_MODE_FAN_HEAT_XM 0x0000051c //西蒙地暖含模式 风控


/******   device id: TY_DEVID_HA_THERMOSTAT 0x06 ******/

/*
type:
common:
   7     6 5  4           3             2        1      0
|  0 |  reserved  | thermostat(mode) | Fan ctr | hum | temp |

special:
    7    6543210
|  tuya |  type  |

special:
     7   |    6   |   5     | 4    |          3     |    2    |   1 |   0
| reserve| reserve|  温控器 | 空调 |thermostat(mode) | Fan ctr | hum | temp |
西蒙空调第四位置1  特殊处理
西蒙温控器第五位置1
*/

#define HA_TEMPCTR_XM_INDEX             5   // 西蒙温控器
#define HA_THERMOSTAT_XM_INDEX          4   // 西蒙
#define HA_THERMOSTAT_THERMOSTAT_INDEX  3
#define HA_THERMOSTAT_FAN_INDEX         2
#define HA_THERMOSTAT_HUM_INDEX         1
#define HA_THERMOSTAT_TEMP_INDEX        0
#define UDDD_GET_XM_THERMOSTAT_FLAG(uddd, ucMeasureFlag)       do{(ucMeasureFlag) = ((uddd) >> HA_THERMOSTAT_XM_INDEX) & 0x01;}while(0)
#define UDDD_GET_XM_TEMPCTR_FLAG(uddd, ucMeasureFlag)          do{(ucMeasureFlag) = ((uddd) >> HA_TEMPCTR_XM_INDEX) & 0x01;}while(0)

#define TY_HA_THERMOSTAT_FAN_TEMP            0x00000605 //新风系统含风速，温度
#define TY_HA_THERMOSTAT_MODE_FAN_HUM_TEMP   0x0000060F //空调含模式，风速，湿度，温度
#define TY_HA_THERMOSTAT_TRANS               0x00000600 //佳宏透传，30个功能点透传

#define TY_HA_THERMOSTAT_FAN_TEMP_TY            0x00000685 //涂鸦新风系统含风速，温度
#define TY_HA_THERMOSTAT_MODE_FAN_HUM_TEMP_TY   0x0000068F //涂鸦空调含模式，风速，湿度，温度

#define TY_XM_WATER_TEMP_CTRL       0x0000061c //西蒙中央空调 模式 风速
#define TY_HA_XM_FRESH_AIR          0x00000614 //西蒙新风机 风速
#define TY_HA_XM_HAIXIN_TEMP_CTRL   0x0000061f //西蒙海信日立空调 模式 风速 湿度 温度
#define TY_XM_ALLINONE_TEMP_CTRL    0x00000620 //西蒙多合一温控器


/******   device id: TY_DEVID_HA_WINDOW_COVERING 0x07 ******/
#define TY_WINDOWCOVER_TYPE_NO_POSTITION    0x00 //窗帘电机，不含位置信息
#define TY_WINDOWCOVER_TYPE_POSTITION       0x01 //窗帘电机，含位置信息
#define TY_WINDOWCOVER_TYPE_POSTITION_DY    0x02 //窗帘电机，含位置信息，杜亚，兼容历史遗留pid不一样
#define TY_WINDOWCOVER_TYPE_NEW_SOC         0x03 //新版本自研窗帘开关，标准dp
#define TY_WINDOWCOVER_TYPE_CURTAIN_MOTOR   0x04 //健达窗帘电机

#define TY_HA_WINDOW_COVERING_NO_POS            0x00000700 //窗帘电机, 不含位置信息
#define TY_HA_WINDOW_COVERING_POSITION          0x00000701 //窗帘电机, 含位置信息,公版
#define TY_HA_WINDOW_COVERING_POSITION_DY       0x00000702 //窗帘电机, 含位置信息
#define TY_HA_WINDOW_COVERING_NEW_SOC           0x02000703
#define TY_HA_WINDOW_CURTAIN_MOTOR              0x00200704 //健达窗帘电机


#define WINDOW_COVERING_CMD_UP_OPEN        0x00
#define WINDOW_COVERING_CMD_DOWN_CLOSE     0x01
#define WINDOW_COVERING_CMD_STOP           0x02
#define WINDOW_COVERING_CMD_GOTOLIFTVAL    0x04
#define WINDOW_COVERING_CMD_GOTOLIFTPER    0x05

/*******FanMode[CLOUD]*******/
#define CLOUD_FAN_LOW_WIND      0x00     /*低风*/
#define CLOUD_FAN_MIDDLE_WIND   0x01     /*中风*/
#define CLOUD_FAN_HIGH_WIND     0x02     /*大风*/
#define CLOUD_FAN_AUTO          0x03     /*自动*/

/*******FanMode[DEV]*******/
#define FAN_OFF           0x00     /*关闭风扇*/
#define FAN_LOW_WIND      0x01     /*低风*/
#define FAN_MIDDLE_WIND   0x02     /*中风*/
#define FAN_HIGH_WIND     0x03     /*大风*/
#define FAN_ON            0x04     /*打开风扇*/
#define FAN_AUTO          0x05     /*自动*/
#define FAN_SMART         0x06     /*智能*/

/*******AcWorkMode*******/
#define AC_OFF 0           /*关闭空调*/
#define AC_AUTO 1          /*自动*/
#define AC_COLD 3          /*制冷*/
#define AC_HEAT 4          /*制热*/
#define AC_EMERG_HEAT 5    /*紧急加热*/
#define AC_PRE_COLD 6      /*预冷*/
#define AC_WIND 7          /*送风*/
#define AC_DEHUM 8         /*除湿*/
#define AC_SLEEP 9         /*睡眠*/
#define AC_ON 10           /*打开空调*/
    /*DEVICE TYPE: REAL_DTP_ENV_FRESH_AIR */
#define DP_ID_FRESH_AIR_POWER 1
#define DP_ID_FRESH_AIR_FAN_MODE 4

    /*DEVICE TYPE: REAL_DTP_ENV_ONE_AC */
#define DP_ID_ONE_AC_TEMP_POWER 1
#define DP_ID_ONE_AC_TEMP_SET 2
#define DP_ID_ONE_AC_TEMP_CUR 3
#define DP_ID_ONE_AC_WORK_MODE 4
#define DP_ID_ONE_AC_WIND_SPEED 5

/************************service dev attr**************************/
/*******serv_ac_work_mode*******/
#define SERV_AC_MODE_COLD 0
#define SERV_AC_MODE_HOT 1
#define SERV_AC_MODE_WET 2
#define SERV_AC_MODE_WIND 3
#define SERV_AC_MODE_WIND_XM 2  //西蒙温控器送风为2
#define SERV_AC_MODE_WET_XM 3


/*******serv_ac_power*******/
#define SERV_AC_OFF 0
#define SERV_AC_ON 1

/*******serv_water_sensor_alarm*******/
#define SERV_WATER_ALARM_SENSOR_LOSS 0
#define SERV_WATER_ALARM_BATTERY_LOW 1
#define SERV_WATER_ALARM_OVERFLOW 2
#define SERV_WATER_ALARM_NONE 3

/*******curtain_switch*******/
#define SERV_CURTAIN_OPEN 0
#define SERV_CURTAIN_CLOSE 1
#define SERV_CURTAIN_STOP 2

/*DEVICE TYPE: REAL_DTP_ENV_CURTAIN */
#define DP_ID_CURTAIN_POS 101
#define DP_ID_CURTAIN_MACH_OPER 102
#define DP_ID_CURTAIN_OPPOSITE 103


/*STANDARD DEVICE DP_ID*/
/*STANDARD DEVICE TYPE: SMARTPLUG*/

#define STANDARD_DP_ID_SMARTPLUG_SWITCH1       1
#define STANDARD_DP_ID_SMARTPLUG_SWITCH2       2
#define STANDARD_DP_ID_SMARTPLUG_SWITCH3       3
#define STANDARD_DP_ID_SMARTPLUG_SWITCH4       4
#define STANDARD_DP_ID_SMARTPLUG_SWITCH5       5
#define STANDARD_DP_ID_SMARTPLUG_SWITCH6       6
#define STANDARD_DP_ID_SMARTPLUG_SWITCH7       7
#define STANDARD_DP_ID_SMARTPLUG_SWITCH8       8
#define STANDARD_DP_ID_SMARTPLUG_COUNTDOWN1    9
#define STANDARD_DP_ID_SMARTPLUG_COUNTDOWN2   10
#define STANDARD_DP_ID_SMARTPLUG_COUNTDOWN3   11
#define STANDARD_DP_ID_SMARTPLUG_COUNTDOWN4   12
#define STANDARD_DP_ID_SMARTPLUG_COUNTDOWN5   13
#define STANDARD_DP_ID_SMARTPLUG_COUNTDOWN6   14
#define STANDARD_DP_ID_SMARTPLUG_COUNTDOWN7   15
#define STANDARD_DP_ID_SMARTPLUG_COUNTDOWN8   16
#define STANDARD_DP_ID_SMARTPLUG_TOTAL_ELEC   17
#define STANDARD_DP_ID_SMARTPLUG_CUR_CURRENT  18
#define STANDARD_DP_ID_SMARTPLUG_CUR_POWER    19
#define STANDARD_DP_ID_SMARTPLUG_CUR_VOL      20
#define STANDARD_DP_ID_SMARTPLUG_FAULT        26
#define STANDARD_DP_ID_SMARTPLUG_RELAY_STATUS 27
#define STANDARD_DP_ID_SMARTPLUG_LIGHT_MODE   28
#define STANDARD_DP_ID_SMARTPLUG_CHILD_LOCK   29
#define STANDARD_DP_ID_SMARTPLUG_ALARM_MNG 30
#define STANDARD_DP_ID_SMARTPLUG_BACKLIGHT_MODE  31


/*STANDARD DEVICE TYPE: ON/OFF LIGHT*/
#define STANDARD_DP_ID_ON_OFF_LIGHT_SWITCH1       1
#define STANDARD_DP_ID_ON_OFF_LIGHT_SWITCH2       2
#define STANDARD_DP_ID_ON_OFF_LIGHT_SWITCH3       3
#define STANDARD_DP_ID_ON_OFF_LIGHT_SWITCH4       4
#define STANDARD_DP_ID_ON_OFF_LIGHT_SWITCH5       5
#define STANDARD_DP_ID_ON_OFF_LIGHT_SWITCH6       6
#define STANDARD_DP_ID_ON_OFF_LIGHT_COUNTDOWN1    7
#define STANDARD_DP_ID_ON_OFF_LIGHT_COUNTDOWN2    8
#define STANDARD_DP_ID_ON_OFF_LIGHT_COUNTDOWN3    9
#define STANDARD_DP_ID_ON_OFF_LIGHT_COUNTDOWN4   10
#define STANDARD_DP_ID_ON_OFF_LIGHT_COUNTDOWN5   11
#define STANDARD_DP_ID_ON_OFF_LIGHT_COUNTDOWN6   12
#define STANDARD_DP_ID_ON_OFF_LIGHT_SWITCH_ALL   13
#define STANDARD_DP_ID_ON_OFF_LIGHT_RELAY_STATUS 14
#define STANDARD_DP_ID_ON_OFF_LIGHT_LIGHT_MODE   15
#define STANDARD_DP_ID_ON_OFF_LIGHT_BACKLIGHT_MODE   16
#define STANDARD_DP_ID_ON_OFF_LIGHT_SWITCH_INCHING   19
#define STANDARD_DP_ID_ON_OFF_LIGHT_RELAY_STATUS_1   29
#define STANDARD_DP_ID_ON_OFF_LIGHT_RELAY_STATUS_2   30
#define STANDARD_DP_ID_ON_OFF_LIGHT_RELAY_STATUS_3   31
#define STANDARD_DP_ID_ON_OFF_LIGHT_RELAY_STATUS_4   32
#define STANDARD_DP_ID_ON_OFF_LIGHT_RELAY_STATUS_5   33
#define STANDARD_DP_ID_ON_OFF_LIGHT_RELAY_STATUS_6   34  
#define STANDARD_DP_ID_ON_OFF_SWITCH_TYPE        47

#define TY_HIDDEN_ON_OFF_ATTRIBUTE_ID   0xD030        //暗合通断器attrId

/*STANDARD DEVICE TYPE: THERMOSTAT*/
#define STANDARD_DP_ID_THERMOSTAT_SWITCH                  1
#define STANDARD_DP_ID_THERMOSTAT_TEMP_SET                2
#define STANDARD_DP_ID_THERMOSTAT_TEMP_CUR                3
#define STANDARD_DP_ID_THERMOSTAT_MODE                    4
#define STANDARD_DP_ID_THERMOSTAT_FAULT                  13
#define STANDARD_DP_ID_THERMOSTAT_VALVE_CHECK            20
#define STANDARD_DP_ID_THERMOSTAT_SLEEP                  22
#define STANDARD_DP_ID_THERMOSTAT_RESET                  28
#define STANDARD_DP_ID_THERMOSTAT_LOW_TEMP_PROTECT       29
#define STANDARD_DP_ID_THERMOSTAT_FILTER_ALARM_FUNC      30
#define STANDARD_DP_ID_THERMOSTAT_FILTER_ALARM_CYCLE     31
#define STANDARD_DP_ID_THERMOSTAT_FILTER_ALARM           32
#define STANDARD_DP_ID_THERMOSTAT_FILTER_BY_PASS         33
#define STANDARD_DP_ID_THERMOSTAT_FILTER_BY_PASS_FUNC    34
#define STANDARD_DP_ID_THERMOSTAT_COMSTATUS              35
#define STANDARD_DP_ID_THERMOSTAT_WINDCTRL               36
#define STANDARD_DP_ID_THERMOSTAT_WINDSPEED              57
#define STANDARD_DP_ID_THERMOSTAT_WIND_DIRECTION         58
#define STANDARD_DP_ID_THERMOSTAT_BACKLIGHT              59
#define PRIVATE_DP_ID_THERMOSTAT_COLD_HOT_SWITCH         101

/* ========================================= 免开发窗帘开关 ========================================= */
// 1, STANDARD DEVICE TYPE: WINDOW_COVERING
#define STANDARD_DP_ID_WINDOW_COVERING_SWITCH1              1   // 设备控制
#define STANDARD_DP_ID_WINDOW_COVERING_SWITCH2              4   // 设备控制2
#define STANDARD_DP_ID_WINDOW_COVERING_PERCENT1             2   // 百分比
#define STANDARD_DP_ID_WINDOW_COVERING_PERCENT2             5   // 百分比2
#define STANDARD_DP_ID_WINDOW_COVERING_CUR1_CALIBRATION     3   // 行程校准
#define STANDARD_DP_ID_WINDOW_COVERING_CUR2_CALIBRATION     6   // 行程校准2

#define STANDARD_DP_ID_WINDOW_COVERING_BACKLIGHT            7   // 背光

#define STANDARD_DP_ID_WINDOW_COVERING_CONTROL_BACK         8   // 电机反转
#define STANDARD_DP_ID_WINDOW_COVERING_CONTROL_BACK2        9   // 电机反转2
#define STANDARD_DP_ID_WINDOW_COVERING_TR1_TIMECON          10   // 行程时间设置
#define STANDARD_DP_ID_WINDOW_COVERING_TR2_TIMECON          11   // 行程时间设置2
#define STANDARD_DP_ID_WINDOW_COVERING_ELEC_MACHINERY_MODE  12  // 电机模式
#define STANDARD_DP_ID_WINDOW_COVERING_ELEC_MACHINERY_MODE2 13  // 电机模式2

#define STANDARD_DP_ID_WINDOW_COVERING_LIGHT_MODE           14  // 指示灯状态设置
// 2, window covering attr value
#define STANDARD_ATTR_ID_WINDOW_COVERING_PERCENT              (0x0008)
#define STANDARD_ATTR_ID_WINDOW_COVERING_BACKLIGHT            (0x5000)
#define PRIVATE_ATTR_ID_WINDOW_COVERING_SWITCH               (0xf000)
#define PRIVATE_ATTR_ID_WINDOW_COVERING_CUR_CALIBRATION      (0xf001)
#define PRIVATE_ATTR_ID_WINDOW_COVERING_CONTROL_BACK         (0xf002)
#define PRIVATE_ATTR_ID_WINDOW_COVERING_TR_TIMECON           (0xf003)
#define PRIVATE_ATTR_ID_WINDOW_COVERING_ELEC_MACHINERY_MODE  (0x8000)
#define PRIVATE_ATTR_ID_WINDOW_COVERING_LIGHT_MODE           (0x8001)
// 3, uddd
#define TY_HA_WINDOW_COVERING_UDDD_SOC              0x2600703  // 二路

/* ========================================= 健达窗帘电机 ========================================= */
//1.dpid
#define STANDARD_DP_ID_WINDOW_COVERING_CURTAIN_MOTOR_CONTROL        1//设备控制
#define STANDARD_DP_ID_WINDOW_COVERING_CURTAIN_MOTOR_PERCENT        2//开启百分比控制
#define STANDARD_DP_ID_WINDOW_COVERING_CURTAIN_MOTOR_CONTROL_BACK   5//电机反向
#define STANDARD_DP_ID_WINDOW_COVERING_CURTAIN_MOTOR_PERCENT_MEAN   11//百分比含义
#define STANDARD_DP_ID_WINDOW_COVERING_CURTAIN_MOTOR_FAULT          12//故障告警
#define STANDARD_DP_ID_WINDOW_COVERING_CURTAIN_MOTOR_SET_LIMIT      16//设置限位
//2.dttributes
#define PRIVATE_ATTR_ID_WINDOW_COVERING_CURTAIN_MOTOR_CONTROL       0xF000
#define STANDARD_ATTR_ID_WINDOW_COVERING_CURTAIN_MOTOR_PERCENT      0x0008
#define PRIVATE_ATTR_ID_WINDOW_COVERING_CURTAIN_MOTOR_CONTROL_BACK  0xF002
#define PRIVATE_ATTR_ID_WINDOW_COVERING_CURTAIN_MOTOR_PERCENT_MEAN  0xE000
#define PRIVATE_ATTR_ID_WINDOW_COVERING_CURTAIN_MOTOR_FAULT         0xF000
#define PRIVATE_ATTR_ID_WINDOW_COVERING_CURTAIN_MOTOR_SET_LIMIT     0xE001

/* ========================================= 西蒙多合一温控器 ========================================= */
//1.dpid
#define DP_ID_TEMPCTR_THERMOSTAT_POWER          1    /**空调开关*/
#define DP_ID_TEMPCTR_THERMOSTAT_CENTROL_CTR    117 /**空调集控状态*/
#define DP_ID_TEMPCTR_FLOORHEAT_POWER           118 /**地暖开关*/
#define DP_ID_TEMPCTR_FLOORHEAT_MODE            119 /**地暖情景模式*/
#define DP_ID_TEMPCTR_FLOORHEAT_TEMP_SET        120 /**地暖设置温度*/
#define DP_ID_TEMPCTR_FLOORHEAT_VALVE_SAT       121 /**地暖阀状态*/
#define DP_ID_TEMPCTR_FLOORHEAT_ERROR_CODE      122 /**地暖错误码*/
#define DP_ID_TEMPCTR_FRESHAIR_SAT              123 /**新风功能状态,是否支持*/
#define DP_ID_TEMPCTR_FRESHAIR_POWER            124 /**新风开关*/
#define DP_ID_TEMPCTR_FRESHAIR_MODE             125 /**新风模式*/
#define DP_ID_TEMPCTR_FRESHAIR_WIND_SPEED       126 /**新风风速*/
#define DP_ID_TEMPCTR_FRESHAIR_FILTER_ALM       127 /**新风滤网报警*/
#define DP_ID_TEMPCTR_FRESHAIR_FILTER_ALM_RM    128 /**新风滤网报警解除*/
#define DP_ID_TEMPCTR_MODE_CONFLICT             129 /**模式冲突指示*/
#define DP_ID_TEMPCTR_ALL_POWER                 130 /**对空调、地暖、新风进行总开关*/
#define DP_ID_TEMPCTR_FRESHAIR_FILTER_ALM_EN    131 /**是否启用新风滤网报警*/
#define DP_ID_TEMPCTR_THERMOSTAT_MODE_LOCK      132 /**空调冷热锁定*/
//2.dttributes
#define PRIVATE_ATTR_ID_TEMPCTR_THERMOSTAT_POWER        0x9002
#define PRIVATE_ATTR_ID_TEMPCTR_THERMOSTAT_TEMP_SET     0x0011
#define PRIVATE_ATTR_ID_TEMPCTR_CURRENT_TEMP            0x0000
#define PRIVATE_ATTR_ID_TEMPCTR_THERMOSTAT_MODE         0x001C
#define PRIVATE_ATTR_ID_TEMPCTR_THERMOSTAT_ERROR_CODE   0x9001
#define PRIVATE_ATTR_ID_TEMPCTR_THERMOSTAT_WIND_SPEED   0x0000
#define PRIVATE_ATTR_ID_TEMPCTR_THERMOSTAT_FAN_DIRECT   0x9000
#define PRIVATE_ATTR_ID_TEMPCTR_THERMOSTAT_MODE_LOCK    0x9003
#define PRIVATE_ATTR_ID_TEMPCTR_BACKLIGHT               0x9009
#define PRIVATE_ATTR_ID_TEMPCTR_COMSTATUS               0x900A
#define PRIVATE_ATTR_ID_TEMPCTR_THERMOSTAT_CENTROL_CTR  0x9000
#define PRIVATE_ATTR_ID_TEMPCTR_FLOORHEAT_POWER         0x9004
#define PRIVATE_ATTR_ID_TEMPCTR_FLOORHEAT_MODE          0x9005
#define PRIVATE_ATTR_ID_TEMPCTR_FLOORHEAT_TEMP_SET      0x0012
#define PRIVATE_ATTR_ID_TEMPCTR_FLOORHEAT_VALVE_SAT     0x9006
#define PRIVATE_ATTR_ID_TEMPCTR_FLOORHEAT_ERROR_CODE    0x9007
#define PRIVATE_ATTR_ID_TEMPCTR_FRESHAIR_SAT            0x9001
#define PRIVATE_ATTR_ID_TEMPCTR_FRESHAIR_POWER          0x9002
#define PRIVATE_ATTR_ID_TEMPCTR_FRESHAIR_MODE           0x9003
#define PRIVATE_ATTR_ID_TEMPCTR_FRESHAIR_WIND_SPEED     0x9004
#define PRIVATE_ATTR_ID_TEMPCTR_FRESHAIR_FILTER_ALM     0x9005
#define PRIVATE_ATTR_ID_TEMPCTR_FRESHAIR_FILTER_ALM_RM  0x9006
#define PRIVATE_ATTR_ID_TEMPCTR_MODE_CONFLICT           0x9008
#define PRIVATE_ATTR_ID_TEMPCTR_ALL_POWER               0x0000
#define PRIVATE_ATTR_ID_TEMPCTR_FRESHAIR_FILTER_ALM_EN  0x9007


/*DEVICE TYPE: REAL_DTP_XM_WATER_TEMP_CTRL REAL_DTP_XM_WATER_ELECTRIC_HEAT REAL_DTP_XM_HAIXIN_TEMP_CTRL REAL_DTP_XM_FRESH_AIR */
#define DP_ID_THERMOSTAT_TEMP_SET                2
#define DP_ID_THERMOSTAT_TEMP_CUR                3
#define DP_ID_THERMOSTAT_MODE                    4
#define DP_ID_THERMOSTAT_FAULT              12
#define DP_ID_THERMOSTAT_VALVE              101
#define DP_ID_THERMOSTAT_SLEEP_MODE         102
#define DP_ID_THERMOSTAT_WIND_SPEED         103
#define DP_ID_THERMOSTAT_FAN_CTNL           105
#define DP_ID_THERMOSTAT_RESET_FACTORY      106
#define DP_ID_THERMOSTAT_FAN_DIRECT         107
#define DP_ID_THERMOSTAT_SCENE_MODE         108
#define DP_ID_THERMOSTAT_LOW_TEMP_PROTECT   109
#define DP_ID_THERMOSTAT_FILTER_ALARM_FUNC  110
#define DP_ID_THERMOSTAT_FILTER_ALARM_CYCLE 111
#define DP_ID_THERMOSTAT_FILTER_ALARM       112
#define DP_ID_THERMOSTAT_BYPASS             113
#define DP_ID_THERMOSTAT_BYPASS_FUNC        114
#define DP_ID_THERMOSTAT_BACKLIGHT          115
#define DP_ID_THERMOSTAT_COMSTATUS          116

/*DEVICE TYPE:REAL_DTP_XM_ONE_SOCKET_MEASURE_10A REAL_DTP_XM_ONE_SOCKET_MEASURE_16A*/
#define DP_ID_SWITCH1_XM                  1
#define DP_ID_COUNTDOWN_XM               11
#define DP_ID_CHILD_LOCK_XM              105
#define DP_ID_PLUG_BACK_LIGHT_MODE_XM    106
#define DP_ID_OVERLOAD_ALARM_XM          108



/******   device id: TY_DEVID_HA_SCENE_SELECTOR 0x08 ******/
/*
       7        6543210
|  sw && sce |   type
*/

#define SCENE_SELECTOR_XM1    0x30 //1路
#define SCENE_SELECTOR_XM2    0x31
#define SCENE_SELECTOR_XM3    0x32
#define SCENE_SELECTOR_XM4    0x33 //4路

#define SCENE_SELECTOR_REX1    0x10 //1路
#define SCENE_SELECTOR_REX2    0x11
#define SCENE_SELECTOR_REX3    0x12
#define SCENE_SELECTOR_REX4    0x13
#define SCENE_SELECTOR_REX5    0x14
#define SCENE_SELECTOR_REX6    0x15
#define SCENE_SELECTOR_REX7    0x16
#define SCENE_SELECTOR_REX8    0x17
#define SCENE_SELECTOR_REX9    0x18 //9路

#define SCENE_SELECTOR_WORD_REX1 0x30 //1路
#define SCENE_SELECTOR_WORD_REX2 0x31
#define SCENE_SELECTOR_WORD_REX3 0x32
#define SCENE_SELECTOR_WORD_REX4 0x33
#define SCENE_SELECTOR_WORD_REX5 0x34
#define SCENE_SELECTOR_WORD_REX6 0x35
#define SCENE_SELECTOR_WORD_REX7 0x36
#define SCENE_SELECTOR_WORD_REX8 0x37
#define SCENE_SELECTOR_WORD_REX9 0x38 //9路

#define SCENE_SELECTOR_TY1     0x00 //1路
#define SCENE_SELECTOR_TY2     0x01
#define SCENE_SELECTOR_TY3     0x02
#define SCENE_SELECTOR_TY4     0x03
#define SCENE_SELECTOR_TY5     0x04
#define SCENE_SELECTOR_TY6     0x05
#define SCENE_SELECTOR_TY7     0x06
#define SCENE_SELECTOR_TY8     0x07
#define SCENE_SELECTOR_TY9     0x08 //9路

#define SCENE_SELECTOR_FH6     0x95 ///<可配置复合场景面板

#define TY_SCENE_SELECTOR_FLAG_INDEX 4
#define TY_HA_SCENE_SELECTOR_REX6          0x00000815 //6路场景面板, REX,图形
#define TY_HA_SCENE_SELECTOR_COM6          0x00000805 //6路场景面板, ty,图形

#define TY_HA_SCENE_SELECTOR_WORD_REX6     0x00000835 //6路场景面板, REX,文字
#define TY_HA_SCENE_SELECTOR_WORD_COM6     0x00000825 //6路场景面板, REX,文字

#define TY_HA_SCENE_SELECTOR_COM4          0x00000803 //四路场景面板, TY

//西蒙1-4路场景开关
#define TY_HA_XM_SCENE_ONE_SWITCH          0x02000830
#define TY_HA_XM_SCENE_TWO_SWITCH          0x02000831
#define TY_HA_XM_SCENE_THREE_SWITCH        0x02000832
#define TY_HA_XM_SCENE_FOUR_SWITCH         0x02000833

#define TY_HA_XM_SCENE_FOUR_SWITCH_CTL  0x022008A3  //  四路场景面板
//场景开关混合设备
#define TY_HA_SWITCH_ONE_SCENE_SELECTOR_THREE  0x02600880
#define TY_HA_SWITCH_TWO_SCENE_SELECTOR_TWO    0x02600881
#define TY_HA_SWITCH_THREE_SCENE_SELECTOR_ONE  0x02600882
#define TY_HA_SWITCH_SIX_SCENE_SELECTOR_SIX    0x02600886
#define TY_HA_SWITCH_FOUR_SCENE_SELECTOR_FOUR  0x0260088a


#define TY_FH_SWITCH_SIX_SCENE_SELECTOR_SIX_TWO    0x02600895   ///<可配置复合场景面板uddd

#define TY_SCE_SUPPORT_SW 7

#define SCENE_ID_GROUP_ID_DP17 17                       ///< 场景ID组ID dp点17
#define SCENE_EXECUTABLE_MIX_MODE1_DP18 18              ///< 模式切换1 dp点18
#define SCENE_EXECUTABLE_MIX_MODE2_DP19 19              ///< 模式切换2 dp点19
#define SCENE_EXECUTABLE_MIX_MODE3_DP20 20              ///< 模式切换3 dp点20
#define SCENE_EXECUTABLE_MIX_MODE4_DP23 23              ///< 模式切换4 dp点 23
#define SCENE_EXECUTABLE_MIX_SWITCH1_DP24 24            ///< 开关1 dp24 
#define SCENE_EXECUTABLE_MIX_SWITCH2_DP25 25            ///< 开关2 dp25
#define SCENE_EXECUTABLE_MIX_SWITCH3_DP26 26            ///< 开关3 dp26
#define SCENE_EXECUTABLE_MIX_SWITCH4_DP29 29            ///< 开关4 dp29
#define SCENE_EXECUTABLE_MIX_COUNTDOWN1_DP30 30         ///< 开关倒计时1 dp30
#define SCENE_EXECUTABLE_MIX_COUNTDOWN2_DP31 31         ///< 开关倒计时2 dp31
#define SCENE_EXECUTABLE_MIX_COUNTDOWN3_DP32 32         ///< 开关倒计时3 dp32
#define SCENE_EXECUTABLE_MIX_COUNTDOWN4_DP35 35         ///< 开关倒计时4 dp35
#define SCENE_SWITCH_CHANGE_ATTRIBUTE_ID 0xD020         ///< 定义的attribute Id为 0xD020


#define SCENE_MAX_BUTTO_NUM 16
#define SCENE_LIGHT_STATUS_DP18 18
#define SCENE_SWITCH_CHANGE_DP101 101
#define SCENE_SWITCH_CHANGE_CMD 0xFE
#define TUYA_LED_MODE_ATTRIBUTE_ID  0x8001
#define SCENE_SWITCH_START_DP 19
#define SCENE_SWITCH_END_DP 24
#define SCENE_SWITCH_CNTDOWN_START_DP 25
#define SCENE_SWITCH_CNTDOWN_END_DP 30
#define SCENE_SWITCH_BACKLIGHT_DP 31
#define SCENE_SWITCH_SUBCONTROL_START_DP 39 /**分控*/
#define SCENE_SWITCH_SUBCONTROL_END_DP 44


//快速添加特殊处理原来老的设备，老的设备modeid乱填的
#define TY_SCENE_SELECTOR_SHIBEI6_PID  "CvX0ntfj" //视贝六路场景面板
#define TY_SCENE_SELECTOR_SHIBEI4_PID  "brVA4294" //视贝四路场景面板
#define TY_SCENE_SELECTOR_XIKE4_PID    "x2Jgm8Qk" //犀科四路场景面板


/******   device id: TY_DEVID_HA_ANC_CTR_EQUIPMENT 0x0a ******/
#define TY_HA_SCENE_SELECTOR_REX9          0x01000a18 //9路遥控器, REX
#define TY_HA_SCENE_SELECTOR_COM9          0x01000a08 //9路遥控器, ty

#define TY_IAS_ACE_ARM_CMD     0x00 //ARM
#define TY_IAS_ACE_ARM_MODE_DISARM   0x00 //none
#define TY_IAS_ACE_ARM_MODE_ARM      0x01 //Arm
#define TY_IAS_ACE_ARM_MODE_ALL      0x03 //all
#define TY_IAS_ACE_EMERGENCY_CMD    0x02 //紧急报警

#define TY_HA_ALARM_REMOTE_CONTROLLER_COM1   0x01000a00 //自研1路报警开关
#define TY_HA_ALARM_REMOTE_CONTROLLER_COM4   0x01000a03 //海漫4路报警开关


// Server to client
#define TY_ZCL_ADD_GROUP_RESPONSE_COMMAND_ID 0x00 // Ver.: always
#define TY_ZCL_VIEW_GROUP_RESPONSE_COMMAND_ID 0x01 // Ver.: always
#define TY_ZCL_GET_GROUP_MEMBERSHIP_RESPONSE_COMMAND_ID 0x02 // Ver.: always
#define TY_ZCL_REMOVE_GROUP_RESPONSE_COMMAND_ID 0x03 // Ver.: always

// Client to server
#define TY_ZCL_ADD_GROUP_COMMAND_ID 0x00 // Ver.: always
#define TY_ZCL_VIEW_GROUP_COMMAND_ID 0x01 // Ver.: always
#define TY_ZCL_GET_GROUP_MEMBERSHIP_COMMAND_ID 0x02 // Ver.: always
#define TY_ZCL_REMOVE_GROUP_COMMAND_ID 0x03 // Ver.: always
#define TY_ZCL_REMOVE_ALL_GROUPS_COMMAND_ID 0x04 // Ver.: always
#define TY_ZCL_ADD_GROUP_IF_IDENTIFYING_COMMAND_ID 0x05 // Ver.: always


// Command types for cluster: Scenes
// Cluster specification level: zcl6-errata-14-0129-15

// Server to client
#define TY_ZCL_ADD_SCENE_RESPONSE_COMMAND_ID 0x00 // Ver.: always
#define TY_ZCL_VIEW_SCENE_RESPONSE_COMMAND_ID 0x01 // Ver.: always
#define TY_ZCL_REMOVE_SCENE_RESPONSE_COMMAND_ID 0x02 // Ver.: always
#define TY_ZCL_REMOVE_ALL_SCENES_RESPONSE_COMMAND_ID 0x03 // Ver.: always
#define TY_ZCL_STORE_SCENE_RESPONSE_COMMAND_ID 0x04 // Ver.: always
#define TY_ZCL_GET_SCENE_MEMBERSHIP_RESPONSE_COMMAND_ID 0x06 // Ver.: always
#define TY_ZCL_ENHANCED_ADD_SCENE_RESPONSE_COMMAND_ID 0x40 // Ver.: since zll-1.0-11-0037-10
#define TY_ZCL_ENHANCED_VIEW_SCENE_RESPONSE_COMMAND_ID 0x41 // Ver.: since zll-1.0-11-0037-10
#define TY_ZCL_COPY_SCENE_RESPONSE_COMMAND_ID 0x42 // Ver.: since zll-1.0-11-0037-10

// Client to server
#define TY_ZCL_ADD_SCENE_COMMAND_ID 0x00 // Ver.: always
#define TY_ZCL_VIEW_SCENE_COMMAND_ID 0x01 // Ver.: always
#define TY_ZCL_REMOVE_SCENE_COMMAND_ID 0x02 // Ver.: always
#define TY_ZCL_REMOVE_ALL_SCENES_COMMAND_ID 0x03 // Ver.: always
#define TY_ZCL_STORE_SCENE_COMMAND_ID 0x04 // Ver.: always
#define TY_ZCL_RECALL_SCENE_COMMAND_ID 0x05 // Ver.: always
#define TY_ZCL_GET_SCENE_MEMBERSHIP_COMMAND_ID 0x06 // Ver.: always
#define TY_ZCL_ENHANCED_ADD_SCENE_COMMAND_ID 0x40 // Ver.: since zll-1.0-11-0037-10
#define TY_ZCL_ENHANCED_VIEW_SCENE_COMMAND_ID 0x41 // Ver.: since zll-1.0-11-0037-10
#define TY_ZCL_COPY_SCENE_COMMAND_ID 0x42 // Ver.: since zll-1.0-11-0037-10

/*DEVICE TYPE: REAL_DTP_FR_SCENE_PANEL REAL_DTP_REMOTE */
#define DP_ID_BTN_BIND_SCE 102
#define DP_ID_BTN_BIND_SCE_STANDARD_DPID17 17
#define DP_ID_BTN_BIND_SCE_XM_DPID105 105



/******   device id: TY_DEVID_HA_DOOR_LOCK 0x09 ******/

#define DOOR_LOCK_TYPE_COM          0x00
#define DOOR_LOCK_TYPE_YALE         0x02
#define DOOR_LOCK_TYPE_COM_FLATS    0x03 //公寓门锁
#define DOOR_LOCK_TYPE_COM_FLATS_B  0x04 //商用门锁

#define TY_HA_DOOR_LOCK                 0x01000900 //门锁
#define TY_HA_WISE_FAMILY_SMART_LOCK    0x01000901 //智家人门锁
#define TY_HA_YALE_SMART_LOCK           0x01000902 //Yale门锁
#define TY_HA_DOOR_LOCK_FLATS           0x01000903 //涂鸦公寓门锁
#define TY_HA_DOOR_LOCK_FLATS_B         0x01000904 //商用门锁

//LOCK ALARM
#define LOCK_BOLT_BLOCKING 0 //门栓组塞
#define LOCK_RESTORE_FACTORY 1 //恢复出厂设置
#define LOCK_RESERVE 2 //保留
#define LOCK_RESTART_OR_CHANGE_BATTERIES 3 //电源重启或换电池
#define LOCK_ATTEMPTS_TO_OPEN_TOO_MANY 4 //试开报警
#define LOCK_PRIED 5 //锁具保护盖被开启
#define LOCK_FORCE_OPEN 6 //内开锁
#define LOCK_VIOLENT_IMPACT 7 //门锁被撬
#define LOCK_TEMPERATURE_TOO_HIGH 8 //门锁内部温度过高
#define LOCK_INPUT_HIJACKING_PWD 9 //胁迫报警
#define LOCK_FORGET_KEY 10 //钥匙忘记拔
#define LOCK_BATTERY_TOO_LOW 11 //门锁电量过低
#define LOCK_OPEN_FOR_ONE_MIN 12 //门常开1分钟
#define LOCK_INSIDE_OPEN 13 //门内开门

#define LOCK_TONGUE_UNLOCK  34 //主锁舌解锁
#define LOCK_INTER_ANTILOCK_UNLOC 35 //内部反锁解锁
#define LOCK_GATE_STATE_OPENS     36 //门磁状态开
#define LOCK_THE_DOOR_BELL_RANG   38 //门铃响
#define LOCK_SPECIAL_DOORBELL_RING  39 //特殊门铃响
#define LOCK_DOOR_LOCK_ACTUATOR_SUPPORT 40 //门锁执行机构支持
#define LOCK_STRONG_DOOR_LOCK  43 //门锁强震

#define LOCK_BATTERY_LOW_THRESHOLD 30 //门锁电量低门限

#define DOOR_LOCK_CMD_ALARM         0x00
#define DOOR_LOCK_CMD_OPTION_EVENT  0x20
#define DOOR_LOCK_CMD_PROGRAM_EVENT 0x21

//smart lock (home type)
#define DP_ID_SL_UNLOCK             21
#define DP_ID_SL_UNLOCK_RESULT      22
#define SL_UNLOCK_RESULT_LEN        1
#define DP_ID_SL_PWD_CREAT          24
#define DP_ID_SL_PWD_DEL            25
#define DP_ID_SL_PWD_UPDATE         26
#define DP_ID_SL_PWD_DISABLE        27
#define DP_ID_SL_PWD_ENABLE         28
#define DP_ID_SL_PWD_CLEAR          39
#define DP_ID_SL_FREE_UNLOCK        40

#define LOCK_RETRY_DPID(dpid)                                                       \
                    (DP_ID_SL_UNLOCK == (dpid) || DP_ID_SL_PWD_CREAT == (dpid) ||       \
                     DP_ID_SL_PWD_DEL == (dpid) || DP_ID_SL_PWD_UPDATE == (dpid) ||     \
                     DP_ID_SL_PWD_DISABLE == (dpid) || DP_ID_SL_PWD_ENABLE == (dpid) || \
                     DP_ID_SL_PWD_CLEAR == (dpid) || DP_ID_SL_FREE_UNLOCK == (dpid) ||  \
                     DP_ID_SL_UNLOCK_RESULT == (dpid))

//smart lock (flats type)
//#define DP_ID_SL_FLATS_UNLOCK             21
//#define DP_ID_SL_FLATS_UNLOCK_RESULT      22
#define DP_ID_SL_FLATS_PWD_CREAT          2
#define DP_ID_SL_FLATS_PWD_DEL            3
#define DP_ID_SL_FLATS_PWD_UPDATE         4
#define DP_ID_SL_FLATS_PWD_DISABLE        5
#define DP_ID_SL_FLATS_PWD_ENABLE         6
#define DP_ID_SL_FLATS_PWD_CLEAR          7
//#define DP_ID_SL_FLATS_FREE_UNLOCK        40
#define DP_ID_SL_FLATS_OFFLINE_PWD_TIME   8
#define DP_ID_SL_FLATS_FG_CREAT           44

#define LOCK_FLATS_RETRY_DPID(dpid)                                                       \
                    (DP_ID_SL_FLATS_PWD_CLEAR == (dpid) || DP_ID_SL_FLATS_PWD_CREAT == (dpid) ||       \
                     DP_ID_SL_FLATS_PWD_DEL == (dpid) || DP_ID_SL_FLATS_PWD_UPDATE == (dpid) ||     \
                     DP_ID_SL_FLATS_PWD_DISABLE == (dpid) || DP_ID_SL_FLATS_PWD_ENABLE == (dpid))

#define LOCK_FLATS_MODEL_DPID(dpid) \
                    (DP_ID_SL_FLATS_OFFLINE_PWD_TIME == (dpid))

#define LOCK_FLATS_B_MODEL_DPID(dpid) \
                    (DP_ID_SL_FLATS_OFFLINE_PWD_TIME == (dpid))

#define LOCK_NOT_NEED_OPT_DPID(uddd, dpid)  \
                    (((DOOR_LOCK_TYPE_COM_FLATS == ((uddd) & 0xFF)) && (!LOCK_FLATS_RETRY_DPID(dpid))) || \
                    ((!(DOOR_LOCK_TYPE_COM_FLATS == ((uddd) & 0xFF))) && (!LOCK_RETRY_DPID(dpid))))

/**
 * DP 91-100作为锁类自定义DP，由开发者自行定义其中含义,网关直接下发
 */
#define DP_ID_LOCK_SEND_MODEL_COM_FLOOR 91
#define DP_ID_LOOK_SEND_MODEL_COM_UPPER 100

#define LOCK_SEND_MODEL_COM(dpid) \
                ( (dpid >= DP_ID_LOCK_SEND_MODEL_COM_FLOOR) && dpid <= (DP_ID_LOOK_SEND_MODEL_COM_UPPER) )



/******   device id: TY_DEVID_HA_ANC_CTR_EQUIPMENT 0x0a ******/
#define ANC_CTR_EQUIPMENT_TYPE0 0x00 //通用类型 3 + 23 + 40
#define ANC_CTR_EQUIPMENT_TYPEA 0x80 //tuya type对应四个枚举值 dp 3 + 26~29


/******   device id: TY_DEVID_HA_DIMMABLE_LIGHT 0x0b ******/

#define DIMMABLE_LIGHT_COM_TYPE0 0x00
#define DIMMABLE_LIGHT_COM_TYPE1 0x01
#define DIMMABLE_LIGHT_STANDARD_TYPEA 0x05
#define DIMMABLE_LIGHT_STANDARD_TYPEB 0x06 //V1.1新协议
#define DIMMABLE_LIGHT_STANDARD_CEILING 0x07 //公版吸顶灯，新协议
#define DIMMABLE_LIGHT_AND_OCCUPANCY_SENSING_TYPE0 0x02
#define DIMMABLE_LIGHT_AND_OCCUPANCY_SENSING_TYPE1 0x03
#define DIMMABLE_LIGHT_AND_OCCUPANCY_SENSING_TYPE2 0x04

#define DIMMABLE_LIGHT_PHP_TYPE0 0x10
#define DIMMABLE_LIGHT_PHP_TYPE1 0x11

#define TY_HA_DIMMABLE_LIGHT_COM                        0x00000b00 //自研灯(支持，开关，亮暗，工作模式，色彩)
#define TY_HA_DIMMABLE_LIGHT_STANDARD_NUM0              0x00200b00 //标准调光灯(支持，开关，亮暗，工作模式，色彩)
#define TY_HA_DIMMABLE_LIGHT_STANDARD_TYPEA             0x00200b05 //新版标准调光灯(支持，开关，亮暗, 色彩, 工作模式, 情景模式, 单色情景模式(dp103))
#define TY_HA_DIMMABLE_LIGHT_STANDARD_TYPEB             0x00200b06 //新版标准调光灯V1.1新协议
#define TY_HA_DIMMABLE_LIGHT_STANDARD_CEILING           0x00200b07 //公版吸顶灯
#define TY_HA_DIMMABLE_LIGHT_AND_OCCUPANCY_SENSING      0x01200b02 //自研灯(支持，开关，亮暗，延迟关灯,PIR)

#define TY_DIMMABLE_SWITCH_FLAG_INDEX 7 //type最高位代表调光器
#define TY_DIMMABLE_SWITCH_FULL_TYPE_DEF    0x8f
#define TY_DIMMABLE_SWITCH_FULL_TYPE2       0x8e
#define TY_DIMMABLE_SWITCH_FULL_TYPE3       0x8d


#define TY_HA_DIMMABLE_SWITCH_ONE                     0x00200b80 //一路调光开关
#define TY_HA_DIMMABLE_SWITCH_TWO                     0x00200b81 //二路调光开关
#define TY_HA_DIMMABLE_SWITCH_FULL                    0x00200b8f //全功能调光器,照明品类
#define TY_HA_DIMMABLE_SWITCH_FULL_TYPE2              0x00200b8e //全功能调光开关,开关品类,最大最小亮度分开下发，亮度改为0-1000
#define TY_HA_DIMMABLE_SWITCH_FULL_TYPE3              0x00200b8d //全功能调光器,照明品类,最大最小亮度分开下发，亮度改为0-1000

/******
simon: 如果第4位置1 代表西蒙，作特殊处理
  7       65     4     3210
| 1 | reserved | 1 |   type   |
*/
#define TY_HA_XM_DIMMABLE_SWITCH_ONE                     0x00000b90 //一路西蒙调光开关
#define TY_HA_XM_DIMMABLE_SWITCH_TWO                     0x00000b91 //二路西蒙调光开关

#define TY_HA_DIMMABLE_LIGHT_PHILIP     0x00000b10 //飞利浦灯(支持，开关，亮暗,冷暖暂不支持)

/******   device id: TY_DEVID_HA_COLOR_DIMMABLE_LIGHT 0x0c ******/
#define TY_HA_COLOR_DIMMABLE_LIGHT_COM0_NUM0            0x00000c00 // 0x00
#define TY_HA_COLOR_DIMMABLE_LIGHT_STANDARD_NUM0        0x00200c00 // 标准调光灯(支持，开关，亮暗，工作模式，色彩)

/******   device id: TY_DEVID_HA_ON_OFF_SWITCH 0x0d ******/
/*
      7654          3210
|   dp type   |   key num   |
dp type:
0: 1ep => 1dp
1: 1ep => 3dp

*/
#define GET_TY_HA_ONOF_SWITCH_TYPE(_uddd) (((_uddd) >> 4) & 0xf)
#define TY_HA_ONOF_SWITCH_TYPEA     0x01 //豪恩无线开关 特殊处理，标准头部，私有电量dp101,后续废弃

#define TY_HA_ONOF_SWITCH_ONE                0x00000d00 //一路无线开关
#define TY_HA_ONOF_SWITCH_TWO                0x00000d01 //二路无线开关
#define TY_HA_ONOF_SWITCH_THR                0x00000d02 //三路无线开关
#define TY_HA_ONOF_SWITCH_FOU                0x00000d03 //四路无线开关
#define TY_HA_ONOF_SWITCH_FIV                0x00000d04 //五路无线开关
#define TY_HA_ONOF_SWITCH_SIX                0x00000d05 //六路无线开关
#define TY_HA_ONOF_SWITCH_SEV                0x00000d06 //七路无线开关
#define TY_HA_ONOF_SWITCH_EIG                0x00000d07 //八路无线开关

#define TY_HA_ONOF_SWITCH_ONE_A                0x00000d10
#define TY_HA_ONOF_SWITCH_TWO_A                0x00000d11
#define TY_HA_ONOF_SWITCH_THR_A                0x00000d12
#define TY_HA_ONOF_SWITCH_FOU_A                0x00000d13
#define TY_HA_ONOF_SWITCH_FIV_A                0x00000d14

#define TY_HA_ONOF_SWITCH_PRIVERT_CMDFD                0xFD //0 单击，1 双击，2 长按
#define TY_HA_ONOF_SWITCH_PRIVERT_CMDFC                0xFC //0 单击, 对应dp点为101
#define TY_HA_ONOF_SWITCH_PRIVERT_CMDFB                0xFB //0 单击, 对应dp点为102,与用西蒙双控
#define TY_TYPE_ONOF_SWITCH_KEY_MAX                     8

/******   device id: TY_DEVID_HA_IAS_WARNING_DEVICE 0x0f ******/
#define TY_HA_IAS_WARNING_DEVICE_STANDRAD       0x00200f07 // 0x07

#define DP_ID_IAS_WD_ALERT_STATE            4
#define DP_ID_IAS_WD_ALARM_VOL              5
#define DP_ID_IAS_WD_SUPPLY_STATE           6
#define DP_ID_IAS_WD_ALARM_SWITCH           13
#define DP_ID_IAS_WD_ALARM_BRIGHT           17
#define DP_ID_IAS_WD_ALARM_TIME             18
#define DP_ID_IAS_WD_ALARM_TAMPER           20

/******   device id: TY_DEVID_HA_SHADE 0x10 ******/
/******
simon: 如果第4位置1 代表西蒙，作特殊处理
     765     4     3210
| reserved | 1 |   type   |
*/
#define TY_HA_XM_SHADE_ONE_SWITCH       0x00001010 // 西蒙一路窗帘开关
#define TY_HA_XM_SHADE_TWO_SWITCH       0x00001011 // 西蒙二路窗帘开关

/******   device id: TY_DEVID_HA_SIMPLE_SENSOR 0x11 ******/
#define HA_SIMPLE_SENSOR_TYPE_PM25      0x01

#define TY_HA_SIMPLE_SENSOR_PM25        0x00001101

/******   device id: DEVID_HA_REMOTE_DIMMABLE_SWITCH 0x12 ******/
#define HA_REMOTE_DIMMABLE_SWITCH_TYPE1      0x00 //one endpoint, support level and onoff
//加入模式切换的无线开关
#define HA_REMOTE_MODE_ONOFF_SWITCH_TYPE      0x01 //可以模式控制的无线开关,看作遥控器
#define HA_REMOTE_8SCENE_DIMMABLE_SWITCH_YTPE 0x02 //8分组灯光场景遥控器

#define TY_HA_REMOTE_MODE_ONOFF_SWITCH              0x00201201 //模式切换无线开关
#define TY_HA_REMOTE_DIMMABLE_SWITCH_COM            0x00001200
#define TY_HA_REMOTE_DIMMABLE_SWITCH_STD_TYPE1      0x00201200
#define TY_HA_REMOTE_8SCENE_DIMMABLE_SWITCH         0x00201202 //8分组灯光场景遥控器
/******   device id: TY_DEVID_HA_SIMPLE_SENSOR_LIGHT 0x13 ******/
#define HA_SIMPLE_SENSOR_LIGHT_TYPT_COM      0x00

#define TY_HA_SIMPLE_SENSOR_LIGHT_COM        0x00001300

/******   device id: TY_DEVID_HA_WIRELESS_REMOTE_CONTROL 0x14 ******/
#define TY_TYPE_IR_WITH_KEY_CONTROL 0x11 // 带按键的红外遥控器 (bit0-红外能力, bit1-是否带按键)
#define TY_TYPE_IR_WITHOUT_KEY_CONTROL 0x01 // 不带按键的红外遥控器 (bit0-红外能力, bit1-是否带按键)

#define ZLL_MANU_TYPE_PHILIPS   0x00
#define ZLL_MANU_TYPE_IKEA      0x01
#define ZLL_MANU_TYPE_COM       0x08
#define GET_ZLL_MANU_TYPE(_uddd) ((_uddd >> 8) & 0xf)

/******   device id: TY_DEVID_LL_DIMMABLE_LIGHT 0x00 ******/
/******
   7        654         3210
| 通用  |   厂商     |   type   |

*/
#define TY_LL_COLOR_LIGHT_COM          0x0001008f //通用调色灯
#define TY_LL_COLOR_LIGHT_COM_PID      "jiofbkmh" //需要更新pid为单调色面板

/******   device id: TY_DEVID_LL_EXTENDED_COLOR_LIGHT 0x01 ******/
/******
   7        654         3210
| 通用  |   厂商     |   type   |

厂商：0 飞利浦
*/
#define TY_LL_EXTENDED_COLOR_LIGHT_COM          0x00010180 //通用调温调色灯
#define TY_LL_EXTENDED_COLOR_LIGHT_COM_PID      "oe0cpnjg"

#define TY_LL_EXTENDED_COLOR_LIGHT_PHILIPS_HUE  0x00010100 //飞利浦Hue调温调色灯

/******   device id: TY_DEVID_LL_COLOR_TEMPERATURE_LIGHT 0x02 ******/
/******
   7        654         3210
| 通用  |   厂商     |   type   |

厂商：0 飞利浦
      1 IKEA
*/
#define TY_LL_COLOR_TEMPERATURE_LIGHT_COM         0x00010280 //通用调温灯
#define TY_LL_COLOR_TEMPERATURE_LIGHT_COM_PID     "zfbj19qm"

#define TY_LL_COLOR_TEMPERATURE_LIGHT_IKEA_980LM  0x00010210 //宜家调温灯
#define TY_LL_COLOR_TEMPERATURE_LIGHT_PHILIPS_HUE  0x00010200 //飞利浦Hue调温灯

/******   device id: TY_DEVID_LL_DIMMABLE_LIGHT 0x03 ******/
/******
   7        654         3210
| 通用  |   厂商     |   type   |

*/
#define TY_LL_DIMMABLE_LIGHT_COM          0x00010380 //通用调光灯
#define TY_LL_DIMMABLE_LIGHT_COM_PID      "1jlpstyg"

/******   device id: TY_DEVID_LL_OnOff_LIGHT 0x04 ******/
/******
   7        654         3210
| 通用  |   厂商     |   type   |

*/
#define TY_LL_OnOff_LIGHT_COM               0x00010480 //通用开关灯
#define TY_LL_OnOff_LIGHT_COM_PID           "dkkymuf0"
#define TY_LL_OnOff_LIGHT_TWO_COM           0x00010481 //通用二路开关灯
#define TY_LL_OnOff_LIGHT_TWO_COM_PID       "rurhiazg"
#define TY_LL_OnOff_LIGHT_THR_COM           0x00010482 //通用三路开关灯
#define TY_LL_OnOff_LIGHT_THR_COM_PID       "smgplfik"

#define TY_LL_OnOff_LIGHT_PHILIPS          0x00010400 //飞利浦开关

/******   device id: TY_DEVID_LL_OnOff_Plugin  0x05 ******/
/******
   7        654         3210
| 通用  |   厂商     |   type   |

*/
#define TY_LL_OnOff_Plugin_COM              0x00010580 //通用开关插座
#define TY_LL_OnOff_Plugin_COM_PID          "y4jnobxh"
#define TY_LL_OnOff_Plugin_TWO_COM          0x00010581 //通用二路开关插座
#define TY_LL_OnOff_Plugin_TWO_COM_PID      "y4jnobxh"
#define TY_LL_OnOff_Plugin_THR_COM          0x00010582 //通用三路开关插座
#define TY_LL_OnOff_Plugin_THR_COM_PID      "y4jnobxh"

#define TY_LL_OnOff_Plugin_PHILIPS          0x00010500 //飞利浦插座

#define IS_TY_PRT_TRD_DEVICE_FLAG_INDEX 7
#define IS_TY_PRT_TRD_FATHER_DEVICE(_uddd)     ((0 == (((_uddd) >> IS_TY_PRT_TRD_DEVICE_FLAG_INDEX) & 0x1 )) && ((((_uddd) >> 16) & 0xf) == TY_PROFILE_ID_RPT))
#define IS_TY_PRT_TRD_DEVICE(_uddd)            ((0 != (((_uddd) >> IS_TY_PRT_TRD_DEVICE_FLAG_INDEX) & 0x1 )) && ((((_uddd) >> 16) & 0xf) == TY_PROFILE_ID_RPT))
/******   device id: TY_DEVID_RPT_485_CONTROLLER  0x00 ******/
/******
   7                654         3210
| is sub dev  |   resave     |   type   |
*/
#define TY_RPT_485_CONTROLLER                   0x00120000
#define TY_RPT_485_CONTROLLER_3ED_DEV_TYPE0     0x08120080

#ifndef TY_ZIGBEE_SDK
#define PROFILE_ID_HA        0x0104
#endif
#define PROFILE_ID_LL        0xC05E

#define DEVID_HA_IAS_ZONE                       0x0402      // 0x0402 -> 0x00，IAS类，pir, 门磁
#define DEVID_HA_TEMPERATURE_SENSOR             0x0302      // 0x0302 -> 0x01，温度类（含温湿度）
#define DEVID_HA_ONOF_LIGHT                     0x0100      // 0x0100 -> 0x02，照明开关类
#define DEVID_HA_SMART_PLUG                     0x0051      // 0x0051 -> 0x03, 智能插座类
#define DEVID_HA_MAINS_POWER_OUTLET             0x0009      // 0x0009 -> 0x04, 非智能插座类
#define DEVID_HA_HEATING_COOLING_UNIT           0x0300      // 0x0300 -> 0x05，地暖
#define DEVID_HA_THERMOSTAT                     0x0301      // 0x0301 -> 0x06, 空调，新风系统
#define DEVID_HA_WINDOW_COVERING                0x0202      // 0x0202 -> 0x07, 窗帘电机
#define DEVID_HA_SCENE_SELECTOR                 0x0004      // 0x0004 -> 0x08, 场景
#define DEVID_HA_DOOR_LOCK                      0x000A      // 0x000A -> 0x09, 门锁
#define DEVID_HA_ANC_CTR_EQUIPMENT              0x0401      // 0x0401 -> 0x0a, 辅助控制设备，如遥控器
#define DEVID_HA_DIMMABLE_LIGHT                 0x0101      // 0x0101 -> 0x0b, 调光灯
#define DEVID_HA_COLOR_DIMMABLE_LIGHT           0x0102      // 0x0102 -> 0x0c, 调色灯
#define DEVID_HA_ON_OFF_SWITCH                  0x0000      // 0x0000 -> 0x0d, on/off switch
#define DEVID_HA_OCCUPANCY_SENSOR               0x0107      // 0x0000 -> 0x0e, occupancy sensor
#define DEVID_HA_IAS_WARNING_DEVICE             0x0403      // 0x0403 -> 0x0f，标准报警器
#define DEVID_HA_SHADE                          0x0200      // 0x0200 -> 0x10, 窗帘开关
#define DEVID_HA_SIMPLE_SENSOR                  0x000C      // 0x000C -> 0x11, 采集类传感器
#define DEVID_HA_REMOTE_DIMMABLE_SWITCH         0x0104      // 0x0104 -> 0x12, 灯光遥控器
#define DEVID_HA_SIMPLE_SENSOR_LIGHT            0x0106      // 0x0106 -> 0x13, 亮度传感器
#define DEVID_HA_WIRELESS_REMOTE_CONTROL        0xF000      // 0xF000 -> 0x14, 无线遥控器

#define DEVID_LL_COLOR_LIGHT                    0x0200      // 0x0200 -> 0x00, 色彩灯
#define DEVID_LL_EXTENDED_COLOR_LIGHT           0x0210      // 0x0210 -> 0x01, 色温色彩灯
#define DEVID_LL_COLOR_TEMPERATURE_LIGHT        0x0220      // 0x0220 -> 0x02, 色温灯
#define DEVID_LL_DIMMABLE_LIGHT                 0x0100      // 0x0100 -> 0x03, 调光灯
#define DEVID_LL_OnOff_LIGHT                    0x0000      // 0x0000 -> 0x04, 开关灯,或者开关
#define DEVID_LL_OnOff_Plugin                   0x0010      // 0x0010 -> 0x05, 插座

#ifndef TY_ZIGBEE_SDK

#define TY_CMD_TYPE_GLOBAL    0x01
#define TY_CMD_TYPE_PRIVATE   0x02
#define TY_CMD_TYPE_ZDO       0x03

/************ green power profile************/
#define PROFILE_ID_GP 0xA1E0
#define TY_PROFILE_ID_GP 0x03
/************ green power device************/
#define DEVID_GP_SIMPLE_GEN_ONE_SWITCH      0x00    //GP Simple Generic 1-state Switch
#define DEVID_GP_SIMPLE_GEN_TWO_SWITCH      0x01    //GP Simple Generic 2-state Switch
#define DEVID_GP_ON_OFF_SWITCH              0x02    //GP On/Off Switch
#define DEVID_GP_LEVEL_CONTROL_SWITCH       0x03    //GP Level Control Switch
#define DEVID_GP_SIMPLE_SENSOR              0x04    //GP Simple Sensor
#define DEVID_GP_ADV_GEN_ONE_SWITCH         0x05    //GP Advanced Generic 1-state Switch
#define DEVID_GP_ADV_GEN_TWO_SWITCH         0x06    //GP Advanced Generic 2-state Switch
#define DEVID_GP_COLOR_DIMMER_SWITCH        0x10    //GP Color Dimmer Switch
#define DEVID_GP_LIGHT_SENSOR               0x11    //GP Light Sensor
#define DEVID_GP_OCCUPANCY_SENSOR           0x12    //GP Occupancy Sensor
#define DEVID_GP_DOOR_LOCK_CONTROLLER       0x20    //GP Door Lock Controller
#define DEVID_GP_TEMPERATURE_SENSOR         0x30    //GP Temperature Sensor
#define DEVID_GP_PRESSURE_SENSOR            0x31    //GP Pressure Sensor
#define DEVID_GP_FLOW_SENSOR                0x32    //GP Flow Sensor
#define DEVID_GP_INDOOR_ENVIRONMENT_SENSOR  0x33    //GP Indoor Environment Sensor

/************ green power commabdID************/
#define TY_GP_SCENE0_COMMANDID              0x10
#define TY_GP_SCENE1_COMMANDID              0x11
#define TY_GP_SCENE2_COMMANDID              0x12
#define TY_GP_SCENE3_COMMANDID              0x13
#define TY_GP_SCENE4_COMMANDID              0x14
#define TY_GP_SCENE5_COMMANDID              0x15
#define TY_GP_SCENE6_COMMANDID              0x16
#define TY_GP_SCENE7_COMMANDID              0x17
#define TY_GP_SCENE8_COMMANDID              0x18
#define TY_GP_SCENE9_COMMANDID              0x19
#define TY_GP_SCENE10_COMMANDID             0x1A
#define TY_GP_SCENE11_COMMANDID             0x1B
#define TY_GP_SCENE12_COMMANDID             0x1C
#define TY_GP_SCENE13_COMMANDID             0x1D
#define TY_GP_SCENE14_COMMANDID             0x1E
#define TY_GP_SCENE15_COMMANDID             0x1F
#define TY_GP_OFF_COMMANDID                 0x20
#define TY_GP_ON_COMMANDID                  0x21
#define TY_GP_TOGGLE_COMMANDID              0x22
#define TY_GP_DECOMMISSIONING_COMMANDID     0xE1





#define TY_GW_SOURCE_ENDPOINT      0x01
#endif
#define TY_DEV_RESET_DST_ENDPOINT  0x01

#define TY_POWER_SORUCE_BATTERY  0x03

typedef struct ty_attr_unit{
    USHORT_T id;
    USHORT_T len;
    BYTE_T*  data;
} TY_ATTR_UNIT_S;

void attributer_analysis_function(UCHAR_T *uBuffer, UCHAR_T ucDataType, UCHAR_T *val, INT_T *iLen, UCHAR_T *ucTyDataType);
BOOL_T find_cluster_id(USHORT_T *clusterIds, UCHAR_T ucNum, USHORT_T clusterId);
int tuya_z3_GetAttributerVal(UCHAR_T *buffer, USHORT_T bufLen, USHORT_T usAttrId,  UCHAR_T *ucVal, INT_T valbufLen, INT_T *valLen, UCHAR_T cmd);
INT_T tuya_z3_GetAttributerList(UCHAR_T *buffer, USHORT_T bufLen, UCHAR_T cmd, TY_ATTR_UNIT_S* unit_buf, INT_T unit_max_cnt, INT_T* unit_cnt);
TY_ATTR_UNIT_S* tuya_z3_FindAttrInList(TY_ATTR_UNIT_S* unit_buf, INT_T unit_cnt, USHORT_T attr_id);
BOOL_T _IsEqualTwoString(IN CONST CHAR_T *ucString1, IN CONST CHAR_T *ucString2);
BOOL_T IsTYP5ManuNameVaild(IN CONST CHAR_T *manu_name, OUT CHAR_T *pid, IN UINT_T pid_buf_len, OUT UCHAR_T *standard_ability_value);
BOOL_T isSupportThisAbilityfromManuName(IN CONST CHAR_T *manu_name, IN CONST TY_STANDAR_ABILITY_TYP_E type);
BOOL_T isSupportThisAbilityfromFullAbility(IN CONST UCHAR_T *full_ability, IN CONST TY_STANDAR_ABILITY_TYP_E type);
UCHAR_T tuya_z3_asc2hex(CHAR_T asccode);
VOID tuya_z3_json_str_add_slash(CHAR_T *json_str, CHAR_T **out_str_data);

typedef struct {
    CONST UINT_T uddd;
    CONST CHAR_T *model_id;
    CONST CHAR_T *prod_key;
}DTP_PID_ITEM_S;

typedef struct {
    CONST UINT_T uddd;
    CONST CHAR_T *dev_data;
}DEVICE_PID_EP_INFO;

typedef struct {
    CONST CHAR_T *xm_model_id;
    CONST CHAR_T *model_id;
    CONST UINT_T uddd;
}XM_SPEC_MODELID_L;

extern CONST DTP_PID_ITEM_S rexense_dpi_tbl[];
extern CONST DTP_PID_ITEM_S bosch_dpi_tbl[];
extern CONST DTP_PID_ITEM_S tuya_dpi_tbl[];
extern CONST DTP_PID_ITEM_S tuya_fast_mode_tbl[];
extern CONST DTP_PID_ITEM_S tuya_tec_fast_mode_tbl[];
extern CONST DTP_PID_ITEM_S tuya_com_fast_mode_tbl[];
extern CONST DEVICE_PID_EP_INFO dev_info_tbl[];
extern CONST XM_SPEC_MODELID_L rexense_xm_modelid_tbl[];
extern CONST CHAR_T* no_support_pid_tbl[];
extern CONST CHAR_T* need_bind_manuname_tbl[];
extern CONST CHAR_T* zb_manuname_dev_without_std_dp_tbl[];


extern INT_T g_tuya_fast_size;
extern INT_T g_tuya_tec_fast_size;
extern INT_T g_rexense_dpi_size;
extern INT_T g_bosch_dpi_size;
extern INT_T g_tuya_dpi_tbl_size;
extern INT_T g_tuya_com_fast_size;
extern INT_T g_dev_info_tbl_size;
extern INT_T g_rexense_xm_modelid_tbl_size;
extern INT_T g_no_support_pid_tbl_size;
extern INT_T g_need_bind_manuname_tbl_size;
extern INT_T g_zb_manuname_dev_without_std_dp_tbl_size;


    //device model id
#define MOD_ID_ONE_SOCKET_MEASURE_10A "TY0007"
#define MOD_ID_ONE_SOCKET_MEASURE_16A "TY0008"
#define MOD_ID_ONE_SOCKET_MEASURE_NO_BTN_10A "TY0009"
#define MOD_ID_ONE_SOCKET_MEASURE_NO_BTN_16A "TY0010"
#define MOD_ID_ONE_SOCKET_NO_MEASURE_10A "HY0012"
#define MOD_ID_ONE_SOCKET_NO_MEASURE_16A "HY0013"
    //#define MOD_ID_ONE_SOCKET_HY_HA_NO_MEASURE_10A "HY0042"
    //#define MOD_ID_ONE_SOCKET_HY_AL_NO_MEASURE_10A "0a0c3c"
#define MOD_ID_ONE_SOCKET_HY_HA_NO_MEASURE_16A "HY0043"
#define MOD_ID_ONE_SOCKET_HY_AL_NO_MEASURE_16A "0a0c55"


#define MOD_ID_TWO_SOCKET ""
#define MOD_ID_TWO_SOCKET_HY_AL_NO_MEASURE_10A "0a0c3c"
#define MOD_ID_TWO_SOCKET_HY_HA_NO_MEASURE_10A "HY0042"

#define MOD_ID_THREE_SOCKET ""
#define MOD_ID_FOUR_SOCKET ""
#define MOD_ID_ONE_LIGHT "TY0001"
#define MOD_ID_AL_ONOF_LIGHT_ONE "500c32" //瑞赢一路阿里定制开关
#define MOD_ID_HY_ONOF_LIGHT_ONE "HY0030" //瑞赢一路标准版定制开关
#define MOD_ID_JP_ONOF_LIGHT_ONE "TS0801" //佳普插卡定制开关
#define MOD_ID_ZH_ONOF_LIGHT_ONE "TS0802" //智慧燃气开关
#define MOD_ID_HM_ONOF_LIGHT_AP  "TS0901" //海曼AP中继
#define MOD_ID_SC_ONOF_LIGHT_ONE "TS0220" //世创IO模块

#define MOD_ID_TWO_LIGHT "TY0002"
#define MOD_ID_AL_ONOF_LIGHT_TWO "500c33" //瑞赢二路阿里定制开关
#define MOD_ID_HY_ONOF_LIGHT_TWO "HY0031" //瑞赢二路标准版定制开关

#define MOD_ID_THREE_LIGHT "TY0003"
#define MOD_ID_AL_ONOF_LIGHT_THR "500c35" //瑞赢三路阿里定制开关
#define MOD_ID_HY_ONOF_LIGHT_THR "HY0031" //瑞赢三路标准版定制开关

#define MOD_ID_FOUR_LIGHT ""
#define MOD_ID_ONE_SET_LIGHT ""
#define MOD_ID_TWO_SET_LIGHT ""
#define MOD_ID_THREE_SET_LIGHT ""
#define MOD_ID_FOUR_SET_LIGHT ""
#define MOD_ID_COL_TEMP_LIGHT ""
#define MOD_ID_HSL_LIGHT ""
#define MOD_ID_XYY_LIGHT ""
#define MOD_ID_ASSIST_ONE_SWITCH  ""
#define MOD_ID_ASSIST_TWO_SWITCH  ""
#define MOD_ID_ASSIST_THREE_SWITCH ""
#define MOD_ID_ASSIST_FOUR_SWITCH ""

#define MOD_ID_AL_ALARM ""
#define MOD_ID_SMART_LOCK "RH8000"
#define MOD_ID_WISE_FAMILY_SMART_LOCK "TY8001"
#define MOD_ID_WISE_FAMILY_SMART_LOCK_HOME "TY0027"
#define MOD_ID_YALE_SMART_LOOK "YRD226/246 TSDB"

#define MOD_ID_DOOR_SENSOR "RH3001"
#define MOD_ID_PIR_SENSOR "RH3040"
#define MOD_ID_JD_SMOKE_SENSOR "RH3010"
#define MOD_ID_SMOKE_SENSOR "RH3011"
#define MOD_ID_HY_AL_SMOKE_SENSOR "670e10"
#define MOD_ID_JD_GAS_SENSOR "RH3060"
#define MOD_ID_GAS_SENSOR "RH3070"
#define MOD_ID_HY_AL_GAS_SENSOR "120e0f"

#define MOD_ID_WATER_SENSOR ""
#define MOD_ID_WATER_HY_HA_SENSOR "RH3022"
#define MOD_ID_WATER_HY_AL_SENSOR "5d0e11"

#define MOD_ID_SHAKE_MOTION_SENSOR ""
#define MOD_ID_HUMAN_PANEL_SENSOR  ""

#define MOD_ID_ENV_TEMP ""
#define MOD_ID_ENV_HUM ""
#define MOD_ID_ENV_LIGHT ""
#define MOD_ID_ENV_CURTAIN "TY0011"
#define MOD_ID_ENV_DY_CURTAIN "DY0001"
#define MOD_ID_ENV_TUYA_CURTAIN_SWITCH "TY0012"
#define MOD_ID_ENV_HY_HA_CURTAIN_SWITCH "HY0039"
#define MOD_ID_ENV_HY_AL_CURTAIN_SWITCH "040c3a"
#define MOD_ID_ENV_FRESH_AIR ""
#define MOD_ID_HY_FRESH_AIR "HY0082"   //新风???
#define MOD_ID_AL_FRESH_AIR "280eda"   //阿里新风
#define MOD_ID_RH_FRESH_AIR "RH9010"   //新风???

#define MOD_ID_ENV_COLD_HEAT ""
#define MOD_ID_RH_HEATING_COOLING_UNIT  "RH9011" //地暖

#define MOD_ID_ENV_ONE_AC "HY0080"
#define MOD_ID_RH_ONE_AC "RH9012"   //空调

#define MOD_ID_ENV_TWO_AC ""
#define MOD_ID_ENV_THREE_AC ""
#define MOD_ID_ENV_FOUR_AC ""
#define MOD_ID_ENV_FIVE_AC ""
#define MOD_ID_ENV_SIX_AC ""
#define MOD_ID_ENV_SENCE_PANEL ""
#define MOD_ID_ENV_PM25_SENSOR ""
#define MOD_ID_ENV_CO2_SENSOR ""
#define MOD_ID_ENV_HCHO_SENSOR ""
#define MOD_ID_ENV_VOC_SENSOR ""
#define MOD_ID_ENV_CURTAIN_ASSIST_SW ""
#define MOD_ID_ENV_TEMP_HUM "RH3052"
#define MOD_ID_ENV_TEMP_CTRL_83 "TY0020"
#define MOD_ID_ENV_TEMP_CTRL_84 "TY0019"


#define MOD_ID_FR_RELAY ""
#define MOD_ID_FR_HY_HA_SCENE_PANEL "HY0017"
#define MOD_ID_FR_HY_WORD_SCENE_PANEL "TY0018"
#define MOD_ID_FR_HY_AL_SCENE_PANEL "5f0c3b"
#define MOD_ID_ENV_TUYA_SCENE_PANEL "TY0404"

#define MOD_ID_HY_HA_REMOTE "HY0110"
#define MOD_ID_HY_AL_REMOTE "5f1367"

#define MOD_ID_HY_AL_REMOTE_ALARM "RH6020"
#define MOD_ID_TY_REMOTE_ALARM "TY4203"
#define MOD_ID_TH_REMOTE_ALARM "TH4203"

#define PHILIPS_MODE_ID_LEDTUBE "LEDtube T8 4FT V2.0"

//ximen device
#define MOD_ID_XM_WATER_TEMP_CTRL "S2100-3101"
#define MOD_ID_XM_HEAT "S2100-3102"
#define MOD_ID_XM_HAIXIN_TEMP_CTRL "S2100-3104"
#define MOD_ID_XM_FRESH_AIR "S2100-3105"
#define MOD_ID_XM_ONE_LIGHT "S2100-1001"
#define MOD_ID_XM_TWO_LIGHT "S2100-1002"
#define MOD_ID_XM_THREE_LIGHT "S2100-1003"
#define MOD_ID_XM_FOUR_LIGHT "S2100-1004"
#define MOD_ID_XM_ONE_SOCKET_MEASURE_10A "S2100-5101"
#define MOD_ID_XM_ONE_SOCKET_MEASURE_16A "S2100-5102"
#define MOD_ID_XM_SCENE_ONE_SWITCH "S2100-0401"
#define MOD_ID_XM_SCENE_TWO_SWITCH "S2100-0402"
#define MOD_ID_XM_SCENE_THREE_SWITCH "S2100-0403"
#define MOD_ID_XM_SCENE_FOUR_SWITCH "S2100-0404"

//ximen device short address
#define MOD_ID_XM_WATER_TEMP_CTRL_SHORT "0-3101"
#define MOD_ID_XM_HEAT_SHORT "1-3102"
#define MOD_ID_XM_HAIXIN_TEMP_CTRL_SHORT "3-3104"
#define MOD_ID_XM_FRESH_AIR_SHORT "4-3105"
#define MOD_ID_XM_SHADE_ONE_SWITCH "SM0301"
#define MOD_ID_XM_SHADE_TWO_SWITCH "SM0302"
#define MOD_ID_XM_DIMMING_ONE_SWITCH  "SM0501"
#define MOD_ID_XM_DIMMING_TWO_SWITCH  "SM0502"
#define MOD_ID_XM_THERMOSTAT          "SM0309X"
#define MOD_ID_XM_TEMPCTR             "SM0308X"/**西蒙温控器6款*/

//Philips ZLL device
#define MOD_ID_ZLL_EXTENDED_COLOR_LIGHT_PHILIPS_HUE "LCT010"
#define MOD_ID_ZLL_EXTENDED_COLOR_LIGHT_PHILIPS_HUE_GO "LLC020"
#define MOD_ID_ZLL_EXTENDED_COLOR_LIGHT_PHILIPS_HUE_LIGHTSTRIP "LST002"
#define MOD_ID_ZLL_EXTENDED_COLOR_LIGHT_PHILIPS_HUE_CHANDELIER "LTD003"
#define MOD_ID_ZLL_COLOR_TEMPERATURE_LIGHT_PHILIPS_HUE "LTW013"

//IKEA ZLL device
#define MOD_ID_ZLL_COLOR_TEMPERATURE_LIGHT_IKEA_980LM "TRADFRI bulb E27 WS opal 980lm"



/*******************TUYA COM, 请参考mode id表*******************************/
//零火开关
#define TY_TS_ONOF_LIGHT_ONE   "TS0001"  //一路开关， 金地的是TY10F0，确认
#define TY_TS_ONOF_LIGHT_TWO   "TS0002"
#define TY_TS_ONOF_LIGHT_THR   "TS0003"
#define TY_TS_ONOF_LIGHT_FOU   "TS0004"
#define TY_TS_ONOF_LIGHT_FIV   "TS0005"
#define TY_TS_ONOF_LIGHT_SIX   "TS0006"
#define TY_TS_ONOF_LIGHT_SEV   "TS0007"

//标准DP零火开关
#define TY_TS_ONOF_STANDARD_LIGHT_ONE "TS002B" //一路开关，标准DP点
#define TY_TS_ONOF_STANDARD_LIGHT_TWO "TS002C" //二路开关，标准DP点
#define TY_TS_ONOF_STANDARD_LIGHT_THR "TS002D" //三路开关，标准DP点
#define TY_TS_ONOF_STANDARD_LIGHT_FOU "TS002E" //四路开关，标准DP点


#define TY_JD_ONOF_LIGHT   "TY10F0" //老的金地一路,二路，三路开关，四路场景共用一个modeid，通过pid兼容

//单火开关
#define TY_TS_SIGNLE_ONOF_LIGHT_ONE   "TS0011" //一路单火开关，休眠
#define TY_TS_SIGNLE_ONOF_LIGHT_TWO   "TS0012"
#define TY_TS_SIGNLE_ONOF_LIGHT_THR   "TS0013"
#define TY_TS_SIGNLE_ONOF_LIGHT_FOU   "TS0014"
#define TY_TS_SIGNLE_ONOF_LIGHT_FIV   "TS0015"
#define TY_TS_SIGNLE_ONOF_LIGHT_SIX   "TS0016"
#define TY_TS_SIGNLE_ONOF_LIGHT_SEV   "TS0017"

//场景开关
#define TY_TS_SCENE_SELECTOR_ONE      "TS0021"
#define TY_TS_SCENE_SELECTOR_TWO      "TS0022"
#define TY_TS_SCENE_SELECTOR_THR      "TS0023"
#define TY_TS_SCENE_SELECTOR_FOU      "TS0024"
#define TY_TS_SCENE_SELECTOR_FIV      "TS0025"
#define TY_TS_SCENE_SELECTOR_SIX      "TS0026"
#define TY_TS_SCENE_SELECTOR_SEV      "TS0027"
#define TY_TS_SCENE_SELECTOR_EIG      "TS0028"
#define TY_TS_SCENE_SELECTOR_NIE      "TS0029"
#define TY_TS_CTR_SCENE_SELECTOR_NIE  "TS002A"

#define TY_TS_CTR_SCENE_SELECTOR_THR    "TS0033"
//无线开关，只有上报单击，双击，长按，没有下发控制，一个ep对应一个dp
#define TY_TS_ONOF_SWITCH_ONE   "TS0041"
#define TY_TS_ONOF_SWITCH_TWO   "TS0042"
#define TY_TS_ONOF_SWITCH_THR   "TS0043"
#define TY_TS_ONOF_SWITCH_FOU   "TS0044"
#define TY_TS_ONOF_SWITCH_FIV   "TS0045"
#define TY_TS_ONOF_SWITCH_SIX   "TS0046"
#define TY_TS_ONOF_SWITCH_SEV   "TS0047"
#define TY_TS_ONOF_SWITCH_EIG   "TS0048"

//无线开关，只有上报单击，双击，长按，没有下发控制, 一个ep对应三个dp
#define TY_TS_ONOF_SWITCH_ONE_A   "TS0041A"
#define TY_TS_ONOF_SWITCH_TWO_A   "TS0042A"
#define TY_TS_ONOF_SWITCH_THR_A   "TS0043A"
#define TY_TS_ONOF_SWITCH_FOU_A   "TS0044A"
#define TY_TS_ONOF_SWITCH_FIV_A   "TS0045A"

//可切换模式的无线开关
#define TY_TS_REMOTE_MODE_ONOFF_SWITCH   "TS004F"


//插座
#define TY_TS_ONE_SOCKET_NO_MEASURE_10A       "TS0101"
#define TY_TS_ONE_SOCKET_MEASURE_10A          "TS0102"

#define TY_TS_ONE_SOCKET_NO_MEASURE_16A       "TS0103"
#define TY_TS_ONE_SOCKET_MEASURE_16A          "TS0104"

#define TY_TS_ONE_SOCKET_MEASURE_NO_BTN_10A   "TS0105"
#define TY_TS_ONE_SOCKET_MEASURE_NO_BTN_16A   "TS0106"

#define TY_TS_TWO_SOCKET_MEASURE_NO_BTN_10A    "TS0107"
#define TY_TS_TWO_SOCKET_NO_MEASURE_NO_BTN_10A "TS0108"

#define TY_TS_TWO_SOCKET_NO_MEASURE_NO_BTN_16A   "TS0107"
#define TY_TS_TWO_SOCKET_MEASURE_NO_BTN_16A      "TS0108"

//标准DP点插座
#define TY_TS_ONE_SOCKET_STANDARD_MEASURE_10A "TS010B" //计量10A插座，标准DP点
#define TY_TS_ONE_SOCKET_STANDARD_MEASURE_16A "TS010C" //计量16A插座，标准DP点

//OEM插座
#define TY_TS_ONE_SOCKET_NO_MEASURE_OEM       "TS0111"
#define TY_TS_ONE_SOCKET_MEASURE_OEM       "TS0121"
#define TY_TS_TWO_SOCKET_NO_MEASURE_OEM       "TS0112"
#define TY_TS_THREE_SOCKET_NO_MEASURE_OEM       "TS0113"
#define TY_TS_FIVE_SOCKET_NO_MEASURE_OEM       "TS0115"

//标准dp全功能插座
#define TY_TS_SOCKET_STANDARD_FULL "TS011F" //1~8路全功能插座

//传感器
#define TY_TS_TEMPERATURE_SENSOR     "TS0201"   //温湿度
#define TY_TS_PIR                    "TS0202"   //PIR
#define TY_TS_DOOR_SENSOR            "TS0203"   //门磁
#define TY_TS_GAS_SENSOR             "TS0204"   //燃气报警器
#define TY_TS_SMOKE_SENSOR           "TS0205"   //烟雾报警器
#define TY_TS_REMOTE_ALARM           "TS0206"   //报警按钮
#define TY_TS_WATER_SENSOR           "TS0207"   //水浸传感器
#define TY_TS_VOICE_SENSOR           "TS0208"   //声音报警
#define TY_TS_LIGHT_SENSOR           "TS0208"   //光电报警
#define TY_TS_VIBRATION_SENSOR       "TS0208"   //振动报警
#define TY_TS_SHOCK_SENSOR           "TS0210"   //震动传感器
#define TY_TS_SOS_SENSOR             "TS0211"   //SOS报警
#define TY_TS_VOICE_LIGHT_ALARM      "TS0219"   //声光报警器
#define TY_TS_MULTI_ALARM            "TS0213"   //多功能报警器
#define TY_TS_ALARM_REMOTE           "TS0215"   //海曼安防遥控器
#define TY_TS_HM_AIR_SENSOR          "TS0217"   //海曼空气传感
#define TY_TS_TY_AIR_SENSOR          "TS0223"   //涂鸦空气传感

#define TY_TS_TEMPERATURE_SENSOR_TYPEA     "TS0201A"   //温湿度
#define TY_TS_PIR_TYPEA                    "TS0202A"   //PIR
#define TY_TS_SOS_SENSOR_TYPEA             "TS0215A"   //新版安防遥控器
#define TY_TS_SOS_SENSOR_TYPEB             "TS0215B"   //强电类型SOS-IAS_ZONE


//窗帘
#define TY_TS_CURTAIN               "TS0301"   //电动窗帘
#define TY_TS_CURTAIN_SWITCH        "TS0302"   //窗帘开关
#define TY_TS_CURTAIN_SWITCH_NEW    "TS130F"   //1~N路窗帘开关（新版）
#define TY_TS_CURTAIN_MOTOR         "TS030F"   //健达窗帘电机

//场景面板
#define TY_TS_FIGURE_SCENE_PANEL     "TS0303"   //6路图形场景面板
#define TY_TS_WORDK_SCENE_PANEL      "TS0304"   //6路文字场景面板


//空调
#define TY_TS_ONE_AC       "TS0305"   //空调

//新风
#define TY_TS_FRESH_AIR    "TS0306"

//地暖
#define TY_TS_COLD_HEAT    "TS0307"

//标准DP温控器
#define TY_TS_STANDARD_AC  "TS0309"   //空调设备，标准DP点
#define TY_TS_STANDARD_FRESH_AIR "TS030A"  //新风设备，标准DP点
#define TY_TS_STANDARD_COLD_HEAT "TS030B"  //加热制冷设备，标准DP点

//佳宏温控器
#define TY_TS_TEMP_CTRL    "TS0308"

//锁
#define TY_TS_SMART_LOCK        "TS0401"
#define TY_TY_SMART_LOCK        "TY0A01"
#define TY_TY_SMART_LOCK_FLATS  "TY0A02"
#define TY_TY_SMART_LOCK_FLATS_B "TY0A03"

//light
#define TY_TS_SMART_LIGHT_ONE   "TS0501"
#define TY_TS_SMART_LIGHT_TWO   "TS0502"
#define TY_TS_SMART_LIGHT_THR   "TS0503"
#define TY_TS_SMART_LIGHT_FOU   "TS0504"
#define TY_TS_SMART_LIGHT_FIV   "TS0505"
#define TY_TS_SMART_LIGHT_ONE_A   "TS0501A"
#define TY_TS_SMART_LIGHT_TWO_A   "TS0502A"
#define TY_TS_SMART_LIGHT_THR_A   "TS0503A"
#define TY_TS_SMART_LIGHT_FOU_A   "TS0504A"
#define TY_TS_SMART_LIGHT_FIV_A   "TS0505A"
#define TY_TS_SMART_LIGHT_ZERO_B  "TS0500B" ///< 只有开关 公版，吸顶灯，感应灯
#define TY_TS_SMART_LIGHT_ONE_B   "TS0501B" ///< C
#define TY_TS_SMART_LIGHT_TWO_B   "TS0502B" ///< CW
#define TY_TS_SMART_LIGHT_THR_B   "TS0503B" ///< RGB
#define TY_TS_SMART_LIGHT_FOU_B   "TS0504B" ///< RGBC
#define TY_TS_SMART_LIGHT_FIV_B   "TS0505B" ///< RGBCW
///< 公版吸顶灯
#define TY_TS_SMART_LIGHT_ONE_C   "TS0501C" ///< W
#define TY_TS_SMART_LIGHT_TWO_C   "TS0502C" ///< CW
#define TY_TS_SMART_LIGHT_THR_C   "TS0503C" ///< RGB
#define TY_TS_SMART_LIGHT_FOU_C   "TS0504C" ///< RGBC
#define TY_TS_SMART_LIGHT_FIV_C   "TS0505C" ///< RGBCW

///< 公版吸顶灯
#define TY_TS_SMART_LIGHT_ONE_C   "TS0501C" ///< W
#define TY_TS_SMART_LIGHT_TWO_C   "TS0502C" ///< CW
#define TY_TS_SMART_LIGHT_THR_C   "TS0503C" ///< RGB
#define TY_TS_SMART_LIGHT_FOU_C   "TS0504C" ///< RGBC
#define TY_TS_SMART_LIGHT_FIV_C   "TS0505C" ///< RGBCW

#define TY_TS_SMART_LIGHT_OCCUPY  "TS0214"

#define TY_TS_ALARM_REMOTE_CONTROLLER_COM1  "TS0218"

//dimmable switch
#define TY_TS_DIMMABLE_SWITCH_ONE "TS1101"
#define TY_TS_DIMMABLE_SWITCH_TWO "TS1102"
#define TY_TS_DIMMABLE_SWITCH_FULL "TS110F" //调光器品类，之后不再使用
#define TY_TS_DIMMABLE_SWITCH_FULL_TYPE2 "TS110E" //全功能调光开关,开关品类,最大最小亮度分开下发，亮度改为0-1000
#define TY_TS_DIMMABLE_SWITCH_FULL_TYPE3 "TS110D" //全功能调光器,照明品类,最大最小亮度分开下发，亮度改为0-1000

//remote dimmable switch
#define TY_TS_REMOTE_DIMMABLE_SWITCH_TYPE1 "TS1001"
//8分组灯光场景遥控
#define TY_TS_REMOTE_8SCENE_DIMMABLE_SWITCH "TS1002"

//simple sensor
#define TY_TS_SIMPLE_SENSOR_PM25 "TS0221"
#define TY_TS_SIMPLE_SENSOR_Light "TS0222"

//TUYA COM
#define TY_TS_HEAVE_CURRENT                 "TS0601"  //通用对接，非场景设备
#define TY_TS_HEAVE_CURRENT_SCENE_SELECTOR  "TS0602"  //通用对接，场景设备

#define TY_TS_HEAVE_CURRENT_TRD_DEV_CONTROLLER "TS0603"  //通用对接,三级架构设备

//场景与开关混合设备
#define TY_TS_SWITCH_ONE_SCENE_SELECTOR_THREE "TS0701"
#define TY_TS_SWITCH_TWO_SCENE_SELECTOR_TWO "TS0702"
#define TY_TS_SWITCH_THREE_SCENE_SELECTOR_ONE "TS0703"
#define TY_TS_SWITCH_SIX_SCENE_SELECTOR_SIX "TS0716" //1-6路开关+1-6路场景混合

//1-6可配置混合场景开关
#define TY_TS_SWITCH_SIX_SCENE_SELECTOR_CFG "TS0726"

//万能遥控器设备
#define TY_TS_UNIVERSAL_IR_WITH_KEY_CONTROL "TS1200"
#define TY_TS_UNIVERSAL_IR_WITHOUT_KEY_CONTROL "TS1201"

/* ========================================= 博世多功能传感 ========================================= */
#define MANU_NAME_BOSCH                 "Bosch"         //manufancture name
#define MOD_ID_BOSCH_MULTI_SENSOR       "RFMS-ZBA-CHI"  //博世多功能传感 modeID
#define PID_BOSCH_MULTI_SENSOR_DOOR     "psnbjkk3"      //博世多功能传感 门磁 PID
#define PID_BOSCH_MULTI_SENSOR_WATER    "zwjyckcw"      //博世多功能传感 水浸 PID
/* ========================================= 博世PIR ========================================= */
#define MOD_ID_BOSCH_PIR                "RFPR-ZBA-CHI"  //博世PIR modeID
#define PID_BOSCH_PIR                   "vzuwzpma"      //博世PIR PID

#endif
