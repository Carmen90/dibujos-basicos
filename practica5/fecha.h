#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct {
	int dia;
	int mes;
	int año;
} tFecha;

/*Procedimiento que pide los datos de una fecha por consola y devuelve la fecha
Entrada: ningun parametro.
Salida: fecha dada por el usuario.
*/
void leerFecha ( tFecha& fecha);

/*Procedimiento que recive una fecha y la escribe por consola
Entrada: fecha
Salida: escribe por consola la fecha
*/
void escribirFecha( tFecha fecha);

/*Procedimiento que recive dos fechas y devuelve una tercera que es la menor de las dos anteriores
Entrada: fechas a comparar
Salida: menor de las fechas
*/
void compararFechas( tFecha fecha1, tFecha fecha2, tFecha& menor);


#endif