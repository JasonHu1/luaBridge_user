/**
 * @file tuya_gw_event_list.h
 * @author zhangyu
 * @brief gateway pubilc event list
 * 
 * @date 2021-02-04
 * @copyright Copyright (c) tuya.inc 2021
 */

#ifndef __TUYA_GW_EVENT_LIST_H__
#define __TUYA_GW_EVENT_LIST_H__

#include "tuya_cloud_types.h"

#ifdef __cplusplus
	extern "C" {
#endif //__cplusplus

/**
 * @note 事件名最长14个字节，不含\0
 *
 */

/*************** 网关控制事件 ***************/
/**
 * @brief 请求网关重启 <传递类型 NULL>
 *
 */
#define GW_EVT_CTL_REBOOT "ctl.reboot"

typedef enum __gw_ctl_reset_type_e{
    GW_CTL_RESET_TYPE_UNACTIVE = 0,     /**< 本地移除 */
    GW_CTL_RESET_TYPE_RESET_FACTORY,    /**< 本地恢复出厂 */
}GW_CTL_RESET_TYPE_E;
/**
 * @brief 请求网关重置 <传递类型 GW_CTL_RESET_TYPE_E*>
 *
 */
#define GW_EVT_CTL_RESET "ctl.reset"

typedef enum __gw_ctl_work_mode_e{
    GW_CTL_WORK_MODE_NORMAL = 0,    /**< 正常模式 */
    GW_CTL_WORK_MODE_ENGINEER,      /**< 工程模式 */
}GW_CTL_WORK_MODE_E;
/**
 * @brief 请求网关切换模式 <传递类型 GW_CTL_WORK_MODE_E*>
 *
 */
#define GW_EVT_CTL_WORK_MODE_CHAGE "ctl.mode"

/**
 * @brief 请求网关子设备添加操作 
 * <传递类型 UINT_T*, 允许配网时间(秒), 
 * 0:关闭配网 >255:长配网模式，需要手动关闭>
 *
 */
#define GW_EVT_CTL_DEVADD "ctl.dev-add"

/**
 * @brief 请求网关升级 <传递类型 FW_UG_S *>
 *
 */
#define GW_EVT_CTL_UPGRADE "ctl.upgrade"

/*************** 网关状态事件 ***************/
/**
 * @brief 网关初始化状态状态
 *
 */
typedef enum __gw_init_stat_e{
    GW_EVT_INIT_STAT_NORMAL_START = 0,  /**< 正常模式启动 */
    GW_EVT_INIT_STAT_ENGR_START,        /**< 工程模式启动 */
    GW_EVT_INIT_STAT_END,               /**< 初始化结束 */
}GW_INIT_STAT_E;
/**
 * @brief 系统初始化结束状态 <传递类型 GW_INIT_STAT_E>
 *
 */
#define GW_EVT_INIT_STAT "stat.init"

/**
 * @brief 服务器连接状态
 *
 */
typedef enum __gw_net_stat_e{
	GW_NET_STAT_CLOUD_UNKNOW = -1, /**< 已连接服务器 */
    GW_NET_STAT_CLOUD_DIS = 0,	/**< 未连接服务器 */
    GW_NET_STAT_CLOUD_CONN = 1, /**< 已连接服务器 */
}GW_NET_STAT_E;
/**
 * @brief 网关服务器连接状态推送事件 <传递类型 GW_NET_STAT_E*>
 * 
 */
#define GW_EVT_NET_STAT "stat.net"

/**
 * @brief 网关激活状态推送事件 <传递类型 GW_STATUS_E*>
 *
 */
#define GW_EVT_ACTIVE_STAT "stat.active"

/**
 * @brief 网关重置推送事件 <传递类型 GW_RESET_TYPE_E*>
 *
 */
#define GW_EVT_RESET_STAT "stat.reset"

/**
 * @brief 子设备允许添加状态
 *
 */
typedef struct __gw_evt_dev_add_permit_msg_s {
    BYTE_T  tp; /**< 添加类型 */
    BOOL_T  permit; /**< 是否允许添加 */
    UINT_T  timeout; /**< 添加时间 */
}GW_EVT_DEV_ADD_PERMIT_MSG_S;
/**
 * @brief 子设备添加状态推送事件 <传递类型 GW_EVT_DEV_ADD_PERMIT_MSG_S*>
 *
 */
#define GW_EVT_ADD_PERMIT_STAT "stat.permit"


/**
 * @brief 子设备操作类型
 *
 */
typedef enum __gw_evt_dev_opt_type_e{
	GW_EVT_DEV_OPT_TYPE_BIND = 0,   /**< 子设备绑定 */
    GW_EVT_DEV_OPT_TYPE_DEL_REMOTE, /**< 子设备APP删除 */
    GW_EVT_DEV_OPT_TYPE_DEL_LOCAL,  /**< 子设备本地删除，一般为通过同步设备列表时删除 */
}GW_EVT_DEV_OPT_TYPE_E;
/**
 * @brief 子设备操作状态
 *
 */
typedef struct __gw_evt_dev_opt_msg_s {
    CHAR_T* cid; /**< 子设备id */
    GW_EVT_DEV_OPT_TYPE_E type; /**< 操作类型 */
}GW_EVT_DEV_OPT_MSG_S;
/**
 * @brief 子设备操作状态推送事件 <传递类型 GW_EVT_DEV_OPT_MSG_S*>
 *
 */
#define GW_EVT_DEV_OPT_STAT "stat.sub-opt"

/*************** 子设备管理事件 ***************/
/**
 * @brief 通知子设备网络状态推送事件 <传递类型 GW_NET_STAT_E*>
 * 
 */
#define GW_EVT_SUB_NET_STAT "sub.net"

/**
 * @brief 数据清除类型
 *
 */
typedef enum __gw_data_clean_type_e{
    GW_SUB_CLEAN_TYPE_GW_UNBIND = 0x0,  /**< 网关解绑 */
    GW_SUB_CLEAN_TYPE_GW_RESET_FACTORY, /**< 网关恢复出厂 */
    GW_SUB_CLEAN_TYPE_GW_DATA_CLEAN,    /**< 网关数据清除(恢复出厂之后再入网会收到) */
}GW_SUB_DATA_CLEAN_TYPE_E;

/**
 * @brief 网关子设备数据清除事件 <传递类型 GW_SUB_DATA_CLEAN_TYPE_E>
 * 
 */
#define GW_EVT_SUB_DATA_CLEAN "sub.clean"

/**
 * @brief 子设备服务启动 <传递类型 GW_DATA_CLEAN_TYPE_E>
 *
 */
#define GW_EVT_SUB_RUN "sub.run"

/**
 * @brief 网关升级状态
 *
 */
typedef enum __gw_upgrade_stat_e{
    GW_UPGRADE_STAT_DOWNLOAD_START = 0,  /**< 开始下载升级文件 */
    GW_UPGRADE_STAT_DOWNLOAD_FINISH = 1,    /**< 升级文件下载完成待网关升级后重启 */
    GW_UPGRADE_STAT_UPGRADE_FINISH = 2,     /**< 网关升级完成 */
}GW_UPGRADE_STAT_E;
/**
 * @brief 网关升级状态 <传递类型 GW_UPGRADE_STAT_E>
 *
 */
#define GW_EVT_UPGRADE_STAT "upgrade.stat"

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //!__TUYA_GW_EVENT_LIST_H__
