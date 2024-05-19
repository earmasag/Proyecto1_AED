#ifndef donante
#define donante
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"


typedef struct donador{
	int cedula;
	char *nombre;
	char *telefono;
	char *direccion;
	struct donador *next;
}Donante;

Donante *registrarDonante();
Donante *crearNodoDonante(Donante donante);

#endif