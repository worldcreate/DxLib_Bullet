#include "KeyEvent.h"
#include "KeyboardListener.h"

KeyEvent::KeyEvent(){

}

KeyEvent::KeyEvent(int key[]){
	for(int i=0;i<256;i++){
		keyState[i]=key[i];
	}
}


int KeyEvent::getKey(int i){
	return keyState[i];
}


bool KeyEvent::isKeyUp(int i){
	if(keyState[i]==KeyboardListener::keystate::KEY_UP){
		return true;
	}
	return false;
}

bool KeyEvent::isKeyDown(int i){
	if(keyState[i]==KeyboardListener::keystate::KEY_DOWN){
		return true;
	}
	return false;
}

bool KeyEvent::isKeyPress(int i){
	if(keyState[i]==KeyboardListener::keystate::KEY_PRESS){
		return true;
	}
	return false;
}