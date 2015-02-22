#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include "fecha.h"
using namespace std;

const int MAX_CAD = 80;
typedef char tCadena[MAX_CAD];

typedef struct {
	int clave;
	tCadena identificacion;
	int existencias;
	int unidadesCompradas;
	int unidadesVendidas;
	tFecha fechUltCompra;
	double precUltCompra;
	tFecha fechUltVenta;
	double precUltVenta;
} tProducto;

//***********PROTOTIPOS************//

/*Procedimiento que lee por consola los datos basicos de un producto e inicializa el resto a 0.
Entrada: producto.
Salida: clave y nombre del producto inicializados por el usuario y
		el resto de elementos de producto inicializados a 0.
*/
void leerNuevoProducto( tProducto producto);

/*Procediemiento que muestra por consola los datos completos de un producto.
Entrada: producto que se desea mostrar
Salida: escritura por consola de los datos de dicho producto
*/
void mostrarProducto( tProducto producto);


	
#endif