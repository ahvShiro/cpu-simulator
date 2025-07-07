//
// Created by fflv on 07/07/25.
//
#include "decode.h"

R_format create_r_instruction (uint16_t instruction)
{
    R_format ins;
    ins.opcode = extract_bits(instruction, 9, 14);
    ins.dest = extract_bits(instruction, 6, 8);
    ins.op1 = extract_bits(instruction, 3, 5);
    ins.op2 = extract_bits(instruction, 0, 2);
    return ins;
}