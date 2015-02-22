#include "fecha.h"
int const AMAX = 2011;


void leerFecha(tFecha& fecha){
	int dia, mes, año;

	cout << "Introduce la fecha deseada:" << endl;
	cout << "Dia: ";
	cin >> dia;
	cout << endl;
	cout << "Mes: ";
	cin >> mes;
	cout << endl;
	cout << "Anio: ";
	cin >> año;
	cout << endl;

	fecha.dia = dia;
	fecha.mes = mes;
	fecha.año = año;

	while ( fecha.dia < 00 || fecha.dia >> 31 || fecha.mes < 00 || fecha.mes > 12 || fecha.año > AMAX){
		cout << "Error en la fecha, escribala de nuevo." << endl;
		leerFecha (fecha);
	}

};

void escribirFecha ( tFecha fecha){

	cout << setprecision(2) << fecha.dia << " " << fecha.mes << " " << setprecision(4) << fecha.año << endl;

};

void comprarFechas ( tFecha fecha1, tFecha fecha2, tFecha& menor){

	if ( fecha1.año == fecha2.año){
		if ( fecha1.mes == fecha2.mes){
			if ( fecha1.dia == fecha2.dia){
				cout << "Fechas iguales" <<endl;
				menor.dia = fecha1.dia;
				menor.mes = fecha1.mes;
				menor.año = fecha1.año;
			}
			else if ( fecha1.dia < fecha2.dia){
					menor.dia = fecha1.dia;
					menor.mes = fecha1.mes;
					menor.año = fecha1.año;
				}
					else{
						menor.dia = fecha2.dia;
						menor.mes = fecha2.mes;
						menor.año = fecha2.año;
					}
		} 
		else if ( fecha1.mes < fecha2.mes ){
				menor.dia = fecha1.dia;
				menor.mes = fecha1.mes;
				menor.año = fecha1.año;
		}
		else {
			menor.dia = fecha2.dia;
			menor.mes = fecha2.mes;
			menor.año = fecha2.año;
		}
	}
	else if ( fecha1.año < fecha2.año){
		menor.dia = fecha1.dia;
		menor.mes = fecha1.mes;
		menor.año = fecha1.año;
	} 
	else {
		menor.dia = fecha2.dia;
		menor.mes = fecha2.mes;
		menor.año = fecha2.año;
	}


};