/**
* @file tuya_reliable_fingerprint.h
* @author zhangyu@tuya.com
* @brief 门锁指纹下发
* @date 2019-11-27
*
* @copyright Copyright (c) tuya.inc 2019
*
*/

#ifndef __TUYA_RELIABLE_FINGERPRINT_H__
#define __TUYA_RELIABLE_FINGERPRINT_H__

#include "tuya_reliable.h"
#ifdef TUYA_RELIABLE_FINGERPRINT_SUPPORT

#include "tuya_gw_encrypt.h"

#ifdef __cplusplus
    extern "C" {
#endif // __cplusplus


#define FINGER_SYNC_INTERVAL (60 * 60)  //1h
#define FINGER_RETRY_INTERVAL 15 //15s
#define FINGER_SEND_TIMEOUT 45 //45s
#define FINGER_TASK_MAX_CNT 50 //下发任务列表最多支持50个

typedef struct {
    UINT16_T    seq;
    BYTE_T      type;
    INT_T       random;
    USHORT_T    finger_id;
    UINT_T      start_time;
    UINT_T      end_time;
    USHORT_T    size;
    UINT_T      check_sum_bin;
    UINT_T      check_sum_str;

}PACKED RELIABLE_FINGER_NOTIFY_S;

/**
 * @brief 初始化指纹下发功能
 *
 * @return OPERATE_RET
 */
OPERATE_RET tuya_reliable_finger_init(GW_ENCRYPT_S *p_encrypt);


/**
 * @brief 指纹传输通知
 *
 * @param dev_id 设备mac地址
 * @param dp_data dp数据
 * @param data_len dp数据长度
 * @return OPERATE_RET
 */
OPERATE_RET tuya_reliable_finger_notify(IN CONST CHAR_T *dev_id, IN CONST BYTE_T *dp_data, IN UINT_T data_len);

/**
 * @brief 获取指纹分包请求处理
 *
 * @param dev_if
 * @param req_data
 * @param req_len
 * @return OPERATE_RET
 */
OPERATE_RET tuya_reliable_finger_block_data_rep(IN DEV_DESC_IF_S* dev_if, IN UCHAR_T* req_data, IN INT_T req_len);

/**
 * @brief 指纹数据传输结果上报
 *
 * @param dev_if
 * @param req_data
 * @param req_len
 * @return OPERATE_RET
 */
OPERATE_RET tuya_reliable_finger_result_rep(IN DEV_DESC_IF_S* dev_if, IN UCHAR_T* req_data, IN INT_T req_len);


#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TUYA_RELIABLE_MCU_OTA_SUPPORT
#endif // __TUYA_RELIABLE_FINGERPRINT_H__
