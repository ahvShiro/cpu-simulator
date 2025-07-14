//
// Created by fflv on 14/07/25.
//
#include "execute.h"

void execute_r(R_format ins)
{
    switch (ins.opcode)
    {
    case 0:
        printf("add\n");
        break;
    case 1:
        printf("sub\n");
        break;
    case 2:
        printf("mul\n");
        break;
    case 3:
        printf("div\n");
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
        break;
    }
}

void execute_i(I_format ins)
{
    switch (ins.opcode)
    {
    case 0:
        printf("jump\n");
        break;
    case 1:
        printf("jump_cond\n");
        break;
    case 3:
        printf("mov\n");
        break;
    default:
        printf("nope\n");
        break;
    }
}