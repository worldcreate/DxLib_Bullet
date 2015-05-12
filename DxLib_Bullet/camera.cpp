#include "camera.h"
#include "DxLib.h"
#include "BulletWorld.h"

camera::camera()
{
	axis[Y]=VGet(0,1,0);
	pos=VGet(0,0,-30);
	tar=VGet(0,0,0);
	SetCameraPositionAndTargetAndUpVec(pos,tar,axis[Y]);
	SetCameraNearFar(1,1000);
}

void camera::Draw(){
#ifdef _DEBUG
	char temp[256];
	sprintf(temp,"camera pos=%.3f,%.3f,%.3f",pos.x,pos.y,pos.z);
	DrawString(400,0,temp,GetColor(0,255,0));

	DrawLine3D(tar,VGet(tar.x+10,tar.y,tar.z),GetColor(255,0,0));
	DrawLine3D(tar,VGet(tar.x,tar.y+10,tar.z),GetColor(0,255,0));
	DrawLine3D(tar,VGet(tar.x,tar.y,tar.z+10),GetColor(0,0,255));
#endif
	
}

void camera::Update(){

}

void camera::mouseClicked(MouseEvent &e){

}

void camera::mouseReleased(MouseEvent &e){

}

void camera::mousePressed(MouseEvent &e){
	if(e.getMouseState(MOUSE_INPUT_MIDDLE) || e.getMouseState(MOUSE_INPUT_RIGHT)){
		e.getMousePos(&pMouseX,&pMouseY);
		return;
	}
}

void camera::mouseMoved(MouseEvent &e){
	int x,y;
	e.getMousePos(&x,&y);
	getAxis();
	if(e.getMouseState(MOUSE_INPUT_MIDDLE)){
		move(pMouseX-x,y-pMouseY);
	}
	if(e.getMouseState(MOUSE_INPUT_RIGHT)){
		rot(pMouseX-x,pMouseY-y);
	}
	pMouseX=x;pMouseY=y;
	SetCameraPositionAndTargetAndUpVec(pos,tar,axis[Y]);
}

void camera::mouseWheeled(MouseEvent &e){
	VECTOR direct=VSub(pos,tar);
	direct=VNorm(direct);
	VECTOR dst=VScale(direct,-e.getMouseWheelVal());
	if(VSize(dst)==0){
		pos=VGet(-pos.x,-pos.y,-pos.z);
	}else{
		pos=VAdd(pos,dst);
	}
	SetCameraPositionAndTargetAndUpVec(pos,tar,axis[Y]);
}

void camera::move(int x,int y){
	VECTOR dist=VAdd(VScale(axis[Y],(float)y),VScale(axis[X],(float)x));
	pos=VAdd(pos,dist);
	tar=VAdd(tar,dist);
}

void camera::rot(int x,int y){
	float dY=PI/180*y;
	float dX=PI/180*x;
	btQuaternion axisY=btQuaternion(btVector3(axis[Y].x,axis[Y].y,axis[Y].z),btScalar(dX));
	btQuaternion axisX=btQuaternion(btVector3(axis[X].x,axis[X].y,axis[X].z),btScalar(dY));
	pos=VSub(pos,tar);
	pos=BulletWorld::rotateVec(pos,axisX);
	pos=BulletWorld::rotateVec(pos,axisY);
	pos=VAdd(pos,tar);
	axis[Y]=BulletWorld::rotateVec(axis[Y],axisX);
	axis[Y]=BulletWorld::rotateVec(axis[Y],axisY);
}

void camera::getAxis(){
	axis[Z]=VSub(tar,pos);
	axis[X]=VCross(axis[Y],axis[Z]);
	for(int i=0;i<3;i++)
		axis[i]=VNorm(axis[i]);
}

camera::~camera()
{
}
