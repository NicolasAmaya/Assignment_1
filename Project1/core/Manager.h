#pragma once

namespace core {

	//make this  asingleton
	class Manager
	{
	public:
		Manager();
		virtual ~Manager();


		virtual bool init() = 0;
		virtual void Update() = 0;
		virtual void Draw() const = 0;
		virtual bool ShutDown() = 0;
	};

}

