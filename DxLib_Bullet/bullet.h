#pragma once
#include<btBulletDynamicsCommon.h>
#include "Character.h"
#include "BulletWorld.h"

class Bullet{
public:
	Bullet(BulletWorld &bw,Character &c);
	btRigidBody* getBody();
	btCollisionShape* getCollisionShape();
	void draw();
	bool isExist();
	~Bullet();
private:
	btCollisionShape *colShape;
	btVector3 direct;
	btRigidBody *body;
	bool underGround;
};