// SIMULADOR DE PROCESSADOR

#include "lib.h"
#include "fetch.h"
#include "reg.h"

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
    printf("%d\n", argc);

    if (argc != 2)
    {
        printf("usage: %s [bin_name]\n", argv[0]);
        exit(1);
    }

    FILE * fp = fopen(argv[1], "r");
    uint16_t size = fsize(fp);
    fclose(fp);

    RegFile rf = start_reg_file();

    uint16_t *memory = malloc(size * sizeof(uint16_t)); // malloc usa metade do tamanho

    load_binary_to_memory(argv[1], memory, size);

    uint16_t * ins = get_next_instruction(memory);

    print_memory(ins, rf.pc);

    free(memory);

    // a instrução inicia no índice 1 não 0 ou algo do tipo, eu tinha anotado, mas esqueci
    // depois dividir a memória em substrings de 16 bits
    // usando o program counter, pode provavelmente mover o ponteiro par a próxima instrução
    // ler o primeiro bit para saber a formatação dos registradores e operandos

    return 0;
}