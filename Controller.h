#include "Simulator.h"
#include "Server.h"

class Controller{
	
	public:
		//Robot robot;
		Simulator dumbRob;
		
		Controller();
		void processAction(int x, int y);
		void processSimulation(int x, int y);
		int launchServer();
};
