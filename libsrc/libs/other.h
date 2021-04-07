#ifndef OTHER_H
#define OTHER_H

#include "memory.h"
#include "myTerminal.h"
#include "bigChars.h"

int printOperation();
int printMemory();
int printAccumalte(int accum);
int printInstCount(int instCount);
int printFlags();
int printKeys();
int printBoxBigChars(int cell);

int markChosenCell(int cell, enum colors color);

#endif