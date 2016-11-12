local CoreElementMecha = class("CoreElementMecha")

local CoreElementBullet = import(".CoreElementBullet")

CoreElementMecha.NORMAL_ANIMATION_GROUP = "normal";
CoreElementMecha.AIM_ANIMATION_GROUP = "aim"
CoreElementMecha.ATTACK_ANIMATION_GROUP = "attack"
CoreElementMecha.JUMP_SPEED = -20
CoreElementMecha.NORMALIZE_MOVE_SPEED = 3.6
CoreElementMecha.MAX_MOVE_SPEED_FRONT = CoreElementMecha.NORMALIZE_MOVE_SPEED * 1.4
CoreElementMecha.MAX_MOVE_SPEED_BACK = CoreElementMecha.NORMALIZE_MOVE_SPEED * 1.0
CoreElementMecha.WEAPON_R_LIST = { "weapon_1502b_r", "weapon_1005", "weapon_1005b", "weapon_1005c", "weapon_1005d", "weapon_1005e" }
CoreElementMecha.WEAPON_L_LIST = { "weapon_1502b_l", "weapon_1005", "weapon_1005b", "weapon_1005c", "weapon_1005d" }


function CoreElementMecha:ctor()
    self._isJumpingA = false
    self._isJumpingB = false
    self._isSquating = false
    self._isAttackingA = false
    self._isAttackingB = false
    self._weaponRIndex = 1
    self._weaponLIndex = 1
    self._faceDir = 1
    self._aimDir = 0
    self._moveDir = 0
    self._aimRadian = 0
    self._speedX = 0
    self._speedY = 0
    self._armature = nil
    self._armatureDisplay = nil
    self._weaponR = nil
    self._weaponL = nil
    self._aimState = nil
    self._walkState = nil
    self._attackState = nil
    self._target = nil

    self:init()
end

function CoreElementMecha:init()
    self._armature = db.CCFactory:getInstance():buildArmature("mecha_1502b")
    self._armatureDisplay = self._armature:getDisplay()
    self._armatureDisplay:setPosition(480,CoreElementInstance.GROUND)
    self._armatureDisplay:setScale(1)
    self._armatureDisplay:bindDragonEventListener(handler(self,self._animationEventHandler))
    self._armatureDisplay:addDragonEventType(db.Event.FADE_IN_COMPLETE)
    self._armatureDisplay:addDragonEventType(db.Event.FADE_OUT_COMPLETE)

    self._armature:getSlot("effects_1").displayController = CoreElementMecha.NORMAL_ANIMATION_GROUP
    self._armature:getSlot("effects_2").displayController = CoreElementMecha.NORMAL_ANIMATION_GROUP

    self._weaponR = self._armature:getSlot("weapon_r"):getChildArmature()
    self._weaponL = self._armature:getSlot("weapon_l"):getChildArmature()
    local weaponRDisplay = self._weaponR:getDisplay()
    local weaponLDisplay = self._weaponL:getDisplay()
    weaponRDisplay:bindDragonEventListener(handler(self, self._frameEventHandler))
    weaponLDisplay:bindDragonEventListener(handler(self, self._frameEventHandler))
    weaponRDisplay:addDragonEventType(db.Event.FRAME_EVENT)
    weaponLDisplay:addDragonEventType(db.Event.FRAME_EVENT)

    self:_updateAnimation()

    db.WorldClock:getInstance():add(self._armature)
    self._armatureDisplay:addTo(CoreElementInstance)
end

function CoreElementMecha:update()
    self:_updatePosition()
    self:_updateAim()
    self:_updateAttack()
end

function CoreElementMecha:move(dir)
    if(self._moveDir == dir) then
        return
    end
    
    self._moveDir = dir
    self:_updateAnimation() 
end

function CoreElementMecha:jump()
    if(self._isJumpingA) then
        return 
    end

    self._isJumpingA = true
    self._armature:getAnimation():fadeIn("jump_1",  -1, -1, 0, CoreElementMecha.NORMAL_ANIMATION_GROUP)
    self._walkState = nil
end

function CoreElementMecha:squat(isSquating)
    if(self._isSquating == isSquating) then
        return
    end

    self._isSquating = isSquating
    self:_updateAnimation()
end

function CoreElementMecha:attack(isAttacking)
    if(self._isAttackingA == isAttacking) then
        return
    end

    self._isAttackingA = isAttacking
