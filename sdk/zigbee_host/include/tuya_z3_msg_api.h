/***********************************************************
*  File: tuya_z3_msg_api.h
*  Author: hxh
*  Date: 201805
***********************************************************/

#ifndef __TUYA_Z3_MSG_API_H
#define __TUYA_Z3_MSG_API_H

#include <stdio.h>
#include <sys/types.h>
#ifndef CONFIG_PLATFORM_8195A
#include <sys/ipc.h>
#include <sys/msg.h>
#endif
#include <errno.h>
#include "tuya_cloud_types.h"

#ifdef __cplusplus
	extern "C" {
#endif


#define MSG_BUF_MAX_LEN 800
typedef struct msq_struct_s   
{    
   INT_T msgtype;    
   BYTE_T msgtext[MSG_BUF_MAX_LEN];
   ULONG_T msTime;
} msq_struct_t;

#define MSG_UDP_ENABLE//原来用消息队列，由于安卓系统api>=26才支持，移植时遇到24版本的，所以更改了

#ifdef MSG_UDP_ENABLE
//#include "uni_network.h"

OPERATE_RET _Z3MsgRecvformInit(INT_T *iSocketId, BOOL_T block, USHORT_T port);
OPERATE_RET _Z3MsgSendToInit(INT_T *iSocketId);
OPERATE_RET _Z3MsgRecvForm(msq_struct_t *msgs, INT_T iSocketId);
OPERATE_RET _Z3MsgSendTo(msq_struct_t msgs, INT_T iSocketId, USHORT_T port);

#else

int msg_create( int *msqid, char *cMsqName, int iMsqId);
void msg_del(int msqid);
int msg_send(int msqid,  msq_struct_t msgs, int msgflag);
int msg_recv(int msqid, msq_struct_t *msgs, int msgflag);
#endif
#ifdef __cplusplus
}
#endif

#endif
