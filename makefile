OBJ_DIR := objectsrc
SRC_DIR := libsrc
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
all: lab3 main

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c -o $@  $<

lab3: lab3.c libsrc/libs/libmyTerminal.a libsrc/libs/libbigChars.a
	gcc lab3.c -o lab3 -lmyTerminal -lbigChars -Llibsrc/libs 

main: main.c libsrc/libs/libmemory.a libsrc/libs/libmyTerminal.a libsrc/libs/libbigChars.a
	gcc main.c -o main -lmemory -lmyTerminal -lbigChars -Llibsrc/libs 

libsrc/libs/libmemory.a: objectsrc/memory.o
	ar rc libsrc/libs/libmemory.a objectsrc/memory.o

libsrc/libs/libmyTerminal.a: objectsrc/myTerminal.o
	ar rc libsrc/libs/libmyTerminal.a objectsrc/myTerminal.o

libsrc/libs/libbigChars.a: objectsrc/bigChars.o
	ar rc libsrc/libs/libbigChars.a objectsrc/bigChars.o
