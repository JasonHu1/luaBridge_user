/**
 * @file gw_data_protocol.h
 * @author diao(HongWangZheng) (diao.hong@tuya.com)
 * @brief 虚拟设备protocol version 2.0 接入
 * @version 0.1
 * @date 2021-04-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef __GW_DATA_PROTOCOL__
#define __GW_DATA_PROTOCOL__

#include "tuya_error_code.h"
#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

OPERATE_RET tuya_pack_special_protocol_data(IN CONST DP_CMD_TYPE_E cmd, IN CONST CHAR_T *pv, IN CONST CHAR_T *data,\
                                        IN CONST UINT_T pro, IN CONST CHAR_T *id, IN CONST BYTE_T *key,\
                                        OUT CHAR_T **out, OUT UINT_T *out_len);

OPERATE_RET tuya_parse_special_protocol_data(IN CONST DP_CMD_TYPE_E cmd, IN CONST CHAR_T *pv, IN CONST BYTE_T *data, \
                                         IN CONST INT_T len, IN CONST CHAR_T *key, OUT CHAR_T **out_data);

#ifdef __cplusplus
} // extern "C"
#endif


#endif  // __GW_DATA_PROTOCOL__
