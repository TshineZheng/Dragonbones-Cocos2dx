#include "scripting/lua-bindings/auto/lua_dragonbones_auto.hpp"
#include "editor-support/dragonbones/renderer/cocos2d-x-3.x/CCDragonBonesHeaders.h"
#include "editor-support/dragonbones/DragonBonesHeaders.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_dragonbones_BaseObject_getClassTypeIndex(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseObject_getClassTypeIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseObject_getClassTypeIndex'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getClassTypeIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseObject:getClassTypeIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseObject_getClassTypeIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseObject_returnToPool(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseObject_returnToPool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseObject_returnToPool'", nullptr);
            return 0;
        }
        cobj->returnToPool();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseObject:returnToPool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseObject_returnToPool'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseObject_clearPool(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.BaseObject",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        unsigned int arg0;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "db.BaseObject:clearPool");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseObject_clearPool'", nullptr);
            return 0;
        }
        dragonBones::BaseObject::clearPool(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.BaseObject:clearPool",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseObject_clearPool'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_BaseObject_setMaxCount(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.BaseObject",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        unsigned int arg0;
        unsigned int arg1;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "db.BaseObject:setMaxCount");
        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "db.BaseObject:setMaxCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseObject_setMaxCount'", nullptr);
            return 0;
        }
        dragonBones::BaseObject::setMaxCount(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.BaseObject:setMaxCount",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseObject_setMaxCount'.",&tolua_err);
#endif
    return 0;
}
static int lua_dragonbones_BaseObject_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BaseObject)");
    return 0;
}

int lua_register_dragonbones_BaseObject(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.BaseObject");
    tolua_cclass(tolua_S,"BaseObject","db.BaseObject","",nullptr);

    tolua_beginmodule(tolua_S,"BaseObject");
        tolua_function(tolua_S,"getClassTypeIndex",lua_dragonbones_BaseObject_getClassTypeIndex);
        tolua_function(tolua_S,"returnToPool",lua_dragonbones_BaseObject_returnToPool);
        tolua_function(tolua_S,"clearPool", lua_dragonbones_BaseObject_clearPool);
        tolua_function(tolua_S,"setMaxCount", lua_dragonbones_BaseObject_setMaxCount);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::BaseObject).name();
    g_luaType[typeName] = "db.BaseObject";
    g_typeCast["BaseObject"] = "db.BaseObject";
    return 1;
}

int lua_dragonbones_Transform_lua_fromMatrix(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_lua_fromMatrix'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const dragonBones::Matrix* arg0;

        ok &= luaval_to_object<const dragonBones::Matrix>(tolua_S, 2, "db.Matrix",&arg0, "db.Transform:lua_fromMatrix");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Transform_lua_fromMatrix'", nullptr);
            return 0;
        }
        dragonBones::Transform* ret = cobj->lua_fromMatrix(arg0);
        object_to_luaval<dragonBones::Transform>(tolua_S, "db.Transform",(dragonBones::Transform*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:lua_fromMatrix",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_lua_fromMatrix'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Transform_lua_toMatrix(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_lua_toMatrix'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Matrix* arg0;

        ok &= luaval_to_object<dragonBones::Matrix>(tolua_S, 2, "db.Matrix",&arg0, "db.Transform:lua_toMatrix");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Transform_lua_toMatrix'", nullptr);
            return 0;
        }
        dragonBones::Transform* ret = cobj->lua_toMatrix(arg0);
        object_to_luaval<dragonBones::Transform>(tolua_S, "db.Transform",(dragonBones::Transform*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:lua_toMatrix",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_lua_toMatrix'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Transform_lua_minus(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_lua_minus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const dragonBones::Transform* arg0;

        ok &= luaval_to_object<const dragonBones::Transform>(tolua_S, 2, "db.Transform",&arg0, "db.Transform:lua_minus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Transform_lua_minus'", nullptr);
            return 0;
        }
        dragonBones::Transform* ret = cobj->lua_minus(arg0);
        object_to_luaval<dragonBones::Transform>(tolua_S, "db.Transform",(dragonBones::Transform*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:lua_minus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_lua_minus'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Transform_lua_add(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_lua_add'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const dragonBones::Transform* arg0;

        ok &= luaval_to_object<const dragonBones::Transform>(tolua_S, 2, "db.Transform",&arg0, "db.Transform:lua_add");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Transform_lua_add'", nullptr);
            return 0;
        }
        dragonBones::Transform* ret = cobj->lua_add(arg0);
        object_to_luaval<dragonBones::Transform>(tolua_S, "db.Transform",(dragonBones::Transform*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:lua_add",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_lua_add'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Transform_getRotation(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_getRotation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Transform_getRotation'", nullptr);
            return 0;
        }
        double ret = cobj->getRotation();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:getRotation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_getRotation'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Transform_setRotation(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_setRotation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.Transform:setRotation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Transform_setRotation'", nullptr);
            return 0;
        }
        cobj->setRotation(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:setRotation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_setRotation'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Transform_lua_identity(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_lua_identity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Transform_lua_identity'", nullptr);
            return 0;
        }
        dragonBones::Transform* ret = cobj->lua_identity();
        object_to_luaval<dragonBones::Transform>(tolua_S, "db.Transform",(dragonBones::Transform*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:lua_identity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_lua_identity'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Transform_normalizeRadian(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.Transform:normalizeRadian");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Transform_normalizeRadian'", nullptr);
            return 0;
        }
        double ret = dragonBones::Transform::normalizeRadian(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.Transform:normalizeRadian",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_normalizeRadian'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_Transform_getx(lua_State* tolua_S)
{
    dragonBones::Transform* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_getx'", nullptr);
        return 0;
    }
#endif

    tolua_pushnumber(tolua_S,(lua_Number)cobj->x);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_getx'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_Transform_setx(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_setx'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.Transform:x");
        cobj->x = arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:x",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_getx'.",&tolua_err);
    return 0;
#endif
}int lua_dragonbones_Transform_gety(lua_State* tolua_S)
{
    dragonBones::Transform* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_gety'", nullptr);
        return 0;
    }
#endif

    tolua_pushnumber(tolua_S,(lua_Number)cobj->y);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_gety'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_Transform_sety(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_sety'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.Transform:y");
        cobj->y = arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:y",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_gety'.",&tolua_err);
    return 0;
#endif
}int lua_dragonbones_Transform_getskewX(lua_State* tolua_S)
{
    dragonBones::Transform* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_getskewX'", nullptr);
        return 0;
    }
#endif

    tolua_pushnumber(tolua_S,(lua_Number)cobj->skewX);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_getskewX'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_Transform_setskewX(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_setskewX'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.Transform:skewX");
        cobj->skewX = arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:skewX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_getskewX'.",&tolua_err);
    return 0;
#endif
}int lua_dragonbones_Transform_getskewY(lua_State* tolua_S)
{
    dragonBones::Transform* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_getskewY'", nullptr);
        return 0;
    }
#endif

    tolua_pushnumber(tolua_S,(lua_Number)cobj->skewY);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_getskewY'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_Transform_setskewY(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_setskewY'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.Transform:skewY");
        cobj->skewY = arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:skewY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_getskewY'.",&tolua_err);
    return 0;
#endif
}int lua_dragonbones_Transform_getscaleX(lua_State* tolua_S)
{
    dragonBones::Transform* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_getscaleX'", nullptr);
        return 0;
    }
#endif

    tolua_pushnumber(tolua_S,(lua_Number)cobj->scaleX);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_getscaleX'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_Transform_setscaleX(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_setscaleX'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.Transform:scaleX");
        cobj->scaleX = arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:scaleX",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_getscaleX'.",&tolua_err);
    return 0;
#endif
}int lua_dragonbones_Transform_getscaleY(lua_State* tolua_S)
{
    dragonBones::Transform* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_getscaleY'", nullptr);
        return 0;
    }
#endif

    tolua_pushnumber(tolua_S,(lua_Number)cobj->scaleY);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_getscaleY'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_Transform_setscaleY(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Transform* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Transform",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Transform*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Transform_setscaleY'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.Transform:scaleY");
        cobj->scaleY = arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.Transform:scaleY",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Transform_getscaleY'.",&tolua_err);
    return 0;
#endif
}static int lua_dragonbones_Transform_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Transform)");
    return 0;
}

int lua_register_dragonbones_Transform(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.Transform");
    tolua_cclass(tolua_S,"Transform","db.Transform","",nullptr);

    tolua_beginmodule(tolua_S,"Transform");
        tolua_function(tolua_S,"fromMatrix",lua_dragonbones_Transform_lua_fromMatrix);
        tolua_function(tolua_S,"toMatrix",lua_dragonbones_Transform_lua_toMatrix);
        tolua_function(tolua_S,"minus",lua_dragonbones_Transform_lua_minus);
        tolua_function(tolua_S,"add",lua_dragonbones_Transform_lua_add);
        tolua_function(tolua_S,"getRotation",lua_dragonbones_Transform_getRotation);
        tolua_function(tolua_S,"setRotation",lua_dragonbones_Transform_setRotation);
        tolua_function(tolua_S,"identity",lua_dragonbones_Transform_lua_identity);
        tolua_function(tolua_S,"normalizeRadian", lua_dragonbones_Transform_normalizeRadian);
        tolua_variable(tolua_S,"x", lua_dragonbones_Transform_getx, lua_dragonbones_Transform_setx);
        tolua_variable(tolua_S,"y", lua_dragonbones_Transform_gety, lua_dragonbones_Transform_sety);
        tolua_variable(tolua_S,"skewX", lua_dragonbones_Transform_getskewX, lua_dragonbones_Transform_setskewX);
        tolua_variable(tolua_S,"skewY", lua_dragonbones_Transform_getskewY, lua_dragonbones_Transform_setskewY);
        tolua_variable(tolua_S,"scaleX", lua_dragonbones_Transform_getscaleX, lua_dragonbones_Transform_setscaleX);
        tolua_variable(tolua_S,"scaleY", lua_dragonbones_Transform_getscaleY, lua_dragonbones_Transform_setscaleY);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::Transform).name();
    g_luaType[typeName] = "db.Transform";
    g_typeCast["Transform"] = "db.Transform";
    return 1;
}

int lua_dragonbones_TextureData_generateRectangle(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.TextureData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_TextureData_generateRectangle'", nullptr);
            return 0;
        }
        dragonBones::Rectangle* ret = dragonBones::TextureData::generateRectangle();
        object_to_luaval<dragonBones::Rectangle>(tolua_S, "db.Rectangle",(dragonBones::Rectangle*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.TextureData:generateRectangle",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TextureData_generateRectangle'.",&tolua_err);
#endif
    return 0;
}
static int lua_dragonbones_TextureData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TextureData)");
    return 0;
}

int lua_register_dragonbones_TextureData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.TextureData");
    tolua_cclass(tolua_S,"TextureData","db.TextureData","db.BaseObject",nullptr);

    tolua_beginmodule(tolua_S,"TextureData");
        tolua_function(tolua_S,"generateRectangle", lua_dragonbones_TextureData_generateRectangle);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::TextureData).name();
    g_luaType[typeName] = "db.TextureData";
    g_typeCast["TextureData"] = "db.TextureData";
    return 1;
}

int lua_dragonbones_TextureAtlasData_addTexture(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::TextureAtlasData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.TextureAtlasData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::TextureAtlasData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TextureAtlasData_addTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::TextureData* arg0;

        ok &= luaval_to_object<dragonBones::TextureData>(tolua_S, 2, "db.TextureData",&arg0, "db.TextureAtlasData:addTexture");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_TextureAtlasData_addTexture'", nullptr);
            return 0;
        }
        cobj->addTexture(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.TextureAtlasData:addTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TextureAtlasData_addTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_TextureAtlasData_generateTexture(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::TextureAtlasData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.TextureAtlasData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::TextureAtlasData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TextureAtlasData_generateTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_TextureAtlasData_generateTexture'", nullptr);
            return 0;
        }
        dragonBones::TextureData* ret = cobj->generateTexture();
        object_to_luaval<dragonBones::TextureData>(tolua_S, "db.TextureData",(dragonBones::TextureData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.TextureAtlasData:generateTexture",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TextureAtlasData_generateTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_TextureAtlasData_getTexture(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::TextureAtlasData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.TextureAtlasData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::TextureAtlasData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TextureAtlasData_getTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.TextureAtlasData:getTexture");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_TextureAtlasData_getTexture'", nullptr);
            return 0;
        }
        dragonBones::TextureData* ret = cobj->getTexture(arg0);
        object_to_luaval<dragonBones::TextureData>(tolua_S, "db.TextureData",(dragonBones::TextureData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.TextureAtlasData:getTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TextureAtlasData_getTexture'.",&tolua_err);
#endif

    return 0;
}
static int lua_dragonbones_TextureAtlasData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TextureAtlasData)");
    return 0;
}

int lua_register_dragonbones_TextureAtlasData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.TextureAtlasData");
    tolua_cclass(tolua_S,"TextureAtlasData","db.TextureAtlasData","db.BaseObject",nullptr);

    tolua_beginmodule(tolua_S,"TextureAtlasData");
        tolua_function(tolua_S,"addTexture",lua_dragonbones_TextureAtlasData_addTexture);
        tolua_function(tolua_S,"generateTexture",lua_dragonbones_TextureAtlasData_generateTexture);
        tolua_function(tolua_S,"getTexture",lua_dragonbones_TextureAtlasData_getTexture);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::TextureAtlasData).name();
    g_luaType[typeName] = "db.TextureAtlasData";
    g_typeCast["TextureAtlasData"] = "db.TextureAtlasData";
    return 1;
}

