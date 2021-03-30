#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>

#define P 1
#define O 2
#define M 3
#define T 4
#define E 5

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int *value);
int sc_memorySave(char *filename);
int sc_memoryLoad(char *filename);
int sc_regInit(void);
int sc_regSet(int register, int value);
int sc_regGet(int register, int *value);
int sc_commandEncode(int command, int operand, int *value);
int sc_commandDecode(int value, int *command, int *operand);

#endif