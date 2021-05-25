#include "libsrc/libs/memory.h"
#include "libsrc/libs/myTerminal.h"
#include <stdio.h>
#include "libsrc/libs/bigChars.h"
#include "libsrc/libs/myReadKey.h"
#include "libsrc/libs/other.h"

int main()
{
    sc_memoryLoad("");
    runTime();
    mt_gotoXY(23, 0);
    mt_clearcolor();
    return 0;
}
