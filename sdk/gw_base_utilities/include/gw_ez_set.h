#ifndef _GW_EZ_SET_H
    #define _GW_EZ_SET_H

#include "tuya_cloud_types.h"

#ifdef __cplusplus
    extern "C" {
#endif

typedef void* GW_EZ_SET_ID;


//遍历过程中可以调用 gw_ez_set_remove删除节点，这时删除后的key可以继续访问
typedef OPERATE_RET (*GW_SET_TRAVERSAL_CB)(VOID *param, IN CONST CHAR_T *key);

OPERATE_RET gw_ez_set_create(OUT GW_EZ_SET_ID *set_id);

//key 存在时 返回OPRT_OK 
OPERATE_RET gw_ez_set_get(GW_EZ_SET_ID set_id, IN CONST CHAR_T *key);

//key在内部会保存一份
//相同的key只存储一个
OPERATE_RET gw_ez_set_put(GW_EZ_SET_ID set_id, IN CONST CHAR_T *key);

//删除key
OPERATE_RET gw_ez_set_remove(GW_EZ_SET_ID set_id, IN CONST CHAR_T *key);

//删除所有元素，不删除set set_id依然有效
OPERATE_RET gw_ez_set_remove_all(GW_EZ_SET_ID set_id);

OPERATE_RET gw_ez_set_traversal_all(GW_EZ_SET_ID set_id, GW_SET_TRAVERSAL_CB cb, VOID *param);

OPERATE_RET gw_ez_set_get_num(GW_EZ_SET_ID set_id, OUT INT_T *num_out);

//删除所有元素并且删除set   ， set_id 失效
OPERATE_RET gw_ez_set_destroy(GW_EZ_SET_ID set_id);

//新创建set,内容复制老的
OPERATE_RET gw_ez_set_copy(GW_EZ_SET_ID old_set_id, OUT GW_EZ_SET_ID *new_set_id);

//将src中的key，合并到 dst中，相同的key会过滤掉
OPERATE_RET gw_ez_set_merge(GW_EZ_SET_ID src_set_id, GW_EZ_SET_ID dst_set_id);


//获取所有的key，使用spe字符分割，all_key需要调用者释放
OPERATE_RET gw_ez_set_save(GW_EZ_SET_ID set_id, IN CHAR_T sep, OUT CHAR_T **all_key);

//gw_ez_set_save的反操作
OPERATE_RET gw_ez_set_load(GW_EZ_SET_ID set_id, IN CHAR_T sep, IN CONST CHAR_T *all_key);



#ifdef __cplusplus
}
#endif
#endif

