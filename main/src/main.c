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

int main(void) {
	float flotante;
	int respuesta;

	respuesta = utn_getFloat(&flotante,"Ingrese flotante: ","Error el numero debe ser desde 0.5 hasta 99.99\n", 0.5, 99.99, 3);

	if(respuesta == 0){
		printf("El flotante es: %.2f\n", flotante);
	}else{
		printf("Error\n");
	}

	system("pause");
	return EXIT_SUCCESS;
}









