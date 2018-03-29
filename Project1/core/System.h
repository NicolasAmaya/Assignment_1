#ifndef SYSTEM_H
#define SYSTEM_H

namespace core {

	enum class SystemType : unsigned __int8 //just possitives of 1 byte
	{
		WINDOW,
		INPUT,
		TOTAL_SYSTEMS
	};

	class System
	{
	protected:
		//const SystemType type;

	public:
		const SystemType type;
		System(SystemType tp);
		virtual ~System();


		virtual bool init();
		virtual void Update();
		virtual void Draw() const;
		virtual bool ShutDown();
	};
}
#endif //SYSTEM_H

