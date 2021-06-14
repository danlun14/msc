#ifndef OTHER_H
#define OTHER_H

#define STANDART_FILENAME "memory.bin"

#include "memory.h"
#include "myTerminal.h"
#include "bigChars.h"
#include "myReadKey.h"

#include <ctype.h>

#include <signal.h>
#include <sys/time.h>
#include <math.h>
extern short operationCount;

void operationCountInit();
int printOperation();
int inputOperation();
int printMemory();
int printAccumulate();
int inputAccumulate();
int printInstCount();
int printFlags();
int printKeys();
int printBoxBigChars();

int markChosenCell(enum colors color);

int loadMemory();
int saveMemory();
int consoleReset();

void runTime();
void runTimeAsm();
int get_command_asm(char *command);

int m_strcmp(char *s1, char *s2);
#endif