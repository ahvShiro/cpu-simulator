#ifndef __HEADER_REG_H__
#define __HEADER_REG_H__

#include "lib.h"

typedef struct {
    uint8_t pc;
    uint8_t r1;
    uint8_t r2;
} RegFile;

RegFile start_reg_file();


#endif