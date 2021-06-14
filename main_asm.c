#include "libsrc/libs/memory.h"
#include "libsrc/libs/myTerminal.h"
#include <stdio.h>
#include "libsrc/libs/bigChars.h"
#include "libsrc/libs/myReadKey.h"
#include "libsrc/libs/other.h"
#include "libsrc/libs/simpleAssembler.h"

int main()
{

    asm_translate("test.asm", "asm.bin");
    int value = 0;
    getchar();
    runTimeAsm();
    mt_gotoXY(23, 0);
    mt_clearcolor();
    return 0;
}
