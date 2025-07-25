//
// Created by fflv on 25/07/25.
//

#include "syscall.h"

void syscall_routine(RegFile *rf, uint16_t *memory)
{
    switch (rf->r0)
    {
    case 0:
        free(memory);
        exit(0);
    case 1:
        // print string
        uint16_t c = rf->r1;
        while (memory[c] != 0)
        {
            printf("%c", memory[c]);
            c++;

        }
        break;
    default:
        printf("System call doesn't exist");
        free(memory);
        exit(1);
    }


}
