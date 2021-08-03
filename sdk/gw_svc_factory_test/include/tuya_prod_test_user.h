#ifndef _TUYA_PROD_TEST_USER_H_
#define _TUYA_PROD_TEST_USER_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define TUYA_ENTER_PRODTEST_SSID "tuya_zigbee_prodtest_scan"


int tuya_prod_user_upgrade_run(char *file_path);
int tuya_prod_user_if_key_test_cb();
int tuya_prod_user_init(char *master_version, char *zigbee_version);
int tuya_prod_user_deinit();
int tuya_prod_user_if_enter_prodtest();
int tuya_prod_user_set_exit_flag(int status);
int tuya_prod_user_if_prodtest_no_need_run();


#ifdef __cplusplus
}
#endif

#endif

