#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "lib.h"

int main (int argc, char **argv)
{
	if (argc != 2) {
		printf("usage: %s [bin_name]\n", argv[0]);
		exit(1);
	}

	return 0;
}