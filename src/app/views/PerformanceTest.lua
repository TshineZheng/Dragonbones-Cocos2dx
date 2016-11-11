local PerformanceTest = class("PerformanceTest", cc.load("mvc").ViewBase)

function PerformanceTest:onCreate()
    -- add touch layer
    display.newLayer(cc.c3b(105,105,105))
        :addTo(self)
        :onTouch(handler(self,self.onTouch))

    self._addingArmature = false
    self._removingArmature = false
    self._dragonBonesData = nil
    self._armature = nil
    self._armatureDisplay = nil
    self._armatures = {}

    self.factory  = db.CCFactory:getInstance()
    self.worldClock = db.WorldClock:getInstance()

    self._dragonBonesData = self.factory:loadDragonBonesData("DragonBoy/DragonBoy.json")
    if(self._dragonBonesData) then
        self.factory:loadTextureAtlasData("DragonBoy/DragonBoy_texture_1.json")
        

        local i = 0
        while(i<100)do
            self:addArmature()
            i=i+1
        end
        self:resetPosition()
    end

    self:scheduleUpdate(handler(self, self._enterFrameHandler))

end

function PerformanceTest:_enterFrameHandler(dt)
    if(self._addingArmature) then
        self:addArmature()
        self:addArmature()
        self:addArmature()
        self:addArmature()
        self:addArmature()
        self:addArmature()
        self:addArmature()
        self:addArmature()
        self:addArmature()
        self:addArmature()
        self:resetPosition()
    end

    if(self._removingArmature) then
        self:removeArmature()
        self:removeArmature()
        self:removeArmature()
        self:removeArmature()
        self:removeArmature()
        self:removeArmature()
        self:removeArmature()
        self:removeArmature()
        self:removeArmature()
        self:removeArmature()
        self:resetPosition()
    end

    self.worldClock:advanceTime(dt)
end

function PerformanceTest:addArmature()
    local armature = self.factory:buildArmature(self._dragonBonesData:getArmatureNames()[2])
    local armatureDisplay = armature:getDisplay()

    armatureDisplay:setScale(1)
    armatureDisplay:addTo(self)

    armature:setCacheFrameRate(24)
    armature:getAnimation():play(armature:getAnimation():getAnimationNames()[1], 0)
    db.WorldClock:getInstance():add(armature)

    table.insert( self._armatures, armature)
end

function PerformanceTest:removeArmature()
    if(table.getn(self._armatures) == 0) then
        return
    end

    local armature = self._armatures[table.getn(self._armatures)]
    local armatureDisplay = armature:getDisplay()
    armatureDisplay:removeSelf()
    db.WorldClock:getInstance():remove(armature)
    armature:dispose()

    table.removebyvalue(self._armatures, armature, false)
end

function PerformanceTest:resetPosition()
    local stageSize = cc.Director:getInstance():getVisibleSize()

    local count = table.getn(self._armatures)
    local paddingH = 50
    local paddingV = 150
    local columnNum = 10
    local dX = (stageSize.width - paddingH * 2) / columnNum
    local dY = (stageSize.height - paddingV * 2) / math.ceil(count / columnNum)

    local i = 0
    while(i < count) do
        local armature = self._armatures[i+1]
        local armatureDisplay = armature:getDisplay()
        local lineY = math.floor(i/columnNum)
        armatureDisplay:setPosition((i%columnNum) * dX + paddingH, stageSize.height - (lineY * dY + paddingV))
        i=i+1
    end
end

function PerformanceTest:onTouch(event)
    if(event.name == "began") then
        local stageSize = cc.Director:getInstance():getVisibleSize()
        local touchRight = event.x > stageSize.width * 0.5
        self._addingArmature = touchRight
        self._removingArmature = not touchRight
        return true
    elseif(event.name == "ended") then
        self._addingArmature = false
        self._removingArmature = false
    elseif(event.name == "moved") then

    end

end

return PerformanceTest