/**
 * @file home_ctrl_demo_server.h
 * @author diao(HongWangZheng)(diao.hong@tuya.com)
 * @brief 中控sdk测试demo服务端模块
 * @version 0.1
 * @date 2021-06-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __HOME_CTRL_DEMO_SERVER__
#define __HOME_CTRL_DEMO_SERVER__

#include "ty_cJSON.h"
#include "tuya_cloud_types.h"
#include "tuya_cloud_error_code.h"
#include "tuya_iot_com_api.h"
#include "tuya_ctrl_base.h"

/**
 * @brief Create a demo server thread object
 * 
 * @param thrid 返回线程id
 * @return OPERATE_RET 
 */

OPERATE_RET create_demo_server_thread(OUT pthread_t *thrid);

#endif  //__HOME_CTRL_DEMO_SERVER__