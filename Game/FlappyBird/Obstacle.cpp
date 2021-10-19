#include "Obstacle.h"

#include "App.h"
#include "Player.h"
#include "Gameplay.h"

using namespace app;
using namespace player;
using namespace gameplay;

namespace app
{
	namespace obstacle
	{
		Column column;

		void InitObstacle()
		{
			column.rec1.width = 60;
			column.rec1.height = GetScreenHeight();

			column.rec2.width = 60;
			column.rec2.height = GetScreenHeight();

			column.rec1.x = GetScreenWidth() - column.rec1.width;
			column.rec2.x = column.rec1.x;

			column.rec1.y = GetRandomValue(50 * 4, GetScreenHeight());
			column.rec2.y = column.rec1.y - column.rec1.height - 150;
		}

		void UpdateObstacle()
		{
			column.rec1.x -= GetFrameTime() * 150;
			column.rec2.x -= GetFrameTime() * 150;

			if (column.rec1.x < player::player.position.x - player::player.radius * 4)
			{
				column.rec1.x = GetScreenWidth() - column.rec1.width;
				column.rec2.x = column.rec1.x;

				column.rec1.y = GetRandomValue(50 * 4, GetScreenHeight());
				column.rec2.y = column.rec1.y - column.rec1.height - 150;
			}

			if (CheckCollisionCircleRec(player::player.position, player::player.radius, column.rec1))
			{
				gameOver = true;
			}

			if (CheckCollisionCircleRec(player::player.position, player::player.radius, column.rec2))
			{
				gameOver = true;
			}
		}

		void DrawObstacle()
		{
			DrawRectangle(column.rec1.x, column.rec1.y, column.rec1.width, column.rec1.height, GREEN);
			DrawRectangle(column.rec2.x, column.rec2.y, column.rec2.width, column.rec2.height, GREEN);
		}

		void UnloadObstacle()
		{
			
		}
	}
}