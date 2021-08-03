#ifndef __PRR_H__
#define __PRR_H__

#define TEST_OUI						"\x04\x8d\x38"
#define PROTO_OUI					"\x04\x88\xf0"
#define TUYA_OUI						"\x68\x57\x2d"
#define DEFAULT_OUI					TUYA_OUI

#define MAX_PRR_BUF					(1024 * 10)
#define MAX_PRR_DEV_ID				(16)

typedef struct
{
	unsigned char buf[MAX_PRR_BUF];
	unsigned int sz;
	unsigned int len;
}prr_buf_t;

typedef enum
{
	VSIE_FRAME_TYPE_BEACON = 0,
	VSIE_FRAME_TYPE_PROBEREQ,
	VSIE_FRAME_TYPE_PROBERSP,
	VSIE_FRAME_TYPE_MAX,
} vsie_frame_type_e;

typedef enum
{
	PRR_CMD_REQ_CFG = 0,
	PRR_CMD_RESP_CFG = 128,
}prr_cmd_type_e;

typedef enum
{
	PRR_TYPE_CMD = 1,
	PRR_TYPE_DEVID,
	PRR_TYPE_MAC,
	PRR_TYPE_CHN,
	PRR_TYPE_SSID,
	PRR_TYPE_PWD,
	PRR_TYPE_SECM,
}prr_tlv_type_e;

typedef enum
{
	WPA_PSK_AES = 0,
	WPA_PSK_TKIP,
	WPA2_PSK_AES,
	WPA2_PSK_TKIP,
}prr_wifi_auth_sec_e;

typedef struct
{
	unsigned char chn;
	char ssid[32 + 1];
	char pwd[64 + 1];
	unsigned short secm;
}prr_wifi_cfg_t;

int prr_check_sta_present(unsigned char mac[6]);
int prr_wifi_get_cfg(prr_wifi_cfg_t *pwc);
int prr_wifi_cfg_to_buf(unsigned char oui[3], unsigned char mac[6], prr_wifi_cfg_t *pwc, 
						unsigned char *buf, unsigned int bufsz);
int prr_link_set(int status, char oui[3]);
int prr_dev_get(unsigned int idx, unsigned char mac[6], char devId[16], 
				unsigned char vsieBuf[], int vsieSz);
int  prr_tx_data(int type, unsigned char vsieBuf[], int vsieSz);
int  prr_tx_done(int type);
int prr_tx_cfg(unsigned char mac[6]);

char *mac2str(char *p);

#endif
