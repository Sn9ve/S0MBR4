#!/bin/bash
# Indique au système que l'argument qui suit est le programme utilisé pour exécuter ce fichier
# programme de compilation du projet S0MBR4

g++ main.cpp Controller.cpp Robot.cpp Motor.cpp Servo.cpp Sensor.cpp Server.cpp -I include -o IEM -lwiringPi -lpthread
