/***********************************************************
*  File: tuya_z3_api_tmp.h
*  Author: hxh
*  Date: 201805
***********************************************************/
#ifndef __TUYA_Z3_API_TMP_H
#define __TUYA_Z3_API_TMP_H

//#include "tuya_z3_base.h"

#ifdef __cplusplus
	extern "C" {
#endif

#ifdef CONFIG_PLATFORM_8195A
#include "FreeRTOS.h"
#include "queue.h"
    extern QueueHandle_t host_send_queue;
    extern QueueHandle_t host_recv_queue;
#endif


#define Z3_LIB
#ifdef Z3_LIB

#ifdef CONFIG_PLATFORM_8195A
VOID tuya_z3_main(PVOID_T pArg);
#else
typedef void (*gw_restart_cb)(void);

typedef struct TY_ZB_CONFIG_S {
    CHAR_T    serial_name[128];
    UINT_T    serial_baud_rate;
    CHAR_T    fs_storge_path[256];
    CHAR_T    fs_backup_path[256];
    CHAR_T    bin_dir[256];
    CHAR_T    tmp_dir[256];
    UCHAR_T   debug_level;
    BOOL_T    is_cts;
    gw_restart_cb gw_restart_func;
} TY_ZB_CONFIG_S;

#define ENGINEER_DEV_FLAG_FILE "engineer_dev_flag.ini"


int tuya_z3_main(const char* current_bin_dir, const char* current_storage_dir, \
        const char* current_tmp_dir, const char* current_backup_dir, \
        const char* serial_port, const unsigned int is_cts);

VOID tuya_zb_host_main(VOID *arg);
TY_ZB_CONFIG_S *tuya_z3_get_cfg(VOID);
#endif
#endif

#ifdef __cplusplus
}
#endif


#endif
