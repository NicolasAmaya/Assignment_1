#include "MainScene.h"
#include <Window.h>
#include <SystemManager.h>
#include <InputSystem.h>
#include <iostream>
#include <SDL.h>



MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}

bool MainScene::init() {
	//sceneSurface = static_cast<core::Window*>(core::SystemManager::GetInstance()->GetSystem(core::SystemType::WINDOW))->GetScreenSurface();
	object->init();
	return true;
}
void MainScene::Update() {
	using namespace core;
	//std::cout << "update" << std::endl;

	SystemManager*sm = core::SystemManager::GetInstance();
	System* SomeSystemIDK = sm->GetSystem(core::SystemType::INPUT);

	InputSystem* inputSystem = dynamic_cast<InputSystem*>(SomeSystemIDK);

	/*switch (SSomeSystemIDK) {

		case SDL

	}*/
	/*if (inputSystem->IsLeftPressed()) {
		posX -= 10;
		printf("Left pressed from main scene \n");
	}
	if (inputSystem->IsRightPressed()) {
		posX += 10;
		printf("Right pressed from main scene \n");
	}
	if (inputSystem->IsUpPressed()) {
		posY += 10;
		printf("Up pressed from main scene \n");
	}
	if (inputSystem->IsDownPressed()) {
		posX -= 10;
		printf("Down pressed from main scene \n");
	}*/
	
}
void MainScene::Draw() const {
	//std::cout << "Draw - hello sexy" << std::endl;
	/*SDL_Surface *screenSurface = SDL_GetWindowSurface();
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(jetskiImage, NULL, screenSurface, NULL);
	SDL_UpdateWindowSurface(window);*/
}
bool MainScene::ShutDown() {
	//std::cout << "Hello sexy" << std::endl;

	return true;
}

