#ifndef __TUYA_GW_BASE_UTILITIES_H__
#define __TUYA_GW_BASE_UTILITIES_H__

#include "tuya_gw_base_safe_malloc.h"
#include "tuya_gw_global_errcode.h"

#ifdef __cplusplus
    extern "C" {
#endif

#define ASSERT_RETURN(x, y)\
do{\
    if (!(x)){\
        PR_ERR("[%s] wrong, error !!!", #x);\
        return (y);\
    }\
}while(0)

#define ASSERT_RETURN_NONE(x)\
do{\
    if (!(x)){\
        PR_ERR("[%s] wrong, error !!!", #x);\
        return;\
    }\
}while(0)

#define ASSERT_GOTO(x, label)\
do{\
    if (!(x)){\
        PR_ERR("[%s] wrong, error !!!", #x);\
        goto label;\
    }\
}while(0)

#define ASSERT_PRINT(x)\
do{\
    if (!(x)){\
        PR_ERR("\n\n assert fail: \n[ %s ] !!!\n\n", #x);\
    }\
}while(0)

// 比Free更好， 因为释放后指针的值会被置为NULL， 防止野指针
#define FREE_S(p) do{ Free(p); p = NULL;} while(0)

#ifdef __cplusplus
}
#endif

#endif //!__TUYA_GW_BASE_UTILITIES_H__