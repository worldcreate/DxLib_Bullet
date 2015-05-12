#include "AbstractWorld.h"
#include "BulletWorld.h"

AbstractWorld::AbstractWorld(void)
{
}

void AbstractWorld::setBulletWorld(BulletWorld *obj){
	bWorld=obj;
}

void AbstractWorld::setObject(abstractObject *obj){
	worldObjectList.push_back(obj);
	bWorld->setObject(obj);
}

void AbstractWorld::deleteObject(abstractObject *obj){
	bWorld->deleteObject(obj);
	std::vector<abstractObject*>::iterator it = worldObjectList.begin();

	for (; it != worldObjectList.end(); it++){
		if ((*it) == obj){
			worldObjectList.erase(it);
			break;
		}
	}
}

AbstractWorld::~AbstractWorld(void)
{
}
