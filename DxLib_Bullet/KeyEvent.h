#pragma once

class KeyEvent{
public:
	KeyEvent();
	KeyEvent(int []);

	//KEY_INPUT_***�̏�Ԃ�Ԃ�
	//KEY_UP|KEY_DOWN|KEY_PRESS
	int getKey(int );
	//KEY_INPUT_***�������ꂽ��
	bool isKeyUp(int );
	//KEY_INPUT_***�������ꂽ��
	bool isKeyDown(int );
	//KEY_INPUT_***��������Ă��邩
	bool isKeyPress(int );
private:
	char keyState[256];
};