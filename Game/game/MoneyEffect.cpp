#include "MoneyEffect.h"

MoneyEffect::MoneyEffect(int _moneyType)
{
	moneyType = _moneyType;

	AddAnimation(moneyType);
	timeDelay = 0.0f;
	isEnable = false;
}

MoneyEffect::~MoneyEffect()
{
}

void MoneyEffect::Update(DWORD dt)
{
	if (isEnable)
	{
		timeDelay += dt;
		if (timeDelay > 450)
		{
			timeDelay = 0.0f;
			isEnable = false;
		}
	}
}

void MoneyEffect::Render()
{
	if (isEnable)
		animations[0]->Render(x, y, 255, rand() % 256, rand() % 256, rand() % 256);
}

void MoneyEffect::Enable()
{
	isEnable = true;
	timeDelay = 0;
}



