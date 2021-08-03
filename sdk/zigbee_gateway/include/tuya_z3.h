#ifndef __TUYA_Z3_H
#define __TUYA_Z3_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "uni_log.h"
#include "uni_thread.h"
#include "uni_network.h"
#include "tuya_hal_mutex.h"
#include "uni_time_queue.h"
#include "tuya_hal_system.h"
#include "sys_timer.h"
#include "async_notify.h"
#include "tuya_hal_semaphore.h"
#include "uni_time.h"
#include "tuya_ws_db.h"
#include "mem_pool.h"
#include "tuya_z3_base.h"
#include "tuya_iot_com_api.h"
#include "tuya_z3_msg_api.h"
#include "tuya_app_plateform_cfg.h"
#include "tuya_gw_encrypt.h"
#include "tuya_rex_gw_encrypt.h"
#include "gw_intf.h"
#include "gw_com_def.h"
#include "tuya_iot_ext_api.h"
#include "tuya_hal_wired.h"

#ifdef  __GW_ADAPTER_GLOBALS
    #define __GW_ADAPTER_EXT
#else
    #define __GW_ADAPTER_EXT extern
#endif

#ifndef PACKED
#define PACKED __attribute__((packed))
#endif

/***********************************************************
*************************micro define***********************
***********************************************************/
#define LG_SCE_EP_MAX_NUM 8  //endpoint的最大数
#define DEV_SCE_NAME_LENGTH 5  //场景名字最大长度

#define IS_USER_DEF_UDDD(x) ((x >> 31) & 0x01)

#define DEV_ADDR_LEN            16
#define CMD_INTERVAL            200   //ms
#define SPEC_CMD_LEN_MAX        128

/*light led control*/
typedef enum {
    LIGHT_APP_CNTL = 1,
    LIGHT_ON,
    LIGHT_OFF,
    LIGHT_START_FLASH,
    LIGHT_STOP_FLASH,
    LIGHT_NO_CNTL,
} LIGHT_ACTION_E;

typedef enum {
    TUYA_Z3_STAT_INIT = 0,
    TUYA_Z3_STAT_CLOUD_CONN = 1,
    
} TUYA_Z3_NET_STAT_E;

typedef struct
{
    INT_T btn;
    INT_T grp;
    INT_T sce;
    CHAR_T sce_name[DEV_SCE_NAME_LENGTH];
}DEV_BTN_SCENE_S;

#define MODULE_DATA_REPORT                 "Data rept"
#define MODULE_COM_DATA_DOWN               "Com data down"
#define MODULE_TEMP_SENSOR_SET             "Temp Sensor set"
#define MODULE_IAS_ZONE_SET                "Ias Zone set"
#define MODULE_LINGHT_ONOFF_SET            "Light on/off set"
#define MODULE_SMART_PLUT_ONOFF_SET        "Smart plut on/off set"
#define MODULE_HEATING_COOLING             "Heating cooling set"
#define MODULE_THERMOSTAT_SET              "Thermostat set"
#define MODULE_WINDOW_COVERING_SET         "Window covering set"
#define MODULE_DIMMABLE_LIGHT_SET          "Dimmable Light set"
#define MODULE_DIMMABLE_SWITCH_SET         "Dimmable Switch set"
#define MODULE_SCENSE_SET                  "Scense set"
#define MODULE_SHADE_SET                   "Shade set"
#define MODULE_EXTENDED_COLOR_LIGHT        "Extended Color Light set"
#define MODULE_ZLL_ONOFF_LIGHT_SET         "Zll On/off Light set"
#define MODULE_IAS_WD_SET                  "Ias WD set"
#define MODULE_SIMPLE_SENSOR_SET           "Simple Sensor set"



//程序运行目录
#define TUYA_FOLD "." //主进程同目录当前目录

////修改密码
#define CHANGE_PWD_SHELL TUYA_FOLD"/change_pw.sh"

#define PRO_MONITOR_FILE_NAME "pro_mon_file"

typedef VOID (*TY_Z3_GetRfTestResultCB)(USHORT_T CurPacketCounter);
typedef VOID (*TY_Z3_GetButtonValueCB)(BOOL_T ButtonValue);
typedef VOID (*TY_Z3_GetCooUpdateStatusCB)(BOOL_T Status);

