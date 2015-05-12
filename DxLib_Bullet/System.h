#pragma once
#include <vector>
#include "KeyboardListener.h"
#include "MouseListener.h"
#include "BorerControl.h"

using namespace std;

class System
{
public:
	System(void);
	~System(void);
	void addKeyboardListener(KeyboardListener *);
	void addMouseListener(MouseListener *);
	void loop();

private:
	vector<KeyboardListener*> keyboardList;
	vector<MouseListener*> mouseList;
	char prevKey[256];
	int keyState[256];
	int prevMouseX;
	int prevMouseY;
	int prevMouseState;
	BorerControl *borerControl;
private:
	void keyCheck();
	//押されてる
	void onKeyPress();
	//離された
	void onKeyUp();
	//押された
	void onKeyDown();
	void mouseCheck();
	//押された
	void onMousePress(int,int,int);
	//動いてる
	void onMouseMove(int,int,int);
	//離された
	void onMouseRelease(int,int,int);
	//押されている
	void onMouseClicked(int,int,int);
	//ホイールの回転
	void onMouseWheeled(int );
	//BorerControlのチェック
	void CheckBorerControl();
};

