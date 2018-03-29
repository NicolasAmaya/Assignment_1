#include "InputSystem.h"
#include <iostream>

namespace core {

	InputSystem::InputSystem():
		System(SystemType::INPUT), requestedQuit(false)
	{
	}


	InputSystem::~InputSystem()
	{
	}

	/*bool InputSystem::init() {
		return true;
	 }*/
	void InputSystem::Update() {

		SDL_Event e;

		//HANDLE events on queue 
		while (SDL_PollEvent(&e) != 0) {

			if (e.type == SDL_QUIT) {
				requestedQuit = true;
			
			}

			switch (e.type) {

			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				
				case SDLK_LEFT:
					m_leftPressed = true;
					//Position->SetPos(-1.0f, 0.0f);


					break;
				case SDLK_RIGHT:
					m_RightPressed = true;
					//Position->SetPos(1.0f, 0.0f);
					Posx += 10;
					break;
				case SDLK_UP:
					m_UpPressed = true;
					//Position->SetPos(0.0f, 1.0f);
					break;
				case SDLK_DOWN:
					m_DownPressed = true;
					//Position->SetPos(0.0f, -1.0f);

					break;
				
				}
				printf("A key was pressed");
				break;

			case SDL_KEYUP:
				switch (e.key.keysym.sym) {

				case SDLK_LEFT:
					m_leftPressed = false;

					break;

				case SDLK_RIGHT:
					m_RightPressed = false;
					break;
				case SDLK_UP:
					m_UpPressed = false;
					break;
				case SDLK_DOWN:
					m_DownPressed = false;

					break;
				case SDL_QUIT:

					break;


				}
				printf("A key was Released");
				break;
			}
		}


	 }
	/*void InputSystem::Draw() const {

	 }
	bool InputSystem::ShutDown() {
		return true;
	 }*/

}
