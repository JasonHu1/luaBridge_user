#ifndef __TUYA_GW_BASE_SAFE_MALLOC_H__
#define __TUYA_GW_BASE_SAFE_MALLOC_H__

#include <string.h>

#include "mem_pool.h"
#include "uni_log.h"
#include "tuya_cloud_error_code.h"

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef SAFE_MALLOC_ERR_GOTO
/**
 * @brief 内存申请并置0，失败跳转
 * 
 */
#define SAFE_MALLOC_ERR_GOTO(_ptr, _size, _label)\
do{\
    if (NULL == ((_ptr) = Malloc((_size)))){\
        PR_ERR("Malloc err.");\
        rt = OPRT_MALLOC_FAILED;\
        goto _label;\
    }\
    memset((_ptr), 0, (_size));\
}while(0)
#endif

#ifndef SAFE_MALLOC_ERR_RET
/**
 * @brief 内存申请并置0，失败返回
 * 
 */
#define SAFE_MALLOC_ERR_RET(_ptr, _size)\
do{\
    if (NULL == ((_ptr) = Malloc((_size)))){\
        PR_ERR("Malloc err.");\
        return OPRT_MALLOC_FAILED;\
    }\
    memset((_ptr), 0, (_size));\
}while(0)
#endif

#ifndef SAFE_MALLOC
/**
 * @brief 内存申请并置0，失败不返回
 * 
 */
#define SAFE_MALLOC(_ptr, _size)\
do{\
    if (NULL == ((_ptr) = Malloc((_size)))){\
        PR_ERR("Malloc err.");\
    } else {\
        memset((_ptr), 0, (_size));\
    }\
}while(0)
#endif

#ifndef SAFE_FREE
/**
 * @brief 释放指针并且置空
 * 
 */
#define SAFE_FREE(_ptr)\
do{\
    if(NULL != (_ptr)){\
        Free((_ptr));\
        (_ptr) = NULL;\
    }else{\
        PR_NOTICE("Pointer is null,do not free again.");\
    }\
}while(0)
#endif

#ifdef __cplusplus
}
#endif

#endif //!__TUYA_GW_BASE_SAFE_MALLOC_H__
