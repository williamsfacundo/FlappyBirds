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
}