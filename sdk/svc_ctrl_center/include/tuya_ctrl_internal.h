#ifndef __TUYA_CTRL_INTERNAL_H__
#define __TUYA_CTRL_INTERNAL_H__

#include <stdio.h>
#include <string.h>
#include "tuya_ctrl_center.h"
#include "uni_slist.h"
#include "gw_intf.h"
#include "mqc_app.h"
#include "tuya_os_adapter.h"
#include "tuya_iot_internal_api.h"
#include "base_event.h"
#include "mem_pool.h"
#include "com_protocol.h"
#include "smart_frame.h"
#include "com_mmod.h"

#define TY_HTTP_GET_PROD_STD_LIST           "tuya.device.screen.prod.standard.config.list"
#define TY_HTTP_SCREEN_GET_DEV              "tuya.device.screen.device.get"
#define TY_HTTP_SCREEN_GET_DEV_ALL          "tuya.device.screen.device.all"
#define TY_HTTP_SCREEN_GET_ROOM_ALL         "tuya.device.screen.room.device.all"
#define TY_HTTP_GET_PROD_STD_ALL            "tuya.device.screen.standard.config.all"
#define TY_HTTP_SCREEN_GET_PROD             "tuya.device.linux.product.get"
#define TY_HTTP_SENSOR_GET_RULE             "tuya.device.screen.device.type.config"
#define TY_HTTP_SENSOR_ALARM_GET            "tuya.device.screen.dp.history.list.batch"

#define TY_CTRL_EVENT_DESC                  "dev_ctrl"
#define TY_CTRL_TOPIC_LEN                   (DEV_ID_LEN + 20)   
#define TY_CTRL_DP_MAX                      255
#define TY_DP_PROP_OBJ_MAX                  PROP_BITMAP
#define TY_DP_PROP_UNKOWN                   10
#define TY_STR_DP_VALUE_DEF                 ""
#define TY_CTRL_IMG_SVC_ID                  "ctrl_dev_img"

#define TY_SYNC_DELAY_TM                    5       //ms
#define TY_MQ_CONN_SYNC_DELAY_TM            100     //ms

#define TY_DP_ID_MAX_LEN                    3   ///< dp id的最大长度
#define TY_SERIALIZE_DP_NAME_EX_LEN         6   ///< 序列化存储dpname时，需要单个dpname需要额外填充的字符个数
#define TY_DP_NAME_MAX_NUM                  10  ///< 最大dp name个数

typedef enum{
    TY_SCHEMA_TP_FUNCTION = 0,
    TY_SCHEMA_TP_STATUS = 1,         

} TY_SCHEMA_TP_E;

typedef UINT_T ONLINE_ST;

typedef struct
{
    UINT_T shortcut_cnt;                            //shortcut control count

} TUYA_DEV_STATISTICS;

typedef struct {
    CHAR_T id[DEV_ID_LEN + 1];
    CHAR_T name[TY_DEV_NAME_LEN + 1];
    CHAR_T mac[TY_DEV_MAC_LEN + 1];
    CHAR_T node_id[DEV_ID_LEN + 1];
    CHAR_T pid[PRODUCT_KEY_LEN + 1];
    CHAR_T *icon_url;
    CHAR_T icon_path[TY_ICON_PATH_LEN + 1];
    CHAR_T communicate[DEV_ID_LEN + 1];         //communication Node
    CHAR_T local_key[LOCAL_KEY_LEN + 1];
    CHAR_T pv[SW_VER_LEN + 1];
    INT_T  p2pType;

    BOOL_T is_sub;                              //is sub device

} TUYA_DEV_IF_S;

typedef struct {
    DP_DESC_IF_S dp_desc;
    TY_CTRL_OBJ_DP_VALUE_U value;   /* 存储dp的值 */
    CHAR_T *dp_name;

} TUYA_CTRL_DP_CNTL_S;

typedef struct {
    SLIST_HEAD  node;    
    TUYA_DEV_IF_S dev_if;
    ONLINE_ST online_stat;
    TUYA_DEV_STATISTICS stats;
    
    BYTE_T dp_num;
    TUYA_CTRL_DP_CNTL_S dp[0];                              //dev dp status

} TUYA_DEV_DATA_S;

