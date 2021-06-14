OBJ_DIR := objectsrc
SRC_DIR := libsrc
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
all: main main_asm main_bsc

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c -o $@  $<

main: main.c libsrc/libs/libmemory.a libsrc/libs/libmyTerminal.a libsrc/libs/libbigChars.a libsrc/libs/libother.a libsrc/libs/libmyReadKey.a libsrc/libs/libcpu.a
	gcc main.c -o main -Llibsrc/libs -lother -lbigChars -lmyTerminal -lmemory -lmyReadKey -lcpu

main_asm: main_asm.c libsrc/libs/libmemory.a libsrc/libs/libmyTerminal.a libsrc/libs/libbigChars.a libsrc/libs/libother.a libsrc/libs/libmyReadKey.a libsrc/libs/libcpu.a libsrc/libs/libsimpleAssembler.a
	gcc main_asm.c -o main_asm -Llibsrc/libs -lother -lbigChars -lmyTerminal -lmemory -lmyReadKey -lcpu -lsimpleAssembler

main_bsc: main_bsc.c  libsrc/libs/libother.a libsrc/libs/libsimpleAssembler.a libsrc/libs/libbasic.a
	gcc main_bsc.c -o main_bsc -lbasic  -Llibsrc/libs -lother -lbigChars -lmyTerminal -lmemory -lmyReadKey -lcpu -lsimpleAssembler -lm

libsrc/libs/libmemory.a: objectsrc/memory.o
	ar rc libsrc/libs/libmemory.a objectsrc/memory.o

libsrc/libs/libmyTerminal.a: objectsrc/myTerminal.o
	ar rc libsrc/libs/libmyTerminal.a objectsrc/myTerminal.o

libsrc/libs/libbigChars.a: objectsrc/bigChars.o
	ar rc libsrc/libs/libbigChars.a objectsrc/bigChars.o

libsrc/libs/libother.a: objectsrc/other.o
	ar rc libsrc/libs/libother.a objectsrc/other.o

libsrc/libs/libmyReadKey.a: objectsrc/myReadKey.o
	ar rc libsrc/libs/libmyReadKey.a objectsrc/myReadKey.o

libsrc/libs/libcpu.a: objectsrc/cpu.o
	ar rc libsrc/libs/libcpu.a objectsrc/cpu.o

libsrc/libs/libsimpleAssembler.a: objectsrc/simpleAssembler.o
	ar rc libsrc/libs/libsimpleAssembler.a objectsrc/simpleAssembler.o

libsrc/libs/libbasic.a: objectsrc/basic.o
	ar rc libsrc/libs/libbasic.a objectsrc/basic.o

