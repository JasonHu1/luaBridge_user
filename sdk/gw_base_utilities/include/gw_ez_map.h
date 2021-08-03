#ifndef _GW_EZ_MAP_H
    #define _GW_EZ_MAP_H

#include "tuya_cloud_types.h"

#ifdef __cplusplus
    extern "C" {
#endif


typedef void* GW_EZ_MAP_ID;


//value_in的入参是gw_ez_map_put的value_in
typedef VOID (*MAP_DATA_FREE)(VOID *value_in);



//当返回非OPRT_OK时，停止遍历，此时 gw_ez_map_traversal_all 返回该错误码
//遍历过程中可以调用 gw_ez_map_remove删除节点，这时删除后的value地址不能再访问，key可以访问
typedef OPERATE_RET (*GW_MAP_TRAVERSAL_CB)(VOID *param, IN CONST CHAR_T *key,  VOID *value);



typedef struct {
	MAP_DATA_FREE func_free;	
} GW_MAP_CREATE_PARAM;

OPERATE_RET gw_ez_map_create(IN GW_MAP_CREATE_PARAM *create_param, OUT GW_EZ_MAP_ID *map_id);

//value_out 是insert输入的value_in参数
OPERATE_RET gw_ez_map_get(GW_EZ_MAP_ID map_id, IN CONST CHAR_T *key, OUT VOID **value_out);

//key在内部会保存一份,相同的key覆盖value
//value_in 需要调用者Malloc 申请 gw_ez_map_remove或gw_map_remove_all时，会调用MAP_DATA_FREE释放
OPERATE_RET gw_ez_map_put(GW_EZ_MAP_ID map_id, IN CONST CHAR_T *key, IN VOID *value_in);

//value会调用 MAP_DATA_FREE 释放
OPERATE_RET gw_ez_map_remove(GW_EZ_MAP_ID map_id, IN CONST CHAR_T *key);

//删除所有元素，不删除 map map_id 依然有效
OPERATE_RET gw_ez_map_remove_all(GW_EZ_MAP_ID map_id);

//将节点内容返回到value_out然后删除（不释放value），需要调用者释放value_out
OPERATE_RET gw_ez_map_pop(GW_EZ_MAP_ID map_id, IN CONST CHAR_T *key, OUT VOID **value_out);


OPERATE_RET gw_ez_map_traversal_all(GW_EZ_MAP_ID map_id, GW_MAP_TRAVERSAL_CB cb, VOID *param);

OPERATE_RET gw_ez_map_get_num(GW_EZ_MAP_ID map_id, OUT INT_T *num_out);

//删除所有元素并且删除map， map_id 失效
OPERATE_RET gw_ez_map_destroy(GW_EZ_MAP_ID map_id);


#ifdef __cplusplus
}
#endif
#endif

