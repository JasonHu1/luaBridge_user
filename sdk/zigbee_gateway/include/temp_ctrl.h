#ifndef __TEMP_CTRL_H
#define __TEMP_CTRL_H

#ifdef __cplusplus
    extern "C" {
#endif

#include "tuya_z3.h"

//temp ctrl dpid
#define DP_ID_TC_POWER              0x01
#define DP_ID_TC_TEMP_SET           0x02
#define DP_ID_TC_CTRL_MODE          0x03
#define DP_ID_TC_SENSOR_ERROR       0x04
#define DP_ID_TC_ROOM_TEMP          0x05
#define DP_ID_TC_ADAPTIVE_FUNC      0x06
#define DP_ID_TC_WIN_SWITCH         0x07 //Window Switch
#define DP_ID_TC_FLOOR_TEMP         0x08
#define DP_ID_TC_FLOOR_LIMIT        0x09
#define DP_ID_TC_WIN_SENSE_TIME     0x0a    
#define DP_ID_TC_LOCK               0x0b
#define DP_ID_TC_HOLIDAY_DAYS_SET   0x0c
#define DP_ID_TC_HOLIDAY_TEMP_SET   0x0d   
#define DP_ID_TC_SENSOR_SELECTION   0x0e   
#define DP_ID_TC_ROOM_TEMP_CAL      0x0f //Room Temp Calibration   
#define DP_ID_TC_WIN_DROP           0x10   
#define DP_ID_TC_FLOOR_TEMP_CAL     0x11 //Floor Temp Calibration      
#define DP_ID_TC_WIN_OFF_TIME       0x12   
#define DP_ID_TC_TEMP_TOLERANCE     0x13   
#define DP_ID_TC_PROGRAM_MODE_SEL   0x14 //Program Mode Select   
#define DP_ID_TC_RESTORE            0x15   
#define DP_ID_TC_HEAT_POWER         0x16   
#define DP_ID_TC_HEAT_HOURS         0x17
#define DP_ID_TC_WEEK_PROGRAM       0x18
#define DP_ID_TC_DEVICE_STATE       0x19  
#define DP_ID_TC_FROST_SWITCH       0x1a   
#define DP_ID_TC_FROST_TEMP         0x1b   
#define DP_ID_TC_SWITCH_DELAY       0x1c   
#define DP_ID_TC_BRIGHTNESS         0x1d   
#define DP_ID_TC_INQUIRE            0x1e   

#define TC_DATA_HEAD_LEN            2 //dpid and data length
#define TC_DATA_LEN_MIN             3 
#define TC_WEEK_PROGRAM_DATA_LEN    6
#define TC_INQUIRE_DATA_LEN         1
#define REX_SELF_DEFINE_MAX_LEN     256 //rex self define data max len

typedef struct {
    BYTE_T dpid;
    BYTE_T len;
    CHAR_T data[256];
    
}PACKED TEMP_CTRL_DATA_S;       //temp ctrl data

typedef struct {
    CONST BYTE_T dpid;
    CONST BYTE_T len;
    CONST DP_PROP_TP_E type;
    
}PACKED TEMP_CTRL_DPID_ITEM_S;



UCHAR_T get_tc_data(IN CONST TY_OBJ_DP_S *obj_dp, OUT TEMP_CTRL_DATA_S *tc);

OPERATE_RET parse_tc_data(IN CONST TEMP_CTRL_DATA_S *tc, IN UINT16_T length, OUT TY_OBJ_DP_S *dp_data);
OPERATE_RET HaHermostat_jh_get_cur_status(IN TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET HaHermostat_down_jh_handle(IN UINT_T  uddd, IN TY_CMD_U *dp, IN CHAR_T type, IN TuYaApsFrame *sTyApsFrameTmp);
VOID HaHermostat_up_jh_handle(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer);


#ifdef __cplusplus
}
#endif

#endif

