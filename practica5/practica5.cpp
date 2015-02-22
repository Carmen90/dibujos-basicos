/*	Nombre: Carmen Acosta Morales
	DNI: 50770146-s
	Laboratorio: 1
*/

#include <iostream>
#include "almacen.h"
#include <string>

using namespace std;

/**********	DECLARACION DE PROTOTIPOS ***********/

/*Funcion que se encarga de mostrar el menu principal y devuelve la opcion elegida por el usuario
Entrada: ningun parametro
Salida: opcion elegida por el usuario
*/
int menuPrincipal ();

/*Funcion que se encarga de mostrar el submenu 1 y devuelve la opcion que elige el usuario
Entrada: ningun parametro
Salida: opcion elegida
*/
int menu1 ();

/*Funcion que se encarga de mostrar el submenu 2 y devuelve la opcion elegida por el usuario
Entrada: ningun parametro
Salida: opcion elegida
*/
int menu2 ();

/*Procedimiento que se encarga de borrar la consola
Entrada: ningun parametro
Salida: borra la consola
*/
void borrarConsola ();

/*Procedimiento que se encarga de implementar la opcion 1 del menu principal
Entrada: lista de productos
Salida: la misma lista con las modificaciones que se hayan realizado en ella
*/
void eleccionMenu1 ( tLista& lista);

/*Procedimiento que se encarga de añadir un nuevo producto en una lista
Entrada: lista en la que se desea añadir el producto
Salida: lista con el nuevo producto
*/
void añadirProducto ( tLista& lista);

/*Procedimiento que muestra los datos de un determinado producto por consola
Entrada: lista en la que se encuentra el prodcucto
Salida: muestra por pantalla los datos del producto
*/
void consultarDatosProducto ( tLista lista);

/*Procedimiento que se encarga de eliminar un producto que cumple unos determinados requisitos
Entrada: lista en la que se encuentra el producto
Salida: lista sin el producto
*/
void opcionEliminar ( tLista& lista);

/*Procedimiento que modifica los datos de un producto perteneciente a una lista
Entrada: lista en la que se encuentra el producto
Salida: lista modificada
*/
void modificarDatos (tLista& lista);

/*Procedimiento que muestra la posicion de un producto y sus caracteristicas
Entrada: lista y posicion en la que se encuentra
Salida: muestra por pantalla las caracteristicas de un producto
*/
void productoEnLista (tLista lista, int posicion);

/*Procedimiento que pide los datos del codigo de un producto y comprueba que son validos
Entrada: ningun parametro
Salida: clave introducida por el usuario y si es correcta o no
*/
void datosCodigo ( int& clave, bool& correcto);

/*Procedimiento que lee los datos de una identificacion metida por el usuario
Entrada:
Salida: string indicando la identificacion del producto
*/
void datosIdentificacion ( tCadena& nombre);

/*Procedimiento que se encarga de realizar una compra y anotarla en un fichero
Entrada: lista sobre la que se efectua la compra
Salida: la lista modificada segun el producto comprado
*/
void entradaProductos ( tLista& lista);

/*Procedimiento que realiza una venta y la anota en un fichero 
Entrada: lista sobre la que se realiza la venta
Salida: lista modificada segun la venta realizada
*/
void salidaProductos ( tLista& lista);

/*Procediemiento que muestra los detalles de todos los productos de una lista
Entrada: la lista a mostrar
Salida: muestra por consola los productos
*/
void mostrarTodosProductos ( tLista lista);

/*Procedimiento que se encarga de implementar las distintas opciones del submenu 2
Entrada: lista sobre la que se trabaja
Salida:
*/
void eleccionMenu2 ( tLista lista);

/*Procedimiento que se encarga de escribir en un archivo una lista de productos ordenados por codigo
Entrada: lista a mostrar
Salida: creacion del fichero de los elementos de la lista
*/
void listadoPorCodigo ( tLista lista);

/*Escribe en un fichero una lista de productos ordenados por identificacion
Entrada: lista de productos
Salida: fichero con la lista ordenada
*/
void listadoPorProductos ( tLista lista);

/*Escribe en un fichero las compras realizadas sobre un determinado producto acumulando las cantidades y comparandola
	con el valor de acumulado de unidades compradas
Entrada: lista en la que se encuentra el producto
Salida: fichero de compras del producto
*/
void listadoEntradas (tLista lista);

