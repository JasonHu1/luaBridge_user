#ifndef __COMPONENT_TUYA_DEV_MGR_H__
#define __COMPONENT_TUYA_DEV_MGR_H__

#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

typedef struct
{
    CHAR_T   dev_id[DEV_ID_LEN + 1]; //设备id
    INT_T    value; //当前功率
    TIME_T   timestamp; //时间戳

}TY_ROOM_DEV_INFO_S;

typedef struct
{
    //CHAR_T* room_id; //暂时不解析
    INT_T               dev_cnt; //家庭中温控器个数
    TY_ROOM_DEV_INFO_S* dev_list; //温控器设备列表

}TY_ROOM_INFO_S;

/**
 * @brief 检查该设备是否为有效温控器设备
 * 
 * @param[in] dev_id 设备id
 * @return TURE:有效设备
 */
typedef BOOL_T (*TY_THERMOSTAT_DEV_CHECK_CB)(IN CONST CHAR_T *dev_id);

/**
 * @brief 返回带计算房间信息
 * 
 * @param[in] room_info 房间信息
 */
typedef VOID (*TY_THERMOSTAT_ROOM_INFO_CB)(IN TY_ROOM_INFO_S *room_info);


typedef struct {
    TY_THERMOSTAT_DEV_CHECK_CB  dev_check_cb;
    TY_THERMOSTAT_ROOM_INFO_CB  room_info_cb;
}TUYA_THERMOSTAT_DEV_CBS_S;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  本地计算初始化
 * 
 * @param[in] thermostat_dev_cbs 用户回调
 * @return OPERATE_RET OPRT_OK:成功
 */
OPERATE_RET tuya_thermostat_dev_mgr_init(IN TUYA_THERMOSTAT_DEV_CBS_S *thermostat_dev_cbs);

/**
 * @brief  温控器数值更新
 * 
 * @param[in] dev_id 设备id
 * @param[in] value 设备数值
 * @return OPERATE_RET 
 */
OPERATE_RET tuya_thermostat_dev_value_update(IN CONST CHAR_T *dev_id, IN INT_T value);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __COMPONENT_TUYA_DEV_MGR_H__