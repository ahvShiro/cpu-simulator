//
// Created by fflv on 14/07/25.
//
#include "execute.h"
#include "syscall.h"
#include "reg.h"

void program_loop(uint16_t *memory)
{
    for (size_t i = pc; i < -1; i++)
    {
        //printf("PC: %d\n", pc);
        uint16_t instruction = memory[pc];
        pc++;
        int type_bit = extract_bits(instruction, 15, 16);

        if(type_bit){
            I_format ins;
            create_i_instruction(&ins, instruction);
            // print_i_instruction(&ins);
            execute_i(&ins, memory);

        } else {
            R_format ins;
            create_r_instruction(&ins, instruction);
            //print_r_instruction(&ins);
            execute_r(&ins, memory);
        }

    }
}

void execute_r(const R_format * ins, uint16_t *memory)
{
    uint16_t val;
    switch (ins->opcode)
    {
    case 0:
        //printf("add\n");
        val = gen_register[ins->op1] + gen_register[ins->op2];
        move_reg(val, ins->dest);
        break;
    case 1:
        //printf("sub\n");
        val = get_reg(ins->op1) - get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 2:
        //printf("mul\n");
        val = get_reg(ins->op1) * get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 3:
        //printf("div\n");
        val = get_reg(ins->op1) / get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 4:
        //printf("cmp_eq\n");
        val = get_reg(ins->op1) == get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 5:
        //printf("cmp_neq\n");
        val = get_reg(ins->op1) != get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 6:
        //printf("cmp_less\n");
        val = get_reg(ins->op1) < get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 7:
        //printf("cmp_greater\n");
        val = get_reg(ins->op1) > get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 8:
        //printf("cmp_less_eq\n");
        val = get_reg(ins->op1) <= get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 9:
        //printf("cmp_greater_eq\n");
        val = get_reg(ins->op1) >= get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 10:
        //printf("and\n");
        val = get_reg(ins->op1) & get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 11:
        //printf("or\n");
        val = get_reg(ins->op1) | get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 12:
        //printf("xor\n");
        val = get_reg(ins->op1) ^ get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 13:
        //printf("shiftl\n");
        val = get_reg(ins->op1) << get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 14:
        //printf("shiftr\n");
        val = get_reg(ins->op1) >> get_reg(ins->op2);
        move_reg(val, ins->dest);
        break;
    case 15:
        //printf("load\n");
        // reg de destino tem o registro que terá o valor do endereço de memória, operando 1 o endereço, operando 2 inutilizado
        val = memory[get_reg(ins->op1)];
        move_reg(val, ins->dest);
        break;
    case 16:
        //printf("store\n");
        memory[get_reg(ins->op1)] = get_reg(ins->op2);
        break;
    case 63:
        //printf("syscall\n");
        syscall_routine(memory);
        break;
    default:
        //printf("nope\n");
        free(memory);
        exit(1);

    }
}

void execute_i(const I_format * ins, uint16_t *memory)
{
    switch (ins->opcode)
    {
    case 0:
        //printf("jump\n");
        pc = ins->immd;
        break;
    case 1:
        //printf("jump_cond\n");
        if (get_reg(ins->reg) != 0)
        {
            pc = ins->immd;
        }
        break;
    case 3:
        //printf("mov\n");
        move_reg(ins->immd, ins->reg);
        gen_register[ins->reg] = ins->immd;
        break;
    default:
        //printf("nope\n");
        free(memory);
        exit(1);
    }
}