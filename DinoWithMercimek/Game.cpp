#include "Game.h"

#include <raylib.h>

Game::Game()
{
	InitWindow(windowWidth, windowHeight, "Dino with Mercimek");

	player = new Player();
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
