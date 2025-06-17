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




int main (int argc, char **argv)
{
	printf("%d\n", argc);

	if (argc != 2) {
		printf("usage: %s [bin_name]\n", argv[0]);
		exit(1);
	}

	FILE * pf = fopen(argv[1], "r");

	int size = fsize(pf);

	// primeira coisa a fazer é saber o tamanho do arquivo

	char mem_buffer[size];

	load_binary_to_memory(argv[1], mem_buffer, size);
	// a instrução inicia no índice 1 não 0 ou algo do tipo, eu tinha anotado mas esqueci
	// depois dividir a memoria em substrings de 16 bits
	// usando o program counter, pode provavelmente mover o ponteiro par a próxima instrução
	// ler o primeiro bit para saber a formatação dos registradores e operandos


	return 0;
}