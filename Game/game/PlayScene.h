﻿#pragma once
#include "Scene.h"
#include "Grid.h"
#include "TileMap.h"
#include "ScoreBoard.h"
#include "GameOver.h"
#include "Enemy.h"

#include "GameObject.h"
#include "Simon.h"
class CPlayScene : public CScene
{
protected:
	Simon *simon; 
	Enemy* boss;

	CGameObject *gameObject;

	vector<LPGAMEOBJECT> objects;
	vector<LPGAMEOBJECT> coObjects;
	vector<LPGAMEOBJECT> listItems;
	vector<Enemy*> listEnemies;

	vector<int> arrTexturesID;
	vector<int> arrSpritesID;
	vector<int> arrAnimationsID;
	vector<int> arrAnimationSetsID;

	TileMap *tileMap = NULL;
	Grid *grid = NULL;
	CCamera *camera;

	ScoreBoard *scoreBoard;
	GameOver *gameOver;

	DWORD time;
	DWORD timeKillAll;

	/* xử lí chờ vẽ màn đen khi bắt đầu lại game*/
	bool isWaitResetGame;
	DWORD TimeWaitedResetGame;

	/* Xử lí gameover*/
	bool isGameOver;

	int stage;
	int defaultTimeGame;
	int remainTime;

	float mapWidth, mapHeight;

	bool CheckOutSideBoundingMap();

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
	CGameObject *GetGameObject() { return gameObject; }


	CPlayScene(int id, LPCWSTR filePath);

	virtual void Load();
	virtual void Unload();
	virtual void Update(DWORD dt);
	virtual void Render();

	int GetRemainTime() { return remainTime; }
	void SetDefaultTime(int time) { this->defaultTimeGame = time; }

	float GetMapWidth() { return mapWidth; }
	float GetMapHeight() { return mapHeight; }

	friend class CPlayScenceKeyHandler;
};

class CPlayScenceKeyHandler : public CScenceKeyHandler
{
public:
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	CPlayScenceKeyHandler(CScene *s) : CScenceKeyHandler(s){};
};
