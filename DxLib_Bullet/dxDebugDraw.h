#include <DxLib.h>  
  
#include <LinearMath/btIDebugDraw.h>  
  
class DxDebugDraw : public btIDebugDraw{  
private:  
    int m_debugMode;  
    //���W�ϊ�  
    inline VECTOR btVGet(const btVector3 &inv){return VGet(inv.getX(), inv.getY(), -inv.getZ());}  
	inline DWORD btGetColor(const btVector3 &color){return GetColor(int(color.getX()*255),int(color.getY()*255),int(color.getZ()*255));}
public:
    DxDebugDraw();  
    virtual void drawLine(const btVector3& from,const btVector3& to,const btVector3& fromColor, const btVector3& toColor);  
    virtual void drawLine(const btVector3& from,const btVector3& to,const btVector3& color);  
    virtual void drawSphere (const btVector3& p, btScalar radius, const btVector3& color);  
    virtual void drawBox (const btVector3& boxMin, const btVector3& boxMax, const btVector3& color, btScalar alpha);  
    virtual void drawTriangle(const btVector3& a,const btVector3& b,const btVector3& c,const btVector3& color,btScalar alpha);  
    virtual void drawContactPoint(const btVector3& PointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color);  
    virtual void reportErrorWarning(const char* warningString);  
    virtual void draw3dText(const btVector3& location,const char* textString);  
    virtual void setDebugMode(int debugMode);  
    virtual int getDebugMode() const { return m_debugMode;}  
};