#pragma once
#include "IDraw.h"
#include "IUpdate.h"
#include <btBulletDynamicsCommon.h>
#define PI 3.141592653
class abstractObject:public IDraw,public IUpdate
{
public:
	abstractObject(void);
	virtual void Draw();
	virtual void Update()=0;
	btCollisionShape* getCollisionShape();
	btRigidBody* getRigidBody();
	void setPos(btVector3 &);
	void setRot(btScalar);
	~abstractObject(void);
protected:
	btCollisionShape *collisionShape;
	btRigidBody *rigidBody;
};

