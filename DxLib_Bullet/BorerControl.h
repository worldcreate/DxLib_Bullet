#pragma once
#include <queue>
#include "MouseListener.h"
#include "KeyboardListener.h"
#include "IDespose.h"

using namespace std;

class BorerControl
{
public:
	//MouseListener�ɉ����������̂��L���[�ɓ����
	void enqueueMouseListener(MouseListener *);
	//�L���[����MouseListener�ɉ�������̂����o��
	MouseListener* dequeueMouseListener();
	//MouseListenerQueue����
	bool isMouseQueueEmpty();
	//KeyboardListener�ɉ����������̂��L���[�ɓ����
	void enqueueKeyboardListener(KeyboardListener *);
	//�L���[����KeyboardListener�ɉ�������̂����o��
	KeyboardListener* dequeueKeyboardListener();
	//KeyboardListenerQueue����
	bool isKeyboardQueueEmpty();
	//BorerControl�̃C���X�^���X���擾����
	static BorerControl* getInstance();
	~BorerControl();
private:
	BorerControl();
	queue<MouseListener *> mouseQueue;
	queue<KeyboardListener *> keyboardQueue;
	static BorerControl *obj;
};

