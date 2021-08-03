
#include "LuaScriptEngine.h"
#include <stdio.h>
#include "luademo.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "tuya_cloud_com_defs.h"
#ifdef __cplusplus
}
#endif

using namespace iot::lua;

int message_encode(void){
    TY_OBJ_DP_S dp_data;
    size_t rbytes=0,fsize=0;
    char *pbuf=NULL;
    dp_data.dpid = 1;
    dp_data.type = 2;
    dp_data.value.dp_value = 3;
    dp_data.time_stamp = 0x55667788;

    protoFormat_t tt;
    LuaScriptEngine engine;
    FILE *fp = fopen("test.lua", "r");
    if(fp){
        fseek(fp, 0, SEEK_END);
        fsize = ftell(fp);
        fseek(fp, 0,SEEK_SET);
        pbuf = (char *)malloc(fsize);
        rbytes = fread (pbuf,1,fsize,fp);
        if(rbytes){
            printf("%s/r/n",pbuf);
            engine.execute(pbuf, "encode", &dp_data, &tt);
        }
    }else{
        return -1;
    }
    
    return 0;
}

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif