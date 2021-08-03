/***********************************************************
*  File: smart_frame.h
*  Author: nzy
*  Date: 20170413
***********************************************************/
#ifndef _GROUP_SCENE_SERVE_H
#define _GROUP_SCENE_SERVE_H

#include "tuya_cloud_types.h"
#include "tuya_hal_mutex.h"
#include "uni_thread.h"
#include "smart_frame.h"

#if defined(ENABLE_SUBDEVICE) && (ENABLE_SUBDEVICE==1)

#ifdef __cplusplus
    extern "C" {
#endif
#if defined(OPERATING_SYSTEM) && (OPERATING_SYSTEM!=SYSTEM_LINUX)
#define GRP_SCE_MAX_DP_NUM 32
#define GRP_SCE_FILE_NAME_LEN_MAX 32
#else
#define GRP_SCE_MAX_DP_NUM 64
#define GRP_SCE_FILE_NAME_LEN_MAX 64
#endif
#define GRP_SCE_FLAG_FILE_NAME     "grp_sce_flag_file"
#define GRP_SCE_FILE_NAME          "grp_sce_save_file"
#define GRP_SCE_BACK_FILE_NAME          "grp_sce_save_bak_file"

//校准时间
#define EXE_CALIBRATION_TIME 3


typedef enum {
    GRP_SEC_ADD = 0, // add a group sce
    GRP_SEC_DEL      // delete a group sce
}GRP_SEC_ACTION_E;


typedef struct grp_sce_dev_list_s {
    struct grp_sce_dev_list_s *next;
    CHAR_T dev_id[DEV_ID_LEN+1];
    BYTE_T dp_id[GRP_SCE_MAX_DP_NUM];
    BYTE_T dp_flag[GRP_SCE_MAX_DP_NUM];
    INT_T dp_num;
}GRP_SCE_DEV_LIST_S;


typedef struct {
    GRP_SCE_DEV_LIST_S *dev_list;
    UINT_T grp_sce_list_num;
    UINT_T uiTime;
}GRP_SCE_TMP_S;


typedef struct grp_sce_cmd_list_s {
    struct grp_sce_cmd_list_s *next;
    USHORT_T grp_id;
    USHORT_T sce_id;
    CHAR_T dev_id[DEV_ID_LEN+1];
    BYTE_T dp_id;
    CHAR_T use_flag;// 1 表明正常查询设备
    TIME_S uiTime;
}GRP_SCE_CMD_LIST_S;


typedef struct {
    GRP_SCE_CMD_LIST_S *cmd_list;
    UINT_T grp_sce_cmd_num;
    UINT_T uiTime;
}GRP_SCE_CMD_S;


typedef struct{
    BOOL_T is_init;
    MUTEX_HANDLE mutex; // mutex
    THRD_HANDLE grpthread;
    BOOL_T grp_sce_process; //发过场景后，再发dp时，认为是新的一轮
    GRP_SCE_TMP_S sce_tmp; //场景配置时的临时缓存
    GRP_SCE_CMD_S grp_sce_cmd_tmp; //组、场景命令下发的临时缓存
    GRP_SCE_TMP_S grp_sce_query_list; //触发组或场景后要查询的例表
    CHAR_T is_save_flag; //异步存储，主要是解决存储文件大，导致保存慢的问题
    UCHAR_T file_flag;    //备份存储flag
    CHAR_T flag_file_path[GRP_SCE_FILE_NAME_LEN_MAX+1];     //文件含路径名
    CHAR_T file_path[GRP_SCE_FILE_NAME_LEN_MAX+1];     //文件含路径名
    CHAR_T back_file_path[GRP_SCE_FILE_NAME_LEN_MAX+1]; //备份文件含路径名
    CHAR_T *grp_sce_list; // 存储的场景与子设备例表
#if defined(ENABLE_SIGMESH) && (ENABLE_SIGMESH==1)
    TM_MSG_S *tmm_group_relation_sync;
#endif
}GROUP_SCENE_INFO_S;

/*

typedef struct{
    USHORT_T grp_id;
    USHORT_T sce_id;
    USHORT_T dev_num;
    GROUP_SCENE_DEV_INFO_S dev_info[0];
}SIG_GROUP_SCENE_LIST_S;


typedef struct{
    USHORT_T grp_sce_num;
    SIG_GROUP_SCENE_LIST_S grp_sce[0];
}TOTAL_GROUP_SCENE_LIST_S;
*/

typedef struct {
    DP_CMD_TYPE_E tp;
    ty_cJSON *cmd_js;
}SF_GW_SCE_CMD_S;


/***********************************************************
*  Function: group_scene_del_store_by_dev
*  Input: dev_id
*  Output: none
*  Return: ok, other error.
***********************************************************/
OPERATE_RET group_scene_del_store_by_dev(CHAR_T *dev_id);


/***********************************************************
*  Function: group_scene_add_scene_tmp
*  Input: dev_id, dp_id
*  Output: none
*  Return: ok, other error.
***********************************************************/
OPERATE_RET group_scene_add_scene_tmp(IN CONST CHAR_T *dev_id, BYTE_T dp_id);


/***********************************************************
*  Function: group_scene_cmd_add
*  Input: grp_id, sce_id, dev_id, dp_id
*  Output: none
*  Return: ok, other error.
***********************************************************/
OPERATE_RET group_scene_cmd_exce(IN CONST CHAR_T  *grp_id_str, USHORT_T sce_id, CHAR_T *dev_id, BYTE_T dp_id);


/***********************************************************
*  Function: group_scene_serve_init
*  Input: p_log_seq_path:save path
*  Output: none
*  Return: ok, other error.
***********************************************************/
OPERATE_RET group_scene_serve_init(CONST CHAR_T *p_log_seq_path, CONST IN BOOL_T engineer_mode);


/* 接收并处理来自mqtt，tcp的场景操作命令 */
OPERATE_RET sf_send_scene_oper_cmd(IN SF_GW_SCE_CMD_S *sce_cmd);

/***********************************************************
*  Function: sf_gw_scene_exce
*  Input: grp_id ,sce_id
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET sf_gw_scene_exce(IN CONST CHAR_T *grp_id, IN CONST CHAR_T *sce_id);

OPERATE_RET sf_send_grp_oper_cmd(IN SF_GW_DEV_CMD_S *grp_cmd);


OPERATE_RET group_scene_clear_all_data(VOID);

/***********************************************************
*  Function: sync_group_relation_handle
*  Input: none
*  Output: none
*  Return: ok, other error.
***********************************************************/
OPERATE_RET sync_group_relation_handle(VOID);

//工程相关特殊处理部分 --开始
//当op_ret == OPRT_OK时 ret_str有效
typedef OPERATE_RET (*SCENE_OPER_CMD_RET_CB)(OPERATE_RET op_ret, DP_CMD_TYPE_E tp, IN CHAR_T *ret_str);
typedef OPERATE_RET (*GROUP_OPER_CMD_RET_CB)(OPERATE_RET op_ret, DP_CMD_TYPE_E tp, IN CHAR_T *ret_str);

typedef struct{
    SCENE_OPER_CMD_RET_CB scene_ret;
    GROUP_OPER_CMD_RET_CB group_ret;
} SUBDEV_GROUP_SCENE_ENGR_HANDLE_CB_S;

OPERATE_RET group_scene_reg_engr_cb(SUBDEV_GROUP_SCENE_ENGR_HANDLE_CB_S *cbs);
//工程相关特殊处理部分 --结束



#ifdef __cplusplus
}
#endif
#endif
#endif
