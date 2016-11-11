#pragma once

#include "cocos2d.h"
#include "../../DragonBonesHeaders.h"

DRAGONBONES_NAMESPACE_BEGIN

class CCEventObject : public cocos2d::Ref
{
public:
	static CCEventObject* create() {
		CCEventObject* cceventobject = new (std::nothrow) CCEventObject();
		if (cceventobject)
		{
			cceventobject->autorelease();
			return cceventobject;
		}
		CC_SAFE_DELETE(cceventobject);
		return nullptr;
	};

	EventObject* eventObj;

	std::string Type() const { return eventObj->type; }

	std::string Name() const { return eventObj->name; }

	void* UserData() const { return eventObj->userData; }

	dragonBones::Armature* Armature() const { return eventObj->armature; }

	dragonBones::Bone* Bone() const { return eventObj->bone; }

	dragonBones::Slot* Slot() const { return eventObj->slot; }

	dragonBones::AnimationState* AnimationState() const { return eventObj->animationState; }

	dragonBones::AnimationFrameData* Frame() const { return eventObj->frame; }

	CCEventObject() {};
	~CCEventObject() {};

private:

};

DRAGONBONES_NAMESPACE_END
