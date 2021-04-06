#include "libs/bigChars.h"
#include "libs/myTerminal.h"

int bc_printA(char *str)
{
    if (!str)
    {
        return 1;
    }

    printf("\E(0%s\E(B", str);

    return 0;
}

int bc_box(int x1, int y1, int x2, int y2)
{
    if (x1 > x2 || y1 > y2)
    {
        return 1;
    }

    if (x1 < 1 || y1 < 1)
    {
        return 1;
    }

    mt_gotoXY(y1, x1);

    int x = x2 - x1 + 1;
    int y = y2 - y1;

    printf("\E(0");

    for (int i = 0; i < y; i++)
    {
        if (i == 0)
        {
            printf("%c", bc_cornerTopLeft);

            for (int j = 1; j < x - 2; j++)
            {
                printf("%c", bc_horizontaleLine);
            }

            printf("%c", bc_cornerTopRight);

            printf("\n");
            continue;
        }

        mt_gotoXY(y1 + i, x1);

        printf("%c", bc_verticalLine);

        for (int j = 1; j < x - 2; j++)
        {
            printf("%c", ' ');
        }

        printf("%c", bc_verticalLine);
        printf("\n");

        if (i == y - 1)
        {
            mt_gotoXY(y1 + i, x1);

            printf("%c", bc_cornerBottomLeft);

            for (int j = 1; j < x - 2; j++)
            {
                printf("%c", bc_horizontaleLine);
            }

            printf("%c", bc_cornerBottomRight);

            printf("\n");
        }
    }

    printf("\E(B");

    return 0;
}

int bc_printbigchar(int *a, int x, int y, enum colors fg, enum colors bg)
{
    if (!a ||
        x < 1 || y < 1 ||
        fg > 7 || fg < 0 ||
        bg > 7 || bg < 0)
    {
        return 1;
    }

    printf("\E(0");
    mt_setfgcolor(fg);
    mt_setbgcolor(bg);

    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            mt_gotoXY(y + i + k * 4, x);
            for (int j = 0; j < 8; j++)
            {
                if ((a[k] >> (i * 8 + j)) & 1)
                {
                    printf("%c", bc_filledCell);
                }
                else
                {
                    printf("%c", ' ');
                }
            }
        }
    }

    printf("\E(B");

    printf("\E[0m"); //clear color

    return 0;
}

int bc_setbigcharpos(int *big, int x, int y, int value)
{
    if (!big || x < 0 || x > 7 || y < 0 || y > 7 || value < 0 || value > 1)
    {
        return 1;
    }

    y--;
    x--;

    if (y < 4)
    {
        if (value)
        {
            big[0] |= 1 << (y * 8 + x);
        }
        else
        {
            big[0] = ~(1 << (y * 8 + x));
        }
    }
    else
    {
        if (value)
        {
            big[1] |= 1 << (y * 8 + x);
        }
        else
        {
            big[1] = ~(1 << (y * 8 + x));
        }
    }

    return 0;
}

int bc_getbigcharpos(int *big, int x, int y, int *value)
{
    if (!big || !value || x < 0 || x > 7 || y < 0 || y > 7)
    {
        return 1;
    }

    x--;
    y--;

    if (y < 4)
    {
        *value = (big[0] >> (y * 8 + x)) & 1;
    }
    else
    {
        *value = (big[1] >> (y * 8 + x)) & 1;
    }

    return 0;
}

int bc_bigcharwrite(int fd, int *big, int count)
{
    if (!big || count < 0 || fd < 0)
    {
        return 1;
    }

    for (; count > 0; count--)
    {
        if (write(fd, &big[0], sizeof(int)) < 0)
        {
            return 1;
        }

        if (write(fd, &big[1], sizeof(int)) < 0)
        {
            return 1;
        }
    }

    return 0;
}

int bc_bigcharread(int fd, int *big, int need_count, int *count)
{
    if (!big || !count || fd < 0)
    {
        return 1;
    }

    for (; need_count > 0; need_count--)
    {
        if (read(fd, &big[0], sizeof(int)) < 0)
        {
            *count = 0;
            return 1;
        }

        if (read(fd, &big[1], sizeof(int)) < 0)
        {
            *count = 0;
            return 1;
        }
    }

    return 0;
}

long bigNull(int x)
{
    if (x == 0)
    {
        return 1717992960;
    }
    return 8283750;
}
long bigOne(int x)
{
    if (x == 0)
    {
        return 471341056;
    }
    return 3938328;
}
long bigTwo(int x)
{
    if (x == 0)
    {
        return 538983424;
    }
    return 3935292;
}
long bigThree(int x)
{
    if (x == 0)
    {
        return 2120252928;
    }
    return 8282238;
}
long bigFour(int x)
{
    if (x == 0)
    {
        return 2120640000;
    }
    return 6316158;
}
long bigFive(int x)
{
    if (x == 0)
    {
        return 2114092544;
    }
    return 8273984;
}
long bigSix(int x)
{
    if (x == 0)
    {
        return 33701376;
    }
    return 8274558;
}
long bigSeven(int x)
{
    if (x == 0)
    {
        return 811630080;
    }
    return 396312;
}
long bigEight(int x)
{
    if (x == 0)
    {
        return 2120646144;
    }
    return 8283750;
}
long bigNine(int x)
{
    if (x == 0)
    {
        return 2120646144;
    }
    return 8282208;
}
long bigA(int x)
{
    if (x == 0)
    {
        return 1715214336;
    }
    return 6710910;
}
long bigB(int x)
{
    if (x == 0)
    {
        return 1044528640;
    }
    return 4080194;
}
long bigC(int x)
{
    if (x == 0)
    {
        return 37912064;
    }
    return 8274434;
}
long bigD(int x)
{
    if (x == 0)
    {
        return 1111637504;
    }
    return 4080194;
}
long bigE(int x)
{
    if (x == 0)
    {
        return 2114092544;
    }
    return 8258050;
}
long bigF(int x)
{
    if (x == 0)
    {
        return 33701376;
    }
    return 131646;
}
long bigPlus(int x)
{
    if (x == 0)
    {
        return 2115508224;
    }
    return 1579134;
}
long bigMinus(int x)
{
    if (x == 0)
    {
        return 2113929216;
    }
    return 126;
}

int intToHex(int number, char *str)
{
    if (!str || number >= 65535 || number < 0)
    {
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        str[i] = 0;
    }
    int firstChar = 0b0011100000000000;
    int secondChar = 0b0000011110000000;
    int thirdChar = 0b0000000001110000;
    int fourChar = 0b0000000000001111;
    int whole = number;
    int nums[4];
    nums[0] = (firstChar & number) >> 11;
    nums[1] = (secondChar & number) >> 7;
    nums[2] = (thirdChar & number) >> 4;
    nums[3] = (fourChar & number);
    int i;

    for (i = 3; i > -1; i--)
    {

        if (nums[i] == 10)
        {
            str[i] = 'A';
        }
        else if (nums[i] == 11)
        {
            str[i] = 'B';
        }
        else if (nums[i] == 12)
        {
            str[i] = 'C';
        }
        else if (nums[i] == 13)
        {
            str[i] = 'D';
        }
        else if (nums[i] == 14)
        {
            str[i] = 'E';
        }
        else if (nums[i] == 15)
        {
            str[i] = 'F';
        }
        else
        {
            str[i] = nums[i] + 48;
        }
    }
    return 0;
}