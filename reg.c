#include "reg.h"

void move_into_reg(uint8_t value, uint8_t reg, RegFile *rf)
{
    switch (reg)
    {
    case 0:
        rf->r0 = value;
        break;
    case 1:
        rf->r1 = value;
        break;
    case 2:
        rf->r2 = value;
        break;
    case 3:
        rf->r3 = value;
        break;
    case 4:
        rf->r4 = value;
        break;
    case 5:
        rf->r5 = value;
        break;
    case 6:
        rf->r6 = value;
        break;
    case 7:
        rf->r7 = value;
        break;
    default:
        printf("Valor inválido, registro não existe.");
        exit(1);
    }
}