int lua_dragonbones_AnimationData_cacheFrames(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationData_cacheFrames'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.AnimationData:cacheFrames");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationData_cacheFrames'", nullptr);
            return 0;
        }
        cobj->cacheFrames(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationData:cacheFrames",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationData_cacheFrames'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationData_getFFDTimeline(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationData_getFFDTimeline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        unsigned int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.AnimationData:getFFDTimeline");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.AnimationData:getFFDTimeline");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "db.AnimationData:getFFDTimeline");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationData_getFFDTimeline'", nullptr);
            return 0;
        }
        dragonBones::FFDTimelineData* ret = cobj->getFFDTimeline(arg0, arg1, arg2);
        object_to_luaval<dragonBones::FFDTimelineData>(tolua_S, "db.FFDTimelineData",(dragonBones::FFDTimelineData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationData:getFFDTimeline",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationData_getFFDTimeline'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationData_getSlotTimeline(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationData_getSlotTimeline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.AnimationData:getSlotTimeline");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationData_getSlotTimeline'", nullptr);
            return 0;
        }
        dragonBones::SlotTimelineData* ret = cobj->getSlotTimeline(arg0);
        object_to_luaval<dragonBones::SlotTimelineData>(tolua_S, "db.SlotTimelineData",(dragonBones::SlotTimelineData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationData:getSlotTimeline",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationData_getSlotTimeline'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationData_addSlotTimeline(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationData_addSlotTimeline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::SlotTimelineData* arg0;

        ok &= luaval_to_object<dragonBones::SlotTimelineData>(tolua_S, 2, "db.SlotTimelineData",&arg0, "db.AnimationData:addSlotTimeline");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationData_addSlotTimeline'", nullptr);
            return 0;
        }
        cobj->addSlotTimeline(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationData:addSlotTimeline",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationData_addSlotTimeline'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationData_addFFDTimeline(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationData_addFFDTimeline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::FFDTimelineData* arg0;

        ok &= luaval_to_object<dragonBones::FFDTimelineData>(tolua_S, 2, "db.FFDTimelineData",&arg0, "db.AnimationData:addFFDTimeline");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationData_addFFDTimeline'", nullptr);
            return 0;
        }
        cobj->addFFDTimeline(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationData:addFFDTimeline",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationData_addFFDTimeline'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationData_getClassTypeIndex(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationData_getClassTypeIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationData_getClassTypeIndex'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getClassTypeIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationData:getClassTypeIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationData_getClassTypeIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationData_addBoneTimeline(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationData_addBoneTimeline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::BoneTimelineData* arg0;

        ok &= luaval_to_object<dragonBones::BoneTimelineData>(tolua_S, 2, "db.BoneTimelineData",&arg0, "db.AnimationData:addBoneTimeline");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationData_addBoneTimeline'", nullptr);
            return 0;
        }
        cobj->addBoneTimeline(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationData:addBoneTimeline",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationData_addBoneTimeline'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationData_getBoneTimeline(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationData_getBoneTimeline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.AnimationData:getBoneTimeline");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationData_getBoneTimeline'", nullptr);
            return 0;
        }
        dragonBones::BoneTimelineData* ret = cobj->getBoneTimeline(arg0);
        object_to_luaval<dragonBones::BoneTimelineData>(tolua_S, "db.BoneTimelineData",(dragonBones::BoneTimelineData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationData:getBoneTimeline",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationData_getBoneTimeline'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationData_getTypeIndex(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.AnimationData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationData_getTypeIndex'", nullptr);
            return 0;
        }
        unsigned int ret = dragonBones::AnimationData::getTypeIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.AnimationData:getTypeIndex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationData_getTypeIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_AnimationData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationData_constructor'", nullptr);
            return 0;
        }
        cobj = new dragonBones::AnimationData();
        tolua_pushusertype(tolua_S,(void*)cobj,"db.AnimationData");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationData:AnimationData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationData_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_AnimationData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimationData)");
    return 0;
}

int lua_register_dragonbones_AnimationData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.AnimationData");
    tolua_cclass(tolua_S,"AnimationData","db.AnimationData","db.TimelineData<db.AnimationFrameData>",nullptr);

    tolua_beginmodule(tolua_S,"AnimationData");
        tolua_function(tolua_S,"new",lua_dragonbones_AnimationData_constructor);
        tolua_function(tolua_S,"cacheFrames",lua_dragonbones_AnimationData_cacheFrames);
        tolua_function(tolua_S,"getFFDTimeline",lua_dragonbones_AnimationData_getFFDTimeline);
        tolua_function(tolua_S,"getSlotTimeline",lua_dragonbones_AnimationData_getSlotTimeline);
        tolua_function(tolua_S,"addSlotTimeline",lua_dragonbones_AnimationData_addSlotTimeline);
        tolua_function(tolua_S,"addFFDTimeline",lua_dragonbones_AnimationData_addFFDTimeline);
        tolua_function(tolua_S,"getClassTypeIndex",lua_dragonbones_AnimationData_getClassTypeIndex);
        tolua_function(tolua_S,"addBoneTimeline",lua_dragonbones_AnimationData_addBoneTimeline);
        tolua_function(tolua_S,"getBoneTimeline",lua_dragonbones_AnimationData_getBoneTimeline);
        tolua_function(tolua_S,"getTypeIndex", lua_dragonbones_AnimationData_getTypeIndex);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::AnimationData).name();
    g_luaType[typeName] = "db.AnimationData";
    g_typeCast["AnimationData"] = "db.AnimationData";
    return 1;
}

int lua_dragonbones_DragonBonesData_getArmatureNames(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DragonBonesData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DragonBonesData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DragonBonesData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DragonBonesData_getArmatureNames'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_DragonBonesData_getArmatureNames'", nullptr);
            return 0;
        }
        const std::vector<std::string>& ret = cobj->getArmatureNames();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.DragonBonesData:getArmatureNames",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DragonBonesData_getArmatureNames'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DragonBonesData_addArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DragonBonesData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DragonBonesData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DragonBonesData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DragonBonesData_addArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::ArmatureData* arg0;

        ok &= luaval_to_object<dragonBones::ArmatureData>(tolua_S, 2, "db.ArmatureData",&arg0, "db.DragonBonesData:addArmature");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_DragonBonesData_addArmature'", nullptr);
            return 0;
        }
        cobj->addArmature(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.DragonBonesData:addArmature",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DragonBonesData_addArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DragonBonesData_getArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DragonBonesData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.DragonBonesData",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::DragonBonesData*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_DragonBonesData_getArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.DragonBonesData:getArmature");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_DragonBonesData_getArmature'", nullptr);
            return 0;
        }
        dragonBones::ArmatureData* ret = cobj->getArmature(arg0);
        object_to_luaval<dragonBones::ArmatureData>(tolua_S, "db.ArmatureData",(dragonBones::ArmatureData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.DragonBonesData:getArmature",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DragonBonesData_getArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_DragonBonesData_getTypeIndex(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.DragonBonesData",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_DragonBonesData_getTypeIndex'", nullptr);
            return 0;
        }
        unsigned int ret = dragonBones::DragonBonesData::getTypeIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.DragonBonesData:getTypeIndex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DragonBonesData_getTypeIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_DragonBonesData_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::DragonBonesData* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_DragonBonesData_constructor'", nullptr);
            return 0;
        }
        cobj = new dragonBones::DragonBonesData();
        tolua_pushusertype(tolua_S,(void*)cobj,"db.DragonBonesData");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.DragonBonesData:DragonBonesData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_DragonBonesData_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_DragonBonesData_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DragonBonesData)");
    return 0;
}

int lua_register_dragonbones_DragonBonesData(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.DragonBonesData");
    tolua_cclass(tolua_S,"DragonBonesData","db.DragonBonesData","db.BaseObject",nullptr);

    tolua_beginmodule(tolua_S,"DragonBonesData");
        tolua_function(tolua_S,"new",lua_dragonbones_DragonBonesData_constructor);
        tolua_function(tolua_S,"getArmatureNames",lua_dragonbones_DragonBonesData_getArmatureNames);
        tolua_function(tolua_S,"addArmature",lua_dragonbones_DragonBonesData_addArmature);
        tolua_function(tolua_S,"getArmature",lua_dragonbones_DragonBonesData_getArmature);
        tolua_function(tolua_S,"getTypeIndex", lua_dragonbones_DragonBonesData_getTypeIndex);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::DragonBonesData).name();
    g_luaType[typeName] = "db.DragonBonesData";
    g_typeCast["DragonBonesData"] = "db.DragonBonesData";
    return 1;
}

int lua_dragonbones_IAnimateble_advanceTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::IAnimateble* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.IAnimateble",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::IAnimateble*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_IAnimateble_advanceTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.IAnimateble:advanceTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_IAnimateble_advanceTime'", nullptr);
            return 0;
        }
        cobj->advanceTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.IAnimateble:advanceTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_IAnimateble_advanceTime'.",&tolua_err);
#endif

    return 0;
}
static int lua_dragonbones_IAnimateble_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IAnimateble)");
    return 0;
}

int lua_register_dragonbones_IAnimateble(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.IAnimateble");
    tolua_cclass(tolua_S,"IAnimateble","db.IAnimateble","",nullptr);

    tolua_beginmodule(tolua_S,"IAnimateble");
        tolua_function(tolua_S,"advanceTime",lua_dragonbones_IAnimateble_advanceTime);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::IAnimateble).name();
    g_luaType[typeName] = "db.IAnimateble";
    g_typeCast["IAnimateble"] = "db.IAnimateble";
    return 1;
}

int lua_dragonbones_EventObject_getTypeIndex(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.EventObject",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_EventObject_getTypeIndex'", nullptr);
            return 0;
        }
        unsigned int ret = dragonBones::EventObject::getTypeIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.EventObject:getTypeIndex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_EventObject_getTypeIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_EventObject_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::EventObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_EventObject_constructor'", nullptr);
            return 0;
        }
        cobj = new dragonBones::EventObject();
        tolua_pushusertype(tolua_S,(void*)cobj,"db.EventObject");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.EventObject:EventObject",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_EventObject_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_EventObject_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (EventObject)");
    return 0;
}

int lua_register_dragonbones_EventObject(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.EventObject");
    tolua_cclass(tolua_S,"EventObject","db.EventObject","db.BaseObject",nullptr);

    tolua_beginmodule(tolua_S,"EventObject");
        tolua_function(tolua_S,"new",lua_dragonbones_EventObject_constructor);
        tolua_function(tolua_S,"getTypeIndex", lua_dragonbones_EventObject_getTypeIndex);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::EventObject).name();
    g_luaType[typeName] = "db.EventObject";
    g_typeCast["EventObject"] = "db.EventObject";
    return 1;
}

int lua_dragonbones_IEventDispatcher_hasEvent(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::IEventDispatcher* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.IEventDispatcher",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::IEventDispatcher*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_IEventDispatcher_hasEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.IEventDispatcher:hasEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_IEventDispatcher_hasEvent'", nullptr);
            return 0;
        }
        bool ret = cobj->hasEvent(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.IEventDispatcher:hasEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_IEventDispatcher_hasEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_IEventDispatcher__dispatchEvent(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::IEventDispatcher* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.IEventDispatcher",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::IEventDispatcher*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_IEventDispatcher__dispatchEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::EventObject* arg0;

        ok &= luaval_to_object<dragonBones::EventObject>(tolua_S, 2, "db.EventObject",&arg0, "db.IEventDispatcher:_dispatchEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_IEventDispatcher__dispatchEvent'", nullptr);
            return 0;
        }
        cobj->_dispatchEvent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.IEventDispatcher:_dispatchEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_IEventDispatcher__dispatchEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_IEventDispatcher__onClear(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::IEventDispatcher* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.IEventDispatcher",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::IEventDispatcher*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_IEventDispatcher__onClear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_IEventDispatcher__onClear'", nullptr);
            return 0;
        }
        cobj->_onClear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.IEventDispatcher:_onClear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_IEventDispatcher__onClear'.",&tolua_err);
#endif

    return 0;
}
static int lua_dragonbones_IEventDispatcher_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IEventDispatcher)");
    return 0;
}

int lua_register_dragonbones_IEventDispatcher(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.IEventDispatcher");
    tolua_cclass(tolua_S,"IEventDispatcher","db.IEventDispatcher","",nullptr);

    tolua_beginmodule(tolua_S,"IEventDispatcher");
        tolua_function(tolua_S,"hasEvent",lua_dragonbones_IEventDispatcher_hasEvent);
        tolua_function(tolua_S,"_dispatchEvent",lua_dragonbones_IEventDispatcher__dispatchEvent);
        tolua_function(tolua_S,"_onClear",lua_dragonbones_IEventDispatcher__onClear);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::IEventDispatcher).name();
    g_luaType[typeName] = "db.IEventDispatcher";
    g_typeCast["IEventDispatcher"] = "db.IEventDispatcher";
    return 1;
}

