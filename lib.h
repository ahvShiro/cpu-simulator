#ifndef __HEADER_LIB_H__
#define __HEADER_LIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#define LENGTH(a) (sizeof(a) / sizeof((a)[0]))

void load_binary_to_memory (const char *fname, void *memory, const uint32_t mem_size);

int fsize(FILE *pf);

void print_memory (const uint16_t *memory, uint32_t size);

static inline uint16_t extract_bits (const uint16_t v, const uint8_t bstart, const uint8_t blength)
{
	const uint16_t mask = (1 << blength) - 1;

	return ((v >> bstart) & mask);
}

#endif