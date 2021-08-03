#ifndef __TUYA_GW_TRD_PARTY_CFG_H__
#define __TUYA_GW_TRD_PARTY_CFG_H__

#include "tuya_gw_config.h"

#if defined (TUYA_GW_THIRD_PARTY_SUPPORT) && (1 == TUYA_GW_THIRD_PARTY_SUPPORT)

#ifdef __cplusplus
    extern "C" {
#endif

//3rd-party define
typedef enum {
    TY_TRD_PARTY_TYPE_NONE = 0x00,
    TY_TRD_PARTY_TYPE_SIEMENS = 0x01,
    TY_TRD_PARTY_TYPE_DANFOSS = 0x02,
	TY_TRD_PARTY_TYPE_SCHNEIDER = 0x03,
    TY_TRD_PARTY_TYPE_MAX,
} TY_TRD_PARTY_TYPE;

#define TY_TRD_PARTY_NAME_SIEMENS    "Siemens"

#define TY_TRD_PARTY_NAME_DANFOSS    "Danfoss"

#define TY_TRD_PARTY_NAME_SCHNEIDER    "Schneider Electric"


#ifdef __cplusplus
}
#endif
#endif //TUYA_GW_THIRD_PARTY_SUPPORT
#endif // __TUYA_GW_TRD_PARTY_CFG_H__
