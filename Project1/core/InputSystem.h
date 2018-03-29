#pragma once
#include "System.h"
#include "Window.h"
#include <SDL.h>
namespace core {
	class InputSystem : public System
	{
		bool requestedQuit;
		bool m_leftPressed = false;
		bool m_RightPressed = false;
		bool m_UpPressed = false;
		bool m_DownPressed = false;
	public:
		InputSystem();
		~InputSystem();

		float Posx;
		float Posy;

		//bool init() override;///
		void Update() override;
		//void Draw() const override;///
		//bool ShutDown() override;///
		//Window* Position; //I HAVE TO CHANGE THIS TO A PROPER WAY 

		bool IsLeftPressed()const { return m_leftPressed; }
		bool IsRightPressed()const { return m_RightPressed; }
		bool IsUpPressed()const { return m_UpPressed; }
		bool IsDownPressed()const { return m_DownPressed; }


		inline bool QuitRequested() const { return requestedQuit; }

	};

}

