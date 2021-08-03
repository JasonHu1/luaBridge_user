/*
tuya_gw_group_scene_api.h
Copyright(C),2018-2020, 涂鸦科技 www.tuya.comm
*/

#ifndef __TUYA_GW_GROUP_SCENE_API_H
#define __TUYA_GW_GROUP_SCENE_API_H

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************
*  Function: tuya_iot_grp_sce_exce_sys
*  Input: sync dev triggle group or scene
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_grp_sce_exce_sys(IN CONST CHAR_T *grp_id_str, IN CONST USHORT_T sce_id, IN CONST BYTE_T dp_id);


/***********************************************************
*  Function: tuya_iot_get_one_dev_by_group_scene
*  Input: grp_id, sce_id, index
*  Output: dev_id
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_get_one_dev_by_group_scene(IN CONST USHORT_T grp_id, IN CONST USHORT_T sce_id, IN CONST INT_T index, OUT CHAR_T *dev_id);


/***********************************************************
*  Function: tuya_iot_get_one_group_by_dev
*  Input:  index dev_id
*  Output: grp_id, sce_id
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_get_one_group_by_dev(OUT USHORT_T *grp_id, OUT USHORT_T *sce_id, IN CONST INT_T index, IN CONST CHAR_T *dev_id);

/***********************************************************
*  Function: tuya_iot_group_scene_del_store_by_grp
*  Input: grp_id
*  Output: none
*  Return: OPERATE_RET
***********************************************************/
OPERATE_RET tuya_iot_group_scene_del_store_by_grp(IN CONST USHORT_T grp_id);

/**
 * @brief 给某个群组添加一个标记
 *
 * @param grp_id [IN]USHORT_T, 需要添加的组id号
 * @param flag [IN]CHAR_T*, 标记字符串
 * @return OPERATE_RET 操作成功返回OPRT_OK
 */
OPERATE_RET tuya_iot_group_flag_add_store_handle(IN USHORT_T grp_id, IN CHAR_T *flag);

/**
 * @brief 根据组id获取标记列表
 *
 * @param grp_id [IN]USHORT_T, 组id
 * @param cnt [OUT]INT_T *, 标记个数
 * @return CHAR_T** 标记列表,失败返回NULL
 *
 * @note 使用结束之后需要使用free_group_flag_list释放
 */
CHAR_T** tuya_iot_get_group_flag_list(IN USHORT_T grp_id, OUT INT_T *cnt);

/**
 * @brief 标记列表指针
 *
 * @param list [IN]CHAR_T**, 需要释放的标记列表
 * @param cnt [IN]INT_T, 指针数组个数
 */
VOID tuya_iot_free_group_flag_list(IN CHAR_T** list, IN INT_T cnt);


typedef VOID (* GROUP_SAVE_SUCC_ST_CB)(IN CONST CHAR_T* grp_id, IN CONST CHAR_T* dev_id);
/**
 * @brief 子设备群组添加成功通知注册
 *
 * @return OPERATE_RET
 */
OPERATE_RET tuya_iot_group_save_succ_st_notity(GROUP_SAVE_SUCC_ST_CB notity);

#ifdef __cplusplus
}
#endif
#endif

