#ifndef SCENE_H
#define SCENE_H

#include <vector>
namespace Scene {

	class Scene
	{
	private:

		//std::vector<class GameObject> gameObj;

	public:
		Scene();
		//use virtual to destroy also all the child of the parent class
		virtual ~Scene();

		virtual bool init();
		virtual void Update();
		virtual void Draw() const;
		virtual bool ShutDown();
	};
}

#endif //SCENE_H

