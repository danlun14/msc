#ifndef BIGCHARS_H
#define BIGCHARS_H

#include "memory.h"
#include "myTerminal.h"
#define _BSD_SOURCE

//a f g i j k l m n o p q r s t u v w x y z { | } ~
//▒ ° ± ␋ ┘ ┐ ┌ └ ┼ ⎺ ⎻ ─ ⎼ ⎽ ├ ┤ ┴ ┬ │ ≤ ≥ π ≠ £ ·

#define bc_cornerTopLeft 'l'
#define bc_cornerBottomLeft 'm'
#define bc_cornerTopRight 'k'
#define bc_cornerBottomRight 'j'
#define bc_horizontaleLine 'q'
#define bc_verticalLine 'x'
#define bc_filledCell 'a'

int bc_printA(char *str);
int bc_box(int x1, int y1, int x2, int y2);
int bc_printbigchar(int a[2], int x, int y, enum colors, enum colors);
int bc_setbigcharpos(int *big, int x, int y, int value);
int bc_getbigcharpos(int *big, int x, int y, int *value);
int bc_bigcharwrite(int fd, int *big, int count);
int bc_bigcharread(int fd, int *big, int need_count, int *count);

long bigNull(int x);
long bigOne(int x);
long bigTwo(int x);
long bigThree(int x);
long bigFour(int x);
long bigFive(int x);
long bigSix(int x);
long bigSeven(int x);
long bigEight(int x);
long bigNine(int x);
long bigA(int x);
long bigB(int x);
long bigC(int x);
long bigD(int x);
long bigE(int x);
long bigF(int x);
long bigPlus(int x);
long bigMinus(int x);

int intToHex(int number, char *str);
#endif
