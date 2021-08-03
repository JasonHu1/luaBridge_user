/***********************************************************
*  File: tuya_z3_uf_file.h 
*  Author: lql
*  Date: 20181213
***********************************************************/
#ifndef __TUYA_Z3_UF_FILE_H
#define __TUYA_Z3_UF_FILE_H
#include "tuya_cloud_error_code.h"
#include "tuya_cloud_types.h"


#ifdef __cplusplus
    extern "C" {
#endif

#ifdef  __UF_FILE_GLOBALS
    #define __UF_FILE_EXT
#else
    #define __UF_FILE_EXT extern
#endif

/***********************************************************
*************************micro define***********************
***********************************************************/
#define PARTITION_0 0 
#define PARTITION_1 1
typedef unsigned char file_bit_t;
#define FILE_DEVICE 0
#define FILE_IAS    1
#define FILE_GROUP  2

__UF_FILE_EXT \
UINT_T getFileFlag(VOID);

/***********************************************************
*  Function: setPartToFile
*  Input: part
*  Output: none
*  Return: UINT_T
***********************************************************/
__UF_FILE_EXT \
UINT_T setPartToFile(IN CONST UINT_T part,IN CONST file_bit_t bit);

__UF_FILE_EXT \
VOID devFileInit(VOID);

#ifdef __cplusplus
}
#endif
#endif
