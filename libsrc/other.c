#include "libs/other.h"
#include "libs/cpu.h"

int printMemory()
{
    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);
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

    mt_clearcolor();
    return 0;
}

int printOperation()
{
    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);
    if (bc_box(63, 7, 84, 10) != 0)
    {
        return 1;
    }

    mt_gotoXY(7, 69);
    printf("Operation");

    short cell = 0;

    int operand = 0, command = 0, value = 0;

    sc_cellGet(&cell);

    sc_memoryGet(cell, &value);
    sc_commandDecode(value, &command, &operand);

    mt_gotoXY(8, 69);
    printf("+ %02X : %02X\n", command, operand);

    mt_clearcolor();
    return 0;
}

int printAccumulate()
{
    int accum = 0;
    sc_accumulatorGet(&accum);

    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);
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
    mt_clearcolor();
    return 0;
}

int inputAccumulate()
{

    mt_setbgcolor(defaultActiveBG);
    mt_setfgcolor(defaultForgeGround);
    mt_gotoXY(19, 64);
    printf("F5 - accumulator");
    mt_clearcolor();
    mt_gotoXY(23, 0);
    printf("Input value:\n");
    int accum, result;
    scanf("%X", &accum);

    result = sc_accumulatorSet(accum);
    if (result != 0)
    {
        printf("Incorrect accumulator");
    }
    mt_gotoXY(23, 0);
}

int printInstCount()
{
    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);
    if (bc_box(63, 4, 84, 7) != 0)
    {
        return 1;
    }

    mt_gotoXY(4, 64);
    printf("InstructionCounter");
    mt_gotoXY(5, 70);
    short value;
    sc_cellGet(&value);
    printf("+%04d", value);

    mt_clearcolor();
    return 0;
}

int printFlags()
{
    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);
    if (bc_box(63, 10, 84, 13) != 0)
    {
        return 1;
    }

    mt_gotoXY(10, 71);
    printf("Flags");

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

    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);
    mt_gotoXY(11, 65);
    if (_P == 1)
    {
        mt_setbgcolor(defaultActiveBG);
    }
    printf("P", _P);

    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);
    mt_gotoXY(11, 69);
    if (_O == 1)
    {
        mt_setbgcolor(defaultActiveBG);
    }
    printf("O", _O);

    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);
    mt_gotoXY(11, 73);
    if (_M == 1)
    {
        mt_setbgcolor(defaultActiveBG);
    }
    printf("M", _M);

    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);
    mt_gotoXY(11, 77);
    if (_T == 1)
    {
        mt_setbgcolor(defaultActiveBG);
    }
    printf("T", _T);

    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);
    mt_gotoXY(11, 81);
    if (_E == 1)
    {
        mt_setbgcolor(defaultActiveBG);
    }
    printf("E", _E);

    mt_clearcolor();
    return 0;
}

int printKeys()
{
    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);
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

    mt_clearcolor();
    return 0;
}

int printBoxBigChars()
{
    short cell;
    sc_cellGet(&cell);
    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(defaultBackGround);

    if (bc_box(1, 13, 63, 23) != 0)
    {
        return 1;
    }
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

    int x;

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
        bc_printbigchar(bigChars[i], x + i * 11, 14, defaultForgeGround, defaultBackGround);
    }
    mt_gotoXY(26, 1);
    fflush(stdout);

    mt_clearcolor();

    return 0;
}

int markChosenCell(enum colors color)
{

    short cell;
    sc_cellGet(&cell);
    int y = cell % 10;
    int x = (cell - y) / 10;
    int value = 0;
    int command = 0;
    int operand = 0;
    sc_memoryGet(x * 10 + y, &value);
    sc_commandDecode(value, &command, &operand);
    mt_gotoXY(2 + x, 2 + 6 * y);
    mt_setfgcolor(defaultForgeGround);
    mt_setbgcolor(color);
    printf("+%02X%02X\n", command, operand);
    mt_clearcolor();
    mt_gotoXY(23, 0);
}

