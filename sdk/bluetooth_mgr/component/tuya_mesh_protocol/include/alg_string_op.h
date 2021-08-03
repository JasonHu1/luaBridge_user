/*************************************************************************
	> File Name: alg_string_op.h
	> Author: 
	> Mail: 
	> Created Time: Sat 08 Dec 2018 04:10:00 PM CST
 ************************************************************************/

#ifndef _ALG_STRING_OP_H
#define _ALG_STRING_OP_H

#include "tuya_mesh_type.h"

//extern int alg_string_op_array_sprintf(char *out, int len, int num, ...);
//

////////////////////////////////////////////////////////////////////////
//KEY-VALUE
extern uint8_t alg_string_op_get_key_value_by_key(uint16_t key_value_buf_len, uint8_t *key_value_buf,
                                uint16_t key_len, uint8_t *key,
                                uint16_t *value_len, uint8_t *value);

////////////////////////////////////////////////////////////////////////
//DP-HEX
typedef enum{
    DP_KIND_RAW = 0x00,
    DP_KIND_BOOL = 0x01,
    DP_KIND_INT = 0x02,
    DP_KIND_STRING = 0x03,
    DP_KIND_ENUM = 0x04,
    DP_KIND_BITMAP = 0x05,
}dp_kind_e;

typedef struct{
    uint8_t id;
    dp_kind_e type;
    uint8_t len;
    uint8_t *data;
}tuya_dp_s;

uint8_t alg_string_op_hexstr2hex(uint8_t *hexstr,int len,uint8_t *hex);
extern void alg_string_op_print_dp(tuya_dp_s *dp);
extern int alg_string_op_hex2dps(uint8_t *hex_array, int hex_array_len, tuya_dp_s *dps);
extern int alg_string_op_dps2hex(tuya_dp_s *dps, int dps_num, uint8_t *out);
uint8_t alg_string_op_hexstr2int(uint8_t *hexstr,uint32_t len,uint32_t *sum);
uint8_t alg_string_op_intstr2int(uint8_t *intstr,int len,int *sum);
uint8_t alg_string_op_hexarry2hexstr(uint8_t *hexstr,int len,uint8_t *hex);
uint8_t ble_gateway_hexarry2hexstr(uint8_t *hexstr,int len,uint8_t *hex);

uint8_t alg_string_op_hex2hexstr(uint8_t *hexstr,int len,uint16_t hex);

#endif
