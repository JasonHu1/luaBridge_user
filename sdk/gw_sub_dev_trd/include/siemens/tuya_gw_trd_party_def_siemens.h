#ifndef __TUYA_GW_TRD_GW_PARTY_DEF_SIEMENS_H__
#define __TUYA_GW_TRD_GW_PARTY_DEF_SIEMENS_H__
#include "tuya_gw_trd_party_cfg.h"
#include "tuya_z3_base.h"

#if defined (TUYA_GW_THIRD_PARTY_SIEMENS_SUPPORT) && (1 == TUYA_GW_THIRD_PARTY_SIEMENS_SUPPORT)

#define     SIEMENS_SLEEP_DEV_HB_TIMEOUT    15*60 // 15min

// Zigbee SystemMode Attribute Values
enum ENUM_SYS_MODE_ATTR_VALUE
{
    SYS_MODE_ATTR_VALUE_OFF    = 0x00,  
    SYS_MODE_ATTR_VALUE_AUTO   = 0x01,  
    SYS_MODE_ATTR_VALUE_COOL   = 0x03,  // Cool
    SYS_MODE_ATTR_VALUE_HEAT   = 0x04,  // Heat
    SYS_MODE_ATTR_VALUE_FAN    = 0x07,  // Fan only
    SYS_MODE_ATTR_VALUE_DRY    = 0x08,  // Dry
    SYS_MODE_ATTR_VALUE_SLEEP  = 0x09,  // Sleep
};

// Zigbee FanMode Attribute Values
enum ENUM_FAN_MODE_ATTR_VALUE
{
    FAN_MODE_ATTR_VALUE_OFF    = 0x00,  
    FAN_MODE_ATTR_VALUE_LOW    = 0x01,
    FAN_MODE_ATTR_VALUE_MEDIUM = 0x02,
    FAN_MODE_ATTR_VALUE_HIGH   = 0x03,
    FAN_MODE_ATTR_VALUE_ON     = 0x04,
    FAN_MODE_ATTR_VALUE_AUTO   = 0x05,
    FAN_MODE_ATTR_VALUE_SMART  = 0x06, 
};

/********************************   中央空调、新风、地暖面板功能属性信息   *********************************/
//DeviceId define
#define DEVID_SIE_THERMOSTAT           DEVID_HA_THERMOSTAT               // 空调、新风
#define DEVID_SIE_HEATING_COOLING      DEVID_HA_HEATING_COOLING_UNIT     // 地暖
//TuyaDeviceId define
#define TY_DEVID_SIE_THERMOSTAT         0x06  // 空调、新风
#define TY_DEVID_SIE_HEATING_COOLING    0x05  // 地暖

#define GW_TRD_SIE_AC_MODEID                    "SIE016"     // 空调
#define GW_TRD_SIE_AC_PID                       "ovk7hiha"
#define GW_TRD_SIE_FAC_MODEID                   "SIE017"     // 新风
#define GW_TRD_SIE_FAC_PID                      "xxk2fqkd"
#define GW_TRD_SIE_HEATING_COOLING_MODEID       "SIE018"     // 地暖
#define GW_TRD_SIE_HEATING_COOLING_PID          "jdnoiiwh"

#define GW_TRD_SIE_AC_SIE016_UDDD                       0x02000601
#define GW_TRD_SIE_AC_SIE016_TYPE                       0x01
#define GW_TRD_SIE_FAC_SIE017_UDDD                      0x02000602
#define GW_TRD_SIE_FAC_SIE017_TYPE                      0x02
#define GW_TRD_SIE_HEATING_COOLING_UNIT_SIE018_UDDD     0x02000503
#define GW_TRD_SIE_HEATING_COOLING_UNIT_SIE018_TYPE     0x03

// 空调功能点
#define THERMOSTAT_MAX_DP_NUM      15

#define DPID_SIE_AC_ONOFF          1
#define DPID_SIE_AC_TMP_SET        2
#define DPID_SIE_AC_TMP_CUR        3
#define DPID_SIE_AC_MODE           4
enum ENUM_DPID_SIE_AC_MODE
{
    SIE_AC_MODE_COOL   = 0,  // 制冷
    SIE_AC_MODE_HEAT   = 1,  // 制热
    SIE_AC_MODE_FAN    = 2,  // 通风
    SIE_AC_MODE_DRY    = 3,  // 除湿
};

