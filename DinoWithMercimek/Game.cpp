#include "Game.h"

#include <raylib.h>

#include "Cactus.h"

Game::Game()
{
	InitWindow(windowWidth, windowHeight, "Dino with Mercimek");

	groundY = windowHeight - groundSize;
	enemyStartX = windowWidth + 100;

	player = new Player(groundY);

	AddEnemy();
}

Game::~Game()
{
	if(player)
		delete player;

	CloseWindow();
}

void Game::Run()
{
	while (!WindowShouldClose()) {
		/* Update */
		Update();
		
		/* Draw */
		BeginDrawing();
		{
			ClearBackground(BLACK);
			Draw();
		}
		EndDrawing();
	}
}

void Game::Update()
{
	player->Update();

	for (auto& enemy : enemies) {
		enemy->Update();
	}
}

void Game::Draw()
{
	player->Draw();

	for (auto& enemy : enemies) {
		enemy->Draw();
	}
}

void Game::AddEnemy()
{
	Enemy* enemy = new Cactus(enemyStartX, groundY);

	enemies.push_back(enemy);
}
