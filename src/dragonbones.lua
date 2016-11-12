db = db or {}

db.ANGLE_TO_RADIAN = math.pi / 180
db.RADIAN_TO_ANGLE = 180 / math.pi

db.Event = db.CCEventObject or {}

db.Event.START = "start"
db.Event.LOOP_COMPLETE = "loopComplete"
db.Event.COMPLETE = "complete"

db.Event.FADE_IN = "fadeIn"
db.Event.FADE_IN_COMPLETE = "fadeInComplete"
db.Event.FADE_OUT = "fadeOut"
db.Event.FADE_OUT_COMPLETE = "fadeOutComplete"

db.Event.FRAME_EVENT = "frameEvent"
db.Event.SOUND_EVENT = "soundEvent"


db.AnimationFadeOutMode = db.AnimationFadeOutMode or {}

db.AnimationFadeOutMode.None = 0
db.AnimationFadeOutMode.SameLayer = 1
db.AnimationFadeOutMode.SameGroup = 2
db.AnimationFadeOutMode.SameLayerAndGroup = 3
db.AnimationFadeOutMode.All  = 4