end

function CoreElementMecha:switchWeaponR()
    self._weaponRIndex = self._weaponRIndex + 1
    if(self._weaponRIndex > table.getn(CoreElementMecha.WEAPON_R_LIST)) then
        self._weaponRIndex = 1
    end

    local weaponDisplay = self._weaponR:getDisplay()
    weaponDisplay:removeDragonEventType(db.Event.FRAME_EVENT)

    local weaponName = CoreElementMecha.WEAPON_R_LIST[self._weaponRIndex]
    self._weaponR = db.CCFactory:getInstance():buildArmature(weaponName)
    self._armature:getSlot("weapon_r"):setChildArmature(self._weaponR);
    weaponDisplay = self._weaponR:getDisplay()
    weaponDisplay:bindDragonEventListener(handler(self,self._frameEventHandler))
    weaponDisplay:addDragonEventType(db.Event.FRAME_EVENT)
end

function CoreElementMecha:switchWeaponL()
    self._weaponLIndex = self._weaponLIndex + 1
    if(self._weaponLIndex > table.getn(CoreElementMecha.WEAPON_L_LIST)) then
        self._weaponLIndex = 1
    end

    local weaponDisplay = self._weaponL:getDisplay()
    weaponDisplay:removeDragonEventType(db.Event.FRAME_EVENT)

    local weaponName = CoreElementMecha.WEAPON_L_LIST[self._weaponLIndex]
    self._weaponL = db.CCFactory:getInstance():buildArmature(weaponName)
    self._armature:getSlot("weapon_l"):setChildArmature(self._weaponL);
    weaponDisplay = self._weaponL:getDisplay()
    weaponDisplay:bindDragonEventListener(handler(self,self._frameEventHandler))
    weaponDisplay:addDragonEventType(db.Event.FRAME_EVENT)
end

function CoreElementMecha:aim(target)
    if(self._aimDir == 0) then
        self._aimDir = 10
    end

    self._target = target
end

function CoreElementMecha:_animationEventHandler(typename, name, eventobj, obj)
    if(typename == db.Event.FADE_IN_COMPLETE) then
        if(eventobj:AnimationState():getName() == "jump_1") then
            self._isJumpingB = true
            self._speedY = - CoreElementMecha.JUMP_SPEED
        elseif(eventobj:AnimationState():getName() == "jump_4") then
            self:_updateAnimation()
        end

    elseif(typename == db.Event.FADE_OUT_COMPLETE) then
        if(eventobj:AnimationState():getName() == "attack_01") then
            self._isAttackingB = false
            self._attackState = nil
        end
    end
end

function CoreElementMecha:_frameEventHandler(typename, name, eventobj, obj)
    if(name == "onFire") then
        local dsp = obj
        local firePointBone = eventobj:Armature():getBone("firePoint")
        local localPoint = cc.vec3(firePointBone.global.x, -firePointBone.global.y, 0);
        local globalPoint = cc.p(0,0)

        localPoint = dsp:convertToWorldSpace(localPoint)
        globalPoint = localPoint

        self:_fire(globalPoint)
    end
end

function CoreElementMecha:_fire(firePoint)
    local radian = 0
    if(self._faceDir < 0) then
        radian = math.pi - self._aimRadian
    else
        radian = self._aimRadian
    end

    local bullet = CoreElementBullet:create()
    bullet:init("bullet_01", "fireEffect_01", radian + math.random(-1,1) * 0.01, 40, firePoint)
    CoreElementInstance:addBullet(bullet)
end

function CoreElementMecha:_updateAnimation()
    if(self._isJumpingA) then
        return
    end

    if(self._isSquating) then
        self._speedX = 0
        self._armature:getAnimation():fadeIn("squat", -1, -1, 0, CoreElementMecha.NORMAL_ANIMATION_GROUP)
        self._walkState = nil
        return
    end

    if(self._moveDir == 0) then
        self._speedX = 0
        self._armature:getAnimation():fadeIn("idle", -1 , -1, 0, CoreElementMecha.NORMAL_ANIMATION_GROUP)
        self._walkState = nil
    else
        if(not self._walkState) then
            self._walkState = self._armature:getAnimation():fadeIn("walk", -1 , -1, 0, CoreElementMecha.NORMAL_ANIMATION_GROUP)
        end

        if(self._moveDir * self._faceDir > 0) then
            self._walkState.timeScale = CoreElementMecha.MAX_MOVE_SPEED_FRONT / CoreElementMecha.NORMALIZE_MOVE_SPEED
        else
            self._walkState.timeScale = -CoreElementMecha.MAX_MOVE_SPEED_BACK / CoreElementMecha.NORMALIZE_MOVE_SPEED
        end

        if(self._moveDir * self._faceDir > 0) then
            self._speedX = CoreElementMecha.MAX_MOVE_SPEED_FRONT * self._faceDir
        else
            self._speedX = -CoreElementMecha.MAX_MOVE_SPEED_BACK * self._faceDir
        end
    end
