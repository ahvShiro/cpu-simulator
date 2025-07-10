// SIMULADOR DE PROCESSADOR

#include "lib.h"
#include "reg.h"
#include "decode.h"

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

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: %s [bin_name]\n", argv[0]);
        exit(1);
    }

    FILE * fp = fopen(argv[1], "r");
    const uint16_t size = fsize(fp);
    fclose(fp);

    RegFile rf = start_reg_file();

    uint16_t *memory = malloc(size * sizeof(uint16_t)); // malloc usa metade do tamanho

    load_binary_to_memory(argv[1], memory, size);
    
    for (size_t i = 1; i < size; i++)
    {
        uint16_t instruction = extract_bits(memory[rf.pc], 0, 16);
        printf("0b%016b\n", instruction);
        rf.pc++;
        int first_bit = extract_bits(instruction, 15, 16);

        if(first_bit){
            print_i_instruction(create_i_instruction(instruction));
            printf("I\n");
        } else {
            print_r_instruction(create_r_instruction(instruction));
            printf("R\n");
        }
        printf("%d\n", first_bit);

    }
    free(memory);
    return 0;
}