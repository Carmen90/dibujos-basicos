#include <iostream>
using namespace std;
#include "producto.h"


void leerNuevoProducto( tProducto producto){
//	bool claveCorrecta;
	string nombre;
	
	//Pide la clave del producto
	cout << "Introduce la calve del producto (hasta 5 digitos): ";
	cin >> producto.clave;
	cout << endl;
	//Comprueba que la clave sea correcta

	if ( producto.clave < 0 || producto.clave > 99999)
		cout << "Error, la clave tiene que tener de 0 a 5 digitos." << endl;
	else{

		//Pide el nombre del producto
		cout << "Introduce el nombre del producto: ";
		getline( cin, nombre);
		cout << endl;
		producto.identificacion = nombre;

		//Inicializacion del resto de datos del producto
		producto.existencias = 0;
		producto.precUltCompra = 0;
		producto.fechUltCompra.dia = 00;
		producto.fechUltCompra.mes = 00;
		producto.fechUltCompra.año = 0000;
		producto.fechUltVenta.dia = 00;
		producto.fechUltVenta.mes = 00;
		producto.fechUltVenta.año = 0000;
		producto.precUltVenta = 0;
		producto.unidadesCompradas = 0;
		producto.unidadesVendidas = 0;
	
	}
};


void mostrarProducto ( tProducto producto){
	
	cout << "Codigo del producto: " << producto.clave << endl;
	cout << "Identificacion: " << producto.identificacion << endl;
	cout << "Existencias: " << producto.existencias << endl;
	cout << "Total unidades adquiridas: " << producto.unidadesCompradas << endl;
	cout << "Fecha de la ultima adquisicion: " << producto.fechUltCompra.dia << " " << producto.fechUltCompra.mes << " " << producto.fechUltCompra.año << endl;
	cout << "Precio de la ultima adquisicion: " << producto.precUltCompra << endl;
	cout <<	"Total unidades vendidas: " << producto.unidadesVendidas << endl;
	cout << "Fecha de la ultima venta: " << producto.fechUltVenta.dia << " " << producto.fechUltVenta.mes << " " << producto.fechUltVenta.año << endl;
	cout << "Precio de la ultima venta: " << producto.precUltVenta << endl;


};