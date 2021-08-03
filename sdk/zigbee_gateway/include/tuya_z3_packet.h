/**
* @file tuya_z3_packet.h
* @author jm.yao@tuya.com
* @brief Zigbee subcontracting transmission
*
* @copyright Copyright (c) tuya.inc 2020
*
*/

#ifndef __TUYA_Z3_PACKET_H
#define __TUYA_Z3_PACKET_H

#include <string.h>
#include <unistd.h>
#include "tuya_cloud_types.h"
#include "tuya_z3_zigbee_bash.h"

#ifdef __cplusplus
    extern "C" {
#endif

/***********************************************************
*************************micro define***********************
***********************************************************/

#define FILE_URL_LEN                                128
#define ZCL_PAYLOAD_LEN_MAX                         64
#define TUYA_ZCL_LARGE_FILE_TRANSFER_CLUSTER_ID     0xED00

/***********************************************************
*************************variable define********************
***********************************************************/


/***********************************************************
*************************function define********************
***********************************************************/

typedef OPERATE_RET (*GET_PERCENT_CB)(IN CONST CHAR_T *addr, OUT USHORT_T file_id, OUT INT_T percent);

typedef struct {
    BOOL_T              isFile;
    CHAR_T              f_url[FILE_URL_LEN+1];
    UCHAR_T            *p_msg;
    USHORT_T            p_len;
} tuya_packet_start_msg_t;

/***********************************************************
*  Function: tuya_z3_packet_init
*  Desc:     init big data transmission module
*  Param:    void
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_z3_packet_init(void);

/***********************************************************
*  Function: tuya_z3_packetStartNotify
*  Desc:     start send subpackage
*  Param:    sHeader: TuYaApsFrameHeader
*  Param:    msg: sub packet data
*  Param:    file_id: sequence number
*  Param:    get_percent_cb: process callback
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_z3_packetStartNotify(IN CONST TuYaApsFrameHeader *sHeader, IN CONST tuya_packet_start_msg_t *msg, \
                                                                   OUT USHORT_T *file_id, IN CONST GET_PERCENT_CB get_percent_cb);

/***********************************************************
*  Function: tuya_z3_packetReportProcess
*  Desc:     receive subpackage and combined into a complete frame
*  Param:    sHeader: TuYaApsFrameHeader
*  Param:    p_buf: data cache
*  Param:    p_len: data length
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_z3_packetReportProcess(IN CONST TuYaApsFrameHeader *sHeader, IN CONST UCHAR_T *p_buf, USHORT_T p_len);

/***********************************************************
*  Function: tuya_z3_packetStopEnd
*  Desc:     stop subpackage send
*  Param:    addr: sub device mac
*  Param:    file_id: sequence number
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_z3_packetStopEnd(IN CONST CHAR_T *addr, IN USHORT_T file_id);

#ifdef __cplusplus
}
#endif

#endif

