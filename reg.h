#ifndef __HEADER_REG_H__
#define __HEADER_REG_H__

#include "lib.h"

typedef struct {
    uint16_t pc;
    uint16_t r0;
    uint16_t r1;
    uint16_t r2;
    uint16_t r3;
    uint16_t r4;
    uint16_t r5;
    uint16_t r6;
    uint16_t r7;
} RegFile;

void move_reg(uint16_t value, uint8_t reg, RegFile *rf);
uint16_t get_reg(uint8_t reg, const RegFile *rf);

#endif