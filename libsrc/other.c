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

int printBoxBigChars(int cell)
{
    bc_box(1, 13, 63, 23);
    long bigChars[5][2];

    int tmp_number = 0;

    sc_memoryGet(cell, &tmp_number);

    if (tmp_number >= 0)
    {
        bigChars[0][0] = bigPlus(0);
        bigChars[0][1] = bigPlus(1);
    }
    else
    {
        bigChars[0][0] = bigMinus(0);
        bigChars[0][1] = bigMinus(1);
        tmp_number = -tmp_number;
    }

    char buf[5];

    if (intToHex(tmp_number, buf))
    {
        return 1;
    }
    int irir = 0;
    mt_gotoXY(23, 3 + 1);
    printf("%s", buf);
    int j = 1;
    for (int i = 0; i < 4; i++)
    {
        if (buf[i] == '0')
        {
            //fflush(stdout);
            bigChars[j][0] = bigNull(0);
            bigChars[j][1] = bigNull(1);
        }
        else if (buf[i] == '1')
        {
            bigChars[j][0] = bigOne(0);
            bigChars[j][1] = bigOne(1);
        }
        else if (buf[i] == '2')
        {
            bigChars[j][0] = bigTwo(0);
            bigChars[j][1] = bigTwo(1);
        }
        else if (buf[i] == '3')
        {
            bigChars[j][0] = bigThree(0);
            bigChars[j][1] = bigThree(1);
            irir++;
        }
        else if (buf[i] == '4')
        {
            bigChars[j][0] = bigFour(0);
            bigChars[j][1] = bigFour(1);
        }
        else if (buf[i] == '5')
        {
            bigChars[j][0] = bigFive(0);
            bigChars[j][1] = bigFive(1);
        }
        else if (buf[i] == '6')
        {
            bigChars[j][0] = bigSix(0);
            bigChars[j][1] = bigSix(1);
        }
        else if (buf[i] == '7')
        {
            bigChars[j][0] = bigSeven(0);
            bigChars[j][1] = bigSeven(1);
        }
        else if (buf[i] == '8')
        {
            bigChars[j][0] = bigEight(0);
            bigChars[j][1] = bigEight(1);
        }
        else if (buf[i] == '9')
        {
            bigChars[j][0] = bigNine(0);
            bigChars[j][1] = bigNine(1);
        }
        else if (buf[i] == 'A')
        {
            bigChars[j][0] = bigA(0);
            bigChars[j][1] = bigA(1);
        }
        else if (buf[i] == 'B')
        {
            bigChars[j][0] = bigB(0);
            bigChars[j][1] = bigB(1);
        }
        else if (buf[i] == 'C')
        {
            bigChars[j][0] = bigC(0);
            bigChars[j][1] = bigC(1);
        }
        else if (buf[i] == 'D')
        {
            bigChars[j][0] = bigD(0);
            bigChars[j][1] = bigD(1);
        }
        else if (buf[i] == 'E')
        {
            bigChars[j][0] = bigE(0);
            bigChars[j][1] = bigE(1);
        }
        else if (buf[i] == 'F')
        {
            bigChars[j][0] = bigF(0);
            bigChars[j][1] = bigF(1);
        }
        else
        {
            bigChars[j][0] = bigNull(0);
            bigChars[j][1] = bigNull(1);
        }
        j++;
    }

    mt_gotoXY(23, 2);
    printf("%d", irir);
    int x;
    enum colors fg = black;
    enum colors bg = white;

    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            x = 4;
        }
        else
        {
            x = 8;
        }
        bc_printbigchar(bigChars[i], x + i * 11, 14, fg, bg);
    }

    mt_gotoXY(26, 1);
    fflush(stdout);

    return 0;
}
