#include "abstractObject.h"


abstractObject::abstractObject(void)
{
	collisionShape = NULL;
	rigidBody = NULL;
}

void abstractObject::Draw(){
}

btCollisionShape* abstractObject::getCollisionShape(){
	return collisionShape;
}

btRigidBody* abstractObject::getRigidBody(){
	return rigidBody;
}

void abstractObject::setPos(btVector3 &pos){
	btTransform trans;
	btMotionState *motion;
	motion = rigidBody->getMotionState();
	motion->getWorldTransform(trans);
	trans.setOrigin(pos);
	motion->setWorldTransform(trans);
	rigidBody->setMotionState(motion);
}

void abstractObject::setRot(btScalar angle){
	btTransform trans;
	btMotionState *motion;
	motion = rigidBody->getMotionState();
	motion->getWorldTransform(trans);
	trans.setRotation(btQuaternion(btVector3(0., 0., 1.), (btScalar)(PI / 180 * angle)));
	motion->setWorldTransform(trans);
	rigidBody->setMotionState(motion);
}


abstractObject::~abstractObject(void)
{
}
