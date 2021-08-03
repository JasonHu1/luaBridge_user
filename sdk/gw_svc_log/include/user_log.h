#ifndef __USER_LOG_H
#define __USER_LOG_H

#ifdef __cplusplus
    extern "C" {
#endif
#include "tuya_cloud_types.h"

VOID getAppLogFile(OUT CHAR_T *path, IN CONST INT_T len);
VOID recordAppStartTime(VOID);
VOID recordSystemStartTime(VOID);

#ifdef __cplusplus
}
#endif
#endif // __USER_LOG_H
