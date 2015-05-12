#pragma once
#include "abstractScene.h"

class StartScene:public abstractScene
{
public:
	StartScene();
	~StartScene();
	void scene(SceneContext*);
};

