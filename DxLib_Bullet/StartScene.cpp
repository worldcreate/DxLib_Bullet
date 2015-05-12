#include "StartScene.h"
#include "GameScene.h"
#include "SceneContext.h"

StartScene::StartScene()
{
}

void StartScene::scene(SceneContext* sceneContext){
	sceneContext->setScene(new GameScene());
}

StartScene::~StartScene()
{
}

