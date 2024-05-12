#include<string.h>
#include <stdio.h>
#include <stdlib.h>




typedef struct donante{
	char *nombre;
	int cedula;
	char *telefono;
	char *direccion;
	struct donante *next;
}Donante;



Donante* registrarDonante();
Donante* buscar_cedula(Donante *cabeza,int buscar_cedula);





