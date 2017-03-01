#include "Robot.h"
#include "Simulator.h"
#include "SocketServer.h"

class Controller{
	
	public:
		Robot robot;
		Simulator dumbRob;
		SocketServer ss;
		
		Controller();
		void processAction(int x, int y);
		void processSimulation(int x, int y);
		int launchServer();
};
