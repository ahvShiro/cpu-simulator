// SIMULADOR DE PROCESSADOR

#include "lib.h"
#include "reg.h"
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
    const uint16_t size = fsize(fp);
    fclose(fp);
    //inicializa os registradores
    RegFile rf = {
        1,0,0,0,0,0,0,0,0
    };
    
    uint16_t *memory = malloc(size * sizeof(uint16_t)); // malloc usa metade do tamanho

    load_binary_to_memory(argv[1], memory, size);

    program_loop(size, memory, rf);

    free(memory);
    return 0;
}
