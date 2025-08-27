#ifndef __HEADER_FETCH_H__
#define __HEADER_FETCH_H__

#include "lib.h"

typedef struct{
    uint16_t instruction_value : 16;
} Fetch;

void fetch(Fetch * fet, uint16_t * memory);


#endif