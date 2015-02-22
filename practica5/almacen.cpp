#include "almacen.h"
using namespace std;



/*Procedimiento que se encarga de ordenar una lista por identificacion
Entrada: lista a ordenar
Salida: lista auxiliar ordenada por identificacion
*/
void ordenarPorProductos ( tLista lista, tLista& producto);

void cargarAlmacen ( tLista& lista){
	ifstream archivo;
	char c;	
	int i = 0;
	
	archivo.open("almacen_ALM.txt");
	if ( !archivo.is_open())
		cout << "Error en la apertura del fichero almacen." << endl;
	else {
		archivo >> lista.elementos[i].clave;

		do{
			archivo.get(c);

			archivo.getline ( lista.elementos[i].identificacion, MAX_CAD ,'\t');

			archivo >> lista.elementos[i].existencias >> lista.elementos[i].unidadesCompradas >> 
				lista.elementos[i].fechUltCompra.dia >> lista.elementos[i].fechUltCompra.mes >> lista.elementos[i].fechUltCompra.año >>
				lista.elementos[i].precUltCompra >> lista.elementos[i].unidadesVendidas >> lista.elementos[i].fechUltVenta.dia >> lista.elementos[i].fechUltVenta.mes >>
				lista.elementos[i].fechUltVenta.año >> lista.elementos[i].precUltVenta;

			i++;
			lista.cont++;
			archivo >> lista.elementos[i].clave;
		} while(!archivo.eof());
	}

	archivo.close();
}

void guardarAlmacen ( tLista& lista){
	ofstream archivo;
	string nombre;
	int i = 0;

	archivo.open ("almacen_ALM.txt");
	if ( !archivo.is_open())
		cout << "Error al guardar el fichero almacen." << endl;
	else{
		do{
			archivo << lista.elementos[i].clave << '\t' << lista.elementos[i].identificacion 
				<< '\t' << lista.elementos[i].existencias << '\t' << lista.elementos[i].unidadesCompradas 
				<< '\t'  << lista.elementos[i].fechUltCompra.dia << " " << lista.elementos[i].fechUltCompra.mes << " " 
				<< lista.elementos[i].fechUltCompra.año << '\t' << lista.elementos[i].precUltCompra << '\t'
				<< lista.elementos[i].unidadesVendidas << '\t' << lista.elementos[i].fechUltVenta.dia << " "
				<< lista.elementos[i].fechUltVenta.mes << " " << lista.elementos[i].fechUltVenta.año << '\t' 
				<< lista.elementos[i].precUltVenta << endl;
			i++;
		
		} while ( i < lista.cont);
	
	}

	archivo.close();

}

void gestionarEntrada ( tLista& lista, int posicion){
	int existencias;
	double precPorUnidad;
	tFecha fecha;

	fecha.dia = 0;
	fecha.mes = 0;
	fecha.año = 0;


		cout << "Introduzca la cantidad de existencias entrantes: ";
		cin >> existencias;
		cout << endl;

		//Incrementa las existencias y las unidades compradas
		lista.elementos[posicion].existencias += existencias;
		lista.elementos[posicion].unidadesCompradas += existencias;

		//Lee e introduce una fecha metida por el usuario
		leerFecha (fecha);
		lista.elementos[posicion].fechUltCompra.dia = fecha.dia;
		lista.elementos[posicion].fechUltCompra.mes = fecha.mes;
		lista.elementos[posicion].fechUltCompra.año = fecha.año;

		cout << "Introduzca el precio unitario de la compra: ";
		cin >> precPorUnidad;
		cout << endl;
		lista.elementos[posicion].precUltCompra = precPorUnidad;

};

