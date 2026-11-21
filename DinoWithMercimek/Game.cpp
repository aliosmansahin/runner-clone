#include "Game.h"

#include <raylib.h>

Game::Game()
{
	InitWindow(windowWidth, windowHeight, "Dino with Mercimek");
}

Game::~Game()
{
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
}

void Game::Draw()
{
}
