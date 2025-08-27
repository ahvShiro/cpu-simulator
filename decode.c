//
// Created by fflv on 07/07/25.
//
#include "decode.h"

void decode(Fetch * fet, Decode * dec){
    //TODO: Make the functions below work with a generalized single struct to help with the process of execution
    int type_bit = extract_bits(fet->instruction_value, 15, 16);
    if(type_bit){
        set_i_instruction(fet->instruction_value, dec);
    } else {
        set_r_instruction(fet->instruction_value, dec);
    }
}

void set_i_instruction(uint16_t ins, Decode * dec){
    dec->type = 1;
    dec->opcode = extract_bits(ins, 13, 15);
    dec->dest = extract_bits(ins, 10, 12);
    dec->op1 = extract_bits(ins, 0, 9);
}

void set_r_instruction(uint16_t ins, Decode * dec){
    dec->type = 0;
    dec->opcode = extract_bits(ins, 9, 15);
    dec->dest = extract_bits(ins, 6, 8);
    dec->op1 = extract_bits(ins, 3, 5);
    dec->op2 = extract_bits(ins, 0, 2);
}


/*
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
*/