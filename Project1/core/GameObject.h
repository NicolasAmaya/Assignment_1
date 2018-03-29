#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>


#define SCREEN_WIDTH 740
#define SCREEN_HEIGHT 500

namespace Scene {
	class GameObject
	{
	private:
		//The image we will load and show on the screen
		SDL_Surface* image;
		//The surface contained by the window
		SDL_Surface* screenSurface;
		int screenPosx;
		int screenPosy;
	public:
		GameObject(SDL_Surface* screenSurface_);
		virtual ~GameObject();

		bool init();
		void Update();
		void Draw() const;
		bool ShutDown();
		bool loadmedia();
		//void SetBMPname(char* filename) { image = filename; };
	};

}
#endif //GAME_OBJECT_H

