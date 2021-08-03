/**
 * @file lpc_init.h
 * @author beihe(JiangBo) (beihe.jiang@tuya.com)
 * @brief 局域网协议客户端模块初始化
 * @version 0.1
 * @date 2021-05-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __LPC_INIT__
#define __LPC_INIT__

#include "tuya_error_code.h"

#pragma pack(1)

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 初始化
 * 
 * @return OPERATE_RET 错误码
 */
OPERATE_RET tuya_lan_pro_client_init();

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __LPC_INIT__