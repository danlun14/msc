#include "libsrc/libs/basic.h"

int main(int argc, char **args)
{
    int i = 0;
    if (argc == 3)
    {
        cell_number_for_variables = 40;

        if (basic_translator(args[1], args[2], &i))
        {
            printf(" in %d line\n", i);
            printf("Please rewrite your code.\n");
            return 1;
        }
    }
    else
    {
        if (basic_translator("test.bsc", "test.asm", &i))
        {
            printf(" in %d line\n", i);
            printf("Please rewrite your code.\n");
            return 1;
        }
        //help();
        return 1;
    }

    printf("Finish\n");

    return 0;
}