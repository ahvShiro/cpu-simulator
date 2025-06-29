#include "lib.h"
#include "fetch.h"
#include "reg.h"

uint16_t get_next_instruction(uint16_t *memory){
    uint16_t cur_memory = memory[2]; //substituir 2 pelo program counter
    memcpy(instruction, cur_memory, sizeof(cur_memory));
}