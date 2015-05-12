#include "SceneContext.h"
#include "StartScene.h"

SceneContext::SceneContext()
{
	myScene = nullptr;
	setScene(new StartScene());
}

void SceneContext::setScene(abstractScene *newScene){
	if (myScene != nullptr)
		delete(myScene->Despose());
	this->myScene = newScene;
}

void SceneContext::scene(){
	this->myScene->scene(this);
}

SceneContext::~SceneContext()
{
	delete(myScene->Despose());
}
