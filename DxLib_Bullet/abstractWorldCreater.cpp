#include "abstractWorldCreater.h"
#include "StageCreater.h"

abstractWorldCreater::abstractWorldCreater()
{

}

AbstractWorld* abstractWorldCreater::getStage(){
	return stage;
}

abstractWorldCreater::~abstractWorldCreater()
{
}