int lua_dragonbones_Armature__addSlotToSlotList(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature__addSlotToSlotList'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Slot* arg0;

        ok &= luaval_to_object<dragonBones::Slot>(tolua_S, 2, "db.Slot",&arg0, "db.Armature:_addSlotToSlotList");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature__addSlotToSlotList'", nullptr);
            return 0;
        }
        cobj->_addSlotToSlotList(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:_addSlotToSlotList",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature__addSlotToSlotList'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getSlot(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getSlot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Armature:getSlot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_getSlot'", nullptr);
            return 0;
        }
        dragonBones::Slot* ret = cobj->getSlot(arg0);
        object_to_luaval<dragonBones::Slot>(tolua_S, "db.Slot",(dragonBones::Slot*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:getSlot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_getDisplay'", nullptr);
            return 0;
        }
        dragonBones::IArmatureDisplay* ret = cobj->getDisplay();
        object_to_luaval<dragonBones::CCArmatureDisplay>(tolua_S, "db.IArmatureDisplay",(dragonBones::CCArmatureDisplay*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:getDisplay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature__bufferAction(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature__bufferAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::ActionData* arg0;

        ok &= luaval_to_object<dragonBones::ActionData>(tolua_S, 2, "db.ActionData",&arg0, "db.Armature:_bufferAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature__bufferAction'", nullptr);
            return 0;
        }
        cobj->_bufferAction(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:_bufferAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature__bufferAction'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getCacheFrameRate(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getCacheFrameRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_getCacheFrameRate'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getCacheFrameRate();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:getCacheFrameRate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getCacheFrameRate'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature__removeBoneFromBoneList(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature__removeBoneFromBoneList'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Bone* arg0;

        ok &= luaval_to_object<dragonBones::Bone>(tolua_S, 2, "db.Bone",&arg0, "db.Armature:_removeBoneFromBoneList");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature__removeBoneFromBoneList'", nullptr);
            return 0;
        }
        cobj->_removeBoneFromBoneList(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:_removeBoneFromBoneList",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature__removeBoneFromBoneList'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_lua_getArmatureData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_lua_getArmatureData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_lua_getArmatureData'", nullptr);
            return 0;
        }
        dragonBones::ArmatureData* ret = cobj->lua_getArmatureData();
        object_to_luaval<dragonBones::ArmatureData>(tolua_S, "db.ArmatureData",(dragonBones::ArmatureData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:lua_getArmatureData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_lua_getArmatureData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getName(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_getName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_dispose(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_dispose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_dispose'", nullptr);
            return 0;
        }
        cobj->dispose();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:dispose",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_dispose'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_addSlot(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_addSlot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        dragonBones::Slot* arg0;
        std::string arg1;

        ok &= luaval_to_object<dragonBones::Slot>(tolua_S, 2, "db.Slot",&arg0, "db.Armature:addSlot");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.Armature:addSlot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_addSlot'", nullptr);
            return 0;
        }
        cobj->addSlot(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:addSlot",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_addSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_invalidUpdate(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_invalidUpdate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_invalidUpdate'", nullptr);
            return 0;
        }
        cobj->invalidUpdate();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Armature:invalidUpdate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_invalidUpdate'", nullptr);
            return 0;
        }
        cobj->invalidUpdate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Armature:invalidUpdate");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "db.Armature:invalidUpdate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_invalidUpdate'", nullptr);
            return 0;
        }
        cobj->invalidUpdate(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:invalidUpdate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_invalidUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getBoneByDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getBoneByDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        void* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_getBoneByDisplay'", nullptr);
            return 0;
        }
        dragonBones::Bone* ret = cobj->getBoneByDisplay(arg0);
        object_to_luaval<dragonBones::Bone>(tolua_S, "db.Bone",(dragonBones::Bone*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:getBoneByDisplay",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getBoneByDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_setCacheFrameRate(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_setCacheFrameRate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "db.Armature:setCacheFrameRate");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_setCacheFrameRate'", nullptr);
            return 0;
        }
        cobj->setCacheFrameRate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:setCacheFrameRate",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_setCacheFrameRate'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_removeSlot(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_removeSlot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Slot* arg0;

        ok &= luaval_to_object<dragonBones::Slot>(tolua_S, 2, "db.Slot",&arg0, "db.Armature:removeSlot");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_removeSlot'", nullptr);
            return 0;
        }
        cobj->removeSlot(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:removeSlot",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_removeSlot'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature__bufferEvent(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature__bufferEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        dragonBones::EventObject* arg0;
        std::string arg1;

        ok &= luaval_to_object<dragonBones::EventObject>(tolua_S, 2, "db.EventObject",&arg0, "db.Armature:_bufferEvent");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.Armature:_bufferEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature__bufferEvent'", nullptr);
            return 0;
        }
        cobj->_bufferEvent(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:_bufferEvent",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature__bufferEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_addBone(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_addBone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Bone* arg0;

        ok &= luaval_to_object<dragonBones::Bone>(tolua_S, 2, "db.Bone",&arg0, "db.Armature:addBone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_addBone'", nullptr);
            return 0;
        }
        cobj->addBone(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        dragonBones::Bone* arg0;
        std::string arg1;

        ok &= luaval_to_object<dragonBones::Bone>(tolua_S, 2, "db.Bone",&arg0, "db.Armature:addBone");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.Armature:addBone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_addBone'", nullptr);
            return 0;
        }
        cobj->addBone(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:addBone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_addBone'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_lua_getAnimation(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_lua_getAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_lua_getAnimation'", nullptr);
            return 0;
        }
        dragonBones::Animation* ret = cobj->lua_getAnimation();
        object_to_luaval<dragonBones::Animation>(tolua_S, "db.Animation",(dragonBones::Animation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:lua_getAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_lua_getAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getClassTypeIndex(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getClassTypeIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_getClassTypeIndex'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getClassTypeIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:getClassTypeIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getClassTypeIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getBone(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getBone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Armature:getBone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_getBone'", nullptr);
            return 0;
        }
        dragonBones::Bone* ret = cobj->getBone(arg0);
        object_to_luaval<dragonBones::Bone>(tolua_S, "db.Bone",(dragonBones::Bone*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:getBone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getBone'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature__addBoneToBoneList(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature__addBoneToBoneList'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Bone* arg0;

        ok &= luaval_to_object<dragonBones::Bone>(tolua_S, 2, "db.Bone",&arg0, "db.Armature:_addBoneToBoneList");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature__addBoneToBoneList'", nullptr);
            return 0;
        }
        cobj->_addBoneToBoneList(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:_addBoneToBoneList",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature__addBoneToBoneList'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getParent(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_getParent'", nullptr);
            return 0;
        }
        dragonBones::Slot* ret = cobj->getParent();
        object_to_luaval<dragonBones::Slot>(tolua_S, "db.Slot",(dragonBones::Slot*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:getParent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getParent'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getSlotByDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_getSlotByDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        void* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_getSlotByDisplay'", nullptr);
            return 0;
        }
        dragonBones::Slot* ret = cobj->getSlotByDisplay(arg0);
        object_to_luaval<dragonBones::Slot>(tolua_S, "db.Slot",(dragonBones::Slot*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:getSlotByDisplay",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getSlotByDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_removeBone(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_removeBone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Bone* arg0;

        ok &= luaval_to_object<dragonBones::Bone>(tolua_S, 2, "db.Bone",&arg0, "db.Armature:removeBone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_removeBone'", nullptr);
            return 0;
        }
        cobj->removeBone(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:removeBone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_removeBone'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature__removeSlotFromSlotList(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature__removeSlotFromSlotList'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Slot* arg0;

        ok &= luaval_to_object<dragonBones::Slot>(tolua_S, 2, "db.Slot",&arg0, "db.Armature:_removeSlotFromSlotList");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature__removeSlotFromSlotList'", nullptr);
            return 0;
        }
        cobj->_removeSlotFromSlotList(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:_removeSlotFromSlotList",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature__removeSlotFromSlotList'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_replaceTexture(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Armature* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Armature*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Armature_replaceTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        void* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_replaceTexture'", nullptr);
            return 0;
        }
        cobj->replaceTexture(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Armature:replaceTexture",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_replaceTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Armature_getTypeIndex(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.Armature",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Armature_getTypeIndex'", nullptr);
            return 0;
        }
        unsigned int ret = dragonBones::Armature::getTypeIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.Armature:getTypeIndex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Armature_getTypeIndex'.",&tolua_err);
#endif
    return 0;
}
static int lua_dragonbones_Armature_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Armature)");
    return 0;
}

int lua_register_dragonbones_Armature(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.Armature");
    tolua_cclass(tolua_S,"Armature","db.Armature","db.IAnimateble",nullptr);

    tolua_beginmodule(tolua_S,"Armature");
        tolua_function(tolua_S,"_addSlotToSlotList",lua_dragonbones_Armature__addSlotToSlotList);
        tolua_function(tolua_S,"getSlot",lua_dragonbones_Armature_getSlot);
        tolua_function(tolua_S,"getDisplay",lua_dragonbones_Armature_getDisplay);
        tolua_function(tolua_S,"_bufferAction",lua_dragonbones_Armature__bufferAction);
        tolua_function(tolua_S,"getCacheFrameRate",lua_dragonbones_Armature_getCacheFrameRate);
        tolua_function(tolua_S,"_removeBoneFromBoneList",lua_dragonbones_Armature__removeBoneFromBoneList);
        tolua_function(tolua_S,"getArmatureData",lua_dragonbones_Armature_lua_getArmatureData);
        tolua_function(tolua_S,"getName",lua_dragonbones_Armature_getName);
        tolua_function(tolua_S,"dispose",lua_dragonbones_Armature_dispose);
        tolua_function(tolua_S,"addSlot",lua_dragonbones_Armature_addSlot);
        tolua_function(tolua_S,"invalidUpdate",lua_dragonbones_Armature_invalidUpdate);
        tolua_function(tolua_S,"getBoneByDisplay",lua_dragonbones_Armature_getBoneByDisplay);
        tolua_function(tolua_S,"setCacheFrameRate",lua_dragonbones_Armature_setCacheFrameRate);
        tolua_function(tolua_S,"removeSlot",lua_dragonbones_Armature_removeSlot);
        tolua_function(tolua_S,"_bufferEvent",lua_dragonbones_Armature__bufferEvent);
        tolua_function(tolua_S,"addBone",lua_dragonbones_Armature_addBone);
        tolua_function(tolua_S,"getAnimation",lua_dragonbones_Armature_lua_getAnimation);
        tolua_function(tolua_S,"getClassTypeIndex",lua_dragonbones_Armature_getClassTypeIndex);
        tolua_function(tolua_S,"getBone",lua_dragonbones_Armature_getBone);
        tolua_function(tolua_S,"_addBoneToBoneList",lua_dragonbones_Armature__addBoneToBoneList);
        tolua_function(tolua_S,"getParent",lua_dragonbones_Armature_getParent);
        tolua_function(tolua_S,"getSlotByDisplay",lua_dragonbones_Armature_getSlotByDisplay);
        tolua_function(tolua_S,"removeBone",lua_dragonbones_Armature_removeBone);
        tolua_function(tolua_S,"_removeSlotFromSlotList",lua_dragonbones_Armature__removeSlotFromSlotList);
        tolua_function(tolua_S,"replaceTexture",lua_dragonbones_Armature_replaceTexture);
        tolua_function(tolua_S,"getTypeIndex", lua_dragonbones_Armature_getTypeIndex);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::Armature).name();
    g_luaType[typeName] = "db.Armature";
    g_typeCast["Armature"] = "db.Armature";
    return 1;
}

int lua_dragonbones_Animation_isPlaying(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_isPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_isPlaying'", nullptr);
            return 0;
        }
        bool ret = cobj->isPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:isPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_isPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_getAnimationNames(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_getAnimationNames'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_getAnimationNames'", nullptr);
            return 0;
        }
        const std::vector<std::string>& ret = cobj->getAnimationNames();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:getAnimationNames",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_getAnimationNames'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_fadeIn(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_fadeIn'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:fadeIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_fadeIn'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:fadeIn");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:fadeIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_fadeIn'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        double arg1;
        int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:fadeIn");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Animation:fadeIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_fadeIn'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 4) 
    {
        std::string arg0;
        double arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:fadeIn");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "db.Animation:fadeIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_fadeIn'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 5) 
    {
        std::string arg0;
        double arg1;
        int arg2;
        int arg3;
        std::string arg4;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:fadeIn");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "db.Animation:fadeIn");

        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "db.Animation:fadeIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_fadeIn'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 6) 
    {
        std::string arg0;
        double arg1;
        int arg2;
        int arg3;
        std::string arg4;
        dragonBones::AnimationFadeOutMode arg5;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:fadeIn");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "db.Animation:fadeIn");

        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "db.Animation:fadeIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_fadeIn'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4, arg5);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 7) 
    {
        std::string arg0;
        double arg1;
        int arg2;
        int arg3;
        std::string arg4;
        dragonBones::AnimationFadeOutMode arg5;
        bool arg6;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:fadeIn");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "db.Animation:fadeIn");

        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "db.Animation:fadeIn");

        ok &= luaval_to_boolean(tolua_S, 8,&arg6, "db.Animation:fadeIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_fadeIn'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 8) 
    {
        std::string arg0;
        double arg1;
        int arg2;
        int arg3;
        std::string arg4;
        dragonBones::AnimationFadeOutMode arg5;
        bool arg6;
        bool arg7;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:fadeIn");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "db.Animation:fadeIn");

        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "db.Animation:fadeIn");

        ok &= luaval_to_boolean(tolua_S, 8,&arg6, "db.Animation:fadeIn");

        ok &= luaval_to_boolean(tolua_S, 9,&arg7, "db.Animation:fadeIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_fadeIn'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 9) 
    {
        std::string arg0;
        double arg1;
        int arg2;
        int arg3;
        std::string arg4;
        dragonBones::AnimationFadeOutMode arg5;
        bool arg6;
        bool arg7;
        bool arg8;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:fadeIn");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "db.Animation:fadeIn");

        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "db.Animation:fadeIn");

        ok &= luaval_to_boolean(tolua_S, 8,&arg6, "db.Animation:fadeIn");

        ok &= luaval_to_boolean(tolua_S, 9,&arg7, "db.Animation:fadeIn");

        ok &= luaval_to_boolean(tolua_S, 10,&arg8, "db.Animation:fadeIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_fadeIn'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 10) 
    {
        std::string arg0;
        double arg1;
        int arg2;
        int arg3;
        std::string arg4;
        dragonBones::AnimationFadeOutMode arg5;
        bool arg6;
        bool arg7;
        bool arg8;
        bool arg9;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:fadeIn");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "db.Animation:fadeIn");

        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "db.Animation:fadeIn");

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "db.Animation:fadeIn");

        ok &= luaval_to_boolean(tolua_S, 8,&arg6, "db.Animation:fadeIn");

        ok &= luaval_to_boolean(tolua_S, 9,&arg7, "db.Animation:fadeIn");

        ok &= luaval_to_boolean(tolua_S, 10,&arg8, "db.Animation:fadeIn");

        ok &= luaval_to_boolean(tolua_S, 11,&arg9, "db.Animation:fadeIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_fadeIn'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->fadeIn(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:fadeIn",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_fadeIn'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_isCompleted(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_isCompleted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_isCompleted'", nullptr);
            return 0;
        }
        bool ret = cobj->isCompleted();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:isCompleted",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_isCompleted'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_reset(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_reset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_reset'", nullptr);
            return 0;
        }
        cobj->reset();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:reset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_reset'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_play(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_play'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_play'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->play();
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:play");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_play'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->play(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:play");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "db.Animation:play");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_play'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->play(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:play",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_play'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_getState(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_getState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:getState");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_getState'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->getState(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:getState",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_getState'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_stop(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:stop");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_stop'", nullptr);
            return 0;
        }
        cobj->stop(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:stop",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_getLastAnimationName(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_getLastAnimationName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_getLastAnimationName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getLastAnimationName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:getLastAnimationName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_getLastAnimationName'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_getLastAnimationState(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_getLastAnimationState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_getLastAnimationState'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->getLastAnimationState();
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:getLastAnimationState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_getLastAnimationState'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_gotoAndPlayByTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_gotoAndPlayByTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndPlayByTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndPlayByTime'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByTime(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndPlayByTime");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:gotoAndPlayByTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndPlayByTime'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByTime(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        double arg1;
        int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndPlayByTime");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:gotoAndPlayByTime");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Animation:gotoAndPlayByTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndPlayByTime'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByTime(arg0, arg1, arg2);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:gotoAndPlayByTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_gotoAndPlayByTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_gotoAndPlayByProgress(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_gotoAndPlayByProgress'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndPlayByProgress");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndPlayByProgress'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByProgress(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndPlayByProgress");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:gotoAndPlayByProgress");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndPlayByProgress'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByProgress(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        double arg1;
        int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndPlayByProgress");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:gotoAndPlayByProgress");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Animation:gotoAndPlayByProgress");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndPlayByProgress'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByProgress(arg0, arg1, arg2);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:gotoAndPlayByProgress",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_gotoAndPlayByProgress'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation__advanceTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation__advanceTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.Animation:_advanceTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation__advanceTime'", nullptr);
            return 0;
        }
        cobj->_advanceTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:_advanceTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation__advanceTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation__updateFFDTimelineStates(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation__updateFFDTimelineStates'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation__updateFFDTimelineStates'", nullptr);
            return 0;
        }
        cobj->_updateFFDTimelineStates();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:_updateFFDTimelineStates",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation__updateFFDTimelineStates'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_hasAnimation(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_hasAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:hasAnimation");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_hasAnimation'", nullptr);
            return 0;
        }
        bool ret = cobj->hasAnimation(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:hasAnimation",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_hasAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_gotoAndStopByTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_gotoAndStopByTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndStopByTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndStopByTime'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndStopByTime(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndStopByTime");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:gotoAndStopByTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndStopByTime'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndStopByTime(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:gotoAndStopByTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_gotoAndStopByTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_gotoAndStopByProgress(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_gotoAndStopByProgress'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndStopByProgress");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndStopByProgress'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndStopByProgress(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndStopByProgress");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.Animation:gotoAndStopByProgress");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndStopByProgress'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndStopByProgress(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:gotoAndStopByProgress",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_gotoAndStopByProgress'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_gotoAndPlayByFrame(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_gotoAndPlayByFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndPlayByFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndPlayByFrame'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByFrame(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        unsigned int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndPlayByFrame");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "db.Animation:gotoAndPlayByFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndPlayByFrame'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByFrame(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        unsigned int arg1;
        int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndPlayByFrame");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "db.Animation:gotoAndPlayByFrame");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Animation:gotoAndPlayByFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndPlayByFrame'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndPlayByFrame(arg0, arg1, arg2);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:gotoAndPlayByFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_gotoAndPlayByFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_gotoAndStopByFrame(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Animation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Animation_gotoAndStopByFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndStopByFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndStopByFrame'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndStopByFrame(arg0);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        unsigned int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Animation:gotoAndStopByFrame");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "db.Animation:gotoAndStopByFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_gotoAndStopByFrame'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->gotoAndStopByFrame(arg0, arg1);
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:gotoAndStopByFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_gotoAndStopByFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Animation_getTypeIndex(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.Animation",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_getTypeIndex'", nullptr);
            return 0;
        }
        unsigned int ret = dragonBones::Animation::getTypeIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.Animation:getTypeIndex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_getTypeIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_Animation_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Animation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Animation_constructor'", nullptr);
            return 0;
        }
        cobj = new dragonBones::Animation();
        tolua_pushusertype(tolua_S,(void*)cobj,"db.Animation");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Animation:Animation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Animation_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_Animation_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Animation)");
    return 0;
}

