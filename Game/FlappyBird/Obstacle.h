#pragma once

#include "raylib.h"

namespace app
{
	namespace obstacle
	{
		struct Column
		{
			Texture2D texture;
			Vector2 position;
			Rectangle collider;
			Rectangle sourceRec;
			Rectangle destRec;
			Vector2 origin;
		};

		void InitObstacle();
		void UpdateObstacleOnePlayer();
		void UpdateObstacleTwoPlayers();
		void DrawObstacle();
		void UnloadObstacle();
	}
}