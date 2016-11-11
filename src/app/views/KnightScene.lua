cc.exports.KnightSceneInstance = {}

local KnightScene = class("KnightScene", cc.load("mvc").ViewBase)

local KnightHero = import("..models.KnightHero")

function KnightScene:start()
    self:scheduleUpdate(handler(self, self._enterFrameHandler))
    return self
end

function KnightScene:stop()
    self:unscheduleUpdate()
    return self
end

function KnightScene:_enterFrameHandler(dt)
    self._player:update()

    local remove = {}

    --print(table.getn(self._bullets))

    for k, b in pairs(self._bullets) do
        if(b:update()) then
            table.insert(remove,b)
        end
    end

    for k, v in pairs(remove) do
        table.removebyvalue(self._bullets,v,false)
    end

    self.worldClock:advanceTime(dt)
    return self
end

function KnightScene:onCreate()
    KnightSceneInstance = self

    self.GROUND = 120
    self.G = -0.6
    self.factory = db.CCFactory:getInstance()
    self.worldClock = db.WorldClock:getInstance()

    self._left = false
    self._right = false
    self._player = null
    self._bullets = {}

    -- add touch layer
    display.newLayer(cc.c3b(105,105,105))
        :onTouch(handler(self, self.onTouch))
        :onKeypad(handler(self, self.onKeypad))
        :addTo(self)

    self:init()



    cc.bind(self, "event")
    

end

function KnightScene:init()
    local dragonBonesData = self.factory:loadDragonBonesData("Knight/Knight.json")
    self.factory:loadTextureAtlasData("Knight/Knight_texture_1.json")

    if(dragonBonesData) then
        self:start()
        self:addKeyboadEvent()
        self._player = KnightHero:create()
    
    end

end

function KnightScene:addBullet(bullet)
    table.insert(self._bullets,bullet)
end

function KnightScene:onTouch(event)
    local x, y = event.x, event.y

    local touchRight = x > display.width * 0.5

    self._player:attack()

    return true

end

function KnightScene:onKeypad(key)
    if(key == "backClicked") then
        print("backClicked")
    elseif(key == "menuClicked") then
        print("menuClicked")
    end

end

function KnightScene:_updateMove(dir)
    if(self._left and self._right) then
        self._player:move(dir)
    elseif(self._left) then
        self._player:move(-1)
    elseif(self._right) then
        self._player:move(1)
    else
        self._player:move(0)
    end
end

function KnightScene:addKeyboadEvent()

    local function keyboadPressed(keyCode, event)
        if keyCode == 124 or keyCode == 26 then  -- a
            self._left = true
            self:_updateMove(-1)
        elseif keyCode == 127 or keyCode == 27 then  -- d
            self._right = true
            self:_updateMove(1)
        elseif keyCode == 146 or keyCode == 28 then  -- w
            self._player:jump()
        elseif keyCode == 142 or keyCode == 29 then  -- s
            print("down")
        elseif keyCode == 140 then -- q
            self._player:upgradeWeapon(-1)
        elseif keyCode == 128 then -- e
            self._player:upgradeWeapon(1)
        elseif keyCode == 59 then -- space
            self._player:switchWeapon()
        else
            print("keyPress" .. keyCode)
        end
    end

    local function keyboardReleased(keyCode, event)
        if keyCode == 124 or keyCode == 26 then  -- a
            self._left = false
            self:_updateMove(-1)
        elseif keyCode == 127 or keyCode == 27 then  -- d
            self._right = false
            self:_updateMove(1)
        else
            print("keyReleased" .. keyCode)
        end
    end

    local listener = cc.EventListenerKeyboard:create()
    listener:registerScriptHandler(keyboadPressed, cc.Handler.EVENT_KEYBOARD_PRESSED)
    listener:registerScriptHandler(keyboardReleased, cc.Handler.EVENT_KEYBOARD_RELEASED)

    local dispatcher = cc.Director:getInstance():getEventDispatcher()
    dispatcher:addEventListenerWithSceneGraphPriority(listener, self)

end

return KnightScene
