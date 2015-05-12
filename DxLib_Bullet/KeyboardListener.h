#pragma once
#include "KeyEvent.h"

class KeyboardListener{
public:
	//�L�[�������ꂽ��
	virtual void onKeyDown(KeyEvent &)=0;
	//�L�[�������ꂽ��
	virtual void onKeyUp(KeyEvent &)=0;
	//�L�[��������Ă��邩
	virtual void onKeyPress(KeyEvent &)=0;
	//�L�[�̏��
	enum keystate{
		KEY_NONE,KEY_DOWN,KEY_UP,KEY_PRESS
	};
};
