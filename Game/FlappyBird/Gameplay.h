#ifndef GAMEPLAY_H
#define GAMEPLAY_H

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
		void UpdateFrame();		
		void Draw();		
		void ResetValues();
		void UnloadGameplay();

		extern bool gameOver;
	}
}

#endif