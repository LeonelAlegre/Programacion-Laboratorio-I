/*
 * UTN.c
 *
 *  Created on: 7 may. 2020
 *      Author: Leonel
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN.h"

static int esNumerica(char* cadena);
static int getInt(int* pResultado);
static int getChar(char* pResultado);

static int esLetra(char* cadena);


/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se guardara el numero
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 en caso de error
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;	//se carga el valor -1 en el caso de error
	int bufferInt;		//guarda el valor ingreso por el usuario

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){  // validacion de parametros
		while(reintentos>=0){		//si reintentos = 0 al final del primer bucle reintentos sera  = -1
			reintentos--;
			printf("%s",mensaje);	//imprime char* mensaje

			if(getInt(&bufferInt) == 0){ //llama a getInt() y guarda el valor en el buffer

				if(bufferInt >= minimo && bufferInt <= maximo){ //se comprueba que buffer este en el rango
					*pResultado = bufferInt;					//puntero pResultado guarda el valor del buffer
					retorno = 0;								//se ingreso un numero
					break;										//fin bucle
				}
			}
			printf("%s",mensajeError);	//si getInt() da falso muestra char* mensajeError
		}
	}

	return retorno;
}
/**
 * \brief Obtiene un entero ingresado por pantalla
 * \param pResultado Puntero al espacio de memoria donde se guardara el entero ingresado
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getInt(int* pResultado){
	int retorno=-1;		// -1 (ERROR)
	char buffer[64];	//guarda el valor ingresado temporalmente
	if(pResultado != NULL){		//validacion del parametro
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer)){ //si myGets() && esNumerica() son true
			*pResultado = atoi(buffer);		//se pasa el buffer a entero y se guarda en el puntero
			retorno = 0;	//0 (EXITO)
		}
	}
	return retorno;
}
/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
 * \param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de la cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*
*/
int myGets(char* cadena, int longitud){
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena){ //validacion de parametros y fgets()
		fflush(stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if(cadena[strlen(cadena)-1] == '\n'){	//se comprueba que exista ENTER en la ultima posicion
			cadena[strlen(cadena)-1] = '\0';	//termina la cadena una posicion antes
		}
		return 0;	// 0 (EXITO)
	}
	return -1;		// -1 (ERROR)
}
/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (VERDADERO) si la cadena es numerica y 0 (FALSO) si no lo es
*/
static int esNumerica(char* cadena){
	int retorno = 1;	//1 (VERDADERO)
	int i = 0;
	if(cadena != NULL && strlen(cadena) > 0){			//valida el paramatreo cadena
		if(cadena[0] == '-'){							//verifica si es negativo
			i = 1;										//se empezara a verificar despues del signo '-'
		}
		for( ; cadena[i] != '\0' ; i++){				//si posicion de la cadena no es vacio i++
			if(cadena[i] < '0' || cadena[i] > '9' ){	//verifica que se haya ingresado un numero
				retorno = 0;	//0 (FALSO)
				break;
			}
			i++;
		}
	}
	return retorno;
}
int  utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0){
		while(reintentos >= 0){
			reintentos --;
			printf("%s", mensaje);

			if(getChar(&bufferChar) == 0){
				if(bufferChar >= minimo && bufferChar <= maximo){
					*pResultado = bufferChar;
					retorno = 0;
					break;
				}
			}
			printf("%s", mensajeError);
		}

	}
	return retorno;
}
/**
 * \brief Obtiene un entero ingresado por pantalla
 * \param pResultado Puntero al espacio de memoria donde se guardara el entero ingresado
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getChar(char* pResultado){
	int retorno=-1;		// -1 (ERROR)
	char buffer[64];	//guarda el valor ingresado temporalmente
	if(pResultado != NULL){		//validacion del parametro
		if(myGets(buffer,sizeof(buffer))==0 && esLetra(buffer)){ //si myGets() && esNumerica() son true
			strcpy(pResultado, buffer);
			retorno = 0;	//0 (EXITO)
		}
	}
	return retorno;
}
/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (VERDADERO) si la cadena es numerica y 0 (FALSO) si no lo es
*/
static int esLetra(char* cadena){
	int retorno = 1;	//1 (VERDADERO)

	if(cadena != NULL && strlen(cadena) > 0){			//valida el paramatreo cadena
		for(int i = 0 ; cadena[i] != '\0' ; i++){				//si posicion de la cadena no es vacio i++
			if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') ){	//verifica que se haya ingresado un numero
				retorno = 0;	//0 (FALSO)
				break;
			}
			i++;
		}
	}
	return retorno;
}
int  utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos){
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%f", &bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else{
				printf("%s", mensajeError);
				reintentos --;
			}
		}while(reintentos >= 0);

	}
	return retorno;
}
/**
 * \brief Solicita numeros al usuario que se cargan en un array
 * \param pArray Puntero al espacio de memoria donde se guardaran los valores ingresados
 * \param mensaje Es el mensaje a ser mostrado
 * \param error Es el mensaje de Error a ser mostrado
 * \param min Es el numero minimo a ser aceptado
 * \param max Es el minimo maximo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 en caso de error
 */
int utn_getArrayInt(int* pArray, int size, char* mensaje, char* error, int min, int max, int reintentos){
	int retorno = -1;
	int buffer;
	if(pArray != NULL && size >= 0 && mensaje != NULL && error != NULL){
		for(int i = 0; i < size; i++){
			utn_getNumero(&buffer, mensaje, error, min, max, reintentos);
			pArray[i] = buffer;
		}
	retorno = 0;
	}

	return retorno;
}
/**
 * \brief Imprime por pantalla los valores de un array asignado
 * \param pArray Puntero al array a mostrar
 * \param size Es la longitud del array
 * \return Retorna 0 si se pudo imprimir o -1 en caso de error
*/
int utn_printArrayInt(int* pArray, int size){
	int retorno = -1;
	if(pArray != NULL && size >=0){
		retorno = 0;
		for(int i = 0; i < size; i++){
			printf("[DEBUG] indice: %d - Valor: %d\n",i ,pArray[i]);
		}
	}

	return retorno;
}
/**
 * \brief Ordena un array de enteros DESC
 * \param pArray Puntero al array a ordenar
 * \param size ES la longitud del array
 * \return Cantidad de iteraciones necesarias para ordenar o -1 en caso de error
*/
int utn_ordenarArrayIntDesc(int* pArray, int size){
	int flagSwap;
	int contador = 0;
	int i;
	int retorno = -1;
	int buffer;
	int newSize;
	if(pArray != NULL && size >= 0){
		newSize = size -1;
		do{
			flagSwap = 0;
			for(i = 0; i < newSize; i++){
				if(pArray[i] < pArray[i+1]){
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
				contador++;
			}
			newSize--;
		}while(flagSwap);
		retorno = contador;
	}
	return retorno;
}
/**
 * \brief Ordena un array de enteros ASC
 * \param pArray Puntero al array a ordenar
 * \param size ES la longitud del array
 * \return Cantidad de iteraciones necesarias para ordenar o -1 en caso de error
*/
int utn_ordenarArrayIntAsc(int* pArray, int size){
	int flagSwap;
	int contador = 0;
	int i;
	int retorno = -1;
	int buffer;
	int newSize;
	if(pArray != NULL && size >= 0){
		newSize = size -1;
		do{
			flagSwap = 0;
			for(i = 0; i < newSize; i++){
				if(pArray[i] > pArray[i+1]){
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
				contador++;
			}
			newSize--;
		}while(flagSwap);
		retorno = contador;
	}
	return retorno;
}




