#include <iostream>
#include "Robot.h"

Robot::Robot(){
	motors = new Motor[NBMOTOR];
	servos = new Servo[NBSERVO];
	sensors = new Sensor[NBSENSOR];
	
	wiringPiSetup();	
	initMotor();
	initSensor();
}

void Robot::initMotor(){
	motors[AvG].init(0, 2, 3, 40, false);
	motors[AvD].init(1, 4, 5, 40, true);
	motors[ArG].init(12, 13, 14, 40, false);
	motors[ArD].init(6, 10, 11, 40, true);

	for(int i = 0; i <= 3; ++i){
		if(softPwmCreate(motors[i].PWM, 0, 100) != 0)
			std::cout << "error" << std::endl;

		pinMode(motors[i].IN1, OUTPUT);
		pinMode(motors[i].IN2, OUTPUT);
		digitalWrite(motors[i].IN1, LOW);
		digitalWrite(motors[i].IN2, LOW);
	}
}

void Robot::toFront(){
	for(int i = 0; i <= 3; ++i){
		if(motors[i].inverted == true)
			digitalWrite(motors[i].IN1, HIGH);
		else
			digitalWrite(motors[i].IN2, HIGH);
	}
}

void Robot::toBack(){
	for(int i = 0; i <= 3; ++i)		{
		if(motors[i].inverted == true)
			digitalWrite(motors[i].IN2, HIGH);
		else
			digitalWrite(motors[i].IN1, HIGH);
	}
}

void Robot::toRight()	{
	for(int i = 0; i <= 3; ++i)
		digitalWrite(motors[i].IN1, HIGH);
}


void Robot::toLeft()	{
	for(int i = 0; i <= 3; ++i)
		digitalWrite(motors[i].IN2, HIGH);
}

//accélère d'un dixième de sa vitesse max
void Robot::accelerate(){
	for(int i = 0; i <= 3; ++i){	
		if(motors[i].speed<91)
			motors[i].speed += 10;
		else
			motors[i].speed = 100;

		softPwmWrite(motors[i].PWM, motors[i].speed);
	}
}

//Ralenti d'un dixième de sa vitesse max
void Robot::slowDown(){
	for(int i = 0; i <= 3; ++i)		{	
		if(motors[i].speed>10)
		motors[i].speed = motors[i].speed-10;

		softPwmWrite(motors[i].PWM, motors[i].speed);
	}

}

//Arrête les moteurs
void Robot::stop(){
	for(int i = 0; i <= 3; ++i)
		digitalWrite(motors[i].PWM, LOW);
}

//Remet tout les IN en état LOW
void Robot::reset(){
	for(int i = 0; i <= 3; ++i){
		digitalWrite(motors[i].IN1, LOW);
		digitalWrite(motors[i].IN2, LOW);
	}
}

void Robot::changeSpeed(int vAvG, int vAvD, int vArG, int vArD){
	motors[AvG].speed = vAvG;
	motors[AvD].speed = vArD;
	motors[ArG].speed = vArG;
	motors[ArD].speed = vArD;
}

//Lance les roues à la vitesse indiqué	
void Robot::go(){
	for(int i = 0; i <= 3; ++i)
		softPwmWrite(motors[i].PWM, motors[i].speed);
}


void Robot::initSensor(){
	sensors[front].init(22, 29);
	sensors[back].init(21, 28);
	
	for(int i = 0; i <= 1; ++i){
		pinMode(sensors[i].TRIGG, OUTPUT);
		pinMode(sensors[i].ECHO, INPUT);
		digitalWrite(sensors[i].TRIGG, LOW);
	}
}

int Robot::proceesDistance(int pos){
	long start, end;
	while(1){
		digitalWrite(sensors[pos].TRIGG, HIGH);
		std::cout << "trigger time = " << start << std::endl;
		sleep(0.000001);
		digitalWrite(sensors[pos].TRIGG, LOW);
		
		while(digitalRead(sensors[pos].ECHO)==LOW)
			start = clock();
		while(digitalRead(sensors[pos].ECHO)==HIGH)
			end = clock();
		int Distance = ((end - start) * 34029) / 2000000; // on divise par 210010000 pour l'allé retour ainsi que les milliseconde
		std::cout << "ECHO read" << std::endl;
		return Distance;
	} 
}
