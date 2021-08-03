#ifndef TUYA_RELIABLE_TRD_DEV_H
#define TUYA_RELIABLE_TRD_DEV_H

#include "tuya_reliable.h"
#ifdef TUYA_RELIABLE_TRD_DEV_SUPPORT

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef enum {
    TUYA_TRD_DEV_TYPE_ERR_COM                = -1,
    TUYA_TRD_DEV_TYPE_ERR_FATHER_NOT_EXIST   = -2,
    TUYA_TRD_DEV_TYPE_ERR_SON_NOT_EXIST      = -3,
    TUYA_TRD_DEV_TYPE_ERR_SON_ADDR_LEN_INVAL = -4,

    TUYA_TRD_DEV_TYPE_NORMAL = 0,
    TUYA_TRD_DEV_TYPE1,
    TUYA_TRD_DEV_TYPE_MAX

} TUYA_TRD_DEV_TPYE_E;
#define TUYA_TRD_DEV_CID_SEPARATOR_STR "-v-"
#define TUYA_TRD_DEV_CID_SEPARATOR_STR_LEN 3
#define TUYA_TRD_DEV_ADDR_MAX_LEN 3
#define TUYA_TRD_DEV_TPYE_LEN 1
#define TUYA_TRD_DEV_TYPE_START (RELIABLE_HEAD_LEN)
#define TUYA_TRD_DEV_ADDR_START (RELIABLE_HEAD_LEN + TUYA_TRD_DEV_TPYE_LEN)

#define TUYA_TRD_DEV_TYPE1_MODEID_LEN 6
#define TUYA_TRD_DEV_TYPE1_PID_LEN 8
#define TUYA_TRD_DEV_TYPE1_ADDR_LEN 2
#define TUYA_TRD_DEV_TYPE1_HEAD_LEN 3
#define TUYA_TRD_DEV_TYPE1_ADDR_SRTIN_LEN 4
#define TUYA_TRD_DEV_TYPE1_CID_LEN \
    (TY_ZIGBEE_EUI_STR_LEN + TUYA_TRD_DEV_CID_SEPARATOR_STR_LEN + TUYA_TRD_DEV_TYPE1_ADDR_SRTIN_LEN)

#define GET_FATHER_CID_FROM_TRD_DEV_CID_STRIN(_TrdDevCidStr, _FatherDevCidStr) \
    do {                                                                       \
        strncpy(_FatherDevCidStr, _TrdDevCidStr, TY_ZIGBEE_EUI_STR_LEN);       \
    } while (0);

#define TRD_DEV_ADDR_STRIN_TO_BTYE_TYPE1(_TrdDevCidStr, _TrdDevCidAddr)                                          \
    do {                                                                                                         \
        if (strlen(_TrdDevCidStr) == (TUYA_TRD_DEV_TYPE1_CID_LEN)) {                                             \
            INT_T iTmp[2] = { 0 };                                                                               \
            sscanf(((_TrdDevCidStr) + (TY_ZIGBEE_EUI_STR_LEN + TUYA_TRD_DEV_CID_SEPARATOR_STR_LEN)), "%02x%02x", \
                   &iTmp[0], &iTmp[1]);                                                                          \
            (_TrdDevCidAddr)[0] = iTmp[0] & 0xFF;                                                                \
            (_TrdDevCidAddr)[1] = iTmp[1] & 0xFF;                                                                \
        }                                                                                                        \
    } while (0)

#define TRD_DEV_ADDR_BYTE_TO_STRIN_TYPE1(_TrdDevCidStr, _FatherDevCidStr, _TrdDevCidAddr)                 \
    do {                                                                                                  \
        snprintf(_TrdDevCidStr, (TUYA_TRD_DEV_TYPE1_CID_LEN + 1), "%s%s%02x%02x", _FatherDevCidStr,       \
                 TUYA_TRD_DEV_CID_SEPARATOR_STR, (_TrdDevCidAddr)[0] & 0xFF, (_TrdDevCidAddr)[1] & 0xFF); \
    } while (0)

typedef struct {
    UINT8_T type;
    UINT8_T addr_len;
    UINT8_T addr[TUYA_TRD_DEV_ADDR_MAX_LEN];

} PACKED RELIABLE_TRD_DEV_ADDR_S;

OPERATE_RET tuya_reliable_trd_dev_add_req(IN CONST CHAR_T* father_dev_id, IN CONST RELIABLE_TRD_DEV_ADDR_S* trd_dev);
OPERATE_RET tuya_reliable_trd_dev_add_rsp(IN CONST DEV_DESC_IF_S* father_dev_if, IN CONST UCHAR_T* rsp_data,
                                          IN CONST INT_T rsp_len);
OPERATE_RET tuya_reliable_trd_dev_add_conf(IN CONST CHAR_T* trd_dev_id, IN CONST BOOL_T bind_result);

OPERATE_RET tuya_reliable_trd_dev_del_req(IN CONST CHAR_T* trd_dev_id);
OPERATE_RET tuya_reliable_trd_dev_del_rsp(IN CONST DEV_DESC_IF_S* father_dev_if, IN CONST UCHAR_T* rsp_data,
                                          IN CONST INT_T rsp_len);

OPERATE_RET tuya_reliable_trd_dev_data_down(IN CONST CHAR_T* trd_dev_id, IN CONST UCHAR_T* msg, IN CONST UINT_T len);
OPERATE_RET tuya_reliable_trd_dev_data_sync(IN CONST CHAR_T* trd_dev_id);

OPERATE_RET tuya_reliable_trd_dev_clean_list(IN CONST CHAR_T* father_dev_id);

OPERATE_RET tuya_reliable_trd_dev_bind(IN CONST CHAR_T* trd_dev_id, IN CONST OPERATE_RET op_ret);
OPERATE_RET tuya_reliable_trd_dev_unbind(IN CONST CHAR_T* trd_dev_id);

VOID tuya_reliable_trd_dev_online_stat_update(IN CONST CHAR_T* trd_dev_id);

///
/// \brief get_tuya_trd_dev_type
/// \param trd_dev_id : son device cid
/// \param is_check_trd_dev : is need check son device
/// \param trd_dev : if need check son device, need use
/// \return son device type
///
TUYA_TRD_DEV_TPYE_E get_tuya_trd_dev_type(IN CONST CHAR_T* trd_dev_id, IN CONST BOOL_T is_check_trd_dev,
                                          OUT RELIABLE_TRD_DEV_ADDR_S* trd_dev);

///
/// \brief build_tuya_trd_dev_id_form_rpt_data
/// \param father_dev_id
/// \param rpt_data
/// \param rpt_data_len
/// \param trd_dev_id_buf
/// \param trd_dev_id_buf_len
/// \param head_len
/// \return
///
OPERATE_RET build_tuya_trd_dev_id_form_rpt_data(IN CONST CHAR_T* father_dev_id, IN CONST UCHAR_T* rpt_data,
                                                IN CONST INT_T rpt_data_len, OUT CHAR_T* trd_dev_id_buf,
                                                IN INT_T trd_dev_id_buf_len, OUT INT_T* head_len);

OPERATE_RET tuya_reliable_trd_dev_init(VOID);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // TUYA_RELIABLE_TRD_DEV_SUPPORT
#endif // TUYA_RELIABLE_TRD_DEV_H
