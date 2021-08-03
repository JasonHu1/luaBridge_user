#ifndef __TUYA_Z3_UPGRADE_H
#define __TUYA_Z3_UPGRADE_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "tuya_z3.h"

typedef VOID (*GW_UP_NOTIFY_CB)(IN CONST CHAR_T *img);
VOID tuya_user_z3_gw_ug_inform(IN CONST FW_UG_S *fw, IN CONST CHAR_T *gw_ver, GW_UP_NOTIFY_CB cb);

VOID tuya_z3_gw_ug_inform(IN CONST FW_UG_S *fw, IN CONST CHAR_T *gw_ver);
OPERATE_RET tuya_z3_dev_ug_inform(IN CONST CHAR_T *dev_id,IN CONST FW_UG_S *fw);

#ifdef __cplusplus
}
#endif

#endif

