#include "Robot.h"
#include "SocketServer.h"

class Controller{
	
	public:
		Robot robot;
		SocketServer ss;
		
		Controller();
		void processAction(int x, int y);
		int initCommunication();
		int acceptClient();
		void trade(int length);
		void shutdownServer();

};