/*Escribe en un fichero las ventas realizadas sobre un determinado producto acumulando las cantidades y comparandola
	con el valor de acumulado de unidades vendidas
Entrada: lista en la que se encuentra el producto
Salida: fichero de ventas del producto
*/
void listadoSalidas ( tLista lista);


int main(){
	int opcion; 
	tLista lista;

	inicializar (lista);
	cargarAlmacen (lista);

	do{
		opcion = menuPrincipal();

			switch (opcion){
				
				case 1: eleccionMenu1 ( lista);
					break;
				case 2: eleccionMenu2 (lista);
					break;
			}

	borrarConsola ();

	}while ( opcion != 0);

	guardarAlmacen (lista);
return 0;
};

int menuPrincipal (){
	int opcion;

	cout << "1 - Mantenimiento." << endl;
	cout << "2 - Informes." << endl;
	cout << "0 - Terminar." << endl;
	cin >> opcion;

return opcion;
};

int menu1 (){
	int opcion;

	cout << "1 - Nuevo producto." << endl;
	cout << "2 - Consultar los datos de un producto." << endl;
	cout << "3 - Eliminar un producto." << endl;
	cout << "4 - Modificar los datos de un producto." << endl;
	cout << "5 - Entrada de productos." << endl;
	cout << "6 - Salida de productos." << endl;
	cout << "7 - Mostrar todos los productos por consola." << endl;
	cout << "0 - Volver al menu principal." << endl;
	cout << "Elige: ";
	cin >> opcion;
	cout << endl;

return opcion;
};

int menu2 (){
	int opcion;

	cout << "1 - Listado General ordenado por codigo." << endl;
	cout << "2 - Listado General ordenado por identificacion de producto." << endl;
	cout << "3 - Listado de Entradas." << endl;
	cout << "4 - Listado de Salidas." << endl;
	cout << "0 - Volver al menu principal." << endl;
	cout << "Elige: ";
	cin >> opcion;
	cout << endl;

return opcion;
};

void borrarConsola ( ) {
	char borrar;
	// Pregunta al usuario si desea borrar la consola
	cout << "Quieres borrar la pantalla? S/N" << endl;
	cin >> borrar;

	// Comprueba el valor metido por el usuario
	if ( borrar == 's' || borrar == 'S' ) 
		
		system ("cls");
				
	else if ( borrar == 'n' || borrar == 'N')
		cout << "De acuerdo, Que opcion elige?: " << endl;
	else{
		// Si el usuario mete un valor no valido vuelve a preguntar si desea o no borrar la consola
		cout << "Opcion no valida" << endl;
		borrarConsola ();
	}
};

void eleccionMenu1 ( tLista& lista){
	int opcion;

	do {
		opcion = menu1();
		switch (opcion) {
			
			case 0:
				break;
			case 1:	añadirProducto (lista);
				break;
			case 2: consultarDatosProducto (lista);
				break;
			case 3: opcionEliminar (lista);
				break;
			case 4: modificarDatos (lista);
				break;
			case 5: entradaProductos (lista);
				break;
			case 6: salidaProductos (lista);
				break;
			case 7: mostrarTodosProductos (lista);
				break;
			default: cout << "La opcion elegida no es correcta." << endl;
				break;
			}	
	
		if ( opcion != 0)
			borrarConsola ();

	}while ( opcion != 0);

};

void añadirProducto ( tLista& lista){
	int clave, posicion, ini = 0, fin;
	bool encontrado, correcto;
	tCadena nombre;
	tProducto producto;
	char c;

	//Pide los datos del codigo del nuevo producto
	datosCodigo ( clave, correcto);
	//Comprueba que no este ya en la lista
	fin = lista.cont-1;
	encontrado = buscarProducto ( lista, clave, ini, fin, posicion);

	if ( correcto){
		if ( encontrado) 
			cout << "Error, la clave ya existe en la lista." << endl;
		else {
			//Pide los datos para añadir la identificacion
			datosIdentificacion (nombre);
			
			//Asigna los valores de clave e identificacion introducidos por el usuario
			producto.clave = clave;

			for ( int i = 0; i < sizeof(nombre); i++){
				producto.identificacion[i] = nombre[i];
			}

			//Inicializa a 0 el resto de los componentes
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

			//Pregunta si quieres insertar el nuevo producto
			cout << producto.clave << " " << producto.identificacion << " Insertar S/N?." << endl;
			cin >> c;

			if ( c == 's' || c == 'S')
				insertarProducto ( lista, producto);
		}
	}
};

