#include "libs/cpu.h"
int numStrForLogs = 0;
int ALU(int command, int operand)
{
    if (operand > 99)
    {
        return 1;
    }
    int number = 0;

    sc_memoryGet(operand, &number);
    switch (command)
    {
    case ADD:
        if ((_accum + number) >= 65535)
        {
            sc_regSet(P, 1);
            break;
        }
        _accum += number;
        break;
    case SUB:
        if ((_accum - number) < -65534)
        {
            sc_regSet(P, 1);
            break;
        }
        _accum -= number;
        break;
    case DIVIDE:
        if (number == 0 || _accum == 0)
        {
            sc_regSet(O, 1);
            break;
        }
        _accum /= number;
        break;
    case MUL:
        if ((_accum * number) >= 65535)
        {
            sc_regSet(P, 1);
            break;
        }
        _accum *= number;
        break;
    default:
        return 1;
    }
    return 0;
}

int CU()
{
    int value = 0;
    int command = 40;
    int operand = 0;
    mt_gotoXY(24, 0);

    sc_memoryGet(_cell, &value);
    // printf("%4X\n", value);
    if (sc_commandDecode(value, &command, &operand))
    {
        sc_regSet(E, 1);
        return 1;
    }
    //command = 0x40;
    //mt_gotoXY(23, 0);
    //printf("+ %02X : %02X\n", command, operand);
    if (command > 0x33 || command < 0x30)
    {
        switch (command)
        {
        case READ:
            mt_gotoXY(24 + numStrForLogs, 1);
            printf("< ");
            int tmp = 0;
            scanf("%d", &tmp);
            printf("\n");
            if (tmp > 65535)
            {
                sc_regSet(P, 1);
                break;
            }

            sc_memorySet(operand, tmp);
            break;
        case WRITE:
            mt_gotoXY(26 + numStrForLogs, 1);
            sc_memoryGet(operand, &value);
            printf(">%d\n", value);
            break;
        case LOAD:
            sc_memoryGet(operand, &value);
            //sc_regSet(T, 1);
            _accum = value;
            break;
        case STORE:
            value = _accum;
            sc_memorySet(operand, value);
            break;

        case JUMP:

            if (operand > 99 || operand < 0)
            {
                sc_regSet(E, 1);
                break;
            }

            _cell = operand;
            _cell--;
            break;
        case JNEG:
            if (_accum < 0)
            {
                if (operand > 99 || operand < 0)
                {
                    sc_regSet(E, 1);
                    break;
                }
                _cell = operand;
                _cell--;
            }
            break;
        case JZ:
            if (_accum == 0)
            {
                if (operand > 99 || operand < 0)
                {
                    sc_regSet(E, 1);
                    break;
                }
                _cell = operand;
                _cell--;
            }
            break;
        case JB:
            if (_accum > 0)
            {
                if (operand > 99 || operand < 0)
                {
                    sc_regSet(E, 1);
                    break;
                }
                _cell = operand;
                _cell--;
            }
            break;

        case SET:
            _accum = operand;

            break;

        case HALT:
            return 2;
        default:
            return 1;
        }
    }
    else
    {
        if (ALU(command, operand))
        {
            return 1;
        }
    }
    _cell++;
    return 0;
}