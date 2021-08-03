/*
  Copyright (c) 2009 Dave Gamble

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef typt_cJSON__h
#define typt_cJSON__h

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdlib.h>

/* typt_cJSON Types: */
#define typt_cJSON_False 0
#define typt_cJSON_True 1
#define typt_cJSON_NULL 2
#define typt_cJSON_Number 3
#define typt_cJSON_String 4
#define typt_cJSON_Array 5
#define typt_cJSON_Object 6

#define typt_cJSON_IsReference 256

/* The typt_cJSON structure: */
typedef struct typt_cJSON {
    struct typt_cJSON *next,*prev;	/* next/prev allow you to walk array/object chains. Alternatively, use GetArraySize/GetArrayItem/GetObjectItem */
    struct typt_cJSON *child;		/* An array or object item will have a child pointer pointing to a chain of the items in the array/object. */

    int type;					/* The type of the item, as above. */

    char *valuestring;			/* The item's string, if type==typt_cJSON_String */
    int valueint;				/* The item's number, if type==typt_cJSON_Number */
    double valuedouble;			/* The item's number, if type==typt_cJSON_Number */

    char *string;				/* The item's name string, if this item is the child of, or is in the list of subitems of an object. */
} typt_cJSON;

typedef struct typt_cJSON_Hooks {
      void *(*malloc_fn)(size_t sz);
      void (*free_fn)(void *ptr);
} typt_cJSON_Hooks;

/* Supply malloc, realloc and free functions to typt_cJSON */
extern void typt_cJSON_InitHooks(typt_cJSON_Hooks* hooks);


/* Supply a block of JSON, and this returns a typt_cJSON object you can interrogate. Call typt_cJSON_Delete when finished. */
extern typt_cJSON *typt_cJSON_Parse(const char *value);
/* Render a typt_cJSON entity to text for transfer/storage. Free the char* when finished. */
extern char  *typt_cJSON_Print(typt_cJSON *item);
/* Render a typt_cJSON entity to text for transfer/storage without any formatting. Free the char* when finished. */
extern char  *typt_cJSON_PrintUnformatted(typt_cJSON *item);
extern void typt_cJSON_FreeBuffer(char *buffer);
/* Delete a typt_cJSON entity and all subentities. */
extern void   typt_cJSON_Delete(typt_cJSON *c);

/* Returns the number of items in an array (or object). */
extern int	  typt_cJSON_GetArraySize(typt_cJSON *array);
/* Retrieve item number "item" from array "array". Returns NULL if unsuccessful. */
extern typt_cJSON *typt_cJSON_GetArrayItem(typt_cJSON *array,int item);
/* Get item "string" from object. Case insensitive. */
extern typt_cJSON *typt_cJSON_GetObjectItem(typt_cJSON *object,const char *string);

/* For analysing failed parses. This returns a pointer to the parse error. You'll probably need to look a few chars back to make sense of it. Defined when typt_cJSON_Parse() returns 0. 0 when typt_cJSON_Parse() succeeds. */
extern const char *typt_cJSON_GetErrorPtr(void);

/* These calls create a typt_cJSON item of the appropriate type. */
extern typt_cJSON *typt_cJSON_CreateNull(void);
extern typt_cJSON *typt_cJSON_CreateTrue(void);
extern typt_cJSON *typt_cJSON_CreateFalse(void);
extern typt_cJSON *typt_cJSON_CreateBool(int b);
extern typt_cJSON *typt_cJSON_CreateNumber(double num);
extern typt_cJSON *typt_cJSON_CreateString(const char *string);
extern typt_cJSON *typt_cJSON_CreateArray(void);
extern typt_cJSON *typt_cJSON_CreateObject(void);

/* These utilities create an Array of count items. */
extern typt_cJSON *typt_cJSON_CreateIntArray(const int *numbers,int count);
extern typt_cJSON *typt_cJSON_CreateFloatArray(const float *numbers,int count);
extern typt_cJSON *typt_cJSON_CreateDoubleArray(const double *numbers,int count);
extern typt_cJSON *typt_cJSON_CreateStringArray(const char **strings,int count);

/* Append item to the specified array/object. */
extern void typt_cJSON_AddItemToArray(typt_cJSON *array, typt_cJSON *item);
extern void	typt_cJSON_AddItemToObject(typt_cJSON *object,const char *string,typt_cJSON *item);
/* Append reference to item to the specified array/object. Use this when you want to add an existing typt_cJSON to a new typt_cJSON, but don't want to corrupt your existing typt_cJSON. */
extern void typt_cJSON_AddItemReferenceToArray(typt_cJSON *array, typt_cJSON *item);
extern void	typt_cJSON_AddItemReferenceToObject(typt_cJSON *object,const char *string,typt_cJSON *item);

/* Remove/Detatch items from Arrays/Objects. */
extern typt_cJSON *typt_cJSON_DetachItemFromArray(typt_cJSON *array,int which);
extern void   typt_cJSON_DeleteItemFromArray(typt_cJSON *array,int which);
extern typt_cJSON *typt_cJSON_DetachItemFromObject(typt_cJSON *object,const char *string);
extern void   typt_cJSON_DeleteItemFromObject(typt_cJSON *object,const char *string);

/* Update array items. */
extern void typt_cJSON_ReplaceItemInArray(typt_cJSON *array,int which,typt_cJSON *newitem);
extern void typt_cJSON_ReplaceItemInObject(typt_cJSON *object,const char *string,typt_cJSON *newitem);

/* Duplicate a typt_cJSON item */
extern typt_cJSON *typt_cJSON_Duplicate(typt_cJSON *item,int recurse);
/* Duplicate will create a new, identical typt_cJSON item to the one you pass, in new memory that will
need to be released. With recurse!=0, it will duplicate any children connected to the item.
The item->next and ->prev pointers are always zero on return from Duplicate. */

/* ParseWithOpts allows you to require (and check) that the JSON is null terminated, and to retrieve the pointer to the final byte parsed. */
extern typt_cJSON *typt_cJSON_ParseWithOpts(const char *value,const char **return_parse_end,int require_null_terminated);

extern void typt_cJSON_Minify(char *json);

/* Macros for creating things quickly. */
#define typt_cJSON_AddNullToObject(object,name)		typt_cJSON_AddItemToObject(object, name, typt_cJSON_CreateNull())
#define typt_cJSON_AddTrueToObject(object,name)		typt_cJSON_AddItemToObject(object, name, typt_cJSON_CreateTrue())
#define typt_cJSON_AddFalseToObject(object,name)		typt_cJSON_AddItemToObject(object, name, typt_cJSON_CreateFalse())
#define typt_cJSON_AddBoolToObject(object,name,b)     typt_cJSON_AddItemToObject(object, name, typt_cJSON_CreateBool(b))
#define typt_cJSON_AddNumberToObject(object,name,n)	typt_cJSON_AddItemToObject(object, name, typt_cJSON_CreateNumber(n))
#define typt_cJSON_AddStringToObject(object,name,s)	typt_cJSON_AddItemToObject(object, name, typt_cJSON_CreateString(s))

/* When assigning an integer value, it needs to be propagated to valuedouble too. */
#define typt_cJSON_SetIntValue(object,val)			((object)?(object)->valueint=(object)->valuedouble=(val):(val))

/* Macro for iterating over an array */
#define typt_cJSON_ArrayForEach(pos, head)            for(pos = (head)->child; pos != NULL; pos = pos->next)

#ifdef __cplusplus
}
#endif

#endif
