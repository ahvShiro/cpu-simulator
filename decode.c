//
// Created by fflv on 07/07/25.
//
#include "decode.h"

R_format create_r_instruction (uint16_t instruction)
{
    R_format ins;
    ins.opcode = extract_bits(instruction, 9, 15);
    ins.dest = extract_bits(instruction, 6, 8);
    ins.op1 = extract_bits(instruction, 3, 5);
    ins.op2 = extract_bits(instruction, 0, 2);
    return ins;
}

void print_r_instruction(R_format ins)
{
    printf("Opcode: %d\n", ins.opcode);
    printf("Destination register: %d\n", ins.dest);
    printf("Operand 1: %d\n", ins.op1);
    printf("Operand 2: %d\n", ins.op2);
}

I_format create_i_instruction (uint16_t instruction) {
    I_format ins;
    ins.opcode = extract_bits(instruction, 9, 15);
    ins.reg = extract_bits(instruction, 0, 9);
    ins.immd = extract_bits(instruction, 0, 15);
    return ins;
}

void print_i_instruction(I_format ins)
{
    printf("Opcode: %d\n", ins.opcode);
    printf("Register: %d\n", ins.reg);
    printf("Immediate value: %d\n", ins.immd);
}
