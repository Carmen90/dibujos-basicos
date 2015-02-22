/*Nombre : Carmen Acosta Morales.
DNI: 50770146-S
Laboratorio:1*/

#include <iostream> // consola de la libreria standard (STL)
#include <string> // cadenas de caracteres de la STL
#include <sstream> 
#include <fstream>
using namespace std; // prefijo de la STL
#include "ventanaGrafica.h" // ventana grafica

/*************DECLARACION DE CONSTANTES*************/
const int FC = 9;
const double ALT_CASILLA = (VGYTOP - VGYBOT- 0.5) /10;
const double ANCH_CASILLA = ( VGXRIGHT - VGXLEFT) /10;
const double DESP_Y_DIGITO = ALT_CASILLA /2.0 +1.5;
const double DESP_X_DIGITO = (ANCH_CASILLA /2.0 -1.5);

/************DECLRACION DE TIPOS*************/
typedef int tIniEnteros [FC][FC];
typedef bool tIniBool [FC][FC];
typedef int tLista [FC];

/***********DECLARACION DE ESTRUCTURAS************/

/*Estructura que se va modificando a lo largo del juego segun la opcion.
Consta de dos arrays bidimensionales y un contador.
*/
struct tJuego {
	tIniEnteros enteros; // Array de enteros modificado durante la partida
	tIniBool booleanos;	// Array de booleanos que se modifica solo al abrir el fichero inicial
	int cont;	// Contador que dice el numero de casillas ocupadas que hay
};

/*Estructura que carga un array bidimensional con la solucion del sudoku y 
un contador que asegura que la solucion conste de todos los numeros.
*/
struct tSolucion {
	tIniEnteros solucion;	//Array de enteros con la solucion
	int cont;	//Contador
};
/*Esturctura que consta de un array de una dimension y un contador
*/
struct tCandidatos {
	tLista lista;	//Array de una dimension que enumera los candidatos de una casilla
	int cont;	//Contador que indica el numero de candidatos que hay por casilla
};


/************DECLARACION DE PROTOTIPOS*********/
/*Funcion que se encarga de mostrar el menu principal por consola y recoge la opcion introducida por el usuario.
Entrada: ningun parametro.
SAlida: la opcion elegida por el usuario.
*/
int menu ();

/*Funcion que se encar
*/
void inicializacion(tJuego& juego, tSolucion& solucion);

/*Procedimiento que se encarga de cargar el tablero inicial y devuelve true/false si se ha cargado o no correctamente.
Entrada: ningun parametro.
Salida: dibuja el tablero inicial y muestra si ha habido algun error en la carga de este.
*/
bool abrirFicheroInicial ( tJuego& juego);

/*Proceidmiento que carga el tablero solucion y devuelve true/false en funcion de si se ha cargado correctamente o no.
ENtrada: ningun parametro.
Salida: muestra por pantalla grafica el tablero solucion y muestra si ha habido algun error en la carga.
*/
bool abrirFichSol (tSolucion& sol);

/*Subprograma que se encarga de dibujar el tablero.
Entrada: array de juego con los valores iniciales cargados
Salida: muestra por pantalla el tablero inicial
*/
void dibujarTablero (tJuego juego);

/*Procedimiento que calcula la posicion centrada de un numero en la ventana grafica.
Entrada: coordenadas iniciales (x0, y0), casilla en la que se situa (f,c).
Salida: coordenada de la posicion del numero (x,y).
*/
void centrarNumeros ( double x0, double y0, int c, int f, double& x, double& y);


/*Subprograma que se encarga de pedir la fila y la columna asociadas a una casilla.
Entrada: ningun parametro.
Salida: la fila y columna con previa comprovacion de rango correcto.
*/
void solicitarCasilla ( int& fila, int& columna);

/*Subprograma que se encarga de mostrar los posibles valores de una casilla
Entrada:
Salida: muestra por consola y ventana grafica si la casilla esta ocupada y sino los posibles valores de esta
*/
void posiblesValores (tJuego juego, string& mensage);

