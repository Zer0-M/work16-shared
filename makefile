all: shared.o
	gcc -o shared shared.o

shared.o: shared.c
	gcc -c -g shared.c

run: 
	./shared