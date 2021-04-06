OBJ_DIR := objectsrc
SRC_DIR := libsrc
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
all: lab3 main

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c -o $@  $<

main: main.c libsrc/libs/libmemory.a libsrc/libs/libmyTerminal.a libsrc/libs/libbigChars.a libsrc/libs/libother.a
	gcc main.c -o main -lmemory -lmyTerminal -lbigChars -lother -Llibsrc/libs 

libsrc/libs/libmemory.a: objectsrc/memory.o
	ar rc libsrc/libs/libmemory.a objectsrc/memory.o

libsrc/libs/libmyTerminal.a: objectsrc/myTerminal.o
	ar rc libsrc/libs/libmyTerminal.a objectsrc/myTerminal.o

libsrc/libs/libbigChars.a: objectsrc/bigChars.o
	ar rc libsrc/libs/libbigChars.a objectsrc/bigChars.o

libsrc/libs/libother.a: objectsrc/other.o
	ar rc libsrc/libs/libother.a objectsrc/other.o
