#include "libsrc/libs/memory.h"
#include "libsrc/libs/myTerminal.h"
#include <stdio.h>
#include "libsrc/libs/bigChars.h"
#include "libsrc/libs/myReadKey.h"
#include "libsrc/libs/other.h"

#include <signal.h>
#include <sys/time.h>

void signalhandler(int signo)
{
    int reg = 0;
    sc_regGet(E, &reg);
    if (reg == 1)
    {
        mt_clrscr();
        printAccumulate();
        printOperation();
        printInstCount();
        printFlags();
        printKeys();
        //fflush(stdout);

        printMemory();
        printBoxBigChars();

        markChosenCell(blue);
        return;
    }
    if (signo == SIGALRM)
    {

        if (sc_cellSet(1) != 0)
        {
            sc_regSet(E, 1);
            sc_cellInit();
        }
        mt_clrscr();
        printAccumulate();
        printOperation();
        printInstCount();
        printFlags();
        printKeys();
        mt_setfgcolor(black);
        mt_setbgcolor(cyan);
        mt_gotoXY(16, 64);
        printf("r - run");
        mt_clearcolor();
        //fflush(stdout);

        printMemory();
        printBoxBigChars();

        markChosenCell(green);
    }
}

int main()
{
    struct termios default_options;
    if (tcgetattr(STDIN_FILENO, &default_options) != 0)
    {
        return -1;
    }

    struct sigaction act;
    act.sa_handler = &signalhandler;
    act.sa_flags = SA_RESTART;

    sigemptyset(&act.sa_mask);

    sigaction(SIGALRM, &act, NULL);

    struct itimerval nval, oval;

    //signal(SIGALRM, signalhandler);

    nval.it_interval.tv_sec = 0;
    nval.it_interval.tv_usec = 0;
    nval.it_value.tv_sec = 0;
    nval.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &nval, &oval);
    //    while(1){
    //    }

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
    short instCount = 0;
    setitimer(ITIMER_REAL, &nval, &oval);
    enum keys key;

    enum colors setup_color = blue;
    enum colors currient_color = blue;
    while (1)
    {
        mt_clrscr();
        printAccumulate();
        printOperation();
        printInstCount();
        printFlags();
        printKeys();

        printMemory();
        printBoxBigChars();

        markChosenCell(currient_color);

        currient_color = setup_color;
        mt_gotoXY(23, 0);
        //mt_gotoXY(24,0);
        rk_readKey(&key);
        nval.it_interval.tv_sec = 0;
        nval.it_interval.tv_usec = 0;
        nval.it_value.tv_sec = 0;
        nval.it_value.tv_usec = 0;

        setitimer(ITIMER_REAL, &nval, &oval);
        mt_gotoXY(23, 0);
        //tcsetattr(STDIN_FILENO, TCSAFLUSH, &default_options);
        if (key == 'q')
        {
            break;
        }
        else if (key == RIGHT)
        {
            if (sc_cellSet(1) == 0)
            {
            }
            else
            {
                currient_color = red;
            }
            sc_cellGet(&instCount);
        }
        else if (key == LEFT)
        {
            if (sc_cellSet(-1) == 0)
            {
            }
            else
            {
                currient_color = red;
            }
            sc_cellGet(&instCount);
        }
        else if (key == UP)
        {
            if (sc_cellSet(-10) == 0)
            {
            }
            else
            {
                currient_color = red;
            }
            sc_cellGet(&instCount);
        }
        else if (key == DOWN)
        {
            if (sc_cellSet(10) == 0)
            {
            }
            else
            {
                currient_color = red;
            }
            sc_cellGet(&instCount);
        }
        else if (key == F5)
        {
            inputAccumulate();
        }
        else if (key == F6)
        {
        }
        else if (key == 'l')
        {
            loadMemory();
        }
        else if (key == 'r')
        {
            int reg = 0;
            sc_regGet(E, &reg);
            if (reg != 1)
            {
                nval.it_interval.tv_sec = 1;
                nval.it_value.tv_sec = 1;
                //sigaction(ITIMER_REAL, &act, NULL);
                setitimer(ITIMER_REAL, &nval, &oval);
            }
            //rk_readKey(&key);
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
            sc_memoryInit();
            //inputAccumulate();
            mt_gotoXY(23, 0);
            rk_readKey(&key);
        }
        //mt_clearcolor();
    }
    //rk_mytermregime(0, 0, 0, 0, 0);
    //rk_mytermrestore();

    //if (!tcsetattr(STDIN_FILENO, TCSAFLUSH, &default_options))
    //   return -1;

    mt_gotoXY(23, 0);
    mt_clearcolor();
    return 0;
}
