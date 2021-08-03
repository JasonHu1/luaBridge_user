#ifndef __LOG_SEQ_HTTP_H
#define __LOG_SEQ_HTTP_H

#include "log_seq.h"


// 定义了日志序对象为 “sub_dev”，包含了此头文件的文件，使用日志序会记录到 “http” 日志序模块
#define LOGSEQ_OBJ "sub_dev"

// 定义了sub_dev的详细日志序信息，包括点的序号，以及描述信息，通过点、类型、值、位置，可以问题发生的位置
typedef enum {
    LOGSEQ_GW_SUB_DEV_ID            = 1,    // 类型：字符串，值：子设备mac，位置：NULL
    LOGSEQ_GW_SUB_DEV_ERRTIME       = 2,    // 类型：字符串，值：子设备错误产生时间，位置：NULL
    LOGSEQ_GW_SUB_DEV_ERRCODE       = 3,    // 类型：十进制数值型，值：子设备上报错误值，位置：NULL

}GW_SUB_DEV_LOG_SEQ_E;

#endif
