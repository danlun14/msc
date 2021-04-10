#ifndef OTHER_H
#define OTHER_H

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

#endif