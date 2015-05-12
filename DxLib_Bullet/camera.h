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
	//�}�E�X�{�^����������Ă���
	void mouseClicked(MouseEvent &);
	//�}�E�X�{�^���������ꂽ
	void mouseReleased(MouseEvent &);
	//�}�E�X�{�^���������ꂽ
	void mousePressed(MouseEvent &);
	//�}�E�X�������Ă���
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

