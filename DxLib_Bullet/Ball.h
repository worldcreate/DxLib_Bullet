#pragma once
#include "Character.h"

class Ball:public Character
{
public:
	Ball();
	void Draw();
	void Update();
	~Ball();
private:
	int radius;

	int cnt;
};

