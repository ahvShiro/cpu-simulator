//
// Created by fflv on 07/07/25.
//
#include "decode.h"

R_format create_r_instruction (uint16_t instruction)
{
    R_format ins;
    ins.opcode = extract_bits(instruction, 9, 16);
    ins.dest = extract_bits(instruction, 6, 16);
    ins.op1 = extract_bits(instruction, 3, 16);
    ins.op2 = extract_bits(instruction, 0, 16);
    return ins;
}

I_format create_i_intruction (uint16_t instruction) {
    I_format ins;
    ins.opcode = extract_bits(instruction, 0, 16);
    ins.reg = extract_bits(instruction, 0, 16);
    ins.immd = extract_bits(instruction, 0, 16);
    return ins;
}