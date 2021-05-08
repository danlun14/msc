#ifndef CPU_H
#define CPU_H

#include "other.h"
#include "myReadKey.h"

#define READ 0x10
#define WRITE 0x11

#define LOAD 0x20
#define STORE 0x21

#define ADD 0x30
#define SUB 0x31
#define DIVIDE 0x32
#define MUL 0x33

#define JUMP 0x40
#define JNEG 0x41
#define JZ 0x42
#define JB 0x44
#define SET 0x78
#define HALT 0x43

int ALU(int command, int operand);
int CU();

#endif