#pragma once
#include "KeyEvent.h"

class KeyboardListener{
public:
	//キーが押されたか
	virtual void onKeyDown(KeyEvent &)=0;
	//キーが離されたか
	virtual void onKeyUp(KeyEvent &)=0;
	//キーが押されているか
	virtual void onKeyPress(KeyEvent &)=0;
	//キーの状態
	enum keystate{
		KEY_NONE,KEY_DOWN,KEY_UP,KEY_PRESS
	};
};
