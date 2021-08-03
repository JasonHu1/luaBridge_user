#ifndef TUYA_APP_PLATEFORM_CFG_H
#define TUYA_APP_PLATEFORM_CFG_H

#include "tuya_cloud_types.h"
#include "tuya_iot_config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define STR_LEN_MAX128 128
#define STR_LEN_MAX64  64
#define STR_LEN_MAX32  32
#define STR_LEN_MAX16  16

typedef struct{
    CHAR_T current_platform_cfg_file_path[STR_LEN_MAX128+1]; //当前配置文件路径
    CHAR_T platform[STR_LEN_MAX32+1];       //支持的平台
    CHAR_T product_key[STR_LEN_MAX32+1];    //支持的product_key
    CHAR_T mode_id[STR_LEN_MAX16+1];        //同一平台下，不同的型号
#ifdef __ANDROID__
    CHAR_T storage_dir[STR_LEN_MAX64+1];    //数据存储目录
    CHAR_T log_dir[STR_LEN_MAX64+1];        //日志存储目录
    CHAR_T tmp_dir[STR_LEN_MAX64+1];        //临时文件目录
    CHAR_T bin_dir[STR_LEN_MAX64+1];        //bin文件目录，勿存放文件，其他平台可能为只读文件系统
    CHAR_T backup_dir[STR_LEN_MAX64+1];     //备份文件目录,默认应该与storage_dir相同，8196e特殊处理，同为文件存
#else
    CHAR_T storage_dir[STR_LEN_MAX32+1];    //数据存储目录
    CHAR_T log_dir[STR_LEN_MAX32+1];        //日志存储目录
    CHAR_T tmp_dir[STR_LEN_MAX32+1];        //临时文件目录
    CHAR_T bin_dir[STR_LEN_MAX32+1];        //bin文件目录，勿存放文件，其他平台可能为只读文件系统
    CHAR_T backup_dir[STR_LEN_MAX32+1];     //备份文件目录,默认应该与storage_dir相同，8196e特殊处理，同为文件存储目录
 #endif
    CHAR_T net_led[STR_LEN_MAX32+1];        //网络灯的gpio号
    CHAR_T status_led[STR_LEN_MAX32+1];     //配网灯的gpio号
    CHAR_T reset_key[STR_LEN_MAX32+1];      //复位按键gpio号
    CHAR_T wan_interface[STR_LEN_MAX16+1];  //有线网口名称
    CHAR_T wifi_interface[STR_LEN_MAX16+1]; //无线网口名称，wan与wifi不能同时为空
    CHAR_T serial_port[STR_LEN_MAX16+1];    //zigbee串口设备号
    BOOL_T is_cts;                          //是否带有流控
    BOOL_T is_sync_systime;                 //是否需要同步系统本地时间
    BOOL_T is_hardward;                     //true表明硬件sdk处理，false表明给用户处理
}TUYA_PLATEFORM_S;

#define TUYA_PLATEFORM_DEF_CONFIG_FILE "../def.cfg"
#define TUYA_PLATEFORM_FILE_LEN 4096

#define TUYA_PLATEFORM_PARAM_NUM 9

//hard platfrom
#define PLATFORM_RTL8196E "RTL8196E"  //rlt8196e
#define PLATFORM_RTL8197F "RTL8197F"  //rtl8197f

//mode id
#define MODE_ID_RTL8196E_TY01    "RTL8196E_TY01"    //8196e自研网关默认
#define MODE_ID_RTL8197F_TY01    "RTL8197F_TY01"    //8197f自研网关默认
#define MODE_ID_RTL8197F_TY02    "alarm_haoen01"    //8197f ihorn
#define MODE_ID_RTL8197F_TY03    "alarm_multi01"    //8197f multi


//product key
#define PRODUCT_KEY_RTL8196E_TY     "keyyj3fy8x98arty"
#define PRODUCT_KEY_RTL8197F_TY     "key4js8gqyhnkdjg"


#define TUYA_DEFAULT_PLATFORM        PLATFORM_RTL8196E
#define TUYA_DEFAULT_MODE_ID         MODE_ID_RTL8196E_TY01
#define TUYA_DEFAULT_PRODUCT_KEY     PRODUCT_KEY_RTL8196E_TY
#define TUYA_DEFAULT_STORAGE_DIR     "./"
#define TUYA_DEFAULT_LOG_DIR         "./log_dir/"
#define TUYA_DEFAULT_TMP_DIR         "/tmp/"
#define TUYA_DEFAULT_BIN_DIR         "/tuya/"
#define TUYA_DEFAULT_BACKUP_DIR      "/tuya/"
#define TUYA_DEFAULT_NET_LED         "123456"
#define TUYA_DEFAULT_STATUS_LED      "123456"
#define TUYA_DEFAULT_RESET_KEY       "123456"
#define TUYA_DEFAULT_WAN_INTERFACE   "eth1"
#define TUYA_DEFAULT_WIFI_INTERFACE  "wlan0"
#define TUYA_DEFAULT_SERIAL_PORT     "/dev/ttyS1"

#define TUYA_PLATFORM_NAME_KEY        "platform"
#define TUYA_PRODUCT_KEY_NAME_KEY     "product_key"
#define TUYA_MODE_ID_NAME_KEY         "mode_id"
#define TUYA_STORAGE_DIR_NAME_KEY     "storage_dir"
#define TUYA_LOG_DIR_NAME_KEY         "log_dir"
#define TUYA_TMP_DIR_NAME_KEY         "tmp_dir"
#define TUYA_BIN_DIR_NAME_KEY         "bin_dir"
#define TUYA_BACKUP_DIR_NAME_KEY      "backup_dir"
#define TUYA_NET_LED_NAME_KEY         "net_led"
#define TUYA_STATUS_LED_NAME_KEY      "status_led"
#define TUYA_RESET_KEY_NAME_KEY       "reset_key"
#define TUYA_WAN_INTERFACE_NAME_KEY   "wan_interface"
#define TUYA_WIFI_INTERFACE_NAME_KEY  "wifi_interface"
#define TUYA_SERIAL_PORT_NAME_KEY     "serial_port"
#define TUYA_IS_CTS_NAME_KEY          "is_cts"
#define TUYA_IS_SYNC_SYSTIME_NAME_KEY "is_sync_systime"
#define TUYA_IS_HARDWARD              "is_hardward"



OPERATE_RET tuya_config_init(CONST CHAR_T * CfgFilePath);
OPERATE_RET tuya_config_init_from_json(CONST CHAR_T *JsonStr);
TUYA_PLATEFORM_S *get_plateform_cfg(VOID);
VOID tuya_plateform_cfg_default_printf(VOID);


#ifdef __cplusplus
}
#endif

#endif

