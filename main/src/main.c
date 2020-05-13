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
	char cadena[256];
	int i = 0;
	while(1){
		system("cls");
		printf("iteracion: %d ***********\n", i);

		getStringLetras(cadena, "ingresar cadena: ");

		printf("Cadena: %s\n", cadena);
		i++;
		system("pause");
	}
	system("pause");
	return EXIT_SUCCESS;
}















