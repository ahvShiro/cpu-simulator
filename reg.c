#include "reg.h"

RegFile start_reg_file()
{
    RegFile regF;
    regF.pc = 1;
    regF.r0 = 0;
    regF.r1 = 0;
    regF.r2 = 0;
    regF.r3 = 0;
    regF.r4 = 0;
    regF.r5 = 0;
    regF.r6 = 0;
    regF.r7 = 0;
    return regF;
}

void move_into_reg(uint8_t value, uint8_t reg, RegFile rf)
{
    switch (reg)
    {
    case 0:
        rf.r0 = value;
    case 1:
        rf.r1 = value;
    case 2:
        rf.r2 = value;
    case 3:
        rf.r3 = value;
    case 4:
        rf.r4 = value;
    case 5:
        rf.r5 = value;
    case 6:
        rf.r6 = value;
    case 7:
        rf.r7 = value;
        break;
    default:
        printf("Valor inválido, registro não existe.");
        exit(1);
    }
}