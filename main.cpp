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
	cout << "a --> Accelerate" << endl;
	cout << "d --> Slow down" << endl;
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
			case 'a':
				controller.robot.accelerate();
				break;
			case 'd':
				controller.robot.slowDown();
				break;
			case 't':
				cout << "la distance entre le robot est un obstacle est de " 
				<< controller.robot.proceesDistance(1) << endl;
				break;
			case 'i':
				if(controller.initCommunication() >= 0){
					while(controller.acceptClient() >= 0){
						cout << "Listening for command" << endl;
						controller.trade(2);
					}
				}else 
					cout << "error init connection" << endl;
				cout << "pass the while";
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
