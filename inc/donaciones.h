#ifndef donaciones
#define donaciones
#include<time.h>
#include<stdlib.h>
#include "donante.h"
#include "listaDonantes.h"


typedef struct donacion{
	int num_donacion;
	int cedula_donante;
	time_t fecha;
	unsigned short int tipo;
	unsigned short int destino;
	unsigned short int estado;
	float valor;
	char *descripcion;
	struct donacion *next;
}Donaciones;

typedef struct {
	Donaciones *ini, *fin;
}headDonacion;

extern Donante *donanteHead;


Donaciones* registrarDonacion(headDonacion *HEAD, Donante *donanteHead);
headDonacion *adminitrarDonaciones(headDonacion *HEAD);

#endif
