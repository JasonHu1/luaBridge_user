/**
 * @file tuya_z3_host_flowctrl.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __TUYA_Z3_HOST_FLOWCTRL_H__
#define __TUYA_Z3_HOST_FLOWCTRL_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#ifdef __cplusplus
    extern "C" {
#endif

/**
 * @brief 更新忙状态
 * 
 * @param is_busy 
 */
void tuya_z3_host_flowctrl_update(bool is_busy);

/**
 * @brief 获取是否在忙
 * 
 * @return true 
 * @return false 
 */
bool tuya_z3_host_flowctrl_is_busy(void);


#ifdef __cplusplus
    }
#endif

#endif //!__TUYA_Z3_WHITELIST_H__