typedef VOID (*TUYA_Z3_INTO_ENGINERR_CB)(VOID);
typedef VOID (*TUYA_Z3_GW_RESET_CB)(VOID);
typedef VOID (*TUYA_Z3_LONG_CFG_NETWORK_CB)(VOID);

typedef struct {
    TUYA_Z3_INTO_ENGINERR_CB     z3_into_engineer_cb;     //进入工程模式
	TUYA_Z3_GW_RESET_CB          z3_gw_reset_cb;          //复位
	TUYA_Z3_LONG_CFG_NETWORK_CB  z3_long_cfg_network_cb;  //按键长配网模式切换
}TUYA_APP_HAL_CB_S;

typedef VOID (*TY_Z3_DevAddedNotifyCB)(BOOL_T Status);
typedef VOID (*TY_Z3_DevCooUpdateResetCB)(VOID);

typedef struct {
    TY_Z3_DevAddedNotifyCB    devadded_notify;
    TY_Z3_DevCooUpdateResetCB devcoo_update_reset;
}TUYA_Z3_APP_CB_S;

#if defined(GW_PLATFORM) && (GW_PLATFORM==GW_RTL8711AM)
typedef VOID (*TUYA_Z3_LOGOUT_SW_CB)(VOID);
typedef VOID (*TUYA_Z3_NET_LOG_SW_CB)(VOID);
typedef VOID (*TUYA_Z3_FACTORY_RESET_CB)(VOID);
typedef struct {
    TUYA_Z3_LOGOUT_SW_CB     z3_logout_sw_cb;     //全日志开关
	TUYA_Z3_NET_LOG_SW_CB    z3_net_log_sw_cb;    //网络日志开关
	TUYA_Z3_FACTORY_RESET_CB z3_factory_rst_cb;   //恢复出厂设置
}TUYA_APP_HAL2_CB_S;
#endif

typedef enum {
    TY_Z3_BUILD_MSG_COMM = 0,//0
    TY_Z3_MSG_OK_CHECK,      //1
    TY_Z3_CREATE_NET,        //2
    TY_Z3_CREATE_NET_WAIT,   //3
    TY_Z3_GET_NET_INFO,      //4
    TY_Z3_WAIT_GET_NET_INFO, //5
    TY_Z3_TIME_SYS,          //6
    TY_Z3_DATA_INIT,         //7
    TY_Z3_COUNTRY_CODE_SET,  //8
    TY_Z3_INIT_END,          //MAX
}TY_Z3_STAT_E;

typedef struct TY_Z3_GLOBAL_S{
    TY_Z3_STAT_E eTyZ3status;
    THRD_HANDLE msgthread;
    THRD_HANDLE keythread;
    INT_T g_msg_send_id;
    INT_T g_msg_recv_id;
    CHAR_T address[DEV_ID_MAX_LEN + 1];
    USHORT_T Channel;
    USHORT_T panId;
    UCHAR_T netWorkKey[TY_NETWORK_KEY + 1];
    CHAR_T *lgw_if;
    UCHAR_T isUpdateNetFlag;//是否要重新创建zigbee网络
    VOID *iterator;
    TIMER_ID InitDatatimerID;
    TIMER_ID sleepDevRecovertimerID;
    TIMER_ID sleepDevtimerID;
    CHAR_T id[DEV_ID_LEN+1];
    CHAR_T flag;//获取zigbee设备信息标志
    TIMER_ID pmit_join_tm;
    TIMER_ID dev_ug_tm;
    TIMER_ID ugend_read_ver_tm;
    TIMER_ID engineer_tm;
    TIMER_ID dev_start_ug_tm;
    TIMER_ID dev_update_percent_tm;
    TIMER_ID proc_mon_tm;
	TIMER_ID proc_mon_alarm_tm;//用于报警完自动返回，暂时这样写
    TIMER_ID zll_delay_tm;//用于zll设备群控之后,延时同步状态
    TIMER_ID zll_sync_tm;//用于zll设备 状态同步
    TIMER_ID gw_info_post;//网关信息上报定时器
    BOOL_T zllSyncFlag;//TURE时,需要从头同步
    BOOL_T isUg;
    BOOL_T isGwUg;
    BOOL_T isMcuUg; //是否本次是Mcu升级
    CHAR_T ug_time_num;
    CHAR_T curUgId[DEV_ID_LEN+1];
    UINT_T file_size;
    //UINT_T percent;
    CHAR_T lastcurUgId[DEV_ID_LEN+1];
    CHAR_T whitelistJoinId[DEV_ID_LEN+1]; // 记录当前白名单配网设备
    BOOL_T permit;
    INT_T iButtonFd;
    INT_T iPortLinkFd;
    CHAR_T zigbee_ver[SW_VER_LEN+1];
    BOOL_T cLongPermitFlag;//1标志1小时配网
    CHAR_T join_num;//长配网加入数据统计
    INT_T tm;//短配网时间
    //INT_T iPmitNum;
    TIME_T lasttimer;// 长配网上次的时间
    BOOL_T bIsInit;//设备相关是否从存储的地方初始化完
    BOOL_T bLedInit;//提示完成
    INT_T iButtonNum;//连续按键次数
    // TUYA_GW_CB_S ty_gw;
    TUYA_APP_HAL_CB_S app_hal_cb;
#if defined(GW_PLATFORM) && (GW_PLATFORM==GW_RTL8711AM)    
    TUYA_APP_HAL2_CB_S app_hal2_cb;
#endif
    GW_BASE_NW_STAT_T nw_stat;//gw internet status
    TUYA_Z3_NET_STAT_E z3_net_stat;
    // CHAR_T cur_run_dir[32+1];
    USHORT_T rf_test_result;
    TUYA_Z3_APP_CB_S app_cb;
    BOOL_T is_ncp_support_write;
}TY_Z3_GLOBAL_T;

