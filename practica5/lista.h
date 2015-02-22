#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "producto.h"
using namespace std;

const int N = 3;

//typedef tProducto *tProdPtr;
//typedef tProdPtr tArray[N];
//MIRAR tLISTA
struct tLista{
	tProducto* elementos;
	int cont;
	int capacidad;
};

//const char BD[] = "almacen_ALM.dat";

/*Procedimiento que se encarga de inicializar una lista vacia poniendo el contador a 0
Entrada: lista a inicializar
Salida: lista inicializada
*/
void inicializar (tLista& lista);

/*Procedimiento que se encarga de insertar un nuevo producto en una lista, siguiendo el orden por codigo
Entrada: lista y producto a insertar
Salida: lista con el nuevo producto
*/
void insertarProducto ( tLista& lista, tProducto producto);

/*Procedimiento que busca un producto por su clave indicandote si lo ha encontrado o no y en que posicion
Entrada: lista en la que buscar y la clave del producto
Salida: si se ha encontrado o no y su posicion
*/
bool buscarProducto ( tLista lista, int clave, int ini, int fin, int& pos);

/*Procedimiento que borra un producto seleccionado por su clave y devuelve si se ha podido borrar o no
Entrada: lista de la que se quiere borrar el producto y clave del mismo
Salida: si se ha podido borrar y de ser asi, la lista sin ese producto
*/
void eliminarProducto ( tLista& lista, int clave, bool borrado);

/*Procedimiento que se encarga de escribir por consola una lista de productos y sus caracteristicas
Entrada: lista de productos
Salida: muestra por consola la lista
*/
void mostrarListaProductos ( tLista lista);

/*Libera el array dinamico, vacía la lista y establece su pacidad a 0
Entrada: lista a vaciar
Salida: lista vaciada
*/
void liberarArrayDinamico ( tLista& lista);

void redimensionarArray ( tLista& lista);


#endif LISTA_H