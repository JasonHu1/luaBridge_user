#ifndef _TUYA_PROD_TEST_COMMON_H_
#define _TUYA_PROD_TEST_COMMON_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "tuya_cloud_types.h"
#include "tuya_prod_test.h"
#include "tuya_testframe_handle.h"

#define TUYA_PROD_CMD_MAX 128
#define TUYA_PROD_READ_MAX 32

//upgrade
#define UPGRADE_FILE_PATH "/tmp/upgrade_file_recv"
#define TCP_TRANS_FILE_SIZE_UNIT 1024
#define FILE_DECOMPRESSION_PATH "/tmp/prod_ug/"
#define TUYA_APP_PATH "/tuya/"
#define APP_STOP_CMD "/tuya/tuya_user1/app_stop.sh"
#define APP_START_CMD "/tuya/tuya_start.sh"

typedef struct{
    ULONG_T up_file_crc32;
    ULONG_T up_file_size;
    UCHAR_T upgrade_has_start;
    ULONG_T up_file_recv;
    UINT_T up_file_hash;
    INT_T up_firmware_cpu;
    INT_T up_fd;  
}TYTEST_UPGRADE;
typedef struct tuya_test_user_handler{
    TYTEST_UPGRADE upgrade_cntl;
 }TYTEST_USER_HANDLER;

//zigbee
VOID tuya_zigbee_get_rftest_result(USHORT_T CurPacketCounter);
int tuya_prod_test_common_zigbee_rf(int index,int channel, int num);
VOID tuya_report_coo_update_status(INT_T status);
//upgrade
OPERATE_RET tuya_prod_test_common_up_slave(UPGRADE_TYPE image_type);
OPERATE_RET tuya_prod_test_common_up_cfg(unsigned long baud, unsigned long crc32, unsigned long size);
OPERATE_RET tuya_prod_test_common_up_start(VOID);
OPERATE_RET tuya_prod_test_common_up_file_rcv(char *data, unsigned int data_len);
OPERATE_RET tuya_prod_test_common_up_end(VOID);

OPERATE_RET tuya_prod_test_common_if_key_test_cb();
int tuya_prod_test_common_init(char *master_ver, char *zigbee_ver);
OPERATE_RET tuya_prod_test_common_exit();
BOOL_T tuya_if_enter_prodtest();


#ifdef __cplusplus
}
#endif

#endif

