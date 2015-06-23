#include "Character.h"
#include "DxLib.h"
#include "BulletWorld.h"

Character::Character(){
	m_playerHandle=MV1LoadModel("model\\char\\miku\\LatŽ®ƒ~ƒNVer2.31_Sailor“~•ž.pmd");
	MV1SetScale(m_playerHandle, VGet(0.2, 0.2, 0.2));
	m_animeIndex = MV1AttachAnim(m_playerHandle, 1, -1, FALSE);
	m_animeTotalTime = MV1GetAttachAnimTotalTime(m_playerHandle, m_animeIndex);
	m_animePlayTime = 0;
}

void Character::Draw(){
	MV1DrawModel(m_playerHandle);
}

void Character::Update(){
	MV1SetPosition(m_playerHandle,VGet(0,0,0));
	MV1SetAttachAnimTime(m_playerHandle, m_animeIndex, m_animePlayTime);
	if (m_animePlayTime <= m_animeTotalTime){
		m_animePlayTime += 0.2;
	}
}


Character::~Character(void)
{
	MV1DeleteModel(m_playerHandle);
	delete m_triangleMesh;
}
