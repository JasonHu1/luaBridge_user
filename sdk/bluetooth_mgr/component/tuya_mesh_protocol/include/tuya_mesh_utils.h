/*
 * tuya_mesh_utils.h
 *
 *  Created on: 2018-11-15
 *      Author: echo
 */
#ifndef	_TUYA_MESH_UTILS_H
#define _TUYA_MESH_UTILS_H

#include "tuya_mesh_type.h"

#define CNT_OF(_x)			(sizeof(_x)/sizeof(_x[0]))

#define CEIL(n,b)  			((n/b) + ((n%b)?1:0))

uint16_t tuya_utils_bin_to_hexstring(uint8_t *phex_string, uint8_t *pbin, uint16_t pbin_len);

void tuya_utils_big_byte_array_to_int(uint8_t *srcArray,uint32_t *desBeData);

void tuya_utils_little_byte_array_to_int(uint8_t *srcArray,uint32_t *desLeData);

void tuya_utils_int_to_big_byte_array(uint8_t *desArray,uint32_t *srcData);

void tuya_utils_int_to_little_byte_array(uint8_t *desArray,uint32_t *srcData);

void tuya_utils_hsv_to_hsl(double h, double s, double v, double* hh, double* ss, double *ll);

void tuya_utils_hsl_to_hsv(double hh, double ss, double ll, double* h, double* s, double *v);

uint16_t tuya_utils_num_range_convert(uint32_t in_num, uint32_t INPUT_MAX, uint32_t INPUT_MIN, uint32_t OUTPUT_MAX, uint32_t OUTPUT_MIN);

int8_t opSceneDataCompress(uint8_t* input_str, uint16_t input_buf_len, uint8_t* output_buf, uint8_t*output_buf_len);

int8_t opSceneDataDecompress(uint8_t* input_buf, uint16_t input_buf_len, uint8_t* output_str, uint8_t* output_buf_len);

int8_t opMusicDataCompress(uint8_t* input_str, uint16_t input_buf_len, uint8_t* output_buf, uint8_t*output_buf_len);


#endif /* _TUYA_MESH_UTILS_H */
