CC=g++
CFLAGS= -c -Wall

all: prog

prog: main.o binaryTree.o
	$(CC) main.o binaryTree.o -o evaluator -lm

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

binaryTree.o: binaryTree.cpp
	$(CC) $(CFLAGS) binaryTree.cpp

clean:
	rm -rf *.o
cleanAll:
	rm -rf *.o *.exe