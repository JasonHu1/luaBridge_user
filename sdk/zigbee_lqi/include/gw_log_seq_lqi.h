#ifndef __GW_LOG_SEQ_LQI_H__
#define __GW_LOG_SEQ_LQI_H__

#include "log_seq.h"

// 定义了日志序对象为 “z3_lqi”，包含了此头文件的文件，使用日志序会记录到 “z3_lqi” 日志序模块
#define LOGSEQ_OBJ "z3_lqi"

// 定义了z3_lqi的详细日志序信息，包括点的序号，以及描述信息，通过点、类型、值、位置，可以问题发生的位置
typedef enum {
    LOGSEQ_GW_LQI_MAX,
}GW_LQI_LOG_SEQ_E;

#endif
