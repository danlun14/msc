#ifndef MYTERMINAL_H
#define MYTERMINAL_H

#include <stdio.h>

#define defaultActiveFlag cyan
#define defaultBackGround white
#define defaultForgeGround black

enum colors
{
    black = 0,
    red = 1,
    green = 2,
    yellow = 3,
    blue = 4,
    purple = 5,
    cyan = 6,
    white = 7
};

int mt_clrscr(void);
int mt_gotoXY(int, int);
int mt_getscreensize(int *rows, int *cols);
int mt_setfgcolor(enum colors);
int mt_setbgcolor(enum colors);
int mt_clearcolor();

#endif