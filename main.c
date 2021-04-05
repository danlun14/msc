#include "libsrc/libs/memory.h"
#include "libsrc/libs/myTerminal.h"
#include <stdio.h>
#include "libsrc/libs/bigChars.h"
#include "libsrc/libs/myReadKey.h"

int intToHex(int number, char *str)
{
    if (!str || number >= 65535 || number < 0)
    {
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        str[i] = 0;
    }
    int firstChar = 0b0011100000000000;
    int secondChar = 0b0000011110000000;
    int thirdChar = 0b0000000001110000;
    int fourChar = 0b0000000000001111;
    int whole = number;
    int nums[4];
    nums[0] = (firstChar & number) >> 11;
    nums[1] = (secondChar & number) >> 7;
    nums[2] = (thirdChar & number) >> 4;
    nums[3] = (fourChar & number);
    int i;

    for (i = 3; i > -1; i--)
    {

        if (nums[i] == 10)
        {
            str[i] = 'A';
        }
        else if (nums[i] == 11)
        {
            str[i] = 'B';
        }
        else if (nums[i] == 12)
        {
            str[i] = 'C';
        }
        else if (nums[i] == 13)
        {
            str[i] = 'D';
        }
        else if (nums[i] == 14)
        {
            str[i] = 'E';
        }
        else if (nums[i] == 15)
        {
            str[i] = 'F';
        }
        else
        {
            str[i] = nums[i] + 48;
        }
    }
    return 0;
}

int main()
{
    mt_clrscr();

    sc_regInit();
    sc_memoryInit();

    mt_setbgcolor(white);
    mt_setfgcolor(black);

    int cell = 0;

    //////////////////////////////////////////che???????
    // while (1){
    if (bc_box(63, 7, 84, 10) != 0)
    {
        return 1;
    }

    mt_gotoXY(7, 69);
    printf("Operation");

    mt_gotoXY(8, 69);
    //printf("+ %02d : %02d\n", command, operand);
    if (bc_box(63, 4, 84, 7) != 0)
    {
        return 1;
    }

    mt_gotoXY(4, 64);
    printf("InstructionCounter");
    mt_gotoXY(5, 70);
    //printf("+%04d", instCount);
    if (bc_box(63, 1, 84, 4) != 0)
    {
        return 1;
    }

    mt_gotoXY(1, 68);
    printf("Accumulator");
    mt_gotoXY(2, 70);
    int accum = 22835 & 0b1011111111111111;
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
    if (bc_box(1, 1, 63, 13) != 0)
    {
        return 1;
    }

    mt_gotoXY(1, 28);
    printf("Memory");
    bc_box(1, 13, 63, 23);
    mt_gotoXY(23, 0);

    int command = 0, operand = 0, value = 0, temp = 1;
    sc_commandEncode(0x32, 0x33, &value);
    sc_memorySet(15, value);
    sc_memoryGet(15, &temp);
    printf("%d   ", temp);
    sc_commandDecode(temp, &command, &operand);
    char eprst[2];

    char cellStr[3]; //ржака
    char operandStr[3];
    intToHex(temp, cellStr);
    printf("%d |%02X %02X| %s", temp, command, operand, cellStr);
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

    int chr[2];
    chr[0] = bigMinus(0);
    chr[1] = bigMinus(1);
    bc_printbigchar(chr, 4, 14, black, white);

    chr[0] = bigFour(0);
    chr[1] = bigFour(1);
    bc_printbigchar(chr, 19, 14, black, white);

    chr[0] = bigFive(0);
    chr[1] = bigFive(1);
    bc_printbigchar(chr, 30, 14, black, white);

    chr[0] = bigSeven(0);
    chr[1] = bigSeven(1);
    bc_printbigchar(chr, 41, 14, black, white);

    chr[0] = bigNine(0);
    chr[1] = bigNine(1);
    bc_printbigchar(chr, 52, 14, black, white);
    mt_setbgcolor(white);
    mt_setfgcolor(black);
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
    printf("\E[0m");
    mt_gotoXY(24, 0);
}
