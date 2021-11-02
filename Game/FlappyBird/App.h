#ifndef APP_H
#define APP_H

#include "raylib.h"

#include "Menu.h"
#include "Credits.h"
#include "Gameplay.h"
#include "Pause.h"
#include "GameOver.h"
#include "Player.h"
#include "Obstacle.h"

using namespace app;
using namespace menu;
using namespace credits;
using namespace gameplay;
using namespace pause;
using namespace gameover;
using namespace playerOne;
using namespace obstacle;

namespace app
{
	enum SCREENS
	{
		MENU = 0, GAMEPLAY, GAMEOVER, CREDITS, PAUSE, MULTIPLAYER
	};

	extern bool exit;
	extern bool onePlayer;
	extern bool winner;
	extern SCREENS currentScreen;

	void ExecuteGame();
}

#endif