#include <iostream>
#include "lista.h"
using namespace std;

void inicializar ( tLista& lista){
	lista.cont = 0;
};

void insertarProducto (tLista& lista, tProducto producto){
	bool lleno;
	int i = 0;

	if ( lista.cont == N){
		lleno = true;
	}
	else{
		while ( (i < lista.cont) && lista.elementos [i].clave < producto.clave){
			i++;
		}
		for ( int j = lista.cont; j > i; j--){

			lista.elementos[j] = lista.elementos [j -1];
		}
		lista.elementos[i] = producto;
		lista.cont++;
	}

};

void buscarProducto ( tLista lista,int clave, bool& encontrado, int& posicion){
	int ini = 0;
	int fin = lista.cont -1;
	int mitad;
	
	encontrado = false;
	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin)/ 2; // División entera

		if (lista.elementos [mitad].clave == clave) {
			encontrado = true;
			posicion = mitad;
		}
		else if (clave < lista.elementos[mitad].clave) 
			fin = mitad - 1;
		else 
			ini = mitad + 1;
	}
};

void eliminarProducto ( tLista& lista, int clave, bool encontrado){
	int i = 0;
	tProducto producto;

	producto.clave = clave;

	while ( lista.elementos [i].clave < producto.clave )
		i++;
	if ( lista.elementos[i].clave == producto.clave){
		encontrado = true;
		for ( int j = i+1; j < lista.cont; j++){
			lista.elementos[j-1] = lista.elementos [j];
		}
		lista.cont--;
	}else {
		encontrado = false;
		cout << "El producto no existe." << endl;
	}
};

void mostrarListaProductos ( tLista lista){
	
	for ( int i = 0; i < lista.cont; i++){
		cout << "ARTICULO " << i+1 << ":" << endl;
		cout << "Nombre del producto: " << lista.elementos[i].identificacion << endl;
		cout << "Clave del producto: " << lista.elementos[i].clave << endl;
		cout << "Existencias del producto: " << lista.elementos[i].existencias << endl;
		cout << "Unidades compradas: " << lista.elementos[i].unidadesCompradas << endl;
		cout << "Unidades vendidas: " << lista.elementos[i].unidadesVendidas << endl;
		cout << "Fecha de la ultima compra: " << lista.elementos[i].fechUltCompra.dia << " " << lista.elementos[i].fechUltCompra.mes << " " << lista.elementos[i].fechUltCompra.año << endl;
		cout << "Precio unitario de la ultima compra: " << lista.elementos[i].precUltCompra << endl;
		cout << "Fecha de la ultima venta: " << lista.elementos[i].fechUltVenta.dia << " " << lista.elementos[i].fechUltVenta.mes << " " << lista.elementos[i].fechUltVenta.año << endl;
		cout << "Precio unitario de la ultima venta: " << lista.elementos[i].precUltVenta << endl;
	}
};