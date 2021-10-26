#pragma once

namespace app
{
	enum SCREENS
	{
		MENU = 0, GAMEPLAY, GAMEOVER, CREDITS, PAUSE, MULTIPLAYER
	};

	extern bool exit;
	extern SCREENS currentScreen;

	void ExecuteGame();
}