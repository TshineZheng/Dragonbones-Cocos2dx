local KnightBullet = class("KnightBullet")

KnightBullet.ANGLE_TO_RADIAN = math.pi / 180
KnightBullet.RADIAN_TO_ANGLE = 180 / math.pi

function KnightBullet:ctor()
    self._speedX = 0;
    self._speedY = 0;
  
    self._armature = null
    self._armatureDisplay = null
end

function KnightBullet:init(armatureName, radian, speed, posx, posy)
    self._speedX = math.cos(radian) * speed
    self._speedY = -math.sin(radian) * speed

    self._armature = KnightSceneInstance.factory:buildArmature(armatureName)
    self._armatureDisplay = self._armature:getDisplay()
    self._armatureDisplay:setPosition(posx, posy)
    self._armatureDisplay:setRotation(radian * 180 / math.pi)
    self._armature:getAnimation():play("idle")

    KnightSceneInstance.worldClock:add(self._armature)
    self._armatureDisplay:addTo(KnightSceneInstance)
end

function KnightBullet:update()
    local posx,posy = self._armatureDisplay:getPosition()

    self._speedY = self._speedY + KnightSceneInstance.G

    self._armatureDisplay:setPosition(posx + self._speedX, posy + self._speedY)
    self._armatureDisplay:setRotation(math.atan2(-self._speedY, self._speedX) * KnightBullet.RADIAN_TO_ANGLE)

    if(posx < -100 or posx > 960 + 100 or posy < -100 or posy > 640 +  100) then
        KnightSceneInstance.worldClock:remove(self._armature)
        KnightSceneInstance:removeChild(self._armatureDisplay)
        self._armature:dispose()
        return true
    end

    return false
end


return KnightBullet