#define DPID_SIE_AC_LOCK           8
#define DPID_SIE_AC_FAN_V          9       // fan_vertical，上下摆风,
// #define DPID_SIE_AC_FAN_H          10      // fan_horizontal，左右摆风, 无此功能
#define DPID_SIE_AC_SLEEP          27
#define DPID_SIE_AC_DEV_TYPE       102     // 机型识别, string,只上报
#define DPID_SIE_AC_ENG_SAVING     103     // 节能模式
#define DPID_SIE_AC_ERR_CODE       104     // 故障告警
#define DPID_SIE_AC_SPEED_FAN      105     // 风速,  高、中、低、自动
enum ENUM_DPID_SIE_AC_SPEED_FAN
{
    SIE_AC_SPEED_FAN_L   = 0,
    SIE_AC_SPEED_FAN_M   = 1,
    SIE_AC_SPEED_FAN_H   = 2,
    SIE_AC_SPEED_FAN_A   = 3,
};

// 新风功能点
#define DPID_SIE_FAC_ONOFF          1
#define DPID_SIE_FAC_MODE           4
#define DPID_SIE_FAC_LOCK           DPID_SIE_AC_LOCK
#define DPID_SIE_FAC_SLEEP          DPID_SIE_AC_SLEEP
#define DPID_SIE_FAC_BYBASS         DPID_SIE_AC_ENG_SAVING    // 旁通阀，和空调的节能模式共用
#define DPID_SIE_FAC_FILTER_TIME    104                       // 滤网时间
#define DPID_SIE_FAC_SPEED_FAN      DPID_SIE_AC_SPEED_FAN     // 风速

//地暖功能点
#define DPID_SIE_HEATING_ONOFF          1
#define DPID_SIE_HEATING_TMP_SET        DPID_SIE_AC_TMP_SET  // 和空调共用dp
#define DPID_SIE_HEATING_TMP_CUR        DPID_SIE_AC_TMP_CUR  // 和空调共用dp
#define DPID_SIE_HEATING_LOCK           DPID_SIE_AC_LOCK
#define DPID_SIE_HEATING_SLEEP          DPID_SIE_AC_SLEEP
#define DPID_SIE_HEATING_ENG_SAVING     DPID_SIE_AC_DEV_TYPE     // 节能模式, 和空调的机型识别共用
#define DPID_SIE_HEATING_ERR_CODE       103     // 故障告警

/*******************************************************************************************/


/************************      智能开关、智能插座、辅控开关功能属性信息    ************************/
//DeviceId define
#define DEVID_SIE_ONOFF_LIGHT               DEVID_HA_ONOF_LIGHT         // 0x0100 -> 0x02, 开关
#define DEVID_SIE_SMART_PLUG                DEVID_HA_MAINS_POWER_OUTLET // 智能插座
#define DEVID_SIE_ON_OFF_SWITCH             DEVID_HA_ON_OFF_SWITCH      // 辅控开关
//TuyaDeviceId define
#define TY_DEVID_SIE_ONOFF_LIGHT            0x02                        // 智能开关
// #define TY_DEVID_SIE_SMART_PLUG             TY_DEVID_SIE_ONOFF_LIGHT    // 智能插座,和智能开关共用
// #define TY_DEVID_SIE_ONOFF_SWITCH           TY_DEVID_SIE_ONOFF_LIGHT    // 辅控开关,和智能开关共用

//dpid 
#define ON_OFF_LIGHT_DP_NUM             10
#define DPID_SIE_ONOFF_LIGHT_1_ONOFF          1
#define DPID_SIE_ONOFF_LIGHT_2_ONOFF          2
#define DPID_SIE_ONOFF_LIGHT_3_ONOFF          3
#define DPID_SIE_ONOFF_BACKLIGHT              101

#define GW_TRD_SIE_ONOFF_LIGHT_UDDD           0x02000201
#define GW_TRD_SIE_ONOFF_LIGHT_DEV_TYPE       0x01
// #define GW_TRD_SIE_SMART_PLUG_UDDD            GW_TRD_SIE_ONOFF_LIGHT_UDDD
// #define GW_TRD_SIE_SMART_PLUG_DEV_TYPE        GW_TRD_SIE_ONOFF_LIGHT_DEV_TYPE

