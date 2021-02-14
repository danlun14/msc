#include<stdio.h>
int main()
{
    int x = 100;
    int y = 300;
     printf("\E[%d;%dH", y, x);
     printf("dade\n");
    return 0;
}