/*Funcion que devuelve un booleano en funcion de si esta o uno un numero en una determinada fila
Entrada: la esturctura tJuego, la fila que se desea comprobar y el valor.
Salida: booleano indicando si el valor se encuentra o no en en dicha fila.
*/
bool estaFila ( tJuego juego, int fila, int valor);

/*Funcion que devuelve un booleano en funcion de si esta o uno un numero en una determinada columna
Entrada: la esturctura tJuego, la columna que se desea comprobar y el valor.
Salida: booleano indicando si el valor se encuentra o no en en dicha columna.*/
bool estaColumna ( tJuego juego, int col, int valor);


/*Funcion que se encarga de comprobar si un valor esta en determinada region.
Entrada: struct juego, la fila, la columna y el valor a comprobar.
Salida: booleano indicando si esta o no ese valor en la region correspondiente.
*/
bool estaRegion ( tJuego juego, int fila, int col, int valor);

/*Procedimiento que se encarga de implementar la opcion 2 del menu, pide una fila, una columna y un valor y lo pone en la pantalla grafica
y en el array de juego, comprobando que sean validos.
Entrada: estructura del juego ( array de enteros, booleanos y contador).
Salida: la misma estructura modificada y escritura del numero por pantalla grafica en su casilla correspondiente
*/
void valorCasilla( tJuego& juego, string& mensage);

/*Funcion que pide por consola el valor que desea introducir el usuario.
Entrada: ningun parametro.
Salida: valor a introducir en pantalla grafica.
*/
int pedirValor();

/*Procedimiento que se encarga de borrar un numero anteriormente introducido por el usuario,asegurandose de que no es un valor inicial.
Entrada: structura del juego.
Salida: estructura del juego quitando del array de enteros el valor borrado y decrementando en uno el contador.
*/
void borrarCasilla (tJuego& juego, string& mensage);

/*Procedimiento que se encarga de mostrar en pantalla grafica en rojo los valores que no coincidan con los de la solucion.
Entrada: estructura del juego hasta el momento, estrutura de la solucion.
Salida: muestra por pantalla grafica los errores.
*/
void valoresIncorrectos (tJuego juego, tSolucion solucion, string& mensage);

/*Se encarga de borrar todos lo valores introducidos por el usuario, asi como de quitarlos del array de la estructura del juego
Entrada: estructura de juego ( array de enteros, booleanos y int de contador).
Salida: esturctura del juego modificada quitando todos los valores no iniciales.
*/
void reiniciarTablero ( tJuego& juego);

/*Procedimiento que recibe la estructura del juego y te lo vuelve a dibujar tal y como estaba.
Entrada: estructura de juego
Salida: vuelve a dibujar el tablero como estaba
*/
void volverAdibujar (tJuego juego);

/*Procedimiento que se encarga de pintar un numero en la ventana grafica.
Entrada: estructura del juego, fila y columna donde se situa el numero a pintar.
Salida: dibuja el numero en la ventana grafica.
*/
void dibujarNumero ( tJuego juego, int f, int c);

/*Procedimiento que se encarga de implementar el apartado 7 rellenando las casillas simples que del sudoku
Entrada: valores de la estructura del juego.
Salida: la misma estructura con los valores de las casillas simples añadidos.
*/
void casillasSimples (tJuego& juego, string& mensage);

/*Procedimiento que se encarga de preguntar si se quiere borrar la consola borrandola o no en funcion de la respuesta.
Entrada: ningun parametro.
Salida: limpia la consola.
*/
void borrarConsola();

/*Procedimientoq ue se encarga de indicar que se ha terminado un sudoku mostrando una felicitacion en el caso de que sea correcto, 
o lo errores si no lo es.
Entrada: las esturcturas del juego y del sudoku de la solucion.
Salida: mensages mostrando si se ha finalizado o no con exito
*/
void finSudoku ( tJuego juego, tSolucion solucion);

/*Proceidmiento que se encarga de borrar los mensages que se muestran por ventana grafica.
Entrada: mensage a borrar.
Salida: borrar el mensage de la ventana grafica.
*/
void borrarMensages ( string& mensage);

