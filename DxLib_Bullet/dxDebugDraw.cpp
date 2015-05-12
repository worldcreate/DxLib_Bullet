#include "dxDebugDraw.h"

DxDebugDraw::DxDebugDraw():m_debugMode(0){

}

void DxDebugDraw::drawLine(const btVector3& from,const btVector3& to,const btVector3& fromColor,const btVector3& toColor){
	DrawLine3D(btVGet(from),btVGet(to),
		btGetColor(toColor));
}

void DxDebugDraw::drawLine(const btVector3& from,const btVector3& to,const btVector3& color){
	drawLine(from,to,color,color);
}

void DxDebugDraw::drawSphere(const btVector3&p,btScalar radius,const btVector3& color){
	DrawSphere3D(btVGet(p),radius,10,
		btGetColor(color)
		,0xFFFFFF,TRUE);
}

void DxDebugDraw::drawBox (const btVector3& boxMin, const btVector3& boxMax, const btVector3& color, btScalar alpha){
	DrawLine3D(VGet(boxMin[0], boxMin[1], boxMin[2]), VGet(boxMax[0], boxMin[1], boxMin[2]), btGetColor(color));
	DrawLine3D(VGet(boxMax[0], boxMin[1], boxMin[2]), VGet(boxMax[0], boxMax[1], boxMin[2]),  btGetColor(color));
	DrawLine3D(VGet(boxMax[0], boxMax[1], boxMin[2]), VGet(boxMin[0], boxMax[1], boxMin[2]),  btGetColor(color));
	DrawLine3D(VGet(boxMin[0], boxMax[1], boxMin[2]), VGet(boxMin[0], boxMin[1], boxMin[2]),  btGetColor(color));
	DrawLine3D(VGet(boxMin[0], boxMin[1], boxMin[2]), VGet(boxMin[0], boxMin[1], boxMax[2]),  btGetColor(color));
	DrawLine3D(VGet(boxMax[0], boxMin[1], boxMin[2]), VGet(boxMax[0], boxMin[1], boxMax[2]),  btGetColor(color));
	DrawLine3D(VGet(boxMax[0], boxMax[1], boxMin[2]), VGet(boxMax[0], boxMax[1], boxMax[2]),  btGetColor(color));
	DrawLine3D(VGet(boxMin[0], boxMax[1], boxMin[2]), VGet(boxMin[0], boxMax[1], boxMax[2]),  btGetColor(color));
	DrawLine3D(VGet(boxMin[0], boxMin[1], boxMax[2]), VGet(boxMax[0], boxMin[1], boxMax[2]),  btGetColor(color));
	DrawLine3D(VGet(boxMax[0], boxMin[1], boxMax[2]), VGet(boxMax[0], boxMax[1], boxMax[2]),  btGetColor(color));
	DrawLine3D(VGet(boxMax[0], boxMax[1], boxMax[2]), VGet(boxMin[0], boxMax[1], boxMax[2]),  btGetColor(color));
	DrawLine3D(VGet(boxMin[0], boxMax[1], boxMax[2]), VGet(boxMin[0], boxMin[1], boxMax[2]),  btGetColor(color));

}

void DxDebugDraw::drawTriangle(const btVector3& a,const btVector3& b,const btVector3& c,const btVector3& color,btScalar alpha){

	DrawLine3D(btVGet(a),btVGet(b),btGetColor(color));
	DrawLine3D(btVGet(b),btVGet(c),btGetColor(color));
	DrawLine3D(btVGet(c),btVGet(a),btGetColor(color));
}

void DxDebugDraw::drawContactPoint(const btVector3& PointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color){
	btVector3 to=PointOnB+normalOnB*1;//distance;
	const btVector3&from = PointOnB;
	DrawLine3D(btVGet(from),btVGet(to),btGetColor(color));
}

void DxDebugDraw::reportErrorWarning(const char* warningString){
	DrawString(0,0,warningString,GetColor(255,0,0));
}

void DxDebugDraw::draw3dText(const btVector3& location,const char* textString){

}

void DxDebugDraw::setDebugMode(int debugMode){
	m_debugMode=debugMode;
}