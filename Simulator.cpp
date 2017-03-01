#include <iostream>
#include "Simulator.h"

using namespace std;

Simulator::Simulator(){
	cout << "/////////////////////////////////////////////////////////////////////////////////" <<  endl;
	cout << "initiating the robot --> " << NBMOTOR << " Motor - " 
			  << NBSENSOR << " Sensor - " 
			  << NBSERVO << " Servo" << endl;
			  
	motors = new Motor[NBMOTOR];
	servos = new Servo[NBSERVO];
	sensors = new Sensor[NBSENSOR];
	
	initMotor();
	initSensor();
}

void Simulator::initMotor(){
	cout << "---------------------------INITIATING MOTOR------------------------------------" <<  endl;
	motors[AvG].init(0, 2, 3, 40, false);
	motors[AvD].init(1, 4, 5, 40, true);
	motors[ArG].init(12, 13, 14, 40, false);
	motors[ArD].init(6, 10, 11, 40, true);

	for(int i = 0; i <= 3; ++i){
		cout << "softPwmCreate --> Motor n°" << i << " PWM[" 
			 << motors[i].IN1 << "] create range 0 to 100 else error" << endl;
		cout << "pinMode --> Motor n°" << i << " IN1[" 
			 << motors[i].IN1 << "] put to OUTPUT" << endl;
		cout << "pinMode --> Motor n°" << i << " IN2[" 
			 << motors[i].IN2 << "] put to OUTPUT" << endl;	
		cout << "digitalWrite --> Motor n°" << i << " IN1[" 
			 << motors[i].IN1 << "] put to LOW" << endl;
		cout << "digitalWrite --> Motor n°" << i << " IN2[" 
			 << motors[i].IN2 << "] put to LOW" << endl;
	}
}

void Simulator::initSensor(){
	cout << "---------------------------INITIATING SENSOR------------------------------------" <<  endl;
	sensors[front].init(22, 29);
	sensors[back].init(21, 28);
	
	for(int i = 0; i <= 1; ++i){
		cout << "pinMode --> SENSOR n°" << i << " TRIGG[" 
			 << sensors[i].TRIGG << "] put to OUTPUT" << endl;
		cout << "pinMode --> SENSOR n°" << i << " ECHO[" 
			 << sensors[i].ECHO << "] put to INPUT" << endl;	
		cout << "digitalWrite --> SENSOR n°" << i << " TRIGG[" 
			 << sensors[i].TRIGG << "] put to LOW" << endl;
	}
}

void Simulator::toFront(){
	cout << "------------------------------------FORWARD--------------------------------------" <<  endl;
	for(int i = 0; i <= 3; ++i){
		if(motors[i].inverted == true)
			cout << "digital Write --> Motor n°" << i << " IN1[" 
				 << motors[i].IN1 << "] put to HIGH " << endl;
		else
			cout << "digital Write --> Motor n°" << i << " IN2[" 
				 << motors[i].IN2 << "] put to HIGH " << endl;
	}
	cout << " S0MBR4 is ready to move forward " << endl;
}

void Simulator::toBack(){
	cout << "-------------------------------------BACKWARD------------------------------------" <<  endl;
	for(int i = 0; i <= 3; ++i)		{
		if(motors[i].inverted == true)
			cout << "digital Write --> Motor n°" << i << " IN2[" 
				 << motors[i].IN2 << "] put to HIGH " << endl;
		else
			cout << "digital Write --> Motor n°" << i << " IN1[" 
				 << motors[i].IN1 << "] put to HIGH " << endl;
	}
	cout << " S0MBR4 is ready to move back " << endl;
}

void Simulator::toRight()	{
	cout << "--------------------------------------RIGHT--------------------------------------" <<  endl;
	for(int i = 0; i <= 3; ++i){
		cout << "digital Write --> Motor n°" << i << " IN1[" 
			 << motors[i].IN1 << "] put to HIGH " << endl;
	}
	cout << " S0MBR4 is ready to turn right  " << endl;
}


void Simulator::toLeft()	{
	cout << "--------------------------------------LEFT---------------------------------------" <<  endl;
	for(int i = 0; i <= 3; ++i){
		cout << "digital Write --> Motor n°" << i << " IN2[" 
			 << motors[i].IN2 << "] put to HIGH " << endl;
	}
	cout << " S0MBR4 is ready to turn left " << endl;
}

//accélère d'un dixième de sa vitesse max
void Simulator::accelerate(){
	cout << "-------------------------------------SPEED UP------------------------------------" <<  endl;
	for(int i = 0; i <= 3; ++i){
		String oldSpeed = motors[i].speed;	
		if(motors[i].speed < 91){
			motors[i].speed += 10;
		} else {
			motors[i].speed = 100;
		}
		cout << "softPwmWrite --> Motor n°" << i << " PWM[" 
			 << motors[i].PWM << "] change from " << oldSpeed 
			 << " to " << motors[i].speed << endl;
	}
	cout << " S0MBR4 is ready to speed up " << endl;
}

//Ralenti d'un dixième de sa vitesse max
void Simulator::slowDown(){
	cout << "-------------------------------------SLOW SOWN-----------------------------------" <<  endl;
	for(int i = 0; i <= 3; ++i)		{
		String oldSpeed = motors[i].speed;		
		if(motors[i].speed > 10)
			motors[i].speed -= 10;
		cout << "softPwmWrite --> Motor n°" << i << " PWM[" 
			 << motors[i].PWM << "] change from " << oldSpeed 
			 << " to " << motors[i].speed << endl;
	}
	cout << " S0MBR4 is ready to slow down " << endl;
}

//Arrête les moteurs
void Simulator::stop(){
	cout << "-------------------------------------STOP----------------------------------------" <<  endl;
	for(int i = 0; i <= 3; ++i){
		cout << "digital Write --> Motor n°" << i << " PWM[" 
			 << motors[i].PWM << "] put to 0 " << endl;
	}
	cout << "S0MBR4 is reset " << endl;
}

//Remet tout les IN en état LOW
void Simulator::reset(){
	cout << "-------------------------------------RESET---------------------------------------" <<  endl;
	for(int i = 0; i <= 3; ++i){
		cout << "digital Write --> Motor n°" << i << " IN1[" 
			 << motors[i].IN1 << "] put to LOW " << endl;
		cout << "digital Write --> Motor n°" << i << " IN2[" 
			 << motors[i].IN2 << "] put to LOW " << endl;
	}
	cout << "S0MBR4 is reset " << endl;
}

void Simulator::changeSpeed(int vAvG, int vAvD, int vArG, int vArD){
	cout << "-------------------------------------CHANGE SPEED-------------------------------------" <<  endl;
	cout << "Motor AvG = " << vAvG << endl;
	motors[AvG].speed = vAvG;
	cout << "Motor AvD = " << vAvD << endl;
	motors[AvD].speed = vArD;
	cout << "Motor ArG = " << vArG << endl;
	motors[ArG].speed = vArG;
	cout << "Motor ArD = " << vArD << endl;
	motors[ArD].speed = vArD;	
	cout << "the speed of the Motors changed " << endl;
}

//Lance les roues à la vitesse indiqué	
void Simulator::move(){
	cout << "-------------------------------------MOVE-------------------------------------" <<  endl;
	for(int i = 0; i <= 3; ++i){
		cout << "softPwmWrite --> Motor n°" << i << " PWM[" 
			 << motors[i].PWM << "] put to " << motors[i].speed << endl;
	}
	cout << "S0MBR4 is moving..." << endl;
}
