﻿#pragma once
#include "GameObject.h"
#include "BrokenBrickEffect.h"

class Brick : public CGameObject
{
	BrokenBrickEffect* listEffect[4];

public:
	Brick();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render();
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b);
	void SetState(int state);
};

