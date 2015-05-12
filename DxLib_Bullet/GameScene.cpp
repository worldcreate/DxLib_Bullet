#include <DxLib.h>
#include "GameScene.h"
#include "StageFactory.h"

std::queue<abstractObject*> GameScene::instanceQueue;
std::queue<abstractObject*> GameScene::destroyQueue;

GameScene::GameScene()
{
	StageFactory sf("stage1");
	nowWorld=sf.getStage();
}

void GameScene::instantiate(abstractObject *obj){
	instanceQueue.push(obj);
}

void GameScene::destroy(abstractObject *obj){
	destroyQueue.push(obj);
}

void GameScene::checkQueue(){
	if(!instanceQueue.empty()){
		nowWorld->setObject(instanceQueue.front());
		instanceQueue.pop();
	}
	if(!destroyQueue.empty()){
		abstractObject *obj=destroyQueue.front();
		destroyQueue.pop();
		nowWorld->deleteObject(obj);
		delete(obj);
	}
}

void GameScene::scene(SceneContext *sContext){
	checkQueue();
	nowWorld->Draw();
	nowWorld->Update();
}

GameScene::~GameScene()
{
}