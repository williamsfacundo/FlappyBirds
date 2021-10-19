#pragma once

#include "raylib.h"

namespace app
{
	namespace player
	{

		struct Player
		{
			Image flappyImage;
			Texture2D flappyTexture;
			Vector2 position;
			Vector2 speed;
			Color color;
			float radius;
			float rotation;
			Vector2 acceleration;
			bool isDead;
			Rectangle sourceRec;
			Rectangle destRec;
			Vector2 origin;
		};

		extern Player player;

		void InitPlayer();
		void UpdatePlayer();
		void DrawPlayer();
		void UnloadPlayer();
		void PlayerController();
	}
}