#ifndef __TUYA_GW_ENGR_COM_API_H__
#define __TUYA_GW_ENGR_COM_API_H__

#include "tuya_cloud_types.h"

#ifdef __cplusplus
extern "C" {
#endif

//网关工作模式
typedef enum __gw_work_mode_e{
    GW_WORK_MODE_ENTER_NORMAL = 0,    /**< 进入正常模式 */
    GW_WORK_MODE_ENTER_ENGINEER,      /**< 进入工程模式 */
}GW_WORK_MODE_E;

//网关工作模式切换的函数类型
typedef VOID (*ENGR_MODE_CHANGE_CB)(GW_WORK_MODE_E mode);


#ifdef __cplusplus
}
#endif

#endif //__TUYA_GW_ENGR_COM_API_H__