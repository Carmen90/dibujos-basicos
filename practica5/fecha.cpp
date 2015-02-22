#include "fecha.h"
int const AMAX = 2011;


void leerFecha(tFecha& fecha){
	int dia, mes, a�o;

	cout << "Introduce la fecha deseada:" << endl;
	cout << "Dia: ";
	cin >> dia;
	cout << endl;
	cout << "Mes: ";
	cin >> mes;
	cout << endl;
	cout << "Anio: ";
	cin >> a�o;
	cout << endl;

	fecha.dia = dia;
	fecha.mes = mes;
	fecha.a�o = a�o;

	while ( fecha.dia < 00 || fecha.dia >> 31 || fecha.mes < 00 || fecha.mes > 12 || fecha.a�o > AMAX){
		cout << "Error en la fecha, escribala de nuevo." << endl;
		leerFecha (fecha);
	}

};

void escribirFecha ( tFecha fecha){

	cout << setprecision(2) << fecha.dia << " " << fecha.mes << " " << setprecision(4) << fecha.a�o << endl;

};

void comprarFechas ( tFecha fecha1, tFecha fecha2, tFecha& menor){

	if ( fecha1.a�o == fecha2.a�o){
		if ( fecha1.mes == fecha2.mes){
			if ( fecha1.dia == fecha2.dia){
				cout << "Fechas iguales" <<endl;
				menor.dia = fecha1.dia;
				menor.mes = fecha1.mes;
				menor.a�o = fecha1.a�o;
			}
			else if ( fecha1.dia < fecha2.dia){
					menor.dia = fecha1.dia;
					menor.mes = fecha1.mes;
					menor.a�o = fecha1.a�o;
				}
					else{
						menor.dia = fecha2.dia;
						menor.mes = fecha2.mes;
						menor.a�o = fecha2.a�o;
					}
		} 
		else if ( fecha1.mes < fecha2.mes ){
				menor.dia = fecha1.dia;
				menor.mes = fecha1.mes;
				menor.a�o = fecha1.a�o;
		}
		else {
			menor.dia = fecha2.dia;
			menor.mes = fecha2.mes;
			menor.a�o = fecha2.a�o;
		}
	}
	else if ( fecha1.a�o < fecha2.a�o){
		menor.dia = fecha1.dia;
		menor.mes = fecha1.mes;
		menor.a�o = fecha1.a�o;
	} 
	else {
		menor.dia = fecha2.dia;
		menor.mes = fecha2.mes;
		menor.a�o = fecha2.a�o;
	}


};