void gestionarSalida ( tLista& lista, int posicion){
	int existencias;
	double precPorUnidad;
	tFecha fecha;

	fecha.dia = 0;
	fecha.mes = 0;
	fecha.año = 0;

		cout << "Introduzca la cantidad de existencias salientes: ";
		cin >> existencias;
		cout << endl;

		if ( existencias > lista.elementos[posicion].existencias)
			cout << "No hay tantas existencias de ese producto." << endl;
		else{
			//Resta las unidades vendidas a las existencias que habia 
			lista.elementos[posicion].existencias -= existencias;
			//Incrementa las unidades vendidas
			lista.elementos[posicion].unidadesVendidas += existencias;

			//Lee e introduce una fecha metida por el usuario
			leerFecha (fecha);
			lista.elementos[posicion].fechUltVenta.dia = fecha.dia;
			lista.elementos[posicion].fechUltVenta.mes = fecha.mes;
			lista.elementos[posicion].fechUltVenta.año = fecha.año;

			cout << "Introduzca el precio unitario de la compra: ";
			cin >> precPorUnidad;
			cout << endl;
			lista.elementos[posicion].precUltVenta = precPorUnidad;
		}
};

void informeEntradas ( int clave, int& cantidad){
	ifstream archivo;
	ofstream listado;
	tLista aux;
	string nombre, cadena;
	int i = 0;
	
	//Abre el archivo deonde se encuentran las compras de los productos
	archivo.open("entradas_ALM.txt");

	if ( !archivo.is_open())
		cout << "Error en la apertura del fichero entradas." << endl;
	else {
		cout << "Introduce el nombre del fichero: ";
		cin >> nombre;
		cout << endl;

		//Abre el archivo donde se van a escribir las compras de un determinado producto
		listado.open( nombre);
		if ( !listado.is_open())
			cout << "Error en la apertura del fichero seleccionado." << endl;
		else{
			cantidad = 0;
			do{
				archivo >> aux.elementos[i].clave;

				//Compara la clave del producto de la posicion i con la clave que se desea gestionar
				if ( aux.elementos[i].clave == clave){

					//Carga del archivo de compras los elementos del producto cuya clave coincida con la que se busca
					archivo >> aux.elementos[i].existencias >> aux.elementos[i].unidadesCompradas 
						>> aux.elementos[i].fechUltCompra.dia >> aux.elementos[i].fechUltCompra.mes >> aux.elementos[i].fechUltCompra.año 
						>> aux.elementos[i].precUltCompra;

					//Escribe en un archivo las distintas compras realizadas del producto
					listado << aux.elementos[i].clave << '\t' << aux.elementos[i].existencias << '\t'
						<< aux.elementos[i].unidadesCompradas << '\t'
						<< aux.elementos[i].fechUltCompra.dia << " " << aux.elementos[i].fechUltCompra.mes << " "
						<< aux.elementos[i].fechUltCompra.año << '\t' << aux.elementos[i].precUltCompra << '\n';
					
					cantidad += aux.elementos[i].unidadesCompradas;
					i++;
				}
				else {
					getline ( archivo, cadena);
				}
			} while(!archivo.eof());
		}
	}
	archivo.close();
	listado.close();

};

void informeSalidas ( int clave, int& cantidad){
	ifstream archivo;
	ofstream listado;
	tLista aux;
	string nombre, cadena;
	int i = 0;
		
	cantidad = 0;
	
	//Abre el archivo donde se encuentran las ventas de los productos
	archivo.open("salidas_ALM.txt");

	if ( !archivo.is_open())
		cout << "Error en la apertura del fichero salidas." << endl;
	else {
		cout << "Introduce el nombre del fichero: ";
		cin >> nombre;
		cout << endl;
		
		//Abre el archivo donde se va a guardar las ventas del producto
		listado.open( nombre);

		if ( !listado.is_open())
			cout << "Error en la apertura del fichero seleccionado." << endl;
		else{

			do{
				archivo >> aux.elementos[i].clave;

				//Compara la clave del producto de la posicion i con la clave que se desea gestionar
				if ( aux.elementos[i].clave == clave){

					//Carga los datos del producto de ventas que interesa
					archivo >> aux.elementos[i].existencias >> aux.elementos[i].unidadesVendidas 
						>> aux.elementos[i].fechUltVenta.dia >> aux.elementos[i].fechUltVenta.mes >> aux.elementos[i].fechUltVenta.año 
						>> aux.elementos[i].precUltVenta;

					//Escribe en otro archivo las ventas de una determinada clave
					listado << aux.elementos[i].clave << '\t' << aux.elementos[i].existencias << '\t'
						<< aux.elementos[i].unidadesCompradas << '\t'
						<< aux.elementos[i].fechUltCompra.dia << " " << aux.elementos[i].fechUltCompra.mes << " "
						<< aux.elementos[i].fechUltCompra.año << '\t' << aux.elementos[i].precUltCompra << '\n';
					
					cantidad += aux.elementos[i].unidadesVendidas;
					i++;
				}
				else {
					getline ( archivo, cadena);
				}
			} while(!archivo.eof());
		}
	}
	archivo.close();
	listado.close();
}

