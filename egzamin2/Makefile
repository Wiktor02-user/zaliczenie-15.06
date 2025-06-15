LIBRARY_DIR = lib


all: manager worker main

manager: manager.c
	gcc -o -c manager.c -o manager.o
	ar rcs libmanager.a manager.o

worker: worker.c
	gcc -o -c worker.c -o worker.o
	ar rcs libworker.a worker.o

main: main.c libmanager.a libworker.a
	gcc -o main.c -L. -lmanager -lworker -o projekt


