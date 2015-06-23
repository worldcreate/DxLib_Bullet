#pragma once
#include "abstractObject.h"
class Character:public abstractObject
{
public:
	Character();
	void Draw();
	void Update();
	~Character(void);

private:
	int m_playerHandle;
	btTriangleMesh* m_triangleMesh;
	int m_animeIndex;
	float m_animeTotalTime;
	float m_animePlayTime;
};

