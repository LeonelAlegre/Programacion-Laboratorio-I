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
	int resultado;

	for(int i = 0; i < 5; i++){
		system("cls");
		printf("iteracion: %d ***************\n", i);
		utn_getNumero(&resultado, "ingresar entero: ", "error\n", -10, 99, 2);
		printf("numero: %d\n", resultado);
		system("pause");

	}


/*
	utn_getArrayInt(arrayInt, TAM, "ingresar entero: ","error.", 0, 99, 1);
	utn_printArrayInt(arrayInt, TAM);
*/

	return EXIT_SUCCESS;
}





