#pragma once

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif


#include "scripting/lua-bindings/manual/cocos2d/LuaScriptHandlerMgr.h"
#include "base/CCEventListenerAcceleration.h"
#include "base/CCEventListenerCustom.h"

USING_NS_CC;

TOLUA_API int register_dragonbone_CCArmatureDisplay_extend(lua_State* tolua_S);