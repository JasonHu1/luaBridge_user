/**
 * @file tuya_os_adapt_system.c
 * @author sunkz@tuya.com
 * @brief 系统接口封装
 * @version 0.1
 * @date 2020-05-15
 * 
 * @copyright Copyright (c) tuya.inc 2019
 * 
 */

#ifndef _TUYA_OS_ADAPT_SYSTEM_H
#define _TUYA_OS_ADAPT_SYSTEM_H

#include <stdbool.h>
#include <stdint.h>
#include "tuya_os_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif


#define STR_POWERUP_EVENT(S) \
    ((S) == TUYA_RESET_REASON_POWERON ? "TUYA_RESET_REASON_POWERON" : \
    ((S) == TUYA_RESET_REASON_HARDWARE_WATCHDOG ? "TUYA_RESET_REASON_HARDWARE_WATCHDOG" : \
    ((S) == TUYA_RESET_REASON_SOFTWARE_WATCHDOG ? "TUYA_RESET_REASON_SOFTWARE_WATCHDOG" : \
    ((S) == TUYA_RESET_REASON_SOFTWARE ? "TUYA_RESET_REASON_SOFTWARE" : \
    ((S) == TUYA_RESET_REASON_DEEPSLEEP ? "TUYA_RESET_REASON_DEEPSLEEP" : \
"Unknown")))))


/**
 * @brief tuya_os_adapt_get_systemtickcount用于获取系统运行ticket 
 * 		count
 * @return SYS_TICK_T 
 */
SYS_TICK_T tuya_os_adapt_get_systemtickcount(void);

/**
 * @brief tuya_os_adapt_get_tickratems用于获取系统ticket是多少个ms
 * 
 * @return uint32_t the time is ms of a system ticket
 */
uint32_t tuya_os_adapt_get_tickratems(void);

/**
 * @brief tuya_os_adapt_system_sleep用于系统sleep
 * 
 * @param[in] msTime sleep time is ms
 */
void tuya_os_adapt_system_sleep(const unsigned long msTime);

/**
 * @brief tuya_os_adapt_system_reset用于重启系统
 * 
 */
void tuya_os_adapt_system_reset(void);

/**
 * @brief tuya_os_adapt_watchdog_init_start用于初始化并运行watchdog
 * 
 * @param[in] timeval watch dog检测时间间隔
 */
unsigned int tuya_os_adapt_watchdog_init_start(const unsigned int timeval);

/**
 * @brief tuya_os_adapt_watchdog_refresh用于刷新watch dog
 * 
 */
void tuya_os_adapt_watchdog_refresh(void);

/**
 * @brief tuya_os_adapt_watchdog_stop用于停止watch dog
 * 
 */
void tuya_os_adapt_watchdog_stop(void);

/**
 * @brief tuya_os_adapt_system_getheapsize用于获取堆大小/剩余内存大小
 * 
 * @return int <0: don't support  >=0: current heap size/free memory
 */
int tuya_os_adapt_system_getheapsize(void);

/**
 * @brief tuya_os_adapt_system_get_rst_info用于获取硬件重启原因
 * 
 * @return char* 硬件重启原因
 */
TY_RST_REASON_E tuya_os_adapt_system_get_rst_info(void);

/**
 * @brief tuya_os_adapt_get_random_data用于获取指定条件下的随机数
 * 
 * @param[in] range 
 * @return int
 */
int tuya_os_adapt_get_random_data(const unsigned int range);

/**
 * @brief tuya_os_adapt_set_cpu_lp_mode用于设置cpu的低功耗模式
 * 
 * @param[in] en 
 * @param[in] mode
 * @return int 0=成功，非0=失败
 */
int tuya_os_adapt_set_cpu_lp_mode(const bool_t en, const TY_CPU_SLEEP_MODE_E mode);

/* add begin: by sunkz, interface regist */
OPERATE_RET tuya_os_adapt_reg_system_intf(VOID_T);
/* add end */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

