#pragma once
#include "abstractScene.h"
#include "AbstractWorld.h"
#include <queue>

class GameScene:public abstractScene
{
public:
	GameScene();
	void scene(SceneContext*);
	static void instantiate(abstractObject *);
	static void destroy(abstractObject *);
	
	~GameScene();
private:
	void checkQueue();
	AbstractWorld *nowWorld;
	static std::queue<abstractObject*> instanceQueue;
	static std::queue<abstractObject*> destroyQueue;
};