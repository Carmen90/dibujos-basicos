#include <iostream>
#include "lista.h"
using namespace std;

void inicializar ( tLista& lista){
	lista.cont = 0;
	lista.capacidad = N;
	lista.elementos = new tProducto [N];

};

void insertarProducto (tLista& lista, tProducto producto){
	bool lleno, encontrado;
	int i = 0, ini = 0, fin, pos, clave;

	clave = producto.clave;
	fin = lista.cont -1;

	if ( lista.cont == N){
		redimensionarArray ( lista);
		insertarProducto (lista, producto);
		lleno = true;
	}
	else{
		encontrado = buscarProducto ( lista, clave, ini, fin, pos);
		for ( int j = lista.cont; j > pos; j--){

			lista.elementos[j] = lista.elementos [j -1];
		}
		lista.elementos[pos] = producto;
		lista.cont++;
	}

};

bool buscarProducto ( tLista lista, int clave, int ini, int fin, int& pos) {
	bool encontrado = false;
	
	pos = 0;
	
	if ( ini > fin ){
		pos = ini;
		return encontrado;
	}
	else {
		int mitad = (ini + fin)/2;
		
		if ( clave == lista.elementos [mitad].clave){
			encontrado = true;
			return encontrado;
			pos = mitad;
		}
		else if ( clave < lista.elementos[mitad].clave)
			return buscarProducto ( lista, clave, ini, mitad - 1, pos);
		else{
			pos = mitad + 1;
			ini = mitad + 1;
			return buscarProducto ( lista, clave, ini, fin,  pos);
		}
	}
}

void eliminarProducto ( tLista& lista, int clave, bool encontrado){
	int i = 0, ini = 0, fin, pos;
	tProducto producto;

	producto.clave = clave;
	fin = lista.cont -1;

	encontrado = buscarProducto ( lista, clave, ini, fin, pos);

	if ( encontrado){
		for ( int j = pos+1; j < lista.cont; j++){
			lista.elementos[j-1] = lista.elementos [j];
		}
		lista.cont--;
	}
	else
		cout << "El producto no existe." << endl;
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

void liberarArrayDinamico ( tLista& lista){
	delete [] lista.elementos;
	lista.cont = 0;
	lista.capacidad = 0;
};

void redimensionarArray ( tLista& lista){
	tProducto* aux = new tProducto [2*N];

	for ( int i = 0; i < lista.cont; i++){
		aux[i] = lista.elementos[i];
	}

	
	tProducto* tmp = new tProducto [2*N];
	tmp = lista.elementos;
	lista.elementos = aux;
	delete [] tmp;


}