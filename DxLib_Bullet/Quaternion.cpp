#include "DxLib.h"
#include<btBulletDynamicsCommon.h>
#include "BulletWorld.h"

#define PI 3.14159265357989
static int count=0;

inline void draw(float x,float y,float z,float w){
		char temp[256];
		sprintf(temp,"%f,%f,%f,%f",x,y,z,w);
		DrawString(0,(count+1)*20,temp,GetColor(0,255,0));
		count++;
}

inline btQuaternion quatCross(const btQuaternion &q1,const btQuaternion &q2){
	
	btQuaternion q3;
    q3.setW(q1.getW() * q2.getW() - q1.getX() * q2.getX() - q1.getY() * q2.getY() - q1.getZ() * q2.getZ());
    q3.setX(q1.getY() * q2.getZ() - q1.getZ() * q2.getY() + q1.getW() * q2.getX() + q1.getX() * q2.getW());
    q3.setY(q1.getZ() * q2.getX() - q1.getX() * q2.getZ() + q1.getW() * q2.getY() + q1.getY() * q2.getW());
    q3.setZ(q1.getX() * q2.getY() - q1.getY() * q2.getX() + q1.getW() * q2.getZ() + q1.getZ() * q2.getW());
	return q3;
}

inline btQuaternion quatNorm(const btQuaternion &q){
	btQuaternion r;
	r.setX(-q.getX());r.setY(-q.getY());r.setZ(-q.getZ());r.setW(q.getW());
	return r;
}

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nCmdShow){
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	SetCameraNearFar( 0.1f, 200.0f ) ;

	ChangeLightTypePoint(VGet(0,20,0),100,1,0,0);

	int model=MV1LoadModel("alice.pmd");
	if(model==-1)return -1;

	MV1SetPosition( model, VGet( 0,0,0) ) ;  
	
	int mex=0,mey=0,mez=0;
	BulletWorld bw;
	btCollisionShape* colShape=new btBoxShape(btVector3(btScalar(2.5),btScalar(2.5),btScalar(2.5)));

	btTransform startTransform;
	startTransform.setIdentity();


	btScalar mass(2.f);

	bool isDynamic=(mass!=0.f);

	btVector3 localInertia(0,0,0);
	if(isDynamic)
		colShape->calculateLocalInertia(mass,localInertia);
	startTransform.setOrigin(btVector3(0,0,0));

	btDefaultMotionState* myMotionState=new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,colShape,localInertia);
	btRigidBody *body=new btRigidBody(rbInfo);
	bw.addRigidBody(body);
	btTransform bt;
	bt.setIdentity();

	while(ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE)==0){
		count=0;
		ClearDrawScreen();

		/*
		MV1SetPosition(model,VGet(mex,mey,mez));
		MV1DrawModel(model) ;

		SetCameraPositionAndTarget_UpVecY(VGet(0,20,20),VGet(0,0,0));

		btTransform bt=body->getWorldTransform();
		btQuaternion bq=bt.getRotation();
		*/

		btQuaternion bqq;
		bqq.setX(1);bqq.setY(0);bqq.setZ(0);bqq.setW(0);
		draw(bqq.x(),bqq.y(),bqq.z(),bqq.w());
		btQuaternion rot(btVector3(0,1,0),PI/2);

		btQuaternion ret=quatCross(quatNorm(rot),bqq);
		ret=quatCross(ret,rot);

		draw(ret.x(),ret.y(),ret.z(),ret.w());

		/*
		body->applyTorque(btVector3(50,0,0));

		bw.loop();
		*/
		ScreenFlip();
	}

	DxLib_End();

	return 0;

}