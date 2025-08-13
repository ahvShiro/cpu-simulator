//
// Created by fflv on 25/07/25.

#include "syscall.h"

void syscall_routine(uint16_t *memory)
{
    uint16_t c = gen_register[1];
    //uint16_t * tempmem;
    switch (gen_register[0])
    {
    case 0:
        free(memory);

        exit(0);
    case 1:
        // print string
        while ((char) memory[c] != 0)
        {
            printf("%c", memory[c]);
            fflush(stdout);
            c++;
        }

        break;
    case 3:
        printf("%d", gen_register[1]);
        fflush(stdout);
        break;
    case 2:
        // print string with newline
        /*
        while (memory[c] != 0)
        {
            printf("%c", memory[c]);
            fflush(stdout);
            c++;

        }
        */
        printf("\n");
        fflush(stdout);
        break;
    /*
    case 4:
        // malloc
        tempmem = realloc(memory, size_mem + c);
        if (tempmem == NULL)
        {
            printf("Malloc failed");
        } else
        {
            gen_register[1] = 0;
            gen_register[2] = size_mem + 1;
            memory = tempmem;
        }
        break;
    case 5:
        // free
        tempmem = realloc(memory, size_mem);
        if (tempmem == NULL)
        {
            printf("Malloc failed");
        } else
        {
            gen_register[1] = 0;
            memory = tempmem;
        }

        break;
        */
    default:
        printf("System call code %d doesn't exist\n", gen_register[0]);
        free(memory);
        exit(1);
    }


}
