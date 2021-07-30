SDK产物介绍
-----------  

```  
.
├── build_app.sh   # 编译脚本
├── CHANGELOG.md   # 版本变更信息
├── demos          # 示例代码
└── sdk
    ├── include    # SDK头文件
    └── lib        # SDK库文件
```  

快速编译  
--------  

运行 `./build_app.sh demos/demo_gw demo_gw 1.0.0`，将编译出来的应用以及SDK库文件拷贝到目标系统，编译产生的应用位于 `output` 目录下。  


关于 demo 说明

目前 demo 目录下有：
```c
demo_dev  demo_gw  demo_pegasus  demo_router  demo_rtl8197f  demo_z3
```

* demo_gw       网关 DP 示例。  
* demo_dev      网关联网 SDK 例子。  
* demo_pegasus  居于无感配网的网关 SDK 例子。  
* demo_router   具有路由器功能的网关 SDK 例子。 
* demo_z3       扩展涂鸦 ZigBee SDK 例子, 同时用户可以接入自有子设备的例子。  
* demo_rtl8197f rtl8197平台有线+无线接口适配，网关例子。  
* demo_gw_eng   扩展涂鸦 ZigBee SDK 例子，具有工程施工以及恢复功能。  

注意的是：用户可以复合网关SDK类型，比如扩展 ZigBee + 路由器功能。
需要在配置文件中新增对应的选项。在 user_iot_initf.c 中增加相应功能的初始化即可。
