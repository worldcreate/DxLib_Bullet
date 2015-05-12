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
	//������Ă�
	void onKeyPress();
	//�����ꂽ
	void onKeyUp();
	//�����ꂽ
	void onKeyDown();
	void mouseCheck();
	//�����ꂽ
	void onMousePress(int,int,int);
	//�����Ă�
	void onMouseMove(int,int,int);
	//�����ꂽ
	void onMouseRelease(int,int,int);
	//������Ă���
	void onMouseClicked(int,int,int);
	//�z�C�[���̉�]
	void onMouseWheeled(int );
	//BorerControl�̃`�F�b�N
	void CheckBorerControl();
};

