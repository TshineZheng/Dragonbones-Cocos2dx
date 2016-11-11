
--------------------------------
-- @module AnimationData
-- @extend TimelineData<dragonBones::AnimationFrameData>
-- @parent_module db

--------------------------------
--  @private 
-- @function [parent=#AnimationData] cacheFrames 
-- @param self
-- @param #float value
-- @return AnimationData#AnimationData self (return value: db.AnimationData)
        
--------------------------------
--  @private 
-- @function [parent=#AnimationData] getFFDTimeline 
-- @param self
-- @param #string skinName
-- @param #string slotName
-- @param #unsigned int displayIndex
-- @return FFDTimelineData#FFDTimelineData ret (return value: db.FFDTimelineData)
        
--------------------------------
--  @private 
-- @function [parent=#AnimationData] getSlotTimeline 
-- @param self
-- @param #string name
-- @return SlotTimelineData#SlotTimelineData ret (return value: db.SlotTimelineData)
        
--------------------------------
--  @private 
-- @function [parent=#AnimationData] addSlotTimeline 
-- @param self
-- @param #db.SlotTimelineData value
-- @return AnimationData#AnimationData self (return value: db.AnimationData)
        
--------------------------------
--  @private 
-- @function [parent=#AnimationData] addFFDTimeline 
-- @param self
-- @param #db.FFDTimelineData value
-- @return AnimationData#AnimationData self (return value: db.AnimationData)
        
--------------------------------
-- 
-- @function [parent=#AnimationData] getClassTypeIndex 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
--  @private 
-- @function [parent=#AnimationData] addBoneTimeline 
-- @param self
-- @param #db.BoneTimelineData value
-- @return AnimationData#AnimationData self (return value: db.AnimationData)
        
--------------------------------
--  @private 
-- @function [parent=#AnimationData] getBoneTimeline 
-- @param self
-- @param #string name
-- @return BoneTimelineData#BoneTimelineData ret (return value: db.BoneTimelineData)
        
--------------------------------
-- 
-- @function [parent=#AnimationData] getTypeIndex 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
--  @private 
-- @function [parent=#AnimationData] AnimationData 
-- @param self
-- @return AnimationData#AnimationData self (return value: db.AnimationData)
        
return nil
