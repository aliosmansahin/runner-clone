#include "Game.h"

#include <raylib.h>

Game::Game()
{
	InitWindow(windowWidth, windowHeight, "Dino with Mercimek");

	int groundSize = 20;
	int playerMaxY = windowHeight - groundSize;

	player = new Player(playerMaxY);
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
}

void Game::Draw()
{
	player->Draw();
}