void consultarDatosProducto ( tLista lista){
	int clave, posicion, ini = 0, fin;
	bool encontrado, correcto;

	fin = lista.cont -1;
	//Pide la clave del producto
	datosCodigo ( clave, correcto);
	if ( correcto){
		//Comprueba que el producto esta en la lista
		encontrado = buscarProducto (lista, clave, ini, fin, posicion);
		if (!encontrado)
			cout << "El codigo no esta en la lista." << endl;
		else {
			//Muestra un producto de una determinada posicion
			productoEnLista (lista, posicion);
		
			}
		}
};

void opcionEliminar ( tLista& lista){
	int clave, posicion, ini = 0, fin;
	bool encontrado, correcto;
	char c;

	fin = lista.cont -1;
	//Pide el codigo del producto
	datosCodigo (clave, correcto);
	//Comprueba que existe en la lista
	encontrado = buscarProducto (lista, clave, ini, fin, posicion);
		
	if (correcto){
		if ( !encontrado)
			cout << "El codigo no existe en la lista." << endl;
		else {
				cout << "Seguro que quiere borrar el producto (S/N)?" << endl;
				cin >> c;
		
			if ( c == 'S' || c == 's'){

				//Comprueba que el producto no tenga existencias
				if ( lista.elementos[posicion].existencias != 0)
					cout << "Error, el producto tiene existencias en el almacen." << endl;
				else 
					eliminarProducto (lista, clave, encontrado);
			}
			else if ( c != 'N' && c != 'n'){
				cout << "Opcion incorrecta." << endl;
				opcionEliminar ( lista);
			}
		}
	}
};

void modificarDatos (tLista& lista){
	int clave, posicion, unidades, ini = 0, fin;
	bool encontrado, correcto;
	tCadena nombre;
	char c, t;

	//Pide el codigo del producto a modificar
	datosCodigo ( clave, correcto);

	fin = lista.cont -1;

	if ( correcto){
		//Se asegura de que el producto esta en la lista
		encontrado = buscarProducto (lista, clave, ini, fin, posicion);
		if (!encontrado)
			cout << "El codigo no esta en la lista." << endl;
		else {
			//Muestra el producto que se kiere modificar
			productoEnLista (lista, posicion);
			cout << "Modificar Identificacion (S/N)?: " << endl;
			cin >> c;
			if ( c == 's' || c == 'S'){
				//Pide la nueva identificacion del producto
				datosIdentificacion ( nombre);
				
				for ( int i = 0; i < sizeof(nombre); i++){
					lista.elementos[posicion].identificacion[i] = nombre[i];
				}
			}
			cout << "Modificar Existencias (S/N)?: " << endl;
			cin >> t;
			if ( t == 's' || t == 'S'){
				cout << "Numero de unidades: ";
				cin >> unidades;
				cout << endl;

				lista.elementos[posicion].existencias = unidades;
			
			}

		}
	}
};

void productoEnLista ( tLista lista, int posicion){
	tProducto producto;

		cout << "Producto encontrado en la posicion " << posicion + 1 << endl;
		//Asigna a un producto los valores dentro de una posicion
		producto = lista.elementos[posicion];

		//Muestra los datos de ese producto
		mostrarProducto ( producto);
		cout << endl;

};

void datosCodigo ( int& clave, bool& correcto){

	cout << "Introduce el codigo del producto: ";
	cin >> clave;
	cout << endl;

	if ( clave < 0 || clave > 99999){
		cout << "El codigo introducido no es correcto." << endl;
		correcto = false;
	}
	else 
		correcto = true;

};

void datosIdentificacion ( tCadena& nombre){
	
	cout << "Introduzca la identificacion del producto (hasta 80 caracteres): ";
	cin.ignore(80,'\n');
	cin.getline (nombre, MAX_CAD);
	cout << endl;

};

