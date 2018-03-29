#include "Window.h"
#include "VMath.h"
#include "SystemManager.h"
//#include "InputSystem.h"

#include <iostream>

namespace core {
					//the window calls the dafault constructure of system so we need to tell him what constructure to use
	Window::Window() :
		System(SystemType::WINDOW)
	{}


	bool Window::init() {
		//projectionMatrix = MATH::MMath::viewportNDC(1000, 600) * MATH::MMath::orthographic(0.0f, 780.0 / 64.0f, 0.0f, 7.0f, 0.0f, 1.0f);
		//Initialization flag

		
		bool success = true;

		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create window
			gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH2, SCREEN_HEIGHT2, SDL_WINDOW_SHOWN);
			if (gWindow == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
		loadMedia();
		return success;
	}


	SDL_Window* Window::GetSDL_Window()
	{
		return gWindow;
	}


	void Window::Update()
	{
		//MOVE IT IN A TERRIBLE WAY THAT IM NOT PROUD OF 
		SystemManager*sm = core::SystemManager::GetInstance();
		System* SomeSystemIDK = sm->GetSystem(core::SystemType::INPUT);
		InputSystem* inputSystem = dynamic_cast<InputSystem*>(SomeSystemIDK);
		if (inputSystem->IsLeftPressed()) {
			PosX -= 1;
			printf("Left pressed from main scene \n");
		}
		if (inputSystem->IsRightPressed()) {
			PosX += 1;
			printf("Right pressed from main scene \n");
		}
		if (inputSystem->IsUpPressed()) {
			PosY -= 1;
			printf("Up pressed from main scene \n");
		}
		if (inputSystem->IsDownPressed()) {
			PosY += 1;
			printf("Down pressed from main scene \n");
		}

		//OVERRIDE THE COLOR
		
		SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, &objRect);
		SDL_UpdateWindowSurface(gWindow);
		Render();

		//hello
	}

	bool Window::loadMedia()
	{
		//Loading success flag
		bool success = true;
		//std::cout << "in load Media" << std::endl;
		//Load splash image
		gHelloWorld = SDL_LoadBMP("star.bmp");
		if (gHelloWorld == NULL)
		{
			printf("Unable to load image %s! SDL Error: %s\n", "hello_world.bmp", SDL_GetError());
			success = false;
		}

		return success;
	}

	void Window::Draw() const
	{

		//color of the surface
		SDL_FillRect(gScreenSurface, NULL, SDL_MapRGB(gScreenSurface->format, 100, 0, 100));
		
	}
	bool Window::ShutDown()
	{


		//Deallocate surface
		SDL_FreeSurface(gHelloWorld);
		gHelloWorld = NULL;

		//Destroy window
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;

		//Quit SDL subsystems
		SDL_Quit();
		return 0;
	}

	void Window::Render() {

			//MATH::Vec3 screenCoordinates = projectionMatrix * Pos;

			objRect.x = PosX;//screenCoordinates.x;
			objRect.y = PosY;//screenCoordinates.y;


		//SDL_UpdateWindowSurface(gWindow);

	}

	void Window::SetPos(float x,float y) {

		PosX = x;
		PosY = y;

	}

}

