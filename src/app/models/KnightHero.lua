local KnightHero = class("KnightHero")

local KnightBullet = import("..models.KnightBullet")

function KnightHero:ctor()
    self.MAX_WEAPON_LEVEL = 3
    self.JUMP_SPEED = 20
    self.MOVE_SPEED = 4
    self.WEAPON_LIST = {}

    self._isJumping = false
    self._isAttacking = false
    self._hitCount = 0
    self._weaponIndex = 1
    self._weaponName = ""
    self._weaponsLevel = {0,0,0,0}
    self._faceDir = 1
    self._moveDir = 0
    self._speedX = 0.0
    self._speedY = 0.0

    self._armature = null
    self._armatureDisplay = null
    self._armArmature = null

    table.insert(self.WEAPON_LIST,"sword")
    table.insert(self.WEAPON_LIST,"pike")
    table.insert(self.WEAPON_LIST,"axe")
    table.insert(self.WEAPON_LIST,"bow")

    self._weaponName = self.WEAPON_LIST[self._weaponIndex]

    self._armature = KnightSceneInstance.factory:buildArmature("knight")
    self._armatureDisplay = self._armature:getDisplay()

    self._armatureDisplay:addTo(KnightSceneInstance)
    self._armatureDisplay:move(480, KnightSceneInstance.GROUND)
    self._armatureDisplay:setScale(1)

    self._armArmature = self._armature:getSlot("armOutside"):getChildArmature()
    local armArmatureDisplay = self._armArmature:getDisplay()

--    armArmatureDisplay:getEventDispatcher():setEnabled(true)
--    local listener = cc.EventListenerCustom:create("complete",handler(self,self._armEventHandler))
--    local listener2 = cc.EventListenerCustom:create("frameEvent",handler(self,self._armEventHandler))
--    armArmatureDisplay:getEventDispatcher():addEventListenerWithFixedPriority(listener,1)
--    armArmatureDisplay:getEventDispatcher():addEventListenerWithFixedPriority(listener2,1)
--    armArmatureDisplay:getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, armArmatureDisplay)

    armArmatureDisplay:addDragonEventListener(handler(self,self._armEventHandler))
    armArmatureDisplay:addDragonEventType("frameEvent");
    armArmatureDisplay:addDragonEventType("complete");



    self:_updateAnimation()

    KnightSceneInstance.worldClock:add(self._armature)


--由于addCustomEventLister为lamaba形式，所以不支持
--armArmatureDisplay:getEventDispatcher():addCustomEventListener("complete",handler(self, self._armEventHandler))
end

function KnightHero:update()
    self:_updatePosition()
end

function KnightHero:move(dir)
    if(self._moveDir == dir) then
        return
    end

    self._moveDir = dir
    if(self._moveDir ~= 0) then
        if(self._faceDir ~= self._moveDir) then
            self._faceDir = self._moveDir
            self._armatureDisplay:setScaleX(self._armatureDisplay:getScaleX() * -1)
        end
    end

    self:_updateAnimation()
end

function KnightHero:jump()
    if(self._isJumping) then
        return
    end

    self._isJumping = true;
    self._speedY = self.JUMP_SPEED
    self._armature:getAnimation():fadeIn("jump")

end

function KnightHero:attack()
    if(self._isAttacking) then
        return
    end

    self._isAttacking = true
    local animationName = "attack_" .. self._weaponName .. "_" .. (self._hitCount + 1)
    self._armArmature:getAnimation():fadeIn(animationName)

end

function KnightHero:switchWeapon()
    self._isAttacking = false
    self._hitCount = 0
    self._weaponIndex = self._weaponIndex + 1
    if(self._weaponIndex > table.getn(self.WEAPON_LIST)) then
        self._weaponIndex = 1
    end

    self._weaponName = self.WEAPON_LIST[self._weaponIndex]

    self._armArmature:getAnimation():fadeIn("ready_" .. self._weaponName)
end

