#include "libs/other.h"

int printMemory()
{
    mt_gotoXY(1, 28);
    printf("Memory");
    if (bc_box(1, 1, 63, 13) != 0)
    {
        return 1;
    }
    int value = 0, operand = 0, command = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            sc_memoryGet(i * 10 + j, &value);
            sc_commandDecode(value, &command, &operand);
            mt_gotoXY(2 + i, 2 + 6 * j);
            printf("+%02X%02X\n", command, operand);
        }
    }
}

int printOperation(int command, int operand)
{
    if (bc_box(63, 7, 84, 10) != 0)
    {
        return 1;
    }

    mt_gotoXY(7, 69);
    printf("Operation");

    mt_gotoXY(8, 69);
    printf("+ %02X : %02X\n", command, operand);
}

int printAccumalte(int accum)
{
    if (bc_box(63, 1, 84, 4) != 0)
    {
        return 1;
    }

    mt_gotoXY(1, 68);
    printf("Accumulator");
    mt_gotoXY(2, 70);

    if (accum < 65536)
    {
        int tmp = accum;
        if (tmp >= 0)
        {
            printf("+%04X", tmp);
        }
        else
        {
            printf("-%04X", tmp * -1);
        }
    }

    return 0;
}

int printInstCount(int instCount)
{
    if (bc_box(63, 4, 84, 7) != 0)
    {
        return 1;
    }

    mt_gotoXY(4, 64);
    printf("InstructionCounter");
    mt_gotoXY(5, 70);
    printf("+%04d", instCount);

    bc_box(1, 13, 63, 23);
}

int printFlags()
{
    if (bc_box(63, 10, 84, 13) != 0)
    {
        return 1;
    }

    mt_gotoXY(10, 71);
    printf("Flags");
    mt_gotoXY(11, 64);
    int _P;
    sc_regGet(P, &_P);
    int _O;
    sc_regGet(O, &_O);
    int _M;
    sc_regGet(M, &_M);
    int _T;
    sc_regGet(T, &_T);
    int _E;
    sc_regGet(E, &_E);
    printf("P-%d O-%d M-%d T-%d E-%d", _P, _O, _M, _T, _E);
}

int printKeys()
{
    if (bc_box(63, 13, 84, 23) != 0)
    {
        return 1;
    }

    mt_gotoXY(13, 64);
    printf("Keys:");
    mt_gotoXY(14, 64);
    printf("l - load");
    mt_gotoXY(15, 64);
    printf("s - save");
    mt_gotoXY(16, 64);
    printf("r - run");
    mt_gotoXY(17, 64);
    printf("t - step");
    mt_gotoXY(18, 64);
    printf("i - reset");
    mt_gotoXY(19, 64);
    printf("F5 - accumulator");
    mt_gotoXY(20, 64);
    printf("F6 - instrCounter");
}
