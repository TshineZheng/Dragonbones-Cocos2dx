
cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("src/")
cc.FileUtils:getInstance():addSearchPath("res/")

require "config"
require "cocos.init"
require "dragonbones"

local function main()
--    require("app.MyApp"):create():run("PerformanceTest")
--    require("app.MyApp"):create():run("AnimationBaseTest")
--    require("app.MyApp"):create():run("KnightScene")
--    require("app.MyApp"):create():run("HelloDragonBonesScene")
    require("app.MyApp"):create():run("CoreElement")
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
