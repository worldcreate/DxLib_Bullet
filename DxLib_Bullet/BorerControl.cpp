#include "BorerControl.h"

BorerControl*  BorerControl::obj = NULL;

BorerControl::BorerControl()
{
}

void BorerControl::enqueueMouseListener(MouseListener *obj){
	mouseQueue.push(obj);
}

MouseListener* BorerControl::dequeueMouseListener(){
	MouseListener *obj;
	obj=mouseQueue.front();
	mouseQueue.pop();
	return obj;
}

bool BorerControl::isMouseQueueEmpty(){
	return mouseQueue.empty();
}

void BorerControl::enqueueKeyboardListener(KeyboardListener *obj){
	keyboardQueue.push(obj);
}

KeyboardListener* BorerControl::dequeueKeyboardListener(){
	KeyboardListener *obj;
	obj = keyboardQueue.front();
	keyboardQueue.pop();
	return obj;
}

bool BorerControl::isKeyboardQueueEmpty(){
	return keyboardQueue.empty();
}

BorerControl* BorerControl::getInstance(){
	if (obj == NULL)
		obj = new BorerControl();
	return obj;
}

BorerControl::~BorerControl()
{
}
