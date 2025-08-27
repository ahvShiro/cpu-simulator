#ifndef __HEADER_DECODE_H__
#define __HEADER_DECODE_H__

#include "lib.h"
#include "fetch.h"

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

typedef struct{
    uint16_t type;
    uint16_t opcode;
    uint16_t dest;
    uint16_t op1;
    uint16_t op2;
    uint16_t stage;
} Decode;
/*
typedef struct {
    // Bit 15 (bit = 0, R)
    uint16_t op2 : 3;     // Bits 2-0
    uint16_t op1 : 3;     // Bits 5-3
    uint16_t dest : 3;    // Bits 8-6
    uint16_t opcode : 6;  // Bits 14-9
    uint16_t type : 1;


} R_format;

typedef struct {
    // Bit 15 (bit = 1, I)
    uint16_t immd : 10;   // Bits 9-0
    uint16_t reg : 3;     // Bits 12-10
    uint16_t opcode : 2;  // Bits 14-13
    uint16_t type : 1;
} I_format;
*/

void create_r_instruction (Decode *ins, uint16_t instruction);

void create_i_instruction (Decode *ins, uint16_t instruction);

void print_r_instruction(Decode *ins);

void print_i_instruction(Decode *ins);

void decode(Fetch *fet, Decode *dec);

#endif