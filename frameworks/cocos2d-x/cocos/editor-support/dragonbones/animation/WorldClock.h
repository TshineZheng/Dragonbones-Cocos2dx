#ifndef DRAGONBONES_WORLD_CLOCK_H
#define DRAGONBONES_WORLD_CLOCK_H

#include "../core/DragonBones.h"
#include "IAnimateble.h"
#include "../armature/Armature.h"

DRAGONBONES_NAMESPACE_BEGIN
class WorldClock final : public IAnimateble
{
public:
    static WorldClock clock;
	static WorldClock* getInstance();

public:
    float time;
    float timeScale;

private:
    std::vector<IAnimateble*> _animatebles;

public:
    WorldClock();
    ~WorldClock();

    virtual void advanceTime(float passedTime) override;
    bool contains(const IAnimateble* value) const;
    void add(IAnimateble* value);
    void remove(IAnimateble* value);
    void clear();

	void inline lua_advanceTime(float passedTime)
	{
		advanceTime(passedTime);
	}

	void inline lua_add(Armature* armature)
	{
		add(armature);
	}

	void inline lua_remove(Armature* armature)
	{
		remove(armature);
	}

private:
    DRAGONBONES_DISALLOW_COPY_AND_ASSIGN(WorldClock);
};

DRAGONBONES_NAMESPACE_END
#endif // DRAGONBONES_WORLD_CLOCK_H