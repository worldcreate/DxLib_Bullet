#include "StageFactory.h"
#include "StageCreater.h"

StageFactory::StageFactory(void)
{
}

StageFactory::StageFactory(std::string name){
	if(name.compare("stage1")==0){
		StageCreater sc;
		stage=sc.getStage();
	}
}

AbstractWorld* StageFactory::getStage(){
	return stage;
}

StageFactory::~StageFactory(void)
{
}
