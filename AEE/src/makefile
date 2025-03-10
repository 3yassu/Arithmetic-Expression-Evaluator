CC=g++
CFLAGS= -c -Wall

all: prog

prog: main.o
	$(CC) main.o -o evaluator -lm
	rm -rf *.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *.exe