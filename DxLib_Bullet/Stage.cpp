#include "Stage.h"
#include "Character.h"
#include "BulletWorld.h"

Stage::Stage(BulletWorld* obj){
	setBulletWorld(obj);
	stageHandle = MV1LoadModel("model\\stage\\ネオＵＫシティ.x");

	bWorld->setObject(new stageObject(BulletWorld::converToBtBvhTriangleMeshShapeFromDxModel(stageHandle,triangleMesh)));
}

void Stage::Draw(){
	for (int i = 0; i < worldObjectList.size(); i++){
		worldObjectList[i]->Draw();
	}
	MV1DrawModel(stageHandle);
}

void Stage::Update(){
	for (int i = 0; i < worldObjectList.size(); i++){
		worldObjectList[i]->Update();
	}
	bWorld->loop();
}

Stage::~Stage(void)
{
	for (int i = 0; i < worldObjectList.size(); i++){
		delete(worldObjectList[i]);
	}
	delete bWorld;
	MV1DeleteModel(stageHandle);
	delete triangleMesh;
}
