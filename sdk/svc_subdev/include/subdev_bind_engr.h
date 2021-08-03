#ifndef __SUBDEV_BIND_ENGR_H__
#define __SUBDEV_BIND_ENGR_H__



#include "tuya_cloud_types.h"
#include "tuya_cloud_com_defs.h"

#include "uni_hlist.h"
#include "tuya_hal_mutex.h"
#include "hashmap.h"


#ifdef __cplusplus
    extern "C" {
#endif

typedef OPERATE_RET (*ENGR_GW_GET_SCHEMA)(IN CONST CHAR_T *product_key, OUT ty_cJSON **pp_result);

typedef OPERATE_RET (*ENGR_GW_UPGRADE_DEV_NOTIFY)(IN CONST CHAR_T *devid,\
                             IN CONST FW_UG_S *fw,\
                             IN CONST GET_FILE_DATA_CB get_file_cb,\
                             IN PVOID_T pri_data,\
                             IN CONST UPGRADE_NOTIFY_CB upgrd_nofity_cb, \
                             IN CONST BOOL_T upload_upgrade_percent, \
                             IN CONST UINT_T download_buf_size
                             );

typedef OPERATE_RET (*ENGR_GW_SUBDEV_UPDATE)(IN CONST CHAR_T *id,IN CONST CHAR_T *ver, IN CONST GW_ATTACH_ATTR_T *attr,IN CONST UINT_T attr_num, IN CONST BOOL_T is_force);


typedef struct{
    ENGR_GW_GET_SCHEMA engr_gw_get_schema;
    ENGR_GW_UPGRADE_DEV_NOTIFY engr_gw_upgrade_ntf;
    ENGR_GW_SUBDEV_UPDATE engr_gw_subdev_update;
} SUBDEV_BIND_ENGR_CB_S;

OPERATE_RET engr_gw_cntl_init_local(OUT UINT_T *channel);

OPERATE_RET engineer_subdev_cbs_init(IN SUBDEV_BIND_ENGR_CB_S *engr_cbs);

SUBDEV_BIND_ENGR_CB_S *engineer_subdev_cbs_get();


#ifdef __cplusplus
} // extern "C"
#endif

#endif 

