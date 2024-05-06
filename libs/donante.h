#include<string.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct donaciones{
	char *fecha;
	char *tipo;
	char *descripcion;
	char *valor;
	struct donaciones *next;
}Donaciones;

typedef struct donante{
	char *nombre;
	int cedula;
	char *telefono;
	char *direccion;
	struct donante *next;
}Donante;



Donante* registrarDonante();
void registrarDonacion();
Donante* buscar_cedula(Donante *cabeza,int buscar_cedula);
Donante* agregarDonante(Donante *cabeza,Donante *nuevo_donante);