int lua_register_dragonbones_Animation(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.Animation");
    tolua_cclass(tolua_S,"Animation","db.Animation","db.BaseObject",nullptr);

    tolua_beginmodule(tolua_S,"Animation");
        tolua_function(tolua_S,"new",lua_dragonbones_Animation_constructor);
        tolua_function(tolua_S,"isPlaying",lua_dragonbones_Animation_isPlaying);
        tolua_function(tolua_S,"getAnimationNames",lua_dragonbones_Animation_getAnimationNames);
        tolua_function(tolua_S,"fadeIn",lua_dragonbones_Animation_fadeIn);
        tolua_function(tolua_S,"isCompleted",lua_dragonbones_Animation_isCompleted);
        tolua_function(tolua_S,"reset",lua_dragonbones_Animation_reset);
        tolua_function(tolua_S,"play",lua_dragonbones_Animation_play);
        tolua_function(tolua_S,"getState",lua_dragonbones_Animation_getState);
        tolua_function(tolua_S,"stop",lua_dragonbones_Animation_stop);
        tolua_function(tolua_S,"getLastAnimationName",lua_dragonbones_Animation_getLastAnimationName);
        tolua_function(tolua_S,"getLastAnimationState",lua_dragonbones_Animation_getLastAnimationState);
        tolua_function(tolua_S,"gotoAndPlayByTime",lua_dragonbones_Animation_gotoAndPlayByTime);
        tolua_function(tolua_S,"gotoAndPlayByProgress",lua_dragonbones_Animation_gotoAndPlayByProgress);
        tolua_function(tolua_S,"_advanceTime",lua_dragonbones_Animation__advanceTime);
        tolua_function(tolua_S,"_updateFFDTimelineStates",lua_dragonbones_Animation__updateFFDTimelineStates);
        tolua_function(tolua_S,"hasAnimation",lua_dragonbones_Animation_hasAnimation);
        tolua_function(tolua_S,"gotoAndStopByTime",lua_dragonbones_Animation_gotoAndStopByTime);
        tolua_function(tolua_S,"gotoAndStopByProgress",lua_dragonbones_Animation_gotoAndStopByProgress);
        tolua_function(tolua_S,"gotoAndPlayByFrame",lua_dragonbones_Animation_gotoAndPlayByFrame);
        tolua_function(tolua_S,"gotoAndStopByFrame",lua_dragonbones_Animation_gotoAndStopByFrame);
        tolua_function(tolua_S,"getTypeIndex", lua_dragonbones_Animation_getTypeIndex);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::Animation).name();
    g_luaType[typeName] = "db.Animation";
    g_typeCast["Animation"] = "db.Animation";
    return 1;
}

int lua_dragonbones_TransformObject__setArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::TransformObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.TransformObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::TransformObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TransformObject__setArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Armature* arg0;

        ok &= luaval_to_object<dragonBones::Armature>(tolua_S, 2, "db.Armature",&arg0, "db.TransformObject:_setArmature");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_TransformObject__setArmature'", nullptr);
            return 0;
        }
        cobj->_setArmature(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.TransformObject:_setArmature",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TransformObject__setArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_TransformObject__setParent(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::TransformObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.TransformObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::TransformObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TransformObject__setParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Bone* arg0;

        ok &= luaval_to_object<dragonBones::Bone>(tolua_S, 2, "db.Bone",&arg0, "db.TransformObject:_setParent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_TransformObject__setParent'", nullptr);
            return 0;
        }
        cobj->_setParent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.TransformObject:_setParent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TransformObject__setParent'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_TransformObject_getParent(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::TransformObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.TransformObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::TransformObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TransformObject_getParent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_TransformObject_getParent'", nullptr);
            return 0;
        }
        dragonBones::Bone* ret = cobj->getParent();
        object_to_luaval<dragonBones::Bone>(tolua_S, "db.Bone",(dragonBones::Bone*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.TransformObject:getParent",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TransformObject_getParent'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_TransformObject_getArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::TransformObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.TransformObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::TransformObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TransformObject_getArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_TransformObject_getArmature'", nullptr);
            return 0;
        }
        dragonBones::Armature* ret = cobj->getArmature();
        object_to_luaval<dragonBones::Armature>(tolua_S, "db.Armature",(dragonBones::Armature*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.TransformObject:getArmature",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TransformObject_getArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_TransformObject_getglobal(lua_State* tolua_S)
{
    dragonBones::TransformObject* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.TransformObject",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::TransformObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TransformObject_getglobal'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<dragonBones::Transform>(tolua_S, "db.Transform",(dragonBones::Transform*)&cobj->global);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TransformObject_getglobal'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_TransformObject_setglobal(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::TransformObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.TransformObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::TransformObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TransformObject_setglobal'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        dragonBones::Transform* arg0 = nullptr;
        ok &= luaval_to_object<dragonBones::Transform>(tolua_S, 2, "db.Transform",&arg0, "db.TransformObject:global");
        cobj->global = *arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.TransformObject:global",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TransformObject_getglobal'.",&tolua_err);
    return 0;
#endif
}int lua_dragonbones_TransformObject_getorigin(lua_State* tolua_S)
{
    dragonBones::TransformObject* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.TransformObject",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::TransformObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TransformObject_getorigin'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<dragonBones::Transform>(tolua_S, "db.Transform",(dragonBones::Transform*)&cobj->origin);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TransformObject_getorigin'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_TransformObject_setorigin(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::TransformObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.TransformObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::TransformObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TransformObject_setorigin'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        dragonBones::Transform* arg0 = nullptr;
        ok &= luaval_to_object<dragonBones::Transform>(tolua_S, 2, "db.Transform",&arg0, "db.TransformObject:origin");
        cobj->origin = *arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.TransformObject:origin",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TransformObject_getorigin'.",&tolua_err);
    return 0;
#endif
}int lua_dragonbones_TransformObject_getoffset(lua_State* tolua_S)
{
    dragonBones::TransformObject* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.TransformObject",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::TransformObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TransformObject_getoffset'", nullptr);
        return 0;
    }
#endif

    object_to_luaval<dragonBones::Transform>(tolua_S, "db.Transform",(dragonBones::Transform*)&cobj->offset);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TransformObject_getoffset'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_TransformObject_setoffset(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::TransformObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.TransformObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::TransformObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_TransformObject_setoffset'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        dragonBones::Transform* arg0 = nullptr;
        ok &= luaval_to_object<dragonBones::Transform>(tolua_S, 2, "db.Transform",&arg0, "db.TransformObject:offset");
        cobj->offset = *arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.TransformObject:offset",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_TransformObject_getoffset'.",&tolua_err);
    return 0;
#endif
}static int lua_dragonbones_TransformObject_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TransformObject)");
    return 0;
}

int lua_register_dragonbones_TransformObject(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.TransformObject");
    tolua_cclass(tolua_S,"TransformObject","db.TransformObject","db.BaseObject",nullptr);

    tolua_beginmodule(tolua_S,"TransformObject");
        tolua_function(tolua_S,"_setArmature",lua_dragonbones_TransformObject__setArmature);
        tolua_function(tolua_S,"_setParent",lua_dragonbones_TransformObject__setParent);
        tolua_function(tolua_S,"getParent",lua_dragonbones_TransformObject_getParent);
        tolua_function(tolua_S,"getArmature",lua_dragonbones_TransformObject_getArmature);
        tolua_variable(tolua_S,"global", lua_dragonbones_TransformObject_getglobal, lua_dragonbones_TransformObject_setglobal);
        tolua_variable(tolua_S,"origin", lua_dragonbones_TransformObject_getorigin, lua_dragonbones_TransformObject_setorigin);
        tolua_variable(tolua_S,"offset", lua_dragonbones_TransformObject_getoffset, lua_dragonbones_TransformObject_setoffset);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::TransformObject).name();
    g_luaType[typeName] = "db.TransformObject";
    g_typeCast["TransformObject"] = "db.TransformObject";
    return 1;
}

int lua_dragonbones_Bone_getIK(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Bone_getIK'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Bone_getIK'", nullptr);
            return 0;
        }
        dragonBones::Bone* ret = cobj->getIK();
        object_to_luaval<dragonBones::Bone>(tolua_S, "db.Bone",(dragonBones::Bone*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Bone:getIK",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Bone_getIK'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Bone__setIK(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Bone__setIK'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        dragonBones::Bone* arg0;
        unsigned int arg1;
        int arg2;

        ok &= luaval_to_object<dragonBones::Bone>(tolua_S, 2, "db.Bone",&arg0, "db.Bone:_setIK");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "db.Bone:_setIK");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.Bone:_setIK");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Bone__setIK'", nullptr);
            return 0;
        }
        cobj->_setIK(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Bone:_setIK",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Bone__setIK'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Bone_getIKChainIndex(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Bone_getIKChainIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Bone_getIKChainIndex'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getIKChainIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Bone:getIKChainIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Bone_getIKChainIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Bone_contains(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Bone_contains'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const dragonBones::TransformObject* arg0;

        ok &= luaval_to_object<const dragonBones::TransformObject>(tolua_S, 2, "db.TransformObject",&arg0, "db.Bone:contains");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Bone_contains'", nullptr);
            return 0;
        }
        bool ret = cobj->contains(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Bone:contains",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Bone_contains'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Bone_getIKChain(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Bone_getIKChain'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Bone_getIKChain'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getIKChain();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Bone:getIKChain",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Bone_getIKChain'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Bone_getVisible(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Bone_getVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Bone_getVisible'", nullptr);
            return 0;
        }
        bool ret = cobj->getVisible();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Bone:getVisible",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Bone_getVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Bone__update(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Bone__update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "db.Bone:_update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Bone__update'", nullptr);
            return 0;
        }
        cobj->_update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Bone:_update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Bone__update'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Bone_setVisible(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Bone_setVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "db.Bone:setVisible");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Bone_setVisible'", nullptr);
            return 0;
        }
        cobj->setVisible(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Bone:setVisible",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Bone_setVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Bone_invalidUpdate(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Bone*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Bone_invalidUpdate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Bone_invalidUpdate'", nullptr);
            return 0;
        }
        cobj->invalidUpdate();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Bone:invalidUpdate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Bone_invalidUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Bone_getTypeIndex(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.Bone",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Bone_getTypeIndex'", nullptr);
            return 0;
        }
        unsigned int ret = dragonBones::Bone::getTypeIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.Bone:getTypeIndex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Bone_getTypeIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_Bone_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Bone* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Bone_constructor'", nullptr);
            return 0;
        }
        cobj = new dragonBones::Bone();
        tolua_pushusertype(tolua_S,(void*)cobj,"db.Bone");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Bone:Bone",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Bone_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_Bone_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Bone)");
    return 0;
}

