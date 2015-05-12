#pragma once
#include <string>
#include "AbstractWorld.h"
class StageFactory
{
public:
	StageFactory(void);
	StageFactory(std::string);
	~StageFactory(void);
	AbstractWorld* getStage();
private:
	AbstractWorld *stage;
};

