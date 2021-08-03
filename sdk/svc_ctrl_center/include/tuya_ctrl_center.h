#ifndef __TUYA_CTRL_CENTER_H__
#define __TUYA_CTRL_CENTER_H__

#include "ty_cJSON.h"
#include "tuya_cloud_types.h"
#include "tuya_cloud_error_code.h"
#include "tuya_iot_com_api.h"
#include "tuya_ctrl_base.h"

#ifndef TY_DEV_NAME_LEN
#define TY_DEV_NAME_LEN                 64          // max string length of name
#endif

#ifndef TY_DEV_MAC_LEN
#define TY_DEV_MAC_LEN                  25          // max string length of mac
#endif

#ifndef TY_ROOM_NAME_LEN
#define TY_ROOM_NAME_LEN                64          // max string length of name
#endif

#ifndef TY_DP_NAME_LEN
#define TY_DP_NAME_LEN                  64          // max string length of dp name 
#endif

#define TY_CATEGORY_LEN                 16          // max string length of category
#define TY_STD_DP_CODE_LEN              32          // max string length of standard dp code
#define TY_STRATEGY_CODE_LEN            32          // max string length of strategy code
#define TY_ICON_PATH_LEN                125         // max string length of icon path

typedef BYTE_T TY_EVENT_DEV_STAT_E;
#define TY_EVENT_DEV_SHORTCUT_STAT      0

#define TY_EVENT_ALL_INFO_SYNC          "all_info_sync"         //TY_INFO_SYNC_TP_E: dev list, room list, product list
#define TY_EVENT_DEV_SHORTCUT_REPORT    "dev_shortcut_report"   //TUYA_EVENT_SHORTCUT_S
#define TY_EVENT_DEV_ONLINE_UPDATE      "dev_online_update"     //data: TUYA_EVENT_DEV_ONLINE_S  
#define TY_EVENT_DEV_DP_NAME_UPDATE     "dev_dp_name_update"    //data：TUYA_EVENT_DP_NAME_S 
#define TY_EVENT_DEV_DP_REPORT          "dp-"                   //dp-devid, data: TUYA_STD_DP_RECV_S
#define TY_EVENT_FAMILY_INFO_INIT_OK    "family_init_ok"        //all family info init ok

typedef BYTE_T TY_INFO_SYNC_TP_E;
#define TY_SYNC_TP_ROOM                 1
#define TY_SYNC_TP_DEV                  2
#define TY_SYNC_TP_SCENE                3
#define TY_SYNC_TP_IMG                  4
#define TY_SYNC_TP_HISTORY_LOG          5

typedef INT_T  TY_DEV_CLASS_TP;
#define TY_DEV_CLASS_SENSOR         (0x01)    //dev type is sensor 
#define TY_DEV_CLASS_SUPPORT_P2P    (0x02)    //dev support p2p

#pragma pack(1)
typedef struct {
    CHAR_T std_code[TY_STD_DP_CODE_LEN + 1];
    CHAR_T strategy_code[TY_STRATEGY_CODE_LEN + 1];
    DP_PROP_TP_E prop_tp;
    DP_MODE_E mode;
    TY_CTRL_DP_PROP_U prop;
    CHAR_T *dp_name;
    
} TUYA_STD_DP_PROP_S;

typedef struct {
    CHAR_T id[DEV_ID_LEN + 1];
    CHAR_T name[TY_DEV_NAME_LEN + 1];
    CHAR_T category[TY_CATEGORY_LEN + 1];
    BOOL_T online_stat;
    BYTE_T dp_num;
    TUYA_STD_DP_PROP_S dp[0];  

} TUYA_CTRL_CENTER_DEV_S;

typedef struct {
    CHAR_T id[DEV_ID_LEN + 1];
    CHAR_T name[TY_DEV_NAME_LEN + 1];
    CHAR_T category[TY_CATEGORY_LEN + 1];
    CHAR_T icon_path[TY_ICON_PATH_LEN + 1];
    BOOL_T online_stat;
    INT_T  devClass;    //TY_DEV_CLASS_TP

} TUYA_DEV_BRIEF_INFO_S;

