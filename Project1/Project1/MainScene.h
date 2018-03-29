#ifndef MAINSCENE_H
#define MAINSCENE_H
#include <Scene.h>
#include <GameObject.h>
using namespace Scene;
class MainScene : public Scene
{
public:

	SDL_Surface *jetskiImage;
	SDL_Rect jetSkiRect;
	int posX;
	int posY;
	GameObject* object;

	MainScene();
	~MainScene();

	bool init() override;
	void Update() override;
	void Draw() const override;
	bool ShutDown() override;
};
#endif MAINSCENE_H

