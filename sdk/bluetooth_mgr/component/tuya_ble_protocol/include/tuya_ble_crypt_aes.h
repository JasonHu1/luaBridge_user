#ifndef __TUYA_BLE_ENCRYPT_AES_H__
#define __TUYA_BLE_ENCRYPT_AES_H__


#ifdef __cplusplus
extern "C" {
#endif

int ty_crypt_aes_encrypt(unsigned char* pinput, int len, unsigned char* poutput, int* polen,
						 unsigned char* pkey, unsigned char* piv);


int ty_crypt_aes_decrypt(unsigned char* pinput, int len, unsigned char* poutput, int* polen,
						 unsigned char* pkey, unsigned char* piv);


int ty_crypt_aes_cbc128_enc_nopadding(unsigned char* pinput, int len, unsigned char* poutput, int* polen,
						 				unsigned char* pkey, unsigned char* piv);


int ty_crypt_aes_cbc128_dec_nopadding(unsigned char* pinput, int len, unsigned char* poutput, int* polen,
						 				unsigned char* pkey, unsigned char* piv);


int ty_crypt_aes_md5_encrypt(unsigned char* pinput, int len, unsigned char* poutput, int* polen,
						 unsigned char* pkey, unsigned char* piv);


int ty_crypt_aes_md5_decrypt(unsigned char* pinput, int len, unsigned char* poutput, int* polen,
						 unsigned char* pkey, unsigned char* piv);


#ifdef __cplusplus
}
#endif

#endif  /*_TUYA_BPI_ECDH_H*/