int lua_register_dragonbones_Bone(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.Bone");
    tolua_cclass(tolua_S,"Bone","db.Bone","db.TransformObject",nullptr);

    tolua_beginmodule(tolua_S,"Bone");
        tolua_function(tolua_S,"new",lua_dragonbones_Bone_constructor);
        tolua_function(tolua_S,"getIK",lua_dragonbones_Bone_getIK);
        tolua_function(tolua_S,"_setIK",lua_dragonbones_Bone__setIK);
        tolua_function(tolua_S,"getIKChainIndex",lua_dragonbones_Bone_getIKChainIndex);
        tolua_function(tolua_S,"contains",lua_dragonbones_Bone_contains);
        tolua_function(tolua_S,"getIKChain",lua_dragonbones_Bone_getIKChain);
        tolua_function(tolua_S,"getVisible",lua_dragonbones_Bone_getVisible);
        tolua_function(tolua_S,"_update",lua_dragonbones_Bone__update);
        tolua_function(tolua_S,"setVisible",lua_dragonbones_Bone_setVisible);
        tolua_function(tolua_S,"invalidUpdate",lua_dragonbones_Bone_invalidUpdate);
        tolua_function(tolua_S,"getTypeIndex", lua_dragonbones_Bone_getTypeIndex);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::Bone).name();
    g_luaType[typeName] = "db.Bone";
    g_typeCast["Bone"] = "db.Bone";
    return 1;
}

int lua_dragonbones_Slot__update(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot__update'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "db.Slot:_update");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot__update'", nullptr);
            return 0;
        }
        cobj->_update(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:_update",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot__update'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_getRawDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_getRawDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot_getRawDisplay'", nullptr);
            return 0;
        }
        void* ret = cobj->getRawDisplay();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:getRawDisplay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_getRawDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot__updateBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot__updateBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot__updateBlendMode'", nullptr);
            return 0;
        }
        cobj->_updateBlendMode();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:_updateBlendMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot__updateBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_getChildArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_getChildArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot_getChildArmature'", nullptr);
            return 0;
        }
        dragonBones::Armature* ret = cobj->getChildArmature();
        object_to_luaval<dragonBones::Armature>(tolua_S, "db.Armature",(dragonBones::Armature*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:getChildArmature",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_getChildArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_getDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_getDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot_getDisplay'", nullptr);
            return 0;
        }
        void* ret = cobj->getDisplay();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:getDisplay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_getDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_getMeshDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_getMeshDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot_getMeshDisplay'", nullptr);
            return 0;
        }
        void* ret = cobj->getMeshDisplay();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:getMeshDisplay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_getMeshDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_setDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_setDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        void* arg0;
        dragonBones::DisplayType arg1;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "db.Slot:setDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot_setDisplay'", nullptr);
            return 0;
        }
        cobj->setDisplay(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:setDisplay",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_setDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_invalidUpdate(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_invalidUpdate'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot_invalidUpdate'", nullptr);
            return 0;
        }
        cobj->invalidUpdate();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:invalidUpdate",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_invalidUpdate'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot__updateMeshData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot__updateMeshData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "db.Slot:_updateMeshData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot__updateMeshData'", nullptr);
            return 0;
        }
        cobj->_updateMeshData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:_updateMeshData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot__updateMeshData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot__setBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot__setBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::BlendMode arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "db.Slot:_setBlendMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot__setBlendMode'", nullptr);
            return 0;
        }
        bool ret = cobj->_setBlendMode(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:_setBlendMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot__setBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_setDisplayIndex(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_setDisplayIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "db.Slot:setDisplayIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot_setDisplayIndex'", nullptr);
            return 0;
        }
        cobj->setDisplayIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:setDisplayIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_setDisplayIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot__updateVisible(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot__updateVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot__updateVisible'", nullptr);
            return 0;
        }
        cobj->_updateVisible();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:_updateVisible",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot__updateVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_setChildArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_setChildArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Armature* arg0;

        ok &= luaval_to_object<dragonBones::Armature>(tolua_S, 2, "db.Armature",&arg0, "db.Slot:setChildArmature");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot_setChildArmature'", nullptr);
            return 0;
        }
        cobj->setChildArmature(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:setChildArmature",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_setChildArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot__setDisplayIndex(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot__setDisplayIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "db.Slot:_setDisplayIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot__setDisplayIndex'", nullptr);
            return 0;
        }
        bool ret = cobj->_setDisplayIndex(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:_setDisplayIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot__setDisplayIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_getDisplayIndex(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_getDisplayIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_Slot_getDisplayIndex'", nullptr);
            return 0;
        }
        int ret = cobj->getDisplayIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:getDisplayIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_getDisplayIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_Slot_getdisplayController(lua_State* tolua_S)
{
    dragonBones::Slot* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_getdisplayController'", nullptr);
        return 0;
    }
#endif

    tolua_pushcppstring(tolua_S,cobj->displayController);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_getdisplayController'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_Slot_setdisplayController(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::Slot* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.Slot",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::Slot*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_Slot_setdisplayController'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.Slot:displayController");
        cobj->displayController = arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.Slot:displayController",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_Slot_getdisplayController'.",&tolua_err);
    return 0;
#endif
}static int lua_dragonbones_Slot_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Slot)");
    return 0;
}

int lua_register_dragonbones_Slot(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.Slot");
    tolua_cclass(tolua_S,"Slot","db.Slot","db.TransformObject",nullptr);

    tolua_beginmodule(tolua_S,"Slot");
        tolua_function(tolua_S,"_update",lua_dragonbones_Slot__update);
        tolua_function(tolua_S,"getRawDisplay",lua_dragonbones_Slot_getRawDisplay);
        tolua_function(tolua_S,"_updateBlendMode",lua_dragonbones_Slot__updateBlendMode);
        tolua_function(tolua_S,"getChildArmature",lua_dragonbones_Slot_getChildArmature);
        tolua_function(tolua_S,"getDisplay",lua_dragonbones_Slot_getDisplay);
        tolua_function(tolua_S,"getMeshDisplay",lua_dragonbones_Slot_getMeshDisplay);
        tolua_function(tolua_S,"setDisplay",lua_dragonbones_Slot_setDisplay);
        tolua_function(tolua_S,"invalidUpdate",lua_dragonbones_Slot_invalidUpdate);
        tolua_function(tolua_S,"_updateMeshData",lua_dragonbones_Slot__updateMeshData);
        tolua_function(tolua_S,"_setBlendMode",lua_dragonbones_Slot__setBlendMode);
        tolua_function(tolua_S,"setDisplayIndex",lua_dragonbones_Slot_setDisplayIndex);
        tolua_function(tolua_S,"_updateVisible",lua_dragonbones_Slot__updateVisible);
        tolua_function(tolua_S,"setChildArmature",lua_dragonbones_Slot_setChildArmature);
        tolua_function(tolua_S,"_setDisplayIndex",lua_dragonbones_Slot__setDisplayIndex);
        tolua_function(tolua_S,"getDisplayIndex",lua_dragonbones_Slot_getDisplayIndex);
        tolua_variable(tolua_S,"displayController", lua_dragonbones_Slot_getdisplayController, lua_dragonbones_Slot_setdisplayController);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::Slot).name();
    g_luaType[typeName] = "db.Slot";
    g_typeCast["Slot"] = "db.Slot";
    return 1;
}

int lua_dragonbones_BaseFactory_lua_replaceSlotDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_lua_replaceSlotDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        dragonBones::Slot* arg4;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.BaseFactory:lua_replaceSlotDisplay");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:lua_replaceSlotDisplay");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.BaseFactory:lua_replaceSlotDisplay");

        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "db.BaseFactory:lua_replaceSlotDisplay");

        ok &= luaval_to_object<dragonBones::Slot>(tolua_S, 6, "db.Slot",&arg4, "db.BaseFactory:lua_replaceSlotDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_lua_replaceSlotDisplay'", nullptr);
            return 0;
        }
        cobj->lua_replaceSlotDisplay(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 6) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        dragonBones::Slot* arg4;
        int arg5;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.BaseFactory:lua_replaceSlotDisplay");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:lua_replaceSlotDisplay");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.BaseFactory:lua_replaceSlotDisplay");

        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "db.BaseFactory:lua_replaceSlotDisplay");

        ok &= luaval_to_object<dragonBones::Slot>(tolua_S, 6, "db.Slot",&arg4, "db.BaseFactory:lua_replaceSlotDisplay");

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "db.BaseFactory:lua_replaceSlotDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_lua_replaceSlotDisplay'", nullptr);
            return 0;
        }
        cobj->lua_replaceSlotDisplay(arg0, arg1, arg2, arg3, arg4, arg5);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:lua_replaceSlotDisplay",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_lua_replaceSlotDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_removeDragonBonesData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_removeDragonBonesData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.BaseFactory:removeDragonBonesData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_removeDragonBonesData'", nullptr);
            return 0;
        }
        cobj->removeDragonBonesData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.BaseFactory:removeDragonBonesData");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "db.BaseFactory:removeDragonBonesData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_removeDragonBonesData'", nullptr);
            return 0;
        }
        cobj->removeDragonBonesData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:removeDragonBonesData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_removeDragonBonesData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_removeTextureAtlasData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_removeTextureAtlasData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.BaseFactory:removeTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_removeTextureAtlasData'", nullptr);
            return 0;
        }
        cobj->removeTextureAtlasData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.BaseFactory:removeTextureAtlasData");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "db.BaseFactory:removeTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_removeTextureAtlasData'", nullptr);
            return 0;
        }
        cobj->removeTextureAtlasData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:removeTextureAtlasData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_removeTextureAtlasData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_parseDragonBonesData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_parseDragonBonesData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "db.BaseFactory:parseDragonBonesData"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_parseDragonBonesData'", nullptr);
            return 0;
        }
        dragonBones::DragonBonesData* ret = cobj->parseDragonBonesData(arg0);
        object_to_luaval<dragonBones::DragonBonesData>(tolua_S, "db.DragonBonesData",(dragonBones::DragonBonesData*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        const char* arg0;
        std::string arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "db.BaseFactory:parseDragonBonesData"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:parseDragonBonesData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_parseDragonBonesData'", nullptr);
            return 0;
        }
        dragonBones::DragonBonesData* ret = cobj->parseDragonBonesData(arg0, arg1);
        object_to_luaval<dragonBones::DragonBonesData>(tolua_S, "db.DragonBonesData",(dragonBones::DragonBonesData*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        const char* arg0;
        std::string arg1;
        double arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "db.BaseFactory:parseDragonBonesData"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:parseDragonBonesData");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "db.BaseFactory:parseDragonBonesData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_parseDragonBonesData'", nullptr);
            return 0;
        }
        dragonBones::DragonBonesData* ret = cobj->parseDragonBonesData(arg0, arg1, arg2);
        object_to_luaval<dragonBones::DragonBonesData>(tolua_S, "db.DragonBonesData",(dragonBones::DragonBonesData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:parseDragonBonesData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_parseDragonBonesData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_clear(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "db.BaseFactory:clear");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_clear'", nullptr);
            return 0;
        }
        cobj->clear(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_addDragonBonesData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_addDragonBonesData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::DragonBonesData* arg0;

        ok &= luaval_to_object<dragonBones::DragonBonesData>(tolua_S, 2, "db.DragonBonesData",&arg0, "db.BaseFactory:addDragonBonesData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_addDragonBonesData'", nullptr);
            return 0;
        }
        cobj->addDragonBonesData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        dragonBones::DragonBonesData* arg0;
        std::string arg1;

        ok &= luaval_to_object<dragonBones::DragonBonesData>(tolua_S, 2, "db.DragonBonesData",&arg0, "db.BaseFactory:addDragonBonesData");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:addDragonBonesData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_addDragonBonesData'", nullptr);
            return 0;
        }
        cobj->addDragonBonesData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:addDragonBonesData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_addDragonBonesData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_buildArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_buildArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.BaseFactory:buildArmature");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_buildArmature'", nullptr);
            return 0;
        }
        dragonBones::Armature* ret = cobj->buildArmature(arg0);
        object_to_luaval<dragonBones::Armature>(tolua_S, "db.Armature",(dragonBones::Armature*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.BaseFactory:buildArmature");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:buildArmature");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_buildArmature'", nullptr);
            return 0;
        }
        dragonBones::Armature* ret = cobj->buildArmature(arg0, arg1);
        object_to_luaval<dragonBones::Armature>(tolua_S, "db.Armature",(dragonBones::Armature*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.BaseFactory:buildArmature");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:buildArmature");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.BaseFactory:buildArmature");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_buildArmature'", nullptr);
            return 0;
        }
        dragonBones::Armature* ret = cobj->buildArmature(arg0, arg1, arg2);
        object_to_luaval<dragonBones::Armature>(tolua_S, "db.Armature",(dragonBones::Armature*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:buildArmature",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_buildArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_addTextureAtlasData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_addTextureAtlasData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::TextureAtlasData* arg0;

        ok &= luaval_to_object<dragonBones::TextureAtlasData>(tolua_S, 2, "db.TextureAtlasData",&arg0, "db.BaseFactory:addTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_addTextureAtlasData'", nullptr);
            return 0;
        }
        cobj->addTextureAtlasData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        dragonBones::TextureAtlasData* arg0;
        std::string arg1;

        ok &= luaval_to_object<dragonBones::TextureAtlasData>(tolua_S, 2, "db.TextureAtlasData",&arg0, "db.BaseFactory:addTextureAtlasData");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:addTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_addTextureAtlasData'", nullptr);
            return 0;
        }
        cobj->addTextureAtlasData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:addTextureAtlasData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_addTextureAtlasData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_getDragonBonesData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_getDragonBonesData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.BaseFactory:getDragonBonesData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_getDragonBonesData'", nullptr);
            return 0;
        }
        dragonBones::DragonBonesData* ret = cobj->getDragonBonesData(arg0);
        object_to_luaval<dragonBones::DragonBonesData>(tolua_S, "db.DragonBonesData",(dragonBones::DragonBonesData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:getDragonBonesData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_getDragonBonesData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_parseTextureAtlasData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_parseTextureAtlasData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        void* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "db.BaseFactory:parseTextureAtlasData"); arg0 = arg0_tmp.c_str();

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_parseTextureAtlasData'", nullptr);
            return 0;
        }
        dragonBones::TextureAtlasData* ret = cobj->parseTextureAtlasData(arg0, arg1);
        object_to_luaval<dragonBones::TextureAtlasData>(tolua_S, "db.TextureAtlasData",(dragonBones::TextureAtlasData*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        const char* arg0;
        void* arg1;
        std::string arg2;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "db.BaseFactory:parseTextureAtlasData"); arg0 = arg0_tmp.c_str();

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.BaseFactory:parseTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_parseTextureAtlasData'", nullptr);
            return 0;
        }
        dragonBones::TextureAtlasData* ret = cobj->parseTextureAtlasData(arg0, arg1, arg2);
        object_to_luaval<dragonBones::TextureAtlasData>(tolua_S, "db.TextureAtlasData",(dragonBones::TextureAtlasData*)ret);
        return 1;
    }
    if (argc == 4) 
    {
        const char* arg0;
        void* arg1;
        std::string arg2;
        double arg3;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "db.BaseFactory:parseTextureAtlasData"); arg0 = arg0_tmp.c_str();

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.BaseFactory:parseTextureAtlasData");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "db.BaseFactory:parseTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_parseTextureAtlasData'", nullptr);
            return 0;
        }
        dragonBones::TextureAtlasData* ret = cobj->parseTextureAtlasData(arg0, arg1, arg2, arg3);
        object_to_luaval<dragonBones::TextureAtlasData>(tolua_S, "db.TextureAtlasData",(dragonBones::TextureAtlasData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:parseTextureAtlasData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_parseTextureAtlasData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_lua_replaceSlotDisplayList(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_lua_replaceSlotDisplayList'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        dragonBones::Slot* arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.BaseFactory:lua_replaceSlotDisplayList");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:lua_replaceSlotDisplayList");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.BaseFactory:lua_replaceSlotDisplayList");

        ok &= luaval_to_object<dragonBones::Slot>(tolua_S, 5, "db.Slot",&arg3, "db.BaseFactory:lua_replaceSlotDisplayList");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_lua_replaceSlotDisplayList'", nullptr);
            return 0;
        }
        cobj->lua_replaceSlotDisplayList(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:lua_replaceSlotDisplayList",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_lua_replaceSlotDisplayList'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_BaseFactory_lua_copyAnimationsToArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::BaseFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.BaseFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::BaseFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_BaseFactory_lua_copyAnimationsToArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        dragonBones::Armature* arg0;
        std::string arg1;

        ok &= luaval_to_object<dragonBones::Armature>(tolua_S, 2, "db.Armature",&arg0, "db.BaseFactory:lua_copyAnimationsToArmature");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:lua_copyAnimationsToArmature");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_lua_copyAnimationsToArmature'", nullptr);
            return 0;
        }
        bool ret = cobj->lua_copyAnimationsToArmature(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        dragonBones::Armature* arg0;
        std::string arg1;
        std::string arg2;

        ok &= luaval_to_object<dragonBones::Armature>(tolua_S, 2, "db.Armature",&arg0, "db.BaseFactory:lua_copyAnimationsToArmature");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:lua_copyAnimationsToArmature");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.BaseFactory:lua_copyAnimationsToArmature");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_lua_copyAnimationsToArmature'", nullptr);
            return 0;
        }
        bool ret = cobj->lua_copyAnimationsToArmature(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 4) 
    {
        dragonBones::Armature* arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;

        ok &= luaval_to_object<dragonBones::Armature>(tolua_S, 2, "db.Armature",&arg0, "db.BaseFactory:lua_copyAnimationsToArmature");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:lua_copyAnimationsToArmature");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.BaseFactory:lua_copyAnimationsToArmature");

        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "db.BaseFactory:lua_copyAnimationsToArmature");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_lua_copyAnimationsToArmature'", nullptr);
            return 0;
        }
        bool ret = cobj->lua_copyAnimationsToArmature(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 5) 
    {
        dragonBones::Armature* arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        bool arg4;

        ok &= luaval_to_object<dragonBones::Armature>(tolua_S, 2, "db.Armature",&arg0, "db.BaseFactory:lua_copyAnimationsToArmature");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.BaseFactory:lua_copyAnimationsToArmature");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.BaseFactory:lua_copyAnimationsToArmature");

        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "db.BaseFactory:lua_copyAnimationsToArmature");

        ok &= luaval_to_boolean(tolua_S, 6,&arg4, "db.BaseFactory:lua_copyAnimationsToArmature");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_BaseFactory_lua_copyAnimationsToArmature'", nullptr);
            return 0;
        }
        bool ret = cobj->lua_copyAnimationsToArmature(arg0, arg1, arg2, arg3, arg4);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.BaseFactory:lua_copyAnimationsToArmature",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_BaseFactory_lua_copyAnimationsToArmature'.",&tolua_err);
