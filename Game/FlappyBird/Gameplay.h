#pragma once

namespace app
{
	namespace gameplay
	{
		void InitValues();
		void UpdateFrame();
		void Draw();
		void ResetValues();
		void UnloadGameplay();

		extern bool gameOver;
	}

	namespace multiplayer
	{
		void InitValues();
		void Input();
		void Update();
		void Draw();
		void play();
		void ResetValues();
		void UnloadGameplay();

		extern bool gameOver;
	}
}