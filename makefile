all: main

main: main.c libs/libmsc.a
	gcc main.c -o main -lmsc -Llibs

libs/libmsc.a: objectsrc/msc.o
	ar rc libs/libmsc.a objectsrc/msc.o

objectsrc/msc.o: libsrc/msc.c
	gcc -c -o objectsrc/msc.o libsrc/msc.c

