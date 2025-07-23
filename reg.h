#ifndef __HEADER_REG_H__
#define __HEADER_REG_H__

#include "lib.h"

typedef struct {
    uint16_t pc;
    uint8_t r0;
    uint8_t r1;
    uint8_t r2;
    uint8_t r3;
    uint8_t r4;
    uint8_t r5;
    uint8_t r6;
    uint8_t r7;
} RegFile;

void move_into_reg(uint8_t value, uint8_t reg, RegFile *rf);

#endif