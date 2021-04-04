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
    return 0;
}
