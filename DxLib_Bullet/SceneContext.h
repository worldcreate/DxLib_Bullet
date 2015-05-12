#pragma once
#include "abstractScene.h"

class SceneContext
{
public:
	SceneContext();
	void setScene(abstractScene *newScene);
	void scene();
	~SceneContext();
private:
	abstractScene *myScene;
};