#ifndef __HEADER_REG_H__
#define __HEADER_REG_H__

#include "lib.h"

typedef struct {
    uint8_t name;
    uint16_t value;

} Reg;

typedef struct {
    Reg pc;
} RegFile;

#endif