typedef struct {
    CHAR_T id[DEV_ID_LEN + 1];
    BOOL_T switch_stat;                                         //on/off switch status
    UINT_T ctrl_cnt;                                            //shortcut control count

} TUYA_SHORTCUT_SWITCH_S;                                       //shortcut: on/off switch

typedef struct {
    CHAR_T dev_id[DEV_ID_LEN + 1];    
} TUYA_ROOM_DEV_INFO_S;

typedef struct {
    UINT_T id;
    CHAR_T name[TY_ROOM_NAME_LEN + 1];
    USHORT_T dev_num;
    TUYA_ROOM_DEV_INFO_S *dev_list;    

} TUYA_ROOM_INFO_S;

typedef struct {
    CHAR_T std_code[TY_STD_DP_CODE_LEN + 1];            // standard dp code
    DP_PROP_TP_E type;                                  // dp type
    TY_CTRL_OBJ_DP_VALUE_U value;                       // dp value

} TUYA_STD_OBJ_DP_S;

typedef struct {
    CHAR_T dev_id[DEV_ID_LEN + 1];
    UINT_T cnt;
    TUYA_STD_OBJ_DP_S *dp;

} TUYA_STD_DP_RECV_S;

typedef struct {
    CHAR_T dev_id[DEV_ID_LEN + 1];    
    BOOL_T online_stat;

} TUYA_EVENT_DEV_ONLINE_S;

typedef struct {
    CHAR_T dev_id[DEV_ID_LEN + 1];    
    DP_PROP_TP_E type;                                  // dp type
    TY_CTRL_OBJ_DP_VALUE_U value;                       // dp value

} TUYA_EVENT_SHORTCUT_S;
typedef struct {
    CHAR_T dev_id[DEV_ID_LEN + 1];
    CHAR_T dp_code[TY_STD_DP_CODE_LEN + 1];
    CHAR_T dp_name[TY_DP_NAME_LEN + 1];
} TUYA_EVENT_DP_NAME_S;

typedef struct
{
    CHAR_T std_code[TY_STD_DP_CODE_LEN + 1];
    CHAR_T *dp_name;

} TUYA_DP_NAME_S;

typedef struct{
    CHAR_T                  std_code[TY_STD_DP_CODE_LEN + 1];    //标准指令集
    DP_PROP_TP_E            prop_tp;
    TY_CTRL_OBJ_DP_VALUE_U  value; 
    UINT_T                alarmTime;        //alarm time
}TUYA_DP_ALARM_T;

typedef struct{
    UINT_T cnt;
    TUYA_DP_ALARM_T *dp_his;
}TUYA_DP_HISTORY_T;

#pragma pack()