#endif

    return 0;
}
static int lua_dragonbones_BaseFactory_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BaseFactory)");
    return 0;
}

int lua_register_dragonbones_BaseFactory(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.BaseFactory");
    tolua_cclass(tolua_S,"BaseFactory","db.BaseFactory","",nullptr);

    tolua_beginmodule(tolua_S,"BaseFactory");
        tolua_function(tolua_S,"replaceSlotDisplay",lua_dragonbones_BaseFactory_lua_replaceSlotDisplay);
        tolua_function(tolua_S,"removeDragonBonesData",lua_dragonbones_BaseFactory_removeDragonBonesData);
        tolua_function(tolua_S,"removeTextureAtlasData",lua_dragonbones_BaseFactory_removeTextureAtlasData);
        tolua_function(tolua_S,"parseDragonBonesData",lua_dragonbones_BaseFactory_parseDragonBonesData);
        tolua_function(tolua_S,"clear",lua_dragonbones_BaseFactory_clear);
        tolua_function(tolua_S,"addDragonBonesData",lua_dragonbones_BaseFactory_addDragonBonesData);
        tolua_function(tolua_S,"buildArmature",lua_dragonbones_BaseFactory_buildArmature);
        tolua_function(tolua_S,"addTextureAtlasData",lua_dragonbones_BaseFactory_addTextureAtlasData);
        tolua_function(tolua_S,"getDragonBonesData",lua_dragonbones_BaseFactory_getDragonBonesData);
        tolua_function(tolua_S,"parseTextureAtlasData",lua_dragonbones_BaseFactory_parseTextureAtlasData);
        tolua_function(tolua_S,"replaceSlotDisplayList",lua_dragonbones_BaseFactory_lua_replaceSlotDisplayList);
        tolua_function(tolua_S,"copyAnimationsToArmature",lua_dragonbones_BaseFactory_lua_copyAnimationsToArmature);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::BaseFactory).name();
    g_luaType[typeName] = "db.BaseFactory";
    g_typeCast["BaseFactory"] = "db.BaseFactory";
    return 1;
}

int lua_dragonbones_WorldClock_clear(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::WorldClock*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_WorldClock_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_WorldClock_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.WorldClock:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_WorldClock_contains(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::WorldClock*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_WorldClock_contains'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const dragonBones::IAnimateble* arg0;

        ok &= luaval_to_object<const dragonBones::IAnimateble>(tolua_S, 2, "db.IAnimateble",&arg0, "db.WorldClock:contains");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_WorldClock_contains'", nullptr);
            return 0;
        }
        bool ret = cobj->contains(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.WorldClock:contains",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_contains'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_WorldClock_lua_advanceTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::WorldClock*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_WorldClock_lua_advanceTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.WorldClock:lua_advanceTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_WorldClock_lua_advanceTime'", nullptr);
            return 0;
        }
        cobj->lua_advanceTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.WorldClock:lua_advanceTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_lua_advanceTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_WorldClock_lua_remove(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::WorldClock*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_WorldClock_lua_remove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Armature* arg0;

        ok &= luaval_to_object<dragonBones::Armature>(tolua_S, 2, "db.Armature",&arg0, "db.WorldClock:lua_remove");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_WorldClock_lua_remove'", nullptr);
            return 0;
        }
        cobj->lua_remove(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.WorldClock:lua_remove",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_lua_remove'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_WorldClock_lua_add(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::WorldClock*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_WorldClock_lua_add'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::Armature* arg0;

        ok &= luaval_to_object<dragonBones::Armature>(tolua_S, 2, "db.Armature",&arg0, "db.WorldClock:lua_add");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_WorldClock_lua_add'", nullptr);
            return 0;
        }
        cobj->lua_add(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.WorldClock:lua_add",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_lua_add'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_WorldClock_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.WorldClock",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_WorldClock_getInstance'", nullptr);
            return 0;
        }
        dragonBones::WorldClock* ret = dragonBones::WorldClock::getInstance();
        object_to_luaval<dragonBones::WorldClock>(tolua_S, "db.WorldClock",(dragonBones::WorldClock*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.WorldClock:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_WorldClock_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::WorldClock* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_WorldClock_constructor'", nullptr);
            return 0;
        }
        cobj = new dragonBones::WorldClock();
        tolua_pushusertype(tolua_S,(void*)cobj,"db.WorldClock");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.WorldClock:WorldClock",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_WorldClock_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_WorldClock_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (WorldClock)");
    return 0;
}

int lua_register_dragonbones_WorldClock(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.WorldClock");
    tolua_cclass(tolua_S,"WorldClock","db.WorldClock","db.IAnimateble",nullptr);

    tolua_beginmodule(tolua_S,"WorldClock");
        tolua_function(tolua_S,"new",lua_dragonbones_WorldClock_constructor);
        tolua_function(tolua_S,"clear",lua_dragonbones_WorldClock_clear);
        tolua_function(tolua_S,"contains",lua_dragonbones_WorldClock_contains);
        tolua_function(tolua_S,"advanceTime",lua_dragonbones_WorldClock_lua_advanceTime);
        tolua_function(tolua_S,"remove",lua_dragonbones_WorldClock_lua_remove);
        tolua_function(tolua_S,"add",lua_dragonbones_WorldClock_lua_add);
        tolua_function(tolua_S,"getInstance", lua_dragonbones_WorldClock_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::WorldClock).name();
    g_luaType[typeName] = "db.WorldClock";
    g_typeCast["WorldClock"] = "db.WorldClock";
    return 1;
}

int lua_dragonbones_AnimationState_setCurrentTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_setCurrentTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.AnimationState:setCurrentTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_setCurrentTime'", nullptr);
            return 0;
        }
        cobj->setCurrentTime(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:setCurrentTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_setCurrentTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState__updateTimelineStates(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState__updateTimelineStates'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState__updateTimelineStates'", nullptr);
            return 0;
        }
        cobj->_updateTimelineStates();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:_updateTimelineStates",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState__updateTimelineStates'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_removeBoneMask(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_removeBoneMask'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.AnimationState:removeBoneMask");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_removeBoneMask'", nullptr);
            return 0;
        }
        cobj->removeBoneMask(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.AnimationState:removeBoneMask");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "db.AnimationState:removeBoneMask");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_removeBoneMask'", nullptr);
            return 0;
        }
        cobj->removeBoneMask(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:removeBoneMask",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_removeBoneMask'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getGroup(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getGroup'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_getGroup'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getGroup();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:getGroup",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getGroup'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getCurrentPlayTimes(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getCurrentPlayTimes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_getCurrentPlayTimes'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getCurrentPlayTimes();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:getCurrentPlayTimes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getCurrentPlayTimes'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getName(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_getName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_lua_getAnimationData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_lua_getAnimationData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_lua_getAnimationData'", nullptr);
            return 0;
        }
        const dragonBones::AnimationData* ret = cobj->lua_getAnimationData();
        object_to_luaval<dragonBones::AnimationData>(tolua_S, "db.AnimationData",(dragonBones::AnimationData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:lua_getAnimationData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_lua_getAnimationData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getCurrentTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getCurrentTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_getCurrentTime'", nullptr);
            return 0;
        }
        double ret = cobj->getCurrentTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:getCurrentTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getCurrentTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState__fadeIn(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState__fadeIn'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 10) 
    {
        dragonBones::Armature* arg0;
        dragonBones::AnimationData* arg1;
        std::string arg2;
        unsigned int arg3;
        double arg4;
        double arg5;
        double arg6;
        double arg7;
        double arg8;
        bool arg9;

        ok &= luaval_to_object<dragonBones::Armature>(tolua_S, 2, "db.Armature",&arg0, "db.AnimationState:_fadeIn");

        ok &= luaval_to_object<dragonBones::AnimationData>(tolua_S, 3, "db.AnimationData",&arg1, "db.AnimationState:_fadeIn");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.AnimationState:_fadeIn");

        ok &= luaval_to_uint32(tolua_S, 5,&arg3, "db.AnimationState:_fadeIn");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "db.AnimationState:_fadeIn");

        ok &= luaval_to_number(tolua_S, 7,&arg5, "db.AnimationState:_fadeIn");

        ok &= luaval_to_number(tolua_S, 8,&arg6, "db.AnimationState:_fadeIn");

        ok &= luaval_to_number(tolua_S, 9,&arg7, "db.AnimationState:_fadeIn");

        ok &= luaval_to_number(tolua_S, 10,&arg8, "db.AnimationState:_fadeIn");

        ok &= luaval_to_boolean(tolua_S, 11,&arg9, "db.AnimationState:_fadeIn");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState__fadeIn'", nullptr);
            return 0;
        }
        cobj->_fadeIn(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:_fadeIn",argc, 10);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState__fadeIn'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getTotalTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getTotalTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_getTotalTime'", nullptr);
            return 0;
        }
        double ret = cobj->getTotalTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:getTotalTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getTotalTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_removeAllBoneMask(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_removeAllBoneMask'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_removeAllBoneMask'", nullptr);
            return 0;
        }
        cobj->removeAllBoneMask();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:removeAllBoneMask",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_removeAllBoneMask'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getLayer(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getLayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_getLayer'", nullptr);
            return 0;
        }
        int ret = cobj->getLayer();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:getLayer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getLayer'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_isCompleted(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_isCompleted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_isCompleted'", nullptr);
            return 0;
        }
        bool ret = cobj->isCompleted();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:isCompleted",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_isCompleted'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_play(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_play'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_play'", nullptr);
            return 0;
        }
        cobj->play();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:play",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_play'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_fadeOut(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_fadeOut'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.AnimationState:fadeOut");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_fadeOut'", nullptr);
            return 0;
        }
        cobj->fadeOut(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        double arg0;
        bool arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.AnimationState:fadeOut");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "db.AnimationState:fadeOut");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_fadeOut'", nullptr);
            return 0;
        }
        cobj->fadeOut(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:fadeOut",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_fadeOut'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_stop(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_stop'", nullptr);
            return 0;
        }
        cobj->stop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_isPlaying(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_isPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_isPlaying'", nullptr);
            return 0;
        }
        bool ret = cobj->isPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:isPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_isPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState__advanceTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState__advanceTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        double arg1;
        int arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.AnimationState:_advanceTime");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "db.AnimationState:_advanceTime");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "db.AnimationState:_advanceTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState__advanceTime'", nullptr);
            return 0;
        }
        cobj->_advanceTime(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:_advanceTime",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState__advanceTime'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState__updateFFDTimelineStates(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState__updateFFDTimelineStates'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState__updateFFDTimelineStates'", nullptr);
            return 0;
        }
        cobj->_updateFFDTimelineStates();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:_updateFFDTimelineStates",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState__updateFFDTimelineStates'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_addBoneMask(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_addBoneMask'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.AnimationState:addBoneMask");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_addBoneMask'", nullptr);
            return 0;
        }
        cobj->addBoneMask(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.AnimationState:addBoneMask");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "db.AnimationState:addBoneMask");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_addBoneMask'", nullptr);
            return 0;
        }
        cobj->addBoneMask(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:addBoneMask",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_addBoneMask'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_containsBoneMask(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_containsBoneMask'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.AnimationState:containsBoneMask");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_containsBoneMask'", nullptr);
            return 0;
        }
        bool ret = cobj->containsBoneMask(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:containsBoneMask",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_containsBoneMask'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_AnimationState_getTypeIndex(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_getTypeIndex'", nullptr);
            return 0;
        }
        unsigned int ret = dragonBones::AnimationState::getTypeIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.AnimationState:getTypeIndex",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getTypeIndex'.",&tolua_err);
