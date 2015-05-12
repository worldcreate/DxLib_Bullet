#pragma once
#include <queue>
#include "MouseListener.h"
#include "KeyboardListener.h"
#include "IDespose.h"

using namespace std;

class BorerControl
{
public:
	//MouseListenerに加えたいものをキューに入れる
	void enqueueMouseListener(MouseListener *);
	//キューからMouseListenerに加えるものを取り出す
	MouseListener* dequeueMouseListener();
	//MouseListenerQueueが空か
	bool isMouseQueueEmpty();
	//KeyboardListenerに加えたいものをキューに入れる
	void enqueueKeyboardListener(KeyboardListener *);
	//キューからKeyboardListenerに加えるものを取り出す
	KeyboardListener* dequeueKeyboardListener();
	//KeyboardListenerQueueが空か
	bool isKeyboardQueueEmpty();
	//BorerControlのインスタンスを取得する
	static BorerControl* getInstance();
	~BorerControl();
private:
	BorerControl();
	queue<MouseListener *> mouseQueue;
	queue<KeyboardListener *> keyboardQueue;
	static BorerControl *obj;
};