typedef struct {
    CHAR_T std_code[TY_STD_DP_CODE_LEN + 1];
    DP_PROP_TP_E prop_tp;
    TY_CTRL_DP_PROP_U prop;
    DP_MODE_E mode;
    CHAR_T strategy_code[TY_STRATEGY_CODE_LEN + 1];

    CHAR_T *dp_code;    // 对应json中的状态集(statusSchemaList)的dpCode,功能集(functionSchemaList)的mainDpCode,与std_code一一对应，但是名称会有区别，主要应用于strategyValue的json解析
    BYTE_T dp_id;                               //pid dp id
    DP_PROP_TP_E dp_tp;                         //pid dp type

    CHAR_T *fun_strategy;                       //function strategy value
    CHAR_T *stat_strategy;                      //status strategy value

    UINT8_T relate_dp_num;
    BYTE_T relate_dp[5];                        //function relate dps
} TUYA_STD_DP_S;

typedef struct {
    BYTE_T switch_dp;

} TUYA_PROD_SHORTCUT_S;

typedef struct {
    SLIST_HEAD  node;    
    CHAR_T pid[PRODUCT_KEY_LEN + 1];
    CHAR_T category[TY_CATEGORY_LEN + 1];
    TUYA_PROD_SHORTCUT_S shortcut;
    INT_T associated_dev_num;
    BYTE_T dp_num;
    TUYA_STD_DP_S dp[0];

} TUYA_PROD_CONF_S;

typedef struct {
    SLIST_HEAD  node;    
    UINT_T id;
    CHAR_T name[TY_ROOM_NAME_LEN + 1];
    USHORT_T dev_num;
    TUYA_ROOM_DEV_INFO_S dev_list[0];    

} TUYA_ROOM_S;

typedef struct {
    SLIST_HEAD      dev_list;
    SLIST_HEAD      prod_list;
    SLIST_HEAD      room_list;
    MUTEX_HANDLE    mutex;

    UINT_T          dev_num;
    UINT_T          prod_num;
    UINT_T          room_num;

    TM_MSG_S        *tmm_sync;

} TUYA_CTRL_MGR_S;


typedef struct{
    CHAR_T                  std_code[TY_STD_DP_CODE_LEN + 1];    //标准指令集
    BYTE_T                  dp_id;
    DP_PROP_TP_E            prop_tp;
    TY_CTRL_OBJ_DP_VALUE_U  value; 
    UINT_T                  alarmTime;        //alarm time
}TUYA_DP_EVENT_T;

typedef struct{
    SLIST_HEAD node;
    UINT_T cnt;
    TUYA_DP_EVENT_T dp[0];
}TUYA_DP_LOG_T;

typedef struct {
    SLIST_HEAD      node;    
    CHAR_T          id[DEV_ID_LEN + 1];   //dev id
    INT_T           dp_count;             //alarm count
    SLIST_HEAD      list;                 //TUYA_DP_LOG_T
} TUYA_SENSOR_ALARM_S;

typedef struct {
    BOOL_T       ready;
    UINT_T       categoryCnt;
    CHAR_T       **category;   //传感器规则
    UINT_T       total_dpids;
    UINT_T       sensor_num;
    SLIST_HEAD   sensor_list;    //TUYA_SENSOR_ALARM_S
} TUYA_ALARM_MGR_S;

typedef OPERATE_RET (*TY_CTRL_TRAVERSAL_DEV_CB)(TUYA_DEV_DATA_S *node, VOID *user_param);

