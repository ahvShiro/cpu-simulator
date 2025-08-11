//
// Created by fflv on 07/07/25.
//
#include "decode.h"

void create_r_instruction (R_format * ins, uint16_t instruction)
{
    memcpy(ins, &instruction, sizeof(*ins));
}

void print_r_instruction(R_format * ins)
{
    printf("Opcode: %d\n", ins->opcode);
    printf("Destination register: %d\n", ins->dest);
    printf("Operand 1: %d\n", ins->op1);
    printf("Operand 2: %d\n", ins->op2);
}

void create_i_instruction (I_format * ins, uint16_t instruction) {
    memcpy(ins, &instruction, sizeof(*ins));
}

void print_i_instruction(I_format * ins)
{
    printf("Opcode: %d\n", ins->opcode);
    printf("Register: %d\n", ins->reg);
    printf("Immediate value: %d\n", ins->immd);
}
