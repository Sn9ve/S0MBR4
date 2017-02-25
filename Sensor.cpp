#include <iostream>
#include "Sensor.h"

Sensor::Sensor(){
	TRIGG = 0;
	ECHO = 0;
}

void Sensor::init(int defTRIGG, int defECHO){
	TRIGG = defTRIGG;
	ECHO = defECHO;
}

