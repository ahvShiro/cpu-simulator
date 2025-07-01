#include "lib.h"
#include "reg.h"

RegFile start_reg_file()
{
    RegFile regF;
    regF.pc = 0;
    regF.r1 = 0;
    regF.r2 = 0;
    return regF;
}