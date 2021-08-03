#ifndef __TUYA_GW_TRD_GW_PARTY_DEF_SCHNEIDER_H__
#define __TUYA_GW_TRD_GW_PARTY_DEF_SCHNEIDER_H__
#include "tuya_gw_trd_party_cfg.h"
#include "tuya_z3_base.h"

#if defined (TUYA_GW_THIRD_PARTY_SCHNEIDER_SUPPORT) && (1 == TUYA_GW_THIRD_PARTY_SCHNEIDER_SUPPORT)

#define SND_TEST_PID

/************************      智能开关、智能插座、辅控开关功能属性信息    ************************/
//DeviceId define
#define DEVID_SND_ONOFF_LIGHT               DEVID_HA_ONOF_LIGHT         // 0x0100 -> 0x01, 开关
#define TY_DEVID_SND_ONOFF_LIGHT            0x01                        // 智能开关

#define DEVID_SND_SCENE_SELECTOR            0x0006
#define TY_DEVID_SND_SCENE_SELECTOR         0x02

#define DEVID_SND_IAS_ZONE                  0x0402
#define TY_DEVID_SND_IAS_ZONE               0x03

#define DEVID_SND_TEMPERATURE_SENSOR        0x0302
#define TY_DEVID_SND_TEMPERATURE_SENSOR     0x04

#define DEVID_SND_CURTAIN_SWITCH            0x0003
#define TY_DEVID_SND_CURTAIN_SWITCH         0x05

#define DEVID_SND_DIMMER_SWITCH             0x0101
#define TY_DEVID_SND_DIMMER_SWITCH          0x06

#define DEVID_SND_REMOTE_CONTROL            0x0006
#define TY_DEVID_SND_REMOTE_CONTROL         0x07

//dpid 
#define DPID_SND_ONOFF_LIGHT_1_ONOFF          1
#define DPID_SND_ONOFF_LIGHT_2_ONOFF          2
#define DPID_SND_ONOFF_LIGHT_3_ONOFF          3

#define GW_TRD_SND_ONOFF_LIGHT_UDDD           0x02000101
#define GW_TRD_SND_ONOFF_LIGHT_UDDD_TYPE2     0x02000102
#define GW_TRD_SND_ONOFF_LIGHT_DEV_TYPE        0x01
#define GW_TRD_SND_ONOFF_LIGHT_DEV_TYPE2       0x02
#define GW_TRD_SND_ONOFF_LIGHT_DEV_TYPE3       0x03

#define GW_TRD_SND_ONOFF_LIGHT_ONE_MODEID       "E8331SRY800ZB"   // 一路智能开关
#define GW_TRD_SND_ONOFF_LIGHT_TWO_MODEID       "E8332SRY800ZB"   // 二路智能开关
#define GW_TRD_SND_ONOFF_LIGHT_TRE_MODEID       "E8333SRY800ZB"   // 三路智能开关
//#define GW_TRD_SND_ONOFF_LIGHT_ONE_MICRO_MODEID "CCT5011-0001_AS"   // 一路智能开关方块
#define GW_TRD_SND_ONOFF_LIGHT_ONE_MICRO_MODEID "PUCK/SWITCH/1"
#define GW_TRD_SND_ONOFF_LIGHT_ONE_LCONIC_MODEID "CH10AX/SWITCH/1" //绿方块

#ifdef SND_TEST_PID
#define GW_TRD_SND_ONOFF_LIGHT_ONE_PID          "ouy7hulq"
#define GW_TRD_SND_ONOFF_LIGHT_TWO_PID          "cnq6tb6p"
#define GW_TRD_SND_ONOFF_LIGHT_TRE_PID          "ewdfcxwu"
#define GW_TRD_SND_ONOFF_LIGHT_ONE_MICRO_PID    "h8btklfd"
#define GW_TRD_SND_ONOFF_LIGHT_ONE_LCONIC_PID   "tzmnkttx"
#else
#define GW_TRD_SND_ONOFF_LIGHT_ONE_PID          "efjqfavn"
#define GW_TRD_SND_ONOFF_LIGHT_TWO_PID          "hpdoxjcp"
#define GW_TRD_SND_ONOFF_LIGHT_TRE_PID          "gapi6d7w"
#define GW_TRD_SND_ONOFF_LIGHT_ONE_MICRO_PID    "avcpmrz7"
#define GW_TRD_SND_ONOFF_LIGHT_ONE_LCONIC_PID   "xik4z550"
#endif

//TY_DEVID_SND_ONOFF_SWITCH
#define GW_TRD_SND_ONOFF_SWITCH_FULL_UDDD 0x0000020f

//IAS ZONE
#define GW_TRD_SND_ISA_ZONE_DOOR_MODEID         "CCT591011_AS"  //门磁
#define GW_TRD_SND_ISA_ZONE_PIR_MODEID          "CCT595011_AS"  //人体运动
#define GW_TRD_SND_ISA_ZONE_WATER_MODEID        "CCT592011_AS"  //水浸
#define GW_TRD_SND_ISA_ZONE_GAS_MODEID          "CCT597011_C1"  //燃气
#define GW_TRD_SND_ISA_ZONE_SMOKE_MODEID        "CCT596011_C1"  //烟雾


