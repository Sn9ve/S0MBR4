#!/bin/bash
# Indique au système que l'argument qui suit est le programme utilisé pour exécuter ce fichier
# programme de compilation du projet S0MBR4

g++ -std=c++1y main.cpp Controller.cpp Simulator.cpp Motor.cpp Servo.cpp Sensor.cpp SocketServer.cpp -I include -DASIO_STANDALONE -DASIO_HAS_STD_SHARED_PTR -DASIO_HAS_STD_ADDRESSOF -DASIO_HAS_STD_ARRAY -DASIO_HAS_CSTDINT -DASIO_HAS_STD_TYPE_TRAITS -o IEM
