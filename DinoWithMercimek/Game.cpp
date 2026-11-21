#include "Game.h"

#include <raylib.h>

#include <stdio.h>
#include <time.h>
#include <iostream>

#include "Cactus.h"

Game::Game()
{
	InitWindow(windowWidth, windowHeight, "Dino with Mercimek");

	groundY = windowHeight - groundSize;
	enemyStartX = windowWidth + 100;

	player = new Player(groundY);

	srand(time(nullptr));

	lastAddEnemyTime = GetTime();
	nextEnemyCooldown = 0.0;
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
	HandleEnemySpawn();
	HandleEnemyDespawn();

	player->Update();

	for (auto& enemy : enemies) {
		enemy->Update();
	}

	HandleCollisions();
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

void Game::HandleEnemySpawn()
{
	double currentTime = GetTime();

	double deltaTime = currentTime - lastAddEnemyTime;

	if (deltaTime <= nextEnemyCooldown) return;

	AddEnemy();

	/* Calculate next enemy cooldown */
	nextEnemyCooldown = static_cast<double>(rand() % 3 + 1);

	lastAddEnemyTime = currentTime;
}

void Game::HandleEnemyDespawn()
{
	Enemy* enemy = enemies.front();

	if (enemy->ShouldDespawn()) {
		delete enemy;
		enemies.pop_front();
	}
}

void Game::HandleCollisions()
{
	for (const auto& enemy : enemies) {
		if (player->GetMax().x >= enemy->GetMin().x &&
			player->GetMin().x <= enemy->GetMax().x &&
			player->GetMax().y >= enemy->GetMin().y &&
			player->GetMin().y <= enemy->GetMax().y) {

			/* Game over */

			std::cout << "Collision" << std::endl;
		}
	}
}
