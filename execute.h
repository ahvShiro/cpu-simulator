//
// Created by fflv on 14/07/25.
//

#ifndef EXECUTE_H
#define EXECUTE_H

#include "decode.h"
#include "reg.h"

void program_loop(uint16_t size, const uint16_t *memory, RegFile rf);

void execute_i(I_format ins, RegFile * rf, const uint16_t *memory);

void execute_r(R_format ins, RegFile * rf, const uint16_t *memory );

#endif //EXECUTE_H
