//
// Created by fflv on 14/07/25.
//
#include "execute.h"

void execute_r(R_format ins)
{
    switch (ins.opcode)
    {
    case 0:
        printf("add");
        break;
    case 1:
        printf("sub");
        break;
    case 2:
        printf("mul");
        break;
    case 3:
        printf("div");
        break;
    case 4:
        printf("cmp_eq");
        break;
    case 5:
        printf("cmp_neq");
        break;
    case 6:
        printf("cmp_less");
        break;
    case 7:
        printf("cmp_greater");
        break;
    case 8:
        printf("cmp_less_eq");
        break;
    case 9:
        printf("cmp_greater_eq");
        break;
    case 10:
        printf("and");
        break;
    case 11:
        printf("or");
        break;
    case 12:
        printf("shiftl");
        break;
    case 13:
        printf("shiftr");
        break;
    case 14:
        printf("load");
        break;
    case 15:
        printf("store");
        break;
    default:
        printf("nope");
        break;
    }
}

void execute_I(I_format ins)
{
    switch (ins.opcode)
    {
    case 0:
        printf("jump");
    case 1:
        printf("jump_cond");
    case 3:
        printf("mov");
    default:
        printf("nope");
        break;
    }
}