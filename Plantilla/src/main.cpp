 // Nombre:Carmen Acosta Morales	
// DNI:50770146s
// Laboratorio:1

#include <iostream>	 // consola de la libreria standard (STL)
#include <string>	 // cadenas de caracteres de la STL
#include <cmath>    //para utilizar razones trigonometricas
using namespace std; // prefijo de la STL
#include "ventanaGrafica.h"	// ventana grafica

int main(int argc, char *argv[]) 
{
	
	// Declaracion de variables.
	int num, iteraciones, nlds, borrar;
	double xi, x2, yi, y2, x3, xd, y3, yd, ang, longitud, lado, incrLado;
	
	double radio, beta, alfa,incrAng; 

	vgInit(true);
	//
	// Comienzo del código de la práctica
	//
	
	do
	{
		//Muestra por pantalla las opciones del menu
		cout << "0- Para salir" << endl;
		cout << "1- Limpia ventana" << endl;
		cout << "2- Dibujar una linea" << endl;
		cout << "3- Dibujar cuadrado" << endl;
		cout << "4- Dibujar una poliespiral" << endl;
		cout << "5- Dibujar un poligono regular" << endl;
		cin >> num; //Lee la opcion elegida por el usuario
		
		switch (num)	// Empieza la ejecucion de las distintas opciones
		{
			case 1:		// Limpia la pantalla grafica
			 vgClear();
				break;
			
			case 2:		// Subprograma que dibuja una linea
			{
		
				//Pedir los datos para la recta
				cout << "Dame el punto inicial con dos reales desde -50.0 a 50.0:" << endl;     // Pide los datos del punto inicial.
				cin >> xi >> yi ;     // Lee las coordenadas (x,y) introducidas por el usuario
				cout << "Dame el angulo de la recta:" << endl;    // Pide el angulo
				cin >> ang;		// Lee el angulo de inclinacion de la recta
				cout << "Dame la longitud de la recta" << endl;		 // Pide distancia del punto inicial al final
				cin >> longitud;	//Lee la longitud de la recta introducida por el usuario
				
				if (longitud <=0) 
					cout << "Error, la longitud tiene que ser mayor que 0" << endl;
				
				else
				{
					//Calculo del punto de destino
					ang = ang * RPG;
					xd = xi + longitud * cos(ang);
					yd = yi + longitud * sin(ang);
	
					//Dibujar la linea 
					vgLine (xi,yi, xd, yd);
					cout << "El punto inicial es: (" << xi << "," << yi << ")"<< endl;
					cout << "El punto final es: (" << xd << "," << yd << ")" << endl;
				}	//Fin del else

			}	//Fin del case 2
				break;
			
			case 3:		// Subprograma que dibuja un cuadrado
			{
			
				//Pedir datos para el cuadrado
				cout << "Dame las coordenadas del vertice inferior izquierdo (de -50, 50)" << endl;
				cin >> xi >> yi;
				cout << "Dame la inclinacion del cuadrado:" << endl;
				cin >> ang;
				cout << "Dame la longitud de sus lados:" << endl;
				cin >> lado;
			
				if (lado <=0)	//Se asegura de que el usuario mete un valor positivo para el lado
					cout << "Error, el lado tiene que ser mayor que 0" << endl;
				else
				{
					ang= ang * RPG;// convierte los grados en radianes
			
					//Calcular los vertices

					// Calcula vertice 2
					x2 = xi + lado * cos (ang); 
					y2 = yi + lado * sin (ang);
					//Calcula vertice 3
					x3 = x2 + lado * cos ((PI/2) + ang);
					y3 = y2 + lado * sin ((PI/2) + ang);
					//Calcula vertice 4
					xd = x3 + lado * cos (PI + ang); 
					yd = y3 + lado * sin (PI + ang);
					//Fin de calculo de vertices
		
					//Dibujar los lados
					vgLine (xi, yi, x2, y2); //Dibuja lado 1
					vgLine (x2, y2, x3, y3); //Dibuja lado 2
					vgLine (x3, y3, xd, yd); //Dibuja lado 3
					vgLine (xd, yd, xi, yi); //Dibuja lado 4
					//Fin de dibujado de lados
				
				}	//Fin del else
			
			}	//Fin del case 3

				break;
			case 4:		//Subprograma que dibuja una poliespiral
			{	//Inicio de poliespiral

				//Pide los datos de la poliespiral
				cout << "Dame la longitud inicial del lado" << endl;
				cin >> lado;
				cout << "Dame el incremento del angulo" << endl;
				cin >> incrAng;
				cout << "Dame el incremento del lado" << endl;
				cin >> incrLado;
				cout << "Numero de iteraciones" << endl;
				cin >> iteraciones;

				//Comprobacion de que los datos metidos por el usuario son positivos
				if (lado < 0)
					cout << "Valor erroneo, introduzca un numero positivo" << endl;
				else if (incrAng < 0)
					cout << "El incremento del angulo tiene que ser positivo" << endl;
					else if (incrLado < 0)
						cout << "El incremento del lado tiene que ser positivo" << endl;
						else if ( iteraciones < 0)
							cout << "El numero de iteraciones tiene que ser positivo" << endl;
						else
						{
							//Inicializacion de variables
							xi= 0;
							yi= 0;
							ang = 0;

							for ( int i= 1; i<= iteraciones; i++)
						{

								xd = xi + (lado * cos (ang * RPG));
								yd = yi + (lado * sin (ang * RPG));
								vgLine (xi, yi, xd, yd);
								ang = ang + incrAng;
								lado= lado + incrLado;
								xi= xd;
								yi= yd;
						}	//Fin del for

						}	//Fin del else
				break;
				//Fin poliespiral
			}	//Fin del case4
			
			case 5:
			{
				//Pide los datos para el poligono
				cout << "Dame la longitud del lado" << endl;
				cin >> lado;
				cout << "Dame el numero de lados" << endl;
				cin >> nlds;
				 
				// Comprobar que lado es mayor que 0 y nlds mayor que 2
				if (lado <=0)
					cout << "El lado tiene que ser positivo" << endl;
					else if ( nlds <= 2)
						cout << "El numero de lados tiene que ser mayor que dos" << endl;
						else
						{
							radio = 0;
							beta = 0;
							alfa = 0;
							xi = 0;
							yi = 0;
							incrAng = 0;

							alfa = ((double)360 / (double)nlds)* RPG;
							beta = (double)270 * RPG  - alfa/2 ;
							radio = lado / (2 * cos (PI /2 - alfa/2));
							xi = radio * cos (beta);
							yi = radio * sin (beta);
				
							xd = xi + lado * cos (0 * RPG);
							yd = yi + lado * sin (0 * RPG);

							vgLine (xi, yi, xd,yd);

							for (int i= 1; i < nlds; i++)
							{
								xi = xd;
								yi = yd;
								incrAng = incrAng + alfa;
								xd = xi + lado * cos (incrAng);
								yd = yi + lado * sin (incrAng);
								vgLine (xi, yi, xd, yd);
					
							}	//Fin del for
				
						}	//Fin del else
				system ("cls");	// Limpia la pantalla de texto

				}	//Fin del case 5

			case 0: // Va al final del main() y sale
				break;

			default: cout << "Numero incorrecto, pon un numero del 0 al 5" << endl;
				break;
		}	// Fin del switch

		cout << "¿Quieres borrar la pantalla? 1 si/ 0 no" << endl;
		cin >> borrar;
		if ( borrar ==1 ) 
			{
				system ("cls");
			}
		else if ( borrar != 0)
			cout << "Opcion no valida" << endl;
		
	}
	while (num != 0);
	
			
	//
	// Fin del código de la práctica
	//
	cin.sync();
	cout << "Fin pulsa una tecla" << endl;
	char c;
	cin.get(c);

	vgEnd();
	return 0;
}