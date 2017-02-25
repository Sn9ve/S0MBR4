#include <iostream>
#include "Controller.h"

using namespace std;

Controller::Controller(){	
	
}

//supposons que nous avons un joystick qui renvoie sur un axe X la direction droite gauche compris entre -100 et 100
//Et sur un axe y la direction avant arrière aussi compris entre -100 et 100 , pour indiquer la vitesse du robot
void Controller::processAction(int x, int y){
	int ordinate = abs(y);
	int abscissa = abs(x);	
	int turnover = sqrt(abs(x)*abs(y));
	
	//si le joystick est au point mort le robot n'avancera donc pas meme pour tourner
	robot.reset();
	if(y == 0){	
		if(x > 0){
			robot.changeSpeed(abscissa, abscissa, abscissa, abscissa);
			robot.toRight();
		} else if (x < 0) {
			robot.changeSpeed(abscissa, abscissa, abscissa, abscissa);
			robot.toLeft();
		} else {
			robot.stop();
		}
	} else {
		//sinon si la vitesse est supérieur à 0 on avance
		if(y > 0)
			robot.toFront();
		else
			robot.toBack();
		
		//si x>0 alors on tourne à droite
		if(x > 0)	
			robot.changeSpeed((turnover / 2), turnover, (turnover / 2), turnover);			
		else if (x < 0)
			robot.changeSpeed(turnover, (turnover / 2), turnover, (turnover / 2));
		else
			robot.changeSpeed(ordinate, ordinate, ordinate, ordinate);
	}
	robot.go();
	
}

int Controller::initCommunication(){
	ss.sock = ss.init_socket();
	return ss.sock;
}

int Controller::acceptClient(){
	ss.clientSock = ss.add_client(ss.sock);
	return ss.clientSock;
}

void Controller::trade(int length){
	std::cout << "trying to connect";
	char* buffer = ss.readSocket(length);
	Controller::processAction(buffer[0], buffer[1]);
}
void Controller::shutdownServer(){
	ss.closeSocket();
}


