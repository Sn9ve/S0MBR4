#!/bin/bash
# Indique au système que l'argument qui suit est le programme utilisé pour exécuter ce fichier
# programme de compilation du projet S0MBR4

g++ main.cpp Controller.cpp Simulator.cpp Motor.cpp Servo.cpp Sensor.cpp SocketServer.cpp -I include -DASIO_STANDALONE -o IEM
