#ifndef __CRASH_DUMP_H__
#define __CRASH_DUMP_H__


#ifdef __cplusplus
extern "C" {
#endif

typedef void (*CRASH_CALLBACK)(int signo);

void crash_dump_init(const char* crash_dump_tmp_file_path);

void register_crash_dump_cb(CRASH_CALLBACK cb);

//设置打印栈信息的长度，默认是3K
void crash_dump_set_stack_len(unsigned int len);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // __CRASH_DUMP_H__

