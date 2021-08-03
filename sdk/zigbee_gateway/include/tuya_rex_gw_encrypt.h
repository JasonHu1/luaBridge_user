/***********************************************************
*  File: tuya_rex_gw_encrypt.h
*  Author: dingsl
*  Date: 20180707
***********************************************************/
#ifndef ___TUYA_REX_GW_ENCRYPT_H
#define ___TUYA_REX_GW_ENCRYPT_H

#include <time.h>
#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"
#include "uni_module.h"
#include "tuya_hal_mutex.h"
#include "uni_slist.h"

#ifndef PACKED
#define PACKED __attribute__((packed))
#endif

typedef struct
{
    SLIST_HEAD  cmd_list;
    SLIST_HEAD  dev_list;
    MUTEX_HANDLE mutex;
    TIMER_ID    tm;
    TIMER_ID    sync_tm;
    time_t      sync_normal_time;  
    INT_T       cmd_num;
    
}PACKED REX_GW_ENCRYPT_S;

#endif
