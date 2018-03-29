#include "System.h"
#include <iostream>

namespace core {

	System::System(SystemType tp) : type(tp)
		
	{
	}


	System::~System()
	{
	}


	bool System::init() {
		std::cout << "hello from Systeminit" << std::endl;
		return true;
	}
	void System::Update() {

	}
	void System::Draw() const {

	}
	bool System::ShutDown() {
		return true;
	}

}
