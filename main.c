#include "libsrc/libs/memory.h"
#include "libsrc/libs/myTerminal.h"
#include <stdio.h>
#include "libsrc/libs/bigChars.h"
#include "libsrc/libs/myReadKey.h"

int intToHex(int number, char *str)
{
	if (!str || number >= 65535 || number < 0) {
		return 1;
	}

	for (int i = 0; i < 5; i++) {
		str[i] = 0;
	}

	int remainder;
	int whole = number;
	int i;

	for (i = 0; whole >= 16; i++) {
		remainder = whole % 16;
		whole = whole / 16;
		if (remainder == 10) {
			str[i] = 'A';
		} else if (remainder == 11) {
			str[i] = 'B';
		} else if (remainder == 12) {
			str[i] = 'C';
		} else if (remainder == 13) {
			str[i] = 'D';
		} else if (remainder == 14) {
			str[i] = 'E';
		} else if (remainder == 15) {
			str[i] = 'F';
		} else {
			str[i] = remainder + 48;
		}
	}


	if (whole != 0) {
		if (whole == 10) {
			str[i] = 'A';
		} else if (whole == 11) {
			str[i] = 'B';
		} else if (whole == 12) {
			str[i] = 'C';
		} else if (whole == 13) {
			str[i] = 'D';
		} else if (whole == 14) {
			str[i] = 'E';
		} else if (whole == 15) {
			str[i] = 'F';
		} else {
			str[i] = whole + 48;
		}
	}
		
	printf("???%s",str);
	return 0;
}


int main()
{
    mt_clrscr();

    
    sc_regInit();
    sc_memoryInit();

    sc_regSet(P, 1);
    sc_regSet(M, 1);

    mt_setbgcolor(white);
    mt_setfgcolor(black);

    int cell = 0;
    char hexStr1[3]="ss";
    char hexStr2[3] = "ss";
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
    int accum = 23332&0b1011111111111111;
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
    sc_commandDecode(temp, &command, &operand);
    intToHex(command, hexStr1);
    intToHex(operand, hexStr2);
    printf("%d|%02X %02X|%s;%s", temp, command, operand, hexStr1,hexStr2);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            sc_memoryGet(i * 10 + j, &value);
            sc_commandDecode(value, &command, &operand);
            mt_gotoXY(2 + i, 2 + 6 * j);
            printf("+%02d%02d\n", command, operand);
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
