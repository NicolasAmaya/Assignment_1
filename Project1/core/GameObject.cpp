#include "GameObject.h"
#include <iostream>


namespace Scene {

	GameObject::GameObject(SDL_Surface *screenSurface_): image(NULL), screenPosx(0), screenPosy(0)
	{

	}


	GameObject::~GameObject()
	{
	}

	bool GameObject::init() {

		/*image = SDL_LoadBMP("sample.bmp");
		if (image == nullptr) {
			std::cout << "Image didnt load properly" << std::endl;
			return false;

		}*/
		return true;

	}
	void GameObject::Update() {

	}
	void GameObject::Draw() const {

	}
	bool GameObject::ShutDown() {


		return true;
	}

	bool GameObject::loadmedia() {
	

		return true;
	
	}

}
