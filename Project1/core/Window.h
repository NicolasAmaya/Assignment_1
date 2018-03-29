#ifndef WINDOW_H
#define WINDOW_H
#include "System.h"
#include "MMath.h"
#include "InputSystem.h"
//#include "MainScene.h"
#include <SDL.h>

#define SCREEN_WIDTH2 1000
#define SCREEN_HEIGHT2 600


namespace core {

	class Window : public System
	{
	private:
		//MATH::Matrix4 projectionMatrix;
		//The window we'll be rendering to
		SDL_Window * gWindow = NULL;

		//The surface contained by the window
		SDL_Surface* gScreenSurface = NULL;

		//The image we will load and show on the screen
		SDL_Surface* gHelloWorld = NULL;
		int width, height;

		SDL_Rect objRect;
		
		//core::System::InputSystem MySystem;

	public:
		float PosX;
		float PosY;
		Window();
		//MainScene hello;
		 bool init() override;
		 void Update() override;
		 void Draw() const override;
		 bool ShutDown() override;
		 bool loadMedia();
		 void Render();
		 void SetPos(float x, float y);


		//void Render();
		SDL_Window* GetSDL_Window();
	};


}

#endif //WINDOW_H