#endif
    return 0;
}
int lua_dragonbones_AnimationState_gettimeScale(lua_State* tolua_S)
{
    dragonBones::AnimationState* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_gettimeScale'", nullptr);
        return 0;
    }
#endif

    tolua_pushnumber(tolua_S,(lua_Number)cobj->timeScale);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_gettimeScale'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_AnimationState_settimeScale(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_settimeScale'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.AnimationState:timeScale");
        cobj->timeScale = arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:timeScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_gettimeScale'.",&tolua_err);
    return 0;
#endif
}int lua_dragonbones_AnimationState_getweight(lua_State* tolua_S)
{
    dragonBones::AnimationState* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getweight'", nullptr);
        return 0;
    }
#endif

    tolua_pushnumber(tolua_S,(lua_Number)cobj->weight);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getweight'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_AnimationState_setweight(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_setweight'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.AnimationState:weight");
        cobj->weight = arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:weight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getweight'.",&tolua_err);
    return 0;
#endif
}int lua_dragonbones_AnimationState_getautoFadeOutTime(lua_State* tolua_S)
{
    dragonBones::AnimationState* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getautoFadeOutTime'", nullptr);
        return 0;
    }
#endif

    tolua_pushnumber(tolua_S,(lua_Number)cobj->autoFadeOutTime);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getautoFadeOutTime'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_AnimationState_setautoFadeOutTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_setautoFadeOutTime'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.AnimationState:autoFadeOutTime");
        cobj->autoFadeOutTime = arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:autoFadeOutTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getautoFadeOutTime'.",&tolua_err);
    return 0;
#endif
}int lua_dragonbones_AnimationState_getfadeTotalTime(lua_State* tolua_S)
{
    dragonBones::AnimationState* cobj = nullptr;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_getfadeTotalTime'", nullptr);
        return 0;
    }
#endif

    tolua_pushnumber(tolua_S,(lua_Number)cobj->fadeTotalTime);

    return 1;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getfadeTotalTime'.",&tolua_err);
    return 0;
#endif
}

int lua_dragonbones_AnimationState_setfadeTotalTime(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
    if (!tolua_isusertype(tolua_S,1,"db.AnimationState",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::AnimationState*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_AnimationState_setfadeTotalTime'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S) - 1;

    if (1 == argc)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "db.AnimationState:fadeTotalTime");
        cobj->fadeTotalTime = arg0;
        return 0;
    }

    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:fadeTotalTime",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_getfadeTotalTime'.",&tolua_err);
    return 0;
#endif
}int lua_dragonbones_AnimationState_constructor(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::AnimationState* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_AnimationState_constructor'", nullptr);
            return 0;
        }
        cobj = new dragonBones::AnimationState();
        tolua_pushusertype(tolua_S,(void*)cobj,"db.AnimationState");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.AnimationState:AnimationState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_AnimationState_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_dragonbones_AnimationState_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (AnimationState)");
    return 0;
}

int lua_register_dragonbones_AnimationState(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.AnimationState");
    tolua_cclass(tolua_S,"AnimationState","db.AnimationState","db.BaseObject",nullptr);

    tolua_beginmodule(tolua_S,"AnimationState");
        tolua_function(tolua_S,"new",lua_dragonbones_AnimationState_constructor);
        tolua_function(tolua_S,"setCurrentTime",lua_dragonbones_AnimationState_setCurrentTime);
        tolua_function(tolua_S,"_updateTimelineStates",lua_dragonbones_AnimationState__updateTimelineStates);
        tolua_function(tolua_S,"removeBoneMask",lua_dragonbones_AnimationState_removeBoneMask);
        tolua_function(tolua_S,"getGroup",lua_dragonbones_AnimationState_getGroup);
        tolua_function(tolua_S,"getCurrentPlayTimes",lua_dragonbones_AnimationState_getCurrentPlayTimes);
        tolua_function(tolua_S,"getName",lua_dragonbones_AnimationState_getName);
        tolua_function(tolua_S,"getAnimationData",lua_dragonbones_AnimationState_lua_getAnimationData);
        tolua_function(tolua_S,"getCurrentTime",lua_dragonbones_AnimationState_getCurrentTime);
        tolua_function(tolua_S,"_fadeIn",lua_dragonbones_AnimationState__fadeIn);
        tolua_function(tolua_S,"getTotalTime",lua_dragonbones_AnimationState_getTotalTime);
        tolua_function(tolua_S,"removeAllBoneMask",lua_dragonbones_AnimationState_removeAllBoneMask);
        tolua_function(tolua_S,"getLayer",lua_dragonbones_AnimationState_getLayer);
        tolua_function(tolua_S,"isCompleted",lua_dragonbones_AnimationState_isCompleted);
        tolua_function(tolua_S,"play",lua_dragonbones_AnimationState_play);
        tolua_function(tolua_S,"fadeOut",lua_dragonbones_AnimationState_fadeOut);
        tolua_function(tolua_S,"stop",lua_dragonbones_AnimationState_stop);
        tolua_function(tolua_S,"isPlaying",lua_dragonbones_AnimationState_isPlaying);
        tolua_function(tolua_S,"_advanceTime",lua_dragonbones_AnimationState__advanceTime);
        tolua_function(tolua_S,"_updateFFDTimelineStates",lua_dragonbones_AnimationState__updateFFDTimelineStates);
        tolua_function(tolua_S,"addBoneMask",lua_dragonbones_AnimationState_addBoneMask);
        tolua_function(tolua_S,"containsBoneMask",lua_dragonbones_AnimationState_containsBoneMask);
        tolua_function(tolua_S,"getTypeIndex", lua_dragonbones_AnimationState_getTypeIndex);
        tolua_variable(tolua_S,"timeScale", lua_dragonbones_AnimationState_gettimeScale, lua_dragonbones_AnimationState_settimeScale);
        tolua_variable(tolua_S,"weight", lua_dragonbones_AnimationState_getweight, lua_dragonbones_AnimationState_setweight);
        tolua_variable(tolua_S,"autoFadeOutTime", lua_dragonbones_AnimationState_getautoFadeOutTime, lua_dragonbones_AnimationState_setautoFadeOutTime);
        tolua_variable(tolua_S,"fadeTotalTime", lua_dragonbones_AnimationState_getfadeTotalTime, lua_dragonbones_AnimationState_setfadeTotalTime);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::AnimationState).name();
    g_luaType[typeName] = "db.AnimationState";
    g_typeCast["AnimationState"] = "db.AnimationState";
    return 1;
}

int lua_dragonbones_CCEventObject_Slot(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCEventObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCEventObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCEventObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCEventObject_Slot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCEventObject_Slot'", nullptr);
            return 0;
        }
        dragonBones::Slot* ret = cobj->Slot();
        object_to_luaval<dragonBones::Slot>(tolua_S, "db.Slot",(dragonBones::Slot*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCEventObject:Slot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCEventObject_Slot'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCEventObject_UserData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCEventObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCEventObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCEventObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCEventObject_UserData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCEventObject_UserData'", nullptr);
            return 0;
        }
        void* ret = cobj->UserData();
        #pragma warning NO CONVERSION FROM NATIVE FOR void*;
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCEventObject:UserData",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCEventObject_UserData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCEventObject_Name(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCEventObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCEventObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCEventObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCEventObject_Name'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCEventObject_Name'", nullptr);
            return 0;
        }
        std::string ret = cobj->Name();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCEventObject:Name",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCEventObject_Name'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCEventObject_Frame(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCEventObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCEventObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCEventObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCEventObject_Frame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCEventObject_Frame'", nullptr);
            return 0;
        }
        dragonBones::AnimationFrameData* ret = cobj->Frame();
        object_to_luaval<dragonBones::AnimationFrameData>(tolua_S, "db.AnimationFrameData",(dragonBones::AnimationFrameData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCEventObject:Frame",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCEventObject_Frame'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCEventObject_AnimationState(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCEventObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCEventObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCEventObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCEventObject_AnimationState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCEventObject_AnimationState'", nullptr);
            return 0;
        }
        dragonBones::AnimationState* ret = cobj->AnimationState();
        object_to_luaval<dragonBones::AnimationState>(tolua_S, "db.AnimationState",(dragonBones::AnimationState*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCEventObject:AnimationState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCEventObject_AnimationState'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCEventObject_Armature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCEventObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCEventObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCEventObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCEventObject_Armature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCEventObject_Armature'", nullptr);
            return 0;
        }
        dragonBones::Armature* ret = cobj->Armature();
        object_to_luaval<dragonBones::Armature>(tolua_S, "db.Armature",(dragonBones::Armature*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCEventObject:Armature",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCEventObject_Armature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCEventObject_Type(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCEventObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCEventObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCEventObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCEventObject_Type'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCEventObject_Type'", nullptr);
            return 0;
        }
        std::string ret = cobj->Type();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCEventObject:Type",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCEventObject_Type'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCEventObject_Bone(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCEventObject* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCEventObject",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCEventObject*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCEventObject_Bone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCEventObject_Bone'", nullptr);
            return 0;
        }
        dragonBones::Bone* ret = cobj->Bone();
        object_to_luaval<dragonBones::Bone>(tolua_S, "db.Bone",(dragonBones::Bone*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCEventObject:Bone",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCEventObject_Bone'.",&tolua_err);
#endif

    return 0;
}
static int lua_dragonbones_CCEventObject_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCEventObject)");
    return 0;
}

int lua_register_dragonbones_CCEventObject(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.CCEventObject");
    tolua_cclass(tolua_S,"CCEventObject","db.CCEventObject","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"CCEventObject");
        tolua_function(tolua_S,"Slot",lua_dragonbones_CCEventObject_Slot);
        tolua_function(tolua_S,"UserData",lua_dragonbones_CCEventObject_UserData);
        tolua_function(tolua_S,"Name",lua_dragonbones_CCEventObject_Name);
        tolua_function(tolua_S,"Frame",lua_dragonbones_CCEventObject_Frame);
        tolua_function(tolua_S,"AnimationState",lua_dragonbones_CCEventObject_AnimationState);
        tolua_function(tolua_S,"Armature",lua_dragonbones_CCEventObject_Armature);
        tolua_function(tolua_S,"Type",lua_dragonbones_CCEventObject_Type);
        tolua_function(tolua_S,"Bone",lua_dragonbones_CCEventObject_Bone);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::CCEventObject).name();
    g_luaType[typeName] = "db.CCEventObject";
    g_typeCast["CCEventObject"] = "db.CCEventObject";
    return 1;
}