int main(int argc, char *argv[]) {
vgInit(false);
bool inicial, solucion;
string mensage;
tJuego juego;
tSolucion sol;
int opcion;
//
// Comienzo del código de la práctica
//
	inicializacion (juego, sol);
	inicial = abrirFicheroInicial (juego);
	solucion = abrirFichSol (sol);
	dibujarTablero (juego);

	do{
		opcion = menu();

		switch (opcion) {
			case 0:
				break;
			case 1:	posiblesValores(juego, mensage);
				break;
			case 2:	valorCasilla (juego, mensage);
				break;
			case 3:	borrarCasilla (juego, mensage);
				break;
			case 4:	 valoresIncorrectos( juego, sol, mensage);
				break;
			case 5:	reiniciarTablero (juego);
				break;
			case 6:	volverAdibujar (juego);
				break;
			case 7:	casillasSimples (juego, mensage);
				break;
			default:
				cout << "El numero introducido no es correcto." << endl;
				break;
		}   
		if ( opcion !=0){
			borrarConsola ();
		};
		
		borrarMensages ( mensage);



	}while ( opcion != 0 && juego.cont < 81);

				if ( juego.cont == 81)
		{
			finSudoku ( juego, sol);
		};
	//
	// Fin del código de la práctica
	//
	cin.sync();
	cout << "Fin pulsa una tecla" << endl;
	char c;
	cin.get(c);
	vgEnd();
	return 0;
};

int menu(){
	int opcion;
	cout << "-------------------------------------------"<< endl;
	cout << "                 MENU                     " << endl;
	cout << "-------------------------------------------"<< endl;
	cout << endl;
	cout << "0 -Salir." << endl;
	cout << "1 -Ver posibles valores de la casilla." << endl;
	cout << "2 -Colocar un valor en una casilla." << endl;
	cout << "3 -Borrar el valor de una casilla." << endl;
	cout << "4 -Mostrar valores incorrectos." << endl;
	cout << "5 -Reiniciar tablero." << endl;
	cout << "6 -Volver a dibujar." << endl;
	cout << "7 -Completar casillas simples." << endl;
	cout << endl;
	cin >> opcion;

return opcion;
};

void dibujarTablero (tJuego juego) {
	double xd, yd, x0, y0, longFila, longColumna;
	int f, c;
	string mensage;

	longFila = 9.0 * ANCH_CASILLA;	// Calcula lo que mide cada linea horizontal.
	longColumna = 9.0 * ALT_CASILLA;	//Caulcula lo que mide cada linea vertical
	//Punto inicial
	x0 = VGXLEFT + ANCH_CASILLA / 2.0;
	y0 = VGYTOP - 0.5;

		for ( f = 0; f <= FC; f++){
			if (f ==0 || f== 3 || f == 6 || f== 9 )
				vgColor (VGRojo);	// Dibuja en rojo las filas 0, 3, 6 y 9.
			else 
				vgColor (VGAzul);	// Dibuja en azul el resto de lineas

			xd = x0 + longFila;
			yd = y0;
			vgLine ( x0, y0, xd, yd);
			y0 -= ALT_CASILLA;	// Desplaza la y inicial para dibujar la siguiente fila
		}
	//Reinstaura el punto inicial para las columnas
	x0 = VGXLEFT + ANCH_CASILLA / 2.0;
	y0 = VGYTOP - 0.5;
		for ( c = 0; c <= FC; c++){
			if (c ==0 || c== 3 || c == 6 || c== 9 )
				vgColor (VGRojo);	//Dibuja en rojpo las columnas 0, 3, 6 y 9
			else 
				vgColor (VGAzul);	//Dibuja en azul el resto de columnas

			xd = x0;
			yd = y0 -longColumna;
			vgLine (x0, y0, xd, yd);
			x0 += ANCH_CASILLA;	//Desplaza la x inicial a la derecha para dibujar la siguiente columna
	
		}
		// Dibuja los numeros iniciales en sus respectivas celdas
			for ( f =0; f < FC; f++)
				for ( c= 0; c< FC; c++){
					if ( juego.enteros [f][c] != 0 && juego.booleanos [f][c]){	// dibuja en azul cuando son iniciales
						vgColor (VGAzul);
						dibujarNumero ( juego, f, c);
							}
					else if ( juego.enteros[f][c] != 0 && !juego.booleanos[f][c]){	//Dibuja en verde si son introducidos por usuario
						vgColor (VGVerde);
						dibujarNumero (juego, f, c);
					}
				}
};

