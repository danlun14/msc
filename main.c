#include "libsrc/libs/memory.h"
#include "libsrc/libs/myTerminal.h"
#include <stdio.h>
#include "libsrc/libs/bigChars.h"

int main()
{
    int tempValue = 0b0010000010011111;
    int tempReg = 0;
    sc_regInit();
    for (int i = 0; i < 100; i++)
    {
        sc_memoryGet(i, &tempValue);
        printf("%d", tempValue);
    }
    printf("\n");
    sc_memorySet(98, 115);
    for (int i = 0; i < 100; i++)
    {
        sc_memoryGet(i, &tempValue);
        printf("%d", tempValue);
    }
    sc_memoryInit();
    sc_memoryGet(3, &tempValue);
    printf("%d\n", tempValue);
    sc_memorySave("memory.bin");
    sc_memorySet(3, 15);
    sc_memoryLoad("memory.bin");
    sc_memoryGet(3, &tempValue);
    printf("%d\n", tempValue);
    printf("\nreg:\n\n");
    sc_regGet(P, &tempReg);
    printf("%d\n", tempReg);
    sc_regGet(O, &tempReg);
    printf("%d\n", tempReg);
    sc_regGet(M, &tempReg);
    printf("%d\n", tempReg);
    sc_regGet(T, &tempReg);
    printf("%d\n", tempReg);
    sc_regGet(E, &tempReg);
    printf("%d\n", tempReg);
    printf("\ncode/encode\n");
    sc_commandEncode(10, 15, &tempValue);
    //sc_commandDecode(100000,&tempValue,&tempReg);

    sc_regGet(P, &tempReg);
    printf("\n%d\n", tempReg);
    sc_regGet(O, &tempReg);
    printf("%d\n", tempReg);
    sc_regGet(M, &tempReg);
    printf("%d\n", tempReg);
    sc_regGet(T, &tempReg);
    printf("%d\n", tempReg);
    sc_regGet(E, &tempReg);
    printf("%d\n\n", tempReg);
    sc_commandDecode(tempValue, &tempReg, &tempValue);
    printf("%d\n", tempReg);
    printf("%d\n", tempValue);
    mt_setbgcolor(white);
    mt_setfgcolor(black);
    bc_box(1, 13, 63, 23);

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
    int _OD;
    sc_regGet(P, &_OD);
    int _DE;
    sc_regGet(O, &_DE);
    int _EG;
    sc_regGet(M, &_EG);
    int _CI;
    sc_regGet(T, &_CI);
    int _IC;
    sc_regGet(E, &_IC);
    printf("D-%d E-%d G-%d I-%d C-%d", _OD, _DE, _EG, _CI, _IC);
}