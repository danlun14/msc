#include "mySimpleComputer.h"

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
    if ((address > 99) && (address < 0))
    {
        return -1;
    }
    sc_memory[address] = value;
    return 0;
}

int sc_memoryGet(int address, int *value)
{
    if ((address > 99) && (address < 0))
    {
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
    fread(sc_memory, 100, sizeof(short), ptrFile); // записать в файл содержимое буфера
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
        return -1;
    }
    printf("%d\n", registr);
    return 0;
}
int sc_regGet(int flag, int *value)
{
    if ((flag < 1) || (flag > 5))
    {
        return -1;
    }
    if (((registr >> (flag - 1)) | 0b11111110) == 0b11111111)
    {
        *value = 1;
    }
    *value = 0;
    printf("%d\n", registr);
    return 0;
}
//int sc_commandEncode(int command, int operand, int *value) int sc_commandDecode(int value, int *command, int *operand) * /