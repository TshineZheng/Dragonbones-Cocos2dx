#include "lua_dragonbone_CCArmatureDisplay_extend.h"

#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "scripting/lua-bindings/manual/cocos2d/LuaScriptHandlerMgr.h"
#include "scripting/lua-bindings/manual/CCLuaValue.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "base/CCEventListenerFocus.h"
#include "../renderer/cocos2d-x-3.x/CCDragonBonesHeaders.h"

#include "cocos2d.h"


static int handleDragonEvent(int handler, cocos2d::Ref* sender, dragonBones::CCEventObject* eventobj, const std::string type, const std::string name)
{
	LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
	
	stack->pushString(type.c_str());
	stack->pushString(name.c_str());
	stack->pushObject(eventobj, "db.CCEventObject");
	stack->pushObject(sender, "cc.Ref");
	stack->executeFunctionByHandler(handler, 4);

	stack->clean();

	return 0;
}

static int lua_dragonbones_CCArmatureDisplay_addDragonEventListener(lua_State* L)
{
	if (nullptr == L)
		return 0;

	int argc = 0;
	dragonBones::CCArmatureDisplay* cobj = nullptr;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
	if (!tolua_isusertype(L, 1, "db.CCArmatureDisplay", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (dragonBones::CCArmatureDisplay*)tolua_tousertype(L, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(L, "invalid 'cobj' in function 'lua_dragonbones_CCArmatureDisplay_addDragonEventListener'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(L) - 1;

	if (1 == argc)
	{
#if COCOS2D_DEBUG >= 1
		if (!toluafix_isfunction(L, 2, "LUA_FUNCTION", 0, &tolua_err))
		{
			goto tolua_lerror;
		}
#endif

		LUA_FUNCTION handler = (toluafix_ref_function(L, 2, 0));

		cobj->addDragonEventListener([=](cocos2d::Ref* sender, dragonBones::CCEventObject* eventobj, const std::string type, const std::string name) {
			handleDragonEvent(handler, sender, eventobj, type, name);
		});

		int j = (int)ScriptHandlerMgr::getInstance()->addCustomHandler((void*)cobj, handler);
		return 0;
	}

	luaL_error(L, "'addDragonEventListener' function of Widget has wrong number of arguments: %d, was expecting %d\n", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(L, "#ferror in function 'addDragonEventListener'.", &tolua_err);
				return 0;
#endif
}

static void extendGame(lua_State* L)
{
	lua_pushstring(L, "db.CCArmatureDisplay");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		tolua_function(L, "addDragonEventListener", lua_dragonbones_CCArmatureDisplay_addDragonEventListener);
	}
	lua_pop(L, 1);
}

int register_dragonbone_CCArmatureDisplay_extend(lua_State* L)
{
	if (nullptr == L)
		return 0;
	extendGame(L);

	return 0;
}