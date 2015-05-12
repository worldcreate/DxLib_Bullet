#include "BulletInclude.h"
#include "dxDebugDraw.h"
#include<btBulletDynamicsCommon.h>
#include <DxLib.h>

typedef struct{
	VECTOR pos;
	VECTOR tar;
	VECTOR norm;
	float Far;
	float Roll;
	float YRoll;
	int oldMouseX;
	int oldMouseY;
	bool click;
}Camera;

void mouseInput(Camera &camera){
	camera.YRoll = GetMouseWheelRotVol()*0.1 ;
	VECTOR vec=camera.pos;
	VECTOR tar=camera.tar;
	vec=VSub(vec,tar);
	MATRIX rot=MGetRotAxis(camera.norm,camera.YRoll);
	VECTOR vec2=VTransform(vec,rot);
	vec2=VAdd(vec2,tar);
	camera.pos=vec2;
		
	if(GetMouseInput()==MOUSE_INPUT_RIGHT){
		int x,y;
		GetMousePoint(&x,&y);
		if(!camera.click){
			camera.oldMouseX=x;
			camera.oldMouseY=y;
			camera.click=true;
		}
		camera.Roll=(x-camera.oldMouseX)*0.01;
		camera.oldMouseX=x;
		camera.oldMouseY=y;
		
		VECTOR pos=camera.pos;
		const VECTOR tar=camera.tar;
		pos=VSub(pos,tar);
		MATRIX rot=MGetRotY(camera.Roll);
		VECTOR pos_ret=VTransform(pos,rot);
		pos_ret=VAdd(pos_ret,tar);
		camera.pos=pos_ret;

		VECTOR norm=camera.norm;
		VECTOR norm_ret=VTransform(norm,rot);
		camera.norm=norm_ret;
	}else{
		camera.click=false;
	}
	
}

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nCmdShow){
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	Camera camera;
	camera.Far=0;
	camera.Roll=0;
	camera.YRoll=0;
	camera.pos=VGet(50,50,0);
	camera.tar=VGet(0,0,0);
	camera.norm=VGet(0,0,-1);
	camera.oldMouseX=0;
	camera.oldMouseY=0;
	camera.click=false;

	SetCameraNearFar( 0.1f, 200.0f ) ;

	ChangeLightTypePoint(VGet(0,20,0),100,1,0,0);

	int model=MV1LoadModel("alice.pmd");
	if(model==-1)return -1;

	MV1SetPosition( model, VGet( 0,0,0) ) ;  
	
	int mex=0,mey=0,mez=0;
	while(ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE)==0){
		ClearDrawScreen();

		MV1SetPosition(model,VGet(mex,mey,mez));
		MV1DrawModel(model) ;

		SetCameraPositionAndTarget_UpVecY(camera.pos,camera.tar);

		mouseInput(camera);

		DrawSphere3D( VGet(0,0,0), 3, 10, GetColor(255,0,255), GetColor(0,0,0),TRUE ) ;
		DrawSphere3D( VGet(20,0,0), 3, 10, GetColor(255,0,255), GetColor(0,0,0),TRUE ) ;
		DrawSphere3D(VGet(300,0,0),3,10,GetColor(255,0,255),GetColor(0,0,0),TRUE);
		DrawTriangle3D(VGet(200,0,0),VGet(-200,0,0),VGet(0,0,300),GetColor(0,0,255),TRUE);

		char key[256];
		GetHitKeyStateAll(key);
		if(key[KEY_INPUT_S]){
			mez++;
			camera.pos.z++;
			camera.tar.z++;
		}
		if(key[KEY_INPUT_W]){
			mez--;
			camera.pos.z--;
			camera.tar.z--;
		}
		if(key[KEY_INPUT_D]){
			mex--;
			camera.pos.x--;
			camera.tar.x--;
		}
		if(key[KEY_INPUT_A]){
			mex++;
			camera.pos.x++;
			camera.tar.x++;
		}

		ScreenFlip();
	}
	/*

	btDefaultCollisionConfiguration* collisionConfiguration=new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher=new btCollisionDispatcher(collisionConfiguration);

	btBroadphaseInterface* overlappingPairCache=new btDbvtBroadphase();
	btSequentialImpulseConstraintSolver* solver=new btSequentialImpulseConstraintSolver;
	btDiscreteDynamicsWorld* dynamicsWorld=new btDiscreteDynamicsWorld(dispatcher,overlappingPairCache,solver,collisionConfiguration);
	
	dynamicsWorld->setGravity(btVector3(0,-10,0));

	btCollisionShape* groundShape=new btBoxShape(btVector3(btScalar(50.),btScalar(50.),btScalar(50.)));

	btAlignedObjectArray<btCollisionShape*> collisionShapes;
	collisionShapes.push_back(groundShape);

	btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(btVector3(0,-56,0));

	{
		btScalar mass(0.);

		bool isDynamic = (mass != 0.f);
		
		btVector3 localInertia(0,0,0);
		if(isDynamic)
			groundShape->calculateLocalInertia(mass,localInertia);
		
		btDefaultMotionState* myMotionState=new btDefaultMotionState(groundTransform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,groundShape,localInertia);
		btRigidBody* body=new btRigidBody(rbInfo);

		dynamicsWorld->addRigidBody(body);

	}

	{
		btCollisionShape* colShape=new btSphereShape(btScalar(1.));
		collisionShapes.push_back(colShape);

		btTransform startTransform;
		startTransform.setIdentity();

		btScalar mass(1.f);

		bool isDynamic=(mass!=0.f);

		btVector3 localInertia(0,0,0);
		if(isDynamic)
			colShape->calculateLocalInertia(mass,localInertia);
		startTransform.setOrigin(btVector3(2,30,0));

		btDefaultMotionState* myMotionState=new btDefaultMotionState(startTransform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,colShape,localInertia);
		btRigidBody*body=new btRigidBody(rbInfo);

		dynamicsWorld->addRigidBody(body);

	}

	SetCameraNearFar( 0.1f, 1000.0f ) ;
	SetCameraPositionAndTarget_UpVecY(VGet(0,2,30),VGet(0,0,0));

	DxDebugDraw g_debugdraw;

	dynamicsWorld->setDebugDrawer(&g_debugdraw);
    dynamicsWorld->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_DrawWireframe);

	while(ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE)==0){
		ClearDrawScreen();

		dynamicsWorld->stepSimulation(1.f/60.f,10);

		for(int j=dynamicsWorld->getNumCollisionObjects()-1;j>=0;j--){
			if(1==j){
				btCollisionObject* obj=dynamicsWorld->getCollisionObjectArray()[j];
				btRigidBody* body=btRigidBody::upcast(obj);
				if(body&&body->getMotionState()){
					btTransform trans;
					body->getMotionState()->getWorldTransform(trans);

					char temp[256];
					sprintf(temp,"%f,%f,%f",trans.getOrigin().getX(),trans.getOrigin().getY(),trans.getOrigin().getZ());
					DrawString(0,0,temp,GetColor(255,0,0));
					DrawSphere3D(VGet(trans.getOrigin().getX(),trans.getOrigin().getY(),trans.getOrigin().getZ()),1.0f,16,GetColor(255,0,0),GetColor(0,0,0),TRUE);
				}
			}
		}
		dynamicsWorld->debugDrawWorld();
		ScreenFlip();
	}

	for(int i=dynamicsWorld->getNumCollisionObjects()-1;i>=0;i--){
		btCollisionObject* obj=dynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body=btRigidBody::upcast(obj);
		if(body&& body->getMotionState()){
			delete body->getMotionState();
		}
		dynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}
	for(int j=0;j<collisionShapes.size();j++){
		btCollisionShape* shape=collisionShapes[j];
		collisionShapes[j]=0;
		delete shape;
	}
	delete dynamicsWorld;
	delete solver;
	delete overlappingPairCache;
	delete dispatcher;
	delete collisionConfiguration;
	collisionShapes.clear();

	*/

	DxLib_End();

	return 0;
}