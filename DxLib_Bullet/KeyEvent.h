#pragma once

class KeyEvent{
public:
	KeyEvent();
	KeyEvent(int []);

	//KEY_INPUT_***‚Ìó‘Ô‚ğ•Ô‚·
	//KEY_UP|KEY_DOWN|KEY_PRESS
	int getKey(int );
	//KEY_INPUT_***‚ª—£‚³‚ê‚½‚©
	bool isKeyUp(int );
	//KEY_INPUT_***‚ª‰Ÿ‚³‚ê‚½‚©
	bool isKeyDown(int );
	//KEY_INPUT_***‚ª‰Ÿ‚³‚ê‚Ä‚¢‚é‚©
	bool isKeyPress(int );
private:
	char keyState[256];
};