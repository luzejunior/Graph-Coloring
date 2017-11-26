CC = g++
FLAGS = -std=c++11

program: src/*.cpp src/*.hpp Makefile main.cpp
	$(CC) $(FLAGS) main.cpp src/*.cpp -o program

run:
	./program
