/***********************************************************
*  Copy from File: app_agent_engr.h
*  Author: nzy
*  Date: 20201224
***********************************************************/
#ifndef _APP_AGENT_ENGR_H
#define _APP_AGENT_ENGR_H


#ifdef __cplusplus
    extern "C" {
#endif

#ifdef  __APP_AGENT_ENGR_GLOBALS
    #define __APP_AGENT_ENGR_EXT
#else
    #define __APP_AGENT_ENGR_EXT extern
#endif

#define FRM_GRP_OPER_ENGR 0xd0
#define FRM_GRP_CMD 0xd1
// engineering cmd
#define FRM_GET_SUB_DEV_LINE_STAT 0xe0
#define UPDATE_SUB_DEV_LINE_STAT 0xe1
#define FROM_SCENE_LINKAGE 0xe2
#define RPT_GW_UNACTIVE 0xe3
#define RPT_SUB_DEV_UNBIND 0xe4
#define FROM_SUB_DEV_UPGRADE_INFO 0xe5
#define FROM_DEV_UPGRADE 0xe6
#define RPT_DOWNLOAD_FIRMWARE 0xe7
#define RPT_UPGRADE_PROGRESS 0xe8
#define RPT_UPGRADE_VERSION 0xe9
#define FRM_USER_BIND_REQ_ENGR 0xf0
#define FRM_GET_SUB_DEV_LIST_ENGR 0Xf1
#define FRM_DEL_SUB_DEV_ENGR 0xf2
#define RPT_ADD_SUB_DEV_ENGR 0xf3
#define FRM_SCE_OPER_ENGR 0xf4
#define FRM_DOWNLOAD_CLOUD_CFG_ENGR 0xf5
#define FRM_DOWNLOAD_APP_CFG_ENGR 0xf6
#define FRM_EXPORT_APP_CFG_ENGR 0xf7
#define FRM_SCE_PANEL_CMD 0xf8
#define FRM_GW_RESET 0xf9
#define FRM_CHK_SOFT_VER 0xfa
#define FRM_UPDATE_GW_SOFT 0xfb
#define FRM_SET_CHANNEL 0xfc
#define FRM_GET_CHANNEL 0xfd
#define FRM_GET_TUYA_LOG 0xfe
//局域网扩展协议
#define FRM_LAN_EXTRA_PROTOCOL_ENGR 0x22

#ifdef __cplusplus
}
#endif
#endif

