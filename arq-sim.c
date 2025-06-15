#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "lib.h"

/*
* FORMATAÇÃO DA INSTRUÇÃO:
* 1 bit de formato
*
* Formato R = 0
* 6 bits de opcode
* 3 bits de destino
* 3 bits de operando
* 3 bits de operando
*
* Formato I = 1
* 2 bits opcode
* 3 bits registrador
* 10 bits imediatos
*
* NO TOTAL toda instrução tem 16 bits (0-15)
*/


int fsize(FILE * pf)
{
	
	fseek(pf, 0, SEEK_SET);
	int size = ftell(pf);
	fseek(pf, 0, SEEK_SET);
	
	return size;
}

int main (int argc, char **argv)
{
	if (argc != 2) {
		printf("usage: %s [bin_name]\n", argv[0]);
		exit(1);
	}

	FILE * pf = fopen(argv[1], "r");

	int size = fsize(pf);

	// primeira coisa a fazer é saber o tamanho do arquivo

	u_char mem_buffer[size];
	
	load_binary_to_memory(argv[1], mem_buffer, 100);
	// a instrução inicia no indice 1 não 0 ou algo do tipo, eu tinha anotado mas esqueci

	return 0;
}