#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*******************************Tuya Ble List Queue Control*****************************************************/
#define ble_container_of(ptr, type, member) ({	\
    const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
    (type *)( (char *)__mptr - offsetof(type,member) );})

typedef struct dlist_elem_st ble_dlist_elem;

/* Double list element. */
struct dlist_elem_st {
	ble_dlist_elem *prev; /* Previous list element. */
    ble_dlist_elem *next; /* Next list element. */
};

/* Double list. */
typedef struct dlist_st {
	ble_dlist_elem head; /* List head. */
	ble_dlist_elem tail; /* List tail. */
}dev_list;

void ble_dev_list_init(dev_list *list);

ble_dlist_elem *ble_dev_list_begin(dev_list *list);

ble_dlist_elem *ble_dev_list_next(ble_dlist_elem *elem);

ble_dlist_elem *ble_dev_list_end(dev_list *list);

void ble_dev_list_push_front(dev_list *list, ble_dlist_elem *elem);

void ble_dev_list_push_back(dev_list *list, ble_dlist_elem *elem);

ble_dlist_elem *ble_dev_list_pop_front (dev_list *list);

ble_dlist_elem *ble_dev_list_pop_back (dev_list *list);

char ble_dev_list_empty(dev_list *list);

int ble_dev_list_size(dev_list *list);

ble_dlist_elem *ble_dev_list_remove(ble_dlist_elem *elem);