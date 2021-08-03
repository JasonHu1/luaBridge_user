#ifndef __ZIGBEE_DATA_QUERY_H
#define __ZIGBEE_DATA_QUERY_H

#ifdef __cplusplus
	extern "C" {
#endif


#include "tuya_z3_base.h"


#ifdef  __GW_ADAPTER_GLOBALS
    #define __GW_ADAPTER_EXT
#else
    #define __GW_ADAPTER_EXT extern
#endif

#ifndef PACKED
#define PACKED __attribute__((packed))
#endif


OPERATE_RET tuya_z3_DevDataDown_HaOnOfLight(IN UINT_T  uddd, IN TY_CMD_U *dp, IN CHAR_T type, IN TuYaApsFrame *sTyApsFrameTmp);


#ifdef __cplusplus
}
#endif

#endif

