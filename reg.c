#include "lib.h"
#include "reg.h"

RegFile start_reg_file()
{
    RegFile regF;
    regF.pc = 1;
    regF.r0 = 0;
    regF.r1 = 0;
    regF.r2 = 0;
    regF.r3 = 0;
    regF.r4 = 0;
    regF.r5 = 0;
    regF.r6 = 0;
    regF.r7 = 0;
    return regF;
}