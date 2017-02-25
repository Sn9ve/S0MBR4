#include <iostream>
#include "Motor.h"

Motor::Motor(){
	IN1 = 0;
	IN2 = 0;
	PWM = 0;
	speed = 0;
	inverted = false;
}

void Motor::init(int defPWM, int defIN1, int defIN2, int defSpeed, bool defInverted){
	PWM = defPWM;
	IN1 = defIN1;
	IN2 = defIN2;
	speed = defSpeed;
	inverted = defInverted;
}
