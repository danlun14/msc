#include "libs/memory.h"
//
short sc_memory[100];
short registr;

int sc_memoryInit()
{
    for (int i = 0; i < 100; i++)
    {
        sc_memory[i] = 0;
    }
    return 0;
}
int sc_memorySet(int address, int value)
{
    if ((address >= 99) || (address < 0))
    {
        sc_regSet(P, 1);
        return -1;
    }
    sc_memory[address] = value;
    return 0;
}

int sc_memoryGet(int address, int *value)
{
    if ((address > 99) && (address < 0))
    {
        sc_regSet(P, 1);
        return -1;
    }
    *value = sc_memory[address];
    return 0;
}
int sc_memorySave(char *filename)
{
    FILE *ptrFile = fopen(filename, "wb");
    if (ptrFile == NULL)
    {

        return -1;
    }
    fwrite(sc_memory, 100, sizeof(short), ptrFile); // записать в файл содержимое буфера
    fclose(ptrFile);
    return 0;
}
int sc_memoryLoad(char *filename)
{
    FILE *ptrFile = fopen(filename, "rb");
    if (ptrFile == NULL)
    {
        return -1;
    }
    fread(sc_memory, 100, sizeof(short), ptrFile);
    fclose(ptrFile);
    return 0;
}
int sc_regInit(void)
{
    registr = 0;
}

int sc_regSet(int flag, int value)
{
    if ((flag < 1) || (flag > 5))
    {
        sc_regSet(P, 1);
        return -1;
    }
    if (value == 0)
    {
        registr = registr & (~(1 << (flag - 1)));
    }
    else if (value == 1)
    {
        registr = registr | (1 << (flag - 1));
    }
    else
    {
        sc_regSet(E, 1);
        return -1;
    }
    return 0;
}
int sc_regGet(int flag, int *value) //0b 0/1 0 1000101 0100110
{                                   // a  0  0 1111111 0000000 -> >> 7
    if ((flag < 1) || (flag > 5))   // b  0  0 0000000 1111111
    {
        sc_regSet(P, 1);
        return -1;
    }
    if (((registr >> (flag - 1)) | 0b11111110) == 0b11111111)
    {
        *value = 1;
    }
    else
    {
        *value = 0;
    }
    return 0;
}
int sc_commandEncode(int command, int operand, int *value)
{
    if ((command > 0x7F) || (command < 0))
    {
        sc_regSet(P, 1);
        return -1;
    }
    if ((operand > 0x7F) || (operand < 0))
    {
        sc_regSet(P, 1);
        return -1;
    }

    command = command << 7;
    *value = command + operand;
    return 0;
}
int sc_commandDecode(int value, int *command, int *operand)
{
    short checkMask = 0b0100000000000000;
    short codeMask = 0b0011111110000000;
    short operandMask = 0b0000000001111111;

    if ((checkMask & value) == 1)
    {
        sc_regSet(E, 1);
        return -1;
    }

    int temp = (codeMask & value) >> 7;
    if ((temp > 0x7F) || (temp < 0))
    {
        sc_regSet(P, 1);
        return -1;
    }
    int temp1 = temp;
    temp = operandMask & value;
    if ((temp > 0x7F) || (temp < 0))
    {
        sc_regSet(P, 1);
        return -1;
    }
    *command = temp1;
    *operand = temp;
    return 0;
}