#include "lib.h"
#include "reg.h"

RegFile start_reg_file()
{
    RegFile regF;
    regF.pc = 1;
    regF.r1 = 0;
    regF.r2 = 0;
    return regF;
}