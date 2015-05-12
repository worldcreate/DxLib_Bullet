#pragma once
#include "AbstractWorld.h"

class WorldCreater
{
public:
	WorldCreater();
	~WorldCreater();
	AbstractWorld* getStage();
protected:
	AbstractWorld *stage;
};

