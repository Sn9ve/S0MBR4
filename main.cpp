#include "Controller.h"
#include <iostream>

	Controller controller;

using namespace std;
int main(){
	char keyWord;
	
	cout << "Key Word --> Action" << endl;
	cout << "s --> Stop" << endl;
	cout << "f --> Move Forward" << endl;
	cout << "b --> Move Backward" << endl;	
	cout << "t --> Calculate a distance" << endl;
	cout << "i --> start the server" << endl;
	cout << "q --> Quit" << endl;
	cout << "-------------------------------" << endl;
	
	while(1){
		cin >> keyWord;
		switch(keyWord){
			case 's':
				controller.processAction(0,0);
				break;
			case 'f':
				controller.processAction(50,50);
				break;
			case 'b':
				controller.processAction(-50,-50);
				break;
			case 't':
				cout << "la distance entre le robot est un obstacle est de " 
				<< controller.robot.proceesDistance(1) << endl;
				break;
			case 'i':
				controller.launchServer();
				cout << "server offline " << endl;
				break;
			case 'q':
				controller.processAction(0,0);
				controller.shutdownServer();
				return 0;
		}
	}
	controller.shutdownServer();
	return 0;
}
