local AnimationBaseTest = class("AnimationBaseTest", cc.load("mvc").ViewBase)

function AnimationBaseTest:onCreate()
    -- add touch layer
    display.newLayer(cc.c3b(105,105,105))
        :addTo(self)
        :onTouch(handler(self,self.onTouch))

    self._isTouched = false
    self._armatureDisplay = nil
    local factory = db.CCFactory:getInstance()

    local dragonBonesData = factory:loadDragonBonesData("AnimationBaseTest/AnimationBaseTest.json")
    factory:loadTextureAtlasData("AnimationBaseTest/texture.json")

    if(dragonBonesData) then
        local armatureNames = dragonBonesData:getArmatureNames()
        local armatureName = armatureNames[1]

        self._armatureDisplay = factory:buildArmatureDisplay(armatureName)

        self._armatureDisplay:setPosition(480, 320)
        self._armatureDisplay:setScale(1)
        self._armatureDisplay:addTo(self)

        self._armatureDisplay:bindDragonEventListener(handler(self,self._animationEventHandler))
        self._armatureDisplay:addDragonEventType("start")
        self._armatureDisplay:addDragonEventType("loopComplete")
        self._armatureDisplay:addDragonEventType("complete")
        self._armatureDisplay:addDragonEventType("fadeIn")
        self._armatureDisplay:addDragonEventType("fadeInComplete")
        self._armatureDisplay:addDragonEventType("fadeOut")
        self._armatureDisplay:addDragonEventType("fadeOutComplete")
        self._armatureDisplay:addDragonEventType("frameEvent")
    end
end

function AnimationBaseTest:onTouch(event)
    if(event.name == "began") then
        self._isTouched = true
        local progress = math.min(math.max((event.x - self._armatureDisplay:getPositionX() + 300) / 600, 0), 1)
        self._armatureDisplay:getAnimation():gotoAndPlayByTime("idle",0.5,1)
        self._armatureDisplay:getAnimation():gotoAndStopByTime("idle", 1)
        self._armatureDisplay:getAnimation():gotoAndPlayByProgress("idle", progress, 3)
        return true
    elseif(event.name == "ended") then
        self._isTouched = false
    elseif(event.name == "moved") then
        if(self._isTouched 
            and self._armatureDisplay:getAnimation():getState("idle") 
            and not self._armatureDisplay:getAnimation():getState("idle"):isPlaying()) then

            local progress = math.min(math.max((event.x - self._armatureDisplay:getPositionX() + 300) / 600, 0), 1)
            self._armatureDisplay:getAnimation():gotoAndStopByProgress("idle", progress)
        end
    end

end

function AnimationBaseTest:_animationEventHandler(typename, name, eventobj, obj)
    print(eventobj:AnimationState():getName() .. "," .. typename .. "," .. name)
end




return AnimationBaseTest