#include "bullet.h"
#include "DxLib.h"

#define SPEED 50

Bullet::Bullet(BulletWorld &bw,Character &c)
{
	colShape=new btSphereShape(btScalar(2.));
	direct=btVector3(btScalar(0),btScalar(0),btScalar(1));
	bw.addCollisionShape(colShape);

	btTransform startTransform;
	startTransform.setIdentity();
	/*
	startTransform.setOrigin(
		btVector3(c.getPos().x(),c.getPos().y()+20,c.getPos().z())
	);
	*/
	startTransform.setRotation(
		btQuaternion(
			btVector3(
				btScalar(0),btScalar(0),btScalar(1)
			)
			,btScalar(0)
		)
	);
	//btVector3 vec=quatRotate(c.getRotation(),direct);
	

	btScalar mass(2.f);

	bool isDynamic=(mass!=0.f);

	btVector3 localInertia(0,0,0);
	if(isDynamic)
		colShape->calculateLocalInertia(mass,localInertia);

	btDefaultMotionState* myMotionState=new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,colShape,localInertia);
	body=new btRigidBody(rbInfo);

	body->setFriction(btScalar(0.7));
	//body->setLinearVelocity(btVector3(SPEED*vec.x(),SPEED*1.5,SPEED*vec.z()));
	bw.addRigidBody(body);
	underGround=false;
}

btRigidBody* Bullet::getBody(){
	return body;
}

btCollisionShape* Bullet::getCollisionShape(){
	return colShape;
}

void Bullet::draw(){
	btTransform bt=body->getWorldTransform();
	btVector3 vec=bt.getOrigin();

	DrawSphere3D(
		VGet(vec.x(),vec.y(),-vec.z())
		,2,10,GetColor(0,255,0),GetColor(255,255,255),TRUE
	);
	if(vec.y()<0){
		underGround=true;
	}
}

bool Bullet::isExist(){
	return !underGround;
}


Bullet::~Bullet(void)
{
}
