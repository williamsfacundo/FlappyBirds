#include "Menu.h"

#include "raylib.h"

#include "App.h"

using namespace app;

namespace app
{
	namespace menu
	{
		static char text1[] = "1 PLAY";
		static char text2[] = "2 PLAY";
		static char text3[] = "CREDITOS";
		static char text4[] = "SONIDO";
		static char text5[] = "SALIR";
		static char text6[] = "V 1.0";
		static int sizeText2 = 0;
		static int sizeText3 = 0;
		static int text1PositionX = 0;
		static int text1PositionY = 0;
		static int text2PositionX = 0;
		static int text2PositionY = 0;
		static int text3PositionX = 0;
		static int text3PositionY = 0;
		static int text4PositionX = 0;
		static int text4PositionY = 0;
		static int text5PositionX = 0;
		static int text5PositionY = 0;
		static int text6PositionX = 0;
		static int text6PositionY = 0;		
		static Vector2 mousePoint;
		static Rectangle rect1;
		static Rectangle rect2;
		static Rectangle rect3;
		static Rectangle rect4;
		static Rectangle rect5;		
		static Color colorRect1;
		static Color colorRect2;
		static Color colorRect3;
		static Color colorRect4;
		static Color colorRect5;		

		static const int scaleAux1 = 800;
		static const int scaleAux2 = 1600;
		static const int scaleAux3 = 1280;

		static int halfScreenWidth = 0;
		static int halfScreenHeight = 0;

		static Image menuImage;
		static Texture2D menuImageTexture;		
		static float scaleBackground;

		void InitMenu()
		{
			menuImage = LoadImage("../res/backgroundMenu.png");
			menuImageTexture = LoadTextureFromImage(menuImage);						
			halfScreenWidth = GetScreenWidth() / 2;
			halfScreenHeight = GetScreenHeight() / 3;

			sizeText2 = (GetScreenWidth() * 20) / scaleAux1;
			sizeText3 = (GetScreenWidth() * 15) / scaleAux1;
			text1PositionX = halfScreenWidth - MeasureText(text1, sizeText2) / 2;
			text1PositionY = halfScreenHeight + GetScreenHeight() * 0.0333333;
			text2PositionX = halfScreenWidth - MeasureText(text2, sizeText2) / 2;
			text2PositionY = halfScreenHeight + GetScreenHeight() * 0.1333333;
			text3PositionX = halfScreenWidth - MeasureText(text3, sizeText2) / 2;
			text3PositionY = halfScreenHeight + GetScreenHeight() * 0.2333333;
			text4PositionX = halfScreenWidth - MeasureText(text4, sizeText2) / 2;
			text4PositionY = halfScreenHeight + GetScreenHeight() * 0.3333333;
			text5PositionX = halfScreenWidth - MeasureText(text4, sizeText2) / 2;
			text5PositionY = halfScreenHeight + GetScreenHeight() * 0.4444444;
			text6PositionX = halfScreenWidth - MeasureText(text5, sizeText2) / 2;
			text6PositionY = halfScreenHeight + GetScreenHeight() * 0.5555555;

			colorRect1 = RED;
			colorRect2 = RED;
			colorRect3 = RED;
			colorRect4 = RED;
			colorRect5 = RED;

			rect1.height = (GetScreenWidth() * 80) / scaleAux2;
			rect1.width = (GetScreenWidth() * 255) / scaleAux2;
			rect1.x = halfScreenWidth - rect1.width / 2;
			rect1.y = halfScreenHeight + GetScreenHeight() * 0.11;

			rect2.height = (GetScreenWidth() * 80) / scaleAux2;
			rect2.width = (GetScreenWidth() * 255) / scaleAux2;
			rect2.x = halfScreenWidth - rect1.width / 2;
			rect2.y = halfScreenHeight + GetScreenHeight() * 0.21;

			rect3.height = (GetScreenWidth() * 80) / scaleAux2;
			rect3.width = (GetScreenWidth() * 255) / scaleAux2;
			rect3.x = halfScreenWidth - rect1.width / 2;
			rect3.y = halfScreenHeight + GetScreenHeight() * 0.31;

			rect4.height = (GetScreenWidth() * 80) / scaleAux2;
			rect4.width = (GetScreenWidth() * 255) / scaleAux2;
			rect4.x = halfScreenWidth - rect1.width / 2;
			rect4.y = halfScreenHeight + GetScreenHeight() * 0.01;	

			rect5.height = (GetScreenWidth() * 80) / scaleAux2;
			rect5.width = (GetScreenWidth() * 255) / scaleAux2;
			rect5.x = halfScreenWidth - rect1.width / 2;
			rect5.y = halfScreenHeight + GetScreenHeight() * 0.41;

			scaleBackground = (GetScreenWidth() * 1.0f) / scaleAux3;
		}

		void UpdateMenu()
		{
			mousePoint = GetMousePosition();

			if (CheckCollisionPointRec(mousePoint, rect3))
			{
				colorRect3.a = 120;

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					//mute = !mute;
				}
			}
			else colorRect3.a = 255;

			if (CheckCollisionPointRec(mousePoint, rect2))
			{
				colorRect2.a = 120;

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					UnloadMenu();
					currentScreen = CREDITS;
				}
			}
			else colorRect2.a = 255;

			if (CheckCollisionPointRec(mousePoint, rect5))
			{
				colorRect5.a = 120;

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					exit = true;
				}
			}
			else colorRect5.a = 255;

			if (CheckCollisionPointRec(mousePoint, rect4))
			{
				colorRect4.a = 120;

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{
					UnloadMenu();
					
					currentScreen = GAMEPLAY;
					onePlayer = true;
				}
			}
			else colorRect4.a = 255;

			if (CheckCollisionPointRec(mousePoint, rect1))
			{
				colorRect1.a = 120;

				if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
				{	
					UnloadMenu();
					
					currentScreen = MULTIPLAYER;
					onePlayer = false;
				}
			}
			else colorRect1.a = 255;
		}

		void DrawMenu()
		{
			ClearBackground(WHITE);
			DrawTextureEx(menuImageTexture, { 0,0 }, 0, scaleBackground, WHITE);
			DrawRectangleRec(rect1, colorRect1);
			DrawRectangleRec(rect2, colorRect2);
			DrawRectangleRec(rect3, colorRect3);
			DrawRectangleRec(rect4, colorRect4);
			DrawRectangleRec(rect5, colorRect5);
			DrawText(text1, text1PositionX, text1PositionY, sizeText2, BLACK);
			DrawText(text2, text2PositionX, text2PositionY, sizeText2, BLACK);
			DrawText(text3, text3PositionX, text3PositionY, sizeText2, BLACK);
			DrawText(text4, text4PositionX, text4PositionY, sizeText2, BLACK);
			DrawText(text5, text5PositionX, text5PositionY, sizeText2, BLACK);
			DrawText(text6, text6PositionX, text6PositionY, sizeText2, BLACK);			
		}

		void UnloadMenu()
		{
			UnloadTexture(menuImageTexture);
			UnloadImage(menuImage);			
		}

	}
}