void dibujarNumero ( tJuego juego, int f, int c){
	int numero, fil, col;
	string mensage;

	double x, y, x0, y0;
		//Posicion inicial	
		x0 = VGXLEFT + ANCH_CASILLA / 2.0;
		y0 =  VGYTOP - 0.5;
		
		//Conversion del numero a pintar en string adecuado para la pantalla grafica
		numero = juego.enteros [f][c];
		stringstream strMsg;
		strMsg << numero;
		mensage = strMsg.str();
		
		//Pinta el numero en ventana grafica
		col = c+1;
		fil= f+1;
		centrarNumeros ( x0, y0, col, fil, x, y);
		vgCString ( x, y, mensage.c_str());

};

void centrarNumeros ( double x0, double y0, int c, int f, double& x, double& y){
	double xc, yf;
	
	//Calcula la coordenada centrica de una casilla
	xc = x0 + (c-1) *ANCH_CASILLA;
	yf = y0 - (f-1) *ALT_CASILLA;
	y = yf - DESP_Y_DIGITO;
	x = xc + DESP_X_DIGITO;

};

void solicitarCasilla (int& fila, int& columna){

	do{	//Pide la fila y la columna
		cout << "Dame el numero de la fila" << endl;
		cin >> fila;
		cout << "Dame la columna" << endl;
		cin >> columna;

		//Comprueba que la fila y la columna estan dentro del rango permitido
	if ( fila > 9 || fila < 1)	
		cout << "Error, la fila tiene que ser un numero entre 1 y 9" << endl;
	else if ( columna > 9 || columna < 1)
		cout << "Error, la columna tiene que ser un numero entre 1 y 9" << endl;

	}while ( fila <= 0 || fila > 9 || columna <= 0 || columna > 9);


};

void inicializacion ( tJuego& juego, tSolucion& solucion) {
	juego.cont = 0;
	solucion.cont =0;
	for (int f = 0; f <= FC; f++)
	{
		for ( int c= 0; c <= FC; c++)
		{	
			juego.enteros [f][c] = 0;
			juego.booleanos [f][c] = false;
			solucion.solucion [f][c] = 0;
		};
	}

};

bool abrirFicheroInicial ( tJuego& juego){
	int f, c, numero;
	ifstream inicial;
	string usuario, msg;
	bool correcto = false;


	cout << "Nombre del sudoku inicial (Intro --> fichero por defecto 'sudoku1.txt')." << endl;
	getline(cin, usuario);

		if ( usuario == "")
			inicial.open ("sudoku1.txt");
		else
			inicial.open (usuario);	// Abre el archivo que introduzca el usuario por consola

			if (!inicial.is_open())
				cout << "Error en la apertura del fichero inicial." << endl;
			else {
				correcto = true;

				do{

					inicial >> f >> c >> numero;
					
					//Compueba que los valores del fichero sean validos
					if ( numero <=0 || numero > 9 || juego.cont > 81 || f<1 || f> 9 || c < 1 || c > 9)
					{
						cout << "Error en el fichero inicial" << endl;
					}
					else{	// Carga los valores del fichero inicial
						juego.enteros [f-1][c-1] = numero;
						juego.booleanos [f-1][c-1] = true;
						juego.cont++;
					}
				
				}while ( !inicial.eof());

			}
	inicial.close();
return correcto;
};

