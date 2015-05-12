#pragma once

#include "MouseEvent.h"

class MouseListener{
public:
	//�}�E�X�{�^����������Ă���
	virtual void mouseClicked(MouseEvent &)=0;
	//�}�E�X�{�^���������ꂽ
	virtual void mouseReleased(MouseEvent &)=0;
	//�}�E�X�{�^���������ꂽ
	virtual void mousePressed(MouseEvent &)=0;
	//�}�E�X�������Ă���
	virtual void mouseMoved(MouseEvent &)=0;
	//�}�E�X�̃z�C�[������]����
	virtual void mouseWheeled(MouseEvent &)=0;
};