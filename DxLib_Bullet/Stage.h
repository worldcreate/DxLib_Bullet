#pragma once
#include "AbstractWorld.h"

class BulletWorld;

class Stage:public AbstractWorld
{
public:
	Stage(BulletWorld *);
	virtual void Draw();
	virtual void Update();
	~Stage(void);
private:
	int stageHandle;
	btCollisionShape* collisionShape;
	btTriangleMesh* triangleMesh;
	btBvhTriangleMeshShape* getShape(int);

	class stageObject:public abstractObject{
	public:
		stageObject(btCollisionShape *obj){
			collisionShape = obj;
			btDefaultMotionState* groundMotionState = new
				btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 0, 0)));
			btRigidBody::btRigidBodyConstructionInfo
				groundRigidBodyCI(0, groundMotionState, collisionShape, btVector3(0, 0, 0));
			rigidBody = new btRigidBody(groundRigidBodyCI);
		}
		void Update(){}

	};
};