bool abrirFichSol (tSolucion& sol){
	bool correcto = false;
	string solucionar;
	ifstream soluc;
	int numero, f =0, c=0;

	cout << "Nombre del sudoku solucion ( Intro --> fichero por defecto 'solsdk1.txt'." << endl;
	getline ( cin, solucionar);
		
		if ( solucionar == "")	// Si pulsa enter, abre el archivo por defecto "solsdk1
			soluc.open ("solsdk1.txt");
		else
			soluc.open ( solucionar);	//Abre el fichero introducido por el usuario por consola

			if (!soluc.is_open())
				cout << "Error en la apertura del fichero solucion." << endl;
			else{
				correcto = true;	//Indica que el fichero se ha abierto correctament

			do{

				do{
					soluc >> numero;
						
					if ( numero < 1 || numero > 9 ){	//Comprueba que los valores sean validos
						cout << "Error en el archivo solucion" << endl;
					}
						else{	//Carga del fichero solucion
		
							sol.solucion [f][c] = numero;
							sol.cont++;
						}
						c++;
					}while (!soluc.eof());
				f++;
			}while ( !soluc.eof());
			
			}
			if ( sol.cont != 81) {	// Si el numero de elementos de la solucion es distinto 
									// de 81 salta un error
				cout << "Error en el numero de elementos de la solucion" << endl;
			}
	soluc.close();

return correcto;
};

void posiblesValores( tJuego juego, string& cand){
	 int fila, columna;
	 stringstream candstring;
	 tCandidatos candidato;

	 candidato.cont=0;

		solicitarCasilla (fila, columna);
			
			if ( juego.enteros [fila-1][columna-1] != 0){	//Muestra por pantalla y consola si la casilla no esta vacia
				
				cout << " CASILLA NO VACIA" << endl;
				candstring << "CASILLA NO VACIA"; 
				cand = candstring.str();
				vgColor (VGRojo);
				vgCString ( VGXLEFT, VGYBOT, cand.c_str());

			}
			else {	// Muestra por pantalla y consola los posibles candidatos
				candstring << "CANDIDATOS: ";
				cout << "CANDIDATOS: ";
				for (int valor = 1; valor <= FC; valor++){
					if ( !estaFila (juego, fila, valor) && !estaColumna (juego, columna, valor) && !estaRegion (juego, fila, columna, valor)){
						
						candidato.lista [candidato.cont] = valor;
						candidato.cont ++;
						vgColor (VGAzul);
						candstring << valor;
						cand = candstring.str();
						cout << valor << ", ";
						candstring << ", ";
						vgCString ( VGXLEFT, VGYBOT, cand.c_str());

					}
				}
			cout << endl;
		
			}		
};

bool estaFila ( tJuego juego, int fila, int valor){
	bool esta = false;
	int f, col = 0;

	f = fila -1;
	while (col < FC && !esta){	//Comprueba si un numero esta en una determinada fila
		if ( juego.enteros [f][col] == valor){
			esta = true;
		}else{
			col++;
		}
	}
return esta;
};
bool estaColumna ( tJuego juego, int col, int valor){
	bool esta = false;
	int c, fila =0;

	c = col-1;
	while ( fila < FC && !esta){	//Comprueba si un numero esta en una columna
		if ( juego.enteros [fila][c] == valor){
			esta = true;
		}else {
			fila++;
		}
	}

return esta;
};

bool estaRegion (tJuego juego, int fila, int col, int valor){
int f, c, regionf, regionc;
bool esta = false;

f = fila -1;
c = col - 1;

	regionf = (f/3) *3;
	regionc = (c/3) *3;

	//Comprueba si un numero esta en una region
	while ( !esta && regionf <= ((f/3)*3) + 2) {
		while ( !esta && regionc <= ((c/3)*3 )+2){

			if (juego.enteros [regionf][regionc] == valor){
				esta = true;
			}
			else
				regionc += 1;
				}		
		regionf += 1;
		regionc = (c/3)*3;
	}

return esta;
};

