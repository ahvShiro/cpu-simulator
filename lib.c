#include <stdlib.h>

#include "lib.h"

void load_binary_to_memory (const char *fname, void *memory, const uint32_t mem_size)
{
	FILE *fp;
	uint32_t bsize;
	
	fp = fopen(fname, "rb");

	if (!fp) {
		printf("cannot open file %s\n", fname);
		exit(1);
	}

	fseek(fp, 0, SEEK_END);
	bsize = ftell(fp);
	
	printf("file %s has %u bytes\n", fname, bsize);

	if (bsize > mem_size) {
		printf("error!\nMax file fize must be 0x0000FFFF\n");
		exit(1);
	}

	rewind(fp);

	if (fread(memory, 1, bsize, fp) != bsize) {
		printf("error loading file %s\n", fname);
		exit(1);
	}

	fclose(fp);
}


int fsize(FILE * fp)
{
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	rewind(fp);
	
	return size;
}

void print_memory(uint16_t *memory, uint32_t size)
{
	for (int i = 0; i < size; i++)
    {
        printf("Instrução %d: 0b%016b\n", i, memory[i]);
    }
}