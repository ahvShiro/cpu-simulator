// SIMULADOR DE PROCESSADOR

#include "lib.h"
#include "execute.h"
#include "decode.h"
#include "fetch.h"

//#define DEBUG
#ifdef DEBUG
#define dprint(x) printf x
#else
#define dprint(x) do{} while(0)
#endif

void fetch(Fetch * fet, uint16_t * memory){
   fet->instruction_value = memory[pc];
}

void program_loop(uint16_t *memory)
{
    while(1)
    {
        dprint(("PC: %d\n", pc));

        // print_memory(memory, size_mem);
        // print_reg();
        Fetch fet;
        Decode dec;
        Execute exe;
        
        switch (dec.stage)
        {
        case 1:
            fetch(&fet, memory);
            
            break;
        case 2:
            fetch(&fet, memory);
            decode(&fet, &dec);
            break;
        case 3:
            fetch(&fet, memory);
            decode(&fet, &dec);
            execute(&dec, &exe);
            break;
        default:
            break;
        }
        pc++;
        /*
        //decode
        int type_bit = extract_bits(instruction, 15, 16);

        if(type_bit){
            I_format ins;
            create_i_instruction(&ins, instruction);
            inst.ins = ins;
            // print_i_instruction(&ins);
            // execute
            execute_i(&inst.ins, memory);

        } else {
            R_format ins;
            create_r_instruction(&ins, instruction);
            //print_r_instruction(&ins);
            execute_r(&ins, memory);
        }
        */

    }
}


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
