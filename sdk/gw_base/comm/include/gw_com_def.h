#ifndef __GW_COM_DEF_H__
#define __GW_COM_DEF_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define RAW_DATA_TYPE 0
#define OBJ_DATA_TYPE 1

typedef union {
    TY_RECV_OBJ_DP_S *obj_dp;
    TY_RECV_RAW_DP_S *raw_dp;
}TY_CMD_U;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

