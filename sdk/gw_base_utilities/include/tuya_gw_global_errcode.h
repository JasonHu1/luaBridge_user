/*******************************************************************
*  File: tuya_gw_global_errcode.h
*  Author: auto generate by tuya code gen system
*  Description:this file defined the error code of tuya IOT 
*  Device OS module GLOBAL, you can change it manully
*  if needed
*  Copyright(C),2018-2020, tuya inc, www.tuya.comm
*******************************************************************/

#ifndef __TUYA_GW_GLOBAL_ERRCODE_H__
#define __TUYA_GW_GLOBAL_ERRCODE_H__

#include "tuya_cloud_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TY_GW_CALL_ERR_RETURN_VAL
#define TY_GW_CALL_ERR_RETURN_VAL(func, y)\
do{\
    rt = (func);\
    if (OPRT_OK != (rt)){\
        PR_ERR("call %s return %d", #func, rt);\
        return (y);\
    }\
}while(0)
#endif

#ifndef TY_GW_CALL_ERR_RETURN
#define TY_GW_CALL_ERR_RETURN(func)\
do{\
    rt = (func);\
    if (OPRT_OK != (rt)){\
       PR_ERR("call %s return %d", #func, rt);\
       return (rt);\
    }\
}while(0)
#endif

#ifndef TY_GW_CALL_ERR_RETURN_VOID
#define TY_GW_CALL_ERR_RETURN_VOID(func)\
do {\
    rt = (func);\
    if (OPRT_OK != (rt)) {\
        PR_ERR("call %s return %d", #func, rt);\
        return;\
    }\
} while (0)
#endif

#ifndef TY_GW_CALL_FALSE_RETURN
#define TY_GW_CALL_FALSE_RETURN(func)\
do{\
    if (FALSE == (func)){\
       PR_ERR("call %s return FALSE", #func);\
       return FALSE;\
    }\
}while(0)
#endif

#ifndef TY_GW_CALL_ERR_GOTO
#define TY_GW_CALL_ERR_GOTO(func, _label)\
do{\
    rt = (func);\
    if (OPRT_OK != (rt)){\
        PR_ERR("call %s return %d", #func, rt);\
        goto _label;\
    }\
}while(0)
#endif

#ifndef TY_GW_CALL_ERR_LOG
#define TY_GW_CALL_ERR_LOG(func)\
do{\
    rt = (func);\
    if (OPRT_OK != (rt))\
        PR_ERR("call %s return %d", #func, rt);\
}while(0)
#endif

#ifndef TY_GW_CHECK_NULL_RETURN
#define TY_GW_CHECK_NULL_RETURN(x)\
do{\
    if (NULL == (x)){\
        PR_ERR("%s is null!", #x);\
        return OPRT_INVALID_PARM;\
    }\
}while(0)
#endif

#ifndef TY_GW_CHECK_NULL_RETURN_VAL
#define TY_GW_CHECK_NULL_RETURN_VAL(x, y)\
do{\
    if (NULL == (x)){\
        PR_ERR("%s is null!", #x);\
        return (y);\
    }\
}while(0)
#endif

#ifndef TY_GW_CHECK_NULL_RETURN_VOID
#define TY_GW_CHECK_NULL_RETURN_VOID(x)\
do {\
    if (NULL == (x)) {\
        PR_ERR("%s is null!", #x);\
        return;\
    }\
} while (0)
#endif

#ifndef TY_GW_CHECK_NULL_GOTO
#define TY_GW_CHECK_NULL_GOTO(x)\
do{\
    if (NULL == (x)){\
        PR_ERR("%s is null!", #x);\
        goto ERR_EXIT;\
    }\
}while(0)
#endif

#ifdef __cplusplus
}
#endif
#endif
