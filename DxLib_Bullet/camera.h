#pragma once
#include "worldObject.h"
#include "KeyboardListener.h"
#include "MouseListener.h"
#include <btBulletDynamicsCommon.h>
#include <DxLib.h>

class camera:public worldObject,public MouseListener
{
public:
	camera();
	void Draw();
	void Update();
	//
	//マウスボタンが押されている
	void mouseClicked(MouseEvent &);
	//マウスボタンが離された
	void mouseReleased(MouseEvent &);
	//マウスボタンが押された
	void mousePressed(MouseEvent &);
	//マウスが動いている
	void mouseMoved(MouseEvent &);
	void mouseWheeled(MouseEvent &);
	//
	~camera();
private:
	VECTOR pos;
	VECTOR tar;
	VECTOR axis[3];
	int pMouseX;
	int pMouseY;
	const enum AXIS {X,Y,Z};
private:
	void move(int,int);
	void rot(int,int);
	void getAxis();
};