#ifdef __cplusplus
extern "C" {
#endif

typedef OPERATE_RET (*PROD_STD_TRAVERSAL_CB)(IN ty_cJSON *item, INOUT TUYA_PROD_CONF_S **pp_prod);
typedef OPERATE_RET (*DEV_TRAVERSAL_CB)(IN CONST TUYA_DEV_DATA_S *p_dev, IN CONST CHAR_T *dp_names_info);
typedef OPERATE_RET (*ROOM_TRAVERSAL_CB)(IN ty_cJSON *item, INOUT TUYA_ROOM_S **pp_room);
typedef OPERATE_RET (*product_TRAVERSAL_CB)(IN CHAR_T *pid, IN ty_cJSON *item, INOUT TUYA_PROD_CONF_S **pp_prod);
typedef OPERATE_RET (*SENSOR_TRAVERSAL_CB)(IN ty_cJSON *item);

OPERATE_RET tuya_ctrl_get_key(CHAR_T *id, CHAR_T *local_key, CHAR_T *pv);
OPERATE_RET tuya_get_prod_dp(CONST BYTE_T dp_id, CONST TUYA_PROD_CONF_S *p_prod, UINT_T *idx);
OPERATE_RET tuya_get_dev_dp(CONST BYTE_T dp_id, CONST TUYA_DEV_DATA_S *p_dev, UINT_T *idx);
/**
 * @brief 根据dp_id获取目标dp在存储的数据p_prod中的索引
 * 
 * @param dp_id dp_id值，对应云端json中relationDpIdMaps的值
 * @param p_prod 存储的从云端获取的设备数据
 * @param idx 目标dp在存储的数据p_prod中的索引
 * @return OPERATE_RET 
 */
OPERATE_RET tuya_get_prod_dp_by_dpid(IN CONST BYTE_T dp_id, IN CONST TUYA_PROD_CONF_S *p_prod, OUT UINT_T *idx);
OPERATE_RET tuya_get_prod_dp_by_std_code(CONST CHAR_T *std_code, CONST TUYA_PROD_CONF_S *p_prod, UINT_T *idx);
TUYA_CTRL_MGR_S *tuya_ctrl_get_mgr();
TUYA_PROD_CONF_S *tuya_ctrl_get_prod_unlock(CONST CHAR_T *pid);
TUYA_DEV_DATA_S *tuya_ctrl_get_dev_unlock(CONST CHAR_T *id, CONST CHAR_T *sub_id);
TUYA_ROOM_S *tuya_ctrl_get_room_unlock(CONST UINT_T id);
INT_T tuya_ctrl_get_enum_index(TY_CTRL_DP_ENUM_S *prop_enum, CHAR_T *value_str);
OPERATE_RET tuya_ctrl_del_room(CONST UINT_T id);
OPERATE_RET tuya_ctrl_http_get_room_list();
OPERATE_RET tuya_ctrl_del_dev(CONST CHAR_T *id);
OPERATE_RET tuya_ctrl_add_dev(CONST CHAR_T *id, CONST CHAR_T *pid);
OPERATE_RET tuya_ctrl_subscribe_db_dev();
OPERATE_RET tuya_ctrl_sync_all_info(TIME_MS delay);
OPERATE_RET tuya_ctrl_sync_img();
OPERATE_RET tuya_ctrl_update_dp_prop(DP_PROP_TP_E tp, TY_CTRL_DP_PROP_U *dst, CONST TY_CTRL_DP_PROP_U *src);
OPERATE_RET tuya_ctrl_http_get_dev(CONST CHAR_T *id);
OPERATE_RET tuya_ctrl_history_dp_update_all(CHAR_T *id, TUYA_STD_OBJ_DP_S *dps, INT_T cnt, UINT_T time);
OPERATE_RET tuya_ctrl_history_dp_update(IN CHAR_T *id, IN CHAR_T *dpcode, TUYA_DP_EVENT_T *dpevent);
OPERATE_RET tuya_ctrl_traversal_dev(TY_CTRL_TRAVERSAL_DEV_CB cb, VOID *user_param);
OPERATE_RET tuya_ctrl_center_get_dev_cid(IN CONST CHAR_T *id, OUT CHAR_T *cid);
OPERATE_RET tuya_ctrl_center_get_dev_ctr_dp(IN CONST CHAR_T *id, IN CONST BYTE_T dpid, OUT TUYA_CTRL_DP_CNTL_S* dp_ctrl);
OPERATE_RET tuya_inc_dev_num_associated_with_pid_unlock(IN CONST CHAR_T *pid);
OPERATE_RET tuya_sub_dev_num_associated_with_pid_unlock(IN CONST CHAR_T *pid);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // 

