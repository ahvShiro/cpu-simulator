#include <stdlib.h>

#include "lib.h"

void load_binary_to_memory (const char *fname, void *memory, const uint32_t mem_size)
{
	FILE *fp = fopen(fname, "rb");

	if (!fp) {
		printf("cannot open file %s\n", fname);
		exit(1);
	}

	fseek(fp, 0, SEEK_END);
	const uint32_t bsize = ftell(fp);
	
	printf("file %s has %u bytes\n", fname, bsize);

	if (bsize > mem_size) {
		printf("error!\nMax file size must be 0x0000FFFF\n");
		exit(1);
	}

	rewind(fp);

	if (fread(memory, 1, bsize, fp) != bsize) {
		printf("error loading file %s\n", fname);
		exit(1);
	}

	fclose(fp);
}

void print_memory(uint16_t * memory, size_t size_mem) {
    for (int i = 1; i < size_mem; i++) {
        if (memory[i] == 0) {
            break;
        }
        printf("%d, ", memory[i]);
    }
    printf("\n");
}

int fsize(FILE *pf)
{
	fseek(pf, 0, SEEK_END);
	long size = ftell(pf);
	rewind(pf);
	
	return size;
}

/*
void print_memory(const uint16_t *memory, uint32_t index)
{
    printf("Instrução %d: 0b%016b\n", index, memory[index]);
}

void print_memory_all (const uint16_t *memory, uint32_t size)
{
	for (int i = 0; i < size; i++)
    {
        printf("Instrução %d: 0b%016b\n", i, memory[i]);
    }
}
*/