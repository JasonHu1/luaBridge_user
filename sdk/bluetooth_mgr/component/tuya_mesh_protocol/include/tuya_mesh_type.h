/*
 * tuya_mesh_type.h
 *
 *  Created on: 2020-05-18
 *      Author: joey
 */
#ifndef _TUYA_MESH_TYPE_H
#define _TUYA_MESH_TYPE_H
#include  <stdint.h>
#include  <stdio.h>
#include  <string.h>
#include "tuya_cloud_types.h"

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE (!FALSE)
#endif

#ifndef false
#define false FALSE
#endif

#ifndef true
#define true  TRUE
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef PACKED
#define PACKED __attribute__ ((packed))
#endif


#endif /* _TUYA_MESH_TYPE_H */
