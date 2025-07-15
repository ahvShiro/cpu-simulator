#ifndef __HEADER_DECODE_H__
#define __HEADER_DECODE_H__

#include "lib.h"

/*
 * FORMATAÇÃO DA INSTRUÇÃO:
 * 1 bit de formato
 *
 * Formato R = 0
 * 6 bits de opcode
 * 3 bits de destino
 * 3 bits de operando
 * 3 bits de operando
 *
 * Formato I = 1
 * 2 bits opcode
 * 3 bits registrador
 * 10 bits imediatos
 *
 * NO TOTAL toda instrução tem 16 bits (0-15)
 */

typedef struct {
    // Bit 15 (bit = 0, R)
    uint16_t opcode : 6;  // Bits 14-9
    uint16_t dest : 3;    // Bits 8-6 
    uint16_t op1 : 3;     // Bits 5-3 
    uint16_t op2 : 3;     // Bits 2-0 
} R_format;

typedef struct {
    // Bit 15 (bit = 1, I)
    uint16_t opcode : 2;  // Bits 14-13
    uint16_t reg : 3;     // Bits 12-10 
    uint16_t immd : 10;   // Bits 9-0
} I_format;

R_format create_r_instruction (uint16_t instruction);

I_format create_i_instruction (uint16_t instruction);

void print_r_instruction(R_format ins);

void print_i_instruction(I_format ins);

#endif