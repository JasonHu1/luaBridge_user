
#include "LuaScriptEngine.h"
#include <stdio.h>
#include "luademo.h"
#include "tuya_proto.h"
#include "third_format.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

using namespace iot::lua;



#ifdef __cplusplus
extern "C" {
#endif

int message_encode(void){
    TuyaProto dp_data;
    size_t rbytes=0,fsize=0;
    char *pbuf=NULL;
    dp_data.set_cmd_tp(0x30);


    Cdp msg1;
    msg1.dpid =0x30;
    
    ThirdFormat tt;
    LuaScriptEngine engine;
    FILE *fp = fopen("../../test.lua", "rw");
    std::cout<<"fp:"<<fp<<std::endl;
    printf("fp:%d\r\n",fp);
    if(fp){
        fseek(fp, 0, SEEK_END);
        fsize = ftell(fp);
        fseek(fp, 0,SEEK_SET);
        pbuf = (char *)malloc(fsize);
        rbytes = fread (pbuf,1,fsize,fp);
        if(rbytes){
            printf("%s",pbuf);
            engine.execute(pbuf, "encode", &dp_data,&tt);
            printf("printf in c++:\r\n");
            printf("tt.retVal=%d",tt.retVal);
            tt.printpayload();\
            printf("tt.name=%s\r\n",tt.name.c_str());
        }
    }else{
        return -1;
    }
    
    return 0;
}
#ifdef __cplusplus
}
#endif