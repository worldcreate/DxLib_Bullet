#pragma once
#include "worldObject.h"
#include "Character.h"
#include "IDraw.h"
#include "IUpdate.h"
#include <vector>

class BulletWorld;

class AbstractWorld:public IDraw,public IUpdate
{
public:
	AbstractWorld(void);
	~AbstractWorld(void);
	virtual void Draw()=0;
	virtual void Update()=0;
	void setBulletWorld(BulletWorld*);
	void setObject(abstractObject*);
	void deleteObject(abstractObject*);
protected:
	std::vector<abstractObject*> worldObjectList;
	BulletWorld *bWorld;
};

