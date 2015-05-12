#pragma once
#include "worldObject.h"
#include "DxLib.h"
#include <btBulletDynamicsCommon.h>

class Ground:public worldObject
{
public:
	Ground();
	virtual void Draw();
	virtual void Update();
	void setSize(btVector3&);
	~Ground();
private:
	btVector3 size;
	btVector3 pos;
};

