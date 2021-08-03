#ifndef __SVC_IMG_COMMON_H__
#define __SVC_IMG_COMMON_H__


#ifdef __cplusplus
extern "C" {
#endif

#define MD5_LEN_MAX           32 
#define ID_NAME_MAX_LEN       32
#define PATH_MAX_LEN          (128+ID_NAME_MAX_LEN)
#define FILE_PATH_MAX_LEN     (PATH_MAX_LEN+MD5_LEN_MAX+10)
#define DEV_IMG_FORMAT_STR ".png"

typedef struct {
    CHAR_T    *img_url;
    CHAR_T    *img_url_path;
}TUYA_IMG_INFO_S;

typedef OPERATE_RET (*TY_IMG_ID_RESULT_CB)(OUT TUYA_IMG_INFO_S *p_list, OUT UINT_T cnt);

typedef OPERATE_RET (*HTTP_GET_DEV_DATA_CB)(IN PVOID_T priv_data,IN CONST BYTE_T *data,IN CONST UINT_T len);

typedef struct {
    CHAR_T          *p_img_url;
}TUYA_IMG_INFO_PARM_S;

typedef struct {
    CHAR_T          *p_path_url;
}TUYA_IMG_PTAH_INFO_S;

typedef enum {
    NOT_NEED_UPDATE_STA = 0,
    NEED_UPDATE_STA,
    OVER_UPDATE_STA
}TUYA_URL_STA_S;

typedef struct {
    TUYA_IMG_INFO_PARM_S   *p_url;
    TUYA_IMG_PTAH_INFO_S   *p_path;
    TUYA_URL_STA_S         *p_sta;
    UINT_T                 url_cnt;
    CHAR_T                 id_name[ID_NAME_MAX_LEN+1];
    CHAR_T                 path[PATH_MAX_LEN+1];
    UINT_T                 sucess_cnt;
    TY_IMG_ID_RESULT_CB    id_img_cb;
}TUYA_IMG_INFO_MSG_S;

typedef struct {
    TUYA_IMG_INFO_MSG_S *p_msg;
    UINT_T               now_cnt;
}TUYA_IMG_HTTP_MSG_S;

typedef struct
{
    BOOL_T cfg_status;
    INT_T w;
    INT_T h;

}TUYA_GET_IMG_CFG_S;

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __COMPONENT_HELLO_H__

