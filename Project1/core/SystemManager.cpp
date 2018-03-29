#include "SystemManager.h"
#include "System.h"
#include "InputSystem.h"
#include "Window.h"

namespace core 
{
	SystemManager* SystemManager::m_instance = nullptr; //this is how u initialize a static variable 

	SystemManager::SystemManager()
	{
		systems.push_back(new InputSystem());
		systems.push_back(new Window());
	}


	SystemManager::~SystemManager()
	{
	}

	bool SystemManager::init() {

		for (System*s : systems)
		{
			if (!s->init()) {
				return false;
			}
		}

		return true;

	}
	void SystemManager::Update() {

		for (System*s : systems)
		{
			s->Update();
		}

	}
	void SystemManager::Draw() const {

		for (System*s : systems)
		{
			s->Draw();
		}

	}
	bool SystemManager::ShutDown() {


		for (System*s : systems)
		{
			if (s->ShutDown()) {
				return false;
			}

			delete s;
			s = nullptr;
		}

		systems.clear();
		return true;
	}

}