void entradaProductos ( tLista& lista){
	int clave, posicion, ini = 0, fin;
	ofstream archivo;
	bool correcto, encontrado;

	fin = lista.cont -1;

	archivo.open ( "entradas_ALM.txt", ios::app);
	
	
	if (!archivo.is_open())
		cout << "Error en la apertura del fichero Entradas." << endl;
	else{
		//Pide el codigo de un producto
		datosCodigo (clave, correcto);
		if ( correcto){
			//Se asegura de que el producto esta en la lista
			encontrado = buscarProducto (lista, clave, ini, fin, posicion);

			if (!encontrado)
				cout << "El codigo no esta en la lista." << endl;
			else {
				//Guarda los movimientos de una compra en la posicion de la lista correspondiente
				gestionarEntrada (lista, posicion);

				//Escribe en un fichero la compra realizada
				archivo << lista.elementos[posicion].clave << '\t' << lista.elementos[posicion].existencias << '\t' 
					<< lista.elementos[posicion].unidadesCompradas << '\t'
					<< lista.elementos[posicion].fechUltCompra.dia << " " << lista.elementos[posicion].fechUltCompra.mes << " "
					<< lista.elementos[posicion].fechUltCompra.año << '\t' << lista.elementos[posicion].precUltCompra << endl;
			}
		}
	}
	archivo.close();
};

void salidaProductos ( tLista& lista){
	int clave, posicion, ini = 0, fin;
	ofstream archivo;
	bool correcto, encontrado;

	fin = lista.cont-1;

	archivo.open ( "salidas_ALM.txt", ios::app);
	
	
	if (!archivo.is_open())
		cout << "Error en la apertura del fichero Salidas." << endl;
	else{
			//Pide el codigo de un producto
			datosCodigo (clave, correcto);

			if ( correcto){
				//Se asegura de que el producto esta en la lista
				encontrado = buscarProducto (lista, clave, ini, fin, posicion);

				if (!encontrado)
					cout << "El codigo no esta en la lista." << endl;
				else {
					//Guarda los movimientos de una venta en la posicion de la lista correspondiente
					gestionarSalida ( lista, posicion);

					//Escribe en un fichero la venta realizada
					archivo << lista.elementos[posicion].clave << '\t' << lista.elementos[posicion].existencias << '\t'
						<< lista.elementos[posicion].fechUltVenta.dia << " " << lista.elementos[posicion].fechUltVenta.mes << " "
						<< lista.elementos[posicion].fechUltVenta.año << '\t' << lista.elementos[posicion].precUltVenta << endl;
				}
			}
		}
	
	archivo.close();
};

void mostrarTodosProductos ( tLista lista){
	tProducto producto;

	for ( int i = 0; i < lista.cont; i++){
		productoEnLista ( lista, i);
	}

};

void eleccionMenu2 (tLista lista){
	int opcion;

	do {
		opcion = menu2();
		switch (opcion) {
			
			case 0:
				break;
			case 1:	listadoPorCodigo (lista);
				break;
			case 2: listadoPorProductos (lista);
				break;
			case 3: listadoEntradas ( lista);
				break;
			case 4: listadoSalidas (lista);
				break;
			default: cout << "La opcion elegida no es valida" << endl;
				break;
			} 
		if ( opcion != 0)
			borrarConsola ();

	}while ( opcion != 0);

};

void listadoPorCodigo ( tLista lista){
	string cadena;

	cadena = "codigo";
	
	generarListado (lista, cadena);

};

void listadoPorProductos ( tLista lista){
	string cadena;

	cadena = "producto";

	generarListado ( lista, cadena);

}

void listadoEntradas (tLista lista){
	int clave, posicion, cantidad, ini = 0, fin;
	bool correcto, encontrado;

	fin = lista.cont-1;

	//Pide el codigo de un producto
	datosCodigo (clave, correcto);
	if (correcto){
		//Se asegura de que el producto esta en la lista
		encontrado = buscarProducto ( lista, clave, ini, fin, posicion);

		if ( encontrado){

			informeEntradas ( clave, cantidad);
			
			//Comprueba que el archivo de entradas coincide con las unidades de compra
			if ( cantidad != lista.elementos[posicion].unidadesCompradas)
				cout << "ERROR" << endl;
			else
				cout << "CORRECTO" << endl;
		}
	}
}

void listadoSalidas ( tLista lista){
	int clave, posicion, cantidad, ini = 0, fin;
	bool correcto, encontrado;

	fin = lista.cont -1;
	//Pide el codigo de un producto
	datosCodigo (clave, correcto);
	if (correcto){
		//Se asegura de que el producto esta en la lista
		encontrado = buscarProducto ( lista, clave, ini, fin, posicion);

		if ( encontrado){
		
			informeSalidas (clave, cantidad);

			//Comprueba que el archivo de salidas coincide con las unidades de venta
			if ( cantidad != lista.elementos[posicion].unidadesVendidas)
				cout << "ERROR" << endl;
			else
				cout << "CORRECTO" << endl;
		}
	}


}