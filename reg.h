#ifndef __HEADER_REG_H__
#define __HEADER_REG_H__

#include "lib.h"

typedef struct {
    uint8_t pc;
    uint8_t r1;
    uint8_t r2;
} RegFile;

inline RegFile start_reg_file()
{
    RegFile regF;
    regF.pc = 1;
    regF.r1 = 0;
    regF.r2 = 0;
    return regF;
}

#endif