void valorCasilla( tJuego& juego, string& mensage){
	int fila,f, c, columna, valor;
	stringstream strMsg;

	solicitarCasilla ( fila, columna);
	valor = pedirValor();

	if ( juego.enteros[fila-1][columna-1] != 0) // Contempla si la casilla esta ocupada
	{
		if ( !juego.booleanos [fila -1][columna -1] ) // Muestra que no es vacia si no lo es y no es inicial
		{
			cout << "CASILLA NO VACIA" << endl;
			strMsg << "CASILLA NO VACIA";
		}
		else
		{
			cout << "NO MODIFICABLE" << endl;	//Muestra que no es modificable si no es vacia y es inicial
			strMsg << "NO MODIFICABLE";
		}
		
		vgColor ( VGRojo);
		mensage = strMsg.str();
		vgCString (VGXLEFT, VGYBOT, mensage.c_str());
	}
	else {
		if ( estaFila ( juego, fila, valor) || estaColumna ( juego, columna, valor) || estaRegion (juego, fila, columna, valor))
		{
			cout << "DIGITO NO VALIDO" <<  endl;
			strMsg << "DIGITO NO VALIDO";
			vgColor ( VGRojo);
			mensage = strMsg.str();
			vgCString (VGXLEFT, VGYBOT, mensage.c_str());
		}
		else{
			f = fila-1;
			c = columna-1;
			juego.enteros[fila-1][columna-1] = valor;
			juego.cont++;
			vgColor (VGVerde);
			dibujarNumero (juego, f, c);
		}
	}
};

int pedirValor(){
	int valor;
		cout << "Introduce el valor que desea: " << endl;
		cin >> valor;

		if (valor <=0 || valor >= 10)
			cout << "El valor debe estar entre 1 y 9." << endl;

return valor;
};

void borrarCasilla (tJuego& juego, string& mensage){
	int fila, columna, f, c;
	stringstream strMsg;

	solicitarCasilla (fila, columna);
	// Hace la fila y columna correspondiente a las posiciones del array
	f = fila -1;
	c = columna -1;

	if ( juego.booleanos [f][c] || juego.enteros [f][c] == 0){//Comprueba que no sea inicial ni vacio
		// Si es inicial
		if ( juego.booleanos [fila-1][columna-1] ){
			cout << "NO MODIFICABLE" << endl;
			strMsg << "NO MODIFICABLE";
		}
		//Si es vacia
		else if ( juego.enteros [f][c] == 0)
		{
			cout << "CASILLA VACIA" << endl;
			strMsg << "CASILLA VACIA";
		}
			vgColor ( VGRojo);
			mensage = strMsg.str();
			vgCString (VGXLEFT, VGYBOT, mensage.c_str());
		}
	else{
		//Borra el numero de la ventana grafica, pone esa posicion del array a 0 y
		//decrementa el contador de casillas completadas
		juego.cont ++;
		vgColor ( VGBlanco);
		dibujarNumero (juego, f, c);
		juego.enteros [f][c]= 0;
		juego.cont--;
	}
	
};

void valoresIncorrectos (tJuego juego, tSolucion solucion, string& mensage){
	int valor, errores =0, sol;
	stringstream strMsg;

	//Compara cada posicion del array de juego con el de solucion para ver si hay errores
	for ( int f =0; f < FC; f++){
		for ( int c=0; c< FC; c++){
			valor = juego.enteros[f][c];
			sol = solucion.solucion [f][c];

			if ( valor != 0 && valor != sol){
					vgColor ( VGRojo);
					dibujarNumero (juego, f, c);
					errores++;	// Aumenta cuando encuentra un error
			}	
		}
	}
	if (errores == 0){	// Cuando todas las posiciones del array de juego coinciden con el de solucion
		cout << "NO HAY ERRORES" << endl;
		strMsg << "NO HAY ERRORES";
		mensage = strMsg.str();
		vgColor (VGAzul);
		vgCString (VGXLEFT, VGYBOT, mensage.c_str());
	}
	else // Si no coninciden muestra donde estan los errores y el numero de errores que ha habido
	{
		cout << "NUMERO DE ERRORES: " << errores << endl;
		strMsg << "NUMERO DE ERRORES: " << errores;
		mensage = strMsg.str();
		vgColor (VGAzul);
		vgCString (VGXLEFT, VGYBOT, mensage.c_str());
	}
		
};

