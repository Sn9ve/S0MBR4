#include "Motor.h"
#include "Servo.h"
#include "Sensor.h"

#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NBMOTOR 4
#define NBSERVO 2
#define NBSENSOR 2

enum{	AvG, AvD, ArG, ArD	};
enum{	front, back	};

class Robot{
	public:
		Motor* motors;
		Servo* servos;
		Sensor* sensors;	
		
		Simulator();
		void initMotor();
		void initSensor();
		void toFront();
		void toBack();
		void toRight();
		void toLeft();
		void slowDown();
		void accelerate();
		void stop();
		void reset();
		void changeSpeed(int vAvG, int vAvD, int vArG, int vArD);	
		void move();
};
