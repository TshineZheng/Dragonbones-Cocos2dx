
local HelloDragonBonesScene = class("HelloDragonBonesScene", cc.load("mvc").ViewBase)

function HelloDragonBonesScene:onCreate()

    -- add touch layer
    display.newLayer()
        :onTouch(handler(self, self.onTouch))
        :addTo(self)

    self._isMoved = false
    self._prevArmatureScale = 0.0
    self._armatureScale = 0.0
    self._startPoint = cc.p(0, 0)
    self._armatureIndex = 0
    self._animationIndex = 1
    self._dragonBonesData = null
    self._armature = null
    self._armatureDisplay = null
    self._factory = null
    
    self._factory = db.CCFactory:getInstance()

    -- Load Dragonbones Data.
    self._dragonBonesData = self._factory:loadDragonBonesData("DragonBoy/DragonBoy.json")
    self._factory:loadTextureAtlasData("DragonBoy/DragonBoy_texture_1.json")

--    local armatureNames = dbd:getArmatureNames()

--    local armatureDisplay = self._factory:buildArmatureDisplay(armatureNames[1])

--    local armature = armatureDisplay:getArmature()

--    local animation = armatureDisplay:getAnimation()

--    local animationNames = armatureDisplay:getAnimation():getAnimationNames()

--    armatureDisplay:move(display.center)

--    armatureDisplay:addTo(self)

--    animation:play(animationNames[1])

    self:changeArmature()
    self:changeAnimation()


end

function HelloDragonBonesScene:changeArmature()
    local armatureNames = self._dragonBonesData:getArmatureNames()
    if(table.getn(armatureNames) == 0) then
        return
    end

    if(self._armature) then
        self._armature:dispose()
        self._armatureDisplay:removeSelf()
    end

    self._armatureIndex = self._armatureIndex + 1

    if(self._armatureIndex > table.getn(armatureNames)) then
        self._armatureIndex = 1
    end

    local armatureName = armatureNames[self._armatureIndex]

    self._armatureDisplay = self._factory:buildArmatureDisplay(armatureName)
    self._armature = self._armatureDisplay:getArmature();


    self._armatureDisplay:move(display.center)
    self._armatureDisplay:addTo(self);

    self._animationIndex = 0
end

function HelloDragonBonesScene:changeAnimation()
    local animationNames = self._armatureDisplay:getAnimation():getAnimationNames()
    if(table.getn(animationNames) == 0) then
        return
    end

    -- Get next Animation name.
    self._animationIndex = self._animationIndex + 1
    if (self._animationIndex > table.getn(animationNames)) then
        self._animationIndex = 1;
    end

    local animationName = animationNames[self._animationIndex]

    self._armatureDisplay:getAnimation():play(animationName)

    print(self._animationIndex .. " " .. animationName)

end



function HelloDragonBonesScene:onTouch(event)
    local x, y = event.x, event.y

    local touchRight = x > display.width * 0.5

    if(table.getn(self._dragonBonesData:getArmatureNames()) > 1 and not touchRight) then
        self:changeArmature()
    end
    self:changeAnimation()

end

return HelloDragonBonesScene
