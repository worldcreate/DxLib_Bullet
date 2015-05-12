#pragma once

class MouseEvent{
public:
	MouseEvent(int ,int ,int );
	MouseEvent(int);
	//�}�E�X�̍��W���擾
	void getMousePos(int* ,int *);
	//�}�E�X�{�^���̏�Ԃ��擾
	//MOUSE_INPUT_***
	//LEFT|RIGHT|MIDDLE
	bool getMouseState(int );
	int getMouseWheelVal();
	~MouseEvent();
private:
	int mousex,mousey;
	int state;
	int wheelVal;
};