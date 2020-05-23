﻿#pragma once
#include "Scene.h"
#include "Grid.h"
#include "TileMap.h"
#include "ScoreBoard.h"

#include "Simon.h"
class CPlayScene : public CScene
{
protected:
	Simon *simon; // A play scene has to have player, right?

	vector<LPGAMEOBJECT> objects;
	vector<LPGAMEOBJECT> coObjects;
	vector<LPGAMEOBJECT> listItems;

	vector<int> arrTexturesID;
	vector<int> arrSpritesID;
	vector<int> arrAnimationsID;
	vector<int> arrAnimationSetsID;

	TileMap *tileMap = NULL;
	Grid *grid = NULL;
	ScoreBoard *scoreBoard;
	CCamera *camera;

	DWORD time;

	int stage;
	int defaultTimeGame;
	int remainTime;

	float mapWidth, mapHeight;
	float simonX_backup, simonY_backup;

	void _ParseSection_SETTINGS(string line);
	void _ParseSection_TEXTURES(string line);
	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);
	void _ParseSection_ANIMATION_SETS(string line);
	void _ParseSection_OBJECTS(string line);
	void _ParseSection_TILEMAP(string line);
	void _ParseSection_GRID(string line);
	void _Load_OBJECTS(string line);

public:
	Simon *GetSimon() { return simon; }

	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Unload();
	virtual void Update(DWORD dt);
	virtual void Render();

	friend class CPlayScenceKeyHandler;

	float GetMapWidth() { return mapWidth; }
	float GetMapHeight() { return mapHeight; }
};

class CPlayScenceKeyHandler : public CScenceKeyHandler
{
public:
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	CPlayScenceKeyHandler(CScene *s) : CScenceKeyHandler(s){};
};
