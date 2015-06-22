#pragma once
#include <vector>
#include "BulletInclude.h"
#include<btBulletDynamicsCommon.h>
#include "DxLib.h"

class abstractObject;

class BulletWorld{
public:
	BulletWorld();
	~BulletWorld();
	void loop();
	void addCollisionShape(btCollisionShape *);
	void addRigidBody(btRigidBody *);
	static MATRIX QuatToMatrix(btQuaternion&);
	void removeRigidBody(btRigidBody *);
	void removeCollisionShape(btCollisionShape *);
	void setObject(abstractObject *);
	void deleteObject(abstractObject *);
	static VECTOR rotateVec(VECTOR &,btQuaternion&);
	static btBvhTriangleMeshShape* converToBtBvhTriangleMeshShapeFromDxModel(int,btTriangleMesh*&);
private:
	btDiscreteDynamicsWorld* dynamicsWorld;
	btAlignedObjectArray<btCollisionShape*> collisionShapes;
	btDefaultCollisionConfiguration* collisionConfiguration;
	btSequentialImpulseConstraintSolver* solver;
	btBroadphaseInterface* overlappingPairCache;
	btCollisionDispatcher* dispatcher;
};