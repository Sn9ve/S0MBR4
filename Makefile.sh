#!/bin/bash
# Indique au système que l'argument qui suit est le programme utilisé pour exécuter ce fichier
# programme de compilation du projet S0MBR4

g++ main.cpp Controller.cpp Robot.cpp Simulator.cpp Motor.cpp Servo.cpp Sensor.cpp SocketServer.cpp -o IEM -lwiringPi -lpthread
