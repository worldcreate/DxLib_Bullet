#include <DxLib.h>
#include "System.h"
#include "SceneContext.h"

System::System(void)
{
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	for(int i=0;i<256;i++)
		prevKey[i]=0;
	GetMousePoint(&prevMouseX,&prevMouseY);
	prevMouseState=GetMouseInput();

	borerControl=BorerControl::getInstance();
}

System::~System(void)
{
	delete(borerControl);
}

void System::addKeyboardListener(KeyboardListener *obj){
	keyboardList.push_back(obj);
}

void System::addMouseListener(MouseListener *obj){
	mouseList.push_back(obj);
}


void System::loop(){
	SceneContext sc;
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0){
		ClearDrawScreen();

		keyCheck();
		mouseCheck();
		CheckBorerControl();
		sc.scene();

		ScreenFlip();
	}
}

void System::keyCheck(){
	char key[256];
	GetHitKeyStateAll(key);
	bool bPress=false,bDown=false,bUp=false;
	for(int i=0;i<256;i++){
		keyState[i]=KeyboardListener::keystate::KEY_NONE;
		if(key[i]!=prevKey[i]){
			if(key[i]==0 && prevKey[i]==1){
				keyState[i]=KeyboardListener::keystate::KEY_UP;
				bUp=true;
			}
			if(key[i]==1 && prevKey[i]==0){
				keyState[i]=KeyboardListener::keystate::KEY_DOWN;
				bDown=true;
			}
		}else{
			if(key[i]==1 && prevKey[i]==1){
				keyState[i]=KeyboardListener::keystate::KEY_PRESS;
				bPress=true;
			}
		}
	}
	if(bUp)
		onKeyUp();
	if(bDown)
		onKeyDown();
	if(bPress)
		onKeyPress();
	for(int i=0;i<256;i++)
		prevKey[i]=key[i];
}

void System::onKeyUp(){
	for(unsigned int i=0;i<keyboardList.size();i++){
		keyboardList[i]->onKeyUp(KeyEvent(keyState));
	}
}

void System::onKeyPress(){
	for(unsigned int i=0;i<keyboardList.size();i++){
		keyboardList[i]->onKeyPress(KeyEvent(keyState));
	}
}

void System::onKeyDown(){
	for(unsigned int i=0;i<keyboardList.size();i++){
		keyboardList[i]->onKeyDown(KeyEvent(keyState));
	}
}

void System::mouseCheck(){
	int MouseX, MouseY,MouseWheel;
	int MouseState;
	GetMousePoint(&MouseX,&MouseY);
	MouseState=GetMouseInput();
	MouseWheel=GetMouseWheelRotVol();

	bool bMove=false;
	bool bPress=false;
	bool bRelease=false;
	bool bClicked=false;
	bool bWheeled=false;

	if(prevMouseX!=MouseX || prevMouseY!=MouseY){
		bMove=true;
	}
	if(!prevMouseState && MouseState){
		bPress=true;
	}
	if(prevMouseState && !MouseState){
		bRelease=true;
	}
	if(prevMouseState && MouseState){
		bClicked=true;
	}
	if(MouseWheel!=0){
		bWheeled=true;
	}

	
	if(bMove)
		onMouseMove(MouseState,MouseX,MouseY);
	if(bPress)
		onMousePress(MouseState,MouseX,MouseY);
	if(bRelease)
		onMouseRelease(MouseState,MouseX,MouseY);
	if(bClicked)
		onMouseClicked(MouseState,MouseX,MouseY);
	if(bWheeled)
		onMouseWheeled(MouseWheel);

	prevMouseX=MouseX;
	prevMouseY=MouseY;
	prevMouseState = MouseState;
}

void System::onMouseMove(int state,int x,int y){
	for(unsigned int i=0;i<mouseList.size();i++){
		mouseList[i]->mouseMoved(MouseEvent(state,x,y));
	}
}

void System::onMouseRelease(int state,int x,int y){
	for(unsigned int i=0;i<mouseList.size();i++){
		mouseList[i]->mouseReleased(MouseEvent(state,x,y));
	}
}

void System::onMousePress(int state,int x,int y){
	for(unsigned int i=0;i<mouseList.size();i++){
		mouseList[i]->mousePressed(MouseEvent(state,x,y));
	}
}

void System::onMouseClicked(int state,int x,int y){
	for(unsigned int i=0;i<mouseList.size();i++){
		mouseList[i]->mouseClicked(MouseEvent(state,x,y));
	}
}

void System::onMouseWheeled(int val){
	for(unsigned int i=0;i<mouseList.size();i++){
		mouseList[i]->mouseWheeled(MouseEvent(val));
	}
}

void System::CheckBorerControl(){
	while (!borerControl->isMouseQueueEmpty()){
		addMouseListener(borerControl->dequeueMouseListener());
	}
	while (!borerControl->isKeyboardQueueEmpty()){
		addKeyboardListener(borerControl->dequeueKeyboardListener());
	}
}