void generarListado ( tLista lista, string cadena){
	string nombre;
	ofstream archivo;
	tLista producto;
	int i = 0;

	cout << "Introduzca el nombre del archivo: ";
	cin >> nombre;
	cout << endl;
	archivo.open (nombre);

	if ( !archivo.is_open())
		cout << "Error en la apertura del archivo de ordenacion." << endl;
	else{
		if ( cadena == "codigo"){
			while ( i < lista.cont){
				//Escribe en el archivo los productos ordenados por codigo
				archivo	<< lista.elementos[i].clave << '\t' << lista.elementos[i].identificacion << '\t' << lista.elementos[i].existencias << '\t'
					<< lista.elementos[i].unidadesCompradas << '\t' << lista.elementos[i].fechUltCompra.dia << " " << lista.elementos[i].fechUltCompra.mes << " "
					<< lista.elementos[i].fechUltCompra.año << '\t' << lista.elementos[i].precUltCompra << '\t' << lista.elementos[i].unidadesVendidas << '\t'
					<< lista.elementos[i].fechUltVenta.dia << " " << lista.elementos[i].fechUltVenta.mes << " " << lista.elementos[i].fechUltVenta.año << '\t'
					<< lista.elementos[i].precUltVenta << endl;

				i++;
			};
		}
		else if ( cadena == "producto"){
			//Ordena una lista por identificador
			ordenarPorProductos ( lista, producto);

			while ( i < lista.cont){
				//Escribe en el archivo 
				archivo	<< producto.elementos[i].clave << '\t' << producto.elementos[i].identificacion << '\t' << producto.elementos[i].existencias << '\t'
					<< producto.elementos[i].unidadesCompradas << '\t' << producto.elementos[i].fechUltCompra.dia << " " << producto.elementos[i].fechUltCompra.mes << " "
					<< producto.elementos[i].fechUltCompra.año << '\t' << producto.elementos[i].precUltCompra << '\t' << producto.elementos[i].unidadesVendidas << '\t'
					<< producto.elementos[i].fechUltVenta.dia << " " << producto.elementos[i].fechUltVenta.mes << " " << producto.elementos[i].fechUltVenta.año << '\t'
					<< producto.elementos[i].precUltVenta << endl;

				i++;
			};
		}
	}
	archivo.close();
}

void ordenarPorProductos ( tLista lista, tLista& producto){
	string nombre;
	tProducto auxiliar;

	//Inicializa la lista vacia producto
	inicializar (producto);

	for ( int i = 0; i < lista.cont; i++){
		//Asigna los valores de lista a los de producto
		producto.elementos[i] = lista.elementos[i];
		producto.cont++;
	};

	//Ordena la nueva lista (producto) por identificacion
	for ( int i = 1; i < producto.cont; i++){
		int pos = i;
		while ((pos > 0) && (producto.elementos [pos-1].identificacion > producto.elementos[pos].identificacion)){
			auxiliar = producto.elementos[pos];
			producto.elementos[pos] = producto.elementos[pos -1];
			producto.elementos[pos -1] = auxiliar;
			pos--;
		
		}
	}

}