#ifdef SND_TEST_PID
#define GW_TRD_SND_ISA_ZONE_DOOR_PID            "hoe95iu0"
#define GW_TRD_SND_ISA_ZONE_PIR_PID             "b1nsarv4"
#define GW_TRD_SND_ISA_ZONE_WATER_PID           "1vpxjvqj"
#define GW_TRD_SND_ISA_ZONE_GAS_PID             "4lishogj"
#define GW_TRD_SND_ISA_ZONE_SMOKE_PID           "cymqlhkd"
#else
#define GW_TRD_SND_ISA_ZONE_DOOR_PID            "jdknwriz"
#define GW_TRD_SND_ISA_ZONE_PIR_PID             "pmt9jkfw"
#define GW_TRD_SND_ISA_ZONE_WATER_PID           "0r1az3ld"
#define GW_TRD_SND_ISA_ZONE_GAS_PID             "4lishogj"
#define GW_TRD_SND_ISA_ZONE_SMOKE_PID           "cymqlhkd"
#endif

#define SND_IAS_ZONE_TYPE_DOOR  0x01
#define SND_IAS_ZONE_TYPE_PIR   0x02
#define SND_IAS_ZONE_TYPE_WATER 0x03
#define SND_IAS_ZONE_TYPE_GAS   0x04
#define SND_IAS_ZONE_TYPE_SMOKE 0x05

//TEMPERATURE SENSOR
#define GW_TRD_SND_TEMPERATURE_SENSOR_MODEID    "CCT593011_AS" //温湿度

#ifdef SND_TEST_PID
#define GW_TRD_SND_TEMPERATURE_SENSOR_PID       "xg5tnokv"
#else
#define GW_TRD_SND_TEMPERATURE_SENSOR_PID       "fent9g4p"
#endif

//DEVID_SND_CURTAIN_SWITCH
#define GW_TRD_SND_CURTAIN_SWITCH_ONE_MODEID    "E8331SCN200ZB" //1路窗帘开关
#define GW_TRD_SND_CURTAIN_SWITCH_TWO_MODEID    "E8332SCN300ZB" //2路窗帘开关


#ifdef SND_TEST_PID
#define GW_TRD_SND_CURTAIN_SWITCH_ONE_PID       "uwhvldcl" //test
#define GW_TRD_SND_CURTAIN_SWITCH_TWO_PID       "cwdvfl8s"
#else
#define GW_TRD_SND_CURTAIN_SWITCH_ONE_PID       "a9tu1kin"
#define GW_TRD_SND_CURTAIN_SWITCH_TWO_PID       "bdeckiza"
#endif

//TY_DEVID_SND_DIMMER_SWITCH
#define GW_TRD_SND_DIMMER_SWITCH_ONE_MODEID     "E8331DST300ZB" //1路调光开关
#define GW_TRD_SND_DIMMER_SWITCH_TWO_MODEID     "E8332DST350ZB" //2路调光开关
//#define GW_TRD_SND_DIMMER_SWITCH_MINI_MODEID    "CCT5010-0001_AS" //1路调光方块
#define GW_TRD_SND_DIMMER_SWITCH_MINI_MODEID      "PUCK/DIMMER/1" //1路调光方块
#define GW_TRD_SND_DIMMER_SWITCH_LCONIC_MODEID    "CH/DIMMER/1" //1路调光绿方块

#ifdef SND_TEST_PID
#define GW_TRD_SND_DIMMER_SWITCH_ONE_PID        "7uqxhipa"
#define GW_TRD_SND_DIMMER_SWITCH_TWO_PID        "r2vkapvs"
#define GW_TRD_SND_DIMMER_SWITCH_MINI_PID       "moexciiq"
#define GW_TRD_SND_DIMMER_SWITCH_LCONIC_PID     "vppxx51i"
#else
#define GW_TRD_SND_DIMMER_SWITCH_ONE_PID        "xxrehdbc"
#define GW_TRD_SND_DIMMER_SWITCH_TWO_PID        "pvvcfbsv"
#define GW_TRD_SND_DIMMER_SWITCH_MINI_PID       "bat2u3vq"
#define GW_TRD_SND_DIMMER_SWITCH_LCONIC_PID     "d2ncagua"
#endif

#define GW_TRD_SND_DIMMER_SWITCH_ONE_UDDD       0x00000601
#define GW_TRD_SND_DIMMER_SWITCH_TWO_UDDD       0x00000602
#define GW_TRD_SND_DIMMER_SWITCH_MINI_UDDD      0x0000060a
#define GW_TRD_SND_DIMMER_SWITCH_ONE_TYPE       0x01
#define GW_TRD_SND_DIMMER_SWITCH_TWO_TYPE       0x02
#define GW_TRD_SND_DIMMER_SWITCH_MINI_TYPE      0x0a
#define GW_TRD_SND_DIMMER_SWITCH_LCONIC_TYPE    0x0b

//TY_DEVID_SND_REMOTE_CONTROL
#define GW_TRD_SND_REMOTE_CONTROL_2key_MODEID    "E8332RWMZB" //2键无线场景
#define GW_TRD_SND_REMOTE_CONTROL_4key_MODEID    "E8334RWMZB" //4键无线场景

#ifdef SND_TEST_PID
#define GW_TRD_SND_REMOTE_CONTROL_2key_PID       "fhcsajfl"
#define GW_TRD_SND_REMOTE_CONTROL_4key_PID       "ni3vzpbi"
#else
#define GW_TRD_SND_REMOTE_CONTROL_2key_PID       "fhcsajfl"
#define GW_TRD_SND_REMOTE_CONTROL_4key_PID       "nxjcbami"
#endif

#endif //TUYA_GW_THIRD_PARTY_SCHNEIDER_SUPPORT
#endif // __TUYA_GW_TRD_GW_PARTY_DEF_SCHNEIDER_H__
