#ifndef __HEADER_LIB_H__
#define __HEADER_LIB_H__

#include <stdint.h>

void load_binary_to_memory (const char *fname, void *memory, const uint32_t mem_size);

static inline uint16_t extract_bits (const uint16_t v, const uint8_t bstart, const uint8_t blength)
{
	const uint16_t mask = (1 << blength) - 1;

	return ((v >> bstart) & mask);
}

#endif