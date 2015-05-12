#include "Ground.h"
#include "DxLib.h"
#include "BulletWorld.h"


Ground::Ground()
{
	collisionShape = new btBoxShape((size = btVector3(btScalar(30.), btScalar(1.), btScalar(5.))));

	btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(pos=btVector3(0, -5, 0));

	btScalar mass(0.);

	bool isDynamic = (mass != 0.f);

	btVector3 localInertia(0, 0, 0);
	if (isDynamic)
		collisionShape->calculateLocalInertia(mass, localInertia);

	groundTransform.setRotation(btQuaternion(btVector3(0., 0., 1.), (btScalar)(PI/180*15)));
	btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, collisionShape, localInertia);
	rigidBody = new btRigidBody(rbInfo);
	rigidBody->setRestitution(btScalar(0.1));
}

void Ground::setSize(btVector3 &size){
	rigidBody->setCollisionShape(new btBoxShape(size));
	this->size = size;
}

void Ground::Draw(){
	
	btTransform trans;
	rigidBody->getMotionState()->getWorldTransform(trans);
	btQuaternion quat = trans.getRotation();
	quat.setZ(-quat.getZ());
	pos = trans.getOrigin();
	// 頂点配列
	VECTOR vec[8] = {
		VGet(- size[0], + size[1], -(+ size[2])),	//手前左上
		VGet(+ size[0], + size[1], -(+ size[2])),	//手前右上
		VGet(- size[0], - size[1], -(+ size[2])),	//手前左下
		VGet(+ size[0], - size[1], -(+ size[2])),	//手前右下
		VGet(- size[0], + size[1], -(- size[2])),	//奥左上
		VGet(+ size[0], + size[1], -(- size[2])),	//奥右上
		VGet(- size[0], - size[1], -(- size[2])),	//奥手前左下
		VGet(+ size[0], - size[1], -(- size[2])),	//奥手前右下
	};
	for (int i = 0; i < 8; i++){
		vec[i] = BulletWorld::rotateVec(vec[i], quat);
		vec[i].x+=pos[0];
		vec[i].y+=pos[1];
		vec[i].z+=pos[2];
	}
	DWORD col = GetColor(255, 0, 0);

	// 手前
	DxLib::DrawTriangle3D(vec[0], vec[2], vec[3], GetColor(0,255,0), TRUE);
	DxLib::DrawTriangle3D(vec[0], vec[1], vec[3], GetColor(0,0,255), TRUE);

	// 右
	DxLib::DrawTriangle3D(vec[1], vec[5], vec[7], col, TRUE);
	DxLib::DrawTriangle3D(vec[1], vec[3], vec[7], col, TRUE);

	//左
	DxLib::DrawTriangle3D(vec[4], vec[0], vec[2], col, TRUE);
	DxLib::DrawTriangle3D(vec[4], vec[6], vec[2], col, TRUE);

	//上
	DxLib::DrawTriangle3D(vec[4], vec[0], vec[1], GetColor(0,255,255), TRUE);
	DxLib::DrawTriangle3D(vec[5], vec[4], vec[1], GetColor(255,0,255), TRUE);

	//下
	DxLib::DrawTriangle3D(vec[6], vec[2], vec[3], col, TRUE);
	DxLib::DrawTriangle3D(vec[6], vec[7], vec[3], col, TRUE);

	//奥
	DxLib::DrawTriangle3D(vec[4], vec[6], vec[7], col, TRUE);
	DxLib::DrawTriangle3D(vec[5], vec[4], vec[7], col, TRUE);
	
}

void Ground::Update(){

}


Ground::~Ground()
{
	delete(collisionShape);
	delete(rigidBody);
}
