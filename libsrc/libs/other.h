#ifndef OTHER_H
#define OTHER_H

#define STANDART_FILENAME "memory.bin"

#include "memory.h"
#include "myTerminal.h"
#include "bigChars.h"
#include "myReadKey.h"

int printOperation();
int inputOperation();
int printMemory();
int printAccumulate();
int inputAccumulate();
int printInstCount(int instCount);
int printFlags();
int printKeys();
int printBoxBigChars(int cell);

int markChosenCell(int cell, enum colors color);

int loadMemory();
int saveMemory();
int consoleReset();

#endif