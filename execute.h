//
// Created by fflv on 14/07/25.
//

#ifndef EXECUTE_H
#define EXECUTE_H

#include "decode.h"
#include "reg.h"

extern size_t size_mem;

typedef struct{

} Execute;

void execute(Decode * dec, Execute * exe);

void program_loop(uint16_t *memory);

void execute_i(const I_format * ins, uint16_t *memory);

void execute_r(const R_format * ins, uint16_t *memory );

#endif //EXECUTE_H
