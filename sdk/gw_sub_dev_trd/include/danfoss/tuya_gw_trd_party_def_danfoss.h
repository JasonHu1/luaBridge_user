#ifndef __TUYA_GW_TRD_GW_PARTY_DEF_DANFOSS_H__
#define __TUYA_GW_TRD_GW_PARTY_DEF_DANFOSS_H__
#include "tuya_gw_trd_party_cfg.h"
#include "tuya_z3_base.h"

#if defined (TUYA_GW_THIRD_PARTY_DANFOSS_SUPPORT) && (1 == TUYA_GW_THIRD_PARTY_DANFOSS_SUPPORT)

#ifdef __cplusplus
    extern "C" {
#endif

#define     DANFOSS_SLEEP_DEV_HB_TIMEOUT    90*60   // 90min
#define     MANUFATURER_CODE                0x1246  // manufacturerCode

//DeviceId define
#define DEVID_DANFOSS_THERMOSTAT              DEVID_HA_THERMOSTAT   //温控器
//TuyaDeviceId define
#define TY_DEVID_DANFOSS_THERMOSTAT           0x01

#define GW_TRD_DANFOSS_THERMOSTAT_DEV_TYPE         0x01
#define GW_TRD_DANFOSS_THERMOSTAT_UDDD             (UDDD_TY_ZIGBEE_UPDATE_BIT | UDDD_TY_SLEPP_FLAG_BIT | 0x00000101)

// eTRV0100 温控器
#define GW_TRD_DANFOSS_THERMOSTAT_ETRV0100_MODEID      "eTRV0100"     // 温控器
#define GW_TRD_DANFOSS_THERMOSTAT_ETRV0100_PID         "den6kzk0"

// dpid
// DPID_DANFOSS_THERMOSTAT_ETRV0100_DevPollStatus
typedef enum{
    DEV_LONG_POLL_STATUS        = 0,  
    DEV_CHECKIN_STATUS          = 1, 
    DEV_FAST_POLLING_STATUS     = 2,  // Cool
    DEV_FAST_POLLED_STATUS      = 3,  // Heat
    DEV_FAST_STOP_STATUS        = 4,  // Fan only
}DEV_POLL_STAUTS_E;

#define ANFOSS_THERMOSTAT_ETRV0100_MAX_DP_NUM               20


#define DPID_DANFOSS_THERMOSTAT_ETRV0100_PRE_HEAT               1    //预加热开关
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_HEAT_STATUS            3    //设备加热状态
enum DANFOSS_HEAT_STATUS{
    NO_HEAT = 0,
    HEAT,
};

#define DPID_DANFOSS_THERMOSTAT_ETRV0100_UPPER_TEMP             18   //设置温度上限
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_TEMP_CURRENT           24   //当前温度
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_LOWER_TEMP             27   //设置温度下限

// #define DPID_DANFOSS_THERMOSTAT_ETRV0100_HEAT_PERCENT           22   // PIHeatingDemand, 加熱程度

#define DPID_DANFOSS_THERMOSTAT_ETRV0100_CHILD_LOCK             30   //KeypadLockout
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_BATTERY_PERCENT        34   //电池电量
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_FACTORY_RESET          44   //恢复出厂设置
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_VIEW_DIRECTION         101  //文字显示方向


// 故障显示
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_FAULT                  45   //故障告警
enum DANFOSS_FAULE{
    CLEAR_FAULT = 0x0000,
    FAULT_E1 = 0x01,
    FAULT_E2 = 0x02,
    FAULT_E3 = 0x04,
    FAULT_E4 = 0x08,
    FAULT_E6 = 0x10,
    FAULT_E14 = 0x20,
    FAULT_E15 = 0x40,
};

#define DPID_DANFOSS_THERMOSTAT_ETRV0100_mode                  2   //工作模式
enum DANFOSS_MODE{
    MODE_holiday = 0,
    MODE_manual,
    MODE_at_home,
    MODE_leaving_home,
    MODE_pause,
};

// 开窗检测状态同步
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_WINDOW_STATE           25   //窗户状态上报
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_WINDOW_CHECK           117  //窗户状态通知
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_window_toggle          116  //是否使能开窗检测功能

//
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_manual_mode_fast       114   //手动控制目标温度,下发快速加热
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_SetpointChangeSource   111   //目标温度改变源

#define DPID_DANFOSS_THERMOSTAT_ETRV0100_TEMP_SET               16    //在家目标温度,下发慢速加热
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_at_home_fast_heat      113   //在家目标温度,下发快速加热

#define DPID_DANFOSS_THERMOSTAT_ETRV0100_leavinghome_temp       109   //离家目标温度,下发慢速加热
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_leave_home_fast_heat   112   //离家目标温度,下发快速加热

#define DPID_DANFOSS_THERMOSTAT_ETRV0100_pause_temp             110   //暂停目标温度,下发快速加热
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_holiday_temp           115   //假期目标温度,下发慢速加热


#define DPID_DANFOSS_THERMOSTAT_ETRV0100_AVERAGE_LOAD           107  //平均负载
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_Load_estimate          108  //负载估算
// #define DPID_DANFOSS_THERMOSTAT_ETRV0100_LoadBalancingEnable    109  //开启负载均衡

#define DPID_DANFOSS_THERMOSTAT_ETRV0100_holiday_setting         121    //Check-inInterval
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_pause_setting           120    //LongPollInterval
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_leaving_home_setting    119    //CheckinIntervalMin
#define DPID_DANFOSS_THERMOSTAT_ETRV0100_at_home_setting         118    //FastPollTimeoutMax

// #define DPID_DANFOSS_THERMOSTAT_ETRV0100_CheckInInterval            102    //Check-inInterval
// #define DPID_DANFOSS_THERMOSTAT_ETRV0100_LongPollInterval           103    //LongPollInterval
// #define DPID_DANFOSS_THERMOSTAT_ETRV0100_CheckinIntervalMin         104    //CheckinIntervalMin
// #define DPID_DANFOSS_THERMOSTAT_ETRV0100_FastPollTimeoutMax         105    //FastPollTimeoutMax
// #define DPID_DANFOSS_THERMOSTAT_ETRV0100_LongPollIntervalMin        106    //LongPollIntervalMin
// #define DPID_DANFOSS_THERMOSTAT_ETRV0100_DevPollStatus              107    // dev_poll_status


#ifdef __cplusplus
}
#endif

#endif //TUYA_GW_THIRD_PARTY_DANFOSS_SUPPORT
#endif // __TUYA_GW_TRD_GW_PARTY_DEF_DANFOSS_H__
