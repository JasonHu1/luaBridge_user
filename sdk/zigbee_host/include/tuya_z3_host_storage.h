#ifndef __TUYA_Z3_HOST_STORAGE_H__
#define __TUYA_Z3_HOST_STORAGE_H__

#ifdef __cplusplus
    extern "C" {
#endif

#include "tuya_z3_zigbee_bash.h"

#define Z3_HOST_STR_LEN_MAX128 128
#define Z3_HOST_STR_LEN_MAX80  80
#define Z3_HOST_STR_LEN_MAX64  64
#define Z3_HOST_STR_LEN_MAX48  48
#define Z3_HOST_STR_LEN_MAX32  32
#define Z3_HOST_STR_LEN_MAX16  16

//tmp
#if 0// move to tuya_z3_zigbee_bash.h
#define ZIGBEE_UPGRADE_FILE_FOLD_NAME "tuya-ota-files"
#define NCP_UPGRADE_FILE_NAME "NcpUpgrade.ota"
#define ZIGBEE_DEV_UPGRADE_FILE_NAME "ZigbeeDevUpgrade.ota"
#endif
#define NCP_VERSION_FILE_NAME "ncp_ver65_1_0_10_flag"

//storage
#define ZIGBEE_DEV_FLAG_INI_FILE "devflag.ini"
#define ZIGBEE_DEV_TABLE0_TXT_FILE "devices.txt"
#define ZIGBEE_DEV_TABLE1_TXT_FILE "devices1.txt"
#define ZIGBEE_IAS_TABLE0_TXT_FILE "iaszone.txt"
#define TUYA_NcpBackupFileName "NcpUpgrade_backup.ota"
#define TUYA_Ncp65BackupFileName "NcpUpgrade_backup65.ota"
#define TUYA_NcpUpgratingFileName "coo_upgrating"
#define TUYA_Ncp65UpgratingFileName "coo_upgdate65"

#define Z3_HOST_MAIN_ARGV_CTS_MODE "-p"
#define Z3_HOST_MAIN_ARGV_NO_CTS_MODE "-n"
#define Z3_HOST_MAIN_ARGV_DEF_SERIAL_PORT "/dev/ttyS1"

#define Z3_HOST_DEF_BIN_DIR         "/tuya/"
#define Z3_HOST_DEF_STORAGE_DIR     "./"
#define Z3_HOST_DEF_TMP_DIR         "/tmp/"
#define Z3_HOST_DEF_BACKUP_DIR      "/tuya/"

//zigbee network info
#define ZIGBEE_NET_INFO "zigbeeNetInfo.txt"
#define ZIGBEE_NET_INFO_BAK "zigbeeNetInfo_bak.txt"
#define ZIGBEE_NET_INFO_VALID_FLAG  "zigbee_net_valid_flag"

#ifdef __ANDROID__
typedef struct{
    char bin_dir[Z3_HOST_STR_LEN_MAX128 + 1];        //bin文件目录
    char storage_dir[Z3_HOST_STR_LEN_MAX128 + 1];    //数据存储目录
    char tmp_dir[Z3_HOST_STR_LEN_MAX128 + 1];        //临时文件目录
    char backup_dir[Z3_HOST_STR_LEN_MAX128 + 1];     //备份文件文件目录

    char zigbee_ota_dir[Z3_HOST_STR_LEN_MAX128 + 1]; //Zigbee升级文件目录,tmp
    char zigbee_ncp_ug_file[Z3_HOST_STR_LEN_MAX128 + 1]; //ZigbeeNcp升级文件地址,tmp
    char zigbee_dev_ug_file[Z3_HOST_STR_LEN_MAX128 + 1]; //Zigbee子设备升级文件地址,tmp
    char zigbee_ncp_ver_file[Z3_HOST_STR_LEN_MAX128 + 1]; //Ncp版本文件,tmp

    char zigbee_dev_flag_ini_file[Z3_HOST_STR_LEN_MAX128 + 1]; //devflag.ini,storage
    char zigbee_devices_txt_file[Z3_HOST_STR_LEN_MAX128 + 1]; //devices.txt,storage
    char zigbee_devices1_txt_file[Z3_HOST_STR_LEN_MAX128 + 1]; //devices1.txt,storage
    char zigbee_iaszone_txt_file[Z3_HOST_STR_LEN_MAX128 + 1]; //iaszone.txt,storage

    char NcpUpgrade_backup_ota_file[Z3_HOST_STR_LEN_MAX128 + 1]; //NcpUpgrade_backup.ota,backup
    char NcpUpgrade_backup65_ota_file[Z3_HOST_STR_LEN_MAX128 + 1]; //NcpUpgrade_backup65.ota,backup
    char coo_upgrating_file[Z3_HOST_STR_LEN_MAX128 + 1]; //coo_upgrating,backup
    char coo_upgdate65_file[Z3_HOST_STR_LEN_MAX128 + 1]; //coo_upgdate65,backup

}TUYA_Z3_HOST_STORAGE_S;
#else
typedef struct{
    char bin_dir[Z3_HOST_STR_LEN_MAX32 + 1];        //bin文件目录
    char storage_dir[Z3_HOST_STR_LEN_MAX32 + 1];    //数据存储目录
    char tmp_dir[Z3_HOST_STR_LEN_MAX32 + 1];        //临时文件目录
    char backup_dir[Z3_HOST_STR_LEN_MAX32 + 1];     //备份文件文件目录

    char zigbee_ota_dir[Z3_HOST_STR_LEN_MAX48 + 1]; //Zigbee升级文件目录,tmp
    char zigbee_ncp_ug_file[Z3_HOST_STR_LEN_MAX64 + 1]; //ZigbeeNcp升级文件地址,tmp
    char zigbee_dev_ug_file[Z3_HOST_STR_LEN_MAX64 + 1]; //Zigbee子设备升级文件地址,tmp
    char zigbee_ncp_ver_file[Z3_HOST_STR_LEN_MAX64 + 1]; //Ncp版本文件,tmp

    char zigbee_dev_flag_ini_file[Z3_HOST_STR_LEN_MAX48 + 1]; //devflag.ini,storage
    char zigbee_devices_txt_file[Z3_HOST_STR_LEN_MAX48 + 1]; //devices.txt,storage
    char zigbee_devices1_txt_file[Z3_HOST_STR_LEN_MAX48 + 1]; //devices1.txt,storage
    char zigbee_iaszone_txt_file[Z3_HOST_STR_LEN_MAX48 + 1]; //iaszone.txt,storage

    char NcpUpgrade_backup_ota_file[Z3_HOST_STR_LEN_MAX64 + 1]; //NcpUpgrade_backup.ota,backup
    char NcpUpgrade_backup65_ota_file[Z3_HOST_STR_LEN_MAX64 + 1]; //NcpUpgrade_backup65.ota,backup
    char coo_upgrating_file[Z3_HOST_STR_LEN_MAX64 + 1]; //coo_upgrating,backup
    char coo_upgdate65_file[Z3_HOST_STR_LEN_MAX64 + 1]; //coo_upgdate65,backup

}TUYA_Z3_HOST_STORAGE_S;
#endif

void tuya_z3_host_storage_print(void);
void tuya_z3_host_storage_set(const char* current_bin_dir, const char* current_storage_dir,
                              const char* current_tmp_dir, const char* current_backup_dir);
const TUYA_Z3_HOST_STORAGE_S* tuya_z3_host_storage_get(void);
int tuya_z3_host_reboot_gw_app(void);

#ifdef __cplusplus
}
#endif

#endif
