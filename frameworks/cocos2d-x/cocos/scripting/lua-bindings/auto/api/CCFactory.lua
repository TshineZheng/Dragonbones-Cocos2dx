
--------------------------------
-- @module CCFactory
-- @extend BaseFactory
-- @parent_module db

--------------------------------
-- 
-- @function [parent=#CCFactory] getTextureDisplay 
-- @param self
-- @param #string textureName
-- @param #string dragonBonesName
-- @return Sprite#Sprite ret (return value: cc.Sprite)
        
--------------------------------
-- 
-- @function [parent=#CCFactory] getSoundEventManater 
-- @param self
-- @return CCArmatureDisplay#CCArmatureDisplay ret (return value: db.CCArmatureDisplay)
        
--------------------------------
-- 
-- @function [parent=#CCFactory] buildArmatureDisplay 
-- @param self
-- @param #string armatureName
-- @param #string dragonBonesName
-- @param #string skinName
-- @return CCArmatureDisplay#CCArmatureDisplay ret (return value: db.CCArmatureDisplay)
        
--------------------------------
-- 
-- @function [parent=#CCFactory] loadTextureAtlasData 
-- @param self
-- @param #string filePath
-- @param #string dragonBonesName
-- @param #float scale
-- @return TextureAtlasData#TextureAtlasData ret (return value: db.TextureAtlasData)
        
--------------------------------
-- 
-- @function [parent=#CCFactory] loadDragonBonesData 
-- @param self
-- @param #string filePath
-- @param #string dragonBonesName
-- @return DragonBonesData#DragonBonesData ret (return value: db.DragonBonesData)
        
--------------------------------
-- 
-- @function [parent=#CCFactory] getInstance 
-- @param self
-- @return CCFactory#CCFactory ret (return value: db.CCFactory)
        
--------------------------------
-- 
-- @function [parent=#CCFactory] CCFactory 
-- @param self
-- @return CCFactory#CCFactory self (return value: db.CCFactory)
        
return nil
