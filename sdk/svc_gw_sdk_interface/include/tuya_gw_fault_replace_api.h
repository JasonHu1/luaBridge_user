/*
tuya_gw_linkage_api.h
Copyright(C),2018-2020, 涂鸦科技 www.tuya.comm
*/

#ifndef __TUYA_GW_FAULT_REPLACE_API_H
#define __TUYA_GW_FAULT_REPLACE_API_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "uni_slist.h"

#ifdef __cplusplus
extern "C" {
#endif


/*dev info extra
{
"version": 1
"devlist":
    [
    {"id":"xxx","tp":2,"uddd":1111,"uddd2":2222},
    {"id":"yyy","tp":2,"uddd":1111,"uddd2":2222}
    ]
}
*/
//#define M_CONFIG_FILE_DEV_VERSION           1
#define M_CONFIG_FILE_DEV_VERSION           2 /*加子设备版本号*/
#define M_CONFIG_FILE_DEV_INF_EXTRA_DIR     "/tmp/"
#define M_CONFIG_FILE_DEV_INF_EXTRA_NAME    "dev_inf_extra"  // db 设备列表云端未保存字段 tp，uddd，uddd2

typedef enum{
    E_GW_TYPE_ZB_NCP_MAC = 0,
}GW_FR_TYPE_E;

#define M_GW_RF_ERR_COMMON_ERR            1   //1:未知错误
#define M_GW_RF_ERR_NCP_VER_NOT_MATCHED   2   //2:ncp版本不匹配
#define M_GW_RF_ERR_OTA_PROCESS           3   //3:处于ota中
#define M_GW_RF_ERR_LOCAL_RESTORE_FAIL    4   //4:本地配置失败
#define M_GW_RF_ERR_ATOP_ACESS_FAIL       5   //5:otop接口访问失败
#define M_GW_RF_ERR_OSS_DWNLOWD_FAIL      6   //6:OSS下载失败
#define M_GW_RF_ERR_SERVICE_SYNC_FAIL     7   //7:业务数据同步失败
#define M_GW_RF_ERR_CLOUD_DATA_ERR        8   //8:云端数据错误
#define M_GW_RF_ERR_CLOUD_CA_ERR          9   //9:CA获取失败

typedef enum {
    E_STAT_NORMAL = 0,
    E_STAT_BACK_UP = 1,
    E_STAT_RESTORE = 2,
    E_STAT_RESTORE_2 = 3,
} FAUTL_REPLACE_STAT_E;

typedef struct{
    CHAR_T id[DEV_ID_LEN+1];
    DEV_TYPE_T tp;
    USER_DEV_DTL_DEF_T uddd; // user detial type define
    USER_DEV_DTL_DEF_T uddd2; /* 最高为1，预留给用户自有子设备*/
    CHAR_T lock_key[ENCRYPT_KEY_LEN*2 + 1];
    CHAR_T sw_ver[SW_VER_LEN+1];
    SLIST_HEAD  node;
} DEV_INFO_EXTRA_S;

typedef OPERATE_RET (*GW_FLT_RPL_BACK_UP_CB)(OUT CHAR_T *path, IN CONST INT_T len);
typedef OPERATE_RET (*GW_FLT_RPL_BACK_UP_DONE_NOTIFY_CB)(IN INT_T result);
typedef OPERATE_RET (*GW_FLT_RPL_RESTORE_GET_FILE_DATA_CB)(IN CONST BYTE_T *data , IN CONST UINT_T len);
typedef OPERATE_RET (*GW_FLT_RPL_RESTORE_START_CB)(OUT INT_T *errcode, IN CHAR_T *key, IN CHAR_T *iv);
typedef OPERATE_RET (*GW_FLT_RPL_RESTORE_NOTIFY_CB)(VOID);
typedef OPERATE_RET (*GW_FLT_RPL_REPLACE_NCP_MAC_CB)(IN CHAR_T *mac);
typedef OPERATE_RET (*GW_FLT_RPL_RESTORE_STAGE2_CB)(VOID);
typedef OPERATE_RET (*GW_FLT_RPL_RESTORE_DONE_NOTIFY_CB)(IN INT_T result);

typedef struct {
    GW_FLT_RPL_BACK_UP_CB gw_flt_rpl_back_cb;
    GW_FLT_RPL_BACK_UP_DONE_NOTIFY_CB gw_flt_rpl_back_up_done_notify_cb;
    GW_FLT_RPL_RESTORE_GET_FILE_DATA_CB gw_flt_rpl_restore_get_file_data_cb;
    GW_FLT_RPL_RESTORE_START_CB gw_flt_rpl_restore_start_cb;
    GW_FLT_RPL_RESTORE_NOTIFY_CB gw_flt_rpl_restore_notify_cb;
    GW_FLT_RPL_REPLACE_NCP_MAC_CB gw_flt_rpl_replace_ncp_mac_cb;
    GW_FLT_RPL_RESTORE_STAGE2_CB gw_flt_rpl_restore_stage2_cb;
    GW_FLT_RPL_RESTORE_DONE_NOTIFY_CB gw_flt_rpl_restore_done_notify_cb;
}GW_FLT_RPL_CBS_S;

OPERATE_RET tuya_gw_config_back_up_cycle(VOID);
DEV_INFO_EXTRA_S *tuya_gw_flt_rpl_dev_inf_traversal(INOUT VOID **iter);
OPERATE_RET tuya_gw_flt_rpl_ncp_mac_get(OUT CHAR_T *mac);
OPERATE_RET tuya_gw_flt_rpl_ncp_mac_set(IN CHAR_T *mac);
OPERATE_RET tuya_gw_flt_rpl_status_get(OUT FAUTL_REPLACE_STAT_E *stat);
OPERATE_RET tuya_gw_flt_rpl_status_set(IN FAUTL_REPLACE_STAT_E stat);
OPERATE_RET tuya_gw_flt_rpl_dec_buf_with_aes_cbc_128(IN BYTE_T *buf, IN UINT_T size, OUT BYTE_T **dec_buf, 
                                                OUT UINT_T *dec_size, IN BYTE_T *key,IN BYTE_T *iv);
OPERATE_RET tuya_iot_gw_fault_replace_init(GW_FLT_RPL_CBS_S *gw_flt_rpl_cbs);


#ifdef __cplusplus
}
#endif
#endif

