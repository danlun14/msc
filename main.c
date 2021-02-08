#include "libs/msc.h"
#include <stdio.h>

int main()
{
    int tempValue = 0b0010000010011111;
    int tempReg = 0;
    sc_regInit();
    for(int i = 0; i < 100; i++){
	sc_memoryGet(i, &tempValue);
	printf("%d", tempValue);
    }
    printf("\n");
    sc_memorySet(98,115);
    for(int i = 0; i< 100; i++){
	sc_memoryGet(i, &tempValue);
	printf("%d", tempValue);
    }
    sc_memoryInit();
    sc_memoryGet(3, &tempValue);
    printf("%d\n", tempValue);
    sc_memorySave("memory.bin");
    sc_memorySet(3, 15);
    sc_memoryLoad("memory.bin");
    sc_memoryGet(3, &tempValue);
    printf("%d\n", tempValue);
    printf("\nreg:\n\n");
    sc_regGet(P, &tempReg);
    printf("%d\n",tempReg);
    sc_regGet(O, &tempReg);
    printf("%d\n", tempReg);
    sc_regGet(M, &tempReg);
    printf("%d\n", tempReg);
    sc_regGet(T, &tempReg);
    printf("%d\n", tempReg);
    sc_regGet(E, &tempReg);
    printf("%d\n",tempReg);
    printf("\ncode/encode\n");
    sc_commandEncode(10000,1231,&tempValue);
    //sc_commandDecode(100000,&tempValue,&tempReg);
    
    sc_regGet(P,&tempReg);
    printf("\n%d\n", tempReg);
    sc_regGet(O,&tempReg);
    printf("%d\n", tempReg);
    sc_regGet(M,&tempReg);
    printf("%d\n", tempReg);
    sc_regGet(T,&tempReg);
    printf("%d\n", tempReg);
    sc_regGet(E,&tempReg);
    printf("%d\n\n", tempReg);
    sc_commandDecode(tempValue,&tempReg,&tempValue);
    printf("%d\n", tempReg);
    printf("%d\n", tempValue);
}