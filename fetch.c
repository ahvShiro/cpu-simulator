#include "fetch.h"
#include "reg.h"

void fetch(Fetch * fet, uint16_t * memory){
   fet->instruction_value = memory[pc];
   
}
