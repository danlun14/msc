#include "libsrc/libs/memory.h"
#include "libsrc/libs/myTerminal.h"
#include <stdio.h>
#include "libsrc/libs/bigChars.h"
#include "libsrc/libs/myReadKey.h"
#include "libsrc/libs/other.h"

int main()
{
    mt_clrscr();

    sc_regInit();
    sc_memoryInit();

    int command = 0, operand = 0, value = 0, temp = 1;
    sc_commandEncode(0x32, 0x33, &value);

    sc_memorySet(15, value);
    sc_commandEncode(0x32, 0x33, &value);
    sc_memorySet(15, value);
    mt_setbgcolor(white);
    mt_setfgcolor(black);

    sc_commandDecode(value, &command, &operand);

    int instCount = 0;

    //////////////////////////////////////////che???????
    // while (1){
    //bc_box(2, 2, 3, 3);
    printAccumalte(value);
    printOperation(command, operand);
    printInstCount(instCount);
    printFlags();
    printKeys();

    printMemory();
    printBoxBigChars(15);

    mt_gotoXY(24, 0);
    mt_clearcolor();
}
