#include "raylib.h"

#include "App.h"
#include "Parallax.h"

namespace app
{
	namespace parallax
	{
		float scrollingBack;
		float scrollingMid;
		float scrollingFore;

		//Imagenes y texturas
		Image backgroundImage;
		Image midgroundImage;
		Image foregroundImage;
		Texture2D backgroundTexture;
		Texture2D midgroundTexture;
		Texture2D foregroundTexture;

		Vector2 V1;
		Vector2 V2;
		Vector2 V3;
		Vector2 V4;
		Vector2 V5;
		Vector2 V6;

		void InitParallax()
		{
			backgroundImage = LoadImage("res/background.png");
			midgroundImage = LoadImage("res/midground.png");
			foregroundImage = LoadImage("res/foreground.png");

			backgroundTexture = LoadTextureFromImage(backgroundImage);
			midgroundTexture = LoadTextureFromImage(midgroundImage);
			foregroundTexture = LoadTextureFromImage(foregroundImage);

			scrollingBack = 0.0f;
			scrollingMid = 0.0f;
			scrollingFore = 0.0f;
		}

		void UpdateParallax()
		{
			scrollingBack -= 0.01f;
			scrollingMid -= 0.02f;
			scrollingFore -= 0.04f;

			if (scrollingBack <= -backgroundTexture.width * 2) scrollingBack = 0;
			if (scrollingMid <= -midgroundTexture.width * 2) scrollingMid = 0;
			if (scrollingFore <= -foregroundTexture.width * 2) scrollingFore = 0;

			V1 = { scrollingBack, 0 };
			V2 = { backgroundTexture.width * 2 + scrollingBack, 0 };
			V3 = { scrollingMid, 20 };
			V4 = { midgroundTexture.width * 2 + scrollingMid, 20 };
			V5 = { scrollingFore, 100 };
			V6 = { foregroundTexture.width * 2 + scrollingFore, 100 };
		}

		void DrawParallax()
		{
			// Draw background image twice
			// NOTE: Texture is scaled twice its size
			DrawTextureEx(backgroundTexture, V1, 0.0f, 2.0f, WHITE);
			DrawTextureEx(backgroundTexture, V2, 0.0f, 2.0f, WHITE);

			// Draw midground image twice
			DrawTextureEx(midgroundTexture, V3, 0.0f, 2.0f, WHITE);
			DrawTextureEx(midgroundTexture, V4, 0.0f, 2.0f, WHITE);

			// Draw foreground image twice
			DrawTextureEx(foregroundTexture, V5, 0.0f, 2.0f, WHITE);
			DrawTextureEx(foregroundTexture, V6, 0.0f, 2.0f, WHITE);
		}

		void DeInitParallax()
		{
			UnloadTexture(backgroundTexture);
			UnloadTexture(midgroundTexture);
			UnloadTexture(foregroundTexture);
		}
	}
}