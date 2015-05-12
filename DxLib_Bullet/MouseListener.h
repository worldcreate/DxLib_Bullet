#pragma once

#include "MouseEvent.h"

class MouseListener{
public:
	//マウスボタンが押されている
	virtual void mouseClicked(MouseEvent &)=0;
	//マウスボタンが離された
	virtual void mouseReleased(MouseEvent &)=0;
	//マウスボタンが押された
	virtual void mousePressed(MouseEvent &)=0;
	//マウスが動いている
	virtual void mouseMoved(MouseEvent &)=0;
	//マウスのホイールが回転した
	virtual void mouseWheeled(MouseEvent &)=0;
};