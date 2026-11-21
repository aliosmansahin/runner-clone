#pragma once

#include "Enemy.h"

class Cactus: public Enemy
{
public:
	Cactus(float startX, float groundY);
	~Cactus();

public:
	void Draw() override final;

private:
};

