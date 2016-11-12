# DragonbonesCocos2dx
Dragonbones for Cocos2dx & Lua

[English](#what-does-this-project-do)

# 这个项目做了什么？
* 将 [DragonbonesCPP](https://github.com/DragonBones/DragonBonesCPP) 整理成方便 Cocos2dx 导入使用的形式。
* 修改 Cocos2dx 的 lua-bindings 使其支持导出类的成员变量，以及修改其中的 rename_functions 规则，让它不再与 skip 规则冲突。
* 修改 DragonbonesCPP 部分代码，使其更加方便导出到 Cocos2dx Lua 中使用，且尽量保持与原版使用规则相同。
* 用 Cocos2dx Lua 实现 DragonbonesCPP 项目中的 4 个 Demo （还差一个，因为那个是鼠标控制的，所以……再说吧……）

# 怎么运行？
* 创建一个 Cocos2dx Lua 项目，然后将这些文件覆盖到项目根目录下。
* 用 VS2015 打开新建好的项目，并导入 libdragonbones 项目，项目配置文件路径如下：

`frameworks\cocos2d-x\cocos\editor-support\dragonbones\renderer\cocos2d-x-3.x\proj.win32\libDragonbones.vcxproj`

* 给主项目添加 “项目依赖项” 和 “引用” libDragonbones。
* 注册 Lua 绑定，在 C++ 调用 register_all_dragonbones 和 register_dragonbone_CCArmatureDisplay_extend 这两个函数。
```cpp
#include "scripting/lua-bindings/auto/lua_dragonbones_auto.hpp"
#include "dragonbones/lua-bindings/lua_dragonbone_CCArmatureDisplay_extend.h"
...
bool AppDelegate::applicationDidFinishLaunching()
{
    ...
    register_all_dragonbones(LuaEngine::getInstance()->getLuaStack()->getLuaState());
    register_dragonbone_CCArmatureDisplay_extend(LuaEngine::getInstance()->getLuaStack()->getLuaState());
    ...
}
```
* 修改 main.lua，让其打开任意一个 Demo。
* 编译运行。

# 关于 Lua API
已经导出的 API 信息放在下面这个目录下

`frameworks\cocos2d-x\cocos\scripting\lua-bindings\auto\api`

目前这些 API 现在已经可以正常运行官方范例了，看情况还会添加，如果你需要更多的 API，可以自己在 dragonbones.ini 添加。
API 名称规则基本和 CPP 版本一样，调用时以 db 开头，比如：db.CCFacotry:getInstance()，更多使用方法你可以看已经做好的 Demo。
###one more thing
为了让 cocos2dxlua 中可以使用事件回调，所以增加了两个方法在 CCArmatureDisplay 中，分别为：

**bindDragonEventListener** 绑定监听回调，参数为一个函数。你可以这样写 

`armatureDisplay:bindDragonEventListener(handler(self, self.callbackfunc))`

**addDragonEventType** 添加监听事件类型，参数为字符串。可以添加多个，回调信息将返回到上面绑定的函数中。

# 其他
应该还有不完善的地方，欢迎补充。


------------

------------

------------

# What does this project do?
* Organize [DragonbonesCPP](https://github.com/DragonBones/DragonBonesCPP) to make it easier for Cocos2dx to import.
* Modify the lua-bindings of Cocos2dx to support member variables of exported classes, and modify the rename_functions rule so that it no longer conflicts with skip rules.
* Modify the DragonbonesCPP part of the code to make it more convenient to export to Cocos2dx Lua use, and try to keep with the original use of the same rules.
* With Cocos2dx Lua project to achieve the four Demo of DragonbonesCPP project( one less, because that is the mouse control, so ... say it ...)

# How to run?
- Create a Cocos2dx Lua project, and then overwrite these files to the project root directory.
- Open the new project with VS2015, and import the libdragonbones project, the project configuration file path is as follows:

`Frameworks\cocos2d-x\cocos\editor-support\dragonbones\renderer\cocos2d-x-3.x\proj.win32\libDragonbones.vcxproj`

- Add "project dependencies" and "references" to the main project libDragonbones.
- Register Lua binding, call  register_all_dragonbones and register_dragonbone_CCArmatureDisplay_extend these two functions in C ++.
```cpp
#include "scripting/lua-bindings/auto/lua_dragonbones_auto.hpp"
#include "dragonbones/lua-bindings/lua_dragonbone_CCArmatureDisplay_extend.h"
...
Bool AppDelegate :: applicationDidFinishLaunching ()
{
    ...
    Register_all_dragonbones (LuaEngine::getInstance()->getLuaStack()->getLuaState());
    Register_dragonbone_CCArmatureDisplay_extend (LuaEngine::getInstance()->getLuaStack()->getLuaState());
    ...
}
```
- Modify main.lua, let it open anyone Demo.
- Compile the run.

# About the Lua API
The exported API information is located in the following directory

`Frameworks\cocos2d-x\cocos\scripting\lua-bindings\auto\api`

At present these APIs can now run the official example, and See also added, if you need more API, you can add them in dragonbones.ini by yourself.API name rules Basic and CPP version of the same call to db beginning, such as: db.CCFacotry: getInstance (), more use You can see the demo which has been done.
### one more thing
In order for cocos2dxlua to use the event callback, two methods have been added in the CCArmatureDisplay, respectively:

**bindDragonEventListener** Binds the listener callback as a function. You can write like this

`armatureDisplay:bindDragonEventListener (handler (self, self.callbackfunc))`

**addDragonEventType** Adds a listener event type with a string argument. You can add multiple, callback information will be returned to the above binding function.
