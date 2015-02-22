#define ALMACEN_H
#ifdef ALMACEN_H
#include <fstream>
#include <string>
#include "lista.h"

/*Procedimiento que carga los valores de los productos de un fichero en una lista
Entrada: lista a completar
Salida: lista rellena con los productos del fichero
*/
void cargarAlmacen ( tLista& lista);

/*Procedimiento que guarda en un archivo los productos de una lista
Entrada: la lista
Salida: creacion del fichero
*/
void guardarAlmacen ( tLista& lista);

/*Procedimiento que se encarga de las compras que se realizan
Entrada: una lista y una posicion de la lista
Salida: la lista con las modificaciones de compras realizadas en esa posicion
*/
void gestionarEntrada ( tLista& lista, int posicion);

/*Procedimiento que se encarga de las ventas que se realizan
Entrada: una lista y una posicion d ela lista
Salida: la lista con las modificaciones de ventas realizadas en la posicion
*/
void gestionarSalida ( tLista& lista, int posicion);


void informeEntradas ( int clave, int& cantidad);
void informeSalidas ( int clave, int& cantidad);
void generarListado ( tLista lista, string cadena);

#endif