#include "VampireBat.h"
#include "Simon.h"
#include "Define.h"
#include "Utils.h"

VampireBat::VampireBat(float startX, float startY, int hp, int damage, float distanceAttack, int point)
{
	this->startX = startX;
	this->startY = startY;
	this->xRespawn = startX;
	this->yRespawn = startY;
	this->hp = hp;
	this->hpC = hp;
	this->damage = damage;
	this->distanceAttack = distanceAttack;
	this->point = point;

	isEnable = true;

	SetState(VAMPIRE_BAT_STATE_IDLE);

	Enemy::Enemy();
}

VampireBat::~VampireBat()
{
}

void VampireBat::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
	if (isDeadth && isEnable) {
		left = 0;
		top = 0;
		right = left + 0;
		bottom = top + 0;
	}
	else {
		left = x;
		right = left + VAMPIRE_BAT_BBOX_WIDTH;
		top = y;
		bottom = top + VAMPIRE_BAT_BBOX_HEIGHT;
	}
}

void VampireBat::Update(DWORD dt, vector<LPGAMEOBJECT>* coObject)
{
	Enemy::Update(dt, coObject);

	if (Enemy::isStop)
	{
		return;
	}

	if (!isDeadth && isEnable) {
		x += dx;
		y += dy;

		float simonX, simonY;

		Simon::GetInstance()->GetPosition(simonX, simonY);

		if (state == VAMPIRE_BAT_STATE_FLYING)
		{
			if (nx > 0) {
				vx = VAMPIRE_BAT_FLYING_SPEED_X;
			}
			else {
				vx = -VAMPIRE_BAT_FLYING_SPEED_X;
			}

			x += dx;
			y += dy;
			if (this->y - simonY >= SIMON_BBOX_HEIGHT / 2 - 5)
			{
				vy = 0;
				y = simonY + SIMON_BBOX_HEIGHT / 2 - 5;
			}
		}
		else if (state == VAMPIRE_BAT_STATE_IDLE) {
			if (abs(this->x - simonX) < this->distanceAttack && abs(this->y - simonY) < SIMON_BBOX_HEIGHT) {
				nx = this->x >= simonX ? -1 : 1;
				SetState(VAMPIRE_BAT_STATE_FLYING);
			}
		}
	}
}

void VampireBat::Render()
{
	if (!isDeadth && isEnable) {
		int posX = x, posY = y;
		int ani = 0;
		switch (state)
		{
		case VAMPIRE_BAT_STATE_IDLE:
		{
			ani = VAMPIRE_BAT_ANI_IDLE;
		}
		break;
		case VAMPIRE_BAT_STATE_FLYING:
		{
			if (nx > 0) {
				ani = VAMPIRE_BAT_ANI_BLACK_FLYING_RIGHT;
			}
			else {
				ani = VAMPIRE_BAT_ANI_BLACK_FLYING_LEFT;
			}
		}
		break;
		default:
			break;
		}

		if (Enemy::isStop)
		{
			ani = VAMPIRE_BAT_ANI_IDLE;
		}

		animation_set->at(ani)->Render(posX, posY);
		RenderBoundingBox();
	}

	Enemy::Render();
}


void VampireBat::SetState(int state)
{
	Enemy::SetState(state);
	switch (state)
	{
	case VAMPIRE_BAT_STATE_IDLE:
		break;
	case VAMPIRE_BAT_STATE_FLYING:
		if (nx > 0) {
			vx = VAMPIRE_BAT_FLYING_SPEED_X;
		}
		else {
			vx = -VAMPIRE_BAT_FLYING_SPEED_X;
		}

		vy = VAMPIRE_BAT_FLYING_SPEED_Y;
		break;
	}
}
