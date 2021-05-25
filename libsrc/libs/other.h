#ifndef OTHER_H
#define OTHER_H

#define STANDART_FILENAME "memory.bin"

#include "memory.h"
#include "myTerminal.h"
#include "bigChars.h"
#include "myReadKey.h"

#include <signal.h>
#include <sys/time.h>

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

#endif