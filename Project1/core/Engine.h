#ifndef ENGINE_H
#define ENGINE_H


#include <vector>
#include "Scene.h"
#include <SDL.h>
#include "InputSystem.h"
#include "SystemManager.h"
#include "Window.h"


#define ENGINE_INIT_ERROR 1
#define ENGINE_SHUTDOWN_ERROR 2



namespace Scene {
	//there is a class name scene in the scene namespace
	class Scene;
}

namespace core {
	class Engine {
	private:

		bool isRunning;
		std::vector<class Manager*> managers;

		Scene::Scene* mainScene;

		//move this to the window system

		//The window we'll be rendering to
		SDL_Window*  window = NULL;
		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;
		SystemManager* systemManager;

		InputSystem inputSystem;


	public:
		Window * Mywindow;
		Engine(Scene::Scene* s);
		~Engine();

		int init();
		int Run();
		bool Test;

	private:
		void update();
		void draw() const;
		int shutdown();

	};

}
#endif ENGINE_H