#ifdef __cplusplus
extern "C" {
#endif


/***********************************************************
*  Function: tuya_ctrl_center_init
*  Desc:     init
*  Input:    null
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_ctrl_center_init();

/***********************************************************
*  Function: tuya_ctrl_center_sync
*  Desc:     device/room/product sync
*  Input:    null
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_ctrl_center_sync();

/***********************************************************
*  Function: tuya_ctrl_center_get_dev
*  Desc:     get device
*  Input:    id: device id
*  Return:   TUYA_CTRL_CENTER_DEV_S: dev content, use tuya_ctrl_center_dev_free release after use
***********************************************************/
TUYA_CTRL_CENTER_DEV_S *tuya_ctrl_center_get_dev(IN CHAR_T *id);

/***********************************************************
*  Function: tuya_ctrl_center_dev_free
*  Desc:     free device memory
*  Input:    p_dev
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_ctrl_center_dev_free(IN TUYA_CTRL_CENTER_DEV_S *p_dev);

/***********************************************************
*  Function: tuya_get_dev_brief_info_list
*  Desc:     get device brief info list
*  Output:   pp_list: dev list point, use Free release after use
*  Output:   p_cnt: list count point
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_get_dev_brief_info_list(OUT TUYA_DEV_BRIEF_INFO_S **pp_list, OUT UINT_T *p_cnt);

/***********************************************************
 *  Function: tuya_dev_brief_info_list_free
 *  Desc:     free device brief info list
 *  Input:    p_list: dev list point
 *  Input:    cnt: list count
 *  Return:   OPRT_OK: success  Other: fail
 ***********************************************************/
OPERATE_RET tuya_dev_brief_info_list_free(IN TUYA_DEV_BRIEF_INFO_S* p_list, IN UINT_T cnt);

/***********************************************************
*  Function: tuya_get_shortcut_switch_list
*  Desc:     get shortcut switch list
*  Output:   pp_list: shortcut switch list point, use Free release after use
*  Output:   p_cnt: list count point
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_get_shortcut_switch_list(OUT TUYA_SHORTCUT_SWITCH_S **pp_list, OUT UINT_T *p_cnt);

/***********************************************************
*  Function: tuya_get_room_info_list
*  Desc:     get room info list
*  Output:   pp_list: room info list point, use tuya_room_info_list_free release after use
*  Output:   p_cnt: list count point
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_get_room_info_list(OUT TUYA_ROOM_INFO_S **pp_list, OUT UINT_T *p_cnt);

/***********************************************************
*  Function: tuya_room_info_list_free
*  Desc:     free room info memory
*  Input:    p_list
*  Input:    cnt: room info count
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_room_info_list_free(IN TUYA_ROOM_INFO_S *p_list, IN UINT_T cnt);

/***********************************************************
*  Function: tuya_ctrl_center_send_dp_async
*  Desc:     send standard dp async.
*  Input:    id: device id
*  Input:    dp_data: dp array 
*  Input:    cnt    : dp array count
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_ctrl_center_send_dp_async(IN CONST CHAR_T *id, IN CONST TUYA_STD_OBJ_DP_S *dp_data, IN CONST UINT_T cnt);

/***********************************************************
*  Function: tuya_shortcut_switch_send
*  Desc:     send shortcut switch.
*  Input:    id: device id
*  Input:    status    : switch status
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_shortcut_switch_send(IN CONST CHAR_T *id, IN CONST BOOL_T status);

/***********************************************************
*  Function: tuya_get_dev_dp_name_list
*  Desc:     get dev dp name list
*  Input:    id: device id
*  Output:   pp_list: dp name list point, use tuya_dev_dp_name_list_free release after use
*  Output:   p_cnt: list count point
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_get_dev_dp_name_list(IN CHAR_T *id, OUT TUYA_DP_NAME_S **pp_list, OUT UINT_T *p_cnt);

/***********************************************************
*  Function: tuya_dev_dp_name_list_free
*  Desc:     dev dp name list free
*  Input:    p_list: dp name list point
*  Input:    cnt: list count point
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_dev_dp_name_list_free(IN TUYA_DP_NAME_S *p_list, IN UINT_T cnt);

/***********************************************************
*  Function: tuya_dev_type_is_sensor
*  Input:    dev_category：dev category 
*  Return:   TRUE: sensor  FALSE: not sensor
***********************************************************/
BOOL_T tuya_dev_type_is_sensor(char *dev_category);

/***********************************************************
*  Function: tuya_dev_type_is_sensor
*  Input:    id: device id 
*  Input:    dpcode: dpcode
*  Output:   pp_dplog : dp history log info 
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_ctrl_get_history_dp_log(IN CHAR_T *id, IN CHAR_T *dpcode, OUT TUYA_DP_HISTORY_T **pp_dplog);

/***********************************************************
*  Function: tuya_ctrl_history_dp_log_release
*  Input:    pp_dplog : dp history log info  
*  Return:   OPRT_OK: success  Other: fail
***********************************************************/
OPERATE_RET tuya_ctrl_history_dp_log_release(IN TUYA_DP_HISTORY_T *p_dplog);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __TUYA_CTRL_CENTER_H__

