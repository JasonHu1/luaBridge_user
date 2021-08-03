/**
 * @file tuya_os_adapt_memory.h
 * @author sunkz@tuya.com
 * @brief 内存操作接口封装
 * @version 0.1
 * @date 2020-05-9
 * 
 * @copyright Copyright (c) tuya.inc 2019
 * 
 */

#ifndef __TUYA_OS_ADAPT_MEMORY_H__
#define __TUYA_OS_ADAPT_MEMORY_H__


#include <stddef.h>
#include "tuya_os_adapter.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @brief tuya_os_adapt_system_malloc用于分配内存
 * 
 * @param[in]       size        需要分配的内存带下
 * @return  分配得到的内存指针
 */
void *tuya_os_adapt_system_malloc(const size_t size);

/**
 * @brief tuya_os_adapt_system_free用于释放内存
 * 
 * @param[in]       ptr         需要释放的内存指针
 */
void tuya_os_adapt_system_free(void* ptr);

/**
 * @brief tuya_os_adapt_system_calloc 用于分配并清除干净内存
 * 
 * @param[in]       nitems      需要分配内存块的数量
 * @param[in]       size        需要分配块的内存大小
 */
void *tuya_os_adapt_system_calloc(size_t nitems, size_t size);

/**
 * @brief tuya_os_adapt_system_realloc 重新调整内存大小
 * 
 * @param[in]       nitems      源内存指针
 * @param[in]       size        调整后的大小
 */
void *tuya_os_adapt_system_realloc(VOID_T* ptr, size_t size);

/* add begin: by sunkz, interface regist */
OPERATE_RET tuya_os_adapt_reg_memory_intf(VOID_T);
/* add end */


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif // __TUYA_HAL_MEMORY_H__

