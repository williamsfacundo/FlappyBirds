#include "Obstacle.h"

#include "App.h"
#include "Player.h"
#include "Gameplay.h"
#include <math.h>

using namespace app;
using namespace player;
using namespace gameplay;

namespace app
{
	namespace obstacle
	{
		static const int colGap = 150;
		static const int colSpeed = 300;
		static const int birdGap = 215;
		static const int minRand = 0;
		static const int maxRand = 250;

		const int totalCols = 1;
		Column columnsUp[totalCols];
		Column columnsDown[totalCols];
		Column column[totalCols];
		int random;

		bool playerIsDead;

		Player player;

		void InitObstacle()
		{
			for (int i = 0; i < totalCols; i++)
			{
				random = GetRandomValue(minRand, maxRand);

				column[i].columnImage = LoadImage("res/COLUMN.png");

				//UP COL
				columnsUp[i].columnTexture = LoadTextureFromImage(column[i].columnImage);

				columnsUp[i].position.x = GetScreenWidth() + colGap + (colGap + columnsUp[i].columnTexture.width) * i;
				columnsUp[i].position.y = 0 - random;

				columnsUp[i].collider.height = columnsUp[i].columnTexture.height;
				columnsUp[i].collider.width = columnsUp[i].columnTexture.width;
				columnsUp[i].collider.x = 0;
				columnsUp[i].collider.y = 0;

				columnsUp[i].sourceRec = { 0.0f, 0.0f, (float)columnsUp[i].columnTexture.width, (float)columnsUp[i].columnTexture.height };

				columnsUp[i].destRec = { columnsUp[i].position.x, columnsUp[i].position.y, (float)columnsUp[i].columnTexture.width,(float)columnsUp[i].columnTexture.height };

				columnsUp[i].origin = { 0,0 };

				//DOWN COL
				columnsDown[i].columnTexture = LoadTextureFromImage(column[i].columnImage);

				columnsDown[i].position.x = GetScreenWidth() + colGap + (colGap + columnsUp[i].columnTexture.width) * i;
				columnsDown[i].position.y = columnsUp[i].position.y + columnsUp[i].columnTexture.height + birdGap;

				columnsDown[i].collider.height = columnsUp[i].columnTexture.height;
				columnsDown[i].collider.width = columnsUp[i].columnTexture.width;
				columnsDown[i].collider.x = 0;
				columnsDown[i].collider.y = 0;

				columnsDown[i].sourceRec = { 0.0f, 0.0f, (float)columnsDown[i].columnTexture.width, (float)columnsDown[i].columnTexture.height };

				columnsDown[i].destRec = { columnsDown[i].position.x, columnsDown[i].position.y, (float)columnsDown[i].columnTexture.width,(float)columnsDown[i].columnTexture.height };

				columnsDown[i].origin = { (float)columnsDown[i].columnTexture.width, (float)columnsDown[i].columnTexture.height };
			}
		}

		void UpdateObstacle()
		{
			if (!gameOver)
			{
				for (int i = 0; i < totalCols; i++)
				{
					//Movement
					random = GetRandomValue(minRand, maxRand);

					columnsUp[i].position.x -= colSpeed * GetFrameTime();
					columnsDown[i].position.x -= colSpeed * GetFrameTime();

					columnsUp[i].collider.x = columnsUp[i].position.x;
					columnsUp[i].collider.y = columnsUp[i].position.y;

					columnsDown[i].collider.x = columnsDown[i].position.x;
					columnsDown[i].collider.y = columnsDown[i].position.y;

					if (CheckCollisionCircleRec(player.position, player.radius, columnsUp[i].collider))
					{
						player.isDead = true;
						gameOver = true;
					}

					if (CheckCollisionCircleRec(player.position, player.radius, columnsDown[i].collider))
					{
						player.isDead = true;
						gameOver = true;
					}

					/*if (circleRect(player.position.x, player.position.y, player.radius, columnsUp[i].collider.x, columnsUp[i].collider.x, columnsUp[i].columnTexture.width, columnsUp[i].columnTexture.height))
					{
						player.isDead = true;
						gameOver = true;
					}*/

					//Recicle
					if (columnsUp[i].position.x + columnsUp[i].columnTexture.width <= 0)
					{
						//recicle up
						columnsUp[i].position.y = 0 - random;
						columnsUp[i].position.x = GetScreenWidth() + colGap * 3;

						//recicle down
						columnsDown[i].position.y = columnsUp[i].position.y + columnsUp[i].columnTexture.height + birdGap;
						columnsDown[i].position.x = GetScreenWidth() + colGap * 3;
					}

					columnsDown[i].destRec = { columnsDown[i].position.x, columnsDown[i].position.y, (float)columnsDown[i].columnTexture.width,(float)columnsDown[i].columnTexture.height };

					columnsUp[i].destRec = { columnsUp[i].position.x, columnsUp[i].position.y, (float)columnsUp[i].columnTexture.width,(float)columnsUp[i].columnTexture.height };
				}
			}
			else
			{
				currentScreen = GAMEOVER;
			}
		}

		void DrawObstacle()
		{
			for (int i = 0; i < totalCols; i++)
			{
				DrawTexturePro(columnsDown[i].columnTexture, columnsDown[i].sourceRec, columnsDown[i].destRec, columnsDown[i].origin, 180, WHITE);
				DrawTexturePro(columnsUp[i].columnTexture, columnsUp[i].sourceRec, columnsUp[i].destRec, columnsUp[i].origin, 0, WHITE);

				DrawRectangleLinesEx(columnsUp[i].collider, 2, GREEN);
				DrawRectangleLinesEx(columnsDown[i].collider, 2, GREEN);
			}
		}

		void UnloadObstacle()
		{
			for (int i = 0; i < totalCols; i++)
			{
				UnloadTexture(columnsUp[i].columnTexture);
				UnloadTexture(columnsDown[i].columnTexture);
			}
		}

		bool circleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh) {

			// temporary variables to set edges for testing
			float testX = cx;
			float testY = cy;

			// which edge is closest?
			if (cx < rx) testX = rx;      // test left edge
			else if (cx > rx + rw) testX = rx + rw;   // right edge
			if (cy < ry) testY = ry;      // top edge
			else if (cy > ry + rh) testY = ry + rh;   // bottom edge

			// get distance from closest edges
			float distX = cx - testX;
			float distY = cy - testY;
			float distance = sqrt((distX * distX) + (distY * distY));

			// if the distance is less than the radius, collision!
			if (distance <= radius) {
				return true;
			}
			return false;
		}
	}
}