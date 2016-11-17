
--------------------------------
-- @module BaseFactory
-- @parent_module db

--------------------------------
-- /
-- @function [parent=#BaseFactory] replaceSlotDisplay 
-- @param self
-- @param #string dragonBonesName
-- @param #string armatureName
-- @param #string slotName
-- @param #string displayName
-- @param #db.Slot slot
-- @param #int displayIndex
-- @return BaseFactory#BaseFactory self (return value: db.BaseFactory)
        
--------------------------------
-- 
-- @function [parent=#BaseFactory] removeDragonBonesData 
-- @param self
-- @param #string dragonBonesName
-- @param #bool disposeData
-- @return BaseFactory#BaseFactory self (return value: db.BaseFactory)
        
--------------------------------
-- 
-- @function [parent=#BaseFactory] removeTextureAtlasData 
-- @param self
-- @param #string dragonBonesName
-- @param #bool disposeData
-- @return BaseFactory#BaseFactory self (return value: db.BaseFactory)
        
--------------------------------
-- 
-- @function [parent=#BaseFactory] parseDragonBonesData 
-- @param self
-- @param #char rawData
-- @param #string dragonBonesName
-- @param #float scale
-- @return DragonBonesData#DragonBonesData ret (return value: db.DragonBonesData)
        
--------------------------------
-- 
-- @function [parent=#BaseFactory] clear 
-- @param self
-- @return BaseFactory#BaseFactory self (return value: db.BaseFactory)
        
--------------------------------
-- 
-- @function [parent=#BaseFactory] addDragonBonesData 
-- @param self
-- @param #db.DragonBonesData data
-- @param #string dragonBonesName
-- @return BaseFactory#BaseFactory self (return value: db.BaseFactory)
        
--------------------------------
-- 
-- @function [parent=#BaseFactory] buildArmature 
-- @param self
-- @param #string armatureName
-- @param #string dragonBonesName
-- @param #string skinName
-- @return Armature#Armature ret (return value: db.Armature)
        
--------------------------------
-- 
-- @function [parent=#BaseFactory] addTextureAtlasData 
-- @param self
-- @param #db.TextureAtlasData data
-- @param #string dragonBonesName
-- @return BaseFactory#BaseFactory self (return value: db.BaseFactory)
        
--------------------------------
-- 
-- @function [parent=#BaseFactory] getDragonBonesData 
-- @param self
-- @param #string dragonBonesName
-- @return DragonBonesData#DragonBonesData ret (return value: db.DragonBonesData)
        
--------------------------------
-- 
-- @function [parent=#BaseFactory] parseTextureAtlasData 
-- @param self
-- @param #char rawData
-- @param #void textureAtlas
-- @param #string dragonBonesName
-- @param #float scale
-- @return TextureAtlasData#TextureAtlasData ret (return value: db.TextureAtlasData)
        
--------------------------------
-- 
-- @function [parent=#BaseFactory] replaceSlotDisplayList 
-- @param self
-- @param #string dragonBonesName
-- @param #string armatureName
-- @param #string slotName
-- @param #db.Slot slot
-- @return BaseFactory#BaseFactory self (return value: db.BaseFactory)
        
--------------------------------
-- 
-- @function [parent=#BaseFactory] copyAnimationsToArmature 
-- @param self
-- @param #db.Armature toArmature
-- @param #string fromArmatreName
-- @param #string fromSkinName
-- @param #string fromDragonBonesDataName
-- @param #bool ifRemoveOriginalAnimationList
-- @return bool#bool ret (return value: bool)
        
return nil
