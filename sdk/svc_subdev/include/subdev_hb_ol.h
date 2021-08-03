#ifndef __SUBDEV_HB_OL_H__
#define __SUBDEV_HB_OL_H__



#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"


#ifdef __cplusplus
    extern "C" {
#endif

typedef struct {
    CHAR_T id[DEV_ID_LEN+1];
} SUBDEV_ONLINE_LIST_S;

//函数返回成功时，需要调用者释放online_dev_list, offline_dev_list
//online_dev_num, offline_dev_num返回获取到的实际在线和离线子设备个数
OPERATE_RET gw_subdev_get_online_dev_list(OUT SUBDEV_ONLINE_LIST_S **online_dev_list_ptr, OUT INT_T *online_dev_num, OUT SUBDEV_ONLINE_LIST_S **offline_dev_list_ptr, OUT INT_T *offline_dev_num);

#ifdef __cplusplus
} // extern "C"
#endif

#endif  // __TUYA_WS_DB_SUBDEV_H__

