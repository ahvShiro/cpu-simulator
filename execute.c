//
// Created by fflv on 14/07/25.
//
#include "execute.h"

void program_loop(uint16_t size, const uint16_t *memory, RegFile rf)
{
    for (size_t i = rf.pc; i < size; i++)
    {
        printf("PC: %d\n", rf.pc);
        uint16_t instruction = extract_bits(memory[rf.pc], 0, 16);
        int first_bit = extract_bits(instruction, 15, 16);

        if(first_bit){
            I_format ins = create_i_instruction(instruction);
            print_i_instruction(ins);
            execute_i(ins, &rf);

        } else {
            R_format ins = create_r_instruction(instruction);
            print_r_instruction(ins);
            execute_r(ins, &rf);
        }
        rf.pc++;
    }
}

void execute_r(R_format ins, RegFile * rf)
{
    uint8_t val;
    switch (ins.opcode)
    {
    case 0:
        printf("add\n");
        val = get_reg(ins.op1, rf) + get_reg(ins.op2, rf);
        move_reg(val, ins.dest, rf);
        break;
    case 1:
        printf("sub\n");
        val = get_reg(ins.op1, rf) - get_reg(ins.op2, rf);
        move_reg(val, ins.dest, rf);
        break;
    case 2:
        printf("mul\n");
        val = get_reg(ins.op1, rf) * get_reg(ins.op2, rf);
        move_reg(val, ins.dest, rf);
        break;
    case 3:
        printf("div\n");
        val = get_reg(ins.op1, rf) / get_reg(ins.op2, rf);
        move_reg(val, ins.dest, rf);
        break;
    case 4:
        printf("cmp_eq\n");
        break;
    case 5:
        printf("cmp_neq\n");
        break;
    case 6:
        printf("cmp_less\n");
        break;
    case 7:
        printf("cmp_greater\n");
        break;
    case 8:
        printf("cmp_less_eq\n");
        break;
    case 9:
        printf("cmp_greater_eq\n");
        break;
    case 10:
        printf("and\n");
        break;
    case 11:
        printf("or\n");
        break;
    case 12:
        printf("shiftl\n");
        break;
    case 13:
        printf("shiftr\n");
        break;
    case 14:
        printf("load\n");
        break;
    case 15:
        printf("store\n");
        break;
    default:
        printf("nope\n");
        //exit(1);
        break;
    }
}

void execute_i(I_format ins, RegFile *rf)
{
    switch (ins.opcode)
    {
    case 0:
        printf("jump\n");
        rf->pc = ins.immd;
        break;
    case 1:
        printf("jump_cond\n");
        if (get_reg(ins.reg, rf) == 0)
        {
            rf->pc = ins.immd;
        }
        break;
    case 3:
        printf("mov\n");
        move_reg(ins.immd, ins.reg, rf);
        break;
    default:
        printf("nope\n");
        //exit(1);
        break;
    }
}