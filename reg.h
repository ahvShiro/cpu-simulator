#ifndef __HEADER_REG_H__
#define __HEADER_REG_H__

#include "lib.h"

extern uint16_t pc;
extern uint16_t gen_register[8];

void move_reg(uint16_t value, uint8_t reg);
uint16_t get_reg(uint8_t reg);
void print_reg();

#endif