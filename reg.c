#include "reg.h"

uint16_t pc = 0;
uint16_t gen_register[8];

void move_reg(uint16_t value, uint8_t reg)
{
    gen_register[reg] = value;
}

uint16_t get_reg(uint8_t reg)
{
    return gen_register[reg];
}