#include "App.h"

namespace app
{
	static int screenWidth = 800;
	static int screenHeight = 600;

	bool exit = false;
	bool onePlayer = true;
	bool winner = true;

	SCREENS currentScreen = MENU;

	static void InitGame()
	{
		SetExitKey(0);
		InitWindow(screenWidth, screenHeight, "FlappyBirds");
		gameplay::InitValues();
		multiplayer::InitValues();
		InitMenu();
		InitCredits();
		InitGameover();
		InitPause();
	}

	static void UpdateGame()
	{
		switch (currentScreen)
		{
		case MENU:
			UpdateMenu();
			break;
		case GAMEPLAY:
			gameplay::UpdateFrame();
			break;
		case GAMEOVER:
			UpdateGameOver();
			break;
		case CREDITS:
			UpdateCredits();
			break;
		case PAUSE:
			UpdatePause();
			break;
		case MULTIPLAYER:
			multiplayer::UpdateFrame();
			break;
		default:
			break;
		}
	}

	static void DrawGame()
	{
		BeginDrawing();
		switch (currentScreen)
		{
		case MENU:
			DrawMenu();
			break;
		case GAMEPLAY:
			gameplay::Draw();
			break;
		case GAMEOVER:
			DrawGameOver();
			break;
		case CREDITS:
			DrawCredits();
			break;
		case PAUSE:
			DrawPause();
			break;
		case MULTIPLAYER:
			multiplayer::Draw();
			break;
		default:
			break;
		}
		EndDrawing();
	}

	static void CloseGame()
	{
		CloseWindow();

		gameplay::UnloadGameplay();
		multiplayer::UnloadGameplay();
	}

	void ExecuteGame()
	{
		InitGame();

		while (!WindowShouldClose() && !exit)
		{
			UpdateGame();
			DrawGame();
		}
		CloseGame();
	}
}