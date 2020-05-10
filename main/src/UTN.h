/*
 * UTN.h
 *
 *  Created on: 7 may. 2020
 *      Author: Leonel
 */

#ifndef UTN_H_
#define UTN_H_

int  utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int  utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int  utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
void utn_getArrayInt(int array[], int size);
void utn_imprimirArrayInt(int array[], int size);

#endif /* UTN_H_ */
