//
// Created by fflv on 25/07/25.

#include "syscall.h"

void syscall_routine(uint16_t *memory)
{
    uint16_t c = gen_register[1];
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
    default:
        printf("System call code %d doesn't exist\n", pc);
        free(memory);
        exit(1);
    }


}
