#ifndef MT_H
#define MT_H

#include <stdio.h>

struct winsize 
{
        unsigned short ws_row;
        unsigned short ws_col;
};
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



int mt_clrscr (void); 
int mt_gotoXY (int, int); 
int mt_getscreensize (int * rows, int * cols);
int mt_setfgcolor (enum colors); 
int mt_setbgcolor (enum colors); 




#endif