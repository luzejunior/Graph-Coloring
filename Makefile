CC = g++
FLAGS = -std=c++11

program: src/*.cpp src/*.h Makefile main.cpp
	$(CC) $(FLAGS) src/*.h src/*.cpp main.cpp -o program

run:
	./program