function KnightHero:upgradeWeapon(dir)
    local weaponLevel = self._weaponsLevel[self._weaponIndex] + dir
    weaponLevel = weaponLevel % self.MAX_WEAPON_LEVEL
    if(weaponLevel < 0) then
        weaponLevel = self.MAX_WEAPON_LEVEL + weaponLevel
    end

    self._weaponsLevel[self._weaponIndex] = weaponLevel

    if(self._weaponName == "bow") then
        local arm = KnightSceneInstance.factory:buildArmature("knightFolder/" .. self._weaponName .. "_" .. (weaponLevel + 1))
        self._armArmature:getSlot("bow"):setChildArmature(arm)
    else
        KnightSceneInstance.factory:replaceSlotDisplay("","weapons", "weapon", 
        "knightFolder/" .. self._weaponName .. "_" .. (weaponLevel + 1),
        self._armArmature:getSlot("weapon"))
    end
end

function KnightHero:_armEventHandler(typename, name, eventobj, obj)
    if(typename == "complete") then
        self._isAttacking = false
        self._hitCount = 0
        local animationName = "ready_" .. self._weaponName
        self._armArmature:getAnimation():fadeIn(animationName)
    elseif(typename == "frameEvent") then
        if(name == "ready") then
            self._isAttacking = false;
            self._hitCount = self._hitCount + 1
        elseif(name == "fire") then
            local amt = eventobj:Armature()
            local dsp = amt:getDisplay()    --   == obj
            local firePointBone = amt:getBone("bow")
            local tsf = dsp:getNodeToWorldTransform()
            local localPoint = cc.vec3(firePointBone.global.x, -firePointBone.global.y, 0)
            local globalPoint = cc.p(0,0)

            local testp = cc.vec3(0,0,0)

            testp = cc.mat4.transformVector(tsf,localPoint,testp)

            localPoint = dsp:convertToWorldSpace(testp)

            globalPoint = localPoint

            local radian = 0
            if(self._faceDir > 0) then
                radian = firePointBone.global:getRotation() + dsp:getRotation() * KnightBullet.ANGLE_TO_RADIAN
            else
                radian = math.pi - (firePointBone.global:getRotation() + dsp:getRotation()* KnightBullet.ANGLE_TO_RADIAN)
            end

            if(self._weaponsLevel[self._weaponIndex] == 0) then
                self:_fire(globalPoint,radian)
            elseif(self._weaponsLevel[self._weaponIndex] == 1) then
                self:_fire(globalPoint,radian + 3 * KnightBullet.ANGLE_TO_RADIAN)
                self:_fire(globalPoint,radian - 3 * KnightBullet.ANGLE_TO_RADIAN)
            elseif(self._weaponsLevel[self._weaponIndex] == 2) then
                self:_fire(globalPoint,radian + 6 * KnightBullet.ANGLE_TO_RADIAN)
                self:_fire(globalPoint,radian)
                self:_fire(globalPoint,radian - 6 * KnightBullet.ANGLE_TO_RADIAN)
            end

        end
    end

end

function KnightHero:_fire(pos, radian)
    local bullet = KnightBullet:create()
    bullet:init("arrow", radian, 20, pos.x, pos.y)
    KnightSceneInstance:addBullet(bullet)
end

function KnightHero:_updateAnimation()
    if(self._isJumping) then
        return;
    end

    if(self._moveDir == 0) then
        self._speedX = 0
        self._armature:getAnimation():fadeIn("stand")
    else
        self._speedX = self.MOVE_SPEED * self._moveDir
        self._armature:getAnimation():fadeIn("run")

    end
end

function KnightHero:_updatePosition()
    local positionX = self._armatureDisplay:getPositionX()
    local positionY = self._armatureDisplay:getPositionY()
    if(self._speedX ~= 0) then
        self._armatureDisplay:setPosition(positionX + self._speedX, positionY)
        if(positionX < 0) then
            self._armatureDisplay:setPosition(0,positionY)
        elseif(positionX > 960) then
            self._armatureDisplay:setPosition(960,positionY)
        end
    end

    positionX = self._armatureDisplay:getPositionX()
    positionY = self._armatureDisplay:getPositionY()

    if(self._speedY ~=0) then
        if(self._speedY > 0 and self._speedY + KnightSceneInstance.G <= 0) then
            self._armature:getAnimation():fadeIn("fall")
        end

        self._speedY = self._speedY  + KnightSceneInstance.G

        self._armatureDisplay:setPosition(positionX, positionY + self._speedY)
        if(positionY < KnightSceneInstance.GROUND) then
            self._armatureDisplay:setPosition(positionX, KnightSceneInstance.GROUND)
            self._isJumping = false
            self._speedX = 0
            self._speedY = 0
            self:_updateAnimation()
        end
    end
end

return KnightHero