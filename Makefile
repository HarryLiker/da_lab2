CC=g++

CFLAGS=--std=c++14 -c -O3

all: solution

solution: main.o functions.o menu.o
	$(CC) main.o functions.o menu.o -o solution

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

functions.o: functions.cpp
	$(CC) $(CFLAGS) functions.cpp

menu.o: menu.cpp
	$(CC) $(CFLAGS) menu.cpp

clean:
	rm -rf *.o solution

