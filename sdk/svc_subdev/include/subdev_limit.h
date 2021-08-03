#ifndef __SUBDEV_LIMIT_H__
#define __SUBDEV_LIMIT_H__



#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"


#ifdef __cplusplus
    extern "C" {
#endif



#if defined(ENABLE_SUBDEVICE) && (ENABLE_SUBDEVICE==1)
/**
 * @brief Set the maximum count of sub-devices
 * @param cnt : Maximum count of user allowed
 * @return TRUE is success
 */
BOOL_T gw_set_subdev_max_cnt(UINT_T cnt);

UINT_T gw_get_subdev_max_cnt(VOID);

/**
 * @brief Get the count of sub-devices
 * @return UINT_T, The count of sub-devices.
 *         If upgrad from an unrestricted version, the current count may exceed the limit.
 */
UINT_T gw_get_subdev_cnt(VOID);

/**
 * @brief Check current count of sub-devices
 * @return TRUE is over max
 */
BOOL_T gw_is_subdev_cnt_over_max(VOID);

#endif


#ifdef __cplusplus
} // extern "C"
#endif

#endif  // __SUBDEV_LIMIT_H__

