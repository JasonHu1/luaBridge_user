#ifndef _GW_EZ_LIST_H
    #define _GW_EZ_LIST_H

#include "tuya_cloud_types.h"

#ifdef __cplusplus
    extern "C" {
#endif

typedef void* GW_EZ_LIST_ID;

//value_in的入参是gw_ez_list_insert_begin 的 node
typedef VOID (*LIST_DATA_FREE)(VOID *node);


//node为insert的参数，
// b_del 标识是否删除该节点，默认是false, 如果删除该节点，内存由调用者释放
//当返回非OPRT_OK时，停止遍历，此时gw_ez_list_traversal_all返回该错误码
typedef OPERATE_RET (*GW_LIST_TRAVERSAL_CB)(VOID *param, IN VOID *node, OUT BOOL_T* b_del);


typedef struct {
	LIST_DATA_FREE func_free;	//当内部删除节点时，释放用户保存的节点
} GW_LIST_CREATE_PARAM;


OPERATE_RET gw_ez_list_create(IN GW_LIST_CREATE_PARAM *create_param,OUT GW_EZ_LIST_ID *list_id);

//读取第一个元素，然后删除节点，需要调用者释放 node_out
OPERATE_RET gw_ez_list_pop_begin(GW_EZ_LIST_ID list_id, OUT VOID **node_out);

//读取最后一个元素，然后删除节点，需要调用者释放 node_out
OPERATE_RET gw_ez_list_pop_end(GW_EZ_LIST_ID list_id, OUT VOID **node_out);

//内部仅仅保存node的地址，插入到链表头
OPERATE_RET gw_ez_list_insert_begin(GW_EZ_LIST_ID list_id, IN VOID *node);

//内部仅仅保存node的地址，插入到链表尾部
OPERATE_RET gw_ez_list_insert_end(GW_EZ_LIST_ID list_id, IN VOID *node);


//删除所有元素, list_id依旧有效
OPERATE_RET gw_ez_list_remove_all(GW_EZ_LIST_ID list_id);

OPERATE_RET gw_ez_list_traversal_all(GW_EZ_LIST_ID list_id, GW_LIST_TRAVERSAL_CB cb, VOID *param);

OPERATE_RET gw_ez_list_get_num(GW_EZ_LIST_ID list_id, OUT INT_T *num_out);

//删除所有元素并且删除list   ， list_id失效
OPERATE_RET gw_ez_list_destroy(GW_EZ_LIST_ID list_id);


#ifdef __cplusplus
}
#endif
#endif

