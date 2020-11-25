CC=g++
FLAGS=-std=c++14 -pedantic -Wall -Wextra -Wno-unused-variable
OUTPUT=lab2

all: menu.o functions.o main.cpp
	$(CC) $(FLAGS) menu.o functions.o main.cpp -o $(OUTPUT)
menu.o: menu.cpp menu.hpp work_with_files.hpp RBTree.hpp
	$(CC) $(FLAGS) -c menu.cpp
functions.o: functions.cpp functions.hpp
	$(CC) $(FLAGS) -c functions.cpp
clean:
	rm -rf *.o $(OUTPUT)