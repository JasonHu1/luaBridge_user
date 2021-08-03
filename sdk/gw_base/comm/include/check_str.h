/***********************************************************
*  File: check_str.h 
*  Author: yf
*  Date: 20190501
***********************************************************/
#ifndef _CHECK_STR_H
#define _CHECK_STR_H

#include "tuya_cloud_types.h"

#ifdef __cplusplus
	extern "C" {
#endif

#ifdef  __CHECK_STR_GLOBALS
	#define __CHECK_STR_EXT
#else
	#define __CHECK_STR_EXT extern
#endif

/***********************************************************
*************************micro define***********************
***********************************************************/
/*data type bit define*/
#define TYPE_BIT_NUMBER 0 
#define TYPE_BIT_LOWER_CASE_LETTERS 1
#define TYPE_BIT_UPPER_CASE_LETTERS 2

/*data type define*/
#define TYPE_NUMBER (1 << TYPE_BIT_NUMBER)
#define TYPE_LOWER_CASE_LETTERS (1 << TYPE_BIT_LOWER_CASE_LETTERS)
#define TYPE_UPPER_CASE_LETTERS (1 << TYPE_BIT_UPPER_CASE_LETTERS)

/*return value*/
#define CHECK_OK 0 	
#define CHECK_COMMON_ERR -1 
#define CHECK_PARAM_ERR -2

/***********************************************************
*************************variable define********************
***********************************************************/

/***********************************************************
*************************function define********************
***********************************************************/

/***********************************************************
*  Function: check_str_data_type 
*  Describe: Check that the string contains only the specified data type
*  Input: 
   1 value 
     The string to be checked
   2 contain_type
     32bits
     bit 0: number
     bit 1: lower case letters
     bit 2: upper case letters
     bit 3-31: reserved
*  Output: 
*  Return: OPERATE_RET
*  Date: 20190501
***********************************************************/
__CHECK_STR_EXT \
INT_T check_str_data_type(CHAR_T *value, UINT_T contain_type);


#ifdef __cplusplus
}
#endif
#endif



