#include "Credits.h"

#include "raylib.h"

#include "App.h"
#include "Menu.h"

using namespace app;
using namespace menu;

namespace app
{
	namespace credits
	{
		static char text1[] = "Using Raylib library";
		static char text4[] = "MENU";
		static char text5[] = "Created by Monti Matias";
		static int sizeText = 0;
		static int sizeText2 = 0;
		static int sizeText3 = 0;
		static int textPositionX = 0;
		static int textPositionY = 0;
		static int text2PositionX = 0;
		static int text2PositionY = 0;
		static int text3PositionX = 0;
		static int text3PositionY = 0;
		static int text4PositionX = 0;
		static int text4PositionY = 0;
		static int text5PositionX = 0;
		static int text5PositionY = 0;
		static int halfScreen = 0;

		static const int scaleAux1 = 800;
		static const int scaleAux2 = 1600;

		static Vector2 mousePoint;
		static Rectangle rect1;
		static Color colorRect1;

		void InitCredits()
		{
			sizeText = (GetScreenWidth() * 20) / scaleAux1;
			sizeText2 = (GetScreenWidth() * 15) / scaleAux1;
			sizeText3 = (GetScreenWidth() * 12.f) / scaleAux1;
			halfScreen = GetScreenWidth() / 2;

			textPositionX = halfScreen - MeasureText(text1, sizeText) / 2;
			textPositionY = GetScreenHeight() * 0.13;
			text4PositionX = halfScreen - MeasureText(text4, sizeText2) / 2;
			text4PositionY = GetScreenHeight() * 0.80;
			text5PositionX = halfScreen - MeasureText(text5, sizeText) / 2;
			text5PositionY = GetScreenHeight() * 0.05;

			colorRect1 = RED;

			rect1.height = (GetScreenWidth() * 80) / scaleAux2;
			rect1.width = (GetScreenWidth() * 170) / scaleAux2;
			rect1.x = halfScreen - rect1.width / 2;
			rect1.y = GetScreenHeight() / 2 + GetScreenHeight() * 0.275;
		}

		void UpdateCredits()
		{
			mousePoint = GetMousePosition();
			if (CheckCollisionPointRec(mousePoint, rect1))
			{
				colorRect1.a = 120;

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					currentScreen = MENU;
					InitMenu();
				}
			}
			else colorRect1.a = 255;
		}

		void DrawCredits()
		{
			ClearBackground(BLACK);
			DrawRectangleRec(rect1, colorRect1);
			DrawText(text1, textPositionX, textPositionY, sizeText, BLUE);
			DrawText(text4, text4PositionX, text4PositionY, sizeText2, BLACK);
			DrawText(text5, text5PositionX, text5PositionY, sizeText, BLUE);
			DrawText("V 1.0", GetScreenWidth() - 70, GetScreenHeight() - 70, (GetScreenWidth() * 20) / 800, WHITE);
			DrawText("https://wallpaperscraft.com/download/hills_landscape_minimalism_evening_sky_beauty_74526/1920x1080", 20, GetScreenHeight() / 2, 12, WHITE);
		}
	}
}