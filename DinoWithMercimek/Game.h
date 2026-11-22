#pragma once

#include "Player.h"
#include "Enemy.h"

#include <deque>

enum class GameStage {
	MENU,
	PLAYING,
	GAMEOVER
};

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
	void AddEnemy();
	void HandleEnemySpawn();
	void HandleEnemyDespawn();
	void HandleCollisions();
	void StartGame();
	void GameOver();

private:
	int windowWidth = 800;
	int windowHeight = 600;

private:
	int groundSize = 20;
	int groundY;
	int enemyStartX;

private:
	double lastAddEnemyTime;
	double nextEnemyCooldown;

private:
	Player* player = nullptr;
	std::deque<Enemy*> enemies;
	GameStage stage;
};

