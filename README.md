# DragonbonesCocos2dxLua
Dragonbones for Cocos2dx & Lua

# 这个项目做了什么？
* 将 [DragonbonesCPP](https://github.com/DragonBones/DragonBonesCPP) 整理成方便 Cocos2dx 导入使用的形式。
* 修改 Cocos2dx 的 lua-bindings 使其支持导出类的成员变量，以及修改其中的 rename_functions 规则，让它不再与 skip 规则冲突。
* 修改 DragonbonesCPP 部分代码，使其更加方便导出到 lua 中使用，且尽量保持与原版使用规则相同。
* 用 Cocos2dxLua 实现 DragonbonesCPP 项目中的4个 Demo （还差一个，因为那个是鼠标控制的，所以……就再说吧……）

# 怎么运行？
* 创建一个 cocos2dxlua 项目，然后将这些文件覆盖到项目根目录下。
* 用 VS2015 打开新建好的项目，并导入libdragonbones项目，项目配置文件路径如下：
```
frameworks\cocos2d-x\cocos\editor-support\dragonbones\renderer\cocos2d-x-3.x\proj.win32\libDragonbones.vcxproj
```
* 给主项目添加“项目依赖项”和“引用” libDragonbones。
* 修改你的 main.lua，让其打开任意一个 Demo。
* 编译运行。

# 关于 API
已经导出的 DragonbonesCPP API 信息放在下面这个目录下
```
frameworks\cocos2d-x\cocos\scripting\lua-bindings\auto\api 
```
目前这些 API 现在已经可以运行官方的范例了，还会看情况添加，如果你需要更多的 API，可以自己在 dragonbones.ini 添加。
API 名称规则基本和 CPP 版本一样，调用时以 db 开头，比如：db:CCFacotry()，更多使用方法你可以看已经做好的 Demo。
###one more thing
事件回调增加了两个方法在 CCArmatureDisplay 中，分别为：

**addDragonEventListener** 添加监听回调，参数为一个函数。你可以这样写 
```
dbdisplay:addDragonEventListener(handler(self,self.callbackfunc))
```
**addDragonEventType** 添加监回调类型，参数为字符串。

# 其他
应该还有不完善的地方，欢迎补充。