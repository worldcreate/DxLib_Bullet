#include "Character.h"
#include "DxLib.h"
#include "BulletWorld.h"

Character::Character(){
	m_playerHandle=MV1LoadModel("model\\char\\miku\\LatŽ®ƒ~ƒNVer2.31_Normal.pmd");
	collisionShape=BulletWorld::convertBulletCollisionShapeFromDXLIBModel(m_playerHandle,m_triangleMesh);

	btTransform playerTransform;
	playerTransform.setIdentity();
	playerTransform.setOrigin(btVector3(0, 5, 0));

	btScalar mass(3.0);

	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0, 5, 0);

	btDefaultMotionState* myMotionState = new btDefaultMotionState(playerTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, collisionShape, localInertia);
	rigidBody = new btRigidBody(rbInfo);
}

void Character::Draw(){
	MV1DrawModel(m_playerHandle);
}

void Character::Update(){
	MV1SetPosition(m_playerHandle,VGet(0,0,0));
}


Character::~Character(void)
{
	MV1DeleteModel(m_playerHandle);
	delete m_triangleMesh;
}
