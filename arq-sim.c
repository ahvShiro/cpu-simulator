// SIMULADOR DE PROCESSADOR

#include "lib.h"
#include "execute.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: %s [bin_name]\n", argv[0]);
        exit(1);
    }

    // tamanho do arquivo
    FILE * fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("File invalid or doesn't exist\n");
        exit(1);
    }
    const uint16_t size = fsize(fp);
    size_mem = size;
    fclose(fp);

    uint16_t *memory = malloc(size * sizeof(uint16_t)); // malloc usa metade do tamanho

    load_binary_to_memory(argv[1], memory, size);

    program_loop(memory);

    free(memory);
    return 0;
}
