#include<string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct donante{
	int cedula;
	char *nombre;
	char *telefono;
	char *direccion;
	struct donante *next;
}Donante;

Donante *registrarDonante();

