CC=g++
CFLAGS= -c -Wall

all: prog

prog: main.o
	$(CC) main.o -o evaluator -lm

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *.o
cleanAll:
	rm -rf *.o *.exe