#pragma once
#include "Enemy.h"
class Ghost : public Enemy
{
	float startX, startY;
	float distanceAttack;
	int ny;

public:
	Ghost(float startX, float startY, int hp, int damage, float distanceAttack, int point);
	~Ghost();

	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObject = NULL);
	virtual void Render();

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void SetState(int state);
};