end

function CoreElementMecha:_updatePosition()
    local posx,posy = self._armatureDisplay:getPosition()

    if(self._speedX ~= 0) then
        self._armatureDisplay:setPosition(posx + self._speedX, posy)
        if(posx < 0) then
            self._armatureDisplay:setPosition(0, posy)
        elseif(posx > 960) then
            self._armatureDisplay:setPosition(960, posy)
        end
    end

    if(self._speedY ~= 0) then
        if(self._speedY > 5 and self._speedY + CoreElementInstance.G <= 5) then
            self._armature:getAnimation():fadeIn("jump_3", -1, -1, 0, CoreElementMecha.NORMAL_ANIMATION_GROUP)
        end

        self._speedY = self._speedY + CoreElementInstance.G

        self._armatureDisplay:setPosition(posx, posy + self._speedY)
        if(posy < CoreElementInstance.GROUND) then
            self._armatureDisplay:setPosition(posx, CoreElementInstance.GROUND)
            self._isJumpingA = false
            self._isAttackingB = false
            self._speedX = 0
            self._speedY = 0
            self._armature:getAnimation():fadeIn("jump_4", -1, -1, 0, CoreElementMecha.NORMAL_ANIMATION_GROUP)
            if(self._isSquating or self._moveDir) then
                self:_updateAnimation()
            end
        end
    end
end

function CoreElementMecha:_updateAim()
    if(self._aimDir == 0) then
        return
    end

    local posx,posy = self._armatureDisplay:getPosition()

    if(self._target.x > posx) then
        self._faceDir = 1
    else
        self._faceDir = -1
    end

    if(self._armatureDisplay:getScaleX() * self._faceDir < 0) then
        self._armatureDisplay:setScaleX(-self._armatureDisplay:getScaleX())
        if(self._moveDir) then
            self:_updateAnimation()
        end
    end

    local aimOffsetY = self._armature:getBone("chest").global.y

    if(self._faceDir > 0) then
        self._aimRadian = math.atan2(-(self._target.y - posy + aimOffsetY), self._target.x - posx)
    else
        self._aimRadian = math.pi - math.atan2(-(self._target.y - posy + aimOffsetY), self._target.x - posx)
        if(self._aimRadian > math.pi) then
            self._aimRadian = self._aimRadian - math.pi * 2
        end
    end

    local aimDir = 0
    if(self._aimRadian > 0) then
        aimDir = -1
    else
        aimDir = 1
    end

    if(self._aimDir ~= aimDir) then
        self._aimDir = aimDir

        if(self._aimDir >= 0) then
            self._aimState = self._armature:getAnimation():fadeIn("aimUp", 0, 1,
                0, CoreElementMecha.AIM_ANIMATION_GROUP, db.AnimationFadeOutMode.SameGroup
            );
        else
            self._aimState = self._armature:getAnimation():fadeIn("aimDown", 0, 1,
                0,  CoreElementMecha.AIM_ANIMATION_GROUP, db.AnimationFadeOutMode.SameGroup
            );
        end
    end

    self._aimState.weight = math.abs(self._aimRadian / math.pi * 2)
    self._armature:invalidUpdate()
end

function CoreElementMecha:_updateAttack()
    if(not self._isAttackingA or self._isAttackingB) then
        return 
    end

    self._isAttackingB = true

    self._attackState = self._armature:getAnimation():fadeIn("attack_01", -1, -1,
        0, CoreElementMecha.ATTACK_ANIMATION_GROUP, db.AnimationFadeOutMode.SameGroup
    );

    self._attackState.autoFadeOutTime = self._attackState.fadeTotalTime
    self._attackState:addBoneMask("pelvis")
end





return CoreElementMecha
