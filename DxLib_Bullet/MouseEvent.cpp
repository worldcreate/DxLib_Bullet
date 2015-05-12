#include "MouseEvent.h"

MouseEvent::MouseEvent(int val):wheelVal(val){

}

MouseEvent::MouseEvent(int state,int x,int y){
	this->state=state;
	this->mousex=x;
	this->mousey=y;
}

void MouseEvent::getMousePos(int *x,int *y){
	*x=mousex;
	*y=mousey;
}

bool MouseEvent::getMouseState(int which){
	return (bool)(state&which);
}

int MouseEvent::getMouseWheelVal(){
	return wheelVal;
}

MouseEvent::~MouseEvent(){

}