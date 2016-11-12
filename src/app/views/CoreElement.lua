cc.exports.CoreElementInstance = {}

local CoreElement = class("CoreElement", cc.load("mvc").ViewBase)

local CoreElementMecha = import("..models.CoreElementMecha")

CoreElement.GROUND = 120;
CoreElement.G = -0.6;

function CoreElement:onCreate()
    CoreElementInstance = self
    -- add touch layer


    self._left = false
    self._right = false
    self._player = nil
    self._bullets = {}
    self.worldClock = db.WorldClock:getInstance()

    local dragonBonesData = db.CCFactory:getInstance():loadDragonBonesData("CoreElement/CoreElement.json")
    db.CCFactory:getInstance():loadTextureAtlasData("CoreElement/CoreElement_texture_1.json")

    if(dragonBonesData) then
        self:scheduleUpdate(handler(self, self._enterFrameHandler))
        self:addKeyboadEvent()

        display.newLayer(cc.c3b(105,105,105))
            :addTo(self)
            :onTouch(handler(self,self.onTouch))
        
        self._player = CoreElementMecha:create()
    end
end

function CoreElement:addBullet(bullet)
    table.insert(self._bullets, bullet)
end

function CoreElement:_enterFrameHandler(passedTime)
    self._player:update()

    local remove = {}

    for k, b in pairs(self._bullets) do
        if(b:update()) then
            table.insert(remove,b)
        end
    end

    for k, v in pairs(remove) do
        table.removebyvalue(self._bullets,v,false)
    end

    self.worldClock:advanceTime(passedTime)
end

function CoreElement:onTouch(event)
    if(event.name == "began") then
        self._player:attack(true)
        return true
    elseif(event.name == "ended") then
        self._player:attack(false)
    elseif(event.name == "moved") then
        local target = cc.p(event.x,event.y)
        self._player:aim(target)
    end
end

function CoreElement:addKeyboadEvent()

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
            self._player:squat(true)
        elseif keyCode == 140 then -- q
            self._player:switchWeaponR()
        elseif keyCode == 128 then -- e
            self._player:switchWeaponL()
        elseif keyCode == 59 then -- space
            self._player:switchWeaponR()
            self._player:switchWeaponL()
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
        elseif keyCode == 142 or keyCode == 29 then  -- s
            self._player:squat(false)
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


function CoreElement:_updateMove(dir)

    if (self._left and self._right) then
        self._player:move(dir);
    elseif (self._left) then
        self._player:move(-1);
    elseif (self._right) then
        self._player:move(1);
    else
        self._player:move(0)
    end
end

return CoreElement
