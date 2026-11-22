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

	stage = GameStage::MENU;
}

Game::~Game()
{
	if(player)
		delete player;

	for (size_t i = 0; i < enemies.size(); ++i) {
		delete enemies[i];
	}

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
	if (stage == GameStage::MENU || stage == GameStage::GAMEOVER) {
		if (IsKeyPressed(KEY_SPACE)) {
			StartGame();
		}
	}
	else {
		HandleEnemySpawn();
		HandleEnemyDespawn();

		player->Update();

		for (auto& enemy : enemies) {
			enemy->Update();
		}

		HandleCollisions();
	}
}

void Game::Draw()
{
	player->Draw();

	for (auto& enemy : enemies) {
		enemy->Draw();
	}

	if (stage == GameStage::GAMEOVER) {
		DrawText("Game Over", 0, 0, 50, BLUE);
	}
	else if (stage == GameStage::MENU) {
		DrawText("Press Space to Play", 0, 0, 30, GREEN);
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

			GameOver();
		}
	}
}

void Game::StartGame()
{
	/* Reset Player */

	if (player)
		delete player;

	player = new Player(groundY);

	/* Reset enemies */

	for (size_t i = 0; i < enemies.size(); ++i) {
		delete enemies[i];
	}

	enemies.clear();

	lastAddEnemyTime = GetTime();
	nextEnemyCooldown = 0.0;

	stage = GameStage::PLAYING;
}

void Game::GameOver()
{
	stage = GameStage::GAMEOVER;
}
