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
	/*robot.reset();
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
	robot.go();*/
}

void Controller::processSimulation(int x, int y){
	int ordinate = abs(y);
	int abscissa = abs(x);	
	int turnover = sqrt(abs(x)*abs(y));
	
	//si le joystick est au point mort le robot n'avancera donc pas meme pour tourner
	dumbRob.reset();
	if(y == 0){	
		if(x > 0){
			dumbRob.changeSpeed(abscissa, abscissa, abscissa, abscissa);
			dumbRob.toRight();
		} else if (x < 0) {
			dumbRob.changeSpeed(abscissa, abscissa, abscissa, abscissa);
			dumbRob.toLeft();
		} else {
			dumbRob.stop();
		}
	} else {
		//sinon si la vitesse est supérieur à 0 on avance
		if(y > 0)
			dumbRob.toFront();
		else
			dumbRob.toBack();
		
		//si x>0 alors on tourne à droite
		if(x > 0)	
			dumbRob.changeSpeed((turnover / 2), turnover, (turnover / 2), turnover);			
		else if (x < 0)
			dumbRob.changeSpeed(turnover, (turnover / 2), turnover, (turnover / 2));
		else
			dumbRob.changeSpeed(ordinate, ordinate, ordinate, ordinate);
	}
	dumbRob.move();
}

int Controller::launchServer(){
	serverListener();
	return 0;
}