#define GW_KEY_RST_TIME       5000            //按键重置时间 ms
#define GW_KEY_TIMER_MS      	 20    //key timer inteval

typedef struct TY_COM_PRO_DATA_S{
    BYTE_T dpid;
    BYTE_T type;
    USHORT_T len;
    UCHAR_T data[0];
} PACKED TY_COM_PRO_DATA_T;

typedef struct {
    TIME_S sExpireTime;         // 下次超时时间 s
    TIME_MS msExpireTime;       // 下次超时时间 ms
}DELAY_CMD_TIMER_S;

typedef struct
{
    CHAR_T      addr[DEV_ADDR_LEN + 1];
    BYTE_T      dp_id;
    BYTE_T      index;
    TuYaApsFrame sTyApsFrameTmp;
    DELAY_CMD_TIMER_S  timer;
    SLIST_HEAD  node;   
    
}PACKED DEV_DELAY_S;

typedef struct
{
    SLIST_HEAD  dev_list;
    MUTEX_HANDLE mutex;
    TIMER_ID    tm;
    
}PACKED GW_DELAY_S;

typedef struct ZCL_DEV_ID_TABLE_S
{
    USHORT_T usDevId;
    UCHAR_T  ucTyDevId;
}ZCL_DEV_ID_TABLE_t;

