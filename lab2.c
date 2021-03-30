#include <stdio.h>
#include "libsrc/libs/memory.h"
#include "libsrc/libs/myTerminal.h"
#include "libsrc/libs/bigChars.h"

int main()
{

    mt_clrscr();
    mt_setbgcolor(black);
    bc_box(5, 10, 15, 20);
    int bigChar[2];
    bigChar[0] = bigFour(0);
    bigChar[1] = bigFour(1);
    bc_printbigchar(bigChar, 6, 11, 7, 0);
    mt_gotoXY(21, 0);
    bc_box(1, 13, 63, 23);

    int chr[2];
    chr[0] = bigPlus(0);
    chr[1] = bigPlus(1);
    bc_printbigchar(chr, 4, 14, 4, 7);

    chr[0] = bigD(0);
    chr[1] = bigD(1);
    bc_printbigchar(chr, 19, 14, 4, 7);

    chr[0] = bigE(0);
    chr[1] = bigE(1);
    bc_printbigchar(chr, 30, 14, 4, 7);

    chr[0] = bigA(0);
    chr[1] = bigA(1);
    bc_printbigchar(chr, 41, 14, 4, 7);

    chr[0] = bigD(0);
    chr[1] = bigD(1);
    bc_printbigchar(chr, 52, 14, 4, 7);
    return 0;
}
