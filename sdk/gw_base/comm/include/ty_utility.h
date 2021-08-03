#ifndef __TY_UTILITY_H__
#define __TY_UTILITY_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if OPERATING_SYSTEM == SYSTEM_LINUX

#include <pthread.h>


typedef void* (*ty_thread_process)(void *pArg);

int creat_thread_and_start(pthread_t *thrid, ty_thread_process thr_process);
int creat_thread_priority_and_start(pthread_t *thrid, ty_thread_process thr_process,int priority);
int cancel_thread(pthread_t thrid);
int linux_exec_cmd(const char *pCmd, char cmdOutput[], int cmdOutMaxLen);
int common_popen_return_result(const char *pCmd, char *result, int result_len);
int common_popen(const char *pCmd);

#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif


