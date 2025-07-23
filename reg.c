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
        printf("Invalid Register: stopping program");
        exit(1);
    }
}

uint8_t get_value_from_reg(uint8_t reg, const RegFile *rf)
{
    switch (reg)
    {
    case 0:
        return rf->r0;
    case 1:
        return rf->r1;
    case 2:
        return rf->r2;
    case 3:
        return rf->r3;
    case 4:
        return rf->r4;
    case 5:
        return rf->r5;
    case 6:
        return rf->r6;
    case 7:
        return rf->r7;
    default:
        printf("Invalid Register: stopping program");
        exit(1);
    }
}