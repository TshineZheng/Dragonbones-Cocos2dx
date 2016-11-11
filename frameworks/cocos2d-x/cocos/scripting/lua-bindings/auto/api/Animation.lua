
--------------------------------
-- @module Animation
-- @extend BaseObject
-- @parent_module db

--------------------------------
-- 
-- @function [parent=#Animation] isPlaying 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Animation] getAnimationNames 
-- @param self
-- @return array_table#array_table ret (return value: array_table)
        
--------------------------------
-- 
-- @function [parent=#Animation] fadeIn 
-- @param self
-- @param #string animationName
-- @param #float fadeInTime
-- @param #int playTimes
-- @param #int layer
-- @param #string group
-- @param #int fadeOutMode
-- @param #bool additiveBlending
-- @param #bool displayControl
-- @param #bool pauseFadeOut
-- @param #bool pauseFadeIn
-- @return AnimationState#AnimationState ret (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#Animation] isCompleted 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Animation] reset 
-- @param self
-- @return Animation#Animation self (return value: db.Animation)
        
--------------------------------
-- 
-- @function [parent=#Animation] play 
-- @param self
-- @return AnimationState#AnimationState ret (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#Animation] getState 
-- @param self
-- @param #string animationName
-- @return AnimationState#AnimationState ret (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#Animation] stop 
-- @param self
-- @param #string animationName
-- @return Animation#Animation self (return value: db.Animation)
        
--------------------------------
-- 
-- @function [parent=#Animation] getLastAnimationName 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#Animation] getLastAnimationState 
-- @param self
-- @return AnimationState#AnimationState ret (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#Animation] gotoAndPlayByTime 
-- @param self
-- @param #string animationName
-- @param #float time
-- @param #int playTimes
-- @return AnimationState#AnimationState ret (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#Animation] gotoAndPlayByProgress 
-- @param self
-- @param #string animationName
-- @param #float progress
-- @param #int playTimes
-- @return AnimationState#AnimationState ret (return value: db.AnimationState)
        
--------------------------------
--  @private 
-- @function [parent=#Animation] _advanceTime 
-- @param self
-- @param #float passedTime
-- @return Animation#Animation self (return value: db.Animation)
        
--------------------------------
--  @private 
-- @function [parent=#Animation] _updateFFDTimelineStates 
-- @param self
-- @return Animation#Animation self (return value: db.Animation)
        
--------------------------------
-- 
-- @function [parent=#Animation] hasAnimation 
-- @param self
-- @param #string animationName
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Animation] gotoAndStopByTime 
-- @param self
-- @param #string animationName
-- @param #float time
-- @return AnimationState#AnimationState ret (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#Animation] gotoAndStopByProgress 
-- @param self
-- @param #string animationName
-- @param #float progress
-- @return AnimationState#AnimationState ret (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#Animation] gotoAndPlayByFrame 
-- @param self
-- @param #string animationName
-- @param #unsigned int frame
-- @param #int playTimes
-- @return AnimationState#AnimationState ret (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#Animation] gotoAndStopByFrame 
-- @param self
-- @param #string animationName
-- @param #unsigned int frame
-- @return AnimationState#AnimationState ret (return value: db.AnimationState)
        
--------------------------------
-- 
-- @function [parent=#Animation] getTypeIndex 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#Animation] getClassTypeIndex 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#Animation] Animation 
-- @param self
-- @return Animation#Animation self (return value: db.Animation)
        
return nil
