#ifndef _SYSTEM_MANAGER_H

#define _SYSTEM_MANAGER_H

#include "Manager.h"
#include "System.h"
#include <vector>

namespace core {


	/*templte<class> T
	class singleton{
	
	static T* GetInstance(); //source mania www check website tut singleton
	}
	
	*/

	class SystemManager : public Manager
	{
		std::vector<class System*> systems;//vector of systems
		SystemManager();

		static SystemManager* m_instance; //from lll the instances of teh classs there can onle be one variable of the type instance;
	public:
		//SystemManager();
		~SystemManager();

		 bool init();
		 void Update();
		 void Draw() const;
		 bool ShutDown();


		 static SystemManager* GetInstance()
		 {

			 if (m_instance == nullptr) {
			 
				 m_instance = new SystemManager();
			 }

			 return m_instance;

		 }
		 //CREATE ANOTHER VERSION THAT USES TEMPLATES GetSystem<inputSystem>()
		 System* GetSystem(SystemType t) {

			 for (System* s : systems) {

				 if (s->type == t) {
				 
					 return s;
				 }
				  return nullptr; 

			 }

		 }

	};

}

#endif // !_SYSTEM_MANAGER_H

