#include "StageCreater.h"
#include "Stage.h"
#include "BulletWorld.h"
#include "Ball.h"
#include "Ground.h"
#include "camera.h"
#include "BorerControl.h"

StageCreater::StageCreater(void)
{
	Stage *s=new Stage(new BulletWorld());
	stage=s;
	
	camera *c;
	s->setObject(c=new camera());	//‰ö‚µ‚¢
	BorerControl *bc=BorerControl::getInstance();
	bc->enqueueMouseListener(c);
	
	s->setObject(new Ball());
	s->setObject(new Ground());
	
	Ground *g;
	s->setObject(g = new Ground());
	g->setPos(btVector3(-5, -30, 0));
	g->setRot(btScalar(-15));

	s->setObject(g = new Ground());
	g->setSize(btVector3(5, 1,5));
	g->setPos(btVector3(-35, -10, 0));
	g->setRot(btScalar(90));

	s->setObject(g = new Ground());
	g->setPos(btVector3(40, -80, 0));
	g->setRot(btScalar(0));

	Ball *b;
	s->setObject(b = new Ball());
	b->setPos(btVector3(58, -75, 0));
	
}


StageCreater::~StageCreater(void)
{
}