TY_Z3_GLOBAL_T *get_ty_z3_global_info(VOID);
OPERATE_RET tuya_z3_ReadAttrData(IN USHORT_T clusterId, IN UCHAR_T destEndpoint, IN USHORT_T *AttrBuf, IN UCHAR_T AttrNum, IN TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET tuya_Z3_DevDataDown_process(IN CHAR_T *dev_id,IN TY_CMD_U *cmd, IN CHAR_T type);
OPERATE_RET tuya_z3_init(VOID);
OPERATE_RET tuya_z3_network_init(VOID);
BOOL_T tuya_Z3_SupportFactory(IN USER_DEV_DTL_DEF_T uddd);
OPERATE_RET tuya_Z3_DevDel(IN CHAR_T *dev_id);
OPERATE_RET tuya_z3_PermitJoin(IN       GW_PERMIT_DEV_TP_T tp,IN BOOL_T permit,IN UINT_T timeout);

/**
 * @brief 启动coo升级
 * 
 * @param cb coo升级结果获取回调，一般产测使用，可为NULL
 */
OPERATE_RET tuya_z3_CooUpdate(TY_Z3_GetCooUpdateStatusCB cb);

OPERATE_RET tuya_z3_DevUpdate(CHAR_T *dev_id, UINT_T file_size);
VOID tuya_z3_SetUpdateStatus(BOOL_T status);
BOOL_T tuya_z3_GetUpdateStatus(VOID);
#if 0//hxh
OPERATE_RET tuyz3_keyHandle(TIME_S InterTime);
VOID tuya_z3_ZigbeeNetWorkLedSet(INT_T iTime);
#endif

OPERATE_RET __update_sce_list(IN CHAR_T *dev_id,IN UINT_T ep_cnt, IN BYTE_T *pep_mark);
OPERATE_RET _Z3_ScenesHandle(IN CONST CHAR_T *dev_id, CHAR_T cCmd, USHORT_T cGrgId, CHAR_T cSceId, \
                                        USHORT_T usTransTime, CHAR_T *cSceName, UCHAR_T *cExtField, CHAR_T cExtFieldLen, UCHAR_T ep);
OPERATE_RET _Z3_GroupHandle(CHAR_T *dev_id, CHAR_T cCmd, USHORT_T *cGrgId, CHAR_T cNum, CHAR_T *cName, UCHAR_T ep);
OPERATE_RET tuya_Z3_Query_Dp_process(IN CONST TY_DP_QUERY_S *dp_qry);
OPERATE_RET tuya_z3_getZigbeeVer(CHAR_T *ver);
OPERATE_RET tuya_z3_dataTime_init(VOID);
OPERATE_RET gw_adapter_rm_all_dev_scene(VOID);
VOID tuya_z3_SetInitStatus(IN BOOL_T isInit);
OPERATE_RET tuya_login_init(CHAR_T *auth_key, BOOL_T active_stat);
OPERATE_RET tuya_Z3_ResetFactory(IN DEV_DESC_IF_S *dev_if,DEV_RESET_TYPE_E type);
OPERATE_RET tuya_z3_DevScenes(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer, IN BOOL_T isSkipUddd);

/**
 * @brief 对低功耗设备下发唤醒参数
 * @param dev_id
 * @return
 */
OPERATE_RET tuya_z3_WakeupDev(IN CONST CHAR_T * dev_id);

/**
 * @brief 启动zigbee rf测试
 * 
 * @param cb rf测试结果获取回调，一般产测使用，可为NULL
 */
OPERATE_RET tuya_z3_RfTestStart(TY_Z3_GetRfTestResultCB cb, BOOL_T type, UCHAR_T channel, USHORT_T numPackets, UCHAR_T length, UCHAR_T *message, CHAR_T power);
OPERATE_RET tuya_z3_GetRfTestResult(USHORT_T *p_result);
OPERATE_RET tuya_z3_CreateNetWithChannel(UCHAR_T channel);

BOOL_T tuya_comProDataCheckout(IN TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET tuya_z3_ComPro_dataQuery(IN TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET ty_ComDataSend(IN TuYaApsFrame * sTyApsFrameTmp, BYTE_T *send_buf, USHORT_T send_len,  USHORT_T cmd_type);
BOOL_T tuya_isEncrypt(UINT_T uddd);
BOOL_T tuya_isReliableData(UINT_T uddd);
BOOL_T tuya_isComEncryptLock(UINT_T uddd);
BOOL_T tuya_isSupportMcuUpdate(UINT_T uddd);

OPERATE_RET gw_encrypt_sync_config(TIME_S timeCycle);
OPERATE_RET tuya_z3_DevDataDown_Send(CHAR_T *addr, UCHAR_T *data, USHORT_T length,
                                                        USHORT_T clusterId, UCHAR_T command, UCHAR_T cmdType);

OPERATE_RET tuya_z3_MsgSendTo(IN msq_struct_t *msgs);
VOID tuya_cmd_printf_info(IN TuYaApsFrame *sTyApsFrameTmp, IN CHAR_T *module);
OPERATE_RET tuya_z3_PluginCountersPrint(VOID);
OPERATE_RET tuya_z3_GetZ3RouteTable(IN CHAR_T* eui64_str, IN UINT16_T flag);
VOID tuya_z3_dev_update_percent_start(VOID);
VOID tuya_z3_dev_update_percent_stop(VOID);
VOID gw_net_log_stop(VOID);
VOID gw_net_log_start(VOID);
VOID gw_status_change(BOOL_T online);
VOID tuya_z3_noUuidInit(VOID);
BOOL_T if_is_XM_dev_judge_by_uddd(IN UINT_T uddd);
OPERATE_RET tuya_Z3_UpdateDevDataStatus_process(IN CHAR_T *dev_id);
TY_Z3_GLOBAL_T *tuya_get_z3_info(VOID);
OPERATE_RET tuya_encrypt_init();
VOID ximeng_dev_reset_factory(IN DEV_DESC_IF_S *dev_if);
VOID tuya_z3_gw_reset(VOID);

OPERATE_RET gw_class_grp_add(IN CHAR_T *dev_id,IN CHAR_T *grp_id);
OPERATE_RET gw_class_grp_del(IN CHAR_T *dev_id,IN CHAR_T *grp_id);
OPERATE_RET gw_adapter_grp_add(IN CHAR_T *dev_id,IN CHAR_T *grp_id);
OPERATE_RET gw_adapter_grp_del(IN CHAR_T *dev_id,IN CHAR_T *grp_id);
OPERATE_RET gw_adapter_sce_add(IN CHAR_T *dev_id,IN CHAR_T *grp_id,IN CHAR_T *sce_id);
OPERATE_RET gw_adapter_sce_del(IN CHAR_T *dev_id,IN CHAR_T *grp_id,IN CHAR_T *sce_id);
OPERATE_RET gw_adapter_sce_exec(IN CHAR_T *dev_id,IN CHAR_T *grp_id,IN CHAR_T *sce_id);
//场景面板设置，目前只有工程模式用到
OPERATE_RET tuya_z3_sce_panel_set(IN CONST CHAR_T *dev_id,IN CONST SCE_PANEL_S *sce_panel,IN CONST INT_T btn_num);


GW_ENCRYPT_S *get_gw_encrypt(VOID);
REX_GW_ENCRYPT_S *get_rex_gw_encrypt();
OPERATE_RET tuya_z3_com_to_dp(UCHAR_T *ucDataIndex, INT_T index, TY_COM_PRO_DATA_T *sComData, TY_OBJ_DP_S *dp_data);
OPERATE_RET tuya_z3_ApsFrameMsgSendTo(IN TuYaApsFrame *sTyApsFrameTmp);
OPERATE_RET tuya_z3_MsgSendApi(IN BYTE_T dpid, IN TuYaApsFrame *sTyApsFrameTmp);
VOID tuya_z3_NetLedStatSet(IN BOOL_T active_stat);
OPERATE_RET tuya_z3_MsgInit();
OPERATE_RET tuya_z3_HaScenesPrivate(IN TuYaApsFrame *sTyApsFrameTmp, IN CONST CHAR_T *address, IN UINT_T uddd, IN UCHAR_T *buffer);
OPERATE_RET gw_z3_clear_store(VOID);
BOOL_T tuya_isStdReliabe(UINT_T uddd);
BOOL_T tuya_isStdReliabeSendDpId(UINT_T uddd, UINT_T dpid);

#if defined(GW_PLATFORM) && (GW_PLATFORM==GW_RTL8711AM)
VOID tuya_set_prodtest_status(IN BOOL_T status);
VOID tuya_get_prodtest_status(OUT BOOL_T *value);
#endif
OPERATE_RET set_tuyaapsframe_ep(IN CONST BYTE_T in_dpid, IN TuYaApsFrame *sTyApsFrameTmp);
BOOL_T __isTuyaStandardDevice(IN UINT_T uddd);
BOOL_T __isHaDimmableSwitch(IN UINT_T  uddd);

VOID tuya_z3_intf_cur_run_dir(CHAR_T *run_dir);
VOID tuya_z3_SetGwUpdateStat(IN BOOL_T status);

VOID tuya_z3_RegisterAppCb(IN CONST TUYA_Z3_APP_CB_S *app_cb);
BOOL_T tuya_z3_GetAddDevStatus(VOID);


#if defined(GW_FAULT_REPLACE) && (GW_FAULT_REPLACE==1)
OPERATE_RET tuya_z3_GetNetInfo(VOID);
VOID tuya_z3_fault_replace(VOID);
VOID tuya_z3_getNcpMac(CHAR_T *mac);
OPERATE_RET tuya_Z3_SetNcpMac(IN CHAR_T *ncp_mac);
#endif

OPERATE_RET tuya_z3_set_ncp_mac_writable(CHAR_T *cur_ver, CHAR_T *valid_ver);
BOOL_T tuya_z3_get_ncp_mac_writable(VOID);

VOID tuya_z3_GW_info_post(VOID);
VOID tuya_z3_HeartBeatQuery(IN CONST CHAR_T *dev_id);

OPERATE_RET delay_queue_msg_report(IN CONST P_MSG_DATA pMsgData, IN CONST MSG_DATA_LEN msgDataLen);

#ifdef __cplusplus
}
#endif

#endif
