#include "WorldCreater.h"
#include "StageCreater.h"

WorldCreater::WorldCreater()
{

}

AbstractWorld* WorldCreater::getStage(){
	return stage;
}

WorldCreater::~WorldCreater()
{
}
