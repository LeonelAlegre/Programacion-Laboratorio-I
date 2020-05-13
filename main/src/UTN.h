/*
 * UTN.h
 *
 *  Created on: 7 may. 2020
 *      Author: Leonel
 */

#ifndef UTN_H_
#define UTN_H_

int  utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int  utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int  utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int utn_getArrayInt(int* pArray, int size, char* mensaje, char* error, int min, int max, int reintentos);
int utn_printArrayInt(int* pArray, int size);
int printArrayFlotante(float* pArray, int size);
int initArrayFlotante(float* pArray, int size, float valorInicial);
int utn_ordenarArrayIntDesc(int* pArray, int size);
int utn_ordenarArrayIntAsc(int* pArray, int size);

int getStringLetras(char* pString, char* mensaje);

int myGets(char* cadena, int longitud);

#endif /* UTN_H_ */
