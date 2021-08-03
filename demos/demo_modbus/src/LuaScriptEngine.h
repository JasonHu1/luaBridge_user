

#ifndef __LUASCRIPTENGINE_H_
#define __LUASCRIPTENGINE_H_

#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <lua.hpp>
#include <mutex>


#include "LuaBridge.h"
#include "luademo.h"
//#include "ScriptBuffer.h"
#include "Message.h"
#include "Json.h"
#ifdef __cplusplus
extern "C" {
#endif
#include "tuya_cloud_com_defs.h"
#ifdef __cplusplus
}
#endif
//
//#include "../../Controllers/HaierController/inc/HaierController.h"
//#include "../../Controllers/HaierController/src/HaierCommand.h"
//#include "../../Controllers/ZigbeeController/src/ShuncomCommand.h"
//#include "../../Controllers/DusunZigbeeController/src/DusunCommand.h"
//
//#include "ScriptTools.h"

#define _log(x...) std::cout

namespace iot {
    namespace lua {

        class LuaScriptEngine {
        private:
            lua_State *L;

            /**
             * 执行线程锁
             */
            std::mutex mutexExecute;

        public:

            /*
             * 注册ScriptBuffer class for lua to use
             */
            void registerClass() {
                using namespace luabridge;

                getGlobalNamespace(L)
                        .beginNamespace("tuya")
                        .beginClass<Message>("Message")
                        .addProperty<string>("type", &Message::getType, &Message::setType)
                        .addProperty<string>("sno", &Message::getSno, &Message::setSno)
                        .addProperty<string>("command", &Message::getCommand, &Message::setCommand)
                        .addProperty<string>("attribute", &Message::getAttribute, &Message::setAttribute)
                        .addProperty<string>("mac", &Message::getMac, &Message::setMac)
                        .addData("data", &Message::data)
                        .addFunction("toJSON", &Message::toJSON)
                        .endClass()
                        .beginClass<Json>("Json")
                        .addFunction("toJSON", &Json::toJSON)
                        .addFunction("fstr", &Json::str)
                        .addFunction("fint", &Json::integer)
                        .addFunction("fbool", &Json::boolean)
                        .addFunction("fnumber", &Json::number)
                        .addFunction("fobj", &Json::fo)
                        .addFunction("flist", &Json::array)

                        .addFunction("fpstr", &Json::strp)
                        .addFunction("fpint", &Json::integerp)
                        .addFunction("fpbool", &Json::booleanp)
                        .addFunction("fpnumber", &Json::numberp)
                        .addFunction("fpobj", &Json::objp)
                        .addFunction("fplist", &Json::arrayp)

                        .addFunction("lstr", &Json::lstr)
                        .addFunction("lint", &Json::lint)
                        .addFunction("lbool", &Json::lbool)
                        .addFunction("lnumber", &Json::lnumber)
                        .addFunction("lobj", &Json::lobj)
                        .addFunction("llist", &Json::ll)

                        .addFunction("lpstr", &Json::lstrp)
                        .addFunction("lpint", &Json::lintp)
                        .addFunction("lpbool", &Json::lboolp)
                        .addFunction("lpnumber", &Json::lnumberp)
                        .addFunction("lpobj", &Json::lobjp)
                        .addFunction("lplist", &Json::llp)

                        .addFunction("setStr", &Json::setStr)
                        .addFunction("setInt", &Json::setInt)
                        .addFunction("setBool", &Json::setBool)
                        .addFunction("setNumber", &Json::setNumber)
                        .addFunction("vstr", &Json::vstr)
                        .addFunction("vint", &Json::vint)
                        .addFunction("vbool", &Json::vbool)
                        .addFunction("vnumber", &Json::vnumber)
                        .addFunction("lcount", &Json::lcount)
                        .addFunction("fcount", &Json::fcount)


                        .addFunction("find", &Json::find)
                        .addFunction("index", &Json::index)
                        .addFunction("moveToRoot", &Json::moveToRoot)
                        .addFunction("parent", &Json::parent)
                        .addFunction("clear", &Json::clear)
                        .endClass()

                .endNamespace();//.beginNamespace("tuya")
            }

            LuaScriptEngine() {
                L = luaL_newstate();
                luaL_openlibs(L);
                registerClass();
            }

            ~LuaScriptEngine() {
                if (L != nullptr) {
                    lua_close(L);
                }
            }

            bool compileScript(const char *script, const char *tag) {

                //LOCK L
                std::unique_lock<std::mutex> lock(mutexExecute);

                int error = luaL_loadbuffer(L, script, strlen(script), tag) || lua_pcall(L, 0, 0, 0);
                if (error) {
                    std::cout<<"ERROR:" << lua_tostring(L, -1);
                    return false;
                }
                return true;
            }

            int execute(std::string script, std::string method, TY_OBJ_DP_S *pSource, protoFormat_t *pTarget) {

                if (method.length() == 0) {
                    _log(INFO) << "* execute lua script  with empty method" << std::endl;
                    return -1;
                }

                int error = luaL_loadbuffer(L, script.c_str(), script.length(), "tuya") || lua_pcall(L, 0, 0, 0);
                if (error) {
                    std::cout<<lua_tostring(L, -1);
                    return -1;
                }
                try {
                    luabridge::LuaRef encoder = luabridge::getGlobal(L, method.c_str());
                    encoder(pSource, pTarget);
                }
                catch (luabridge::LuaException const &e) {
                    std::cout<<e.what();
                    return -1;
                }
                return 0;
            }

        };
        class xx {
            char q;

        };
    }
}

#endif //__LUASCRIPTENGINE_H_