int lua_dragonbones_CCArmatureDisplay_removeDragonEventType(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCArmatureDisplay* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCArmatureDisplay",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCArmatureDisplay*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCArmatureDisplay_removeDragonEventType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCArmatureDisplay:removeDragonEventType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCArmatureDisplay_removeDragonEventType'", nullptr);
            return 0;
        }
        cobj->removeDragonEventType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCArmatureDisplay:removeDragonEventType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCArmatureDisplay_removeDragonEventType'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCArmatureDisplay_advanceTimeBySelf(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCArmatureDisplay* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCArmatureDisplay",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCArmatureDisplay*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCArmatureDisplay_advanceTimeBySelf'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "db.CCArmatureDisplay:advanceTimeBySelf");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCArmatureDisplay_advanceTimeBySelf'", nullptr);
            return 0;
        }
        cobj->advanceTimeBySelf(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCArmatureDisplay:advanceTimeBySelf",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCArmatureDisplay_advanceTimeBySelf'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCArmatureDisplay_removeEvent(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCArmatureDisplay* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCArmatureDisplay",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCArmatureDisplay*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCArmatureDisplay_removeEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCArmatureDisplay:removeEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCArmatureDisplay_removeEvent'", nullptr);
            return 0;
        }
        cobj->removeEvent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCArmatureDisplay:removeEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCArmatureDisplay_removeEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCArmatureDisplay_dispose(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCArmatureDisplay* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCArmatureDisplay",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCArmatureDisplay*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCArmatureDisplay_dispose'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCArmatureDisplay_dispose'", nullptr);
            return 0;
        }
        cobj->dispose();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCArmatureDisplay:dispose",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCArmatureDisplay_dispose'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCArmatureDisplay_getArmature(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCArmatureDisplay* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCArmatureDisplay",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCArmatureDisplay*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCArmatureDisplay_getArmature'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCArmatureDisplay_getArmature'", nullptr);
            return 0;
        }
        dragonBones::Armature* ret = cobj->getArmature();
        object_to_luaval<dragonBones::Armature>(tolua_S, "db.Armature",(dragonBones::Armature*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCArmatureDisplay:getArmature",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCArmatureDisplay_getArmature'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCArmatureDisplay__onClear(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCArmatureDisplay* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCArmatureDisplay",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCArmatureDisplay*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCArmatureDisplay__onClear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCArmatureDisplay__onClear'", nullptr);
            return 0;
        }
        cobj->_onClear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCArmatureDisplay:_onClear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCArmatureDisplay__onClear'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCArmatureDisplay__dispatchEvent(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCArmatureDisplay* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCArmatureDisplay",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCArmatureDisplay*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCArmatureDisplay__dispatchEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        dragonBones::EventObject* arg0;

        ok &= luaval_to_object<dragonBones::EventObject>(tolua_S, 2, "db.EventObject",&arg0, "db.CCArmatureDisplay:_dispatchEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCArmatureDisplay__dispatchEvent'", nullptr);
            return 0;
        }
        cobj->_dispatchEvent(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCArmatureDisplay:_dispatchEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCArmatureDisplay__dispatchEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCArmatureDisplay_addDragonEventType(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCArmatureDisplay* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCArmatureDisplay",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCArmatureDisplay*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCArmatureDisplay_addDragonEventType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCArmatureDisplay:addDragonEventType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCArmatureDisplay_addDragonEventType'", nullptr);
            return 0;
        }
        cobj->addDragonEventType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCArmatureDisplay:addDragonEventType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCArmatureDisplay_addDragonEventType'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCArmatureDisplay_hasEvent(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCArmatureDisplay* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCArmatureDisplay",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCArmatureDisplay*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCArmatureDisplay_hasEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCArmatureDisplay:hasEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCArmatureDisplay_hasEvent'", nullptr);
            return 0;
        }
        bool ret = cobj->hasEvent(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCArmatureDisplay:hasEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCArmatureDisplay_hasEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCArmatureDisplay_lua_getAnimation(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCArmatureDisplay* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCArmatureDisplay",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCArmatureDisplay*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCArmatureDisplay_lua_getAnimation'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCArmatureDisplay_lua_getAnimation'", nullptr);
            return 0;
        }
        dragonBones::Animation* ret = cobj->lua_getAnimation();
        object_to_luaval<dragonBones::Animation>(tolua_S, "db.Animation",(dragonBones::Animation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCArmatureDisplay:lua_getAnimation",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCArmatureDisplay_lua_getAnimation'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCArmatureDisplay_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.CCArmatureDisplay",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCArmatureDisplay_create'", nullptr);
            return 0;
        }
        dragonBones::CCArmatureDisplay* ret = dragonBones::CCArmatureDisplay::create();
        object_to_luaval<dragonBones::CCArmatureDisplay>(tolua_S, "db.CCArmatureDisplay",(dragonBones::CCArmatureDisplay*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.CCArmatureDisplay:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCArmatureDisplay_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_dragonbones_CCArmatureDisplay_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCArmatureDisplay)");
    return 0;
}

int lua_register_dragonbones_CCArmatureDisplay(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.CCArmatureDisplay");
    tolua_cclass(tolua_S,"CCArmatureDisplay","db.CCArmatureDisplay","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CCArmatureDisplay");
        tolua_function(tolua_S,"removeDragonEventType",lua_dragonbones_CCArmatureDisplay_removeDragonEventType);
        tolua_function(tolua_S,"advanceTimeBySelf",lua_dragonbones_CCArmatureDisplay_advanceTimeBySelf);
        tolua_function(tolua_S,"removeEvent",lua_dragonbones_CCArmatureDisplay_removeEvent);
        tolua_function(tolua_S,"dispose",lua_dragonbones_CCArmatureDisplay_dispose);
        tolua_function(tolua_S,"getArmature",lua_dragonbones_CCArmatureDisplay_getArmature);
        tolua_function(tolua_S,"_onClear",lua_dragonbones_CCArmatureDisplay__onClear);
        tolua_function(tolua_S,"_dispatchEvent",lua_dragonbones_CCArmatureDisplay__dispatchEvent);
        tolua_function(tolua_S,"addDragonEventType",lua_dragonbones_CCArmatureDisplay_addDragonEventType);
        tolua_function(tolua_S,"hasEvent",lua_dragonbones_CCArmatureDisplay_hasEvent);
        tolua_function(tolua_S,"getAnimation",lua_dragonbones_CCArmatureDisplay_lua_getAnimation);
        tolua_function(tolua_S,"create", lua_dragonbones_CCArmatureDisplay_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::CCArmatureDisplay).name();
    g_luaType[typeName] = "db.CCArmatureDisplay";
    g_typeCast["CCArmatureDisplay"] = "db.CCArmatureDisplay";
    return 1;
}

int lua_dragonbones_CCFactory_getTextureDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCFactory_getTextureDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:getTextureDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_getTextureDisplay'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getTextureDisplay(arg0);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:getTextureDisplay");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.CCFactory:getTextureDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_getTextureDisplay'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getTextureDisplay(arg0, arg1);
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCFactory:getTextureDisplay",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCFactory_getTextureDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCFactory_getSoundEventManater(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCFactory_getSoundEventManater'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_getSoundEventManater'", nullptr);
            return 0;
        }
        dragonBones::CCArmatureDisplay* ret = cobj->getSoundEventManater();
        object_to_luaval<dragonBones::CCArmatureDisplay>(tolua_S, "db.CCArmatureDisplay",(dragonBones::CCArmatureDisplay*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCFactory:getSoundEventManater",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCFactory_getSoundEventManater'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCFactory_buildArmatureDisplay(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCFactory_buildArmatureDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:buildArmatureDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_buildArmatureDisplay'", nullptr);
            return 0;
        }
        dragonBones::CCArmatureDisplay* ret = cobj->buildArmatureDisplay(arg0);
        object_to_luaval<dragonBones::CCArmatureDisplay>(tolua_S, "db.CCArmatureDisplay",(dragonBones::CCArmatureDisplay*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:buildArmatureDisplay");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.CCFactory:buildArmatureDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_buildArmatureDisplay'", nullptr);
            return 0;
        }
        dragonBones::CCArmatureDisplay* ret = cobj->buildArmatureDisplay(arg0, arg1);
        object_to_luaval<dragonBones::CCArmatureDisplay>(tolua_S, "db.CCArmatureDisplay",(dragonBones::CCArmatureDisplay*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:buildArmatureDisplay");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.CCFactory:buildArmatureDisplay");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.CCFactory:buildArmatureDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_buildArmatureDisplay'", nullptr);
            return 0;
        }
        dragonBones::CCArmatureDisplay* ret = cobj->buildArmatureDisplay(arg0, arg1, arg2);
        object_to_luaval<dragonBones::CCArmatureDisplay>(tolua_S, "db.CCArmatureDisplay",(dragonBones::CCArmatureDisplay*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCFactory:buildArmatureDisplay",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCFactory_buildArmatureDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCFactory_loadTextureAtlasData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCFactory_loadTextureAtlasData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:loadTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_loadTextureAtlasData'", nullptr);
            return 0;
        }
        dragonBones::TextureAtlasData* ret = cobj->loadTextureAtlasData(arg0);
        object_to_luaval<dragonBones::TextureAtlasData>(tolua_S, "db.TextureAtlasData",(dragonBones::TextureAtlasData*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:loadTextureAtlasData");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.CCFactory:loadTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_loadTextureAtlasData'", nullptr);
            return 0;
        }
        dragonBones::TextureAtlasData* ret = cobj->loadTextureAtlasData(arg0, arg1);
        object_to_luaval<dragonBones::TextureAtlasData>(tolua_S, "db.TextureAtlasData",(dragonBones::TextureAtlasData*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:loadTextureAtlasData");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.CCFactory:loadTextureAtlasData");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "db.CCFactory:loadTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_loadTextureAtlasData'", nullptr);
            return 0;
        }
        dragonBones::TextureAtlasData* ret = cobj->loadTextureAtlasData(arg0, arg1, arg2);
        object_to_luaval<dragonBones::TextureAtlasData>(tolua_S, "db.TextureAtlasData",(dragonBones::TextureAtlasData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCFactory:loadTextureAtlasData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCFactory_loadTextureAtlasData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCFactory_parseTextureAtlasData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCFactory_parseTextureAtlasData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:parseTextureAtlasData");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.CCFactory:parseTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_parseTextureAtlasData'", nullptr);
            return 0;
        }
        dragonBones::TextureAtlasData* ret = cobj->parseTextureAtlasData(arg0, arg1);
        object_to_luaval<dragonBones::TextureAtlasData>(tolua_S, "db.TextureAtlasData",(dragonBones::TextureAtlasData*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:parseTextureAtlasData");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.CCFactory:parseTextureAtlasData");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.CCFactory:parseTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_parseTextureAtlasData'", nullptr);
            return 0;
        }
        dragonBones::TextureAtlasData* ret = cobj->parseTextureAtlasData(arg0, arg1, arg2);
        object_to_luaval<dragonBones::TextureAtlasData>(tolua_S, "db.TextureAtlasData",(dragonBones::TextureAtlasData*)ret);
        return 1;
    }
    if (argc == 4) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        double arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:parseTextureAtlasData");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.CCFactory:parseTextureAtlasData");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "db.CCFactory:parseTextureAtlasData");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "db.CCFactory:parseTextureAtlasData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_parseTextureAtlasData'", nullptr);
            return 0;
        }
        dragonBones::TextureAtlasData* ret = cobj->parseTextureAtlasData(arg0, arg1, arg2, arg3);
        object_to_luaval<dragonBones::TextureAtlasData>(tolua_S, "db.TextureAtlasData",(dragonBones::TextureAtlasData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCFactory:parseTextureAtlasData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCFactory_parseTextureAtlasData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCFactory_loadDragonBonesData(lua_State* tolua_S)
{
    int argc = 0;
    dragonBones::CCFactory* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"db.CCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (dragonBones::CCFactory*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_dragonbones_CCFactory_loadDragonBonesData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:loadDragonBonesData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_loadDragonBonesData'", nullptr);
            return 0;
        }
        dragonBones::DragonBonesData* ret = cobj->loadDragonBonesData(arg0);
        object_to_luaval<dragonBones::DragonBonesData>(tolua_S, "db.DragonBonesData",(dragonBones::DragonBonesData*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "db.CCFactory:loadDragonBonesData");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "db.CCFactory:loadDragonBonesData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_loadDragonBonesData'", nullptr);
            return 0;
        }
        dragonBones::DragonBonesData* ret = cobj->loadDragonBonesData(arg0, arg1);
        object_to_luaval<dragonBones::DragonBonesData>(tolua_S, "db.DragonBonesData",(dragonBones::DragonBonesData*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "db.CCFactory:loadDragonBonesData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCFactory_loadDragonBonesData'.",&tolua_err);
#endif

    return 0;
}
int lua_dragonbones_CCFactory_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"db.CCFactory",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_dragonbones_CCFactory_getInstance'", nullptr);
            return 0;
        }
        dragonBones::CCFactory* ret = dragonBones::CCFactory::getInstance();
        object_to_luaval<dragonBones::CCFactory>(tolua_S, "db.CCFactory",(dragonBones::CCFactory*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "db.CCFactory:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_dragonbones_CCFactory_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_dragonbones_CCFactory_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCFactory)");
    return 0;
}

int lua_register_dragonbones_CCFactory(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"db.CCFactory");
    tolua_cclass(tolua_S,"CCFactory","db.CCFactory","db.BaseFactory",nullptr);

    tolua_beginmodule(tolua_S,"CCFactory");
        tolua_function(tolua_S,"getTextureDisplay",lua_dragonbones_CCFactory_getTextureDisplay);
        tolua_function(tolua_S,"getSoundEventManater",lua_dragonbones_CCFactory_getSoundEventManater);
        tolua_function(tolua_S,"buildArmatureDisplay",lua_dragonbones_CCFactory_buildArmatureDisplay);
        tolua_function(tolua_S,"loadTextureAtlasData",lua_dragonbones_CCFactory_loadTextureAtlasData);
        tolua_function(tolua_S,"parseTextureAtlasData",lua_dragonbones_CCFactory_parseTextureAtlasData);
        tolua_function(tolua_S,"loadDragonBonesData",lua_dragonbones_CCFactory_loadDragonBonesData);
        tolua_function(tolua_S,"getInstance", lua_dragonbones_CCFactory_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(dragonBones::CCFactory).name();
    g_luaType[typeName] = "db.CCFactory";
    g_typeCast["CCFactory"] = "db.CCFactory";
    return 1;
}
TOLUA_API int register_all_dragonbones(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"db",0);
	tolua_beginmodule(tolua_S,"db");

	lua_register_dragonbones_BaseObject(tolua_S);
	lua_register_dragonbones_TransformObject(tolua_S);
	lua_register_dragonbones_Slot(tolua_S);
	lua_register_dragonbones_Transform(tolua_S);
	lua_register_dragonbones_Animation(tolua_S);
	lua_register_dragonbones_BaseFactory(tolua_S);
	lua_register_dragonbones_CCFactory(tolua_S);
	lua_register_dragonbones_TextureAtlasData(tolua_S);
	lua_register_dragonbones_IAnimateble(tolua_S);
	lua_register_dragonbones_WorldClock(tolua_S);
	lua_register_dragonbones_IEventDispatcher(tolua_S);
	lua_register_dragonbones_CCArmatureDisplay(tolua_S);
	lua_register_dragonbones_AnimationState(tolua_S);
	lua_register_dragonbones_CCEventObject(tolua_S);
	lua_register_dragonbones_Armature(tolua_S);
	lua_register_dragonbones_Bone(tolua_S);
	lua_register_dragonbones_TextureData(tolua_S);
	lua_register_dragonbones_EventObject(tolua_S);
	lua_register_dragonbones_DragonBonesData(tolua_S);
	lua_register_dragonbones_AnimationData(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

