#ifndef _LIST_OP_H
#define _LIST_OP_H

#ifdef __cplusplus
extern "C" {
#endif

#define IN 
#define OUT

typedef struct list_head 
{
    struct list_head *next, *prev;
}TYPT_LIST_HEAD,*TYPT_P_LIST_HEAD;

#define TYPT_LIST_HEAD_INIT(name) { &(name), &(name) }

// 定义LIST并静态初始化一个空的通用双向链表
#define TYPT_LIST_HEAD(name) \
TYPT_LIST_HEAD name = TYPT_LIST_HEAD_INIT(name)

// 动态初始化一个空的通用双向链表
#define TYPT_INIT_LIST_HEAD(ptr) do { \
(ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

// 动态分配一个包含通用双向链表的结构体
#define TYPT_NEW_LIST_NODE(type, node) \
{\
    node = (type *)malloc(sizeof(type));\
}

// 释放链表中的所有节点，使该链表成为空链表
#define TYPT_FREE_LIST(type, p, list_name)\
{\
    type *posnode;\
    while(!typt_list_empty(&(p)->list_name)) {\
    posnode = typt_list_entry((&(p)->list_name)->next, type, list_name);\
    typt_list_del((&(p)->list_name)->next);\
    free(posnode);\
    }\
}

// 获取链表中第一个节点地址(该地址指向其主结构)
#define TYPT_GetFirstNode(type,p,list_name,pGetNode)\
{\
    pGetNode = NULL;\
    while(!typt_list_empty(&(p)->list_name)){\
    pGetNode = typt_list_entry((&(p)->list_name)->next, type, list_name);\
    break;\
    }\
}

// 从链中删除某节点，并释放该节点所在结构占用的内存
#define TYPT_DeleteNodeAndFree(pDelNode,list_name)\
{\
    typt_list_del(&(pDelNode->list_name));\
    free(pDelNode);\
}

// 仅从链中删除某节点
#define TYPT_DeleteNode(pDelNode,list_name)\
{\
    typt_list_del(&(pDelNode->list_name));\
}

// 释放链表内存
#define TYPT_FreeNode(pDelNode)\
{\
    free(pDelNode);\
}


// 获取包含该通用链表节点的结构体的首址
#define typt_list_entry(ptr, type, member) \
((type *)((char *)(ptr)-(size_t)(&((type *)0)->member)))

// 遍历链表
#define typt_list_for_each(pos, head) \
for (pos = (head)->next; pos != (head); pos = pos->next)

/***********************************************************
*************************variable define********************
***********************************************************/

/***********************************************************
*************************function define********************
***********************************************************/

int typt_list_empty(IN const TYPT_P_LIST_HEAD pHead);


void typt_list_add(IN const TYPT_P_LIST_HEAD pNew, IN const TYPT_P_LIST_HEAD pHead);


void typt_list_add_tail(IN const TYPT_P_LIST_HEAD pNew, IN const TYPT_P_LIST_HEAD pHead);

void typt_list_splice(IN const TYPT_P_LIST_HEAD pList, IN const TYPT_P_LIST_HEAD pHead);

void typt_list_del(IN const TYPT_P_LIST_HEAD pEntry);

void typt_list_del_init(IN const TYPT_P_LIST_HEAD pEntry);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

