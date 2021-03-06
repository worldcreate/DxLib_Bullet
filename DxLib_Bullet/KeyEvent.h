#pragma once

class KeyEvent{
public:
	KeyEvent();
	KeyEvent(int []);

	//KEY_INPUT_***の状態を返す
	//KEY_UP|KEY_DOWN|KEY_PRESS
	int getKey(int );
	//KEY_INPUT_***が離されたか
	bool isKeyUp(int );
	//KEY_INPUT_***が押されたか
	bool isKeyDown(int );
	//KEY_INPUT_***が押されているか
	bool isKeyPress(int );
private:
	char keyState[256];
};