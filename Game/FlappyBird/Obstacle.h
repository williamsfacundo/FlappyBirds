#pragma once

#include "raylib.h"

namespace app
{
	namespace obstacle
	{
		struct Column
		{
			Rectangle rec1;
			Rectangle rec2;
		};

		void InitObstacle();
		void UpdateObstacle();
		void DrawObstacle();
		void UnloadObstacle();
	}
}