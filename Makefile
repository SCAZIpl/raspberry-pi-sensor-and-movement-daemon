CC = g++
CFLAGS= -pedantic-errors -std=c++98 -Wall

all:compile 
compile:
	$(CC) src/main.cpp $(CFLAGS) -o bin/raspberrydaemon.o
clean:
	rm bin/*