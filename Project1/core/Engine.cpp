#include "Engine.h"
#include <iostream>



namespace core{
										//this takes s as teh default value
	Engine::Engine(Scene::Scene* s) : mainScene(s), isRunning(false) {
		//mainScene = s; //In inizialice 2 times teh default and then the varibale s;
		
		//managers.push_back(new SystemManager::GetInstance());
		managers.push_back(SystemManager::GetInstance());//use singleton
	}
	Engine::~Engine() {

	}
	

	int Engine::init() {
		int initResult = 0;
		//Mywindow->init();
		
	
		/*
		//Initialize SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			initResult = ENGINE_INIT_ERROR;
		}
		else
		{
			//Create window
			window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
				initResult = ENGINE_INIT_ERROR;
			}
			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);

				//Fill the surface white
				SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0xFF));

				//Update the surface
				SDL_UpdateWindowSurface(window);

			}
		}
		*/
	for (Manager *m : managers) {
			 m->init();

		}
		mainScene->init();
		return 0;

	}
	int Engine::Run() {
		isRunning = true;

		//systemManager.GetSystem();
		while (!inputSystem.QuitRequested()) {

			//update 
			update();
			//render
			draw();
				
		}

		return shutdown();

	}

	void Engine::update() {

		
		//inputSystem.Update();
		for (Manager *m : managers) {
			m->Update();

		}

			mainScene->Update();

	}
	void Engine::draw() const {

		
		for (Manager *m : managers) {
			m->Draw();

		}
		mainScene->Draw();
	}
	int Engine::shutdown() {

		if (mainScene->ShutDown()) {
			return 1;
		 }

		//Destroy window
		//SDL_DestroyWindow(window);

		//Quit SDL subsystems
		//SDL_Quit();

		 return 0;

	}

}