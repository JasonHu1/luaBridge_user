
#include "LuaScriptEngine.h"
#include <stdio.h>
#include "luademo.h"
#include "Json.h"
#include "Message.h"
#include "tuya_proto.h"
#include "third_format.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "tuya_cloud_com_defs.h"
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

    TuyaProto msg2;
    msg2.set_cmd_tp(0x31);
    
    ThirdFormat tt;
    LuaScriptEngine engine;
    FILE *fp = fopen("../../test.lua", "r");
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
        }
    }else{
        return -1;
    }
    
    return 0;
}
#ifdef __cplusplus
}
#endif