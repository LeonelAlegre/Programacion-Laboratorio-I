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
#include <string.h>
#include "UTN.h"

#define TAM 9

int main(void) {
	float array[TAM];

	initArrayFlotante(array, TAM, -10);
	printArrayFlotante(array, TAM);

	system("pause");
	return EXIT_SUCCESS;
}














