#include "libsrc/libs/memory.h"
#include "libsrc/libs/myTerminal.h"
#include <stdio.h>
#include "libsrc/libs/bigChars.h"
#include "libsrc/libs/myReadKey.h"
#include "libsrc/libs/other.h"

int main()
{
    struct termios default_options;
    if (tcgetattr(STDIN_FILENO, &default_options) != 0)
    {
        return -1;
    }

    mt_clrscr();
    sc_accumulatorInit();
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
        mt_clrscr();
        printAccumulate();
        printOperation(command, operand);
        printInstCount(instCount);
        printFlags();
        printKeys();

        printMemory();
        markChosenCell(cell, currient_color);
        currient_color = setup_color;
        printBoxBigChars(cell);
        mt_gotoXY(23, 0);
        //mt_gotoXY(24,0);
        rk_readKey(&key);
        mt_gotoXY(23, 0);
        //tcsetattr(STDIN_FILENO, TCSAFLUSH, &default_options);
        if (key == 'q')
        {
            break;
        }
        else if (key == RIGHT)
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
        else if (key == LEFT)
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
        else if (key == UP)
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
        else if (key == DOWN)
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
        else if (key == F5)
        {
            inputAccumulate();
        }
        else if (key == F6)
        {
            inputOperation();
        }
        else if (key == 'l')
        {
            loadMemory();
        }
        else if (key == 'r')
        {
        }
        else if (key == 's')
        {
            saveMemory();
        }
        else if (key == 't')
        {
            mt_gotoXY(17, 64);
            mt_setbgcolor(defaultActiveBG);
            mt_setfgcolor(defaultForgeGround);
            printf("t - step");

            mt_clearcolor();
            mt_gotoXY(23, 0);
            fflush(stdout);
            rk_readKey(&key);
        }
        else if (key == 'i')
        {
            //inputAccumulate();
            consoleReset();
        }
        //mt_clearcolor();
        instCount++;
    }
    //rk_mytermregime(0, 0, 0, 0, 0);
    //rk_mytermrestore();

    //if (!tcsetattr(STDIN_FILENO, TCSAFLUSH, &default_options))
    //   return -1;

    mt_gotoXY(23, 0);
    return 0;
}
