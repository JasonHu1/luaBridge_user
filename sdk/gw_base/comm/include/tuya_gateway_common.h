/**
 * @file tuya_gateway_common.h
 * @author zhangyu@tuya.com
 * @brief 涂鸦网关基础定义以及头文件，无业务相关性
 * 
 * @date 2020-07-17
 * @copyright Copyright (c) tuya.inc 2020
 */

#ifndef __TUYA_GATEWAY_COMMON_H__
#define __TUYA_GATEWAY_COMMON_H__

/****** 公共头文件 ******/
#include <stdio.h>
#include <string.h>

/****** 类型定义 ******/
#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_types.h"

/****** 系统资源 ******/
#include "uni_log.h"            // log print
#include "mem_pool.h"           //Malloc and Free
#include "tuya_hal_mutex.h"     //mutex
#include "tuya_hal_semaphore.h" //semaphore
#include "tuya_hal_system.h"    //sleep

/****** 时间、定时器 ******/
#include "uni_time.h"       //get time
#include "uni_time_queue.h" //TIMERID
#include "uni_module.h"     //module
#include "sys_timer.h"      //timer api

/****** 网关通用定义 ******/
#include "gw_com_def.h"
#include "tuya_gw_com_api.h"

/****** 网关基础功能宏 ******/
#include "tuya_gw_base_utilities.h"

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef PACKED
#define PACKED __attribute__((packed))
#endif

#ifdef __cplusplus
}
#endif

#endif //!__TUYA_GATEWAY_COMMON_H__