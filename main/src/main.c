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
	int i = 0;
	char cadena[64];
	while(i < 5){
		system("cls");
		printf("iteracion: %d ********\n", i);

		utn_getChar(cadena, "Ingresar lentra: ", "error. dato no valido\n", 'A', 'z', 2);

		printf("cadena ingresada: %s\n", cadena);

		system("pause");

		i++;
	}
	system("pause");

/*
	utn_getArrayInt(arrayInt, TAM, "ingresar entero: ","error.", 0, 99, 1);
	utn_printArrayInt(arrayInt, TAM);
*/

	system("pause");
	return EXIT_SUCCESS;
}





