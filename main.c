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
    sc_regSet(O, 1);
    sc_regSet(T, 1);
    int command = 0, operand = 0, value = 0;
    sc_commandEncode(0x32, 0x33, &value);

    sc_memorySet(15, value);
    sc_commandEncode(0x2F, 0x37, &value);
    sc_memorySet(22, value);

    sc_commandDecode(value, &command, &operand);
    int cell = 0;
    int instCount = 0;

    enum keys key;

    enum colors setup_color = blue;
    enum colors currient_color = blue;
    while (1)
    {

        printAccumalte(value);
        printOperation(command, operand);
        printInstCount(instCount);
        printFlags();
        printKeys();

        printMemory();
        markChosenCell(cell, currient_color);
        currient_color = setup_color;
        printBoxBigChars(cell);

        //mt_gotoXY(24,0);
        rk_readKey(&key);
        if (key == 'q')
        {
            break;
        }
        if (key == RIGHT)
        {
            if ((cell + 1) % 10 != 0)
            {
                cell++;
            }
            else
            {
                currient_color = red;
            }
        }
        if (key == LEFT)
        {
            if ((cell) % 10 != 0)
            {
                cell--;
            }
            else
            {
                currient_color = red;
            }
        }
        if (key == UP)
        {
            if (cell > 9)
            {
                cell -= 10;
            }
            else
            {
                currient_color = red;
            }
        }
        if (key == DOWN)
        {
            if (cell < 90)
            {
                cell += 10;
            }
            else
            {
                currient_color = red;
            }
        }
        if (key == F5)
        {
            setup_color = blue;
        }
        if (key == F6)
        {
            setup_color = green;
        }
        instCount++;
    }
    return 0;
}
