#ifndef __TUYA_BLE_PROCESS_H__
#define __TUYA_BLE_PROCESS_H__

#include "tuya_ble_process_pack.h"

#ifdef __cplusplus
extern "C" {
#endif

#define AIR_FRAME_MAX  256

#pragma pack(1)
typedef struct ty_blep_recv_packet_ {
    unsigned int    len;
    unsigned char   data[AIR_FRAME_MAX];
} ty_blep_recv_packet_s;

#define H_ID_LEN              19
//#define PRODUCT_ID_LEN        TUYA_BLE_PRODUCT_ID_OR_KEY_LEN
//#define PRODUCT_KEY_LEN       TUYA_BLE_PRODUCT_ID_OR_KEY_LEN
#define DEVICE_ID_LEN         16
#define DEVICE_ID_LEN_MAX     20
#define AUTH_KEY_LEN          32
#define LOGIN_KEY_LEN         6
#define ECC_SECRET_KEY_LEN    32
#define DEVICE_VIRTUAL_ID_LEN 22
#define SECRET_KEY_LEN        16
#define PAIR_RANDOM_LEN       6
#define MAC_LEN               6

#define TUYA_BLE_PRODUCT_ID_MAX_LEN  16

// APP == BLE Master 
#define FRM_QRY_DEV_INFO_REQ  0x0000  //APP->BLE
#define FRM_QRY_DEV_INFO_RESP 0x0000  //BLE->APP
#define PAIR_REQ              0x0001  //APP->BLE
#define PAIR_RESP             0x0001  //BLE->APP
#define FRM_CMD_SEND          0x0002  //APP->BLE
#define FRM_CMD_RESP          0x0002  //BLE->APP
#define FRM_STATE_QUERY       0x0003  //APP->BLE
#define FRM_STATE_QUERY_RESP  0x0003  //BLE->APP
#define FRM_LOGIN_KEY_REQ     0x0004  //APP->BLE
#define FRM_LOGIN_KEY_RESP    0x0004  //BLE->APP
#define FRM_UNBONDING_REQ     0x0005  //APP->BLE
#define FRM_UNBONDING_RESP    0x0005  //BLE->APP
#define FRM_DEVICE_RESET      0x0006  //APP->BLE
#define FRM_DEVICE_RESET_RESP 0x0006  //BLE->APP

#define FRM_BULKDATA_START_REQ              0x0007  //APP->BLE
#define FRM_BULKDATA_START_CONFIRM          0x0008  //APP->BLE
#define FRM_BULKDATA_DATA_SEND_RESP         0x0009  //APP->BLE
#define FRM_BULKDATA_DATA_SEND_END_RESP     0x000A  //APP->BLE
#define FRM_BULKDATA_DATA_SEND_FORCED_END   0x000B  //APP->BLE


#define FRM_OTA_START_REQ         0x000C //APP->BLE
#define FRM_OTA_START_RESP        0x000C //BLE->APP
#define FRM_OTA_FILE_INFOR_REQ    0x000D //APP->BLE
#define FRM_OTA_FILE_INFOR_RESP   0x000D //BLE->APP
#define FRM_OTA_FILE_OFFSET_REQ   0x000E //APP->BLE
#define FRM_OTA_FILE_OFFSET_RESP  0x000E //BLE->APP
#define FRM_OTA_DATA_REQ          0x000F //APP->BLE
#define FRM_OTA_DATA_RESP         0x000F //BLE->APP
#define FRM_OTA_END_REQ           0x0010 //APP->BLE
#define FRM_OTA_END_RESP          0x0010 //BLE->APP

#define FRM_FACTORY_TEST_CMD           0x0012 //APP->BLE
#define FRM_FACTORY_TEST_RESP          0x0012 //BLE->APP


#define FRM_ANOMALY_UNBONDING_REQ      0x0014 //APP->BLE
#define FRM_ANOMALY_UNBONDING_RESP     0x0014 //BLE->APP


#define FRM_NET_CONFIG_INFO_REQ   0x0021 //APP->BLE
#define FRM_NET_CONFIG_INFO_RESP  0x0021 //BLE->APP

#define FRM_NET_CONFIG_RESPONSE_REPORT_REQ   0x0022 //APP->BLE
#define FRM_NET_CONFIG_RESPONSE_REPORT_RESP  0x0022 //BLE->APP


#define FRM_DATA_PASSTHROUGH_REQ   0x0023 //APP<->BLE


#define FRM_STAT_REPORT         0x8001  //BLE->APP
#define FRM_STAT_REPORT_RESP    0x8001  //APP->BLE

#define FRM_STAT_WITH_TIME_REPORT    0x8003  //BLE->APP
#define FRM_STAT_WITH_TIME_REPORT_RESP      0x8003  //APP->BLE

#define FRM_BULKDATA_START_RESP                 0x8007  //BLE->APP
#define FRM_BULKDATA_START                      0x8008  //BLE->APP
#define FRM_BULKDATA_DATA_SEND_REQ              0x8009  //BLE->APP
#define FRM_BULKDATA_DATA_SEND_END_REQ          0x800A  //BLE->APP
#define FRM_BULKDATA_DATA_SEND_FORCED_END_RESP  0x800B  //BLE->APP
 
#define FRM_GET_UNIX_TIME_MS_REQ           0x8010  //BLE->APP
#define FRM_GET_UNIX_TIME_MS_RESP          0x8010  //APP->BLE
#define FRM_GET_UNIX_TIME_CHAR_MS_REQ      0x8011  //BLE->APP
#define FRM_GET_UNIX_TIME_CHAR_MS_RESP     0x8011  //APP->BLE
#define FRM_GET_UNIX_TIME_CHAR_DATE_REQ    0x8012  //BLE->APP
#define FRM_GET_UNIX_TIME_CHAR_DATE_RESP   0x8012  //APP->BLE

#define TUYA_BLE_PROTOCOL_V0100             (0x0100)
#define TUYA_BLE_PROTOCOL_V0200             (0x0200)
#define TUYA_BLE_PROTOCOL_V0300             (0x0300)
#define TUYA_BLE_PROTOCOL_V0303             (0x0303)  // v3.3 protocol


enum
{
    ENCRYPTION_MODE_NONE,
    ENCRYPTION_MODE_KEY_1,
    ENCRYPTION_MODE_KEY_2,//MD5（secret_key_1,srand）的结果16字节转32个字符，取第8-24个字符，只用于配对请求指令。
    ENCRYPTION_MODE_KEY_3,//MD5(secret_key_1,srand,user_rand) 的结果16字节转32个字符，取第8-24个字符,适用于高级加密设备
    ENCRYPTION_MODE_KEY_4,//MD5（login_key）的结果16字节转32个字符，取第8-24个字符
    ENCRYPTION_MODE_SESSION_KEY,//MD5（login_key,srand）的结果16字节转32个字符，取第8-24个字符
    ENCRYPTION_MODE_MAX,
};

typedef struct ty_ble_key_ {
	unsigned char 			auth_key[32];
	unsigned char 			device_uuid[16];
	unsigned char 			login_key[6];
	unsigned char 			virtual_id[22];
	unsigned char 			product_id[8];
    unsigned char           version;  // this is ble protocol version. should be 1/2/3
    unsigned short          protocol_version; // this is ble protocol specific version. should be 2.4 3.0 3.3 --
    unsigned short          ble_firmware_version;
    unsigned char           mcu_firmware_version[3];

	unsigned char 			key[16];
	unsigned char           server_rand[16];
	unsigned char           pair_rand[6];
	unsigned char 			secret_key_1[16];
	unsigned char 			secret_key_2[16];
	unsigned char 			secret_key_3[16];
	unsigned char 			secret_key_4[16];
	unsigned char 			session_key[16];
} ty_ble_key;
#pragma pack()

int  tuya_ble_decrypt_old_with_key(uint8_t *key,uint8_t *in_buf,uint8_t in_len,uint8_t *out_buf);

int ty_ble_device_id_decrypt(uint8_t *key_in,uint16_t key_len,uint8_t *input,uint16_t input_len,uint8_t *output);

int ty_ble_generate_key(uint8_t mode,uint8_t *IV,ty_ble_key* dev_key);

int ty_ble_monitor_key(unsigned char *auth_key,unsigned char *server_rand,unsigned char *secret_key_1);

int ty_blep_process_packet(ty_blep_recv_packet_s* ppacket,
                            ty_frm_trsmitr_proc_s* ptrdata,
                            unsigned char *buf, unsigned int len);


int ty_blep_pack_cmd(ty_blep_header_s* phdr, char* pdata, int len, unsigned char* pencout, int* penclen,
                    int enflag, ty_ble_key *dev_key);

int ty_blep_unpack_cmd(ty_blep_header_s* phdr, ty_blep_recv_packet_s* packet,
						char* pout, int* plen, unsigned char* pkey);

int ty_blep_unpack_session_cmd(ty_blep_header_s* phdr, ty_blep_recv_packet_s* packet,
                char* pout, int* plen, unsigned char* pkey);


int ty_blep_exchange_key(ty_blep_header_s* phdr, char* pkey, int len, unsigned char* pout, int* polen);

int ty_blep_pack_session_data(ty_blep_header_s* phdr, char* pdata, int len, unsigned char* pencout, int* penclen, unsigned char*key);

#ifdef __cplusplus
}
#endif

#endif
