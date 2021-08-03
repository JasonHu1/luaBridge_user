#ifndef __TUYA_Z3_WHITELIST_H__
#define __TUYA_Z3_WHITELIST_H__
#include "tuya_cloud_error_code.h"
#include "tuya_z3_zigbee_bash.h"

#ifdef __cplusplus
    extern "C" {
#endif

typedef struct _z3_white_dev_node{
    CHAR_T dev_id[DEV_ID_MAX_LEN+1];    //白名单设备
    TIME_T timestamp;                   //超时删除时间
    struct _z3_white_dev_node *next;    //下一个结点
}Z3_WHITE_DEV_NODE;

/**
 * @brief 添加一个子设备mac到白名单
 * 
 * @param id 子设备mac地址，String
 * @param timeout 超时时间，Value
 * @return OPERATE_RET 
 */
OPERATE_RET tuya_z3_whitelist_node_add(CHAR_T* id, UINT_T timeout);

/**
 * @brief 检查一个子设备是否存在于白名单列表中
 * 
 * @param id 子设备mac地址，String
 * @return BOOL_T 
 */
BOOL_T tuya_z3_whitelist_node_check(CHAR_T *id);

#ifdef __cplusplus
    }
#endif

#endif //!__TUYA_Z3_WHITELIST_H__