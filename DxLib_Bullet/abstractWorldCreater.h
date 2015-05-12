#pragma once
#include "AbstractWorld.h"

class abstractWorldCreater
{
public:
	abstractWorldCreater();
	~abstractWorldCreater();
	AbstractWorld* getStage();
protected:
	AbstractWorld *stage;
};

