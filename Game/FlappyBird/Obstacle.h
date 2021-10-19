#pragma once

#include "raylib.h"

namespace app
{
	namespace obstacle
	{
		struct Column
		{
			Image columnImage;
			Texture2D columnTexture;
			Vector2 position;
			Rectangle collider;
			Rectangle sourceRec;
			Rectangle destRec;
			Vector2 origin;
		};

		void InitObstacle();
		void UpdateObstacle();
		void DrawObstacle();
		void UnloadObstacle();
		bool circleRect(float cx, float cy, float radius, float rx, float ry, float rw, float rh);
	}
}