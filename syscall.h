//
// Created by fflv on 25/07/25.
//

#ifndef __HEADER_SYSCALL_H__
#define __HEADER_SYSCALL_H__

#include "reg.h"

void syscall_routine(RegFile rf, uint16_t *memory);

#endif //__HEADER_SYSCALL_H__
