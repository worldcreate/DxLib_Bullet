#include "BulletWorld.h"
#include "dxDebugDraw.h"
#include "abstractObject.h"

MATRIX BulletWorld::QuatToMatrix(btQuaternion &q){
	MATRIX mat = MGetIdent();

	//XŽ²
	mat.m[0][0] = 1.0f - 2.0f * q.y() * q.y() - 2.0f * q.z() * q.z();
	mat.m[0][1] = 2.0f * q.x() * q.y() + 2.0f * q.w() * q.z();
	mat.m[0][2] = 2.0f * q.x() * q.z() + 2.0f * q.w() * q.y();
	


	//YŽ²
	mat.m[1][0] = 2.0f * q.x() * q.y() - 2.0f * q.w() * q.z();
	mat.m[1][1] = 1.0f - 2.0f * q.x() * q.x() - 2.0f * q.z() * q.z();
	mat.m[1][2] = 2.0f * q.y() * q.z() + 2.0f * q.w() * q.x();



	//ZŽ²
	mat.m[2][0] = 2.0f * q.x() * q.z() - 2.0f * q.w() * q.y();
	mat.m[2][1] = 2.0f * q.y() * q.z() - 2.0f * q.w() * q.x();
	mat.m[2][2] = 1.0f - 2.0f * q.x() * q.x() - 2.0f * q.y() * q.y();

	/*
	mat.m[0][0]=-mat.m[0][0];
	mat.m[0][1]=-mat.m[0][1];
	mat.m[0][2]=-mat.m[0][2];
	mat.m[1][0]=-mat.m[1][0];
	mat.m[1][1]=-mat.m[1][1];
	mat.m[1][2]=-mat.m[1][2];
	mat.m[2][0]=-mat.m[2][0];
	mat.m[2][1]=-mat.m[2][1];
	mat.m[2][2]=-mat.m[2][2];
	*/

	return mat;
}

BulletWorld::BulletWorld(){
	collisionConfiguration=new btDefaultCollisionConfiguration();
	dispatcher=new btCollisionDispatcher(collisionConfiguration);

	overlappingPairCache=new btDbvtBroadphase();
	solver=new btSequentialImpulseConstraintSolver;
	dynamicsWorld=new btDiscreteDynamicsWorld(dispatcher,overlappingPairCache,solver,collisionConfiguration);
	
	dynamicsWorld->setGravity(btVector3(0,-10,0));
	

	//ground‚ð’Ç‰Á‚µ‚Ä‚¢‚é=>worldObject‚ðŒp³‚µ‚½ground Class‚ðì¬‚µ‚½‚Ù‚¤‚ª‚æ‚¢ //04/28
/*
	btCollisionShape* groundShape=new btBoxShape(btVector3(btScalar(500.),btScalar(5.),btScalar(500.)));

	collisionShapes.push_back(groundShape);	//collisionShape“o˜^

	btTransform groundTransform;
	groundTransform.setIdentity();
	groundTransform.setOrigin(btVector3(0,-5,0));

	{
		btScalar mass(0.);

		bool isDynamic = (mass != 0.f);
		
		btVector3 localInertia(0,0,0);
		if(isDynamic)
			groundShape->calculateLocalInertia(mass,localInertia);
		
		btDefaultMotionState* myMotionState=new btDefaultMotionState(groundTransform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,groundShape,localInertia);
		btRigidBody* body=new btRigidBody(rbInfo);
		body->setFriction(btScalar(0.7));
		dynamicsWorld->addRigidBody(body);	//rigidBody“o˜^

	}
*/
#ifdef _DEBUG
	DxDebugDraw *g_debugdraw=new DxDebugDraw();;
	dynamicsWorld->setDebugDrawer(g_debugdraw);
	dynamicsWorld->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
#endif
}

void BulletWorld::loop(){
	dynamicsWorld->stepSimulation(1.f/60);


	for(int j=dynamicsWorld->getNumCollisionObjects()-1;j>=0;j--){

		btCollisionObject* obj=dynamicsWorld->getCollisionObjectArray()[j];
		btRigidBody* body=btRigidBody::upcast(obj);
		if(body&&body->getMotionState()){
			btTransform trans;
			body->getMotionState()->getWorldTransform(trans);
#ifdef _DEBUG
			char temp[256];
			sprintf(temp,"%f,%f,%f",trans.getOrigin().getX(),trans.getOrigin().getY(),trans.getOrigin().getZ());
			DrawString(0,j*20,temp,GetColor(255,0,0));
#endif
		}
	}

	dynamicsWorld->debugDrawWorld();
}

void BulletWorld::addCollisionShape(btCollisionShape *col){
	collisionShapes.push_back(col);
}

void BulletWorld::addRigidBody(btRigidBody *body){
	dynamicsWorld->addRigidBody(body);
}

void BulletWorld::setObject(abstractObject* obj){
	if (obj->getCollisionShape()!=NULL)
		addCollisionShape(obj->getCollisionShape());
	if (obj->getRigidBody()!=NULL)
		addRigidBody(obj->getRigidBody());

}

void BulletWorld::deleteObject(abstractObject *obj){
	dynamicsWorld->removeRigidBody(obj->getRigidBody());
	collisionShapes.remove(obj->getCollisionShape());
}

void BulletWorld::removeRigidBody(btRigidBody *tarBody){
	for(int i=dynamicsWorld->getNumCollisionObjects()-1;i>=0;i--){
		btCollisionObject* obj=dynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body=btRigidBody::upcast(obj);
		if(tarBody==body){
			if(body&& body->getMotionState()){
				delete body->getMotionState();
			}
			dynamicsWorld->removeCollisionObject(obj);
			delete obj;
		}
	}

}

void BulletWorld::removeCollisionShape(btCollisionShape *tarShape){
	for(int j=0;j<collisionShapes.size();j++){
		btCollisionShape* shape=collisionShapes[j];
		if(shape==tarShape){
			collisionShapes[j]=0;
			delete shape;
		}
	}

}

VECTOR BulletWorld::rotateVec(VECTOR &vec, btQuaternion &quat){
	VECTOR dst;
	btQuaternion inv = quat.inverse();
	btQuaternion P = btQuaternion(vec.x, vec.y, vec.z, 0);
	btQuaternion PP = inv*P*quat;
	dst.x = PP.x();
	dst.y = PP.y();
	dst.z = PP.z();
	return dst;
};

BulletWorld::~BulletWorld(){
	for(int i=dynamicsWorld->getNumCollisionObjects()-1;i>=0;i--){
		btCollisionObject* obj=dynamicsWorld->getCollisionObjectArray()[i];
		btRigidBody* body=btRigidBody::upcast(obj);
		if(body&& body->getMotionState()){
			delete body->getMotionState();
		}
		dynamicsWorld->removeCollisionObject(obj);
		delete obj;
	}
	for(int j=0;j<collisionShapes.size();j++){
		btCollisionShape* shape=collisionShapes[j];
		collisionShapes[j]=0;
		delete shape;
	}
	delete dynamicsWorld;
	delete solver;
	delete overlappingPairCache;
	delete dispatcher;
	delete collisionConfiguration;
	collisionShapes.clear();

}