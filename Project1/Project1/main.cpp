#include <iostream>
#include <Engine.h>
#include "MainScene.h"




int main(int argc,char* argv[]) {

	core::Engine e(new MainScene());

	if(e.init() == 0) {

		return e.Run();
	}


	return -1;
}