void reiniciarTablero ( tJuego& juego){

	for ( int f = 0; f < FC; f++)
		for ( int c =0; c < FC; c++){
			//Si encuentra in valor no inicial lo pone a 0 en el array de juego (enteros) 
			//y decrementa el contador de casillas ocupadas
			if ( !juego.booleanos[f][c] && juego.enteros[f][c] != 0){
				
				juego.enteros[f][c] =0;
				juego.cont--;
			}
		}

	vgClear();	// Limpia la ventana grafica
	dibujarTablero (juego);	// Vuelve a dibujar el tablero inicial
};

void volverAdibujar (tJuego juego){

	vgClear ();	// Limpia la ventana grafica
	dibujarTablero (juego);	// Vuelve a dibujar el tablero con los mismos numeros
							// que tenia


};

void casillasSimples (tJuego& juego, string& mensage){
	int fila, columna, valor, valorSimple =0, rellenadas = 0;
	stringstream strMsg;
	tCandidatos candidato;
	candidato.cont =0;

	for ( int f = 0; f < FC; f++){
		fila = f+ 1;
		for ( int c = 0; c < FC; c++){
			columna = c+ 1;
			//Prueba con todos los valores posibles del 1 al 9 y mira a 
			//ver si estan en fila, columna o region y si son los unicos candidatos
			for (valor = 1; valor <= FC; valor++){
				
				if ( !estaFila (juego, fila, valor) && !estaColumna (juego, columna, valor) 
					&& !estaRegion (juego, fila, columna, valor) && juego.enteros[f][c] ==0){
					
					valorSimple = valor;	// Asigna a la variable auxiliar el valor actual y 
											//si candidato.cont es 1 indica que ese unico valorSimple es el que hay que poner
					candidato.lista [candidato.cont] = valor;
					candidato.cont ++;
				}
			}
			if ( candidato.cont == 1){	// Si solo hay un candidato este se dibuja por pantalla
				juego.enteros[f][c] = valorSimple;
				vgColor (VGVerde);
				dibujarNumero (juego, f, c);
				juego.cont ++;
				rellenadas++;
				candidato.cont =0;
			    valorSimple =0;
				
			}
			//Inicializa el contador y el valor simple para la siguiente casilla a comprobar
			candidato.cont = 0;
			valorSimple =0;
		}
	}
	if ( rellenadas > 0) {
		cout << "CASILLAS SIMPLES: "<< rellenadas << endl;
		strMsg <<  "CASILLAS SIMPLES: "<< rellenadas;
		mensage = strMsg.str();
		vgColor (VGAzul);
		vgCString (VGXLEFT, VGYBOT, mensage.c_str());
	}

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

void finSudoku ( tJuego juego, tSolucion solu){
	int errores = 0, valor, sol;
	stringstream strMsg;
	string mensage;

	//Compueba si se ha finalizado correctamente
	for ( int f =0; f<FC; f++)
		for (int c =0; c < FC; c++){
				valor = juego.enteros [f][c];
				sol = solu.solucion [f][c];
		
				// Si hay errores los muestra
				if (valor != sol)
				{
					valoresIncorrectos (juego, solu, mensage);
					c = FC;
					f = FC;
					errores++;

				}
		}
	//Si no ha habido errores muestra un mensage de felicitacion
	if ( errores == 0){ 

		cout << "ENHORABUENA LO HAS COMPLETADO" << endl;
		strMsg << "ENHORABUENA LO HAS COMPLETADO";
		mensage = strMsg.str();
		vgColor ( VGAzul);
		vgCString (VGXLEFT, VGYBOT, mensage.c_str());
	}
};

void borrarMensages ( string& mensage){
	stringstream strMsg;
	
	//Muestra en blanco (borra) el mensage que recibe
	strMsg << mensage;
	mensage = strMsg.str();
	vgColor (VGBlanco);
	vgCString (VGXLEFT, VGYBOT, mensage.c_str());

};