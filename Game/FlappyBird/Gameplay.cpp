#include "Gameplay.h"

#include "raylib.h"
#include "App.h"
#include "Player.h"
#include "Obstacle.h"
#include "Parallax.h"

using namespace app;
using namespace player;
using namespace obstacle;
using namespace parallax;

namespace app
{
	namespace gameplay
	{
		extern bool gameOver = false;

		//Boton pausa
		static Rectangle btnPause1;
		static Rectangle btnPause2;
		static Color colorRect;
		static Vector2 mousePoint;

		//static bool init;

		void InitValues()
		{
			//init boton pausa
			btnPause1.x = GetScreenWidth() * 0.96f;
			btnPause1.y = GetScreenHeight() * 0.02f;
			btnPause1.height = (GetScreenWidth() * 40) / 1600;
			btnPause1.width = (GetScreenWidth() * 15) / 1600;
			btnPause2.x = GetScreenWidth() * 0.975f;
			btnPause2.y = GetScreenHeight() * 0.02f;
			btnPause2.height = (GetScreenWidth() * 40) / 1600;
			btnPause2.width = (GetScreenWidth() * 15) / 1600;
			colorRect = GRAY;

			InitParallax();
			InitPlayer();
			InitObstacle();
		}

		static void Input()
		{
			mousePoint = GetMousePosition();

			if (CheckCollisionPointRec(mousePoint, btnPause1))
			{
				colorRect.a = 120;

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) currentScreen = PAUSE;
			}
			else colorRect.a = 255;

			if (CheckCollisionPointRec(mousePoint, btnPause2))
			{
				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) currentScreen = PAUSE;
			}
		}

		static void Update()
		{
			UpdateParallax();
			UpdatePlayer();
			UpdateObstacle();
		}

		void UpdateFrame()
		{
			Input();
			Update();
		}

		void Draw()
		{
			ClearBackground(BLANK);

			DrawParallax();
			DrawPlayer();
			DrawObstacle();

			DrawRectangleRec(btnPause1, colorRect);
			DrawRectangleRec(btnPause2, colorRect);
		}

		void ResetValues()
		{
			InitValues();
			gameOver = false;
		}

		void UnloadGameplay()
		{
			DeInitParallax();
			UnloadPlayer();
			UnloadObstacle();
		}
	}

	namespace multiplayer
	{
		extern bool gameOver = false;

		//Boton pausa
		static Rectangle btnPause1;
		static Rectangle btnPause2;
		static Color colorRect;
		static Vector2 mousePoint;
		
		void InitValues()
		{
			//init boton pausa
			btnPause1.x = GetScreenWidth() * 0.96f;
			btnPause1.y = GetScreenHeight() * 0.02f;
			btnPause1.height = (GetScreenWidth() * 40) / 1600;
			btnPause1.width = (GetScreenWidth() * 15) / 1600;
			btnPause2.x = GetScreenWidth() * 0.975f;
			btnPause2.y = GetScreenHeight() * 0.02f;
			btnPause2.height = (GetScreenWidth() * 40) / 1600;
			btnPause2.width = (GetScreenWidth() * 15) / 1600;
			colorRect = GRAY;			

			InitParallax();
		}

		static void Input() 
		{

		}

		static void Update() 
		{
			UpdateParallax();
		}

		static void Draw() 
		{
			ClearBackground(BLANK);

			DrawParallax();
		}

		void ResetValues()
		{
			InitValues();
			gameOver = false;
		}

		void play() 
		{
			Input();
			Update();			
		}

		void UnloadGameplay()
		{
			DeInitParallax();			
		}
	}
}