#pragma once
#include "abstractObject.h"

class worldObject:public abstractObject
{
public:
	worldObject(void);
	~worldObject(void);
	virtual void Update() = 0;
};

