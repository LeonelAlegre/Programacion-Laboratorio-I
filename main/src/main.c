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
	int respuesta;
	float resultado;


	while(1){
		respuesta = utn_getFloat(&resultado, "ingresar flotante: ","error\n", -5, 10, 2);
		printf("Resultado: %.2f -- Respuesta %d\n",resultado, respuesta);
	}

	system("pause");
	return EXIT_SUCCESS;
}






