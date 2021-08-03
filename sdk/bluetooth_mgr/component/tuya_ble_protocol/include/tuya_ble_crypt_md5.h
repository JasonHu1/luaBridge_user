#ifndef __TUYA_BLE_ENCRYPT_MD5_H__
#define __TUYA_BLE_ENCRYPT_MD5_H__


#ifdef __cplusplus
extern "C" {
#endif

int ty_crypt_md5(unsigned char *poutput, unsigned char* pinput, int len);


int ty_crypt_hmac_sha256(unsigned char* pbuffer, int dlen,
                         unsigned char* psecret, int slen,
                         unsigned char* pdigest);

#ifdef __cplusplus
}
#endif

#endif
