local CoreElementBullet = class("CoreElementBullet")

CoreElementBullet.ANGLE_TO_RADIAN = math.pi / 180
CoreElementBullet.RADIAN_TO_ANGLE = 180 / math.pi

function CoreElementBullet:ctor()
    self._speedX = 0
    self._speedY = 0

    self._armature = nil
    self._armatureDisplay = nil
    self._effect = nil
end

function CoreElementBullet:init(armatureName, effectArmatureName, radian, speed, position)
    self._speedX = math.cos(radian) * speed
    self._speedY = -math.sin(radian) * speed

    self._armature = db.CCFactory:getInstance():buildArmature(armatureName)
    self._armatureDisplay = self._armature:getDisplay()
    self._armatureDisplay:setPosition(position)
    self._armatureDisplay:setRotation(radian * CoreElementBullet.RADIAN_TO_ANGLE)
    self._armature:getAnimation():play("idle")

    if(effectArmatureName ~= nil) then
        self._effect = db.CCFactory:getInstance():buildArmature(effectArmatureName)
        local effectDisplay = self._effect:getDisplay()
        effectDisplay:setPosition(position)
        effectDisplay:setRotation(radian * CoreElementBullet.RADIAN_TO_ANGLE)
        effectDisplay:setScaleX(math.random(100,200) * 0.01);
        effectDisplay:setScaleY(math.random(100,150) * 0.01);
        if(math.random(0,100) * 0.01 < 0.5) then
            effectDisplay:setScaleY(effectDisplay:getScaleY())
        end

        self._effect:getAnimation():play("idle")

        db.WorldClock:getInstance():add(self._effect)
        effectDisplay:addTo(CoreElementInstance)
    end

    db.WorldClock:getInstance():add(self._armature)
    self._armatureDisplay:addTo(CoreElementInstance)

end

function CoreElementBullet:update()
    local posx,posy = self._armatureDisplay:getPosition()

    local position = {x = posx , y = posy}

    self._armatureDisplay:setPosition(position.x + self._speedX, position.y + self._speedY)

    if( position.x < -100 or position.x >= 960 + 100 or
        position.y < -100 or position.y >= 640 + 100) then

        db.WorldClock:getInstance():remove(self._armature)
        self._armatureDisplay:removeSelf()
        self._armature:dispose()

        if(self._effect) then
            db.WorldClock:getInstance():remove(self._effect)
            self._effect:getDisplay():removeSelf()
            self._effect:dispose()
        end

        return true
    end

    return false
end

return CoreElementBullet