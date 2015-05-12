#include "Ball.h"
#include "DxLib.h"
#include <btBulletDynamicsCommon.h>
#include "GameScene.h"

Ball::Ball()
{
	radius = 2;
	collisionShape = new btSphereShape(radius);

	btTransform sphereTransform;
	sphereTransform.setIdentity();
	sphereTransform.setOrigin(btVector3(20, 30, 0));

	btScalar mass(3.0);

	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0, 0, 0);
	if (isDynamic)
		collisionShape->calculateLocalInertia(mass, localInertia);

	btDefaultMotionState* myMotionState = new btDefaultMotionState(sphereTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, collisionShape, localInertia);
	rigidBody = new btRigidBody(rbInfo);
	rigidBody->setRestitution(btScalar(0.1));

	cnt = 0;
}

void Ball::Draw(){
	btTransform trans;
	rigidBody->getMotionState()->getWorldTransform(trans);
	VECTOR pos = VGet(trans.getOrigin().getX(),
		trans.getOrigin().getY(),
		-trans.getOrigin().getZ());
	DrawSphere3D(pos, radius, 50, GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);
}

void Ball::Update(){
	btTransform trans;
	rigidBody->getMotionState()->getWorldTransform(trans);
	if(trans.getOrigin().getY()<0 && cnt==0){
		cnt++;
		GameScene::instantiate(new Ball());
	}
	if (trans.getOrigin().getY() < -100){
		GameScene::destroy(this);
	}
}

Ball::~Ball()
{
}
