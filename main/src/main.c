/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

#define TAM 5

int main(void) {
	int v[5];

	utn_getArrayInt(v, 5);
	utn_imprimirArrayInt(v, 5);

	system("pause");
	return EXIT_SUCCESS;
}




