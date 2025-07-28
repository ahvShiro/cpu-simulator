//
// Created by fflv on 25/07/25.

#include "syscall.h"

void syscall_routine(RegFile * rf, uint16_t *memory)
{
    uint16_t c = rf->r1;
    switch (rf->r0)
    {
    case 0:
        free(memory);
        exit(0);
    case 1:
        // print string
        while (memory[c] != 0)
        {
            printf("%c", memory[c]);
            c++;
        }
        break;
    case 2:
        //print integer
        while (memory[c] != 0)
        {
            printf("%d", memory[c]);
            c++;

        }
        break;
    case 3:
        // print string with newline
        while (memory[c] != 0)
        {
            printf("%c", memory[c]);
            c++;

        }
        printf("\n");
        break;
    default:
        printf("System call code %d doesn't exist\n", rf->pc);
        free(memory);
        exit(1);
    }


}
