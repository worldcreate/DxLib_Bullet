#include "Stage.h"
#include "Character.h"
#include "BulletWorld.h"

Stage::Stage(BulletWorld* obj){
	setBulletWorld(obj);
	stageHandle = MV1LoadModel("model\\ネオＵＫシティ.x");

	bWorld->setObject(new stageObject(getShape(stageHandle)));
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

btBvhTriangleMeshShape* Stage::getShape(int modelHandle){
	//参照用メッシュの構築
	triangleMesh = new btTriangleMesh;
	MV1SetupReferenceMesh(stageHandle, -1, TRUE);
	MV1_REF_POLYGONLIST refMesh = MV1GetReferenceMesh(stageHandle, -1, TRUE);

	for (int i = 0; i < refMesh.PolygonNum; i++){
		btVector3 vertex[3];
		for (int j = 0; j < 3; j++){
			vertex[j] = btVector3(
				refMesh.Vertexs[refMesh.Polygons[i].VIndex[j]].Position.x,
				refMesh.Vertexs[refMesh.Polygons[i].VIndex[j]].Position.y,
				-(refMesh.Vertexs[refMesh.Polygons[i].VIndex[j]].Position.z)
				);
		}
		triangleMesh->addTriangle(vertex[0], vertex[1], vertex[2], false);
	}
	return new btBvhTriangleMeshShape(triangleMesh, true, true);
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
