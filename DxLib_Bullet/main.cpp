#include <vector>
#include <DxLib.h>
#include "BulletWorld.h"
#include "Character.h"
#include "bullet.h"

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
	if(GetMouseInput()==MOUSE_INPUT_RIGHT){
		int x,y;
		GetMousePoint(&x,&y);
		if(!camera.click){
			camera.oldMouseX=x;
			camera.oldMouseY=y;
			camera.click=true;
		}
		camera.Roll=(x-camera.oldMouseX)*0.01;
		camera.YRoll = (y-camera.oldMouseY)*0.01;
		camera.oldMouseX=x;
		camera.oldMouseY=y;
		

		
		VECTOR vec=camera.pos;
		VECTOR tar=camera.tar;
		vec=VSub(vec,tar);
		MATRIX rot=MGetRotAxis(camera.norm,camera.YRoll);
		VECTOR vec2=VTransform(vec,rot);
		vec2=VAdd(vec2,tar);
		camera.pos=vec2;


		vec=camera.pos;
		tar=camera.tar;
		vec=VSub(vec,tar);
		rot=MGetRotY(camera.Roll);
		VECTOR pos_ret=VTransform(vec,rot);
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

	SetCameraNearFar( 0.1f, 1000.0f ) ;

	ChangeLightTypePoint(VGet(0,20,0),100,1,0,0);

	
	int mex=0,mey=0,mez=0;

	BulletWorld bw;
	Character c(bw);
	std::vector<Bullet*> bullet;

	while(ProcessMessage()==0 && CheckHitKey(KEY_INPUT_ESCAPE)==0){
		ClearDrawScreen();


		SetCameraPositionAndTarget_UpVecY(camera.pos,camera.tar);

		mouseInput(camera);

		DrawSphere3D( VGet(0,0,0), 3, 10, GetColor(255,0,255), GetColor(0,0,0),TRUE ) ;
		DrawSphere3D( VGet(20,0,0), 3, 10, GetColor(255,0,255), GetColor(0,0,0),TRUE ) ;
		DrawSphere3D(VGet(300,0,0),3,10,GetColor(255,0,255),GetColor(0,0,0),TRUE);
		DrawTriangle3D(VGet(200,0,0),VGet(-200,0,0),VGet(0,0,300),GetColor(128,0,128),TRUE);
		

		char key[256];
		GetHitKeyStateAll(key);
		int move=0;
		if(key[KEY_INPUT_S]){
			/*
			mez++;
			camera.pos.z++;
			camera.tar.z++;
			*/
			move+=Character::DOWN;
		}
		if(key[KEY_INPUT_W]){
			/*
			mez--;
			camera.pos.z--;
			camera.tar.z--;
			*/
			move+=Character::UP;
		}
		if(key[KEY_INPUT_D]){
			/*
			mex--;
			camera.pos.x--;
			camera.tar.x--;
			*/
			move+=Character::RIGHT;
		}
		if(key[KEY_INPUT_A]){
			/*
			mex++;
			camera.pos.x++;
			camera.tar.x++;
			*/
			move+=Character::LEFT;
		}
		if(key[KEY_INPUT_SPACE]){
			bullet.push_back(new Bullet(bw,c));
		}
		btVector3 bt=c.getPos();
		int tx=mex,ty=mey,tz=mez;
		mex=bt.getX();mey=bt.getY();mez=-bt.getZ();
		camera.pos.x-=tx-mex;camera.tar.x-=tx-mex;
		camera.pos.y-=ty-mey;camera.tar.y-=ty-mey;
		camera.pos.z-=tz-mez;camera.tar.z-=tz-mez;
		c.move(move);
		c.draw();
		for(int i=0;i<bullet.size();i++){
			bullet[i]->draw();
			if(!bullet[i]->isExist()){
				bw.removeRigidBody(bullet[i]->getBody());
				bw.removeCollisionShape(bullet[i]->getCollisionShape());
			}
		}
		bw.loop();
		ScreenFlip();
	}

	DxLib_End();

	return 0;
}