#pragma once

#include "IDespose.h"

class SceneContext;

class abstractScene:public IDespose{
public:
	virtual void scene(SceneContext*)=0;
	void* Despose(){
		return this;
	}
};