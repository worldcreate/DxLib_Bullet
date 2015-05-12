#pragma once

class MouseEvent{
public:
	MouseEvent(int ,int ,int );
	MouseEvent(int);
	//マウスの座標を取得
	void getMousePos(int* ,int *);
	//マウスボタンの状態を取得
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