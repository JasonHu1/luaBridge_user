#ifndef __TUYA_GW_TRD_GW_PARTY_CMD_SCHNEIDER_H__
#define __TUYA_GW_TRD_GW_PARTY_CMD_SCHNEIDER_H__
#include "tuya_gw_trd_party_cfg.h"
#include "tuya_z3_base.h"
#include "tuya_gw_trd_party_cluster_schneider.h"
#include "tuya_z3.h"

#if defined (TUYA_GW_THIRD_PARTY_SCHNEIDER_SUPPORT) && (1 == TUYA_GW_THIRD_PARTY_SCHNEIDER_SUPPORT)

//common
OPERATE_RET schneider_common_global_attr_write(IN USHORT_T cluster, IN USHORT_T attr_id, BYTE_T* val_buf, BYTE_T buf_len, BYTE_T destEp, TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET schneider_common_attt_write(IN USHORT_T cluster, IN USHORT_T attr_id, BYTE_T* val_buf, BYTE_T buf_len, BYTE_T destEp, TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET schneider_common_attt_read(IN USHORT_T clusterId, IN UCHAR_T destEndpoint, IN USHORT_T *AttrBuf,
                                        IN UCHAR_T AttrNum, IN TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET schneider_common_cmd_indicator_ctrl(IN USHORT_T attr_id, IN BYTE_T value, IN BYTE_T destEp, IN TuYaApsFrame *sTyApsFrameTmp);
VOID schneider_common_cmd_indicator_rpt(IN TuYaApsFrame *sTyApsFrameTmp, IN UCHAR_T *buffer, IN BYTE_T level_dp, IN BYTE_T color_dp, IN BYTE_T mode_dp, OUT TY_OBJ_DP_S* dplist, OUT BYTE_T *offset);
OPERATE_RET schneider_common_cmd_get_battery(IN UINT_T uddd, IN TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET schneider_common_cmd_get_version(IN UINT_T uddd, IN TuYaApsFrame *sTyApsFrameTmp);
VOID schneider_common_cmd_basic_process(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer);

OPERATE_RET schneider_DevDataGet_HaOnOfLight(IN UINT_T uddd, IN TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET schneider_DevDataDown_HaOnOfLight(IN UINT_T uddd, IN TY_CMD_U *dp, IN CHAR_T type, IN TuYaApsFrame *sTyApsFrameTmp);
VOID schneider_uploadDevData_HaOnofLight(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer);

OPERATE_RET schneider_DevDataDown_HaIasZone(IN UINT_T uddd, IN TY_CMD_U *dp, IN CHAR_T type, IN TuYaApsFrame *sTyApsFrameTmp);
VOID schneider_uploadDevData_HaIasZone(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer);

VOID schneider_uploadDevData_HaTempSensor(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer);

OPERATE_RET schneider_DevDataGet_HaCurtainSwitch(IN UINT_T uddd, IN TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET schneider_DevDataDown_HaCurtainSwitch(IN UINT_T uddd, IN TY_CMD_U *dp, IN CHAR_T type, IN TuYaApsFrame *sTyApsFrameTmp);
VOID schneider_uploadDevData_HaCurtainSwitch(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer);

OPERATE_RET schneider_DevDataGet_HaDimmerSwitch(IN UINT_T uddd, IN TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET schneider_DevDataDown_HaDimmerSwitch(IN UINT_T uddd, IN TY_CMD_U *dp, IN CHAR_T type, IN TuYaApsFrame *sTyApsFrameTmp);
VOID schneider_uploadDevData_HaDimmerSwitch(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer);

OPERATE_RET schneider_DevDataDown_HaRemoteControl(IN UINT_T uddd, IN TY_CMD_U *dp, IN CHAR_T type, IN TuYaApsFrame *sTyApsFrameTmp);
VOID schneider_uploadDevData_HaRemoteControl(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer);
#endif //TUYA_GW_THIRD_PARTY_SCHNEIDER_SUPPORT
#endif // __TUYA_GW_TRD_GW_PARTY_CMD_SCHNEIDER_H__