#define GW_TRD_SIE_ONOFF_LIGHT_SIE001_MODEID       "SIE001"   // 一路智能开关
#define GW_TRD_SIE_ONOFF_LIGHT_SIE001_PID          "bikditbf"
#define GW_TRD_SIE_ONOFF_LIGHT_SIE002_MODEID       "SIE002"   // 二路智能开关
#define GW_TRD_SIE_ONOFF_LIGHT_SIE002_PID          "xva3bjoh"
#define GW_TRD_SIE_ONOFF_LIGHT_SIE003_MODEID       "SIE003"   // 三路智能开关
#define GW_TRD_SIE_ONOFF_LIGHT_SIE003_PID          "kgczcctc"

#define GW_TRD_SIE_ONOFF_SWITCH_SIE021_MODEID      "SIE021"  // 一路辅控开关
#define GW_TRD_SIE_ONOFF_SWITCH_SIE021_PID         GW_TRD_SIE_ONOFF_LIGHT_SIE001_PID
#define GW_TRD_SIE_ONOFF_SWITCH_SIE022_MODEID      "SIE022"  // 二路辅控开关
#define GW_TRD_SIE_ONOFF_SWITCH_SIE022_PID         GW_TRD_SIE_ONOFF_LIGHT_SIE002_PID

#define GW_TRD_SIE_SMART_PLUG_SIE007_MODEID        "SIE007"  // 3孔插座
#define GW_TRD_SIE_SMART_PLUG_SIE007_PID           "xvtciyb3"
#define GW_TRD_SIE_SMART_PLUG_SIE008_MODEID        "SIE008"  // 五孔USB插座
#define GW_TRD_SIE_SMART_PLUG_SIE008_PID           "qos3mgvx"
#define GW_TRD_SIE_SMART_PLUG_SIE009_MODEID        "SIE009"  // 5孔插座
#define GW_TRD_SIE_SMART_PLUG_SIE009_PID           "6ywoglx5"

/*******************************************************************************************/

/********************************      场景设备功能属性信息    *********************************/
//DeviceId define
#define DEVID_SIE_SCENE_SELECTOR               DEVID_HA_SCENE_SELECTOR      // 场景开关
//TuyaDeviceId define
#define TY_DEVID_SIE_SCENE_SELECTOR            0x08

#define GW_TRD_SIE_SCENE_SELECTOR_UDDD              (0x02000801|UDDD_TY_STANDARD_DP_BIT)  // 标准dp置位
#define GW_TRD_SIE_SCENE_SELECTOR_DEV_TYPE          0x01

#define DPID_SIE_SCENE_SELECTOR_BATTERY_PERCENT           101   //场景遥控器电池版 电池电量

#define GW_TRD_SIE_SCENE_SELECTOR_SIE004_MODEID       "SIE004"   // 2键场景开关
#define GW_TRD_SIE_SCENE_SELECTOR_SIE004_PID          "jyqafzji" 
#define GW_TRD_SIE_SCENE_SELECTOR_SIE005_MODEID       "SIE005"   // 4键场景开关
#define GW_TRD_SIE_SCENE_SELECTOR_SIE005_PID          "xpz50qjn" 
#define GW_TRD_SIE_SCENE_SELECTOR_SIE006_MODEID       "SIE006"   // 6键场景开关
#define GW_TRD_SIE_SCENE_SELECTOR_SIE006_PID          "ut1igln5" //"tgasueng"
#define GW_TRD_SIE_SCENE_SELECTOR_SIE015_MODEID       "SIE015"   // 6键场景遥控器电池版
#define GW_TRD_SIE_SCENE_SELECTOR_SIE015_PID          "sufqnpl5"

/*******************************************************************************************/

/********************************      窗帘开关设备功能属性信息    *********************************/
//DeviceId define
#define DEVID_SIE_WINDOW_COVERING              DEVID_HA_WINDOW_COVERING      // 窗帘电机
//TuyaDeviceId define
#define TY_DEVID_SIE_WINDOW_COVERING           0x07

#define GW_TRD_SIE_WINDOW_COVERING_UDDD             0x02000701
#define GW_TRD_SIE_WINDOW_COVERING_DEV_TYPE         0x01

