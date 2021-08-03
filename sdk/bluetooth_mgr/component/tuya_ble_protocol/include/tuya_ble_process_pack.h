#ifndef __TUYA_BLE_PROCESS_PACK_H__
#define __TUYA_BLE_PROCESS_PACK_H__

#ifdef __cplusplus
extern "C" {
#endif

// frame total len
typedef unsigned int frame_total_t;

// frame subpackage num
typedef unsigned int frame_subpkg_num_t;

// frame sequence
typedef unsigned char frame_seq_t;

// frame subpackage len
typedef unsigned char frame_subpkg_len_t;

// frame package description
typedef unsigned char frm_pkg_desc_t;
typedef int mtp_ret;

#define TUYA_LITTLE_ENDIAN

// 短整型大小端互换

#ifdef TUYA_LITTLE_ENDIAN
#define BigLittleSwap16(A)  ((((unsigned short)(A) & 0xff00) >> 8) | \
                            (((unsigned short)(A) & 0x00ff) << 8))  

 // 长整型大小端互换
#define BigLittleSwap32(A)  ((((unsigned int)(A) & 0xff000000) >> 24) | \
                            (((unsigned int)(A) & 0x00ff0000) >> 8)    | \
                            (((unsigned int)(A) & 0x0000ff00) << 8)    | \
                            (((unsigned int)(A) & 0x000000ff) << 24))
#endif

#define SNGL_PKG_TRSFR_LMT 	20 // single package transfer limit

//#define FRM_TYPE_OFFSET (0x0f << 4)
#define FRM_VERSION_OFFSET 	(0x0f << 4)
#define FRM_SEQ_OFFSET  	(0x0f << 0)

#define FRAME_SEQ_LMT 		16

#define FRM_PKG_INIT 		0   // frame package init
#define FRM_PKG_FIRST 		1  // frame package first
#define FRM_PKG_MIDDLE 		2 // frame package middle
#define FRM_PKG_END 		3    // frame package end

// mutil tsf ret code
#define MTP_OK  				0
#define MTP_INVALID_PARAM 		1
#define MTP_COM_ERROR 			2
#define MTP_TRSMITR_CONTINUE 	3
#define MTP_TRSMITR_ERROR 		4
#define MTP_MALLOC_ERR 			5

#pragma pack(1)
// frame transmitter process
typedef struct {
    frame_total_t  		total;         //4字节，数据总长度，不包括包头
   // frame_type_t   type;        //1字节
    unsigned char  		version;       //1字节,协议主版本号
    frame_seq_t    		seq;           //1字节，
    frm_pkg_desc_t 		pkg_desc;      //1字节 当前分包帧类型（init/first/middle/end）
    frame_subpkg_num_t 	subpkg_num;//4字节，当前分包编号
    unsigned int 		pkg_trsmitr_cnt; //  package process count  已发送出去的字节数
    frame_subpkg_len_t 	subpkg_len;//1字节，当前分包中的数据长度（）
    unsigned char 		subpkg[SNGL_PKG_TRSFR_LMT];
} ty_frm_trsmitr_proc_s;


typedef struct ty_blep_header_ {
	int 	sn;
	int 	ack_sn;
	short 	fcode;
	short 	len;
} ty_blep_header_s;
#pragma pack()

int ty_blep_header_pack(ty_blep_header_s* phdr, int sn, int ack_sn, short fcode, short len);

int ty_blep_header_unpack(ty_blep_header_s* phdr, int* psn, int* pack_sn, short* pfcode, short* plen);

int ty_blep_bind_info_pack(      char *out, int *out_len,unsigned char *device_id,unsigned char *login_id,unsigned char *virtual_id);

int ty_blep_pack_data(ty_blep_header_s* phdr, char* pout, int* polen, char* pin, int ilen);

int ty_blep_unpack_data(ty_blep_header_s* phdr, char* pout, int* polen, char* pin, int ilen);

int ty_blep_unpack_session_data(ty_blep_header_s* phdr, char* pout, int* polen, char* pin, int ilen);

mtp_ret ty_trsmitr_send_pkg_encode(ty_frm_trsmitr_proc_s *frm_trsmitr, unsigned char version, unsigned char *buf, unsigned int len);

mtp_ret ty_trsmitr_recv_pkg_decode(ty_frm_trsmitr_proc_s *frm_trsmitr, unsigned char *raw_data, unsigned char raw_data_len);


#ifdef __cplusplus
}
#endif

#endif  /*_TUYA_BPI_ECDH_H*/
