#include "App.h"
#include "raylib.h"

#include "Menu.h"
#include "Credits.h"

using namespace app;
using namespace menu;
using namespace credits;

namespace app
{
	static int screenWidth = 800;
	static int screenHeight = 600;

	bool exit = false;

	SCREENS currentScreen = MENU;

	static void InitGame()
	{
		SetExitKey(0);
		InitWindow(screenWidth, screenHeight, "FlappyBirds");
		//InitValues();
		InitMenu();
		InitCredits();
		//InitGameover();
		//InitPause();
	}

	static void UpdateGame()
	{
		switch (currentScreen)
		{
		case MENU:
			UpdateMenu();
			break;
		case GAMEPLAY:
			//UpdateFrame();
			break;
		case GAMEOVER:
			//UpdateGameOver();
			break;
		case CREDITS:
			UpdateCredits();
			break;
		case PAUSE:
			//UpdatePause();
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
			//DrawFrame();
			break;
		case GAMEOVER:
			//DrawGameOver();
			break;
		case CREDITS:
			DrawCredits();
			break;
		case PAUSE:
			//DrawPause();
			break;
		default:
			break;
		}
		EndDrawing();
	}

	static void CloseGame()
	{
		CloseWindow();
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