#define GW_TRD_SIE_WINDOW_COVERING_SIE013_MODEID      "SIE013"   // 一路窗帘电机
#define GW_TRD_SIE_WINDOW_COVERING_SIE013_PID         "0kzmipgd"   // 一路窗帘电机
#define GW_TRD_SIE_WINDOW_COVERING_SIE014_MODEID      "SIE014"   // 二路窗帘电机
#define GW_TRD_SIE_WINDOW_COVERING_SIE014_PID         "9i55zbta"   // 二路窗帘电机

//dpid 
#define SIE_WINDOW_COVERING_DP_NUM             5
#define DPID_SIE_WINDOW_COVERING_CONTROL_1                1  // 设备控制, rw, {"range":["open","stop","close"],"type":"enum"}
#define DPID_SIE_WINDOW_COVERING_CONTROL_2                4  // 设备控制, rw, {"range":["open","stop","close"],"type":"enum"}
#define DPID_SIE_WINDOW_COVERING_CUR_CALIBRATION_1        3  // 行程校准,rw,{"range":["start","end"],"type":"enum"}
#define DPID_SIE_WINDOW_COVERING_CUR_CALIBRATION_2        6  // 行程校准,rw,{"range":["start","end"],"type":"enum"}
#define DPID_SIE_WINDOW_COVERING_ELEC_MACH_MODE           11 // 电机模式,rw,{"range":["0","1"],"type":"enum"}
#define DPID_SIE_WINDOW_COVERING_ELEC_MACH_MODE_2         10 // 电机模式,rw,{"range":["0","1"],"type":"enum"}

/*******************************************************************************************/

/********************************      IAS类设备功能属性信息    *********************************/
//DeviceId define
#define DEVID_SIE_IAS_ZONE              DEVID_HA_IAS_ZONE   //IAS类，pir, 门磁
//TuyaDeviceId define
#define TY_DEVID_SIE_IAS_ZONE           0x01

#define GW_TRD_SIE_DOOR_CONTACT_DEV_TYPE         0x01
#define GW_TRD_SIE_DOOR_CONTACT_UDDD             (UDDD_TY_ZIGBEE_UPDATE_BIT | UDDD_TY_SLEPP_FLAG_BIT | 0x00000101)

#define GW_TRD_SIE_PIR_DEV_TYPE         0x02
#define GW_TRD_SIE_PIR_UDDD             (UDDD_TY_ZIGBEE_UPDATE_BIT | UDDD_TY_SLEPP_FLAG_BIT | 0x00000102)

#define IAS_ZONE_MAX_DP_NUM                     10
#define DPID_SIE_DOOR_CONTACT_STATE                     1   //门磁状态
#define DPID_SIE_DOOR_CONTACT_BATTERY_PERCENT           2   //电池电量
#define DPID_SIE_DOOR_CONTACT_TEMPER_ALARM              4   //防拆报警

#define DPID_SIE_PIR_STATE                     1   //门磁状态
#define DPID_SIE_PIR_BATTERY_PERCENT           4   //电池电量
#define DPID_SIE_PIR_TEMPER_ALARM              5   //防拆报警
#define DPID_SIE_PIR_NIGHT_JUDGEMENT           101 //夜晚判断

#define GW_TRD_SIE_IAS_ZONE_SIE011_MODEID      "SIE011"     // 门磁
#define GW_TRD_SIE_IAS_ZONE_SIE011_PID         "nd3yex1i"
#define GW_TRD_SIE_IAS_ZONE_SIE019_MODEID      "SIE019"     // 人体传感器（电池款） 
#define GW_TRD_SIE_IAS_ZONE_SIE019_PID         "j0hmkcqb"
#define GW_TRD_SIE_IAS_ZONE_SIE010_MODEID      "SIE010"     // 人体传感器（强电款）
#define GW_TRD_SIE_IAS_ZONE_SIE010_PID         "klfwaizw"



/********************************      人体传感器（强电款）设备功能属性信息    *********************************/

/********************************      人体传感器（电池款）设备功能属性信息    *********************************/







//TY_DEVID_SIE_ONOFF_SWITCH
#define GW_TRD_SIE_ONOFF_SWITCH_FULL_UDDD 0x0000020f

#endif //TUYA_GW_THIRD_PARTY_SIEMENS_SUPPORT
#endif // __TUYA_GW_TRD_GW_PARTY_DEF_SIEMENS_H__
