#!/bin/bash

g++ -c main.cpp -L main.hpp
g++ main.o -o app -lsfml-graphics -lsfml-window -lsfml-system
