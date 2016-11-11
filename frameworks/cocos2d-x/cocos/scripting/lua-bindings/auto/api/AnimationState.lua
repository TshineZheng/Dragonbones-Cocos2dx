
--------------------------------
-- @module AnimationState
-- @extend BaseObject
-- @parent_module db

--------------------------------
-- 
-- @function [parent=#AnimationState] setCurrentTime 
-- @param self
-- @param #float value
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
--------------------------------
--  @private 
-- @function [parent=#AnimationState] _updateTimelineStates 
-- @param self
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] removeBoneMask 
-- @param self
-- @param #string name
-- @param #bool recursive
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] getGroup 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] getCurrentPlayTimes 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] getName 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] lua_getAnimationData 
-- @param self
-- @return AnimationData#AnimationData ret (return value: db.AnimationData)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] getCurrentTime 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
--  @private 
-- @function [parent=#AnimationState] _fadeIn 
-- @param self
-- @param #db.Armature armature
-- @param #db.AnimationData clip
-- @param #string animationName
-- @param #unsigned int playTimes
-- @param #float position
-- @param #float duration
-- @param #float time
-- @param #float timeScale
-- @param #float fadeInTime
-- @param #bool pausePlayhead
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] getTotalTime 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] removeAllBoneMask 
-- @param self
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] getLayer 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] isCompleted 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] play 
-- @param self
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] fadeOut 
-- @param self
-- @param #float fadeOutTime
-- @param #bool pausePlayhead
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] stop 
-- @param self
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] isPlaying 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
--  @private 
-- @function [parent=#AnimationState] _advanceTime 
-- @param self
-- @param #float passedTime
-- @param #float weightLeft
-- @param #int index
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
--------------------------------
--  @private 
-- @function [parent=#AnimationState] _updateFFDTimelineStates 
-- @param self
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] addBoneMask 
-- @param self
-- @param #string name
-- @param #bool recursive
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] containsBoneMask 
-- @param self
-- @param #string name
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] getTypeIndex 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] getClassTypeIndex 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#AnimationState] AnimationState 
-- @param self
-- @return AnimationState#AnimationState self (return value: db.AnimationState)
        
return nil
