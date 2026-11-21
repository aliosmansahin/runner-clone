#pragma once

#include "Player.h"

class Game
{
public:
	Game();
	~Game();

public:
	void Run();
	void Update();
	void Draw();

private:
	int windowWidth = 800;
	int windowHeight = 600;

private:
	Player* player = nullptr;
};