int loadMemory()
{
    mt_gotoXY(14, 64);
    mt_setbgcolor(defaultActiveBG);
    mt_setfgcolor(defaultForgeGround);
    printf("l - load");
    mt_clearcolor();
    mt_gotoXY(23, 0);
    printf("Input filename:\n");
    fflush(stdout);
    char filename[100];
    enum keys key;
    scanf("%s", filename);
    if (strcmp(filename, "STANDART_FILENAME") == 0)
    {
        strcpy(filename, STANDART_FILENAME);
    }
    if (sc_memoryLoad(filename))
    {
        mt_gotoXY(25, 0);
        printf("Error reading file");
        mt_gotoXY(26, 0);
        printf("Press any key to continue");
        fflush(stdout);
        rk_readKey(&key);
        return -1;
    }
    mt_gotoXY(25, 0);
    printf("Succsess loading");
    mt_gotoXY(26, 0);
    printf("Press any key to continue");
    fflush(stdout);
    rk_readKey(&key);
    return 0;
}

int saveMemory()
{
    mt_gotoXY(15, 64);
    mt_setbgcolor(defaultActiveBG);
    mt_setfgcolor(defaultForgeGround);
    printf("s - save");
    mt_clearcolor();
    mt_gotoXY(23, 0);
    printf("Input filename:\n");
    fflush(stdout);
    char filename[100];
    enum keys key;
    scanf("%s", filename);
    if (strcmp(filename, "STANDART_FILENAME") == 0)
    {
        strcpy(filename, STANDART_FILENAME);
    }
    if (sc_memorySave(filename))
    {
        mt_gotoXY(25, 0);
        printf("Error open file");
        mt_gotoXY(26, 0);
        printf("Press any key to continue");
        fflush(stdout);
        rk_readKey(&key);
        return -1;
    }
    mt_gotoXY(25, 0);
    printf("Succsess saving");
    mt_gotoXY(26, 0);
    printf("Press any key to continue");
    fflush(stdout);
    rk_readKey(&key);
    return 0;
}

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

        CU();
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
void step()
{
}
void runTime()
{

    struct termios default_options;
    if (tcgetattr(STDIN_FILENO, &default_options) != 0)
    {
        return;
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
    operationCountInit();
    sc_regInit();
    sc_memoryInit();
    int command = 0, operand = 0, value = 0;
    sc_commandEncode(0x40, 5, &value);
    sc_memorySet(0, value);

    sc_commandEncode(LOAD, 22, &value);
    sc_memorySet(5, value);

    sc_commandEncode(0x2F, 0x37, &value);
    sc_memorySet(22, 0x1520);

    sc_commandDecode(value, &command, &operand);
    short instCount = 0;
    setitimer(ITIMER_REAL, &nval, &oval);
    enum keys key;

    enum colors setup_color = blue;
    enum colors currient_color = blue;
    while (1)
    {
        //mt_clrscr();
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
        fflush(stdout);
        //tcsetattr(STDIN_FILENO, TCSAFLUSH, &default_options);
        if (key == 'q')
        {
            break;
        }
        else if (key == RIGHT)
        {
            if (sc_cellSet(_cell + 1) == 0)
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
            if (sc_cellSet(_cell - 1) == 0)
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
            if (sc_cellSet(_cell - 10) == 0)
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
            if (sc_cellSet(_cell + 10) == 0)
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
            mt_clrscr();
        }
        else if (key == F6)
        {
        }
        else if (key == 'l')
        {
            loadMemory();
            mt_clrscr();
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
            mt_clrscr();
        }
        else if (key == 't')
        {
            mt_gotoXY(17, 64);
            mt_setbgcolor(defaultActiveBG);
            mt_setfgcolor(defaultForgeGround);
            printf("t - step");
            mt_clearcolor();
            step();
            mt_gotoXY(23, 0);

            fflush(stdout);

            rk_readKey(&key);
            mt_clrscr();
        }
        else if (key == 'i')
        {
            mt_gotoXY(18, 64);
            mt_gotoXY(17, 64);
            mt_setbgcolor(defaultActiveBG);
            mt_setfgcolor(defaultForgeGround);
            printf("i - reset");

            sc_regInit();
            sc_memoryInit();
            //inputAccumulate();
            mt_gotoXY(23, 0);

            printf("Sucsessfull reset! Press any key to continue");
            fflush(stdout);
            rk_readKey(&key);

            mt_clrscr();
        }

        //mt_clearcolor();
    }
    //rk_mytermregime(0, 0, 0, 0, 0);
    //rk_mytermrestore();

    //if (!tcsetattr(STDIN_FILENO, TCSAFLUSH, &default_options))
}
short operationCount;
void operationCountInit()
{
    operationCount = 0;
}