#include "mt.h"
#include <sys/ioctl.h>
int mt_clrscr (void) 
 {
     printf("\E[H\E[J");
     
     return 0;
 }
//производит очистку и перемещение курсора в левый верхний угол экрана
int mt_gotoXY (int x, int y) 
{
 printf("\E[?%dH\E[?%dC", x ,y);
 
 return 0;
}
//перемещает курсор в указанную позицию. Первый параметр номер строки, второй - номер столбца
int mt_getscreensize (int * rows, int * cols) 
{
    struct winsize win;
    ioctl(1,TIOCGWINSZ,&win);
    *rows = win.ws_row;
    *cols = win.ws_col;

}

//определяет размер экрана терминала (количество строк и столбцов)
int mt_setfgcolor (enum colors color) 
{
    printf("\E[3%dm", color);
}

int mt_setbgcolor (enum colors color) 
{
    printf("\E[4%dm",color);
}